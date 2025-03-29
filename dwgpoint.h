#ifndef DWGPOINT_H
#define DWGPOINT_H

#include "dwgobject.h"


class DwgPoint : public DwgObject
{
    enum PointType          // 该枚举类型用于区别点的样式与作用
    {
        Nomal,              // 正常点，显示为一个小圆
        CrossPt,            // 作为圆等形状的中心点，显示正十字交叉形状
        ControlPt           // 作为控制直线、圆等大小长短的点，显示为小方框
    };

    Q_OBJECT
public:
    explicit DwgPoint(QObject *parent = nullptr);

    DwgPoint& operator = (const QPointF& pt);		// 该赋值运算符重载，用于使用QPointF对点进行赋值

    qreal mx,my,mz;         // 点的三维坐标，实数类型
    PointType mShape;

    // DwgObject interface
public:
    void Draw(QPainter *p);
};

#endif // DWGPOINT_H
