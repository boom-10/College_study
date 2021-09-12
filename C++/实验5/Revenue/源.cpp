#include<iostream>
#include<iomanip>
using namespace std;
struct Rule
{
	int money;
	int revenue;
};
void printRules(Rule* Rules,int step) {
	cout << endl;
	cout << "��˰�������£�" << endl;
	cout << "��˰��\t" << "˰��" << endl;
	for (int i = 0; i < step; i++)
	{
		cout << Rules[i].money << "\t" << Rules[i].revenue << endl;
	}
}
void countRevenue(Rule* Rules,int sum,int step) {
	int upper = 0;
	float revenue = 0;
	for (int i = 0; i < step; i++)
	{
		if (sum>=Rules[i].money)
		{
			upper = i;
		}
	}
	//cout << upper << endl;
	//revenue += 1.0;
	//cout << revenue << endl;
	if (sum <= Rules[0].money) {
		cout << "���������ǣ�0��Ӧ������˰��0.00Ԫ��" << endl;
	}
	else
	{
		if (upper==0)
		{
			revenue += (sum - Rules[upper].money) * Rules[upper].revenue * 0.01;
		}
		else
		{
			for (int i = 0; i < upper; i++)
			{
				revenue += (Rules[i + 1].money - Rules[i].money) * Rules[i].revenue * 0.01;
				//cout << revenue << endl;
			}
			revenue += (sum - Rules[upper].money) * Rules[upper].revenue * 0.01;
		}
		cout << "���������ǣ�" << sum << " , Ӧ������˰�ǣ�" << revenue << "Ԫ��" << endl;
	}
}
int main() {
	int num = 0;
	int step = 0;
	int choice = 0;
	cout << "����������������" << endl;
	cin >> num;
	Rule* Rules = new Rule[num];
	for (int i = 0; i < num; i++)
	{
		cout << "������� " << i+1 << " ������";
		cin >> Rules[i].money;
		cin >> Rules[i].revenue;
		step++;
	}
	//cout << (sizeof(Rules) / sizeof(Rules[0])) << endl;
	printRules(Rules, step);
	while (true)
	{
		cout << "�������������룺" << endl;
		cin >> choice;
		if (choice == -1) {
			cout << "�ټ�" << endl;
			break;
		}
		else
		{
			countRevenue(Rules, choice, step);
		}
	}
	return 0;
}