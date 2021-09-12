#include<iostream>
using namespace std;
#include<string>
int main() {
	while (true)
	{
		int step = 0;
		cin >> step;
		if (step == 0)break;
		int flool[100] = { 0 };
		int up = 0;
		int down = 0;
		int stop = 0;
		string list;
		for (int i = 0; i < step; i++)
		{
			cin >> flool[i];
			if (i == 0) {
				int firstMove = flool[0] - 0;
				up = firstMove * 6 + 5;
			}
			else
			{
				int nowStep = flool[i] - flool[i - 1];
				if (nowStep > 0)
				{
					up += nowStep * 6 + 5;
				}
				else if (nowStep == 0) {
					down += 0;
				}
				else {
					down += -(nowStep) * 4 + 5;
				}
			}
		}
			cout << down + up;
			for (int i = 0; i < step; i++) {
				if (i == 0) {
					cout << "(" << "6 * " << flool[0] - 0 << " + 5";
				}
				else
				{
					int coutStep = flool[i] - flool[i - 1];
					if (coutStep > 0)
					{
						cout << " + 6 * " << flool[i] - flool[i - 1] << " + 5";
					}
					else
					{
						if (down != 0) {
							cout << " + 4 * " << -(flool[i] - flool[i - 1]) << " + 5";
						}
					}
				}
			}
			cout << ")" << endl;
			
		}
	   system("pause");
	   return 0;
}