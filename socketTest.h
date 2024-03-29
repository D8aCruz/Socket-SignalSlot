#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>

class socketTest : public QObject
{
    Q_OBJECT
public:
    explicit socketTest(QObject *parent = nullptr);
    void Test();
signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
private:
    QTcpSocket *socket;
};

#endif // SOCKETTEST_H
