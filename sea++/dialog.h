#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QTimer>
#include <QLabel>
#include <QMap>
#include <QStringList>
#include <QRandomGenerator>
#include <QWidget>

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
    void resetGame();
    void onStartButtonClicked();

private:
    void initializeButtons();
    void assignValuesToButtons();
    void assignNewValueToButton(QPushButton *button);
    void handleButtonClick(QPushButton *button);
    void updateScore();
    void checkWinCondition();

    Ui::Dialog *ui;
    QList<QPushButton*> buttons;
    QMap<QPushButton*, QString> buttonValues;
    QLabel *scoreLabel;
    QLabel *gameTitleLabel;  // Add this member
    QLabel *langName;  // Add this member for instructions
    QWidget *backWidget;
    QPushButton *startButton;
    int points;
};

#endif // DIALOG_H
