#include<iostream>
using namespace std;
#include<string>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

const int MAX_TYPE = 62;

//class TravelWay {
//public:
//	TravelWay(int Destination){
//		this->Destination = Destination;
//	}
//	int Destination = 0;
//};

class Team{
public:
	Team(int Destination) {
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
private:
	int Destination = 0;
	int num = 0;
};

Team *team;

class Luggage
{
public:
	Luggage() {

	}
	string getName() {
		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}
	Luggage(string name) {
		this->name = name;;
	};
	~Luggage();

private:
	string name;
};

class TicketOffice {
public:
	TicketOffice(int type) {
		if (type==1)
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
class Passenger
{
public:
	Passenger(string name, int LuaggageNum, int Destination,int TravelWay) {
		this->name = name;
		this->LuaggageNum = LuaggageNum;
		this->Destination = Destination;
		this->TravelWay = TravelWay;
		if (this->TravelWay==0)
		{
			this->ChoseTravelWay = "旅行社";
			for (int i = 0; i < 5; i++)
			{
				if (team[i].getDestination() == this->Destination&&team[i].getNum()<6) {
					team[i].AddNum();
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
		this->money = this->ticket->getMoney();
		if (this->LuaggageNum<2&&this->Destination==3)
		{
			this->money = 500;
		}
		else
		{
			this->money += this->LuaggageNum * 100;
		}
		return this->money;
	}
	void report() {
		cout << "我是乘客" << this->name << "选择" << this->ChoseTravelWay << "携带" << this->ticket->getDestination() << "行李，行李编号是";
		for (int  i = 0; i < this->LuaggageNum; i++)
		{
			cout<<this->MyLuggage[i].
		}
	}
	void coutLuggage() {
		string namesand = {'1','2','3'};
		this->MyLuggage = new Luggage[this->LuaggageNum];
		for (int i = 0; i < this->LuaggageNum; i++)
		{
			string LuggageName = this->name;
			LuggageName += '0';
			LuggageName += namesand[i];
			MyLuggage[i].setName(LuggageName);
		}
	}
	~Passenger();

private:
	string name;
	int LuaggageNum = 0;
	int Destination = 0;
	int money = 0;
	int TravelWay = 0;
	string ChoseTravelWay;
	TicketOffice* ticket = NULL;
	Luggage* MyLuggage = NULL;
};

int main() {
	srand(static_cast<unsigned> (time(NULL)));		// 初始化随机数发生器
	int number = rand();
	int remainder = number % MAX_TYPE;
}
