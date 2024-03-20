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
        nameList.append(name.readLine());
        nameNumber++;
    }
    nameNumber--;

    ui->spinBoxColumn->setMinimum(1);
    ui->spinBoxColumn->setMaximum(nameNumber);

    name.close();

    QObject::connect(ui->pushButtonGenerate, SIGNAL(clicked()),
                     this, SLOT(pushButtonGenerate_clicked()));
}

void QueryScheduler::pushButtonGenerate_clicked()
{
    //qInfo() << "Generate button pressed";

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

QueryScheduler::~QueryScheduler()
{
    delete ui;
}

