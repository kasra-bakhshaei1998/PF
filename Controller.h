#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <Zambie.h>
#include <Score.h>
#include <Sun.h>

class Controller : public QObject
{
    Q_OBJECT
    friend class View;
private:
    QGraphicsScene *scene;
    QList<Zambie *> zambieList;
    QList<Sun *> sunList;
    QTimer *cTimer;
    QGraphicsRectItem *holder;
    QGraphicsPixmapItem *scoreBoard;
    Score *controllerScore;
    int factor;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    void addZombie(const int& velocity, const int& lives);
    void addSun();


signals:

public slots:
};

#endif // CONTROLLER_H
