#include <iostream>

#include <fstream>

#include <string>

#include <vector>

#include "Header.h"

using namespace std;



int main() {

	ifstream file("eurovision.csv");

	if (!file.is_open()) {

		cout << "File couldn't be open.\n";

	}



	string Num;

	getline(file, Num);

	int num = stoi(Num);



	vector <Country> Countries_list;

	for (int i = 0; i < num; i++) {

		Country country(num);

		string str;

		getline(file, str);

		country.set_country_info(str, num);

		Countries_list.push_back(country);

	}

	

	sort_marks(Countries_list, num);

	sort_result(Countries_list, num);



	ofstream fout("result.csv");

	fout << "List of winners : \n";

	cout << "List of winners : \n";

	for (int i = 0; i < 10; i++) {

		fout << Countries_list[i].name << " " << Countries_list[i].result << ";" << endl;

		cout << Countries_list[i].name << " " << Countries_list[i].result << ";" << endl;

	}



	file.close();

	system("pause");

}
