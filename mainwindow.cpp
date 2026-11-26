#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QFormLayout>

struct Entry {
    QString characterName;
    unsigned int amountSeen = 0;
};

std::vector<Entry> createEntries() { // Big list of entries
    std::vector<Entry> entryVec;

    entryVec.push_back({"Ana", 0});
    entryVec.push_back({"Anran", 0});

    entryVec.push_back({"Ashe", 0});
    entryVec.push_back({"Baptiste", 0});

    entryVec.push_back({"Bastion", 0});
    entryVec.push_back({"Brigitte", 0});

    entryVec.push_back({"Cassidy", 0});
    entryVec.push_back({"D.MON", 0});

    entryVec.push_back({"D.VA", 0});
    entryVec.push_back({"Cassidy", 0});

    entryVec.push_back({"Domina", 0});
    entryVec.push_back({"Doomfist", 0});

    entryVec.push_back({"Echo", 0});
    entryVec.push_back({"Emre", 0});

    entryVec.push_back({"Freja", 0});
    entryVec.push_back({"Genji", 0});

    entryVec.push_back({"Hanzo", 0});
    entryVec.push_back({"Hazard", 0});

    entryVec.push_back({"Illari", 0});
    entryVec.push_back({"Jetpack Cat", 0});

    entryVec.push_back({"Junker Queen", 0});
    entryVec.push_back({"Junkrat", 0});

    entryVec.push_back({"Juno", 0});
    entryVec.push_back({"Kiriko", 0});

    entryVec.push_back({"Lifeweaver", 0});
    entryVec.push_back({"Lucio", 0});

    entryVec.push_back({"Mauga", 0});
    entryVec.push_back({"Mei", 0});

    entryVec.push_back({"Mercy", 0});
    entryVec.push_back({"Mizuki", 0});

    entryVec.push_back({"Moira", 0});
    entryVec.push_back({"Orisa", 0});

    entryVec.push_back({"Pharah", 0});
    entryVec.push_back({"Ramattra", 0});

    entryVec.push_back({"Reaper", 0});
    entryVec.push_back({"Reinhardt", 0});

    entryVec.push_back({"Roadhog", 0});
    entryVec.push_back({"Shion", 0});

    entryVec.push_back({"Sierra", 0});
    entryVec.push_back({"Sigma", 0});

    entryVec.push_back({"Sojourn", 0});
    entryVec.push_back({"Soldier: 76", 0});

    entryVec.push_back({"Sombra", 0});
    entryVec.push_back({"Symmetra", 0});

    entryVec.push_back({"Torbjörn", 0});
    entryVec.push_back({"Tracer", 0});

    entryVec.push_back({"Vendetta", 0});
    entryVec.push_back({"Venture", 0});

    entryVec.push_back({"Widowmaker", 0});
    entryVec.push_back({"Winston", 0});

    entryVec.push_back({"Wrecking Ball", 0});
    entryVec.push_back({"Wuyang", 0});

    entryVec.push_back({"Zarya", 0});
    entryVec.push_back({"Zenyatta", 0});

    return entryVec;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<Entry> entryVec = createEntries();

    // Example code from:
    // https://stackoverflow.com/questions/49020491/qlabel-and-qpushbutton-align
    QFormLayout* const formlayout = new QFormLayout(ui->scrollAreaWidgetContent);
    for(size_t i = 0; i < entryVec.size(); i++)
    {
        QHBoxLayout* newHLayout = new QHBoxLayout();
        QLabel *labelName = new QLabel();

        // Push button
        QPushButton *pushButton = new QPushButton();
        pushButton->setFixedWidth(100);
        pushButton->setText("Create");
        //pushButton->setStyleSheet("background-color: green");
        newHLayout->addWidget(pushButton);

        // Character name label
        labelName->setText(entryVec[i].characterName);
        newHLayout->addWidget(labelName);

        // Amont of times seen label
        QLabel *labelNumber = new QLabel();
        labelNumber->setText(QString::number(entryVec[i].amountSeen));
        labelNumber->setFixedWidth(100);
        newHLayout->addWidget(labelNumber);

        formlayout->insertRow(i, newHLayout);
        hlayout.push_back(newHLayout);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

