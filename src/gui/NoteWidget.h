#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QSizeGrip>
#include <QWidget>

#include "Note.h"

namespace Ui {
class NoteWidget;
}

class NoteWidget : public QWidget {
  Q_OBJECT

 public:
  explicit NoteWidget(Note* note = new Note(), QWidget* parent = nullptr);
  ~NoteWidget();

  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent* event);

  void lock();
  void unlock();

 private slots:
  void addNoteWidget();
  void switchLockStatusNoteWidget();
  void expandMenuNoteWidget();
  void openSettingsDialog();
  void deleteNoteWidget();

 private:
  Ui::NoteWidget* ui;
  QSizeGrip* mSizeGrip;

  Note* mNote;
  QPoint mPosition;
  bool mDragging;
};

#endif  // NOTEWIDGET_H
