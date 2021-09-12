#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Date {
public:
	/* Ĭ�Ϲ��캯������fullyear����ʽ���������գ�Ĭ��ֵΪ1990��1��1�գ�ͬʱ�������ڷָ���Ϊ��-�� */
	Date(int year = 1990, int month = 1, int day = 1) {
		this->year = year;
		this->day = day;
		this->month = month;
	}
	/* get��set���� */
	// �������ڣ�����зǷ����»��գ�������Ϊ1
	void setDate(int year, int month, int day) {
		this->year = year;
		this->day = day;
		this->month = month;
	}
	void setYear(int year) {
		this->year = year;
	}
	int getYear() {
		return this->year;
	}
	void setMonth(int month) {
		this->month = month;
	}
	int getMonth() {
		return this->month;
	}
	void setDay(int day) {
		this->day = day;
	}
	int getDay() {
		return this->day;
	}
	void setSeparator(char separator) {
		this->separator = separator;
	}

	/* �����������ʹ��setfill(��0��)��setw(2)����Ҫ����<iomanip>ͷ�ļ� */
	void printFullYear() {
		cout << this->year << this->separator << setfill('0') << setw(2) << this->month << this->separator << setfill('0') << setw(2) << this->day << endl;
	}      // ��YYYY-MM-DD����ʽ��ӡ��2011-01-08
	void printStandardYear() {
		cout << this->year % 100 << this->separator << setfill('0') << setw(2) << this->month << this->separator << setfill('0') << setw(2) << this->day << endl;
	} // ��YY-MM-DD����ʽ��ӡ������11-01-08
	/*  ���㺯��  */
	// ���㵱ǰ�������������֮���������꣬�����ǲ������ڱȵ�ǰ����������
	int fullYearsTo(Date& date) {
		int wholeYear = date.year - this->year;
		if (this->month < date.month) {
			//cout << wholeYear;
		}
		else
		{
			wholeYear--;
			//cout << wholeYear;
		}
		return wholeYear;
		cout << " ��" << wholeYear << "����" << endl;
	};
	/* ���㵱ǰ�������������֮����������(��������)��������������ڵ�ǰ����֮ǰ�����ظ����� */
	int daysTo(Date& date) {
		int run = 0;
		int days = 0;
		if (date.year < this->year)
		{
			for (int i = date.year; i <= this->year; i++)
			{
				if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) {
					run++;
				}
			}
			days = wholeMonth[month] - date.day;
			for (int i = date.month + 1; i < 13; i++)
			{
				days += wholeMonth[i];
			}
			//cout << days<< endl;
			days += (this->year - date.year - 1) * 365 + run;
			for (int i = 1; i < this->month; i++)
			{
				days += wholeMonth[i];
			}
			days += this->day;
			//cout << "-" << days << endl;
			return -days;
		}
		else
		{
			for (int i = date.year; i >= this->year; i--)
			{
				if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) {
					run++;
				}
			}
			//int wholeMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
			days = wholeMonth[this->month] - this->day;
			for (int i = this->month + 1; i < 13; i++)
			{
				days += wholeMonth[i];
			}
			days += (date.year - this->year - 1) * 365 + run;
			for (int i = 1; i < date.month; i++)
			{
				days += wholeMonth[i];
			}
			days += date.day;
			//cout << "-" << days << endl;
			return days;
		}

	}
	int getDayOfYear() {
		int days = 0;
		for (int i = 0; i < this->month; i++)
		{
			days += wholeMonth[i];
		}
		if (month>2)
		{
			if (isLeapyear(this->year))
			{
				days++;
			}
		}
		return days;
	}  //���㵱ǰ�����Ǳ���ĵڼ���
	int getLeftDaysYear() {
		if (isLeapyear(this->year))
		{
			return 366 - this->getDayOfYear();
		}
		return 365 - this->getDayOfYear();
	}//���㵱ǰ���ھ౾��������м��죬��������ǰ������һ��
	bool isLeapyear(int year1) {
		if (year1 % 400 == 0 || year1 % 4 == 0 && year1 % 100 != 0) {
			return true;
		}
		return false;
	}//�ϲ������Ƿ������ꡣ
private:
	int year;
	int month;
	int day;
	char separator = '-';  // ���ڷָ�����
	static int wholeMonth[13];
};
int Date::wholeMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
class Employee {
public:
	//���캯����ʹ�á���Ա��ʼ��������ʼ�����ݳ�Ա
	Employee(string firstName, string lastName, Date& birthDate, Date& hireDate) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->birthDate = birthDate;
		this->hireDate = hireDate;
	}
	//��ӡԱ������Ϣ������Date���print��������ӡԱ�������պ͹�Ӷ���ڡ�
	void print() {
		cout << this->firstName << ' ' << this->lastName << "'s birthDate and HireDate: " << endl;
		this->birthDate.printFullYear();
		this->hireDate.printFullYear();
	}
	//����Ա���ڲ���ָ��������ʱ���������ꡣ��ʹ��Date���fullYearsTo����
	int getAge(Date& date) {
		return this->birthDate.fullYearsTo(date);
	}
	//�����Ա���ڲ���ָ��������ʱ���������˶����ꡣ
	int getYearsWorked(Date& date) {
		return this->hireDate.fullYearsTo(date);
	}
	//�����Ա���ڲ���ָ��������ʱ�������˶����졣ʹ��Date���daysTo������
	int getDaysWorked(Date& date) {
		return this->hireDate.daysTo(date);
	}
	//~Employee();   //��������
private:
	string firstName;
	string lastName;
	Date birthDate;    //��Ƕ���󣬳�������
	Date hireDate;     //��Ƕ���󣬹�������
};
void main() {
	Date birth(1969, 8, 11);
	Date hire(1998, 4, 1);
	Date today(2010, 4, 30);
	Employee manager("Bob", "Blue", birth, hire);
	cout << endl;
	manager.print();
	cout << endl;
	cout << manager.getAge(today) << endl;
	cout << manager.getDaysWorked(today) << endl;
}