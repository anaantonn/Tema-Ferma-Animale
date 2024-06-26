#include "Animal.h"
#include <iostream>

using namespace std;



ostream& operator << (ostream& os, const Animal& a)
{
    os << "Nume: " << a.Nume << " " << "Specie: " << a.Specie << " " << "Categorie de productie: " << a.CategorieDeProductie << " " << "Greutate: " << a.Greutate << " "
    << "Varsta: " << a.Varsta << endl;

    return os;
}

istream& operator >> (istream& in, Animal& a)
{
    cout << "Nume: ";
    in >> a.Nume;
    cout << "Specie: ";
    in >> a.Specie;
    cout << "Rasa: ";
    in >> a.Rasa;
    cout << "Categorie de productie: ";
    in >> a.CategorieDeProductie;
    cout << "Greutate: ";
    in >> a.Greutate;
    cout << "Varsta: ";
    in >> a.Varsta;

    return in;
}