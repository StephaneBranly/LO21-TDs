#include <QApplication>
#include "qComputer.h"

#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qDebug()<<"Message dans la console\n";

    QComputer fenetre;
    fenetre.show();

    return app.exec();
}
