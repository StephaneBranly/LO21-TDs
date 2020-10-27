#include<QApplication>
#include<QPushButton>
int main(int argc,char*argv[])
{
    QApplication app(argc, argv);
    QPushButton bouton("Quitter");
    QPushButton bouton2("Coucou, ceci est un nouveau bouton àdéplace");
    QObject::connect(&bouton,SIGNAL(clicked()), &app, SLOT(quit()));
    bouton.show();
    bouton2.show();
    return app.exec();
}
