#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QTableWidget>
#include <QPushButton>
#include <QString>
#include <QPalette>
#include <QPixMap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void startgame();
    void EazyGame();
    void MediumGame();
   // void HardGame();
    //void ExpertGame();
    bool isValid(QString);
    bool defaultInTable(int,int);
    //bool findintable(QString);
public slots:
    void ChoseLevel();
    void BackIsClicked();
    void BackToLevels();
    void LevelIsClicked();
    void buttonPressedSlot();
    void helpgame();
    void resetgame();
    void solvegame();
    void rulesgame();
    void EraserIsClicked();
    void PenIsClicked();

    void clickeda(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *bar);

private:
    QTableWidget* table;
    QPushButton* one;
    QPushButton* two;
    QPushButton* three;
    QPushButton* four;
    QPushButton* five;
    QPushButton* sex;
    QPushButton* seven;
    QPushButton* eight;
    QPushButton* nine;
    QPushButton* pen;
    QPushButton* pensil;
    QPushButton* eraser;
private:
    QPushButton* eazy;
    QPushButton* medium;
    QPushButton* hard;
    QPushButton* expert;
    QPushButton* back;
    QWidget* game;
    QObject* level;
    QObject* penstyle;

};


#endif // MAINWINDOW_H
