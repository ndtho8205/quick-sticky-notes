#ifndef TODOWIDGET_H
#define TODOWIDGET_H

#include <QWidget>

#include "TodoWebView.h"

namespace Ui {
class TodoWidget;
}

class TodoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TodoWidget(QWidget *parent = nullptr);
    ~TodoWidget();

    void show();

private:
    Ui::TodoWidget *ui;
};

#endif // TODOWIDGET_H
