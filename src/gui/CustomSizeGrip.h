#ifndef CUSTOMSIZEGRIP_H
#define CUSTOMSIZEGRIP_H

#include <QSizeGrip>

class CustomSizeGrip : public QSizeGrip
{
    Q_OBJECT
public:
    explicit CustomSizeGrip(QWidget *parent = nullptr);

    void mouseReleaseEvent(QMouseEvent *event);

signals:
    bool resized();

public slots:

private:
    bool mResizing;
};

#endif // CUSTOMSIZEGRIP_H
