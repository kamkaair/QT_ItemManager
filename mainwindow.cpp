#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFormLayout>
#include <array>

// Double-braces required in C++11 prior to (seemed to be needed in this case)
// https://en.cppreference.com/cpp/container/array
std::array<std::pair<QString, int>, 54> characters = {{
    {"Ana", 0},
    {"Anran", 0},
    {"Ashe", 0},
    {"Baptiste", 0},
    {"Bastion", 0},
    {"Brigitte", 0},
    {"Cassidy", 0},
    {"D.MON", 0},
    {"D.VA", 0},
    {"Doctrine", 0},
    {"Domina", 0},
    {"Doomfist", 0},
    {"Echo", 0},
    {"Emre", 0},
    {"Freja", 0},
    {"Genji", 0},
    {"Hanzo", 0},
    {"Hazard", 0},
    {"Illari", 0},
    {"Jetpack Cat", 0},
    {"Junker Queen", 0},
    {"Junkrat", 0},
    {"Juno", 0},
    {"Kiriko", 0},
    {"Lifeweaver", 0},
    {"Lucio", 0},
    {"Mauga", 0},
    {"Mei", 0},
    {"Mercy", 0},
    {"Mizuki", 0},
    {"Moira", 0},
    {"Orisa", 0},
    {"Pharah", 0},
    {"Ramattra", 0},
    {"Reaper", 0},
    {"Reinhardt", 0},
    {"Roadhog", 0},
    {"Shion", 0},
    {"Sierra", 0},
    {"Sigma", 0},
    {"Sojourn", 0},
    {"Soldier: 76", 0},
    {"Sombra", 0},
    {"Symmetra", 0},
    {"Torbjörn", 0},
    {"Tracer", 0},
    {"Vendetta", 0},
    {"Venture", 0},
    {"Widowmaker", 0},
    {"Winston", 0},
    {"Wrecking Ball", 0},
    {"Wuyang", 0},
    {"Zarya", 0},
    {"Zenyatta", 0},
}};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Example code from:
    // https://stackoverflow.com/questions/49020491/qlabel-and-qpushbutton-align
    QFormLayout* const formlayout = new QFormLayout(ui->scrollAreaWidgetContent);
    for(int i = 0; i < characters.size(); i++) {
        Entry* newEntry = new Entry(characters[i].first, i);

        formlayout->insertRow(i, newEntry->getHLayout());
        //hlayout.push_back(newEntry.getHLayout());
        entries.push_back(newEntry);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

