#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

int main(int argc,char* argv[])
{
    QApplication app(argc, argv);
    QWidget fenetre;

    QLineEdit* commande = new QLineEdit();

    QPushButton* plus = new QPushButton("+");
    QPushButton* moins = new QPushButton("-");
    QPushButton* fois = new QPushButton("*");
    QPushButton* div = new QPushButton("/");
    QPushButton* entree = new QPushButton("Entrée");

    QPushButton* un = new QPushButton("1");
    QPushButton* deux = new QPushButton("2");
    QPushButton* trois = new QPushButton("3");
    QPushButton* quatre = new QPushButton("4");
    QPushButton* cinq = new QPushButton("5");
    QPushButton* six = new QPushButton("6");
    QPushButton* sept = new QPushButton("7");
    QPushButton* huit = new QPushButton("8");
    QPushButton* neuf = new QPushButton("9");
    QPushButton* zero = new QPushButton("0");

    QVBoxLayout* globalLayout = new QVBoxLayout;
    QHBoxLayout* underCommandLayout = new QHBoxLayout;

    QVBoxLayout* operatorLayout = new QVBoxLayout;

    QVBoxLayout* numberLayout = new QVBoxLayout;
    QHBoxLayout* number123Layout = new QHBoxLayout;
    QHBoxLayout* number456Layout = new QHBoxLayout;
    QHBoxLayout* number789Layout = new QHBoxLayout;
    QHBoxLayout* number0Layout = new QHBoxLayout;

    globalLayout->addWidget(commande);

    number123Layout->addWidget(un);
    number123Layout->addWidget(deux);
    number123Layout->addWidget(trois);
    number456Layout->addWidget(quatre);
    number456Layout->addWidget(cinq);
    number456Layout->addWidget(six);
    number789Layout->addWidget(sept);
    number789Layout->addWidget(huit);
    number789Layout->addWidget(neuf);
    number0Layout->addWidget(zero);

    numberLayout->addLayout(number123Layout);
    numberLayout->addLayout(number456Layout);
    numberLayout->addLayout(number789Layout);
    numberLayout->addLayout(number0Layout);


    operatorLayout->addWidget(plus);
    operatorLayout->addWidget(moins);
    operatorLayout->addWidget(fois);
    operatorLayout->addWidget(div);
    operatorLayout->addWidget(entree);

    underCommandLayout->addLayout(numberLayout);
    underCommandLayout->addLayout(operatorLayout);

    globalLayout->addLayout(underCommandLayout);
    fenetre.setLayout(globalLayout);

    fenetre.show();
    return app.exec();
}
