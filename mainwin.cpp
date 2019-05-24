#include "mainwin.h"
#include "ui_mainwin.h"
#include <QHostAddress>
#include <QHostInfo>
#include <QMessageBox>
#include <QFileDialog>

MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatebase.db");
    if(!db.open())
    {
        qDebug()<<"Open database failed!";
    }
    QSqlQuery query;
    query.exec("select count(*) from sqlite_master where type='table' and name='record';");
    if(query.next())
    {
        if(query.value(0).toInt() == 0)
            query.exec("create table record(ipAddr text,message text,filePath text,savePath text,fileSize int);");
        else
            query.exec("delete from record;");
    }

    pageLabel = new QLabel(this);
    pageLabel->setText("<a href=\"http:github.com/Taury\">D•Kingson Mo</a>");
    pageLabel->setOpenExternalLinks(true);
    ui->statusbar->addPermanentWidget(pageLabel);
    infoLabel = new QLabel(this);

    isConneted = false;
    Tserver = new QTcpServer();
    Tsocket = new QTcpSocket();
    clientSock.clear();

    Uchat = new UdpChat();

    ui->pushButton_file->setEnabled(false);
    ui->pushButton_connect->setEnabled(false);
}

MainWin::~MainWin()
{
    delete ui;
    delete Tsocket;
    delete Tserver;
}

//新建连接
void MainWin::newConnect()
{
    isConneted = true;
    ui->pushButton_file->setEnabled(true);
    ui->label_connect->setStyleSheet("background-color: rgb(00, 255, 0);border:1px solid#000000;border-radius:10px;");
    Tsocket = Tserver->nextPendingConnection();
    clientSock.append(Tsocket);
    ui->comboBox->addItem(Tsocket->peerAddress().toString());

    connect(Tsocket,SIGNAL(readyRead()),this, SLOT(read_data()));
    connect(Tsocket,SIGNAL(disconnected()),this, SLOT(disConnect()));
}

// 断开连接
void MainWin::disConnect()
{
    QTcpSocket *sock = static_cast<QTcpSocket *>(sender());
    int row = clientSock.indexOf(sock);
    if(mode == TcpServerMode)
    {
        clientSock.removeAll(sock);
        clientSock.at(row)->destroyed();
        ui->comboBox->removeItem(row);

        if(clientSock.length() == 0)
        {
            ui->label_connect->setStyleSheet("background-color: rgb(206, 206, 206);border:1px solid#000000;border-radius:10px;");
        }
    }
    else
    {
        Tsocket->close();
        ui->pushButton_connect->setText("开始连接");
        ui->label_connect->setStyleSheet("background-color: rgb(206, 206, 206);border:1px solid#000000;border-radius:10px;");
    }
    isConneted = false;
    ui->groupBox_mode->setEnabled(true);
    ui->pushButton_file->setEnabled(false);
}

// Tcp Server 模式
void MainWin::on_radioButton_TcpSvr_clicked()
{
    mode = TcpServerMode;
    ui->comboBox->clear();
    ui->pushButton_connect->setEnabled(true);
    ui->lineEdit_localport->setEnabled(true);
    ui->lineEdit_hostport->setEnabled(false);
    ui->pushButton_connect->setText("开始监听");
    QHostInfo hostinfo = QHostInfo::fromName(QHostInfo::localHostName());

    foreach (QHostAddress addr, hostinfo.addresses())
    {
        if(addr.protocol() == QAbstractSocket::IPv4Protocol)
        {
            ui->lineEdit_IP->setText(addr.toString());
            ui->lineEdit_IP->setEnabled(false);
        }
    }
}

// Tcp Client 模式
void MainWin::on_radioButton_TcpClt_clicked()
{
    mode = TcpClientMode;
     ui->comboBox->clear();
    ui->lineEdit_hostport->setEnabled(true);
    ui->lineEdit_localport->setEnabled(false);
    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_connect->setText("开始连接");
    ui->lineEdit_IP->clear();
    ui->lineEdit_IP->setEnabled(true);

    for(int i=0; i<clientSock.length(); i++)
    {
        clientSock.at(i)->disconnectFromHost();
        clientSock.removeAt(i);
    }
}

