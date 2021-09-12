#include<iostream>
#include<iomanip>
using namespace std;
class Account {
public:
	virtual void credit(int money) {

	}
	virtual void debit(int money) {

	}
	virtual double getBalance() {
		return this->balance;
	}
private:
	double balance = 0.0;
};
class SavingsAccount :public Account {
public:
	double getBalance() {
		return this->balance;
	}
	void credit(int money) {
		this->balance += money;
		//this->balance += this->interestRate * this->balance;
		//cout << this->balance << endl;
	}
	void debit(int money) {
		if (this->balance < money)
		{
			cout << "Debit amount exceeded account balance" << endl;
		}
		else
		{
			this->balance -= money;
			//this->balance += this->balance * this->interestRate;
			//cout << "取出后" << this->balance << endl;
		}
	}
	SavingsAccount(double banlance, double intersetRate) {
		//cout << banlance << endl;
		this->interestRate = intersetRate / 100;
		//cout << this->interestRate << endl;
		this->balance = banlance;
		//cout << this->balance << endl;
	}
	double calculateInterest() {
		this->balance += this->balance * this->interestRate;
		return this->balance * this->interestRate;
	}
private:
	double interestRate = 0.0;
	double balance = 0.0;
};
class CheckingAccount :public Account {
public:
	CheckingAccount(int balance, int service) {
		this->balance = balance;
		this->service = service;
	}
	void credit(int money) {
		if ((this->balance) - this->service >= 0)
		{
			this->balance -= this->service;
			this->balance += money;
		}
		else {
			cout << "Transaction fee exceeded account balance while crediting" << endl;
		}
	}
	void debit(int money) {
		if ((this->balance) - money >= 0)
		{
			if (this->balance-money-this->service>=0)
			{
				this->balance -= this->service;
				this->balance -= money;
			}
			else
			{
				cout << "Transaction fee exceeded account balance while debiting" << endl;
			}
			
			//cout << "leave money: " << this->balance << endl;
		}
		else {
			cout << "Debit amount exceeded account balance" << endl;
		}
	}
	double getBalance() {
		return this->balance;
	}
private:
	double balance = 0.0;
	double service = 0.0;
};
int main() {
	Account* accounts[3];
	accounts[0] = new SavingsAccount(100, 3);   //余额100元，利息3%
	accounts[1] = new CheckingAccount(100, 5);  //余额100元，交易费5元
	accounts[2] = new CheckingAccount(50, 5);   //余额50元，交易费5元

	for (int i = 0; i < 3; i++) {
		cout << "第" << i + 1 << "次循环的结果：" << endl;
		accounts[i]->debit(200);   //借款200元
		accounts[i]->debit(40);
		accounts[i]->credit(50);   //存款50元
		accounts[i]->debit(49);
		accounts[i]->debit(43);
		accounts[i]->credit(1);
		//将Account指针强制转换为SavingAccount指针
		SavingsAccount* derivedPtr =
			dynamic_cast<SavingsAccount*>(accounts[i]);
		if (derivedPtr != NULL)   //如果类型兼容，转换成功
			derivedPtr->credit(derivedPtr->calculateInterest());
		cout << fixed << setprecision(2);   //使用定点数格式，2位小数部分
		cout << "账户的余额为：" << accounts[i]->getBalance() << endl;
	}
}
