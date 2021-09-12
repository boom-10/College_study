#include<iostream>
using namespace std;
#include<string>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include<vector>
#include<iomanip>

const int MAX_TYPE = 62;

//class TravelWay {
//public:
//	TravelWay(int Destination){
//		this->Destination = Destination;
//	}
//	int Destination = 0;
//};
class TicketOffice {
public:
	TicketOffice(int type) {
		if (type == 1)
		{
			this->Destination = "DomesticShort";
			this->money = 10;
		}
		else if (type == 2) {
			this->Destination = "DomesticLong";
			this->money = 100;
		}
		else if (type == 3) {
			this->Destination = "International";
			this->money = 500;
		}
	}
	int getMoney() {
		return this->money;
	}
	string getDestination() {
		return this->Destination;
	}
private:
	int type = 0;
	string Destination;
	int money = 0;
};

class Team {
public:
	Team() {

	}
	Team(int Destination) {
		this->Destination = Destination;
	}
	void setDestination(int Destination) {
		this->Destination = Destination;
	}
	int getDestination() {

		return this->Destination;
	}
	void AddNum() {
		this->num++;
	}
	int getNum() {
		return this->num;
	}
	string getDestinationName() {
		this->ticket = new TicketOffice(this->Destination);
		return this->ticket->getDestination();
	}
	int SumMoney() {
		int money = this->num * this->ticket->getMoney();
		return money ;
	}
	int getMoney() {
		int money = this->ticket->getMoney();
		return money;
	}
	~Team() {
		if (this->ticket!=NULL)
		{
			this->ticket = NULL;
		}
	}
private:
	int Destination = 0;
	int num = 0;
	TicketOffice* ticket = NULL;
};

Team team[5];

class Luggage
{
public:
	string getName() {
		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}
	//Luggage(string name) {
	//	this->name = name;;
	//};
	//~Luggage();

private:
	string name;
};


class Passenger
{
public:
	Passenger(char name, int LuaggageNum, int Destination, int TravelWay) {
		this->name = name;
		this->LuaggageNum = LuaggageNum;
		this->Destination = Destination;
		this->TravelWay = TravelWay;
		if (this->TravelWay == 0)
		{
			this->ChoseTravelWay = "旅行社";
			for (int i = 0; i < 5; i++)
			{
				if (team[i].getDestination() == this->Destination && team[i].getNum() < 6) {
					team[i].AddNum();
					this->isteam = true;
					break;
				}
			}
		}
		else
		{
			this->ChoseTravelWay = "自由行";
		}
		this->ticket = new TicketOffice(this->Destination);
	};
	int countMoney() {
		//this->money = this->ticket->getMoney();
		if (this->LuaggageNum <= 2 && this->Destination == 3)
		{
			this->money = 0;
		}
		else if (this->LuaggageNum == 3 && this->Destination == 3) {
			this->money = 100;
		}
		else
		{
			this->money += this->LuaggageNum * 100;
		}
		return this->money;
	}
	void report() {
		this->coutLuggage();
		cout << "我是乘客" << this->name << ",选择" << this->ChoseTravelWay<<",目的地："<< this->ticket->getDestination()<< "\t携带" <<this->LuaggageNum<< "件行李，行李编号是";
		for (int i = 0; i < this->LuaggageNum; i++)
		{
			cout << this->MyLuggage[i].getName();
		}
		cout << "\t买票需付" << this->ticket->getMoney() << "\t行李托运费" << this->countMoney() << "元" << endl;
	}
	int getMoney() {
		return this->ticket->getMoney();
	}
	char getName() {
		return this->name;
	}
	void coutLuggage() {
		string namesand = { '1','2','3' };
		this->MyLuggage = new Luggage[this->LuaggageNum];
		for (int i = 0; i < this->LuaggageNum; i++)
		{
			string LuggageName = "0";
			LuggageName[0]= this->name;
			LuggageName += '0';
			LuggageName += namesand[i];
			MyLuggage[i].setName(LuggageName);
		}
	}
	int getDestination() {
		return this->Destination;
	}
	bool getIsteam() {
		return this->isteam;
	}
	~Passenger() {
		if (this->ticket!=NULL||this->MyLuggage!=NULL)
		{
			this->ticket = NULL;
			this->MyLuggage = NULL;
		}
	}

private:
	char name;
	int LuaggageNum = 0;
	int Destination = 0;
	int money = 0;
	int TravelWay = 0;
	bool isteam = false;
	string ChoseTravelWay;
	TicketOffice* ticket = NULL;
	Luggage* MyLuggage = NULL;
};

