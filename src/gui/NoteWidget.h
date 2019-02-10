#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QMainWindow>

namespace Ui {
class NoteWidget;
}

class NoteWidget : public QMainWindow {
  Q_OBJECT

 public:
  explicit NoteWidget(QWidget* parent = nullptr);
  ~NoteWidget();

  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent* event);

 private:
  Ui::NoteWidget* ui;

  QPoint mPosition;
  bool mDragging;
};

#endif  // NOTEWIDGET_H
