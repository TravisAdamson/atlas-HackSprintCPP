#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QMap>
#include <QTimer>
#include <QLabel> // Include QLabel for scoreLabel

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void onButtonClicked();
    void updateScore();
    void disableRandomButton();
    void checkWinCondition();
    void checkLoseCondition();

private:
    void assignValuesToButtons();
    void handleButtonClick(QPushButton *button);
    void initializeButtons();
    void setupTimers();

    Ui::Dialog *ui;
    QLabel *scoreLabel;  // Score label
    QMap<QPushButton*, QString> buttonValues; // Map to store button texts
    QList<QPushButton*> buttons;  // List of buttons
    QTimer *disableButtonTimer; // Timer to disable random button
    int points;
};

#endif // DIALOG_H
