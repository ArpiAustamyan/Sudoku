#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QSize>
#include <QLabel>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QModelIndex>
#include <QPushButton>
#include <QObject>
#include <QString>
#include <QPoint>
#include <QIcon>
#include <QMessageBox>
#include <QFont>
#include <QCloseEvent>
#include <QList>
QList<QPoint> defaultitems;
int myrow=0;
int mycolumn=0;
char matrixEazy[9][9]={{'5','4','8','7','3','1','2','9','6'},
                       {'6','9','1','8','4','2','7','5','3'},
                       {'3','2','7','9','5','6','8','1','4'},
                       {'7','3','2','6','9','8','5','4','1'},
                       {'8','6','9','4','1','5','3','2','7'},
                       {'1','5','4','2','7','3','6','8','9'},
                       {'4','1','6','5','8','7','9','3','2'},
                       {'9','7','5','3','2','4','1','6','8'},
                       {'2','8','3','1','6','9','4','7','5'}};
char matrixMedium[9][9]={{'4','6','3','7','1','8','5','9','2'},
                         {'1','5','8','4','2','9','3','7','6'},
                         {'7','9','2','3','6','5','8','1','4'},
                         {'3','7','9','1','4','6','2','8','5'},
                         {'8','1','6','2','5','3','9','4','7'},
                         {'5','2','4','8','9','7','6','3','1'},
                         {'6','3','7','5','8','4','1','2','9'},
                         {'2','4','5','9','3','1','7','6','8'},
                         {'9','8','1','6','7','2','4','5','3'}};
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Sudoku");
    QDesktopWidget desktop;
    QRect screenSize = desktop.availableGeometry(this);
    this->setFixedSize(screenSize.width()*0.40,screenSize.height()*0.45);


    QPixmap bgPic(":/images/aaaa.jpg");
    bgPic = bgPic.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bgPic);
    this->setPalette(palette);


}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::startgame()
{
    QWidget *parent = new QWidget();
    QLabel* slabel=new QLabel(parent);
    QPushButton* play=new QPushButton("PLAY",parent);
    QPushButton* rules=new QPushButton("RULES",parent);
    QPushButton* exit=new QPushButton("EXIT",parent);
    slabel->setFixedSize(QSize(200,100));
    slabel->setStyleSheet("font:bold 40px;color: #791007;background-color:none;");
    slabel->setText("Sudoku");
    slabel->move(180,50);
    play->setFixedSize(QSize(90,35));
    rules->setFixedSize(QSize(90,35));
    exit->setFixedSize(QSize(90,35));
    play->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;border-color: beige;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");
    rules->setStyleSheet("font-size : 10; color: #A85708; background-color:#EEDEAF;border-color: beige;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");
    exit->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;border-color: beige;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");
    QVBoxLayout* mainLayout = new QVBoxLayout(parent);
    mainLayout->addWidget(play);
    mainLayout->addWidget(rules);
    mainLayout->addWidget(exit);
    mainLayout->setContentsMargins(210,150,140,150);
    setLayout(mainLayout);
    mainLayout->addStretch();

    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(play,SIGNAL(clicked()),this,SLOT(ChoseLevel()));
    connect(rules,SIGNAL(clicked()),this,SLOT(rulesgame()));

     this->setCentralWidget(parent);
     this->show();
}
void MainWindow::ChoseLevel()
{

    QWidget* levelparent=new QWidget;
    eazy=new QPushButton("EAZY",levelparent);
    medium=new QPushButton("MEDIUM",levelparent);
    hard=new QPushButton("HARD",levelparent);
    expert=new QPushButton("EXPERT",levelparent);
    back=new QPushButton(levelparent);

    eazy->setFixedSize(QSize(90,35));
    medium->setFixedSize(QSize(90,35));
    hard->setFixedSize(QSize(90,35));
    expert->setFixedSize(QSize(90,35));

    back->setFixedSize(QSize(40,20));
    back-> setStyleSheet("border-image: url(:/images/backn.png);background-color: none;");
    back->move(0,390);

    QVBoxLayout* levelLayout = new QVBoxLayout(levelparent);
    levelLayout->addWidget(eazy);
    levelLayout->addWidget(medium);
    levelLayout->addWidget(hard);
    levelLayout->addWidget(expert);
    levelLayout->setContentsMargins(210,150,140,110);
    setLayout(levelLayout);
    levelLayout->addStretch();

   eazy->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");
   medium->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;border-color: beige;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");
   hard->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;border-color: beige;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");
   expert->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;border-color: beige;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");

    connect(eazy,SIGNAL(clicked()),this,SLOT(LevelIsClicked()));
    connect(medium,SIGNAL(clicked()),this,SLOT(LevelIsClicked()));
    connect(hard,SIGNAL(clicked()),this,SLOT(LevelIsClicked()));
    connect(expert,SIGNAL(clicked()),this,SLOT(LevelIsClicked()));

    connect(back,SIGNAL(clicked()),this,SLOT(BackIsClicked()));
    this->setCentralWidget(levelparent);
    this->show();
}
void MainWindow::BackIsClicked()
{
    startgame();
}
void MainWindow::LevelIsClicked()
 {
    game=new QWidget;
    back=new QPushButton(game);
    back-> setStyleSheet("border-image: url(:/images/backn.png);background-color: none;");
    back->setFixedSize(40,20);
    back->move(0,390);

    connect(back,SIGNAL(clicked()),this,SLOT(BackToLevels()));

  {
   one=new QPushButton("1",game);
   two=new QPushButton("2",game);
   three=new QPushButton("3",game);
   four=new QPushButton("4",game);
   five=new QPushButton("5",game);
   sex=new QPushButton("6",game);
   seven=new QPushButton("7",game);
   eight=new QPushButton("8",game);
   nine=new QPushButton("9",game);

   one->setFixedSize(QSize(33,33));
   two->setFixedSize(QSize(33,33));
   three->setFixedSize(QSize(33,33));
   four->setFixedSize(QSize(33,33));
   five->setFixedSize(QSize(33,33));
   sex->setFixedSize(QSize(33,33));
   seven->setFixedSize(QSize(33,33));
   eight->setFixedSize(QSize(33,33));
   nine->setFixedSize(QSize(33,33));

   one->move(QPoint(20,350));
   two->move(QPoint(53,350));
   three->move(QPoint(86,350));
   four->move(QPoint(119,350));
   five->move(QPoint(152,350));
   sex->move(QPoint(185,350));
   seven->move(QPoint(218,350));
   eight->move(QPoint(251,350));
   nine->move(QPoint(284,350));


   one->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                         "font:bold 14px;border-style: outset;border-radius: 8px;");   
   two->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                         "font:bold 14px;border-style: outset;border-radius: 8px;");
   three->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                         "font:bold 14px;border-style: outset;border-radius: 8px;");
   four->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                         "font:bold 14px;border-style: outset;border-radius: 8px;");
   five->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                         "font:bold 14px;border-style: outset;border-radius: 8px;");
   sex->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                         "font:bold 14px;border-style: outset;border-radius: 8px;");
   seven->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                         "font:bold 14px;border-style: outset;border-radius: 8px;");
   eight->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                         "font:bold 14px;border-style: outset;border-radius: 8px;");
   nine->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                         "font:bold 14px;border-style: outset;border-radius: 8px;");


    connect(one,SIGNAL(clicked(bool)),this, SLOT(buttonPressedSlot()));
    connect(two,SIGNAL(clicked(bool)),this, SLOT(buttonPressedSlot()));
    connect(three,SIGNAL(clicked(bool)),this, SLOT(buttonPressedSlot()));
    connect(four,SIGNAL(clicked(bool)),this, SLOT(buttonPressedSlot()));
    connect(five,SIGNAL(clicked(bool)),this, SLOT(buttonPressedSlot()));
    connect(sex,SIGNAL(clicked(bool)),this, SLOT(buttonPressedSlot()));
    connect(seven,SIGNAL(clicked(bool)),this, SLOT(buttonPressedSlot()));
    connect(eight,SIGNAL(clicked(bool)),this, SLOT(buttonPressedSlot()));
    connect(nine,SIGNAL(clicked(bool)),this, SLOT(buttonPressedSlot()));

}

 {
   pen=new QPushButton(game);
   pensil=new QPushButton(game);
   eraser=new QPushButton(game);

  pen -> setStyleSheet("border-image: url(:/images/pen.png);background-color: none;");
  pensil -> setStyleSheet("border-image: url(:/images/pencil.png);background-color: none;");
  eraser -> setStyleSheet("border-image: url(:/images/eraser.png);background-color: none;");

   pen->setFixedSize(QSize(40,40));
   pensil->setFixedSize(QSize(40,40));
   eraser->setFixedSize(QSize(30,30));

   pen->move(QPoint(330,100));
   pensil->move(QPoint(330,150));
   eraser->move(QPoint(330,200));

   connect(pensil,SIGNAL(clicked(bool)),this,SLOT(PenIsClicked()));
   connect(pen,SIGNAL(clicked(bool)),this,SLOT(PenIsClicked()));
   connect(eraser,SIGNAL(clicked(bool)),this,SLOT(EraserIsClicked()));
}

  {
   QPushButton* help=new QPushButton("HELP",game);
   QPushButton* reset=new QPushButton("RESET",game);
   QPushButton* solve=new QPushButton("SOLVE",game);
   QPushButton* rules=new QPushButton("RULES",game);

   help->setFixedSize(QSize(60,35));
   reset->setFixedSize(QSize(60,35));
   solve->setFixedSize(QSize(60,35));
   rules->setFixedSize(QSize(60,35));

   QVBoxLayout* gameLayout = new QVBoxLayout(game);
   gameLayout->addWidget(help);
   gameLayout->addWidget(reset);
   gameLayout->addWidget(solve);
   gameLayout->addWidget(rules);
   gameLayout->setContentsMargins(400,90,0,0);
   setLayout(gameLayout);
   gameLayout->addStretch();

   help->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");
   reset->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");
   solve->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");
   rules->setStyleSheet("font-size: 10; color: #A85708; background-color:#EEDEAF;padding: 6px;"
                        "font:bold 14px;border-style: outset;border-radius: 8px;");


   connect(help,SIGNAL(clicked(bool)),this,SLOT(helpgame()));
   connect(reset,SIGNAL(clicked(bool)),this,SLOT(resetgame()));
   connect(solve,SIGNAL(clicked(bool)),this,SLOT(solvegame()));
   connect(rules,SIGNAL(clicked(bool)),this,SLOT(rulesgame()));
}

   table=new QTableWidget(9,9,game);
   table->horizontalHeader()->setVisible(false);
   table->verticalHeader()->setVisible(false);
   table->resize(299,299);
   table->move(20,40);
   for(int i=0;i<9;i++)
   {
       table->setRowHeight(i,33);
       table->setColumnWidth(i,33);
   }

   for(int row = 0; row < table->rowCount(); row++)
     for(int column = 0; column < table->columnCount(); column++)
      {
         table->setItem(row, column, new QTableWidgetItem());
         table->item(row,column)->setTextAlignment(Qt::AlignCenter );
      }

   table->setStyleSheet(" color: #A85708; background-color:#ECDFB7;"
                        "font:bold 18px; ");

   level=sender();
   if(level==eazy)
       EazyGame();
   else if(level==medium)
        MediumGame();
   /*else if(level==hard)
       HardGame();
   else
       ExpertGame();*/

    connect(table, SIGNAL(clicked(QModelIndex)),
            this, SLOT(clickeda(QModelIndex)));


    this->setCentralWidget(game);
    this->show();
}
void MainWindow::EazyGame()
{

    table->item(0,0)->setText("5");
    table->item(0,5)->setText("1");
    table->item(0,6)->setText("2");
    table->item(0,8)->setText("6");
    defaultitems<<QPoint(0,0);
    defaultitems<<QPoint(0,5);
    defaultitems<<QPoint(0,6);
    defaultitems<<QPoint(0,8);
    table->item(1,0)->setText("6");
    table->item(1,1)->setText("9");
    table->item(1,4)->setText("4");
    table->item(1,6)->setText("7");
    defaultitems<<QPoint(1,0);
    defaultitems<<QPoint(1,1);
    defaultitems<<QPoint(1,4);
    defaultitems<<QPoint(1,6);
    table->item(2,3)->setText("9");
    table->item(2,8)->setText("4");
    defaultitems<<QPoint(2,3);
    defaultitems<<QPoint(2,8);
    table->item(3,0)->setText("7");
    table->item(3,4)->setText("9");
    table->item(3,5)->setText("8");
    table->item(3,6)->setText("5");
    table->item(3,8)->setText("1");
    defaultitems<<QPoint(3,0);
    defaultitems<<QPoint(3,4);
    defaultitems<<QPoint(3,5);
    defaultitems<<QPoint(3,6);
    defaultitems<<QPoint(3,8);
    table->item(4,0)->setText("8");
    table->item(4,1)->setText("6");
    table->item(4,7)->setText("2");
    table->item(4,8)->setText("7");
    defaultitems<<QPoint(4,0);
    defaultitems<<QPoint(4,1);
    defaultitems<<QPoint(4,7);
    defaultitems<<QPoint(4,8);
    table->item(5,0)->setText("1");
    table->item(5,2)->setText("4");
    table->item(5,3)->setText("2");
    table->item(5,4)->setText("7");
    table->item(5,8)->setText("9");
    defaultitems<<QPoint(5,0);
    defaultitems<<QPoint(5,2);
    defaultitems<<QPoint(5,3);
    defaultitems<<QPoint(5,4);
    defaultitems<<QPoint(5,8);
    table->item(6,0)->setText("4");
    table->item(6,5)->setText("7");
    defaultitems<<QPoint(6,0);
    defaultitems<<QPoint(6,5);
    table->item(7,2)->setText("5");
    table->item(7,4)->setText("2");
    table->item(7,7)->setText("6");
    table->item(7,8)->setText("8");
    defaultitems<<QPoint(7,2);
    defaultitems<<QPoint(7,4);
    defaultitems<<QPoint(7,7);
    defaultitems<<QPoint(7,8);
    table->item(8,0)->setText("2");
    table->item(8,2)->setText("3");
    table->item(8,3)->setText("1");
    table->item(8,8)->setText("5");
    defaultitems<<QPoint(8,0);
    defaultitems<<QPoint(8,2);
    defaultitems<<QPoint(8,3);
    defaultitems<<QPoint(8,8);
    return ;
}
void MainWindow::MediumGame()
{
    table->item(0,1)->setText("6");
    table->item(0,6)->setText("5");
    defaultitems<<QPoint(0,1);
    defaultitems<<QPoint(0,3);
    table->item(1,3)->setText("4");
    table->item(1,4)->setText("2");
    table->item(1,6)->setText("3");
    table->item(1,8)->setText("6");
    defaultitems<<QPoint(1,3);
    defaultitems<<QPoint(1,4);
    defaultitems<<QPoint(1,6);
    defaultitems<<QPoint(1,8);
    table->item(2,0)->setText("7");
    table->item(2,1)->setText("9");
    table->item(2,6)->setText("8");
    defaultitems<<QPoint(2,0);
    defaultitems<<QPoint(2,1);
    defaultitems<<QPoint(2,6);
    table->item(3,1)->setText("7");
    table->item(3,2)->setText("9");
    defaultitems<<QPoint(3,1);
    defaultitems<<QPoint(3,2);
    table->item(4,3)->setText("2");
    table->item(4,4)->setText("5");
    table->item(4,5)->setText("3");
    defaultitems<<QPoint(4,3);
    defaultitems<<QPoint(4,4);
    defaultitems<<QPoint(4,5);
    table->item(5,6)->setText("6");
    table->item(5,7)->setText("3");
    defaultitems<<QPoint(5,6);
    defaultitems<<QPoint(5,7);
    table->item(6,2)->setText("7");
    table->item(6,7)->setText("2");
    table->item(6,8)->setText("9");
    defaultitems<<QPoint(6,2);
    defaultitems<<QPoint(6,7);
    defaultitems<<QPoint(6,8);
    table->item(7,0)->setText("2");
    table->item(7,2)->setText("5");
    table->item(7,4)->setText("3");
    table->item(7,5)->setText("1");
    defaultitems<<QPoint(7,0);
    defaultitems<<QPoint(7,2);
    defaultitems<<QPoint(7,4);
    defaultitems<<QPoint(7,5);
    table->item(8,2)->setText("1");
    table->item(8,5)->setText("2");
    table->item(8,7)->setText("5");
    defaultitems<<QPoint(8,2);
    defaultitems<<QPoint(8,5);
    defaultitems<<QPoint(8,7);
    return ;
}
void MainWindow::buttonPressedSlot()
{
    QObject* obj = sender();

    if (obj==one && isValid(one->text()))
    {
        table->item(myrow,mycolumn)->setText("1");
    }
    else if (obj==two && isValid(two->text()))
    {
        table->item(myrow,mycolumn)->setText("2");

    }
    else if(obj== three && isValid(three->text()))
    {
        table->item(myrow,mycolumn)->setText("3");
    }
    else if(obj== four && isValid(four->text()))
    {
        table->item(myrow,mycolumn)->setText("4");
    }
    else if(obj== five && isValid(five->text()))
    {
        table->item(myrow,mycolumn)->setText("5");
    }
    else if(obj== sex && isValid(sex->text()))
    {
        table->item(myrow,mycolumn)->setText("6");
    }
    else if(obj==seven && isValid(seven->text()))
    {
        table->item(myrow,mycolumn)->setText("7");
    }
   else if(obj== eight && isValid(eight->text()))
    {
        table->item(myrow,mycolumn)->setText("8");
    }
    else if(obj== nine && isValid(nine->text()))
    {
        table->item(myrow,mycolumn)->setText("9");
    }
}
void MainWindow::clickeda(const QModelIndex &index)
{
    myrow=index.row();
    mycolumn=index.column();
}
bool MainWindow::isValid(QString tx)
{
  if(defaultInTable(myrow,mycolumn))
  return false;
  else
  {
    if(penstyle==pensil)
       {
        QFont font("Helvetica", 8, QFont::Bold);
        font.setPointSize(8);
        table->item(myrow,mycolumn)->setFont(font);
        return true;
    }
     else
    {
        for(int i=0;i<9;i++)
        if(tx==table->item(myrow,i)->text() && i!=mycolumn )
         return false;
       for(int i=0;i<9;i++)
        if(tx==table->item(i,mycolumn)->text() && i!=myrow)
          return false;
       return true;
    }
  }
}
void MainWindow::solvegame()
{
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(level==eazy)
                    table->item(i,j)->setText((QString)matrixEazy[i][j]);
                else if(level==medium)
                    table->item(i,j)->setText((QString)matrixMedium[i][j]);
                /*else if(level==hard)
                    table->item(i,j)->setText((QString)matrixHard[i][j]);
                else
                    table->item(i,j)->setText((QString)matrixExpert[i][j]);*/

}
void MainWindow::helpgame()
{
    if(level==eazy)
    {
        for(int i=0;i<9;i++)
         for(int j=0;j<9;j++)
       { if(table->item(i,j)->text()==(QString)matrixEazy[i][j] || table->item(i,j)->text()==NULL)
          continue;
        else
           table->item(i,j)->setBackgroundColor(QColor (242, 177, 164));
         }
    }
    else if (level==medium)
    {
        for(int i=0;i<9;i++)
         for(int j=0;j<9;j++)
        if((table->item(i,j)->text()==(QString)matrixMedium[i][j]) || table->item(i,j)->text()==NULL)
          continue;
        else
           table->item(i,j)->setBackgroundColor(QColor(242, 177, 164));
    }

}
void MainWindow::rulesgame()
{
    QWidget* helppage=new QWidget;
    QLabel*  rules=new QLabel(helppage);
    back=new QPushButton(helppage);
    back->setFixedSize(QSize(40,20));
    back-> setStyleSheet("border-image: url(:/images/backn.png);background-color: none;");
    back->move(0,390);
    rules->move(0,0);
    rules->setStyleSheet("font:bold 18px;color: #791007;");
    rules->setText("· There is only one valid solution to each Sudoku puzzle. <br/>"
                   "The only way the puzzle can be considered solved <br/>"
                   "correctly is when all 81 boxes contain numbers and the <br/>"
                   "other Sudoku  rules have been followed.<br/>"
                   "· When you start a game of Sudoku, some blocks will be <br/> "
                   "pre-filled for you. You cannot change these numbers in <br/>"
                   " the course of the game.<br/>"
                   "·Each column must contain all of the numbers 1 through <br/> "
                   "9 and no two numbers in the same column of a Sudoku<br/> "
                   " puzzle can be the same. <br/>"
                   "· Each row must contain all of the numbers 1 through <br/> 9"
                   "  and no two numbers in the same row of a Sudoku <br/>"
                   " puzzle can be the same.<br/>"
                   "· Each block must contain all of the numbers 1 through <br/> "
                   "9 and no two numbers in the same block of a Sudoku <br/> "
                   "puzzle can be the same.");
    connect(back,SIGNAL(clicked()),this,SLOT(BackIsClicked()));
    this->setCentralWidget(helppage);
    this->show();
}
void MainWindow::resetgame()
{
    for(int i=0;i<9;i++)
     for(int j=0;j<9;j++)
    if(!defaultInTable(i,j))
      table->item(i,j)->setText(NULL);
}
void MainWindow::PenIsClicked()
{
   penstyle=sender();
}
void MainWindow::EraserIsClicked()
{
    if(!defaultInTable(myrow,mycolumn))
    {
        table->item(myrow,mycolumn)->setText(NULL);
        table->item(myrow,mycolumn)->setBackgroundColor(QColor (236, 223, 183));
    }
}
void MainWindow::BackToLevels()
{
    ChoseLevel();
}
void MainWindow::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Exit?",
                                                                tr("Are you sure to close the game?"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::No);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}
bool MainWindow::defaultInTable(int x,int y)
{
    return defaultitems.contains(QPoint(x,y));
}













