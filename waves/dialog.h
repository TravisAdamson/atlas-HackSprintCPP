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
    void resetButtons();
    void checkForMatch();

private:
    void assignValuesToButtons();
    void toggleButtonValue(QPushButton *button);
    void updateScore();

    Ui::Dialog *ui;
    QLabel *scoreLabel;  // Add this line to declare scoreLabel
    QPushButton *firstClickedButton;
    QPushButton *secondClickedButton;
    QMap<QPushButton*, int> buttonValues;
    QTimer *resetTimer;
    QList<QPushButton*> buttons;
    int points;
    bool canSelect;  // Add this line to declare the canSelect field
};

#endif // DIALOG_H
