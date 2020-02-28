#pragma once
#include"Auto.h"
class Truck :public Auto
{
private:
	double capasity;
public:
	Truck();
	Truck(int km, int year, string name, double engine, int weight, double capasity);
	void Service() override;
	void toString(ostream& out) override;
	void ReadFromFile(istream& file) override;
};

