#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QTableView>
class database
{
public:
    database();

    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QVector<QString>userinfo;
    QSqlDatabase connect();
    bool add(QString user, int score);
    bool change(QString user,int score);
    bool del(QString name);
    bool rankList();
    bool findall();
};

#endif // DATABASE_H
