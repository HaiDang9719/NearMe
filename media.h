#ifndef MEDIA_H
#define MEDIA_H
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QDebug>
#include <QTimer>
#include <QThread>

class media
{
public:
    media();
    void playvideo(QVideoWidget vw);
};

#endif // MEDIA_H
