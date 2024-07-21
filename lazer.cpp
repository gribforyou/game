#include "lazer.h"

void Lazer::update()
{
    if(!isActive){
        chargeTimer-=0.01;
        if(chargeTimer<=0)
            isActive = true;
    }
    else {
        actionTimer-=0.01;
        if(actionTimer<=0)
            delete this;
    };
}

Lazer::Lazer(QLineF segment, QObject *parent)
{
    this->segment = segment;
    isActive= false;
    chargeTimer = 2;
    actionTimer = 2;
    Q_UNUSED(parent);
}

void Lazer::draw(QPainter *painter) {
    QPen pen(Qt::SolidLine);
    if(!isActive){
        pen.setWidth(2);
        pen.setColor(Qt::darkGray);
    }
    else{
        pen.setWidth(5);
        pen.setColor(Qt::black);
    }
    painter->setPen(pen);
    painter->drawLine(segment.toLine());
}

bool Lazer::getActive()
{
    return isActive;
}

void Lazer::setActive() {
    isActive = true;
}


