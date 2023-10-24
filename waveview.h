#ifndef WAVEVIEW_H
#define WAVEVIEW_H

#include <QWidget>

class WaveView : public QWidget
{
    Q_OBJECT
public:
    enum ViewMode
    {
        ModeNormal,
        ModeVertical,
        ModeGrid,
        ModeDock,
    };

    explicit WaveView(QWidget *parent = nullptr);

    void setData(QList<int> datas);

    ViewMode viewMode() const;
    void setViewMode(const ViewMode &viewMode);

private:
    void updateLayout();
    void clearContent();

private:
    ViewMode m_viewMode;
    int m_displayMode;
    QList<int> m_datas;
};

#endif // WAVEVIEW_H
