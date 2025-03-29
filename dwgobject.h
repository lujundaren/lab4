#ifndef DWGOBJECT_H
#define DWGOBJECT_H

#include <QObject>
#include <QPainter>

enum DrawType       // 这里定义了图元和绘图的类型，图元类型存储在图元中，绘图类型主要应用于鼠标交互操作
{
    None,
    DPoint,
    DLine,
    DCircle,
    DRectangle
};

class DwgObject : public QObject
{
    Q_OBJECT
public:
    explicit DwgObject(QObject *parent = nullptr);

    long mID;                   // 用于记录该图元的ID唯一标识号
    DrawType mType = None;             // 用于记录该图元的类型, 缺省是None
    QColor mColor = QColor(0,0,0);          // 用于设置该图元的颜色 ，缺省是黑色
    Qt::PenStyle mLineType = Qt::SolidLine; // 用于记录该图元的线型 ，缺省是实线

    virtual void Draw(QPainter *p);
signals:
};

#endif // DWGOBJECT_H
