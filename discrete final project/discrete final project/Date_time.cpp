#include<iostream>
#include<string>
#include"Date_time.h"
using namespace std;

/*Function to set date*/
void date_time::set_date(int days, int months, int years, int hours, int mins, int secs)
{
	day = days;
	month = months;
	year = years;
	hour = hours;
	min = mins;
	sec = secs;
}
//Constructer
date_time::date_time()
{
	day = month = year = hour = min = sec = 0;
}

/*Display Function To display time*/
void date_time::display()
{
	cout << day << "/" << month << "/" << year << "     " << hour << ":" << min << ":" << sec;
}