#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname)
{
	ofstream fout(fname);
	char ch;
	string s;
	do
	{
		cin.get();
		cin.sync();
		cout << "enter line: "; getline(cin, s);
		fout << s << endl;
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}

void Remove(char* fname)
{
	ifstream f(fname);
	ofstream t("TMP.TXT");
	int x;
	while (f >> x)
		if (x >= 0)
			t << x << endl;
	f.close();
	t.close();
	remove(fname);
	rename("TMP.TXT", fname);
}

int Calculation(char* fname)
{
	int max = 0;
	int countSpace = 0;
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		const char symbol = ' ';
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i]==symbol) 
				countSpace++;

			if (s[i] != symbol)
				countSpace=0;

			if (max < countSpace)
				max = countSpace;
		}
	}
	return max;
}

int main()
{
	char fname[1] = {'t'};
	CreateTXT(fname);
	PrintTXT(fname);
	cout << "Max spase = " << Calculation(fname);
	Remove(fname);

	return 0;
}