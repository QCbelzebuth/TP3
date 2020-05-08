#include "produit.h"

//constructeur sans paramètres
Produit::Produit() {
	Produit::id_produit;
	Produit::prix;
};
//constructeur, prends en paramètres le id du produit, le nom, le prix
Produit::Produit(string id_produit, string prix) {
	Produit::id_produit = id_produit;
	Produit::prix = prix;
};

//destructeur
Produit::~Produit() {}

//getters & setters
string Produit::getIdproduit() const
{
    return id_produit;
}

void Produit::setIdproduit(string idproduit)
{
    id_produit = idproduit;
}

string Produit::getPrix() const
{
    return prix;
}

void Produit::setPrix(string prix)
{
    this->prix = prix;
}

