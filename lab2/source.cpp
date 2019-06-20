#include <iostream>

#include <fstream>

#include <string>

#include <vector>

#include "Header.h"

using namespace std;



void Country::set_country_info(string str, int num)

{

	int pos = str.find(',');

	name = str.substr(0, pos);

	str = str.substr(pos + 1, str.length() + 1);

	for (int i = 0; i < num; i++) {

		string out;

		pos = str.find(',');

		out = str.substr(0, pos);

		mark[i] = stoi(out);

		str = str.substr(pos + 1, str.length() - 1);

	}

}



void sort_marks(vector <Country> &Countries_list, int num) {

	int *res = new int[10]{ 12, 10, 8, 7, 6, 5, 4, 3, 2, 1 };



	for (int q = 0; q < num; q++) {

		for (int i = 0; i < num; i++) {

			for (int j = 0; j < num - 1; j++) {

				if (Countries_list[j].mark[q] < Countries_list[j + 1].mark[q]) {

					swap(Countries_list[j], Countries_list[j + 1]);

				}

			}

		}



		for (int i = 0; i < num; i++) {

			Countries_list[i].result += (i >= 10) ? 0 : (res[i]);

		}

	}

}



void sort_result(vector <Country> &Countries_list, int num) {

	for (int i = 0; i < num; i++) {

		for (int j = 0; j < num - 1; j++) {

			if (Countries_list[j].result < Countries_list[j + 1].result) {

				swap(Countries_list[j], Countries_list[j + 1]);

			}

		}

	}

}
