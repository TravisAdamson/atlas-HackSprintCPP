#include "dialog.h"
#include "ui_try.h"
#include "LanguageTerms.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>
#include <QMessageBox>

const int NUM_BUTTONS = 30;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    points(0)
{
    ui->setupUi(this);

	scoreLabel = ui->scoreLabel;

    initializeButtons();
    assignValuesToButtons();

    for (QPushButton* button : buttons) {
        connect(button, &QPushButton::clicked, this, &Dialog::onButtonClicked);
    }

    updateScore();

    // Connect the reset button
    connect(ui->rerollButton, &QPushButton::clicked, this, &Dialog::resetGame);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::initializeButtons()
{
    buttons = {
        ui->pushButton_1, ui->pushButton_2, ui->pushButton_3, ui->pushButton_4,
        ui->pushButton_5, ui->pushButton_6, ui->pushButton_7, ui->pushButton_8,
        ui->pushButton_9, ui->pushButton_10, ui->pushButton_11, ui->pushButton_12,
        ui->pushButton_13, ui->pushButton_14, ui->pushButton_15, ui->pushButton_16,
        ui->pushButton_17, ui->pushButton_18, ui->pushButton_19, ui->pushButton_20,
        ui->pushButton_21, ui->pushButton_22, ui->pushButton_23, ui->pushButton_24,
        ui->pushButton_25, ui->pushButton_26, ui->pushButton_27, ui->pushButton_28,
        ui->pushButton_29, ui->pushButton_30
    };

    if (buttons.size() != NUM_BUTTONS) {
        qDebug() << "Error: Number of buttons does not match NUM_BUTTONS!";
    }
}

void Dialog::assignNewValueToButton(QPushButton *button)
{
	std::random_device rd;
	std::mt19937 generator1(rd());
	std::mt19937 generator2(rd());
	std::uniform_int_distribution<int> distribution1(0,11);
	std::uniform_int_distribution<int> distribution2(0,41);
	int which_list = distribution1(generator1);
	int which_value = distribution2(generator2);
	QString value = AllTerms[which_list][which_value];
	buttonValues[button] = value;
	button->setText(value);
}

void Dialog::assignValuesToButtons()
{
	std::random_device rd;
	std::mt19937 generator1(rd());
	std::mt19937 generator2(rd());
	std::uniform_int_distribution<int> distribution1(0, 11);
	std::uniform_int_distribution<int> distribution2(0, 41);
	int which_list = distribution1(generator1);
	int which_value = distribution2(generator2);

	correctValueTexts = AllTerms[which_list];
	QString value = Titles[which_list];
	QString puzzleText = "Find the terms related to " + Titles[which_list];
    ui->langName->setText(puzzleText);
    // Assign random values to buttons
    for (int i = 0; i < buttons.size(); ++i) {
        QPushButton* button = buttons[i];
        if (button == nullptr) {
            qDebug() << "Button is null!";
            continue;
        }
		which_list = distribution1(generator1);
		which_value = distribution2(generator2);
        QString value = AllTerms[which_list][which_value];
        buttonValues[button] = value;  // Update internal value map
        button->setText(value);        // Update button text


        // Debugging output
        qDebug() << "Button" << i << "assigned value:" << value;
    }
}

void Dialog::resetGame()
{
    qDebug() << "Resetting the game"; // Debugging output

    // Reset the score
    points = 0;
    updateScore();

    // Reset all button styles and enable them
    for (QPushButton* button : buttons) {
        button->setStyleSheet("");  // Clear any existing styles
        button->setDisabled(false); // Re-enable the button
    }

    // Shuffle and assign new values to buttons
    assignValuesToButtons();

    // Debug output to confirm new values
    for (QPushButton* button : buttons) {
        qDebug() << "Button text after reset:" << button->text();
    }
}

void Dialog::onButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        handleButtonClick(button);
    }
}

void Dialog::handleButtonClick(QPushButton *button)
{
    QString value = buttonValues[button];

    if (correctValueTexts.contains(value)) {
        button->setStyleSheet("background-color: green; color: white;"); // Assuming white text on green is readable
        button->setDisabled(true);
        points += 100;
		updateScore();
    } else {
		button->setDisabled(true);
		points -= 50;
		updateScore();
        QTimer *timer = new QTimer(this); // `this` is the parent QObject
		qDebug() << "Button text: " + button->text();
		button->setStyleSheet("background-color: red; color: black;");
        connect(timer, &QTimer::timeout, [this, button, timer]() {
            // Ensure the button is still valid before using it
            if (button) {
				assignNewValueToButton(button);
				qDebug() << "Button text: " + button->text();
                button->setStyleSheet(""); // Reset to default or appropriate style
                updateScore();
                checkWinCondition();
				button->setDisabled(false);
            }
            // Delete the timer once it’s done to avoid memory leaks
            timer->deleteLater();
		});
		// Start the timer with a 5000 ms (5 seconds) interval
		timer->start(2000);

		return;

    }

    checkWinCondition();
}


void Dialog::updateScore()
{
	if (points < 0)
		points = 0;
    if (scoreLabel)
        scoreLabel->setText("Score: " + QString::number(points));
}

void Dialog::checkWinCondition()
{
    bool allCorrectButtonsGreenOrBlue = true;

    for (QPushButton* button : buttons) {
        QString style = button->styleSheet();
        QString text = button->text();

        if (correctValueTexts.contains(text)) {
            if (!(style.contains("background-color: green;"))) {
                allCorrectButtonsGreenOrBlue = false;
                break;
            }
        }
    }

    if (allCorrectButtonsGreenOrBlue) {
        QString winMessage = QString("Your score is: %1").arg(points);

        QMessageBox winMsgBox(this);
        winMsgBox.setText(winMessage);
        winMsgBox.setWindowTitle("Congratulations!");

        // Add custom buttons
        QPushButton *playAgainButton = winMsgBox.addButton("Play Again", QMessageBox::ActionRole);
        QPushButton *exitButton = winMsgBox.addButton("Quit", QMessageBox::RejectRole);

        // Connect the buttons to slots
        connect(playAgainButton, &QPushButton::clicked, this, &Dialog::resetGame);
        connect(exitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

        winMsgBox.exec();
    }
}
