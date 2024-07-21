#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuwidget.h"

#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedHeight(400);
    setFixedWidth(300);
    menu = new MenuWidget();
    connect(menu->findChild<QPushButton*>("NewGame"), &QPushButton::clicked, this, &MainWindow::show_game);
    connect(menu->findChild<QPushButton*>("Records"), &QPushButton::clicked, this, &MainWindow::show_records);
    connect(menu->findChild<QPushButton*>("Settings"), &QPushButton::clicked, this, &MainWindow::show_settings);
    connect(menu->findChild<QPushButton*>("Controls"), &QPushButton::clicked, this, &MainWindow::show_control);
    connect(menu->findChild<QPushButton*>("Exit"), &QPushButton::clicked, this, &MainWindow::exit);
    game = new GameWidget();
    show_menu();
    this->setWindowTitle("game");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_menu() {
    setCentralWidget(menu);
}

void MainWindow::show_game(){
    takeCentralWidget();
    setCentralWidget(game);
    //game->spawnBullets(20);
}
void MainWindow::show_records(){}
void MainWindow::show_settings(){}
void MainWindow::show_control(){}
void MainWindow::exit(){
    QMessageBox::StandardButton confirmExit = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите выйти?", QMessageBox::Yes | QMessageBox::No);

    if (confirmExit == QMessageBox::Yes) {
        QMessageBox::StandardButton confirmExit = QMessageBox::question(this, "Подтверждение", "Вы УВЕРЕНЫ, что хотите ВЫЙТИ?", QMessageBox::Yes | QMessageBox::No);

        if (confirmExit == QMessageBox::Yes) {
            qApp->quit();
        }
    }
}
void MainWindow::updateGameScene() {
    // QPixmap gameScenePixmap(findChild<QGraphicsView*>()->size());
    // gameScenePixmap.fill(Qt::white);
    // QPainter painter(&gameScenePixmap);
    // painter.setBrush(Qt::black);
    // painter.drawEllipse(0, 0, 100, 100);
    // gameScene.setPixmap(gameScenePixmap);
}
