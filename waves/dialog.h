#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_try.h"  // This should be the header file generated from try.ui

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    void toggleButtonText(QPushButton *button);

    Ui::Dialog *ui;  // Pointer to the UI class
};

#endif // DIALOG_H