int main() {
	srand(static_cast<unsigned> (time(NULL)));		// 初始化随机数发生器
	int PassengerNum = (rand() % (62)) + 1;
	//int PassengerNum = 10;
	int LuggageNum = (rand() % (3)) + 1;
	//int remainder = number % MAX_TYPE;
	int DestinationNum= (rand() % (3)) + 1;
	int TravelWayNum = PassengerNum % 2;
	string PassengerNameSand = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	string name = "Aa";
	vector<Passenger>PassengerContainer1;
	vector<Passenger>PassengerContainer2;
	vector<Passenger>PassengerContainer3;
	vector<Passenger>PassengerContainer4;
	vector<Passenger>PassengerContainer5;
	vector<Passenger>PassengerContainer6;
	/*Passenger p1('A', 1, 1, 1);
	p1.report();*/
	//Team teams[5];
	for (int i = 0; i < 5; i++)
	{
		int x = i+1;
		if (x>3)
		{
			x -= 3;
		}
		team[i].setDestination((rand() % (3)) + 1);
	}
	/*team = teams;*/
	for (int i = 0; i < PassengerNum; i++)
	{
		//PassengerNum = (rand() % (62)) + 1;
		LuggageNum = (rand() % (3)) + 1;
		DestinationNum = (rand() % (3)) + 1;
		TravelWayNum = LuggageNum % 2;
		char PassengerName = PassengerNameSand[i];
		Passenger Randpassenger(PassengerName, LuggageNum, DestinationNum, TravelWayNum);
		if (Randpassenger.getDestination()==1&&!Randpassenger.getIsteam())
		{
			PassengerContainer1.push_back(Randpassenger);
		}
		else if (Randpassenger.getDestination() == 2 && !Randpassenger.getIsteam()) {
			PassengerContainer2.push_back(Randpassenger);
		}
		else if (Randpassenger.getDestination() == 3 && !Randpassenger.getIsteam()) {
			PassengerContainer3.push_back(Randpassenger);
		}
		else if (Randpassenger.getDestination() == 1 && Randpassenger.getIsteam()) {
			PassengerContainer4.push_back(Randpassenger);
		}
		else if (Randpassenger.getDestination() == 2 && Randpassenger.getIsteam()) {
			PassengerContainer5.push_back(Randpassenger);
		}
		else if (Randpassenger.getDestination() == 3 && Randpassenger.getIsteam()) {
			PassengerContainer6.push_back(Randpassenger);
		}
		Randpassenger.report();
	}
	cout << "……\n……" << endl;
	cout << "旅行社开始报名。" << endl;
	cout << "旅行社共计安排了5个旅行团，共计" <<PassengerContainer4.size() + PassengerContainer5.size() + PassengerContainer6.size()<< "人报名。" << endl;
	cout << "出行的目的地分别是:" << "\t人数：" << "\t票价："<< endl;
	/*for (int i = 0; i < 5; i++)
	{
		cout << teams[i].getDestinationName() << '\t' << team[i].getNum() << '/t' << team[i].SumMoney() << endl;
	}
	/*Passenger p2('B', 2, 2, 0);
	p2.report();
	Passenger p3('C', 2, 3, 0);
	p3.report();*/
	for (int i = 0; i < 5; i++)
	{
		cout << team[i].getDestinationName();
		cout <<setfill(' ') << setw(7)<<'\t'<<" "<<  team[i].getNum() <<'\t';
		cout << team[i].getMoney() <<'\t';
		cout << endl;
	}
	cout << "售票处开始售票。\n售票结束，营业额统计信息如下：" << endl;
	cout << "国内短途自由行:"; 
	if (PassengerContainer1.empty())
	{
		cout <<'\t'<< "0";
	}
	else {
		cout << '\t' << PassengerContainer1.size() * PassengerContainer1[0].getMoney();
	}
	cout << "元" << "\t乘客姓名：";
	if (!PassengerContainer1.empty())
	{
		for (int i = 0; i < PassengerContainer1.size(); i++)
		{
			cout << PassengerContainer1[i].getName() << ' ';
		}
	}
	cout << endl;
	cout << "国内长途自由行:";
	if (PassengerContainer2.empty())
	{
		cout << '\t' << "0";
	}
	else {
		cout << '\t' << PassengerContainer2.size() * PassengerContainer2[0].getMoney();
	}
	cout << "元" << "\t乘客姓名：";
	if (!PassengerContainer2.empty())
	{
		for (int i = 0; i < PassengerContainer2.size(); i++)
		{
			cout << PassengerContainer2[i].getName() << ' ';
		}
	}
	cout << endl;
	cout << "国际游自由行:";
	if (PassengerContainer3.empty())
	{
		cout << '\t' << "0";
	}
	else {
		cout << '\t' << PassengerContainer3.size() * PassengerContainer3[0].getMoney();
	}
	cout << "元" << "\t乘客姓名：";
	if (!PassengerContainer3.empty())
	{
		for (int i = 0; i < PassengerContainer3.size(); i++)
		{
			cout << PassengerContainer3[i].getName() << ' ';
		}
	}
	cout << endl;
	cout << "国内短途团购:";
	if (PassengerContainer4.empty())
	{
		cout << '\t' << "0";
	}
	else {
		cout << '\t' << PassengerContainer4.size() * PassengerContainer4[0].getMoney();
	}
	cout << "元" << "\t乘客姓名：";
	if (!PassengerContainer4.empty())
	{
		for (int i = 0; i < PassengerContainer4.size(); i++)
		{
			cout << PassengerContainer4[i].getName() << ' ';
		}
	}
	cout << endl;
	cout << "国内长途团购:";
	if (PassengerContainer5.empty())
	{
		cout << '\t' << "0";
	}
	else {
		cout << '\t'<< PassengerContainer5.size() * PassengerContainer5[0].getMoney();
	}
	cout << "元"<<"\t乘客姓名：";
	if (!PassengerContainer5.empty())
	{
		for (int i = 0; i < PassengerContainer5.size(); i++)
		{
			cout << PassengerContainer5[i].getName() << ' ';
		}
	}
	cout << endl;
	cout << "国际游团购:";
	if (PassengerContainer6.empty())
	{
		cout << '\t' << "0";
	}
	else {
		cout << '\t' << PassengerContainer6.size() * PassengerContainer6[0].getMoney();
	}
	cout << "元" << "\t乘客姓名：";
	if (!PassengerContainer6.empty())
	{
		for (int i = 0; i < PassengerContainer6.size(); i++)
		{
			cout << PassengerContainer6[i].getName() << ' ';
		}
	}
	cout << endl;
}
