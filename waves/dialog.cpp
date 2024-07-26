#include "dialog.h"
#include "ui_try.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>

const QStringList valueTexts = {
    "char", "float", "double", "void", "short", "long", "long long",
    "unsigned int", "unsigned short", "unsigned long", "unsigned long long",
    "long double", "array", "pointer", "reference (C++ only)", "function",
    "struct", "union", "enum", "typedef", "class", "namespace",
    "template", "bool", "int"
};

const int NUM_BUTTONS = 30;
const int NUM_VALUES = 15;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    firstClickedButton(nullptr),
    secondClickedButton(nullptr),
    resetTimer(new QTimer(this)),  // Remove or comment out
    points(0),
    scoreLabel(nullptr),
    canSelect(true)  // Initialize selection state
{
    ui->setupUi(this);

    // Initialize the score label
    scoreLabel = ui->scoreLabel;
    if (scoreLabel == nullptr) {
        qDebug() << "Error: scoreLabel is not initialized!";
    }

    // Initialize the list of buttons
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

    // Verify that we have exactly the number of buttons required
    if (buttons.size() != NUM_BUTTONS) {
        qDebug() << "Error: Number of buttons does not match NUM_BUTTONS!";
    }

    // Assign values to buttons and show them immediately
    assignValuesToButtons();

    // Connect all buttons to the same slot
    for (QPushButton* button : buttons) {
        connect(button, &QPushButton::clicked, this, &Dialog::onButtonClicked);
    }

    // Set up the reset timer - Remove or comment out
    // connect(resetTimer, &QTimer::timeout, this, &Dialog::resetButtons);
    // resetTimer->setSingleShot(true);

    // Update score label
    updateScore();
}



Dialog::~Dialog()
{
    delete ui;
}

void Dialog::assignValuesToButtons()
{
    // Create a list of values, each appearing exactly twice
    QList<int> values;
    for (int i = 1; i <= NUM_VALUES; ++i) {
        values.append(i);
        values.append(i);  // Each value appears twice
    }

    // Shuffle values randomly
    QRandomGenerator rng;
    std::shuffle(values.begin(), values.end(), rng);

    // Assign values to buttons and set text immediately
    for (int i = 0; i < buttons.size(); ++i) {
        QPushButton* button = buttons[i];
        if (button == nullptr) {
            qDebug() << "Button is null!";
            continue;
        }
        int value = values[i];
        buttonValues[button] = value;
        button->setText(valueTexts[value - 1]);
    }
}

void Dialog::onButtonClicked()
{
    if (!canSelect) return;  // Prevent actions if not allowed to select

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        if (firstClickedButton == nullptr) {
            firstClickedButton = button;
            toggleButtonValue(button);
        } else if (secondClickedButton == nullptr && button != firstClickedButton) {
            secondClickedButton = button;
            toggleButtonValue(button);
            canSelect = false;  // Disable further selections
            checkForMatch();
        }
    }
}

void Dialog::toggleButtonValue(QPushButton *button)
{
    if (button->text().isEmpty()) {
        int value = buttonValues[button];
        button->setText(valueTexts[value - 1]);
    }
}

void Dialog::checkForMatch()
{
    if (firstClickedButton && secondClickedButton) {
        int firstValue = buttonValues[firstClickedButton];
        int secondValue = buttonValues[secondClickedButton];

        if (firstValue == secondValue) {
            firstClickedButton->setVisible(false);
            secondClickedButton->setVisible(false);
            points++;
            updateScore();
        } else {
            // No need to start the timer anymore
            // resetTimer->start(1000);
        }

        firstClickedButton = nullptr;
        secondClickedButton = nullptr;

        // Re-enable button clicks after resetting or matching
        canSelect = true;
    }
}



void Dialog::resetButtons()
{
    // Reset all buttons
    for (QPushButton* button : buttons) {
        if (button->isVisible()) {
            button->setText("");
        }
    }
}

void Dialog::updateScore()
{
    if (scoreLabel) {
        scoreLabel->setText("Score: " + QString::number(points));
    } else {
        qDebug() << "Error: scoreLabel is not available!";
    }
}
