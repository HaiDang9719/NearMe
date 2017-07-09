#ifndef SUPPORT_FUNCTION_DATABASE_H
#define SUPPORT_FUNCTION_DATABASE_H
#include<QString>
#include <QJsonArray>

class support_function
{
public:
    support_function();
    void delay_time(int millisecondsToWait);
    QString checkTimeToStartEvent();
    void insertDateTime();
    void deleteControlTable();
    void sendJsonStationPackage(QByteArray station);
};

#endif // SUPPORT_FUNCTION_DATABASE_H
