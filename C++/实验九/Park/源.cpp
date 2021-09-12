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
protected:
	virtual void pay(Park& park) = 0;
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
	void enter(Automobile* SomeCar) {
		if (this->num < this->Max)
		{
			for (int i = 0; i < this->Max; i++) {
				if (this->spaces[i] == NULL)
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
	void reclaimSpace(Automobile* Somecar) {
		for (int i = 0; i < this->Max; i++)
		{
			if (this->spaces[i] == Somecar) {
				this->spaces[i] = NULL;
				this->num--;
			}
		}
	}
	void getpaid(int money) {
		this->sumMoney += money;
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
	Truck(string name, int weight) {
		this->name = name;
		this->weight = weight;
	}
	void enter(Park* park) {
		park->enter(this);
	}
	void leave(Park* park) {
		park->reclaimSpace(this);    // ��ͣ�����ջ�ͣ��λ
		pay(*park);
		//park->leave(this);
	}
	string getNumber() {
		return this->name;
	}
	int getMoney() {
		return this->money;
	}
protected:
	void pay(Park& park) {
		park.getpaid(3);
		cout << this->getNumber() << "�뿪ͣ����������ͣ����" << this->getMoney() << "Ԫ" << endl;
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
		park->reclaimSpace(this);    // ��ͣ�����ջ�ͣ��λ
		pay(*park);
		//park->leave(this);
	}
	string getNumber() {
		return this->name;
	}
	int getMoney() {
		return this->money;
	}
protected:
	void pay(Park& park) {
		park.getpaid(1);
		cout << this->getNumber() << "�뿪ͣ����������ͣ����" << this->getMoney() << "Ԫ" << endl;
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
		park->reclaimSpace(this);    // ��ͣ�����ջ�ͣ��λ
		pay(*park);
		//park->leave(this);
	}
	string getNumber() {
		return this->name;
	}
	int getMoney() {
		return this->money;
	}
protected:
	void pay(Park& park) {
		park.getpaid(2);
		cout << this->getNumber() << "�뿪ͣ����������ͣ����" << this->getMoney() << "Ԫ" << endl;
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

	Park park(N);// ����һ��ͣ��������

	Automobile* auto1 = new Car("³B-12345", "�µ�A6");  // �����γ�����
	Automobile* auto2 = new Truck("³B-23456", 15);      // ������������
	Automobile* auto3 = new Bus("³B-34567", 50);        // ����������
	Automobile* auto4 = new Car("³B-45678", "����320");// �����γ�����

	auto1->enter(&park);   // car����ͣ����������ͣ��λ
	auto2->enter(&park);   // truck����ͣ���������䳵λ
	auto1->leave(&park);   // car�뿪ͣ����������ͣ����
	auto3->enter(&park);   // bus����ͣ���������䳵λ

	/* ��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park.showInfo();

	auto4->enter(&park);      // car����ͣ����������ͣ��λ
	// car����ͣ����������ͣ��λ����Ϊû�п���ͣ��λ�������޷�����

	auto3->leave(&park);  // bus�뿪ͣ����������ͣ����
	auto2->leave(&park);  // truck�뿪ͣ����������ͣ����

	/* ��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park.showInfo();

	//return 0;
}