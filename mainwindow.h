#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QFormLayout>

#include <vector>
#include <entry.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void receiveEntry(Entry& inEntry);

private:
    QFormLayout* mainFormlayout;
    QFormLayout* selectFormlayout;

    std::vector<Entry*> mainEntries;
    std::vector<Entry*> selectedEntries;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
