#include "mainwindow.h"
#include <QApplication>
#include "media.h"
#include "support_function.h"
#include <QSqlDatabase>
#include <QtCharts>
#include <QSqlQuery>
using namespace QtCharts;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //w.showFullScreen();
    //w.setVideoWidget();
    QString temp;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //connect to local database MySQL
    db.setHostName("localhost"); // hostname
    db.setDatabaseName("NearMe"); // db name
    db.setUserName("root"); //username for login to database
    db.setPassword("root"); //password for login to database
    db.setPort(3306); // default port connect
    if(!db.open()) //check connection
        qDebug() << "can not connect";
    else qDebug() << "connected";
    support_function abc;
    MainWindow w;
    QString event = "0";
    //abc.insertDateTime();
/*
    while(1){

        QString b  = abc.checkTimeToStartEvent();
        qDebug()<<b;
        if (b=="1" && event =="0"){
        w.display(b);
        event ="1";
        }
        else if (b=="0" && event=="1"){
            w.display(b);
            event ="0";
        }

        abc.delay_time(2000);
    }
*/
        return a.exec();
}

