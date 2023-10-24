#include "waveview.h"

#include "viewitem.h"

#include <QVBoxLayout>
#include <QGridLayout>

WaveView::WaveView(QWidget *parent) : QWidget(parent),
    m_viewMode(ViewMode::ModeNormal)
{
    m_displayMode = -1;
}

void WaveView::setData(QList<int> datas)
{
    m_datas = datas;
    updateLayout();
}

void WaveView::updateLayout()
{
    if(m_datas.size() == 0){
       setLayout(nullptr);
        return;
    }

    if(m_viewMode != m_displayMode){
         clearContent();
        switch (m_viewMode) {
            case WaveView::ModeNormal:
            {
                QVBoxLayout *layout = new QVBoxLayout();
                ViewItem *item = new ViewItem();
                item->setValues(m_datas);
                item->setMinimumHeight(150);
                layout->addWidget(item);
                setLayout(layout);

            }
                break;
            case WaveView::ModeVertical:
            {
                QVBoxLayout *layout = new QVBoxLayout();
                for(auto p : m_datas){
                    ViewItem *item = new ViewItem();
                    item->setValue(p);
                    item->setMinimumHeight(50);
                    layout->addWidget(item);
                }
                setLayout(layout);

            }
                break;
            case WaveView::ModeGrid:
            {
                QGridLayout *layout = new QGridLayout();
                const int columnMax = 3;
                int i = 0;
                for(auto p : m_datas){
                    int row = i / columnMax;
                    int column = i % columnMax;

                    ViewItem *item = new ViewItem();
                    item->setValue(p);
                    item->setMinimumHeight(50);
                    layout->addWidget(item, row, column);
                    i++;
                }

                setLayout(layout);
            }
                break;
            case WaveView::ModeDock:
                break;

        }
        m_displayMode = m_viewMode;
    }
    else{

    }


}

void clearLayout(QLayout* layout) {
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        QWidget* widget = item->widget();
        if (widget) {
            widget->deleteLater();
        } else {
            QLayout* sublayout = item->layout();
            if (sublayout) {
                clearLayout(sublayout);
            }
        }
        delete item;
    }
}

void clearWidgetLayout(QWidget* widget) {
    QLayout* layout = widget->layout();
    if (layout) {
        clearLayout(layout);
        delete layout;
        layout = nullptr;
    }
//    widget->setLayout(nullptr);
}

void WaveView::clearContent()
{
    clearWidgetLayout(this);
}


WaveView::ViewMode WaveView::viewMode() const
{
    return m_viewMode;
}

void WaveView::setViewMode(const ViewMode &viewMode)
{
    m_viewMode = viewMode;

    updateLayout();
}
