#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QHash>
#include <QObject>

#include "LocalDataManager.h"
#include "Note.h"
#include "NoteWidget.h"
#include "SettingsDialog.h"

class MainController : public QObject {
  Q_OBJECT

 public:
  static MainController* getInstance();

  void run();

 public slots:
  void createNote();
  void showNote(Note* note = nullptr);

  void updateNote(Note* note);

  void deleteNote(QString noteId);

  void showAllNote();
  void hideAllNote();

  void showAboutDialog();
  void showSettingsDialog();

 private slots:
  void settingsDialogIsFinished(int result);

 private:
  MainController();
  ~MainController();

  LocalDataManager* mDataManager;
  QHash<QString, NoteWidget*> mNoteWidgetMap;
  SettingsDialog* mSettingsDialog;

  static MainController* mInstance;
};

#endif  // MAINCONTROLLER_H