//Udp 模式
void MainWin::on_radioButton_Udp_clicked()
{
    mode = UdpMode;
    ui->pushButton_connect->setEnabled(true);
    ui->lineEdit_IP->setEnabled(true);
    ui->lineEdit_localport->setEnabled(true);
    ui->lineEdit_hostport->setEnabled(true);
    ui->pushButton_connect->setText("开启UDP");

    ui->comboBox->addItem("单播");
    ui->comboBox->addItem("组播");
    ui->comboBox->addItem("广播");
}

// 连接/断开
void MainWin::on_pushButton_connect_clicked()
{
    if(isConneted)
    {
        switch (mode) {
        case TcpServerMode:
            Tserver->close();
            ui->pushButton_connect->setText("开始监听");
            ui->label_connect->setStyleSheet("background-color: rgb(206, 206, 206);border:1px solid#000000;border-radius:10px;");
            break;
        case TcpClientMode:
            Tsocket->disconnectFromHost();
            Tsocket->close();
            ui->pushButton_connect->setText("开始连接");
            ui->label_connect->setStyleSheet("background-color: rgb(206, 206, 206);border:1px solid#000000;border-radius:10px;");
            break;
        case UdpMode:
            Uchat->Usocket->close();
            infoLabel->setText("");

            ui->comboBox->setEnabled(true);
            ui->lineEdit_IP->setEnabled(true);
            ui->pushButton_connect->setText("开启UDP");
            ui->label_connect->setStyleSheet("background-color: rgb(206, 206, 206);border:1px solid#000000;border-radius:10px;");
            break;
        default:
            break;
        }
        isConneted = false;
        ui->groupBox_mode->setEnabled(true);
        ui->pushButton_file->setEnabled(false);
    }
    else
    {
        if(ui->lineEdit_IP->text() == NULL)
        {
            QMessageBox::warning(this,"警告","请输入正确的IP地址");
            return;
        }
        switch (mode) {
        case TcpServerMode:
            if(Tserver->listen(static_cast<QHostAddress> (ui->lineEdit_IP->text()), ui->lineEdit_localport->text().toInt()))
            {
                connect(Tserver,SIGNAL(newConnection()),this, SLOT(newConnect()));
                ui->pushButton_connect->setText("停止监听");
                ui->pushButton_file->setEnabled(true);
            }
            else
            {
                QMessageBox::warning(this,"警告","监听失败");
                return;
            }
            break;
        case TcpClientMode:
            Tsocket->connectToHost(ui->lineEdit_IP->text(),ui->lineEdit_hostport->text().toInt());
            if(Tsocket->waitForConnected(1000))
            {
                connect(Tsocket,SIGNAL(readyRead()),this,SLOT(read_data()));
                connect(Tsocket,SIGNAL(disconnected()),this, SLOT(disConnect()));
                ui->pushButton_connect->setText("断开连接");
                ui->pushButton_file->setEnabled(true);
                ui->label_connect->setStyleSheet("background-color: rgb(00, 255, 0);border:1px solid#000000;border-radius:10px;");
            }
            else
            {
                QMessageBox::warning(this, "警告","连接错误");
                return;
            }
            break;
          case UdpMode:
            {
                Uchat->Ubind(Uchat->GetlocalAddr(),ui->lineEdit_localport->text().toInt());
                connect(Uchat->Usocket,SIGNAL(readyRead()),this,SLOT(read_data()));

                //状态栏显示本地IP和端口号
                QString str = QString("Local IP: %1:%2").arg(Uchat->GetlocalAddr().toString()).arg(ui->lineEdit_localport->text());
                infoLabel->setText(str);
                ui->statusbar->addWidget(infoLabel);

                ui->pushButton_connect->setText("关闭UDP");
                ui->label_connect->setStyleSheet("background-color: rgb(00, 255, 0);border:1px solid#000000;border-radius:10px;");
                if(ui->comboBox->currentText() == "单播")
                {
                }
                else if(ui->comboBox->currentText() == "组播")
                {
                    Uchat->Usocket->joinMulticastGroup(QHostAddress(ui->lineEdit_IP->text()));
                }
                else if(ui->comboBox->currentText() == "广播")
                {

                }
                ui->lineEdit_IP->setEnabled(false);
                ui->comboBox->setEnabled(false);
                break;
            }
        default:
            break;
        }

        isConneted = true;
        ui->groupBox_mode->setEnabled(false);
    }
}

