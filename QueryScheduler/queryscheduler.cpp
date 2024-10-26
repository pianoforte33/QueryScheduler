#include "queryscheduler.h"
#include "./ui_queryscheduler.h"

QueryScheduler::QueryScheduler(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QueryScheduler)
{
    ui->setupUi(this);

    QFile name(":/name.txt");

    // file exeption handling
    if (!name.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + name.errorString());
        return;
    }

    // file "name" is read line by line
    while (!name.atEnd()){
        nameList.append(name.readLine().trimmed());
    }
    nameNumber = nameList.size();

    ui->spinBoxColumn->setMinimum(1);
    ui->spinBoxColumn->setMaximum(nameNumber);

    name.close();

    QObject::connect(ui->pushButtonGenerate, SIGNAL(clicked()),
                     this, SLOT(pushButtonGenerate_clicked()));
}

void QueryScheduler::pushButtonGenerate_clicked()
{
    shuffle(nameList.begin(), nameList.end(), std::default_random_engine(time(NULL)));

    if (nameNumber % ui->spinBoxColumn->value() == 0) {
        ui->tableWidget->setColumnCount(nameNumber / ui->spinBoxColumn->value());
    } else {
        ui->tableWidget->setColumnCount(nameNumber / ui->spinBoxColumn->value() + 1);
    }
    ui->tableWidget->setRowCount(ui->spinBoxColumn->value());

    int cnt = 0;

    for (int i = 0; i < ui->tableWidget->columnCount(); i++) {
        for (int j = 0; j < ui->tableWidget->rowCount(); j++) {
            if (cnt < nameNumber) {
                ui->tableWidget->setItem(j, i, new QTableWidgetItem(nameList.at(cnt)));
                cnt++;
            }
        }
    }
}


void QueryScheduler::on_actionExport_as_CSV_triggered()
{
    QString date = QDateTime::currentDateTime().toString("dd.mm.yyyy") + "-" + QDateTime::currentDateTime().toString("h.m.s");
    QString fileName = "queried-" + date + ".csv";

    QFile file(fileName);

    // if it find a file whit the name whe rename the file
    while (file.exists()) {
        counterSameName++;
        fileName.chop(4);
        fileName = fileName + "(new" + QString::number(counterSameName) + ").csv";
        file.setFileName(fileName);
    }

    // making sure that file was opened correctly
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    // writing on the file using the .csv file format
    QTextStream cell(&file);
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->colorCount(); j++) {
            if (ui->tableWidget->item(i, j) != nullptr) {
                cell << ui->tableWidget->item(i, j)->text() << ';';
            }
        }
        cell << "\n";
    }

    file.close();
}

QueryScheduler::~QueryScheduler()
{
    delete ui;
}
