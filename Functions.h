#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Animal.h"

using namespace std;

ostream& operator << (ostream& os, const Animal& a);
istream& operator >> (istream& in, Animal& a);
string toLowerCase(const string& str);
vector<Animal>::iterator findAnimalByName(vector<Animal>& animals, const string& name);
int showMenu();
void addNewAnimal(vector<Animal>& animals);
void showEntireList(vector<Animal>& animals);
void changeAnimalDetails(vector<Animal>& animals);
void deleteAnimal(vector<Animal>& animals);
