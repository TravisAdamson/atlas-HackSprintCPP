#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QTimer>
#include <QLabel>
#include <QMap>          // Include QMap
#include <QStringList>  // Include QStringList
#include <QRandomGenerator> // Include QRandomGenerator for shuffling

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
    void resetGame();  // Declare the slot for resetting the game

private:
    void initializeButtons();
    void assignValuesToButtons();
    void handleButtonClick(QPushButton *button);
    void updateScore();
    void checkWinCondition();
    Ui::Dialog *ui;
    QList<QPushButton*> buttons;
    QMap<QPushButton*, QString> buttonValues;
    QLabel *scoreLabel;
    int points;
};

#endif // DIALOG_H
