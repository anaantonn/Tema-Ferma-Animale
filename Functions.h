#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

int showMenu();
void addNewAnimal(vector<Animal>& animals);
void showEntireList(vector<Animal>& animals);
void changeAnimalDetails(vector<Animal>& animals);
void deleteAnimal(vector<Animal>& animals);
