#include "View.h"
#include "Controller.h"

View::View() : QGraphicsView()
{
    viewcontroller = new Controller();
    setScene(viewcontroller->scene);
    setBackgroundBrush(QBrush(QImage(":/images/backgroundasli.jpg")));
    setFixedSize(3600,2100);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    viewplayer = new QMediaPlayer();
    viewplayer->setMedia(QUrl("qrc:/music/Trap.mp3"));
    viewplayer->play();

    seconds=0;

    viewTimer = new QTimer();
    viewTimer->start(1000);
    connect(viewTimer, SIGNAL(timeout()), this, SLOT(PlayTime()));
}

View::~View(){
    delete viewTimer;
    delete viewplayer;
    delete viewcontroller;
}

void View::Scheduel(){
    ++seconds;
    if(seconds == 50 || seconds==54 || seconds== 57 || seconds== 59 ||seconds==60 ){
        viewcontroller->addZombie(6 * viewcontroller->factor,10);
}

    if(seconds % 2 == 0){
        viewcontroller->addSun();
    }
}
