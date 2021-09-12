#include<iostream>
#include "Array.h"
#include<math.h>
#include<cstdlib>
#include<vector>
using namespace std;
class shape {
public:
	virtual float getCircumference() {
		return 0.1;
	}
	virtual void showInfo() {
		cout << "123" << endl;
	}
	bool operator>(shape &someshape) {
		return (this->getCircumference() < someshape.getCircumference());

	}
	bool operator<( shape &someshape) {
		return (this->getCircumference() < someshape.getCircumference());
	}
};
class Rectangle :public shape {
public:
	Rectangle() {
		cout << "������Rectangle��" << "��͸ߣ�";
		cin >> this->width >> this->height;
	}
	float getCircumference(){
		return 2 * (this->width + this->height);
	}
	void showInfo() {
		cout << "���� " << '\t' << "��" << this->width << '\t' << "�ߣ�" << this->height << '\t' << "�ܳ��� " << this->getCircumference() << endl;
	}
private:
	int width = 0;
	int height = 0;
};
class RightTriangle :public shape {
public:
	RightTriangle() {
		cout << "������RightTriangle��" << "����ֱ�Ǳߣ�";
		cin >> this->width >> this->height;
	}
	float getCircumference() {
		float lenght = sqrt(pow(this->height, 2) + pow(this->width, 2));
		return lenght + this->width + this->height;
	}
	void showInfo() {
		cout << "ֱ�������� " << ' ' << "ֱ�Ǳߣ�" << this->width << '\t'<< this->height << '\t' << "�ܳ��� " << this->getCircumference() << endl;
	}
private:
	int width = 0;
	int height = 0;
};
class Circle :public shape {
public:
	Circle() {
		cout << "������Circle��" << "�뾶��";
		cin >> this->r;
	}
	float getCircumference() {
		return pow(this->r, 2) * 3.14;
	}
	void showInfo() {
		cout << "Բ " << '\t' << "�뾶��" << this->r << '\t' << "�ܳ��� " << this->getCircumference() << endl;
	}
private:
	int r = 0;
};
void  showInfo1() {
	cout << "��ѡ���ܣ�" << endl;
	cout << "1.���Σ�" << endl;
	cout << "2.ֱ��������" << endl;
	cout << "3.Բ" << endl;
	cout << "-1.�˳�" << endl;
}
void insert(Array<shape*>&shapeArray,int n) {
	for (int i = 0; i < n; i++)
	{
		int max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (*shapeArray[max] < *shapeArray[j]) {
				max = j;
			}
		}
		shape* temp = shapeArray[i];
		shapeArray[i] = shapeArray[max];
		shapeArray[max] = temp;
	}
}
int main() {
	int choice = 0;
	Array<shape*>shapeArray(50);
	int n = 0;
	shape** ptr = NULL;
	ptr = new shape * [50];
	for (int i = 0; i < 50; i++)
	{
		shapeArray[i] = NULL;
	}
	while (choice!=-1)
	{
		showInfo1();
		cin >> choice;
		if (choice==-1)
		{
			break;
		}
		switch (choice)
		{
		case 1:
			shapeArray[n] = new Rectangle;
			n++;
			break;
		case 2:
			shapeArray[n] = new RightTriangle;
			n++;
			break;
		case 3:
			shapeArray[n] = new Circle;
			n++;
			break;
		default:
			break;
			cout << "fuck" << endl;
		}
		system("pause");
		system("cls");
	}
	cout << n << endl;
	int max = 0;
	insert(shapeArray, n);
	for (int i = 0; i <n; i++)
	{
		if (shapeArray[i])
		{
			shapeArray[i]->showInfo();
		}
	}
}