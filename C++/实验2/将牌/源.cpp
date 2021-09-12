#include<iostream>
using namespace std;
#include<cstring>
#include<algorithm>
struct Data {
	char data[7];
}charString[7];
bool cmp(const Data& elem1, const Data& elem2) {
	if (strcmp(elem1.data, elem2.data) < 0) {
		return true;
	}
	return false;
}
void printString(string trump) {
	for (int i = 0; i < 7; i++)
	{
		cout << trump[i];
	}
	cout << endl;
}
void charArray(string trump,int num) {
	/*for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
		{
			charString[i][j] = '0';
		}
	}*/
	for (int i = 0; i < 7; i++)
	{
		charString[num].data[i] = trump[i];
	}
}
void printChar() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
		{
			if(charString[i].data[j]!='0')
			cout << charString[i].data[j];
		}
		cout << endl;
	}
}
void sortChar() {
	sort(charString, charString + 6, cmp);
}
void FindString(string trump,int times) {
	int space = 0;
	int white = 0;
	int black = 0;
	int step = 0;
	string FakeTrump = trump;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++) {
				charString[i].data[j]='0';
			
		}
	}
	bool change = true;
	cout << "结果_" << times << "：" << endl;
	for (int i = 0; i < 7; i++)
	{
		if (trump[i]=='W')
		{
			white++;
		}
		else if (trump[i] == 'E')
		{
			space++;
			step = i;
		}
		else if(trump[i] == 'B')
		{
			black++;
		}
		if (white == 3&&black==0)
		{
			cout << "目标格局" << endl;
			change = false;
			break;
		}
	}
	if (change) {
		char temp;
		int num = -3;
		int hang = 0;
		for (int j = 0; j < 7; j++)
		{
			if (step + num < 7 && step + num >= 0&& num !=0) {
				temp = FakeTrump[step + num];
				FakeTrump[step + num] = FakeTrump[step];
				FakeTrump[step] = temp;
				charArray(FakeTrump,hang);
				hang++;
				FakeTrump = trump;
			}
			num++;
		}
		sortChar();
		printChar();
	}
}
int main() {
	int step = 0;
	string trumpCard;
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> trumpCard;
		FindString(trumpCard,i+1);
	}
	system("pause");
	return 0;
	
}
