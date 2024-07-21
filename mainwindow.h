#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menuwidget.h"
#include "gamewidget.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void show_menu();
    void show_game();
    void show_records();
    void show_settings();
    void show_control();
    void exit();
    void updateGameScene() ;
private:
    MenuWidget* menu;
    GameWidget *game;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
