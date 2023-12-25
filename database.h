#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>
class database
{
public:
    database();

    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QVector<QVector<QString>>userinfo;
    bool connect(QString user,int score);
    bool add(QString user, int score);
    bool del(QString name);
    bool findall();
};

#endif // DATABASE_H
