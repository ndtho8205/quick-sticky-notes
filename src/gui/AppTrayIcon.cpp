#include "AppTrayIcon.h"

#include <QCoreApplication>
#include <QDebug>

#include "MainController.h"

AppTrayIcon::AppTrayIcon() {
  QIcon appIcon = QIcon(":/app/icon_app.png");
  mTrayIcon = new QSystemTrayIcon(appIcon);

  mContextMenu = new QMenu();

  QAction* newNoteAction = new QAction("&New note");
  QAction* settingsAction = new QAction("&Settings");
  QAction* showAllAction = new QAction("&Show all");
  QAction* hideAllAction = new QAction("&Hide all");
  QAction* aboutAction = new QAction("&About");
  QAction* quitAction = new QAction("&Quit");

  mContextMenu->addAction(newNoteAction);
  mContextMenu->addAction(settingsAction);
  mContextMenu->addSeparator();
  mContextMenu->addAction(showAllAction);
  mContextMenu->addAction(hideAllAction);
  mContextMenu->addSeparator();
  mContextMenu->addAction(aboutAction);
  mContextMenu->addSeparator();
  mContextMenu->addAction(quitAction);

  mTrayIcon->setContextMenu(mContextMenu);

  auto mainController = MainController::instance();
  QObject::connect(newNoteAction, &QAction::triggered, mainController,
                   &MainController::addNewNote);
  QObject::connect(settingsAction, &QAction::triggered, mainController,
                   &MainController::showSettingsDialog);
  QObject::connect(showAllAction, &QAction::triggered, mainController,
                   &MainController::showAllNote);
  QObject::connect(hideAllAction, &QAction::triggered, mainController,
                   &MainController::hideAllNote);
  QObject::connect(aboutAction, &QAction::triggered, mainController,
                   &MainController::showAboutDialog);
  QObject::connect(quitAction, &QAction::triggered, &QCoreApplication::quit);
}

void AppTrayIcon::show() {
  qDebug() << "Tray icon abailable: " << mTrayIcon->isSystemTrayAvailable();

  mTrayIcon->setVisible(true);
  mTrayIcon->showMessage("Quick Sticky Notes", "Quick Sticky Notes is running.",
                         QSystemTrayIcon::Information, 1000);
}
