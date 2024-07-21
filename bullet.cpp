#include "bullet.h"

int Bullet::radius = 5;

int Bullet::getRadius() {
    return radius;
}

QPointF Bullet::getPosition() const {
    return position;
}

Bullet::Bullet(qreal speed, QObject *parent)
{
    this->speed = speed;
    int height = 400, width = 300;
    QPointF target;
    int k = rand() % 4;
    switch(k) {
    case 0:
        position = QPointF(width, rand() % height);
        target = QPointF(rand() % (width / 2), rand() % height);
        break;
    case 1:
        position = QPointF(rand() % width, 0);
        target = QPointF(rand() % width, height - rand() % (height / 2));
        break;
    case 2:
        position = QPointF(0, rand() % height);
        target = QPointF(width - rand() % (width / 2), rand() % height);
        break;
    case 3:
        position = QPointF(rand() % width, height);
        target = QPointF(rand() % width, rand() % (height / 2));
        break;
    };
    direction = (target - position);
    direction /= sqrt(direction.x() * direction.x() + direction.y() * direction.y());
    Q_UNUSED(parent);
}

void Bullet::update() {
    this->position += speed * direction;
}

void Bullet::draw(QPainter *painter) {
    QRadialGradient gradient;
    gradient.setCenter(position);
    gradient.setRadius(radius);
    gradient.setFocalPoint(position);
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, Qt::black);
    QBrush brush(gradient);
    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->drawEllipse(position, radius, radius);
}
