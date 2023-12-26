#ifndef RANKLISTPAGE_H
#define RANKLISTPAGE_H

#include <QWidget>
#include <QLabel>
#include <QtGui/QTextLine>
#include <QPropertyAnimation>
#include <QDebug>
#include <QImage>
#include <QFile>
#include "hoverbutton.h"
#include "gamewidget.h"
#include <QTime>
#include <QTemporaryDir>
#include <QTextBrowser>
#include "client.h"
#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QHeaderView>
<<<<<<< HEAD
#include <QStandardItemModel>
=======
>>>>>>> 1275c8aa00fce8d77af47c8826c228218e6c0901

// #include "startpage.h"
// #include "ui_startpage.h"


extern Client *client;
extern database *mysql;

namespace Ui {
class rankListPage;
//class StartPage;
}

class rankListPage : public QWidget
{
  Q_OBJECT

public:
  explicit rankListPage(QWidget *parent = nullptr);
  QPropertyAnimation *bkAnim;
  void setUserRankList(QString s);
  void setRankList(QString s);
  ~rankListPage();
protected:
  virtual void keyPressEvent(QKeyEvent *ev);
private:
  Ui::rankListPage *ui;
  HoverButton *returnButton;
  QLabel *background;
  QTextBrowser *ranklist;
  QTextBrowser *userRanklist;
  QLabel *labelRanklist;
  QLabel *labelUserRanklist;

  QPropertyAnimation *  ShowBackground();
  QPropertyAnimation * ShowTitle();
  void SetButton();
  void setBkImg(QString path,QLabel *label);
  void setAdaptedImg(QString path,QLabel *label);
  void Sleep(int msec);
signals:
  void showStartPage();
};

#endif // RANKLISTPAGE_H
