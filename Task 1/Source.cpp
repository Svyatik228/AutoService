#include <iostream>
#include<string>
#include<fstream>
#include"Auto.h"
#include"Small.h"
#include"Truck.h"
#include"AutoService.h"
using namespace std;

int main() {
	string nameFile = "Text.txt";
	ifstream file;
	file.open(nameFile);

	if (!file.is_open())
	{
		cout << "The file cannot be  open\n";
		return 1;
	}
	AutoService as;
	as.Read(nameFile);
	as.print_mas();
	cout << endl;

	cout << "Syma " << as.Sym() << endl;
	cout << endl;

	cout << "Kilkiclisvn " << endl;
	as.kilkiclisvn();
	cout << endl;

	cout << "Max Price" << endl;
	as.findMaxPrice();
	cout << endl;

	cout << "The more new car" << endl;
	as.NewCar(2020);
	cout << endl;
	
	cout << "adding car" << endl;
	as.AddingToAnArray();
	cout << endl;
	as.print_mas();

	cout << "delet" << endl;
	string s;
	cin >> s;
	as.DeletToAnArray(s);
	cout << endl;
	as.print_mas();


}