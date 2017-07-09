#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "media.h"
#include "support_function.h"
#include <QLabel>
#include <QGraphicsView>
#include <QStackedWidget>
#include <QGraphicsScene>
#include <QDataStream>
#include <QFile>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QSvgRenderer>
#include <QGraphicsSvgItem>
#include <QMovie>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //while (1) {

   // }

}
void MainWindow::setVideoWidget(){
    // this part play mp3
    QMediaPlayer* player = new QMediaPlayer;
    //QVideoWidget* vw = new QVideoWidget;
    //player->setMedia(QUrl("https://1drv.ms/v/s!AlUHhEiXQDAKhgX0TDD3eYjQr4Q-"));
    player->setMedia(QUrl::fromLocalFile("/Users/admin/Downloads/a-2.mp4"));
    //ui->widget->resize(600,200);
    ui->widget->setGeometry(0,0,600,200);
    player->setVideoOutput(ui->widget);
    ui->widget->show();
    player->play();
    qDebug() << player->state();

}
void MainWindow::display(QString check){
   // QLabel lbdisplay;
    //support_function abc;
    //QString check = "0";
   static QGraphicsScene* scene = new QGraphicsScene();//set variable to display images
   static QGraphicsView* view = new QGraphicsView(scene); // set space to show images
   static QString Ifile = "/Users/admin/Downloads/SVG/happyhour.svg"; // path for picture.
   static QString Vfile = "/Users/admin/Downloads/SVG/giphy.gif"; // path for video.
   static QMovie *movie = new QMovie(Vfile);
   static QLabel *processLabel = new QLabel();
   // check = abc.checkTimeToStartEvent();
   if(check == "0" ){
       movie->stop();
       processLabel->close();
       scene->addItem(new QGraphicsSvgItem(Ifile));// this code show file.svg
   }
   else if(check == "1"){
        //This part to show file.gif
       processLabel->setMovie(movie);
       movie->start();
       scene->addWidget(processLabel);

   }
   view->showFullScreen(); // show image, gif as fullscreen
   view->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio); // set ratio, location of image in screen

}
MainWindow::~MainWindow()
{
    delete ui;
}
