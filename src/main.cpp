#include <QApplication>
#include "NoteWidget.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  NoteWidget w;
  w.show();

  return a.exec();
}
