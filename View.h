#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include "Controller.h"
class View :  public QGraphicsView
{
    Q_OBJECT

private:
    QTimer *viewTimer;
    int seconds;
    QMediaPlayer *viewplayer;
    Controller *viewcontroller;

public:
    explicit View();
    ~View();

public slots:
    void Scheduel();

signals:

public slots:
};

#endif // VIEW_H
