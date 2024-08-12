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
    points(0),
    messageBoxOpen(false),
    marqueePosition2(0)
{
    ui->setupUi(this);
	lcdScore = ui->lcdNumber;
	lcdScore->setVisible(false);
    gameTitleLabel = ui->gameTitleLabel;  // Initialize the game title label
    langName = ui->langName;  // Initialize the instructions label
    backWidget = ui->backgroundWidget;
    startButton = ui->startButton;
	gifLabel = ui->gifLabel;
    gifLabel2 = ui->gifLabel2;
	gifLabel2->setVisible(false);

    backWidget->resize(800, 600);
    backWidget->setGeometry(0, 0, 800, 600);
    QLabel *backgroundLabel = new QLabel(backWidget);
    QMovie *movie = new QMovie("gif/water_pa.gif");
	QMovie *movie1 = new QMovie("gif/cratego.gif"); // For gifLabel
    gifLabel->setMovie(movie1);
    movie1->start();

    QMovie *movie2 = new QMovie("gif/raft3extendedallframes.gif"); // For gifLabel2
    gifLabel2->setMovie(movie2);
    backgroundLabel->setMovie(movie);
    movie2->start();
    movie->start();
    backgroundLabel->resize(800, 600);
    backgroundLabel->setGeometry(0, 0, 800, 600);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->show();
    initializeButtons();
    assignValuesToButtons();

    // Hide game elements initially
    for (QPushButton* button : buttons) {
        button->setVisible(false);
    }
    ui->rerollButton->setVisible(false);
    langName->setVisible(false);  // Hide instructions initially

    // Connect the start button to the slot
    connect(startButton, &QPushButton::clicked, this, &Dialog::onStartButtonClicked);
    for (QPushButton* button : buttons) {
        connect(button, &QPushButton::clicked, this, &Dialog::onButtonClicked);
    }
    connect(ui->rerollButton, &QPushButton::clicked, this, &Dialog::resetGame);

    updateScore();

    // Initialize the second marquee
    marqueeLabel2 = new QLabel("Developed by: Matt Ernst, Nolan Heald, & Travis Adamson", this);
    marqueeLabel2->setGeometry(0, 540, 800, 30);
    marqueeLabel2->setAlignment(Qt::AlignLeft);  // Align text to left to start scrolling from right
    marqueeLabel2->setStyleSheet("background-color: transparent; color: white; font-weight: 900; font-size: 24px; font-family: 'Scoreboard';");


    marqueeTimer = new QTimer(this);
    connect(marqueeTimer, &QTimer::timeout, this, &Dialog::updateMarquee);
    marqueeTimer->start(10); // Adjust speed as needed

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
    }
}

