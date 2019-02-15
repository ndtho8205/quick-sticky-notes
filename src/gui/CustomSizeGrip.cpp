#include "CustomSizeGrip.h"

#include <QDebug>
#include <QMouseEvent>

CustomSizeGrip::CustomSizeGrip(QWidget* parent) : QSizeGrip(parent) {}

void CustomSizeGrip::mouseReleaseEvent(QMouseEvent* event) {
  QSizeGrip::mouseReleaseEvent(event);
  if (event->button() == Qt::LeftButton) {
    emit resized();
  }
}
