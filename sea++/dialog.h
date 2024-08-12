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
#include <QMediaPlayer>
#include <QLCDNumber>

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
    void updateMarquee(); // Slot for updating marquee

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
	QLabel *gifLabel;
    QLabel *gifLabel2;
    QWidget *backWidget;
	QLCDNumber *lcdScore = new QLCDNumber;
    QPushButton *startButton;
	QMediaPlayer *effect = new QMediaPlayer(this);
	QMediaPlayer *ceffect = new QMediaPlayer(this);
	int points;
    bool messageBoxOpen;

    QLabel *marqueeLabel2; // Marquee label
    QTimer *marqueeTimer; // Timer for marquee
    int marqueePosition2;  // Position of the marquee text
};

#endif // DIALOG_H
