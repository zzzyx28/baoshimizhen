#include "database.h"

database::database() {}

bool database::connect(QString user,int score){


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

    QSqlQuery query;
    query.prepare("INSERT INTO game_rank (user, score) VALUES (:value1, :value2)");
    query.bindValue(":value1", user);
    query.bindValue(":value2", score);

    if (query.exec()) {
        qDebug() << "Insert successful";
        return true;
        qDebug() << "Insert error:" << query.lastError().text();
    }
    return false;

    return db.isOpen();
}

bool database::add(QString user,int score){
    // qDebug()<<"into adding"<<db.lastError();
    // QSqlQuery query(db);
    // qDebug()<<"before prepare"<<db.lastError();
    // query.prepare("insert into rank(user,score) values(:user,:score);");
    // qDebug()<<"after prepare";
    // query.bindValue(":user",user);
    // qDebug()<<"after bindValue";
    // query.bindValue(":score",score);
    // if(query.exec())
    // {
    //     findall();
    //     return true;
    // }else{
    //     qDebug()<<"fail to add";
    // }
    // return false;
    QSqlQuery query;
    query.prepare("insert into rank(user,score) values(:user,:score);");
    query.bindValue(":user",user);
    query.bindValue("score",score);
    query.exec("insert into rank values('qwert',123);");
    if(query.execBatch()){
        qDebug()<<"success to exec"<<"   user:  "<<user<<"     score:  "<<score;
    }else{
        qDebug()<<"fail to exec";
    }
}

