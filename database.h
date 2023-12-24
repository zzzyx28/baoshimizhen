#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
class database
{
public:
    database();

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QVector<QVector<QString>>userinfo;
    void connect();
    bool add(QString user, QString mark);
    bool del(QString name);
    bool findall();
};

#endif // DATABASE_H
