#include "TodoWidget.h"
#include "ui_TodoWidget.h"

#include <QDebug>

TodoWidget::TodoWidget(QWidget *parent) : QWidget(parent, Qt::Dialog), ui(new Ui::TodoWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
}

TodoWidget::~TodoWidget()
{
    delete ui;
}

void TodoWidget::show()
{
    qDebug() << "show todowidget";
    move(1500, 120);
    QWidget::show();
    ui->todoWebView->run();
}
