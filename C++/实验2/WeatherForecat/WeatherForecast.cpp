#include<iostream>
using namespace std;
bool updown = false;
int minTemp = 0;
void inputTemps(int temps[], int n) {
	int temp = 0;
	cout << "Please input the temprature: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp<0)
		{
			if (temp< minTemp)
			{
				minTemp = temp;
			}
			updown = true;
		}
		temps[i] = temp;
		//cout << -minTemp << endl;
	}
}
void displayTemps(int temps[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "\t";
		if (updown)
		{
				int now = 0;
				if (temps[i] > 0)
				{
					now = -minTemp;
					for (int m = 0; m < now; m++)
					{
						cout << " ";
					}
				}
				else
				{
					now = temps[i] - minTemp;
					for (int m = 0; m < now; m++)
					{
						cout << " ";
					}
					for (int q = 0; q < -temps[i]; q++)
					{
						cout << "*";
					}
				}
			cout << "|" ;
		}
		for (int j = 0; j < temps[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void displayPeaks(int temps[], int n) {
	int hightTemps[15] = { 0 };
	cout << "显示峰值如下: " << endl;
	for (int i = 1; i < n-1; i++)
	{
		
		if (temps[i]>temps[i+1]&&temps[i]>temps[i-1]||temps[0]>temps[1])
		{
			hightTemps[i] = temps[i];
		}
	}
	for (int i = 0; i < 15; i++) {
		if (hightTemps[i]!=0)
		{
			cout << "Max at day " << i + 1 << " is " << hightTemps[i] << endl;
		}
	}
	
}
void displayFlat(int temps[], int n) {
	int lenght = 1;
	int MaxLenght = 0;
	for (int i = 0; i < n; i++)
	{
		if (temps[i]==temps[i+1])
		{
			lenght++;
			for (int j = i+1; j < n; j++)
			{
				if (MaxLenght < lenght)
				{
					MaxLenght = lenght;
				}
				if (temps[j] == temps[j + 1]) {
					lenght++;
				}
				else
				{
					lenght = 0;
					break;
				}
			}
		}
	}
	cout << "显示崮的长度如下：" << endl;
	cout << "The lenght of longest flat is " << MaxLenght << endl;
}
void displayMost(int temps[], int n) {
	int most = 0;
	int mostTemp = 0;
	int lenght = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (temps[i]==temps[j])
			{
				lenght++;
			}
			if (lenght > most)
			{
				most = lenght;
				mostTemp = temps[i];
			}
		}
		lenght = 1;
	}
	cout << "出现次数最多的温度是：" << mostTemp<< endl;
	cout<<"出现次数：" << most << endl;
}
int  main() {
	int temps[15];
	inputTemps(temps, 15);
	displayTemps(temps, 15);
	displayPeaks(temps, 15);
	displayFlat(temps, 15);
	displayMost(temps, 15);
	system("pause");
	return 0;
}