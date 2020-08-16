#include "Bullet.h"
#include <QGraphicsScene>
#include <QList>
#include "Zambie.h"




Bullet::Bullet(QTimer *bulletTimer, const int &velocity, QGraphicsItem *parent)
    :QObject() , QGraphicsPixmapItem(parent), velocity{velocity}
{
    setPixmap(QPixmap(":/images/bullet.PNG"));
    connect(bulletTimer,SIGNAL(timeout()),this,SLOT(MoveToRight()));
}

void Bullet::MoveToRight()
{
    QList<QGraphicsItem *> collection = collidingItems();
    for(size_t i{0}; i<collection.size(); i++){
        dynamic_cast<Zambie *>(collection[i])->decreamentLives();
        scene()->removeItem(this);
        delete this;
        return;


    }

    setPos(x()+velocity ,y());
    if(x()> 3600){
        scene()->removeItem(this);
        delete this;
    }
}
