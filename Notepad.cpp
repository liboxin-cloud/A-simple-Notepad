#include "Notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotepadClass())
{
    ui->setupUi(this);
    // �����ļ��˵�����
    connect(ui->actionNew, &QAction::triggered, this, &Notepad::onActionNewTriggered);
    connect(ui->actionOpen, &QAction::triggered, this, &Notepad::onActionOpenTriggered);
    connect(ui->actionSave, &QAction::triggered, this, &Notepad::onActionSaveTriggered);
    connect(ui->actionSaveAs, &QAction::triggered, this, &Notepad::onActionSaveAsTriggered);

    // ���ӱ༭�˵�����
    connect(ui->actionPaste, &QAction::triggered, this, &Notepad::onActionPasteTriggered);
    connect(ui->actionUndo, &QAction::triggered, this, &Notepad::onActionUndoTriggered);
    connect(ui->actionRedo, &QAction::triggered, this, &Notepad::onActionRedoTriggered);
    connect(ui->actionCopy, &QAction::triggered, this, &Notepad::onActionCopyTriggered);
    connect(ui->actionCut, &QAction::triggered, this, &Notepad::onActionCutTriggered);
    connect(ui->actionSelectAll, &QAction::triggered, this, &Notepad::onActionSelectAllTriggered);



    //���ӹ��ڲ˵��Ķ���
    connect(ui->actionAbout, &QAction::triggered, this, &Notepad::onActionAboutTriggered);

    // �����ı��༭�ź�
    connect(ui->textEdit, &QTextEdit::textChanged, this, &Notepad::onEdited);
    this->saved = false;
    this->count = 1;
    this->defaultFileName = "untitled" + QString::number(count);

    //�༭�ı�����ʽ��
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
    //����ļ���·��Ϊ�յĻ��� ˵���û�û�н���ѡ��

    if (file_path.isEmpty())
    {
        return;
    }

    //���ļ����Ҷ�ȡ����txt����
    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //�����ʧ�ܣ���ʾ����
        QMessageBox::information(this, "notice", "can not open the target file, please retry");
        return;
    }

    //��ʼ��ȡѡ�е��ļ�����
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

        //���ļ�����д��

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
    //����ļ���·��Ϊ�յĻ��� ˵���û�û�н���ѡ��
    qDebug() << file_path;
    if (file_path.isEmpty())
    {
        return;
    }

    if (!file_path.endsWith(".txt", Qt::CaseInsensitive))
    {
        file_path += ".txt";

    }

    //���༭���е��ı���ȡ����
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


