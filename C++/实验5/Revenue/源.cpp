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
	cout << "纳税规则如下：" << endl;
	cout << "纳税线\t" << "税率" << endl;
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
		cout << "您的收入是：0，应缴所得税：0.00元。" << endl;
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
		cout << "您的收入是：" << sum << " , 应交所得税是：" << revenue << "元。" << endl;
	}
}
int main() {
	int num = 0;
	int step = 0;
	int choice = 0;
	cout << "请输入规则的条数：" << endl;
	cin >> num;
	Rule* Rules = new Rule[num];
	for (int i = 0; i < num; i++)
	{
		cout << "请输入第 " << i+1 << " 条规则：";
		cin >> Rules[i].money;
		cin >> Rules[i].revenue;
		step++;
	}
	//cout << (sizeof(Rules) / sizeof(Rules[0])) << endl;
	printRules(Rules, step);
	while (true)
	{
		cout << "请输入您的收入：" << endl;
		cin >> choice;
		if (choice == -1) {
			cout << "再见" << endl;
			break;
		}
		else
		{
			countRevenue(Rules, choice, step);
		}
	}
	return 0;
}