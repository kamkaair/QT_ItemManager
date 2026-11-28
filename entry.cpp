#include "entry.h"

#include <QLabel>
#include <QPushButton>
#include <iostream>

Entry::Entry(QString charName, int seenAmount) : characterName(charName), amountSeen(seenAmount)
{
    newHLayout = new QHBoxLayout();
    QLabel *labelName = new QLabel();

    // Push button
    QPushButton *pushButton = new QPushButton();
    pushButton->setFixedWidth(100);
    pushButton->setText("Create");
    //pushButton->setStyleSheet("background-color: green");
    newHLayout->addWidget(pushButton);

    // Character name label
    labelName->setText(charName);
    newHLayout->addWidget(labelName);

    // Amont of times seen label
    QLabel *labelNumber = new QLabel();
    labelNumber->setText(QString::number(seenAmount));
    labelNumber->setFixedWidth(100);
    newHLayout->addWidget(labelNumber);

    // Event filters for all of the elements. The signal should come everywhere from the widget
    pushButton->installEventFilter(this);
    labelName->installEventFilter(this);
    labelNumber->installEventFilter(this);
}

// https://runebook.dev/en/docs/qt/qwidget/mousePressEvent
bool Entry::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->button() == Qt::LeftButton) {
            qDebug() << "Mouse press on child at: " << mouseEvent->pos() << " - " << amountSeen;

            // Return false to let the event continue propagating to the child widget itself.
            // Return true to stop it here.
            //return false;
        }
    }
    return QObject::eventFilter(obj, event);
}
