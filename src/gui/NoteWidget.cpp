#include "NoteWidget.h"
#include "ui_NoteWidget.h"

NoteWidget::NoteWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::NoteWidget) {
  auto centralWidget = new QWidget(this);
  ui->setupUi(centralWidget);

  this->setCentralWidget(centralWidget);
  this->setWindowFlag(Qt::FramelessWindowHint);
}

NoteWidget::~NoteWidget() {
  delete ui;
}

void NoteWidget::mousePressEvent(QMouseEvent* event) {
  mPosition = event->pos();
  mDragging = true;
}

void NoteWidget::mouseReleaseEvent(QMouseEvent* event) {
  Q_UNUSED(event);
  mDragging = false;
}

void NoteWidget::mouseMoveEvent(QMouseEvent* event) {
  if (mDragging && event->buttons() && Qt::LeftButton) {
    auto diff = event->pos() - mPosition;
    this->move(this->pos() + diff);
  }
}
