#include "dialog.h"
#include "ui_try.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>

const QStringList correctValueTexts = {
    "char", "float", "double", "short", "long", "long long",
    "unsigned int", "unsigned short", "unsigned long", "unsigned long long",
    "long double", "array", "pointer", "reference", "function",
    "struct", "union", "enum", "typedef", "class", "bool", "int"
};

/* const QStringList incorrectValueTexts = {
    "void", "QStringList", "namespace", "template", "pattern matching", "decimal",
    "string", "list", "dict", "tuple", "option", "complex", "record", "var"
};
 */

const QStringList incorrectValueTexts = {
    "var", "var", "var", "var", "var", "var",
    "var", "var", "var", "var", "var", "var", "var", "var"
};

const int NUM_BUTTONS = 30;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    scoreLabel(nullptr),
    points(0)
{
    ui->setupUi(this);

    // Initialize the score label
    scoreLabel = ui->scoreLabel;
    if (scoreLabel == nullptr) {
        qDebug() << "Error: scoreLabel is not initialized!";
    }

    // Initialize the list of buttons
    initializeButtons();

    // Assign values to buttons
    assignValuesToButtons();

    // Connect all buttons to the same slot
    for (QPushButton* button : buttons) {
        connect(button, &QPushButton::clicked, this, &Dialog::onButtonClicked);
    }

    // Setup timers
    setupTimers();

    // Update score label
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

void Dialog::assignValuesToButtons()
{
    QStringList allValues = correctValueTexts + incorrectValueTexts;
    QRandomGenerator rng;
    std::shuffle(allValues.begin(), allValues.end(), rng);

    for (int i = 0; i < buttons.size(); ++i) {
        QPushButton* button = buttons[i];
        if (button == nullptr) {
            qDebug() << "Button is null!";
            continue;
        }
        QString value = allValues[i];
        buttonValues[button] = value;
        button->setText(value);
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
        button->setStyleSheet("background-color: green;");
        button->setDisabled(true);
        points += 100;
    } else {
        button->setStyleSheet("background-color: red;");
        points -= 50;
    }

    updateScore();
    checkWinCondition();
    checkLoseCondition();
}

void Dialog::updateScore()
{
    if (scoreLabel) {
        scoreLabel->setText("Score: " + QString::number(points));
    } else {
        qDebug() << "Error: scoreLabel is not available!";
    }
}

void Dialog::setupTimers()
{
    disableButtonTimer = new QTimer(this);
    connect(disableButtonTimer, &QTimer::timeout, this, &Dialog::disableRandomButton);
    disableButtonTimer->start(2000);  // Every 2 seconds
}

void Dialog::disableRandomButton()
{
    // List of buttons to choose from (excluding green or red)
    QList<QPushButton*> availableButtons;
    
    for (QPushButton* button : buttons) {
        // Check the button's current style
        QString style = button->styleSheet();
        
        // Add buttons that are not green or red
        if (button->isEnabled() && button->isVisible() &&
            !(style.contains("background-color: green;") ||
              style.contains("background-color: red;") ||
              style.contains("background-color: orange;"))) {
            availableButtons.append(button);
        }
    }

    // If no buttons are available, return
    if (availableButtons.isEmpty()) return;

    // Choose a random button from the available ones
    int index = QRandomGenerator::global()->bounded(availableButtons.size());
    QPushButton* button = availableButtons[index];

    // Set the button color to blue and disable it
    button->setStyleSheet("background-color: blue;");
    button->setDisabled(true);
}


void Dialog::checkWinCondition()
{
    bool allCorrectButtonsGreenOrBlue = true;
    
    // Check if all correct buttons are either green or blue
    for (QPushButton* button : buttons) {
        QString style = button->styleSheet();
        QString text = button->text();

        if (correctValueTexts.contains(text)) {
            // Correct button should be green or blue
            if (!(style.contains("background-color: green;") || style.contains("background-color: blue;"))) {
                allCorrectButtonsGreenOrBlue = false;
                break;  // Stop checking if any correct button is not green or blue
            }
        }
    }

    if (allCorrectButtonsGreenOrBlue) {
        if (ui->statusLabel) {
            ui->statusLabel->setText("YOU WIN!!");
            qDebug() << "Win condition met.";
        } else {
            qDebug() << "Error: statusLabel is not available!";
        }
        disableButtonTimer->stop();  // Stop the timer
    }
}



void Dialog::checkLoseCondition()
{
    bool allIncorrectButtonsColored = true;
    
    for (QPushButton* button : buttons) {
        QString style = button->styleSheet();
        if (incorrectValueTexts.contains(buttonValues[button])) {
            // Check if the button is either red or blue
            if (!(style.contains("background-color: red;") || style.contains("background-color: blue;"))) {
                allIncorrectButtonsColored = false;
                break;  // If any incorrect button is not red or blue, stop checking
            }
        }
    }
    
    if (allIncorrectButtonsColored) {
        if (ui->statusLabel) {
            ui->statusLabel->setText("SORRY YOU LOOSE TRY AGAIN!!");
        } else {
            qDebug() << "Error: statusLabel is not available!";
        }
        disableButtonTimer->stop();  // Stop the timer
    }
}