// 发送数据
void MainWin::on_pushButton_snd_clicked()
{
    if(mode == UdpMode)
    {
        QString msg = ui->plainTextEdit_sndmsg->document()->toPlainText();
        QHostAddress peerAddr = QHostAddress(ui->lineEdit_IP->text());
        quint16 peerPort = ui->lineEdit_hostport->text().toInt();

        Uchat->UwriteData(msg.toUtf8(),peerAddr,peerPort);
        //消息右对齐
        QListWidgetItem *strItem = new QListWidgetItem(msg);
        strItem->setTextAlignment(Qt::AlignRight);
        ui->listWidget_rcvmsg->addItem(strItem);

        //如果不定时发送则每次发完清空发送框
        if(!ui->checkBox_autoSnd->isChecked())
            ui->plainTextEdit_sndmsg->clear();
    }
    else
    {
        QString peerAddr;
        QString filePath;
        QString message;
        QString str = ui->plainTextEdit_sndmsg->document()->toPlainText();
        if(str == NULL)
            return;

        int row = ui->comboBox->currentIndex();
        if(str.mid(1,2) == ":/")
        {
            filePath = str;
            QFileInfo info = QFileInfo(filePath);
            quint64 fileSize = info.size();
            qDebug()<<"fileSize:"<<fileSize;

            //添加到文件列表
            FileList *list = new FileList("right", ui->listWidget_rcvmsg);
            list->setFilePath(filePath);
            list->setFileSize(fileSize);

            if(mode == TcpServerMode)
            {
                peerAddr = ui->comboBox->currentText();
                clientSock.at(row)->write(QString("#snd#"+filePath+"("+QString("%1").arg(fileSize)+")").toUtf8());
            }
            else if(mode == TcpClientMode)
            {
                peerAddr = ui->lineEdit_IP->text();
                Tsocket->write(QString("#snd#"+filePath+"("+fileSize+")").toUtf8());
            }
            list->setpeerAddr(peerAddr);
            fileList.append(list);

            //显示到数据接收区
            QListWidgetItem *fileItem  = new QListWidgetItem();
            fileItem->setSizeHint(list->sizeHint());

            QSize size;
            size.setHeight(60);
            int row = ui->listWidget_rcvmsg->count();
            ui->listWidget_rcvmsg->addItem(fileItem);
            ui->listWidget_rcvmsg->setItemWidget(fileItem, list);
            ui->listWidget_rcvmsg->item(row)->setSizeHint(size);
            ui->listWidget_rcvmsg->item(row)->setText(filePath);
            ui->listWidget_rcvmsg->item(row)->setTextAlignment(Qt::AlignRight);

            ui->plainTextEdit_sndmsg->clear();
        }
        else
        {
            message = str;
            if(mode == TcpServerMode)
                clientSock.at(row)->write(str.toUtf8());
            else if(mode == TcpClientMode)
                Tsocket->write(str.toUtf8());

            //消息右对齐
            QListWidgetItem *strItem = new QListWidgetItem(str);
            strItem->setTextAlignment(Qt::AlignRight);
            ui->listWidget_rcvmsg->addItem(strItem);

            //如果不定时发送则每次发完清空发送框
            if(!ui->checkBox_autoSnd->isChecked())
                ui->plainTextEdit_sndmsg->clear();
        }
        QString cmd = QString("insert into record (ipAddr,message,filePath) values('%1','%2','%3');").arg(peerAddr).arg(message).arg(filePath);
        QSqlQuery query;
        query.exec(cmd);
    }
}

