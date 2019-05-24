#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QTimer>
#include <QLabel>
#include <QFile>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QProcess>

#include "udpchat.h"
#include "filelist.h"

namespace Ui {
class MainWin;
}

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);

    enum NetworkMode {
        TcpServerMode,
        TcpClientMode,
        UdpMode,
        OtherMode = -1
    };
    enum DataType {
        msgData,
        fileData,
        OtherType = -1
    };

    QString sizeConvert(quint64 value);

    ~MainWin();

private slots:

    void on_pushButton_connect_clicked();

    void on_radioButton_TcpSvr_clicked();

    void newConnect();

    void read_data();

    void disConnect();

    void on_pushButton_snd_clicked();

    void on_pushButton_clear_clicked();

    void on_radioButton_TcpClt_clicked();

    void on_checkBox_autoSnd_clicked(bool checked);

    void on_pushButton_file_clicked();

    void on_listWidget_rcvmsg_doubleClicked(const QModelIndex &index);

    void recvFile();

    void on_radioButton_Udp_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWin *ui;

    QSqlDatabase db;

    bool isConneted;

    QTcpSocket *Tsocket;
    QTcpServer *Tserver;
    QList<QTcpSocket*> clientSock;

    UdpChat *Uchat;

    NetworkMode mode;

    QTimer    timer;

    QList<FileList *> fileList;
    quint8 fileIndex;

    QLabel *infoLabel;

    QLabel *pageLabel;

};

#endif // MAINWIN_H
