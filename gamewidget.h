#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include "player.h"
#include <QWidget>
#include <QTimer>
#include <QMouseEvent>
#include <QLabel>
#include "bullet.h"
#include "lazer.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void spawnBullets(int);
    void spawnLazers(int);

private slots:
    void updateScene();
    void updateTime();
    void removeLazer();

private:
    double kol;
    double spawn_time;
    qreal gameTimer, spawnTimer, bulletSpeed;
    QTimer *timer;
    Player *player;
    std::vector<Bullet*> bullets;
    std::vector<Lazer*> lazers;
    QLabel *timeLabel;
    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void checkDeath();
};

#endif // GAMEWIDGET_H
