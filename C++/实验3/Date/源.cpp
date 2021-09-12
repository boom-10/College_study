#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Date {
public:
	/* 默认构造函数，以fullyear的形式给出年月日，默认值为1990年1月1日，同时设置日期分隔符为“-” */
	Date(int year = 1990, int month = 1, int day = 1) {
		this->year = year;
		this->day = day;
		this->month = month;
	}
	/* get、set方法 */
	// 设置日期，如果有非法的月或日，将其置为1
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

	/* 输出函数，请使用setfill(‘0’)和setw(2)，需要包含<iomanip>头文件 */
	void printFullYear() {
		cout << this->year << this->separator << setfill('0') << setw(2) << this->month << this->separator << setfill('0') << setw(2) << this->day << endl;
	}      // 以YYYY-MM-DD的形式打印，2011-01-08
	void printStandardYear() {
		cout << this->year%100 << this->separator << setfill('0') << setw(2) << this->month << this->separator << setfill('0') << setw(2) << this->day << endl;
	} // 以YY-MM-DD的形式打印，比如11-01-08
	/*  计算函数  */
	// 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况
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
		cout << " 满" << wholeYear << "岁了" << endl;
	};
	/* 计算当前日期与参数日期之间相差多少天(考虑闰年)，如果参数日期在当前日期之前，返回负数。 */
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
	char separator='-';  // 日期分隔符
};
void main() {
	Date birthDate(1969, 8, 11);
	birthDate.printFullYear();      // 打印：1969-08-11
	birthDate.printStandardYear(); // 打印：69-08-11
	birthDate.setSeparator('/');
	birthDate.printFullYear(); // 打印：1969/08/11
	cout << birthDate.fullYearsTo(2010, 4, 15)<<endl; // 打印：40，满四十岁
	cout << birthDate.daysTo(2010, 4, 15)<<endl; // 打印14857，活了14857天了
	// 打印-7254，共和国比我早诞生了7254天
	cout << birthDate.daysTo(1949, 10, 1)<<endl;
}