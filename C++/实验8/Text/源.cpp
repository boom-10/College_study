#include<iostream>
using namespace std;
class number {
private:
	int x, y;
public:
	void show() {
		cout << this->x << this->y << endl;
	}
};
void main() {
	number n;
	n.show();
}
