#include "database.h"

database::database() {}

QSqlDatabase database::connect(){


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");  //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("db");
    db.setUserName("root");
    db.setPassword("666666");
    bool ok = db.open();
    if (ok){
        qDebug()<<"link success";
    }
    else {
        qDebug()<<"error open database because"<<db.lastError();
    }

    return db;
}

bool database::add(QString user,int score){

    QSqlQuery query;
    query.prepare("INSERT INTO game_rank (user, score) VALUES (:value1, :value2)");
    query.bindValue(":value1", user);
    query.bindValue(":value2", score);

    if (query.exec()) {
        qDebug() << "Insert successful";
        //userinfo.push_back(user);
        return true;
    }else{
        qDebug() << "Insert error:" << query.lastError().text();
    }
    return false;

}

bool database::change(QString user, int score){
    QSqlQuery query;
    query.prepare("UPDATE game_rank SET score=:score WHERE user=:user;");
    query.bindValue(":user",user);
    query.bindValue(":score",score);
    if (query.exec()) {
        qDebug() << "change successful";
        return true;
    }else{
        qDebug() << "change error:" << query.lastError().text();
    }
    return false;

}

bool database::rankList(){

}
