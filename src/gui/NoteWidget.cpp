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

  connect(ui->btnActionAdd, SIGNAL(clicked()), this, SLOT(createNoteWidget()));
  connect(ui->btnActionLock, SIGNAL(clicked()), this,
          SLOT(switchLockStatusNoteWidget()));
  connect(ui->btnActionExpandMenu, SIGNAL(clicked()), this,
          SLOT(expandMenuNoteWidget()));
  connect(ui->btnActionDelete, SIGNAL(clicked()), this,
          SLOT(deleteNoteWidget()));
  connect(ui->txtContent, &NoteTextEdit::editingFinished, this,
          &NoteWidget::updateNoteContent);

  mNote = note;

  this->move(mNote->properties()->position());
  if (mNote->properties()->locked()) {
    lock();
  }
  this->resize(mNote->properties()->size());
  ui->txtContent->setPlainText(mNote->content());
}

NoteWidget::~NoteWidget() {
  delete ui;
}

void NoteWidget::mousePressEvent(QMouseEvent* event) {
  if (!mNote->properties()->locked()) {
    mPosition = event->pos();
    mDragging = true;
  }
}

void NoteWidget::mouseReleaseEvent(QMouseEvent* event) {
  Q_UNUSED(event);
  if (mDragging) {
    mNote->properties()->setPosition(this->pos());
    MainController::getInstance()->updateNote(mNote);
  }
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

void NoteWidget::createNoteWidget() {
  MainController::getInstance()->createNote();
}

void NoteWidget::switchLockStatusNoteWidget() {
  if (mNote->properties()->locked()) {
    unlock();
  } else {
    lock();
  }
}

void NoteWidget::expandMenuNoteWidget() {
  qDebug() << __PRETTY_FUNCTION__;
}

void NoteWidget::openSettingsDialog() {
  qDebug() << __PRETTY_FUNCTION__;
}

void NoteWidget::deleteNoteWidget() {
  close();
  deleteLater();
  MainController::getInstance()->deleteNote(mNote->id());
}

//-------------------------------------------------------------------------------------------------
// slots
//-------------------------------------------------------------------------------------------------

void NoteWidget::lock() {
  ui->btnActionLock->setIcon(QIcon(":/note/icon_lock"));
  mNote->properties()->lock();
  mSizeGrip->setEnabled(false);

  MainController::getInstance()->updateNote(mNote);
}

void NoteWidget::unlock() {
  ui->btnActionLock->setIcon(QIcon(":/note/icon_lock_open"));
  mNote->properties()->unlock();
  mSizeGrip->setEnabled(true);

  MainController::getInstance()->updateNote(mNote);
}

void NoteWidget::updateNoteContent() {
  mNote->setContent(ui->txtContent->toPlainText());
  MainController::getInstance()->updateNote(mNote);
}
