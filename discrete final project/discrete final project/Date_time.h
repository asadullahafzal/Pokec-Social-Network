//Date Time Class using to store the date and time of Users
#include<iostream>
#include<string>
using namespace std;
class date_time
{
public:
	int day, month, year, hour, min, sec;
	date_time();
	void set_date(int days, int months, int years, int hours, int mins, int secs);
	void display();

};