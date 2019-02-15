#ifndef APPTRAYICON_H
#define APPTRAYICON_H

#include <QMenu>
#include <QSystemTrayIcon>

class AppTrayIcon {
 public:
  AppTrayIcon();
  ~AppTrayIcon();

  void show();

 private:
  QSystemTrayIcon* mTrayIcon;
  QMenu* mContextMenu;

  QAction* mNewNoteAction;
  QAction* mSettingsAction;
  QAction* mShowAllAction;
  QAction* mHideAllAction;
  QAction* mAboutAction;
  QAction* mQuitAction;
};

#endif  // APPTRAYICON_H
