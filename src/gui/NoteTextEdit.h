#ifndef NOTETEXTEDIT_H
#define NOTETEXTEDIT_H

#include <QPlainTextEdit>

class NoteTextEdit : public QPlainTextEdit {
  Q_OBJECT
 public:
  explicit NoteTextEdit(QWidget* parent = nullptr);

  void focusInEvent(QFocusEvent* event);
  void focusOutEvent(QFocusEvent* event);

 signals:
  bool editingFinished();
  bool receivedFocus();

 private slots:
  void handleTextChanged();

 private:
  bool mChanged;
};

#endif  // NOTETEXTEDIT_H
