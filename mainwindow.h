#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QHBoxLayout>
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

private:
    //void createEntry(QString buttonStr, QString labelName, int labelAmount);

    std::vector<QHBoxLayout*> hlayout;
    std::vector<Entry*> entries;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
