#include "NoteTextEdit.h"

#include <QDebug>

NoteTextEdit::NoteTextEdit(QWidget* parent) : QPlainTextEdit(parent) {
  mChanged = false;
  connect(this, &NoteTextEdit::textChanged, this,
          &NoteTextEdit::handleTextChanged);
}

void NoteTextEdit::focusInEvent(QFocusEvent* event) {
  QPlainTextEdit::focusInEvent(event);
  emit receivedFocus();
}

void NoteTextEdit::focusOutEvent(QFocusEvent* event) {
  if (mChanged) {
    emit editingFinished();
    mChanged = false;
  }
  QPlainTextEdit::focusOutEvent(event);
}

void NoteTextEdit::handleTextChanged() {
  mChanged = true;
}
