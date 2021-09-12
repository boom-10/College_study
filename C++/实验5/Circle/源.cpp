#include<iostream>
using namespace std;
struct Point
{
	int x;
	int y;
};
void displayMenu() {
	cout << "***************" << endl;
	cout << "***1.Circle****" << endl;
	cout << "***2.Rectangle*" << endl;
	cout << "***0.exit******" << endl;
	cout << "***************" << endl;
	cout << "请选择图形：";
}
int getTwoPoints(struct Point *startP, struct Point * endP) {
	cout << "请确保输入的坐标均为正数！" << endl;
	cout << "请输入起始坐标的（x，y）坐标：" << endl;
	cin >> (*startP).x;
	cin >> startP->y;
	cout<<"请输入最终坐标的（x，y）坐标：" << endl;
	cin >> endP->x;
	cin >> endP->y;
	if (endP->y<=startP->y||endP->x<=startP->x)
	{
		cout << "输入坐标有误，请确保最终坐标比起始坐标大后重新输入！" << endl;
		return 0;
	}
}
//void printPoint(struct startP*) {
//
//}
int drawCircle(struct Point* startP, struct Point* endP) {
	if (endP->x-startP->x!=endP->y-startP->y)
	{
		cout << "您的输入并不是一个圆，请重新输入！" << endl;
		return 0;
	}
	else
	{
		cout << "圆心坐标为：(" << (endP->x +startP->x)/2 << "," << (endP->y + startP->y)/2 << ")" << "圆的半径为：" << (endP->x - startP->x) / 2 << endl;
	}
}
int drawRectangle(struct Point* startP, struct Point* endP) {
	if (endP->x - startP->x == endP->y - startP->y)
	{
		cout << "这是一个正方形，它的边长是：" << endP->x - startP->x << endl;
		return 0;
	}
	cout << "长方形的长是：" << endP->x - startP->x << " 宽是：" << endP->y - startP->y << endl;
}
int main() {
	int choice=1;
	struct Point startP, endP;
	while (choice) {
		displayMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (getTwoPoints(&startP, &endP) != 0) {
				drawCircle(&startP, &endP);
			};
			system("pause");
			system("cls");
			break;
		case 2:
			if (getTwoPoints(&startP, &endP) != 0) {
				drawRectangle(&startP, &endP);
			};
			//drawRectangle(&startP, &endP);
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			exit(0);
			break;
		default:
			cout << "输入错误请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
