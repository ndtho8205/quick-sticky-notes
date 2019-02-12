#ifndef APPTRAYICON_H
#define APPTRAYICON_H

#include <QMenu>
#include <QSystemTrayIcon>

class AppTrayIcon {
 public:
  AppTrayIcon();

  void show();

 private:
  QSystemTrayIcon* mTrayIcon;
  QMenu* mContextMenu;
};

#endif  // APPTRAYICON_H
