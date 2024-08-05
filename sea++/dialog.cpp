#include "dialog.h"
#include "ui_try.h"
#include "LanguageTerms.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>
#include <QMessageBox>
#include <QMovie>

#include <QString>
#include <QLabel>
#include <unordered_map>
#include <functional>
#include <QMediaPlayer>

const int NUM_BUTTONS = 30;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    points(0)
{
    ui->setupUi(this);

    scoreLabel = ui->scoreLabel;
    gameTitleLabel = ui->gameTitleLabel;  // Initialize the game title label
    langName = ui->langName;  // Initialize the instructions label
    backWidget = ui->backgroundWidget;
    startButton = ui->startButton;
	gifLabel = ui->gifLabel;

    backWidget->resize(746, 547);
    backWidget->setGeometry(0, 0, 746, 547);
    QLabel *backgroundLabel = new QLabel(backWidget);
    QMovie *movie = new QMovie("gif/water_pa.gif");
	QMovie *backmovie = new QMovie("gif/gifframe.gif");

	gifLabel->setMovie(backmovie);
	backmovie->start();
    backgroundLabel->setMovie(movie);
    movie->start();
    backgroundLabel->resize(746, 547);
    backgroundLabel->setGeometry(0, 0, 746, 547);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->show();
	qDebug() << startButton->styleSheet();
    initializeButtons();
    assignValuesToButtons();

    // Hide game elements initially
    for (QPushButton* button : buttons) {
        button->setVisible(false);
    }
    ui->rerollButton->setVisible(false);
    scoreLabel->setVisible(false);
    langName->setVisible(false);  // Hide instructions initially

    // Connect the start button to the slot
    connect(startButton, &QPushButton::clicked, this, &Dialog::onStartButtonClicked);
    for (QPushButton* button : buttons) {
        connect(button, &QPushButton::clicked, this, &Dialog::onButtonClicked);
    }
    connect(ui->rerollButton, &QPushButton::clicked, this, &Dialog::resetGame);

    updateScore();
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
    for (int i = 0; i < buttons.size(); ++i) {
        QPushButton* button = buttons[i];
        if (button == nullptr) {
            qDebug() << "Button is null!";
            continue;
        }
        which_list = distribution1(generator1);
        which_value = distribution2(generator2);
        QString value = AllTerms[which_list][which_value];
        buttonValues[button] = value;
        button->setText(value);
        qDebug() << "Button" << i << "assigned value:" << value;
    }
}

void Dialog::resetGame()
{
    qDebug() << "Resetting the game";

    points = 0;
    updateScore();

    for (QPushButton* button : buttons) {
        button->setStyleSheet("");
        button->setDisabled(false);
    }

    assignValuesToButtons();

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
    std::string valueStr = value.toStdString();
	QMediaPlayer *effect = new QMediaPlayer(this);
	QMediaPlayer *ceffect = new QMediaPlayer(this);

	ceffect->setMedia(QUrl("qrc:sound/gif/correct.mp3"));
	effect->setMedia(QUrl("qrc:sound/gif/buzzer.mp3"));
    if (correctValueTexts.contains(value)) {
        auto it = explanationMap.find(valueStr);
		ceffect->play();
        if (it != explanationMap.end()) {
            button->setToolTip(QString::fromStdString(it->second));
        } else {
            button->setToolTip("unknown value");
        }
        button->setStyleSheet("background-color: green; color: white;");
        button->setDisabled(true);
        points += 100;
        updateScore();
    } else {
		effect->play();
        button->setDisabled(true);
        points -= 50;
        updateScore();
        QTimer *timer = new QTimer(this);
        qDebug() << "Button text: " + button->text();
        button->setStyleSheet("background-color: red; color: black;");

        connect(timer, &QTimer::timeout, [this, button, timer]() {
            if (button) {
                assignNewValueToButton(button);
                qDebug() << "Button text: " + button->text();
                button->setStyleSheet("");
                updateScore();
                checkWinCondition();
                button->setDisabled(false);
            }
            timer->deleteLater();
        });

        timer->start(2000);
        return;
    }

    checkWinCondition();
}

void Dialog::onStartButtonClicked()
{
    // Hide the start button, game title, and show the game elements
    startButton->setVisible(false);
    gameTitleLabel->setVisible(false);
    langName->setVisible(true);  // Show instructions when the game starts

    for (QPushButton* button : buttons) {
        button->setVisible(true);
    }
    ui->rerollButton->setVisible(true);
    scoreLabel->setVisible(true);
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

        QPushButton *playAgainButton = winMsgBox.addButton("Play Again", QMessageBox::ActionRole);
        QPushButton *exitButton = winMsgBox.addButton("Quit", QMessageBox::RejectRole);

        connect(playAgainButton, &QPushButton::clicked, this, &Dialog::resetGame);
        connect(exitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

        winMsgBox.exec();
    }
}
