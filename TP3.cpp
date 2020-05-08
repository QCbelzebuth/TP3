// TP3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "produit.h"

using namespace std;

void skip(std::istream& is, size_t n, char delim);
Produit* getWantedLines(std::istream& in);
void removeSubstrs(string& s, string& p);

int main()
{
    vector<Produit*> produits;

    ifstream f1;
    f1.open("txt/Facturator.txt");

    while (f1.eof() == false) {
        Produit* p1 = getWantedLines(f1);
        Produit* p2 = getWantedLines(f1);
        Produit* p3 = getWantedLines(f1);
        produits.push_back(p1);
        produits.push_back(p2);
        produits.push_back(p3);
    }

    f1.close();
    int i;
    for (i = 0; i < 3; i++) {

        string id= produits[i]->getIdproduit();
        string delim = ":";
        removeSubstrs(id, delim);
        produits[i]->setIdproduit(id);

    }

    ofstream f2("txt/DaCount.txt");
    for (i=0; i < produits.size(); i++) {
        f2 << produits[i]->getIdproduit() << " ";
        f2 << produits[i]->getPrix() << "\n";
        cout << produits[i]->getIdproduit() << "\n";
        cout << produits[i]->getPrix() << "\n";
    }
    f2.close();
    return 0;

}
      

void skip(std::istream& is, size_t n, char delim)
{
    size_t i = 0;
    while (i++ < n)
        is.ignore(80, delim);
}

Produit* getWantedLines(std::istream& in) {
    string line;
    string id;
    string prix;


    getline(in, line, '\n');
    cout << "current iteration line: '" << line << "'\n";
    id = line;
    skip(in, 1, '\n');
    getline(in, line, '\n');
    cout << "current iteration line: '" << line << "'\n";
    prix = line;
    Produit* p = new Produit(id, prix);

    return p;
}

void removeSubstrs(string& s, string& p) {
    string::size_type n = p.length();
    for (string::size_type i = s.find(p);
        i != string::npos;
        i = s.find(p))
        s.erase(i, n);
}

