#ifndef __PRODUIT_H__
#define __PRODUIT_H__

#include <iostream>

using namespace std;

class Produit {
private:

    //attributs
    string id_produit="";
    string prix = "";


public:

    //constructeur sans paramètres
    Produit();

    //constructeur, prends  en paramètres le id du produit, le nom, le prix
    Produit(string id_produit, string prix);

    //destructeur
    virtual~Produit();

    //getters & setters
    virtual string getIdproduit() const;
    virtual void setIdproduit(string idproduit);
    virtual string getPrix() const;
    virtual void setPrix(string prix);

};

#endif // __PRODUIT_H__