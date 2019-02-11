#include "NoteWidget.h"
#include "ui_NoteWidget.h"

#include <QDebug>
#include <QMenu>
#include "MainController.h"

NoteWidget::NoteWidget(Note* note, QWidget* parent)
    : QWidget(parent, Qt::Dialog), ui(new Ui::NoteWidget) {
  ui->setupUi(this);
  this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);

  connect(ui->btnActionAdd, SIGNAL(clicked()), this, SLOT(addNoteWidget()));
  connect(ui->btnActionLock, SIGNAL(clicked()), this, SLOT(lockNoteWidget()));
  connect(ui->btnActionMore, SIGNAL(clicked()), this,
          SLOT(expandMenuNoteWidget()));
  connect(ui->btnActionDelete, SIGNAL(clicked()), this,
          SLOT(deleteNoteWidget()));

  mNote = note;
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

//-------------------------------------------------------------------------------------------------
// slots
//-------------------------------------------------------------------------------------------------

void NoteWidget::addNoteWidget() {
  qDebug() << __func__;
  MainController::instance()->addNote();
}

void NoteWidget::lockNoteWidget() {
  qDebug() << __func__;
}

void NoteWidget::expandMenuNoteWidget() {
  qDebug() << __func__;
}

void NoteWidget::openSettingsDialog() {
  qDebug() << __func__;
}

void NoteWidget::deleteNoteWidget() {
  qDebug() << __func__;
  MainController::instance()->deleteNote();
}
