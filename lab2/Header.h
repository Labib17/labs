   

#pragma once

#include <string>

using namespace std;



class Country {

public:

	string name;

	int *mark;

	int result;



	Country(int num) {

		name = "";

		mark = new int[num];

		result = 0;

	}



	~Country() {};



	void set_country_info(string str, int num);

};



void sort_marks(vector <Country> &Countries_list, int num);

void sort_result(vector <Country> &Countries_list, int num);
