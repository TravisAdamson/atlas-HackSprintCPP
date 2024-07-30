#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Dialog window;  // Create an instance of the Dialog class
    window.show();  // Call the show() method on the instance

    return app.exec();  // Enter the application's event loop
}
