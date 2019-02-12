#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QMenu>

#include "AppTrayIcon.h"
#include "MainController.h"
#include "NoteWidget.h"

void setupTrayIcon();

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  AppTrayIcon* appTrayIcon = new AppTrayIcon();
  appTrayIcon->show();

  MainController::instance()->addNewNote();

  return a.exec();
}
