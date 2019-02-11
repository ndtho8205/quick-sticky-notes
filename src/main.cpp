#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QMenu>
#include <QSystemTrayIcon>
#include "MainController.h"
#include "NoteWidget.h"

void setupTrayIcon();

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  setupTrayIcon();

  MainController::instance()->addNote();

  return a.exec();
}

void setupTrayIcon() {
  auto menu = new QMenu();
  auto quitAction = new QAction("&Quit");
  QObject::connect(quitAction, &QAction::triggered, qApp,
                   &QCoreApplication::quit);
  menu->addAction(quitAction);

  auto appIcon = QIcon(":/app/icon_app.png");
  QSystemTrayIcon* trayIcon = new QSystemTrayIcon();
  trayIcon->setIcon(appIcon);
  trayIcon->setContextMenu(menu);

  qDebug() << trayIcon->isSystemTrayAvailable();

  trayIcon->setVisible(true);
  trayIcon->showMessage("Test Message", "Text", appIcon, 1000);
}
