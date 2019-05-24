/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget_rcvmsg;
    QPushButton *pushButton_snd;
    QGroupBox *groupBox_mode;
    QRadioButton *radioButton_TcpSvr;
    QRadioButton *radioButton_TcpClt;
    QRadioButton *radioButton_Udp;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_clear;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_localport;
    QPushButton *pushButton_connect;
    QLabel *label;
    QLabel *label_connect;
    QLineEdit *lineEdit_IP;
    QLineEdit *lineEdit_hostport;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit_sndmsg;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_time;
    QCheckBox *checkBox_autoSnd;
    QLabel *label_4;
    QPushButton *pushButton_file;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QStringLiteral("MainWin"));
        MainWin->resize(946, 580);
        MainWin->setMinimumSize(QSize(946, 580));
        MainWin->setMaximumSize(QSize(946, 580));
        MainWin->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral("border-image: url(:/f.png);"));
        listWidget_rcvmsg = new QListWidget(centralwidget);
        listWidget_rcvmsg->setObjectName(QStringLiteral("listWidget_rcvmsg"));
        listWidget_rcvmsg->setGeometry(QRect(230, 40, 691, 291));
        pushButton_snd = new QPushButton(centralwidget);
        pushButton_snd->setObjectName(QStringLiteral("pushButton_snd"));
        pushButton_snd->setGeometry(QRect(840, 510, 71, 28));
        groupBox_mode = new QGroupBox(centralwidget);
        groupBox_mode->setObjectName(QStringLiteral("groupBox_mode"));
        groupBox_mode->setEnabled(true);
        groupBox_mode->setGeometry(QRect(10, 20, 191, 121));
        radioButton_TcpSvr = new QRadioButton(groupBox_mode);
        radioButton_TcpSvr->setObjectName(QStringLiteral("radioButton_TcpSvr"));
        radioButton_TcpSvr->setGeometry(QRect(20, 30, 115, 19));
        radioButton_TcpClt = new QRadioButton(groupBox_mode);
        radioButton_TcpClt->setObjectName(QStringLiteral("radioButton_TcpClt"));
        radioButton_TcpClt->setGeometry(QRect(20, 60, 115, 19));
        radioButton_Udp = new QRadioButton(groupBox_mode);
        radioButton_Udp->setObjectName(QStringLiteral("radioButton_Udp"));
        radioButton_Udp->setGeometry(QRect(20, 90, 131, 19));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 20, 72, 15));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 350, 72, 15));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(840, 290, 71, 28));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 160, 191, 201));
        lineEdit_localport = new QLineEdit(groupBox_2);
        lineEdit_localport->setObjectName(QStringLiteral("lineEdit_localport"));
        lineEdit_localport->setGeometry(QRect(100, 80, 71, 31));
        pushButton_connect = new QPushButton(groupBox_2);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(90, 160, 81, 31));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 71, 31));
        label_connect = new QLabel(groupBox_2);
        label_connect->setObjectName(QStringLiteral("label_connect"));
        label_connect->setGeometry(QRect(40, 165, 21, 20));
        label_connect->setStyleSheet(QLatin1String("background-color: rgb(206, 206, 206);\n"
"border:1px solid#000000;\n"
"border-radius:10px;"));
        lineEdit_IP = new QLineEdit(groupBox_2);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));
        lineEdit_IP->setGeometry(QRect(10, 40, 161, 31));
        lineEdit_hostport = new QLineEdit(groupBox_2);
        lineEdit_hostport->setObjectName(QStringLiteral("lineEdit_hostport"));
        lineEdit_hostport->setGeometry(QRect(100, 120, 71, 31));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 120, 61, 31));
        plainTextEdit_sndmsg = new QPlainTextEdit(centralwidget);
        plainTextEdit_sndmsg->setObjectName(QStringLiteral("plainTextEdit_sndmsg"));
        plainTextEdit_sndmsg->setGeometry(QRect(230, 380, 691, 171));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 380, 191, 171));
        lineEdit_time = new QLineEdit(groupBox_3);
        lineEdit_time->setObjectName(QStringLiteral("lineEdit_time"));
        lineEdit_time->setGeometry(QRect(110, 80, 61, 31));
        checkBox_autoSnd = new QCheckBox(groupBox_3);
        checkBox_autoSnd->setObjectName(QStringLiteral("checkBox_autoSnd"));
        checkBox_autoSnd->setGeometry(QRect(20, 80, 101, 31));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 80, 31, 31));
        pushButton_file = new QPushButton(groupBox_3);
        pushButton_file->setObjectName(QStringLiteral("pushButton_file"));
        pushButton_file->setGeometry(QRect(100, 130, 71, 28));
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 30, 161, 31));
        MainWin->setCentralWidget(centralwidget);
        plainTextEdit_sndmsg->raise();
        listWidget_rcvmsg->raise();
        groupBox_mode->raise();
        label_2->raise();
        label_3->raise();
        pushButton_clear->raise();
        groupBox_2->raise();
        pushButton_snd->raise();
        groupBox_3->raise();
        menubar = new QMenuBar(MainWin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 946, 26));
        MainWin->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QFont font;
        font.setFamily(QStringLiteral("SimSun-ExtB"));
        font.setPointSize(11);
        statusbar->setFont(font);
        MainWin->setStatusBar(statusbar);

        retranslateUi(MainWin);

        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWin)
    {
        MainWin->setWindowTitle(QApplication::translate("MainWin", "\347\275\221\347\273\234\350\260\203\350\257\225\344\270\216\346\226\207\344\273\266\344\274\240\350\276\223", 0));
        pushButton_snd->setText(QApplication::translate("MainWin", "\345\217\221\351\200\201", 0));
        groupBox_mode->setTitle(QApplication::translate("MainWin", "\351\200\232\350\256\257\346\250\241\345\274\217", 0));
        radioButton_TcpSvr->setText(QApplication::translate("MainWin", "TCP Server", 0));
        radioButton_TcpClt->setText(QApplication::translate("MainWin", "TCP Client", 0));
        radioButton_Udp->setText(QApplication::translate("MainWin", "UDP", 0));
        label_2->setText(QApplication::translate("MainWin", "\346\216\245\346\224\266\345\214\272", 0));
        label_3->setText(QApplication::translate("MainWin", "\345\217\221\351\200\201\345\214\272", 0));
        pushButton_clear->setText(QApplication::translate("MainWin", "\346\270\205\347\251\272", 0));
        groupBox_2->setTitle(QApplication::translate("MainWin", "\347\275\221\347\273\234\350\256\276\347\275\256", 0));
        lineEdit_localport->setText(QApplication::translate("MainWin", "1210", 0));
        lineEdit_localport->setPlaceholderText(QApplication::translate("MainWin", "port", 0));
        pushButton_connect->setText(QApplication::translate("MainWin", "\345\274\200\345\247\213\347\233\221\345\220\254", 0));
        label->setText(QApplication::translate("MainWin", "\346\234\254\345\234\260\347\253\257\345\217\243", 0));
        label_connect->setText(QString());
        lineEdit_IP->setPlaceholderText(QApplication::translate("MainWin", "Host IP", 0));
        lineEdit_hostport->setText(QApplication::translate("MainWin", "1410", 0));
        lineEdit_hostport->setPlaceholderText(QApplication::translate("MainWin", "port", 0));
        label_5->setText(QApplication::translate("MainWin", "\350\277\234\347\250\213\347\253\257\345\217\243", 0));
        groupBox_3->setTitle(QApplication::translate("MainWin", "\345\217\221\351\200\201\351\200\211\351\241\271", 0));
        lineEdit_time->setText(QApplication::translate("MainWin", "1000", 0));
        checkBox_autoSnd->setText(QApplication::translate("MainWin", "\350\207\252\345\212\250\345\217\221\351\200\201", 0));
        label_4->setText(QApplication::translate("MainWin", "ms", 0));
        pushButton_file->setText(QApplication::translate("MainWin", "\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
