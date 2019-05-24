/********************************************************************************
** Form generated from reading UI file 'filelist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILELIST_H
#define UI_FILELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileList
{
public:

    void setupUi(QWidget *FileList)
    {
        if (FileList->objectName().isEmpty())
            FileList->setObjectName(QStringLiteral("FileList"));
        FileList->resize(652, 72);

        retranslateUi(FileList);

        QMetaObject::connectSlotsByName(FileList);
    } // setupUi

    void retranslateUi(QWidget *FileList)
    {
        FileList->setWindowTitle(QApplication::translate("FileList", "ProgressBar", 0));
    } // retranslateUi

};

namespace Ui {
    class FileList: public Ui_FileList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILELIST_H