// 接收数据
void MainWin::read_data()
{
    if(mode == UdpMode)
    {
        QByteArray array;
        array.resize(Uchat->Usocket->bytesAvailable());
        Uchat->UreadData(array.data(),array.size());
        qDebug()<<array;
        QString str = array;
        ui->listWidget_rcvmsg->addItem(str);
    }
    else
    {
        QString  cmd;
        QSqlQuery query;

        QTcpSocket *sock = static_cast<QTcpSocket *>(sender());
        QString senderIP = sock->peerAddress().toString();

        QString msg = sock->readAll();
        qDebug()<<msg;
        //收到对方发来的文件
        if(msg.mid(0,5) == "#snd#")
        {
            msg.remove(0,5);
            int i = msg.indexOf("(");
            QString filePath = msg.mid(0,i);
            qDebug()<<"filePath:"<<filePath;

            int fileSize = msg.remove(filePath).remove("(").remove(")").toInt();
            qDebug()<<"fileSize:"<<msg.remove(filePath).remove("(").remove(")").toInt();

            QString fileName = filePath.right(filePath.size()-filePath.lastIndexOf('/')-1);
            qDebug() << "fileName:" << fileName;
            // fileSize = sizeConvert(fileSize);

            //添加到文件列表
            FileList *list = new FileList("left", ui->listWidget_rcvmsg);
            list->setpeerAddr(sock->peerAddress().toString());
            list->setFilePath(filePath);
            list->setFileSize(fileSize);
            fileList.append(list);

            QListWidgetItem *fileItem  = new QListWidgetItem();
            fileItem->setSizeHint(list->sizeHint());

            //显示到数据接收区
            QSize size;
            size.setHeight(80);
            int itemCnt = ui->listWidget_rcvmsg->count();
            ui->listWidget_rcvmsg->addItem(fileItem);
            ui->listWidget_rcvmsg->setItemWidget(fileItem, list);
            ui->listWidget_rcvmsg->item(itemCnt)->setSizeHint(size);
            ui->listWidget_rcvmsg->item(itemCnt)->setText(senderIP+"\n"+fileName+"("+sizeConvert(fileSize)+")");
            ui->listWidget_rcvmsg->item(itemCnt)->setTextAlignment(Qt::AlignLeft);

            cmd = QString("insert into record (ipAddr,filePath,fileSize) values('%1','%2','%3');").arg(senderIP).arg(filePath).arg(fileSize);
            query.exec(cmd);
        }
        //对方发出接收文件响应
        else if(msg.mid(0,5) == "#rcv#")
        {
            msg.remove(0,5);
            QString filePath = msg;

            //  qDebug()<<"filePath:"+filePath;
            qint8 listIndex = fileList.count();
            // qDebug()<<listIndex;
            for(; listIndex>0; listIndex--)
            {
                if(fileList.at(listIndex-1)->getFilePath() == filePath  && fileList.at(listIndex-1)->getpeerAddr() == sock->peerAddress().toString())
                {
                    // qDebug()<< "listIndex:"<<listIndex;
                    fileList.at(listIndex-1)->setFileSock(sock);
                    fileList.at(listIndex-1)->sendFile();
                    break;
                }
            }
        }
        //收到的是消息
        else
        {
            ui->listWidget_rcvmsg->addItem(senderIP+"\n"+msg);
            QString cmd = QString("insert into record (ipAddr,message) values('%1','%2');").arg(senderIP).arg(msg);
            QSqlQuery query;
            query.exec(cmd);
        }
    }

}

//清空接收区数据
void MainWin::on_pushButton_clear_clicked()
{
    ui->listWidget_rcvmsg->clear();
    QSqlQuery query;
    query.exec("delete from record;");
}

//自动发送
void MainWin::on_checkBox_autoSnd_clicked(bool checked)
{
    if(checked)
    {
        timer.start(ui->lineEdit_time->text().toInt());
        connect(&timer, SIGNAL(timeout()), this, SLOT(on_pushButton_snd_clicked()));
    }
    else
        timer.stop();
}

