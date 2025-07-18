#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QCoreApplication>
#include "ui_Notepad.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NotepadClass; };
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void onActionPasteTriggered();
    void onActionOpenTriggered();
    void onActionSaveTriggered();
    void onActionNewTriggered();
    void onActionSaveAsTriggered();
    void onActionRedoTriggered();
    void onActionUndoTriggered();
    void onActionAboutTriggered();
    void onActionCopyTriggered();
    void onActionCutTriggered();
    void onActionSelectAllTriggered();

    void onEdited();
private:
    QString fileSavePath;
    QString defaultFileName;
    quint64 count;
    QString defaultFilePath;

    bool saved;
    Ui::NotepadClass *ui;
};

