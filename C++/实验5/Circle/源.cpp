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
	cout << "��ѡ��ͼ�Σ�";
}
int getTwoPoints(struct Point *startP, struct Point * endP) {
	cout << "��ȷ������������Ϊ������" << endl;
	cout << "��������ʼ����ģ�x��y�����꣺" << endl;
	cin >> (*startP).x;
	cin >> startP->y;
	cout<<"��������������ģ�x��y�����꣺" << endl;
	cin >> endP->x;
	cin >> endP->y;
	if (endP->y<=startP->y||endP->x<=startP->x)
	{
		cout << "��������������ȷ�������������ʼ�������������룡" << endl;
		return 0;
	}
}
//void printPoint(struct startP*) {
//
//}
int drawCircle(struct Point* startP, struct Point* endP) {
	if (endP->x-startP->x!=endP->y-startP->y)
	{
		cout << "�������벢����һ��Բ�����������룡" << endl;
		return 0;
	}
	else
	{
		cout << "Բ������Ϊ��(" << (endP->x +startP->x)/2 << "," << (endP->y + startP->y)/2 << ")" << "Բ�İ뾶Ϊ��" << (endP->x - startP->x) / 2 << endl;
	}
}
int drawRectangle(struct Point* startP, struct Point* endP) {
	if (endP->x - startP->x == endP->y - startP->y)
	{
		cout << "����һ�������Σ����ı߳��ǣ�" << endP->x - startP->x << endl;
		return 0;
	}
	cout << "�����εĳ��ǣ�" << endP->x - startP->x << " ���ǣ�" << endP->y - startP->y << endl;
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
			cout << "��ӭ�´�ʹ�ã�" << endl;
			exit(0);
			break;
		default:
			cout << "����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
