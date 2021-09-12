#include<iostream>
#include<string>
using namespace std;
class Park;
class Automobile {
public:
	virtual void enter(Park* park) {

	}
	virtual void leave(Park* park) {

	}
	virtual  string getNumber() {
		return this->name;
	}
	virtual int getMoney() {
		return this->money;
	}
private:
	string name;
	int money;
};
class Park {
public:
	Park(int N) {
		this->spaces = new Automobile * [N];
		for (int i = 0; i < N; i++)
		{
			this->spaces[i] = NULL;
		}
		this->Max = N;
	}
	void showInfo() {
			cout << "ͣ����Ŀǰͣ����" << this->num << "��������";
			if (this->num != 0) {
				for (int i = 0; i < this->num; i++)
				{
					cout << this->spaces[i]->getNumber() << ",";
				}
			}
			cout << "������" << sumMoney << "Ԫͣ����" << endl;
	}
	void enter(Automobile *SomeCar) {
		if (this->num<this->Max)
		{
			for (int i = 0; i < this->Max; i++) {
				if (this->spaces[i]==NULL)
				{
					this->spaces[i] = SomeCar;
					this->num++;
					break;
				}
			}
			cout << SomeCar->getNumber() << "����ͣ����������ͣ��λ" << endl;
		}
		else {
			cout << "�޷�Ϊ" << SomeCar->getNumber() << "����ͣ��λ" << endl;
		}
	}
	void leave(Automobile* SomeCar) {
		cout << SomeCar->getNumber() << "�뿪ͣ����������ͣ����" << SomeCar->getMoney() << "Ԫ" << endl;
		for (int i = 0; i < this->Max; i++)
		{
			if (this->spaces[i] == SomeCar) {
				this->spaces[i] = NULL;
				this->num--;
			}
		}
		sumMoney += SomeCar->getMoney();
	}
	~Park() {
		delete[] this->spaces;
	}
private:
	Automobile** spaces;
	int num = 0;
	int Max;
	int sumMoney = 0;
};
class Truck :public Automobile {
public:
	Truck(string name,int weight) {
		this->name = name;
		this->weight = weight;
	}
	void enter(Park* park) {
		park->enter(this);
	}
	void leave(Park* park) {
		park->leave(this);
	}
	string getNumber() {
		return this->name;
	}
	int getMoney() {
		return this->money;
	}
private:
	string name;
	int money = 3;
	int weight = 0;
};
class Car :public Automobile {
public:
	Car(string name, string type) {
		this->name = name;
		this->type = type;
	}
	void enter(Park* park) {
		park->enter(this);
	}
	void leave(Park* park) {
		park->leave(this);
	}
	string getNumber() {
		return this->name;
	}
	int getMoney() {
		return this->money;
	}
private:
	string name;
	int money = 1;
	string type;
};
class Bus :public Automobile {
public:
	Bus(string name, int people) {
		this->name = name;
		this->people = people;
	}
	void enter(Park* park) {
		park->enter(this);
	}
	void leave(Park* park) {
		park->leave(this);
	}
	string getNumber() {
		return this->name;
	}
	int getMoney() {
		return this->money;
	}
private:
	string name;
	int money = 2;
	int people = 0;
};
void main() {
	int N = 0;
	cout << "������ͣ��λ������";
	cin >> N;// ����ͣ��λ�������˴�����2

	Park* park = new Park(N);// ����һ��ͣ��������

	Car car1("³B-12345", "�µ�A6");  // �����γ�����
	car1.enter(park);    // car1����ͣ����������ͣ��λ

	Truck truck("³B-23456", 15);  // ������������
	truck.enter(park);   // truck����ͣ���������䳵λ

	car1.leave(park);   // car1�뿪ͣ����������ͣ����

	Bus bus("³B-34567", 50);  // ��������������
	bus.enter(park);   // bus����ͣ���������䳵λ

	/* ��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park->showInfo();

	Car car2("³B-45678", "����320");  // �����γ�����
	car2.enter(park);
	// car2����ͣ����������ͣ��λ����Ϊû�п���ͣ��λ�������޷�����

	bus.leave(park);  // bus�뿪ͣ����������ͣ����
	truck.leave(park);  // truck�뿪ͣ����������ͣ����

	/* ��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park->showInfo();
	delete park;

	//return 0;
}