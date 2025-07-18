#include "Notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotepadClass())
{
    ui->setupUi(this);
    // 连接文件菜单动作
    connect(ui->actionNew, &QAction::triggered, this, &Notepad::onActionNewTriggered);
    connect(ui->actionOpen, &QAction::triggered, this, &Notepad::onActionOpenTriggered);
    connect(ui->actionSave, &QAction::triggered, this, &Notepad::onActionSaveTriggered);
    connect(ui->actionSaveAs, &QAction::triggered, this, &Notepad::onActionSaveAsTriggered);

    // 连接编辑菜单动作
    connect(ui->actionPaste, &QAction::triggered, this, &Notepad::onActionPasteTriggered);
    connect(ui->actionUndo, &QAction::triggered, this, &Notepad::onActionUndoTriggered);
    connect(ui->actionRedo, &QAction::triggered, this, &Notepad::onActionRedoTriggered);
    connect(ui->actionCopy, &QAction::triggered, this, &Notepad::onActionCopyTriggered);
    connect(ui->actionCut, &QAction::triggered, this, &Notepad::onActionCutTriggered);
    connect(ui->actionSelectAll, &QAction::triggered, this, &Notepad::onActionSelectAllTriggered);



    //连接关于菜单的动作
    connect(ui->actionAbout, &QAction::triggered, this, &Notepad::onActionAboutTriggered);

    // 连接文本编辑信号
    connect(ui->textEdit, &QTextEdit::textChanged, this, &Notepad::onEdited);
    this->saved = false;
    this->count = 1;
    this->defaultFileName = "untitled" + QString::number(count);

    //编辑文本框样式表
    ui->textEdit->setStyleSheet("border:none;");


    this->defaultFilePath = QCoreApplication::applicationDirPath();
    defaultFilePath += "/";
    defaultFilePath += defaultFileName;
    defaultFilePath += ".txt";
    setWindowTitle(defaultFileName + "*");

}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::onActionPasteTriggered()
{
    qDebug() << __FUNCTION__ << "is triggered";
}

void Notepad::onActionOpenTriggered()
{
    qDebug() << __FUNCTION__ << "is triggered";
    QString file_path = QFileDialog::getOpenFileName(
        this,
        "choose the target file",
        QCoreApplication::applicationDirPath(),
        "txt file(*.txt);;All files(*)"
    );
    //如果文件的路径为空的话， 说明用户没有进行选择

    if (file_path.isEmpty())
    {
        return;
    }

    //打开文件并且读取其中txt内容
    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //如果打开失败，提示错误
        QMessageBox::information(this, "notice", "can not open the target file, please retry");
        return;
    }

    //开始读取选中的文件内容
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    ui->textEdit->setPlainText(text);

    QFileInfo fileInfo(file_path);
    this->defaultFilePath = file_path;
    this->defaultFileName = fileInfo.fileName();
    this->saved = true;

    setWindowTitle(defaultFileName);
}

void Notepad::onActionSaveTriggered()
{
    qDebug() << __FUNCTION__ << "is triggered";
    if (this->saved == true)
    {
        return;
    }
    else
    {

        qDebug() << "current file dir path is " << defaultFilePath;
        if (!defaultFilePath.endsWith(".txt", Qt::CaseInsensitive))
        {
            defaultFilePath += ".txt";
        }
        QString text = ui->textEdit->toPlainText();

        //打开文件进行写入

        QFile file(defaultFilePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << text;
            file.close();
            QMessageBox::information(this, "notice", "file saved success", QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(this, "notice", "file saved failed", QMessageBox::Ok);
            return;
        }

        this->defaultFileName.chopped(1);
        this->saved = true;
        setWindowTitle(defaultFileName);
    }
}

void Notepad::onActionNewTriggered()
{
    ui->textEdit->clear();

    this->saved = false;
    this->count++;
    this->defaultFileName.clear();
    this->defaultFileName = "untitled" + QString::number(count);
    this->defaultFilePath = QCoreApplication::applicationDirPath();
    defaultFilePath += "/";
    defaultFilePath += defaultFileName;
    defaultFilePath += ".txt";
    setWindowTitle(defaultFileName + "*");


    qDebug() << __FUNCTION__ << "is triggered";
}

void Notepad::onActionSaveAsTriggered()
{
    qDebug() << __FUNCTION__ << "is triggered";
    QString file_path = QFileDialog::getSaveFileName(
        this,
        "choose the target file",
        QCoreApplication::applicationDirPath(),
        "txt file(*.txt);;All files(*)"
    );
    //如果文件的路径为空的话， 说明用户没有进行选择
    qDebug() << file_path;
    if (file_path.isEmpty())
    {
        return;
    }

    if (!file_path.endsWith(".txt", Qt::CaseInsensitive))
    {
        file_path += ".txt";

    }

    //将编辑框中的文本读取出来
    QString text = ui->textEdit->toPlainText();

    QFile file(file_path);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << text;
        file.close();
        QMessageBox::information(this, "notice", "file saved success", QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "notice", "file saved failed", QMessageBox::Ok);
        return;
    }

    QFileInfo fileInfo(file_path);

    this->saved = true;
    this->defaultFileName = fileInfo.fileName();
    this->defaultFilePath = file_path;

    setWindowTitle(defaultFileName);
}

void Notepad::onActionRedoTriggered()
{
    qDebug() << __FUNCTION__ << "is triggered";
    if (ui->textEdit->document()->isRedoAvailable())
    {
        ui->textEdit->redo();
    }
}

void Notepad::onActionUndoTriggered()
{
    qDebug() << __FUNCTION__ << "is triggered";
    if (ui->textEdit->document()->isUndoAvailable())
    {
        ui->textEdit->undo();
    }
}

void Notepad::onActionAboutTriggered()
{

    qDebug() << __FUNCTION__ << "is triggered";
    QString copyrightText =
        "Copyright (C) [lbx] " + QString::number(QDate::currentDate().year()) + ".\n"
        "All rights reserved.\n\n"
        "This software is protected by copyright laws and international treaties.\n"
        "Unauthorized reproduction or distribution of this software, or any portion of it,\n"
        "may result in severe civil and criminal penalties, and will be prosecuted to the\n"
        "maximum extent permitted by law.\n"
        "if you have any questions or advice, please contact the author at 3551839250@qq.com";

    QMessageBox::information(this, "Copyright Notice", copyrightText);


}

void Notepad::onActionCopyTriggered()
{
    qDebug() << __FUNCTION__ << "is triggered";
    ui->textEdit->copy();


}

void Notepad::onActionCutTriggered()
{
    qDebug() << __FUNCTION__ << "is triggered";
    ui->textEdit->cut();

}

void Notepad::onActionSelectAllTriggered()
{
    qDebug() << __FUNCTION__ << "is triggered";
    ui->textEdit->selectAll();
}

void Notepad::onEdited()
{
    if (this->saved)
    {
        setWindowTitle(defaultFileName + "*");
        this->saved = false;
        defaultFileName.chopped(1);
    }
    
    qDebug() << __FUNCTION__ << "is triggered";
}


