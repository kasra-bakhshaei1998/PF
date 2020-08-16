#include "Controller.h"
#include "Sun.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    factor=3;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200*factor,700*factor);
    cTimer = new QTimer();
    cTimer->start(40);
    holder = new  QGraphicsRectItem();
    holder->setRect(0,0,1200*factor,700*factor);

    scoreBoard = new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/mainscore.png"));
    scene->addItem(scoreBoard);
    scoreBoard->setPos(10*factor, 10*factor);


    controllerScore = new Score(holder);
    scene->addItem(controllerScore);
    controllerScore->setPos(50*factor, 118*factor);



}

Controller::~Controller(){
    delete cTimer;
    delete holder;
    delete scene;
    delete controllerScore;
}

void Controller::addZombie(const int& speed,const int& lives)
{
    zambieList.push_back(new Zambie{speed,cTimer,lives,holder});
    scene->addItem(zambieList.last());
    zambieList.last()->setPos(1200*factor,620);
}

void Controller::addSun()
{
    sunList.push_back(new Sun{scene,controllerScore,cTimer,holder});




}
