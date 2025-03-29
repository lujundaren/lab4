#include "dwgpoint.h"

DwgPoint::DwgPoint(QObject *parent)
    : DwgObject{parent}
{
    mShape = Nomal;
}
DwgPoint &DwgPoint::operator =(const QPointF &pt)
{
    this->mx=pt.x();
    this->my = pt.y();
    this->mz = 0.0;

    return *this;
}


void DwgPoint::Draw(QPainter *p)					// 重载了父类的Draw函数
{
    if(mShape == Nomal)							// 判断是否是正常点，如果是，画个红点
    {
        p->setBrush(QBrush(Qt::red));
        p->drawEllipse(mx-2.5,my-2.5,5,5);
    }
    else if(mShape & CrossPt)						// 通过位比较判断是否是交叉点，如果是，画交叉直线段
    {
        p->drawLine(mx,my-2.5,mx,my+2.5);
        p->drawLine(mx-2.5,my,mx+2.5,my);
    }
}
