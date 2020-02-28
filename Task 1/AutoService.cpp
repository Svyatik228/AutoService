#include "AutoService.h"

void AutoService::Read(string file_name)
{
	ifstream file;
	file.open(file_name);
	file >> name;
	int i = 0;
	//for (int i = 0; i < size; i++) {
	while (!file.eof()) {
		try {
			string temp;
			file >> temp;
			type[i] = stoi(temp);

		}
		catch (...) {
			cout << "Erorr" << endl;
			system("pause");
		}

		if (type[i] == 1) {
			mas[i] = new Auto;
			mas[i]->ReadFromFile(file);
			mas[i]->Service();
			i++;
		}
		else if (type[i] == 2) {
			mas[i] = new Simple;
			mas[i]->ReadFromFile(file);
			mas[i]->Service();
			i++;
		}
		else if (type[i] == 3) {
			mas[i] = new Truck;
			mas[i]->ReadFromFile(file);
			mas[i]->Service();
			i++;
		}
	}
	size = i;
}

void AutoService::print_mas()
{
	for (int i = 0; i < size; i++) {
		cout << "Tepy:" << type[i] << " ";
		mas[i]->toString(cout);
		cout << endl;

	}
}

void AutoService::findMaxPrice()
{
	int mas_prise = 0;
	for (int i = 0; i < size; i++) {
		if (mas_prise < mas[i]->getOplata()) {
			mas_prise = mas[i]->getOplata();
		}
	}
	for (int i = 0; i < size; i++) {
		if (mas_prise == mas[i]->getOplata()) {
			mas[i]->toString(cout);
			cout << endl;
		}
	}
}

double AutoService::Sym()
{
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += mas[i]->getOplata();
	}
	return sum;
}

Auto** AutoService::minMas(int& s)
{
	Auto** ma = new Auto * [size];
	double min = mas[0]->getOplata();
	for (int i = 0; i < size; i++) {
		if (mas[i]->getOplata() < min) {
			min = mas[i]->getOplata();
		}
	}
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (mas[i]->getOplata() == min) {
			ma[j] = mas[i];
			j++;
		}
	}
	s = j;
	return ma;
}

void AutoService::AddingToAnArray()
{
	cout << "Type :";
	int i = size;
	cin >> type[i];
	if (type[i] == 1) {
		mas[i] = new Auto;
		mas[i]->ReadFromFile(cin);
		mas[i]->Service();

	}
	else if (type[i] == 2) {

		mas[i] = new Simple;
		mas[i]->ReadFromFile(cin);
		mas[i]->Service();
	}
	else if (type[i] == 3) {

		mas[i] = new Truck;
		mas[i]->ReadFromFile(cin);
		mas[i]->Service();
	}
	size++;
}

void AutoService::DeletToAnArray(string name)
{
	for (int i = 0; i < size; i++) {
		if (mas[i]->getNameVlas() == name) {
			for (int j = i; j < size - 1; j++) {
				swap(mas[j], mas[j + 1]);
				swap(type[j], type[j + 1]);
			}
			break;
		}

	}
	size--;
}


AutoService::AutoService() :size(1), name("nameAuto") {

	mas = new Auto * [1000];
	for (int i = 0; i < size; i++) {
		mas[i] = new Auto;
	}
	type = new  int[100];
	for (int i = 0; i < size; i++) {
		type[i] = 1;
	}
}

AutoService::AutoService(string name, int size) :size(size), name(name) {
	mas = new Auto * [1000];
	for (int i = 0; i < size; i++) {
		mas[i] = new Auto;
	}
	type = new  int[100];
	for (int i = 0; i < size; i++) {
		type[i] = 1;
	}
}

void AutoService::kilkiclisvn() {
	string* arrey = new string[size];
	int size_mas = 0;
	for (int i = 0; i < size; i++) {
		bool flag = true;
		for (int j = 0; j < size_mas; j++) {
			if (arrey[j] == mas[i]->getNameAuto()) {
				flag = false;
				break;
			}
		}
		if (flag) {
			int s = 0;
			arrey[size_mas] = mas[i]->getNameAuto();
			size_mas++;
			for (int k = 0; k < size; k++) {
				if (mas[i]->getNameAuto() == mas[k]->getNameAuto()) {
					s++;
				}
			}
			cout << "NameAuto: " << mas[i]->getNameAuto() << " " << "kilkiclisvn " << s << endl;

		}
	}

}

void AutoService::NewCar(int thisYear) {
	int minr = thisYear - mas[0]->getYear();
	for (int i = 1; i < size; i++) {
		if (minr > thisYear - mas[i]->getYear()) {
			minr = thisYear - mas[i]->getYear();
		}
	}
	for (int i = 0; i < size; i++) {
		if (minr == thisYear - mas[i]->getYear()) {
			mas[i]->toString(cout);
			cout << endl;
		}
	}

}
