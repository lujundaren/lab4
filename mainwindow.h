#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dwgobject.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<DwgObject *>  m_mainlist;     // 定义了一个数组用于保存所有屏幕上绘制的图元对象
    DrawType curDrawType = None;       // 定义一个变量用来记录当前鼠标正在绘制哪种图元
private slots:
    void on_actionPoint_triggered();

    void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
