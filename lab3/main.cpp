#include <iostream>

#include<string>

#include<fstream>

struct elem

{

	int data1, data2, data3;

	elem *prev, *next;

};

struct queue

{

	elem *back, *front;

	queue(void) :back(NULL), front(NULL) {}

};

struct coo

{

	int a, b;

};

char returnVal(int x)

{

	x=x+87;

    return (char)x;

}

using namespace std;

void push_back(queue &a, coo &p, int &x);

void pop_back(queue &a, int &v1, int &v2, int &v3);

void alg(queue &one, coo &p, coo &k, coo &napram, int **A, int &i, int &j, int &h, int &g, int &w);

void print(queue &a, coo &b, int &);

int main()

{

	ifstream input("input.txt");

	string d[25];

	int m = 0;

	while (!input.eof())

	{

		getline(input, d[m], '\n');

		m++;

	}

	int n = d[0].size();

	int **A=new int*[n];

	m--;

	for (int r = 0; r < m; r++)

	{

		A[r] = new int[n];

	}

	for (int i = 0; i < m; i++)

	{

		for (int j = 0; j < n; j++)

		{

			if (d[i][j] == ' ')

				A[i][j] = -2;

			else

				A[i][j] = -1;

		}

	}

	int i = 0, j = 1, h = 0, g = 0, w = 0; 

	queue one;

	coo napram;

	p.a = 2; p.b = 1; k.a = 9; k.b = 6;

	alg(one, p, k, napram, A, i, j, h, g, w);

	ofstream output("output.txt");

	char r;

	int o;

	for (int i = 0; i < m; i++)

	{

		for (int j = 0; j < n; j++)

		{

			if (A[i][j] == -2||A[i][j]==-3)

			{

				output << ' ';

			}

			else if (A[i][j] == -1)

			{

				output << 'X';

			}

			else if (A[i][j] < 10)

			{

				o=A[i][j];

				output << o;

			}

			else

			{

				r=returnVal(A[i][j]);

				output << r;

			}

		}

		output << "\n";

		cout << "\n";

	}

	

	return 0;

}

void push_back(queue &a, coo &p, int &i)

{

	elem *temp = new elem;

	temp->data1 = p.a;

	temp->data2 = p.b;

	temp->data3 = i;

	temp->prev = NULL;

	if (!a.back)

	{

		a.back = a.front = temp; temp->next = NULL;

	}

	else

	{

		temp->next = a.back;

		a.back->prev = temp;

		a.back = temp;

	}

}

void print(queue &a, coo &b, int &j)

{

	elem *cursor = a.back;

	for(int i=0; i<j-1; i++)

	{

		cursor = cursor->next;

	}

	b.a=cursor->data1;

	b.b = cursor->data2;

}

void pop_back(queue &a, int &v1, int &v2, int &v3)

{

	if (!a.back->next)

	{

		v1 = a.back->data1;

		v2 = a.back->data2;

		v3 = a.back->data3;

		delete a.back;

		a.back = a.front = NULL;

	}

	else

	{

		v1 = a.back->data1;

		v2 = a.back->data2;

		v3 = a.back->data3;

		a.back = a.back->next;

		a.back->prev = NULL;

	}

}

void alg(queue &one, coo &p, coo &k, coo &napram, int **A, int &i, int &j, int &h, int &g, int &w)

{

	napram.a = p.a;

	napram.b = p.b;

	push_back(one, p, i);

	h = 1;

	w = h;

	while (i < j)

	{

		i++;

		j++;

		for (int r = 0; r < h; r++)

		{

			int o = h - r+g;

			print(one, napram, o);

			if (A[napram.a][napram.b - 1] == -2)

			{

				g++; w++;

				napram.b = napram.b - 1;

				push_back(one, napram, i);

				if (napram.a == k.a&&napram.b == k.b)

				{

					j--;

					break;

				}

				A[napram.a][napram.b]=-3;

				napram.b = napram.b + 1;

			}

			if (A[napram.a][napram.b + 1] == -2)

			{

				g++; w++;

				napram.b = napram.b + 1;

				push_back(one, napram, i);

				if (napram.a == k.a&&napram.b == k.b)

				{

					j--;

					break;

				}

				A[napram.a][napram.b]=-3;

				napram.b = napram.b - 1;

			}

			if (A[napram.a - 1][napram.b] == -2)

			{

				g++; w++;

				napram.a = napram.a - 1;

				push_back(one, napram, i);

				if (napram.a == k.a&&napram.b == k.b)

				{

					j--;

					break;

				}

				A[napram.a][napram.b]=-3;

				napram.a = napram.a + 1;

			}

			if (A[napram.a + 1][napram.b] == -2)

			{

				g++; w++;

				napram.a = napram.a + 1;

				push_back(one, napram, i);

				if (napram.a == k.a&&napram.b == k.b)

				{

					j--;

					break;

				}

				A[napram.a][napram.b]=-3;

				napram.a = napram.a - 1;

			}

		}

		h = g;

		g = 0;

	}

	pop_back(one, h, g, j);

	napram.a = h; napram.b = g;

	A[h][g] = j;

	for (i = 0; i < w - 1; i++)

	{

		pop_back(one, h, g, j);

		if ((h == napram.a&&g == napram.b - 1) || (h == napram.a&&g == napram.b + 1) || (h == napram.a - 1 && g == napram.b) || (h == napram.a + 1 && g == napram.b))

		{

			napram.a = h; napram.b = g;

			A[h][g] = j;

		}

	}

}
