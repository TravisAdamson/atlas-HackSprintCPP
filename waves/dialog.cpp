#include "dialog.h"
#include <QPushButton>

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
}

Dialog::~Dialog()
{
    delete ui;  // Clean up the UI resources
}

void Dialog::on_pushButton_1_clicked()
{
    toggleButtonText(ui->pushButton_1);
}

void Dialog::on_pushButton_2_clicked()
{
    toggleButtonText(ui->pushButton_2);
}

void Dialog::on_pushButton_3_clicked()
{
    toggleButtonText(ui->pushButton_3);
}

void Dialog::on_pushButton_4_clicked()
{
    toggleButtonText(ui->pushButton_4);
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