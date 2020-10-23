#include "qComputer.h"

QComputer::QComputer(QWidget* parent) : QWidget(parent)
{
    // Création et positionnement de chaque composant
    pile = new Pile;
    controleur = new Controleur(ExpressionManager::getInstance(),*pile);

    message = new QLineEdit;
    vuePile = new QTableWidget(pile->getNbItemsToAffiche(),1);
    commande = new QLineEdit;
    couche = new QVBoxLayout;

    couche->addWidget(message);
    couche->addWidget(vuePile);
    couche->addWidget(commande);

    setLayout(couche);

    setWindowTitle("Comp'UT");

    message->setStyleSheet("background: cyan");
    message->setReadOnly(true);
    message->setText("Bienvenue");

    vuePile->setStyleSheet("background: darkcyan");
    vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // suppression du header horizontal de la pile
    vuePile->horizontalHeader()->setVisible(false);

    // ajuster la largeur des colonnes
    vuePile->horizontalHeader()->setStretchLastSection(true);

    // création d'une liste de labels pour le header vertical
    QStringList labels;
    for(size_t i=pile->getNbItemsToAffiche(); i>0; i--)
    {
        QString str=QString::number(i);
        str+=":";
        labels<<str;

        // création de l'item de chaque ligne
        vuePile->setItem(i-1,0, new QTableWidgetItem(""));

    }
    vuePile->setVerticalHeaderLabels(labels);
    vuePile->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    commande->setFocus(Qt::OtherFocusReason);


    connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));
    connect(commande, SIGNAL(returnPressed()),this,SLOT(getNextCommande()));
};

void QComputer::refresh(){
    qDebug()<<"\nRefresh called";
    message->setText(pile->getMessage());
    for(size_t i=0; i<pile->getNbItemsToAffiche(); i++)
        vuePile->item(i,0)->setText("");

    size_t nb=0;
    for(Pile::iterator it=pile->begin(); it!=pile->end()  && nb<pile->getNbItemsToAffiche(); ++it)
    {
        vuePile->item(pile->getNbItemsToAffiche()-nb-1,0)->setText((*it)
                                                          .toString());
        nb++;
    }

}

void QComputer::getNextCommande(){
    QString c=commande->text();
    controleur->commande(c);
    commande->clear();
}
