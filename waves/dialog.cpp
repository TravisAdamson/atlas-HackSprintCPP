#include "dialog.h"
#include "ui_try.h"  // Included the generated UI header

#include <QPushButton>
#include <QVBoxLayout>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)  // Initialize the UI pointer
{
    ui->setupUi(this);  // Set up the UI components

    // Connect buttons to their respective slots
    connect(ui->pushButton_1, &QPushButton::clicked, this, &Dialog::on_pushButton_1_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Dialog::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Dialog::on_pushButton_3_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &Dialog::on_pushButton_4_clicked);

    // Initialize button texts
    ui->pushButton_1->setText("!NOT CLICKED!");
    ui->pushButton_2->setText("!NOT CLICKED!");
    ui->pushButton_3->setText("!NOT CLICKED!");
    ui->pushButton_4->setText("!NOT CLICKED!");
}

Dialog::~Dialog()
{
    delete ui;  // Clean up the UI resources
}

void Dialog::on_pushButton_1_clicked()
{
    toggleButtonText(ui->pushButton_1);
    checkAllButtons();  // Ensure this method is declared in dialog.h
}

void Dialog::on_pushButton_2_clicked()
{
    toggleButtonText(ui->pushButton_2);
    checkAllButtons();  // Ensure this method is declared in dialog.h
}

void Dialog::on_pushButton_3_clicked()
{
    toggleButtonText(ui->pushButton_3);
    checkAllButtons();  // Ensure this method is declared in dialog.h
}

void Dialog::on_pushButton_4_clicked()
{
    toggleButtonText(ui->pushButton_4);
    checkAllButtons();  // Ensure this method is declared in dialog.h
}

void Dialog::toggleButtonText(QPushButton *button)
{
    QString currentText = button->text();

    // Toggle between the three states
    if (currentText == "!NOT CLICKED!") {
        button->setText("Clicked!");
    } 
    else if (currentText == "Clicked!") {
        button->setText("Click");
    } 
    else if (currentText == "Click") {
        button->setText("!NOT CLICKED!");
    } 
    else {
        // Optional: Handle unexpected text
        button->setText("!NOT CLICKED!");
    }
}

void Dialog::checkAllButtons()
{
    // Check the state of all buttons
    if (ui->pushButton_1->text() == "Clicked!" &&
        ui->pushButton_2->text() == "Clicked!" &&
        ui->pushButton_3->text() == "Clicked!" &&
        ui->pushButton_4->text() == "Clicked!") {

        // All buttons are clicked
        ui->pushButton_1->setText("Congrats");
        ui->pushButton_2->setText("You");
        ui->pushButton_3->setText("Win");
        ui->pushButton_4->setText("!!!!!");
    }
}
