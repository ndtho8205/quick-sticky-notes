#include "AppTrayIcon.h"

#include <QCoreApplication>
#include <QDebug>

#include "MainController.h"

AppTrayIcon::AppTrayIcon() {
  QIcon appIcon = QIcon(":/app/icon_app.png");
  mTrayIcon = new QSystemTrayIcon(appIcon);

  mContextMenu = new QMenu();

  mNewNoteAction = new QAction("&New note");
  mSettingsAction = new QAction("&Settings");
  mShowAllAction = new QAction("&Show all");
  mHideAllAction = new QAction("&Hide all");
  mAboutAction = new QAction("&About");
  mQuitAction = new QAction("&Quit");

  mContextMenu->addAction(mNewNoteAction);
  mContextMenu->addAction(mSettingsAction);
  mContextMenu->addSeparator();
  mContextMenu->addAction(mShowAllAction);
  mContextMenu->addAction(mHideAllAction);
  mContextMenu->addSeparator();
  mContextMenu->addAction(mAboutAction);
  mContextMenu->addSeparator();
  mContextMenu->addAction(mQuitAction);

  mTrayIcon->setContextMenu(mContextMenu);

  auto mainController = MainController::getInstance();
  QObject::connect(mNewNoteAction, &QAction::triggered, mainController,
                   &MainController::createNote);
  QObject::connect(mSettingsAction, &QAction::triggered, mainController,
                   &MainController::showSettingsDialog);
  QObject::connect(mShowAllAction, &QAction::triggered, mainController,
                   &MainController::showAllNote);
  QObject::connect(mHideAllAction, &QAction::triggered, mainController,
                   &MainController::hideAllNote);
  QObject::connect(mAboutAction, &QAction::triggered, mainController,
                   &MainController::showAboutDialog);
  QObject::connect(mQuitAction, &QAction::triggered, &QCoreApplication::quit);
}

AppTrayIcon::~AppTrayIcon() {
  delete mTrayIcon;
  delete mContextMenu;

  delete mNewNoteAction;
  delete mSettingsAction;
  delete mShowAllAction;
  delete mHideAllAction;
  delete mAboutAction;
  delete mQuitAction;
}

void AppTrayIcon::show() {
  qDebug() << "Tray icon available: " << mTrayIcon->isSystemTrayAvailable();

  mTrayIcon->setVisible(true);
  mTrayIcon->showMessage("Quick Sticky Notes", "Quick Sticky Notes is running.",
                         QSystemTrayIcon::Information, 1000);
}
