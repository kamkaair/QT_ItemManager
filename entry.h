#ifndef ENTRY_H
#define ENTRY_H
#include <QString>
#include <QHBoxLayout>

#include <QWidget>
#include <QMouseEvent>

class Entry : public QWidget
{
    Q_OBJECT
public:
    Entry(QString charName, int seenAmount);
    QHBoxLayout* getHLayout() { return newHLayout; }

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:   
    QString characterName;
    unsigned int amountSeen = 0;

    QHBoxLayout* newHLayout = nullptr;
};

#endif // ENTRY_H
