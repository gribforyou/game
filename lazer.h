#ifndef LAZER_H
#define LAZER_H

#include <QObject>
#include <QPainter>

class Lazer : public QObject
{
    Q_OBJECT
private:
    QLineF segment;
    bool isActive;
public slots:
    void update();
public:
    qreal chargeTimer, actionTimer;
    Lazer(QLineF, QObject *parent = 0);
    void setActive();
    void draw(QPainter *painter);
    bool getActive();
    ~Lazer() {}
};
#endif // LAZER_H
