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
		cout << "请输入Rectangle的" << "宽和高：";
		cin >> this->width >> this->height;
	}
	float getCircumference(){
		return 2 * (this->width + this->height);
	}
	void showInfo() {
		cout << "矩形 " << '\t' << "宽：" << this->width << '\t' << "高：" << this->height << '\t' << "周长： " << this->getCircumference() << endl;
	}
private:
	int width = 0;
	int height = 0;
};
class RightTriangle :public shape {
public:
	RightTriangle() {
		cout << "请输入RightTriangle的" << "两条直角边：";
		cin >> this->width >> this->height;
	}
	float getCircumference() {
		float lenght = sqrt(pow(this->height, 2) + pow(this->width, 2));
		return lenght + this->width + this->height;
	}
	void showInfo() {
		cout << "直角三角形 " << ' ' << "直角边：" << this->width << '\t'<< this->height << '\t' << "周长： " << this->getCircumference() << endl;
	}
private:
	int width = 0;
	int height = 0;
};
class Circle :public shape {
public:
	Circle() {
		cout << "请输入Circle的" << "半径：";
		cin >> this->r;
	}
	float getCircumference() {
		return pow(this->r, 2) * 3.14;
	}
	void showInfo() {
		cout << "圆 " << '\t' << "半径：" << this->r << '\t' << "周长： " << this->getCircumference() << endl;
	}
private:
	int r = 0;
};
void  showInfo1() {
	cout << "请选择框架：" << endl;
	cout << "1.矩形：" << endl;
	cout << "2.直角三角形" << endl;
	cout << "3.圆" << endl;
	cout << "-1.退出" << endl;
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