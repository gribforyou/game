#include "player.h"

Player::Player(QObject *parent)
{
    Q_UNUSED(parent);
}

void Player::setTarget(QPointF position) {
    targetPosition = position;
}

void Player::draw(QPainter *painter) {
    QRadialGradient gradient;
    gradient.setCenter(position);
    gradient.setRadius(radius);
    gradient.setFocalPoint(position);
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, Qt::red);
    QBrush brush(gradient);
    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->drawEllipse(position, radius, radius);
}

QPointF Player::getPosition() const
{
    return position;
}

int Player::getRadius() const
{
    return radius;
}

void Player::moveToTarget()
{
    position += (targetPosition - position) / 16;
}
