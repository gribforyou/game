#include "menuwidget.h"
#include <QPushButton>
#include <QVBoxLayout>
MenuWidget::MenuWidget(QWidget *parent)
    : QWidget{parent}
{
    QPushButton* button = new QPushButton("NewGame");
    button->setObjectName("NewGame");
    button->setFlat(true);
    button->setMaximumWidth(100);
    button->setMinimumHeight(45);
    QVBoxLayout *verticalLayout = new QVBoxLayout();
    verticalLayout->addWidget(button, Qt::AlignHCenter);
    button = new QPushButton("Records");
    button->setFlat(true);
    button->setMaximumWidth(100);
    button->setMinimumHeight(45);
    button->setObjectName("Records");
    verticalLayout->addWidget(button, Qt::AlignHCenter);
    button = new QPushButton("Controls");
    button->setFlat(true);
    button->setMaximumWidth(100);
    button->setMinimumHeight(45);
    button->setObjectName("Controls");
    verticalLayout->addWidget(button);
    button = new QPushButton("Settings");
    button->setFlat(true);
    button->setMaximumWidth(100);
    button->setMinimumHeight(45);
    button->setObjectName("Settings");
    verticalLayout->addWidget(button);
    button = new QPushButton("Exit");
    button->setFlat(true);
    button->setMaximumWidth(100);
    button->setMinimumHeight(45);
    button->setObjectName("Exit");
    verticalLayout->addWidget(button);
    verticalLayout->setAlignment(Qt::AlignHCenter);
    this->setLayout(verticalLayout);
}
