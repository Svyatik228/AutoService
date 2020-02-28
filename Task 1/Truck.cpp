#include "Truck.h"

Truck::Truck()
{

	this->capasity = 0.0;
}

Truck::Truck(int km, int year, string name, double engine, int weight, double capasity) :Auto(km, year, name, engine, weight)
{
	this->capasity = capasity;
}

void Truck::Service()
{
	double k = 0.05;
	cout << "Enter capasity:";
	cin >> capasity;
	int cena = 0;
	if (getYear() > 2000 && getNameAuto() == "Shkoda") {
		cena = 5000;
	}
	else if (getYear() > 2010 && getNameAuto() == "Audi ") {
		cena = 14000;
	}
	else {
		cout << "ne obsl" << endl;
	}

	double m = cena * k;
	for (int i = 0; i < capasity; i++) {
		cena = m + cena;
	}
	this->setOplata(cena);

	cout << "cena of service:" << cena << endl;

}

void Truck::toString(ostream& out)
{
	Auto::toString(out);
	out << "capasity: " << capasity << " ";

}

void Truck::ReadFromFile(istream& file)
{
	Auto::ReadFromFile(file);
	try {
		string temp;
		file >> temp;
		capasity = stod(temp);

	}
	catch (...) {
		cout << "Erorr" << endl;
		system("pause");
	}
	file >> capasity;

}

