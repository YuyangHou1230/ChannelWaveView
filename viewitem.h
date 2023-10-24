#ifndef VIEWITEM_H
#define VIEWITEM_H

#include <QWidget>

class ViewItem : public QWidget
{
    Q_OBJECT
public:
    explicit ViewItem(QWidget *parent = nullptr);

    void setValue(int value);
    void setValues(QList<int> value);
signals:

protected:
    void paintEvent(QPaintEvent *e) override;

private:
    QStringList m_content;
};

#endif // VIEWITEM_H
