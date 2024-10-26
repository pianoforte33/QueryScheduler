#ifndef QUERYSCHEDULER_H
#define QUERYSCHEDULER_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDateTime>
#include <algorithm>
#include <random>

QT_BEGIN_NAMESPACE
namespace Ui {
class QueryScheduler;
}
QT_END_NAMESPACE

class QueryScheduler : public QMainWindow
{
    Q_OBJECT

public:
    QueryScheduler(QWidget *parent = nullptr);
    ~QueryScheduler();

private slots:
    void pushButtonGenerate_clicked();
    void on_actionExport_as_CSV_triggered();

private:
    Ui::QueryScheduler *ui;

    int counterSameName = 0; // the variable is used to count how many time we find the same file
    int nameNumber; // the variable is used generate the exact naumber of cell in the table
    QList<QString> nameList; // the vector store all the name of people in the file
};
#endif // QUERYSCHEDULER_H
