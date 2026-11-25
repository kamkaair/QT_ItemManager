#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QFormLayout>

// Temp
#include <QCheckBox>

void MainWindow::createEntry(QString buttonStr, QString labelName, int labelAmount) {
    QHBoxLayout *layout = new QHBoxLayout(this);

    QWidget* widgetEntry = new QWidget;

    QPushButton* btnInteract = new QPushButton("Interaction", this);
    QLabel* lblName = new QLabel(labelName, this);
    QLabel* lblAmount = new QLabel(QString::number(labelAmount), this);

    layout->addWidget(btnInteract);
    layout->addWidget(lblName);
    layout->addWidget(lblAmount);

    ui->scrollAreaWidgetContent->setLayout(layout);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //createEntry("Hehe lambao", "Orisa", 5);
    //createEntry("keel", "Soldier", 2);

    // Example code from:
    // https://stackoverflow.com/questions/49020491/qlabel-and-qpushbutton-align
    QFormLayout* const formlayout = new QFormLayout(ui->scrollAreaWidgetContent);
    QHBoxLayout* hlayout[100];
    QLineEdit* lineEdit[100];
    for(int i=0; i!=100; ++i)
    {
      hlayout[i] = new QHBoxLayout();
      QLabel *label = new QLabel();
      label->setText(QString::number(i));
      label->setStyleSheet("background-color: red");
      label->setFixedWidth(100);
      hlayout[i]->addWidget(label);
      //
      QPushButton *pushButton = new QPushButton();
      int menu_x_pos = label->pos().x();
      int menu_y_pos = label->pos().y();
      pushButton->setGeometry(menu_x_pos+120, menu_y_pos,10,20);
      pushButton->setText(QString::number(i));
      pushButton->setStyleSheet("background-color: green");
      hlayout[i]->addWidget(pushButton);
      //
      QCheckBox *checkbox = new QCheckBox();
      checkbox->setText("CheckB:");
      hlayout[i]->addWidget(checkbox);
      //
      lineEdit[i] = new QLineEdit;
      lineEdit[i]->setText("Text");
      hlayout[i]->addWidget(lineEdit[i]);
      // now line up all widgets in a row
      formlayout->insertRow(i,hlayout[i]);
    }

    //ui->ScrollMain->addScrollBarWidget();
    //window->setLayout();
}

MainWindow::~MainWindow()
{
    delete ui;
}

