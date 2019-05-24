#include "filelist.h"
#include "ui_filelist.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

FileList::FileList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileList)
{
    ui->setupUi(this);
}

FileList::FileList(QString barSite, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileList)
{
    ui->setupUi(this);

    this->setMinimumHeight(70);

    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();
    QGridLayout *grid = new QGridLayout(this);

    progressBar = new QProgressBar(this);
    progressBar->setMaximumWidth(220);
    if(barSite == "left")
    {
        progressBar->setGeometry(20,40,220,23);
        hbox->addWidget(progressBar);
        hbox->addStretch();
    }
    else if(barSite == "right")
    {
        progressBar->setGeometry(400,40,220,23);
        hbox->addStretch();
        hbox->addWidget(progressBar);
    }

    vbox->addStretch();
    vbox->addLayout(hbox);

    grid->addLayout(vbox,1,1,Qt::AlignCenter);

    fileSize = 0;
    sendSize = 0;
    recvSize = 0;
    recv_over = false;
    progressBar->setValue(0);
}

void FileList::setpeerAddr(QString peerAddr)
{
    this->peerAddr = peerAddr;
}

void FileList::openFile(QString filePath)
{
    file.setFileName(filePath);
    file.open(QIODevice::ReadOnly);
}

void FileList::setFilePath(QString filePath)
{
    this->filePath = filePath;
}

void FileList::setSavePath(QString savePath)
{
    this->savePath = savePath;
}

void FileList::setFileSize(quint64 fileSize)
{
    this->fileSize = fileSize;
}

//准备发送文件
void FileList::sendFile()
{
    openFile(filePath);
    //当数据发送出会发送bytesWritten，触发sendFile()持续发送文件数据
    connect(fileSock,SIGNAL(bytesWritten(qint64)),this, SLOT(send_data()));
    progressBar->setMaximum(fileSize);
    send_data();
}

//准备接收文件
void FileList::recvFile()
{
    recv_over = false;
    qDebug()<< "savePath:"<<savePath;
    file.setFileName(savePath);
    file.open(QIODevice::WriteOnly);

    progressBar->setMaximum(fileSize);
}

void FileList::setFileSock(QTcpSocket *fileSocket)
{
    this->fileSock  = fileSocket;
}

FileList::~FileList()
{
    delete ui;
    delete progressBar;
    delete fileSock;
}

void FileList::send_data()
{
    qDebug()<<"sendFile";
    qDebug()<<"sendSize:"<<sendSize<<"fileSize:"<<fileSize;
    if(sendSize < fileSize)
    {
        QByteArray array = file.read(1024*10);
        QString str = array;
       // qDebug()<<str;
        fileSock->write(array);
        qDebug()<<"arraySize:"<<array.size();
        sendSize += array.size();

        qDebug()<<"sendSize"<<sendSize;
        progressBar->setValue(sendSize);
    }
    if(sendSize == fileSize)
    {
        qDebug()<<"Transmit completed!";
        file.close();
        disconnect(fileSock,SIGNAL(bytesWritten(qint64)),this, SLOT(send_data()));
        fileSize = 0;
        sendSize = 0;
    }
}

void FileList::recv_data()
{
    qDebug()<<"recvSize:"<<recvSize<<"fileSize:"<<fileSize;
    if(recvSize < fileSize)
    {
        QByteArray array = fileSock->readAll();
      //  QString str = array;
      //  qDebug()<<str;
        file.write(array);
        recvSize += array.size();
        progressBar->setValue(recvSize);
    }
    if(recvSize == fileSize)
    {
        recv_over = true;
        file.close();
        fileSize = 0;
        recvSize = 0;
    }
}
