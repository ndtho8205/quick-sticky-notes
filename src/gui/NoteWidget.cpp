#include "NoteWidget.h"
#include "ui_NoteWidget.h"

#include <QDebug>
#include <QMenu>
#include <QSizeGrip>
#include <QSizePolicy>

#include "MainController.h"

NoteWidget::NoteWidget(Note* note, QWidget* parent)
    : QWidget(parent), ui(new Ui::NoteWidget) {
  ui->setupUi(this);

  mSizeGrip = new QSizeGrip(this);
  //  mSizeGrip->setStyleSheet("image: none;");
  ui->layoutBottom->addWidget(mSizeGrip, 0, Qt::AlignBottom | Qt::AlignRight);

  setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);

  connect(ui->btnActionAdd, SIGNAL(clicked()), this, SLOT(addNoteWidget()));
  connect(ui->btnActionLock, SIGNAL(clicked()), this,
          SLOT(switchLockStatusNoteWidget()));
  connect(ui->btnActionExpandMenu, SIGNAL(clicked()), this,
          SLOT(expandMenuNoteWidget()));
  connect(ui->btnActionDelete, SIGNAL(clicked()), this,
          SLOT(deleteNoteWidget()));

  mNote = note;
}

NoteWidget::~NoteWidget() {
  delete ui;
}

void NoteWidget::mousePressEvent(QMouseEvent* event) {
  if (!mNote->isLock()) {
    mPosition = event->pos();
    mDragging = true;
  }
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

void NoteWidget::lock() {
  ui->btnActionLock->setIcon(QIcon(":/note/icon_lock"));
  mNote->setLockStatus(true);
  mSizeGrip->setEnabled(false);
}

void NoteWidget::unlock() {
  ui->btnActionLock->setIcon(QIcon(":/note/icon_lock_open"));
  mNote->setLockStatus(false);
  mSizeGrip->setEnabled(true);
}

//-------------------------------------------------------------------------------------------------
// slots
//-------------------------------------------------------------------------------------------------

void NoteWidget::addNoteWidget() {
  qDebug() << __func__;
  MainController::instance()->addNewNote();
}

void NoteWidget::switchLockStatusNoteWidget() {
  qDebug() << __func__;
  if (mNote->isLock()) {
    unlock();
  } else {
    lock();
  }
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
