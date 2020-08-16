#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Bullet : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int velocity;

public:
    explicit Bullet(QTimer *bulletTimer, const int& velocity, QGraphicsItem *parent = nullptr);

signals:

public slots:
    void MoveToRight();
};

#endif // BULLET_H
