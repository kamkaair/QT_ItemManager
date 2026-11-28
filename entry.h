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
    Entry(QString charName, int inAmountSeen, int inIndex);
    QHBoxLayout* getHLayout() { return newHLayout; }
    unsigned int& getIndex() { return index; }

signals:
    void sendEntry(Entry& inEntry);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:   
    QString characterName;
    unsigned int seenAmount = 0, index = 0;

    QHBoxLayout* newHLayout = nullptr;
};

#endif // ENTRY_H
