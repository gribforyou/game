#include "gamewidget.h"
#include "mainwindow.h"
#include <QHBoxLayout>
#include <QPushButton>

qreal magnitude(QPointF p) {
    return sqrt(p.x() * p.x() + p.y() * p.y());
}

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    gameTimer = 0;
    player = new Player();
    QCursor::setPos(150, 200);
    timeLabel = new QLabel(this);
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setFixedSize(50, 30);
    timeLabel->move(125, 0);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, player, &Player::moveToTarget);
    connect(timer, &QTimer::timeout, this, &GameWidget::updateScene);
    connect(timer, &QTimer::timeout, this, &GameWidget::updateTime);
    timer->start(10);
    setMouseTracking(true);
    spawn_time = 2;
    kol = 3;
    bulletSpeed = 2;
}

void GameWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    player->draw(&painter);
    for(int i = 0; i<bullets.size(); i++)
        bullets[i]->draw(&painter);
    for(int i = 0; i<lazers.size(); i++)
        lazers[i]->draw(&painter);
}

void GameWidget::mouseMoveEvent(QMouseEvent * event)
{
    player->setTarget(event->position());
}

void GameWidget::checkDeath()
{
    for(int i = 0; i<bullets.size(); i++){
        if(magnitude(player->getPosition() - bullets[i]->getPosition()) < player->getRadius() + Bullet::getRadius())
            timer->stop();
    }
}

void GameWidget::spawnBullets(int n)
{
    Bullet *bullet;
    for(int i =0; i<n; i++) {
        bullet = new Bullet(bulletSpeed);
        bullets.push_back(bullet);
        connect(timer, &QTimer::timeout, bullet, &Bullet::update);
    };
}

void GameWidget::spawnLazers(int n)
{
    Lazer *lazer;
    for(int i = 0; i<n; i++){
        lazer = new Lazer(QLine(0, 0, 300, 400));
        lazers.push_back(lazer);
        //connect(timer, &QTimer::timeout, lazer, &Lazer::update);
        //connect(lazer, &QObject::destroyed, this, &GameWidget::removeLazer);
    }
}

void GameWidget::updateScene()
{
    // Bullet *bullet = new Bullet();
    // bullets.push_back(bullet);
    //connect(timer, &QTimer::timeout, bullet, &Bullet::move);
    update();
}

void GameWidget::updateTime()
{
    checkDeath();
    spawnTimer += 0.01;
    if(timeLabel->text().toDouble()==0.00)
    spawnLazers(1);
    if(spawnTimer > spawn_time){
        spawnBullets(rand() % (int)kol + 1);
        spawn_time *= 0.99;
        kol+=0.15;
        bulletSpeed += 0.02;
        spawnTimer = 0;
    };
    for(int i = 0; i<lazers.size(); i++) {
        if(!lazers[i]->getActive()){
            lazers[i]->chargeTimer-=0.01;
            if(lazers[i]->chargeTimer<=0){
                lazers[i]->setActive();
            }
        }
        else{
            lazers[i]->actionTimer-=0.01;
            if(lazers[i]->actionTimer<=0){
                lazers.erase(lazers.begin()+i);
            }
        }
    }

    gameTimer += 0.01;
    timeLabel->setText(QString::number(gameTimer));
    timeLabel->setText(QString::number(lazers.size()));
}

void GameWidget::removeLazer()
{
    std::remove(lazers.begin(), lazers.end(), qobject_cast<Lazer*>(sender()));
}
