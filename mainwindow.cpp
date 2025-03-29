#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dwgobject.h"
#include "dwgpoint.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPoint_triggered()
{
    curDrawType = DPoint;           // 点击绘图菜单中的Point菜单项，设置当前绘图类型为点
}


void MainWindow::on_actionNew_triggered()
{
    m_mainlist.clear();             // 点New，就是清除主链表，并刷新屏幕
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    DwgPoint *pt;
    if(curDrawType & DPoint)
    {
        pt = new DwgPoint;
        *pt = event -> pos();
        m_mainlist.append(pt);
    }
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(auto& i : m_mainlist)
        i->Draw(&painter);
}
