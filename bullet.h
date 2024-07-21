#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QPainter>

class Bullet : public QObject
{
    Q_OBJECT
private:
    qreal speed;
    static int radius;
    QPointF position, direction;
public slots:
    void update();
public:
    Bullet(qreal speed, QObject *parent = 0);
    void draw(QPainter *painter);
    static int getRadius();
    QPointF getPosition() const;
    ~Bullet() {}
};

#endif // BULLET_H
