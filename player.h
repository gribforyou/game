#ifndef PLAYER_H
#define PLAYER_H

#include <QPainter>
#include <QObject>

class Player : public QObject
{
    Q_OBJECT
private:
    QPointF position = QPoint(100, 100), targetPosition = QPoint(100, 100);
    int radius = 7;
public:
    Player(QObject *parent = 0);
    void setTarget(QPointF);
    void draw(QPainter *painter);
    ~Player() {}
    QPointF getPosition() const;
    int getRadius() const;
public slots:
    void moveToTarget();
};

#endif // PLAYER_H
