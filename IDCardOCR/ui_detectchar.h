/********************************************************************************
** Form generated from reading UI file 'detectchar.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTCHAR_H
#define UI_DETECTCHAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectCharClass
{
public:
    QWidget *centralWidget;
    QLabel *ShowImg;
    QPushButton *OpenImg;
    QPushButton *Process;
    QTextEdit *textEdit_IDCard;
    QPushButton *pushButton_clear1;
    QGroupBox *groupBox;
    QGroupBox *groupBox_4;
    QPushButton *testPushButton;
    QLabel *label_6;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_3;
    QLabel *label_2;
    QGroupBox *groupBox_5;
    QProgressBar *ocrProgressBar;
    QLabel *label;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DetectCharClass)
    {
        if (DetectCharClass->objectName().isEmpty())
            DetectCharClass->setObjectName(QStringLiteral("DetectCharClass"));
        DetectCharClass->resize(1214, 632);
        DetectCharClass->setStyleSheet(QLatin1String("\n"
"background-image: url(:/img/img/back10.jpg);\n"
"\n"
"color: rgb(255, 255, 255);\n"
""));
        centralWidget = new QWidget(DetectCharClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ShowImg = new QLabel(centralWidget);
        ShowImg->setObjectName(QStringLiteral("ShowImg"));
        ShowImg->setGeometry(QRect(20, 20, 681, 391));
        QFont font;
        font.setPointSize(21);
        ShowImg->setFont(font);
        ShowImg->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        ShowImg->setFrameShape(QFrame::Panel);
        ShowImg->setLineWidth(0);
        ShowImg->setAlignment(Qt::AlignCenter);
        OpenImg = new QPushButton(centralWidget);
        OpenImg->setObjectName(QStringLiteral("OpenImg"));
        OpenImg->setGeometry(QRect(970, 20, 70, 30));
        OpenImg->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        Process = new QPushButton(centralWidget);
        Process->setObjectName(QStringLiteral("Process"));
        Process->setGeometry(QRect(1050, 20, 70, 30));
        Process->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        textEdit_IDCard = new QTextEdit(centralWidget);
        textEdit_IDCard->setObjectName(QStringLiteral("textEdit_IDCard"));
        textEdit_IDCard->setGeometry(QRect(720, 60, 481, 481));
        textEdit_IDCard->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_clear1 = new QPushButton(centralWidget);
        pushButton_clear1->setObjectName(QStringLiteral("pushButton_clear1"));
        pushButton_clear1->setGeometry(QRect(1130, 20, 70, 30));
        pushButton_clear1->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 701, 411));
        groupBox->setFlat(false);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(720, 560, 481, 51));
        testPushButton = new QPushButton(groupBox_4);
        testPushButton->setObjectName(QStringLiteral("testPushButton"));
        testPushButton->setGeometry(QRect(390, 10, 70, 30));
        testPushButton->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 10, 141, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 470, 701, 141));
        tableWidget->setStyleSheet(QLatin1String("QScrollBar{\n"
"background:black; \n"
" height:10px;\n"
"}"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setTextElideMode(Qt::ElideRight);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(20);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 430, 701, 181));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 121, 31));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(720, 10, 481, 411));
        ocrProgressBar = new QProgressBar(groupBox_5);
        ocrProgressBar->setObjectName(QStringLiteral("ocrProgressBar"));
        ocrProgressBar->setGeometry(QRect(130, 20, 121, 20));
        ocrProgressBar->setStyleSheet(QStringLiteral(""));
        ocrProgressBar->setMaximum(100);
        ocrProgressBar->setValue(0);
        label = new QLabel(groupBox_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 121, 31));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        DetectCharClass->setCentralWidget(centralWidget);
        groupBox_5->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        groupBox->raise();
        ShowImg->raise();
        OpenImg->raise();
        Process->raise();
        textEdit_IDCard->raise();
        pushButton_clear1->raise();
        tableWidget->raise();
        statusBar = new QStatusBar(DetectCharClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DetectCharClass->setStatusBar(statusBar);

        retranslateUi(DetectCharClass);
        QObject::connect(OpenImg, SIGNAL(clicked()), DetectCharClass, SLOT(ShowImg()));
        QObject::connect(Process, SIGNAL(clicked()), DetectCharClass, SLOT(ProcessClicked()));

        QMetaObject::connectSlotsByName(DetectCharClass);
    } // setupUi

    void retranslateUi(QMainWindow *DetectCharClass)
    {
        DetectCharClass->setWindowTitle(QApplication::translate("DetectCharClass", "IDCard OCR", Q_NULLPTR));
        ShowImg->setText(QApplication::translate("DetectCharClass", "ShowImage", Q_NULLPTR));
        OpenImg->setText(QApplication::translate("DetectCharClass", "Open", Q_NULLPTR));
        Process->setText(QApplication::translate("DetectCharClass", "OCR", Q_NULLPTR));
        pushButton_clear1->setText(QApplication::translate("DetectCharClass", "Clear", Q_NULLPTR));
        groupBox->setTitle(QString());
        groupBox_4->setTitle(QString());
        testPushButton->setText(QApplication::translate("DetectCharClass", "test", Q_NULLPTR));
        label_6->setText(QApplication::translate("DetectCharClass", "Tesseract Test", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DetectCharClass", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DetectCharClass", "\346\200\247\345\210\253", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DetectCharClass", "\346\260\221\346\227\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DetectCharClass", "\345\207\272\347\224\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DetectCharClass", "\344\275\217\345\235\200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DetectCharClass", "\345\205\254\346\260\221\350\272\253\344\273\275\345\217\267\347\240\201", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        label_2->setText(QApplication::translate("DetectCharClass", " Result Table", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        label->setText(QApplication::translate("DetectCharClass", " IDCard OCR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DetectCharClass: public Ui_DetectCharClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTCHAR_H
