#include "database.h"

database::database() {}


void database::connect(){

    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("mysql"); //
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();
    if (ok){
        qDebug()<<"success";
    }
    else {
        qDebug()<<"failed!";

    }
}

bool database::add(QString user,QString mark){
    QSqlQuery query(db);
    query.prepare("insert into users(username,password,permission) values(:user,:passwd,:per);");
    query.bindValue(":user",user);
    query.bindValue(":mark",mark);
    if(query.exec())
    {
        findall();
        return true;
    }
    return false;

}

bool database::del(QString name){

    QSqlQuery query(db);
    query.prepare("delete from users WHERE  username=:user;");
    query.bindValue(":user",name);
    if(query.exec())
    {
        findall();
        return true;
    }
    return false;
}

bool database::findall(){
    //userinfo.clear();
    QSqlQuery query(db);
    query.prepare("select * from users;");
    if(query.exec())
    {
        while (query.next()) {
            QVector<QString>rec;
            for(int i=0;i<query.record().count();i++)
            {
                rec.push_back(query.record().value(i).toString());
            }
            userinfo.push_back(rec);
        }
    }

}
