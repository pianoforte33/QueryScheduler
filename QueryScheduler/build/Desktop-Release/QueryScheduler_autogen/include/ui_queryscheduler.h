/********************************************************************************
** Form generated from reading UI file 'queryscheduler.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYSCHEDULER_H
#define UI_QUERYSCHEDULER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryScheduler
{
public:
    QAction *actionExport_as_CSV;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxColumn;
    QPushButton *pushButtonGenerate;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menufile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QueryScheduler)
    {
        if (QueryScheduler->objectName().isEmpty())
            QueryScheduler->setObjectName(QString::fromUtf8("QueryScheduler"));
        QueryScheduler->resize(905, 600);
        actionExport_as_CSV = new QAction(QueryScheduler);
        actionExport_as_CSV->setObjectName(QString::fromUtf8("actionExport_as_CSV"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentSave")));
        actionExport_as_CSV->setIcon(icon);
        centralwidget = new QWidget(QueryScheduler);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spinBoxColumn = new QSpinBox(centralwidget);
        spinBoxColumn->setObjectName(QString::fromUtf8("spinBoxColumn"));
        sizePolicy.setHeightForWidth(spinBoxColumn->sizePolicy().hasHeightForWidth());
        spinBoxColumn->setSizePolicy(sizePolicy);
        spinBoxColumn->setMinimum(0);

        horizontalLayout->addWidget(spinBoxColumn);

        pushButtonGenerate = new QPushButton(centralwidget);
        pushButtonGenerate->setObjectName(QString::fromUtf8("pushButtonGenerate"));
        sizePolicy.setHeightForWidth(pushButtonGenerate->sizePolicy().hasHeightForWidth());
        pushButtonGenerate->setSizePolicy(sizePolicy);
        pushButtonGenerate->setAutoDefault(false);
        pushButtonGenerate->setFlat(false);

        horizontalLayout->addWidget(pushButtonGenerate);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setMouseTracking(false);
        tableWidget->setSortingEnabled(true);
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(1);

        verticalLayout->addWidget(tableWidget);

        QueryScheduler->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QueryScheduler);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 905, 23));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        QueryScheduler->setMenuBar(menubar);
        statusbar = new QStatusBar(QueryScheduler);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QueryScheduler->setStatusBar(statusbar);

        menubar->addAction(menufile->menuAction());
        menufile->addAction(actionExport_as_CSV);

        retranslateUi(QueryScheduler);

        pushButtonGenerate->setDefault(false);


        QMetaObject::connectSlotsByName(QueryScheduler);
    } // setupUi

    void retranslateUi(QMainWindow *QueryScheduler)
    {
        QueryScheduler->setWindowTitle(QCoreApplication::translate("QueryScheduler", "QueryScheduler", nullptr));
        actionExport_as_CSV->setText(QCoreApplication::translate("QueryScheduler", "&save", nullptr));
#if QT_CONFIG(shortcut)
        actionExport_as_CSV->setShortcut(QCoreApplication::translate("QueryScheduler", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("QueryScheduler", "How many people need to be queried per day?", nullptr));
        pushButtonGenerate->setText(QCoreApplication::translate("QueryScheduler", "generate table", nullptr));
        menufile->setTitle(QCoreApplication::translate("QueryScheduler", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueryScheduler: public Ui_QueryScheduler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYSCHEDULER_H
