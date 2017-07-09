#include "support_function.h"
#include <QJsonObject>
#include<QJsonDocument>
#include<QDebug>
#include <QJsonArray>
#include <QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QTime>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
support_function::support_function()
{

}
void support_function::delay_time(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
QString support_function::checkTimeToStartEvent()
{
    QSqlQuery query;
    QString total;
    QDateTime time_start,time_end;
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    query.prepare("SELECT COUNT(event_TimeStart) FROM Display");
    query.exec();
    if(query.next())
        {
            total = query.value(0).toString();
            qDebug().noquote()<<total;
        }
        else
        {
            qDebug()<<"count not successful";
        }

   query.prepare("SELECT event_TimeStart, event_TimeEnd FROM Display WHERE idD = 4");
   query.exec();
   if(query.next())
   {
       time_start = query.value(0).toDateTime();
       time_end = query.value(1).toDateTime();
   }
   qDebug()<<time_start;
   qDebug()<<time_end;
   qDebug()<<dateTime;
   if((time_start < dateTime) && (time_end >dateTime)) return "1";
   else return "0";

}

void support_function::insertDateTime()
{
    QSqlQuery query;
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<dateTimeString;
    query.prepare("INSERT INTO Display (idD,sign_Name,event_TimeStart) "
                    "VALUES (?, ?, ?)");
    query.bindValue(0,4);
    query.bindValue(1,"gdi");
    query.bindValue(2,dateTimeString);
    if(query.exec())
        {
            qDebug()<<"insert successful";
        }
        else
        {
            qDebug()<<"insert not successful";
        }
}

// delete control table
void support_function::deleteControlTable()
{
    QSqlQuery query;
    query.prepare("DELETE FROM control WHERE GlobalID IS NOT NULL");
    if(query.exec())
    {
        qDebug()<<"delete success";
    }
    else qDebug()<<"delete not success";
}
void support_function::sendJsonStationPackage(QByteArray station)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QUrl url("https://accounts.google.com/o/oauth2/token");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrl params;
    params.addQueryItem("client_id", "...");
    params.addQueryItem("client_secret", "...");
    params.addQueryItem("code", "...");
    // etc

    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    manager->post(request, params.encodedQuery());
}
