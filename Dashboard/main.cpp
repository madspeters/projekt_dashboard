#include "dialog.h"
#include <QApplication>
// Dette er en test
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
