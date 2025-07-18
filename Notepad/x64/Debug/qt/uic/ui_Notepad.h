/********************************************************************************
** Form generated from reading UI file 'Notepad.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotepadClass
{
public:
    QAction *actionPaste;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionRedo;
    QAction *actionUndo;
    QAction *actionAbout;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionSelectAll;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NotepadClass)
    {
        if (NotepadClass->objectName().isEmpty())
            NotepadClass->setObjectName("NotepadClass");
        NotepadClass->resize(617, 458);
        NotepadClass->setAnimated(true);
        NotepadClass->setTabShape(QTabWidget::TabShape::Rounded);
        actionPaste = new QAction(NotepadClass);
        actionPaste->setObjectName("actionPaste");
        actionNew = new QAction(NotepadClass);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(NotepadClass);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(NotepadClass);
        actionSave->setObjectName("actionSave");
        actionSaveAs = new QAction(NotepadClass);
        actionSaveAs->setObjectName("actionSaveAs");
        actionRedo = new QAction(NotepadClass);
        actionRedo->setObjectName("actionRedo");
        actionUndo = new QAction(NotepadClass);
        actionUndo->setObjectName("actionUndo");
        actionAbout = new QAction(NotepadClass);
        actionAbout->setObjectName("actionAbout");
        actionCopy = new QAction(NotepadClass);
        actionCopy->setObjectName("actionCopy");
        actionCut = new QAction(NotepadClass);
        actionCut->setObjectName("actionCut");
        actionSelectAll = new QAction(NotepadClass);
        actionSelectAll->setObjectName("actionSelectAll");
        centralWidget = new QWidget(NotepadClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8("menu\n"
"{\n"
"	menu-position:below-parent;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        NotepadClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NotepadClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 617, 33));
        menuBar->setDefaultUp(true);
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName("menu_3");
        NotepadClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(NotepadClass);
        statusBar->setObjectName("statusBar");
        NotepadClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addSeparator();
        menu->addSeparator();
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(actionSaveAs);
        menu->addSeparator();
        menu_2->addAction(actionCopy);
        menu_2->addAction(actionPaste);
        menu_2->addAction(actionCut);
        menu_2->addAction(actionSelectAll);
        menu_2->addAction(actionRedo);
        menu_2->addAction(actionUndo);
        menu_3->addAction(actionAbout);

        retranslateUi(NotepadClass);

        QMetaObject::connectSlotsByName(NotepadClass);
    } // setupUi

    void retranslateUi(QMainWindow *NotepadClass)
    {
        NotepadClass->setWindowTitle(QCoreApplication::translate("NotepadClass", "Notepad", nullptr));
        actionPaste->setText(QCoreApplication::translate("NotepadClass", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("NotepadClass", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("NotepadClass", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("NotepadClass", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("NotepadClass", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(shortcut)
        actionSaveAs->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("NotepadClass", "\351\207\215\345\201\232", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("NotepadClass", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("NotepadClass", "\345\205\263\344\272\216\346\234\254\347\250\213\345\272\217", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("NotepadClass", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("NotepadClass", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelectAll->setText(QCoreApplication::translate("NotepadClass", "\345\205\250\351\200\211", nullptr));
#if QT_CONFIG(shortcut)
        actionSelectAll->setShortcut(QCoreApplication::translate("NotepadClass", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("NotepadClass", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("NotepadClass", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("NotepadClass", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotepadClass: public Ui_NotepadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
