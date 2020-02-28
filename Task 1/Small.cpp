#include "Small.h"


Simple::Simple()
{
	this->count_ofPlace = 0;
}

Simple::Simple(int km, int year, string name, double engine, int weight, int count_ofPlace) :Auto(km, year, name, engine, weight)
{
	this->count_ofPlace = count_ofPlace;
}


void Simple::Service()
{
	double k = 0.02;
	//cout << endl;
	//cout << "Enter count of place:";
	count_ofPlace=13;
	double cena = 0;
	int ob;
	int ab;
	if (getYear() > 2000 && getNameAuto() == "Shkoda") {
		cena = 8000;
	}
	else if (getYear() > 2010 && getNameAuto() == "Audi") {
		cena = 14000;
	}
	else {
		cena = 5000;
	}
	ab = getKm() / 10000;
	ob = ((2019 - getYear()) / 2) + ab;
	//cout << "obsl:" << ob << endl;
	double m = cena * k;
	for (int i = 0; i < count_ofPlace; i++) {
		cena = m + cena;
	}
	//cout << "cena of service:" << cena << endl;

	this->setOplata(cena);

}

void Simple::carType()
{
	if (getEngine() < 2) {
		cout << "malolitrajna" << endl;
	}
	else if (getEngine() > 2 && getEngine() < 4) {
		cout << "serednolitrajna" << endl;
	}
	else {
		cout << "bagatolitrajna" << endl;
	}
}

void Simple::toString(ostream& out)
{
	Auto::toString(out);
	out << "count of place: " << count_ofPlace << " ";



}

void Simple::ReadFromFile(istream& file)
{
	Auto::ReadFromFile(file);
	try {
		string temp;
		file >> temp;
		count_ofPlace = stod(temp);

	}
	catch (...) {
		cout << "Erorr" << endl;
		system("pause");
	}

}



