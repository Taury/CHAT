#ifndef FILELIST_H
#define FILELIST_H

#include <QWidget>
#include <QProgressBar>
#include <QString>
#include <QTcpSocket>
#include <QFile>
#include <QFileInfo>

namespace Ui {
class FileList;
}

class FileList : public QWidget
{
    Q_OBJECT

public:
    explicit FileList(QWidget *parent = 0);

    FileList(QString barSite, QWidget *parent = 0);

    void setpeerAddr(QString peerAddr);
    QString getpeerAddr(){return peerAddr;}

    void openFile(QString filePath);

    //设置与获取将要发送或者需要接收的文件路径
    void setFilePath(QString filePath);
    QString getFilePath(){return filePath;}

    //设置与获取保存路径
    void setSavePath(QString savePath);
    QString getSavePath(){return savePath;}

    void setFileSize(quint64 fileSize);
    quint64 getFileSize(){return fileSize;}

    void setProgressBarVal(qint8 val);

    void sendFile();

    quint64 getSendSize(){return sendSize;}
    quint64 getRecvSize(){return recvSize;}

    void recvFile();

    void recv_data();

    void setFileSock(QTcpSocket *fileSock);

    bool recv_over;

    ~FileList();

private slots:

    void send_data();

private:
    Ui::FileList *ui;

    QProgressBar *progressBar;

    QFile file;

    QString peerAddr;

    QString filePath;

    QString savePath;

    quint64 fileSize;

    quint64 sendSize;

    quint64 recvSize;

    QTcpSocket *fileSock;
};

#endif // FILELIST_H
