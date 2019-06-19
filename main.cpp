#include "catchbutton.h"
#include <QApplication>

int main(int lArgc, char *lArgv[])
{
    QApplication lApplication(lArgc, lArgv);

    CatchButton pressButton;

    pressButton.show();

    return lApplication.exec();
}
