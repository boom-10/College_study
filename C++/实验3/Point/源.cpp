#include<iostream>
using namespace std;
class Point {
public:
	// 默认构造函数，默认值为左上角坐标(0, 0)
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	};
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void print();
	void moveRight(int offset);
	void moveDown(int offset);
private:
	int x;
	int y;
};
int Point::getX() {
	return this->x;
}
int Point::getY() {
	return this->y;
}
void Point::setX(int x) {
	this->x = x;
}
void Point::setY(int y) {
	this->y = y;
}
void Point::print() {
	cout << "( " << this->x << " , " << this->y << " )";
}
void Point::moveRight(int offset) {
	this->x += offset;
}
void Point::moveDown(int offset) {
	this->y += offset;
}
void main() {
	int x, y;
	cout << "Please input a point: ";
	cin >> x >> y;
	Point p1(x, y);            // 生成点对象1
	cout << "Point p1: ";
	p1.print();
	cout << endl;
	Point p2(x * 2, y * 2); //生成点对象2
	cout << "Point p2: ";
	p2.print();
	cout << endl;
	p1.moveRight(10);
	cout << "After moving right, p1: ";
	p1.print();
	cout << endl;
	p2.moveDown(-10);        // 位移量为负数，表示向上移动
	cout << "After moving down, p2: ";
	p2.print();
	cout << endl;
}