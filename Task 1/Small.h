#pragma once
#include"Auto.h"
class Simple :public Auto
{
private:
	int count_ofPlace;

public:
	Simple();
	Simple(int km, int year, string name, double engine, int weight, int count_ofPlace);
	void Service() override;
	void carType();
	void toString(ostream& out)override;
	void ReadFromFile(istream& file) override;
};

