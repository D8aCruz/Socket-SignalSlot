#include "socketTest.h"

socketTest::socketTest(QObject *parent) : QObject(parent)
{

}

void socketTest::Test()
{
    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    qDebug()<< "Connecting....";
    socket->connectToHost("192.168.43.95",80);

    if(!socket->waitForConnected(1000)){
        qDebug()<<"Error: "<<socket->errorString();
    }
}

void socketTest::connected(){
    qDebug()<<"Connected..";
    socket->write("#S$");
}
void socketTest::disconnected(){
    qDebug()<<"Disconnected..";
    socket->connectToHost("192.168.43.95",80);
}
void socketTest::bytesWritten(qint64 bytes){
    qDebug()<<"We wrote: "<<bytes;
}
void socketTest::readyRead(){
    qDebug()<<"Reading...";
    qDebug()<<socket->readAll();
}