//浏览文件夹
void MainWin::on_pushButton_file_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this);
    ui->plainTextEdit_sndmsg->appendPlainText(filepath);
}

//保存文件
void MainWin::on_listWidget_rcvmsg_doubleClicked(const QModelIndex &index)
{
    QString filePath;
    QString savePath;
    QString message;
    QString peerAddr;
    QTcpSocket *sock = NULL;
    qint8 currentRow = index.row()+1;
    qDebug()<<"currentRow="<<currentRow;
    QString cmd = QString("select ipAddr,message,filePath,savePath from record where rowid=%1;").arg(currentRow);
    QSqlQuery query;
    query.exec(cmd);
    if(query.next())
    {
        message = query.value(1).toString();
        filePath = query.value(2).toString();
        savePath = query.value(3).toString();
    }

    if(message != NULL)
         return;
    if(savePath==NULL)
    {
        savePath = QFileDialog::getSaveFileName(this);
        //   qDebug()<<savePath;
        if(savePath != NULL)
        {
            if(mode == TcpServerMode)
            {
                qint8 clientIndex = 0;
                //查找文件发送者
                for(qint8 i=0; i<clientSock.count(); i++)
                {
                    if(clientSock.at(i)->peerAddress().toString() == query.value(0).toString())
                    {
                        clientIndex = i;
                        break;
                    }
                }
                sock = clientSock.at(clientIndex);
                peerAddr = clientSock.at(clientIndex)->peerAddress().toString();
            }
            else if(mode == TcpClientMode)
            {
                sock = Tsocket;
                peerAddr = Tsocket->peerAddress().toString();
            }
            //发送接收文件请求
            sock->write(QString("#rcv#"+filePath).toUtf8());

            qint8 i = fileList.count();
            // qDebug()<<listIndex;
            for(; i>0; i--)
            {
                if(fileList.at(i-1)->getFilePath() == filePath  && fileList.at(i-1)->getpeerAddr() == peerAddr)
                {
                    fileIndex = i-1;
                    break;
                }
            }

            cmd.clear();
            cmd = QString("update record set savePath='%1' where rowid=%2;").arg(savePath).arg(currentRow);
            query.exec(cmd);

            fileList.at(fileIndex)->setFileSock(sock);
            fileList.at(fileIndex)->setSavePath(savePath);
            fileList.at(fileIndex)->recvFile();

            //断开接收数据槽函数关联，转向接收文件，将要读到的数据为文件数据
            disconnect(sock,SIGNAL(readyRead()),this,SLOT(read_data()));
            connect(sock,SIGNAL(readyRead()),this,SLOT(recvFile()));
        }
    }
    else
    {
        QProcess *proc = new QProcess();
        proc->start("cmd.exe",QStringList()<<"/c"<<savePath);
    }
}

void MainWin::recvFile()
{
    QTcpSocket *sock = static_cast<QTcpSocket *>(sender());

    if(fileList.at(fileIndex)->recv_over)
    {
        disconnect(sock,SIGNAL(readyRead()),this,SLOT(recvFile()));
        connect(sock,SIGNAL(readyRead()),this,SLOT(read_data()));
    }
    else
        fileList.at(fileIndex)->recv_data();
}

QString MainWin::sizeConvert(quint64 value)
{
    if(value>=1024 && value<1024*1024)
        return QString("%1KB").arg(QString::number(value/1024.0,'f',2));
    else if(value>=1024*1024)
        return QString("%1MB").arg(QString::number(value/1024.0/1024.0,'f',2));
    else
        return QString("%1B").arg(value);
}


void MainWin::on_comboBox_activated(const QString &arg1)
{
    if(arg1 == "单播")
    {
        ui->lineEdit_IP->setEnabled(true);
        ui->lineEdit_IP->clear();
    }
    else if(arg1 == "组播")
    {
        ui->lineEdit_IP->setEnabled(true);
        ui->lineEdit_IP->setText("224.0.0.100");
    }
    else if(arg1 == "广播")
    {
        ui->lineEdit_IP->setText("255.255.255.255");
        ui->lineEdit_IP->setEnabled(false);
    }
}
