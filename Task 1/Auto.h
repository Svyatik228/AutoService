#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Auto {
private:
	string nameVlas;
	string nameAuto;
	int year;
	int km;
	int weight;
	double engine;
	double oplata;

public:
	Auto();
	Auto(int km, int year, string name, double engine, int weight);
	Auto(Auto& other);

	virtual void Service();
	int HowManyTo(int thisYear);

	void setKm(int km);
	int getKm();

	void setYear(int year);
	int getYear();

	void setNameAuto(string name);
	string getNameAuto();

	void setNameVlas(string name);
	string getNameVlas();

	void setWeight(int weight);
	int getWeight();

	void setEngine(double engine);
	double getEngine();

	void setOplata(double engine);
	double getOplata();

	virtual void ReadFromFile(istream& file);

	virtual void toString(ostream& out);

	bool operator >(const Auto& other);
	bool operator <(const Auto& other);
	bool operator==(const Auto& other);
	Auto operator = (const Auto& other);

	friend istream& operator>>(istream& is, Auto& v);
	friend ostream& operator<<(ostream& out, const Auto& v);

};


