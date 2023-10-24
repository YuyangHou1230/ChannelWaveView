#include "viewitem.h"

#include <QPainter>

ViewItem::ViewItem(QWidget *parent) : QWidget(parent)
{

}

void ViewItem::setValue(int value)
{
    m_content.clear();
    m_content.append( QString::number(value));

    update();
}

void ViewItem::setValues(QList<int> values)
{
    m_content.clear();
    for(auto p : values){
        m_content.append( QString::number(p));
    }

    update();
}

void ViewItem::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);

    QPainter painter(this);

    painter.fillRect(rect().adjusted(3, 3, -3, -3), QColor(120, 120, 120));

    for(auto p : m_content){
         painter.drawText(rect(), Qt::AlignCenter,p);
    }

}
