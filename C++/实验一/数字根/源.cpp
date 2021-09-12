#include<iostream>
using namespace std;
int numberGen(int gen) {
	int ten = gen / 10;
	gen = gen % 10;
	gen = ten + gen;
	return gen;
}
int main() {
	int num[10][10] = { 0 };
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++) {
			num[0][j] = j ;
		}
		num[i][0] = i ;
	}
	int gen = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			gen = num[i][0] * num[0][j];
			if (gen > 9) {
				while(gen>9)gen = numberGen(gen);
			}
			num[i][j] = gen;
		}
	}
	int star ;
	cin >> star;
	string numStr[10][10];
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++)
		{
			if (num[i][j]!= star)numStr[i][j]=' ';
			else
			{
				numStr[i][j] = '*';
			}
			cout << numStr[i][j] << ' ';
			if (j == 9)cout << endl;
		}
	}
}