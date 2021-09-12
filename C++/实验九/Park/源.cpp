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
		cout << "停车场目前停放了" << this->num << "辆汽车：";
		if (this->num != 0) {
			for (int i = 0; i < this->num; i++)
			{
				cout << this->spaces[i]->getNumber() << ",";
			}
		}
		cout << "共收入" << sumMoney << "元停车费" << endl;
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
			cout << SomeCar->getNumber() << "进入停车场，分配停车位" << endl;
		}
		else {
			cout << "无法为" << SomeCar->getNumber() << "分配停车位" << endl;
		}
	}
	void leave(Automobile* SomeCar) {
		cout << SomeCar->getNumber() << "离开停车场，缴纳停车费" << SomeCar->getMoney() << "元" << endl;
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
		park->reclaimSpace(this);    // 让停车场收回停车位
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
		cout << this->getNumber() << "离开停车场，缴纳停车费" << this->getMoney() << "元" << endl;
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
		park->reclaimSpace(this);    // 让停车场收回停车位
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
		cout << this->getNumber() << "离开停车场，缴纳停车费" << this->getMoney() << "元" << endl;
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
		park->reclaimSpace(this);    // 让停车场收回停车位
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
		cout << this->getNumber() << "离开停车场，缴纳停车费" << this->getMoney() << "元" << endl;
	}
private:
	string name;
	int money = 2;
	int people = 0;
};
void main() {
	int N = 0;
	cout << "请输入停车位数量：";
	cin >> N;// 输入停车位数量，此处输入2

	Park park(N);// 创建一个停车场对象

	Automobile* auto1 = new Car("鲁B-12345", "奥迪A6");  // 创建轿车对象
	Automobile* auto2 = new Truck("鲁B-23456", 15);      // 创建卡车对象
	Automobile* auto3 = new Bus("鲁B-34567", 50);        // 公交车对象
	Automobile* auto4 = new Car("鲁B-45678", "宝马320");// 创建轿车对象

	auto1->enter(&park);   // car进入停车场，分配停车位
	auto2->enter(&park);   // truck进入停车场，分配车位
	auto1->leave(&park);   // car离开停车场，缴纳停车费
	auto3->enter(&park);   // bus进入停车场，分配车位

	/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();

	auto4->enter(&park);      // car进入停车场，分配停车位
	// car进入停车场，分配停车位。因为没有空余停车位，所以无法分配

	auto3->leave(&park);  // bus离开停车场，缴纳停车费
	auto2->leave(&park);  // truck离开停车场，缴纳停车费

	/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();

	//return 0;
}