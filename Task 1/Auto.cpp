#include "Auto.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;




Auto::Auto(int km, int year, string name, double engine, int weight)
{
	this->km = km;
	this->year = year;
	this->nameAuto = name;
	this->engine = engine;
	this->weight = weight;
}

Auto::Auto()
{
	this->km = 0;
	this->year = 0;
	this->nameAuto = " ";
	this->engine = 0.0;
	this->weight = 0;
	this->oplata = 0.0;

}

void Auto::setKm(int km) {
	this->km = km;
}
int Auto::getKm() {
	return km;
}
void Auto::setYear(int year) {
	this->year = year;
}
int Auto::getYear() {
	return year;
}
void Auto::setNameAuto(string name) {
	this->nameAuto = name;
}
string Auto::getNameAuto() {
	return nameAuto;
}

void Auto::setNameVlas(string name)
{
	nameVlas = name;
}

string Auto::getNameVlas()
{
	return nameVlas;
}

void Auto::setWeight(int weight)
{
	this->weight = weight;
}

int Auto::getWeight()
{
	return weight;
}

void Auto::setEngine(double engine)
{
	this->engine = engine;
}

double Auto::getEngine()
{
	return engine;
}

void Auto::setOplata(double engine)
{
	this->oplata = engine;
}

double Auto::getOplata()
{
	return  oplata;
}


void Auto::Service() {

	if (year > 2000 && nameAuto == "Shkoda") {
		oplata = 5000;
	}
	else if (year > 2010 && nameAuto == "Audi") {
		oplata = 14000;
	}
	else if (year > 2000 && nameAuto == "Volvo") {
		oplata = 9000;
	}
	else if (year > 2000 && nameAuto == "Renault") {
		oplata = 7000;
	}
	else {
		oplata = 10000;
	}

}
void  Auto::ReadFromFile(istream& file)
{
	file >> nameVlas;
	file >> nameAuto;
	try {
		string temp;
		file >> temp;
		km = stoi(temp);

	}
	catch (...) {
		cout << "Erorr" << endl;
		system("pause");
	}
	try {
		string temp;
		file >> temp;
		year = stoi(temp);

	}
	catch (...) {
		cout << "Erorr" << endl;
		system("pause");
	}

	try {
		string temp;
		file >> temp;
		engine = stod(temp);

	}
	catch (...) {
		cout << "Erorr" << endl;
		system("pause");
	}
	try {
		string temp;
		file >> temp;
		weight = stoi(temp);

	}
	catch (...) {
		cout << "Erorr" << endl;
		system("pause");
	}

}


void Auto::toString(ostream& out)
{
	out << "nameVlas: " << nameVlas << " ";
	out << " nameAuto: " << nameAuto << " ";
	out << " year: " << year << " ";
	out << " km: " << km << " ";
	out << " engine: " << engine << " ";
	out << " weight: " << weight << " ";
	out << " oplata: " << oplata << " ";
}

Auto::Auto(Auto& other) {
	this->nameVlas = other.nameVlas;
	this->nameAuto = other.nameAuto;
	this->year = other.year;
	this->km = other.km;
	this->engine = other.engine;
	this->weight = other.weight;
	this->oplata = other.oplata;
}

int Auto::HowManyTo(int thisYear) {

	int ab = km / 10000;
	return ((thisYear - year) / 2) + ab;

}

bool Auto::operator>(const Auto& other) {
	return (this->nameAuto > other.nameAuto);
}

bool Auto::operator<(const Auto& other) {
	return (this->nameAuto < other.nameAuto);
}

bool Auto::operator==(const Auto& other) {
	return  (this->nameVlas == other.nameVlas &&
		this->nameAuto == other.nameAuto &&
		this->year == other.year &&
		this->km == other.km &&
		this->engine == other.engine &&
		this->weight == other.weight &&
		this->oplata == other.oplata);
}

Auto Auto::operator=(const Auto& other) {
	nameVlas = other.nameVlas;
	nameAuto = other.nameAuto;
	year = other.year;
	km = other.km;
	engine = other.engine;
	weight = other.weight;
	oplata = other.oplata;
	return  *this;
}

istream& operator>>(istream& in, Auto& obj) {
	in >> obj.nameVlas;
	in >> obj.nameAuto;
	in >> obj.km;
	in >> obj.year;
	in >> obj.engine;
	in >> obj.weight;
	return in;
}

ostream& operator<<(ostream& out, const Auto& v) {
	out << "nameAuto vlas " << v.nameVlas << " ";
	out << " nameAuto: " << v.nameAuto << " ";
	out << " year: " << v.year << " ";
	out << " km: " << v.km << " ";
	out << " engine: " << v.engine << " ";
	out << " weight: " << v.weight << " ";
	out << " oplata: " << v.oplata << " ";
	return out;
}

