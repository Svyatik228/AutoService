#pragma once
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include "fstream"
#include "Auto.h"
#include"Small.h"
#include"Truck.h"
using namespace std;
class AutoService
{
private:
	string name;
	Auto** mas;
	int size;
	int* type;



public:
	AutoService();
	AutoService(string name, int size);
	void Read(string file_name);
	void print_mas();
	double Sym();

	void findMaxPrice();

	Auto** minMas(int& s);

	void NewCar(int thisYear);
	void kilkiclisvn();
	void AddingToAnArray();
	void DeletToAnArray(string name);


};

