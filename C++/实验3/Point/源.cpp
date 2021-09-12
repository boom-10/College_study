#include<iostream>
using namespace std;
class Point {
public:
	// Ĭ�Ϲ��캯����Ĭ��ֵΪ���Ͻ�����(0, 0)
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
	Point p1(x, y);            // ���ɵ����1
	cout << "Point p1: ";
	p1.print();
	cout << endl;
	Point p2(x * 2, y * 2); //���ɵ����2
	cout << "Point p2: ";
	p2.print();
	cout << endl;
	p1.moveRight(10);
	cout << "After moving right, p1: ";
	p1.print();
	cout << endl;
	p2.moveDown(-10);        // λ����Ϊ��������ʾ�����ƶ�
	cout << "After moving down, p2: ";
	p2.print();
	cout << endl;
}