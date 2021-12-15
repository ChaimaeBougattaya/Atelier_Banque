// BanqueFINAL.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<typeinfo>
#include"Client.h"
#include"Compte.h"
#include"Devise.h"
#include"MAD.h"
#include"Euro.h"
#include"Dollars.h"
#include"Operations.h"
#include"OperationR.h"
#include"OperationV.h"
#include"CompteEpargne.h"
#include"CompteCourant.h"
#include"ComptePayant.h"
using namespace banque;
using namespace std;
int main()
{
    Client* Client1 = new Client("chaimae", "bougattaya", "Mohammedia");

    Devise* devise1 = new MAD(10);
    Devise* devise2 = new Euro(100);
    Devise* devise3 = new Euro(10);
    Devise* devise4 = new Dollars(24000);
    Devise* devise5 = new Euro(170);
    Devise* devise6 = new Euro(3);
    Devise* decouvert = new Euro(8);


    CompteEpargne* compte1 = new CompteEpargne(Client1, devise1);
    CompteEpargne* compte2 = new CompteEpargne(Client1, devise2);
    Client1->ajouterCompte(*compte1);
    Client1->ajouterCompte(*compte2);

    //Compte* CC = new CompteCourant(Client1, devise3, decouvert);
    ComptePayant* CP = new ComptePayant(Client1, devise3, decouvert);
    Client1->ajouterCompte(*CP);

    CP->crediter(devise6);
    //bool b = CP->debiter(devise4);
    compte1->crediter(devise4);
    bool b = compte1->debiter(devise5);
    Client1->print();


    delete Client1;
    delete devise1;
    delete devise2;
    delete devise3;
    delete devise4;
    delete devise5;
    delete devise6;
    delete decouvert;

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

/*
  /*  Client* Client1 = new Client("chaimae", "bougattaya", "El mansouria");

    Devise* devise1 = new MAD(2000);
    Devise* devise2 = new Euro(1000);
    //Devise* devise3;
    Compte* compte1 = new CompteEpargne(Client1, devise1);
    Client1->ajouterCompte(*compte1);

    compte1->crediter(devise2);
    Client1->print();
    delete Client1;
    delete devise1;*/
 