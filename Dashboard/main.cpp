#include "dialog.h"
#include <QApplication>
//Test er dette
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
