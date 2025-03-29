#include "dwgobject.h"

DwgObject::DwgObject(QObject *parent)
    : QObject{parent}
{
}

void DwgObject::Draw(QPainter *p)
{
}