void Dialog::resetGame()
{
    qDebug() << "Resetting the game";

    points = 0;
    updateScore();

    for (QPushButton* button : buttons) {
        button->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: blanchedalmond;\nborder-image:url(gif/crate.jpg);\nbackground: transparent;\npadding: 3px;");
        button->setDisabled(false);
    }

    assignValuesToButtons();
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
        button->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: green;\nborder-image:url(:/img/gif/cratec.jpg);\nbackground: transparent;\npadding: 3px;");
        button->setDisabled(true);
        points += 100;
        updateScore();
    } else {
		effect->play();
        button->setDisabled(true);
        points -= 25;
        updateScore();
        QTimer *timer = new QTimer(this);
        button->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: blanchedalmond;\nborder-image:url(:/img/gif/cratei.jpg);\nbackground: transparent;\npadding: 3px;");

        connect(timer, &QTimer::timeout, [this, button, timer]() {
        	if (button) {
                assignNewValueToButton(button);
        		button->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: blanchedalmond;\nborder-image:url(:/img/gif/crate.jpg);\nbackground: transparent;\npadding: 3px;");
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
	marqueeLabel2->setVisible(false);
    gifLabel->setVisible(false);
    gifLabel2->setVisible(true);
    startButton->setVisible(false);
    gameTitleLabel->setVisible(false);
    langName->setVisible(true);  // Show instructions when the game starts

    for (QPushButton* button : buttons) {
        button->setVisible(true);
    }

	gifLabel2->setVisible(true);
    ui->rerollButton->setVisible(true);
    lcdScore->setVisible(true);

    // Match the size of gifLabel2 to rerollButton
    gifLabel2->setGeometry(ui->rerollButton->geometry());
    gifLabel2->setScaledContents(true);
}


void Dialog::updateScore()
{
    if (points < 0) {
        points = 0;
	}

	lcdScore->display(points);
}


void Dialog::checkWinCondition()
{
    if (messageBoxOpen) {
        // If a message box is already open, do nothing
        return;
    }

    bool allCorrectButtonsGreenOrBlue = true;
    QString definitionsList;  // To hold the list of term definitions
    QSet<QString> listedTerms;  // To keep track of already listed terms

    for (QPushButton* button : buttons) {
        QString style = button->styleSheet();
        QString text = button->text();

        if (correctValueTexts.contains(text)) {
            if (!(style.contains("background-color: green;"))) {
                allCorrectButtonsGreenOrBlue = false;
                break;
            }

            // Retrieve the definition for the correct term
            std::string valueStr = text.toStdString();
            auto it = explanationMap.find(valueStr);

            if (it != explanationMap.end()) {
                // Only add the term if it hasn't been added yet
                if (!listedTerms.contains(text)) {
                    listedTerms.insert(text);
                    definitionsList += QString("<b><font color='blue'>%1</font></b> - <font color='green'>%2</font><br>")
                                       .arg(text)
                                       .arg(QString::fromStdString(it->second));
                }
            } else {
                // Only add the term if it hasn't been added yet
                if (!listedTerms.contains(text)) {
                    listedTerms.insert(text);
                    definitionsList += QString("<b><font color='blue'>%1</font></b> - <font color='green'>Definition not found.</font><br>")
                                       .arg(text);
                }
            }
        }
    }

    if (allCorrectButtonsGreenOrBlue) {
        for (QPushButton* button : buttons) {
            button->setDisabled(true);
        }
        QString winMessage = QString("<font color='green' size='10'>Your score is: %1</font><br><br>")
                             + "<b><font color='blue' size='6'>Correct Terms and Definitions:</font></b><br><br>" + definitionsList;
        // QString winMessage = QString("<font color='green' size='10'>"
        //                "Your score is: <span style='font-family: monospace; color: #00FF00; background-color: #000000; padding: 2px; border-radius: 5px;'>%1</span>"
        //                "</font><br><br>").arg(points) + "<b><font color='blue' size='6'>Correct Terms and Definitions:</font></b><br><br>" + definitionsList;

        QMessageBox winMsgBox(this);
        winMsgBox.setGeometry(0, 0, 400, 300);
        winMsgBox.setStyleSheet("color: black;\nbackground-color: white");
        QPushButton *playAgainButton = winMsgBox.addButton("Play Again", QMessageBox::ActionRole);
        QPushButton *exitButton = winMsgBox.addButton("Walk the plank", QMessageBox::RejectRole);
        winMsgBox.setText(winMessage.arg(points)); // Inject points into the message
        winMsgBox.setWindowTitle("Congratulations!");

        playAgainButton->setDisabled(false);
        exitButton->setDisabled(false);
        playAgainButton->setFocusPolicy(Qt::NoFocus);
        exitButton->setFocusPolicy(Qt::NoFocus);

        // Set the flag to true when the message box is about to be shown
        messageBoxOpen = true;

        connect(playAgainButton, &QPushButton::clicked, this, &Dialog::resetGame);
        connect(exitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

        // Ensure the flag is reset when the message box is closed
        connect(&winMsgBox, &QMessageBox::finished, this, [this]() {
            messageBoxOpen = false;
        });

        winMsgBox.exec();
    }
}
void Dialog::updateMarquee()
{
    int marqueeWidth2 = marqueeLabel2->fontMetrics().boundingRect(marqueeLabel2->text()).width();
    marqueePosition2 -= 1;
    if (marqueePosition2 < -marqueeWidth2) {
        marqueePosition2 = backWidget->width();
    }
    marqueeLabel2->move(marqueePosition2, marqueeLabel2->y());
}



