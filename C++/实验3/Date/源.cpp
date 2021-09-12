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
		cout << this->year%100 << this->separator << setfill('0') << setw(2) << this->month << this->separator << setfill('0') << setw(2) << this->day << endl;
	} // ��YY-MM-DD����ʽ��ӡ������11-01-08
	/*  ���㺯��  */
	// ���㵱ǰ�������������֮���������꣬�����ǲ������ڱȵ�ǰ����������
	int fullYearsTo(int year, int month, int day) {
		int wholeYear = year-this->year;
		if (this->month < month) {
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
	int daysTo(int year, int month, int day) {
		int run = 0;
		int days = 0;
		if (year<this->year)
		{
			for (int i = year; i <= this->year; i++)
			{
				if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) {
					run++;
				}
			}
			int wholeMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
			days = wholeMonth[month] - day;
			for (int i = month + 1; i < 13; i++)
			{
				days += wholeMonth[i];
			}
			//cout << days<< endl;
			days += (this->year - year - 1) * 365 + run;
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
			for (int i = year; i >= this->year; i--)
			{
				if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) {
					run++;
				}
			}
			int wholeMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
			days = wholeMonth[this->month] - this->day;
			for (int i = this->month + 1; i < 13; i++)
			{
				days += wholeMonth[i];
			}
			days += (year-this->year- 1) * 365 + run;
			for (int i = 1; i < month; i++)
			{
				days += wholeMonth[i];
			}
			days +=day;
			//cout << "-" << days << endl;
			return days;
		}
		
	}
private:
	int year;
	int month;
	int day;
	char separator='-';  // ���ڷָ���
};
void main() {
	Date birthDate(1969, 8, 11);
	birthDate.printFullYear();      // ��ӡ��1969-08-11
	birthDate.printStandardYear(); // ��ӡ��69-08-11
	birthDate.setSeparator('/');
	birthDate.printFullYear(); // ��ӡ��1969/08/11
	cout << birthDate.fullYearsTo(2010, 4, 15)<<endl; // ��ӡ��40������ʮ��
	cout << birthDate.daysTo(2010, 4, 15)<<endl; // ��ӡ14857������14857����
	// ��ӡ-7254�����͹������絮����7254��
	cout << birthDate.daysTo(1949, 10, 1)<<endl;
}