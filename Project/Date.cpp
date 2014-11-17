#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

std::string Date::months[12] = {"January", "February", "March", "April", "May", "June",
								"July", "August", "September", "October", "November", "December"};
Date::Date(){
	month = 1;
	day = 1;
	year = 2001;
	month_string = "January";}
Date::Date(int m_month, int d_day, int y_year){
	month = m_month;
	day = d_day;
	year = y_year;
	set_month_string(m_month);}
Date::~Date()
{}
void Date::display_date(Date d_date){
	cout << d_date.month << "-" << d_date.day << "-" << d_date.year;}
void Date::setAge(int a)
{Age = a;}
void Date::setDay(int d_day)
{day = d_day;}
void Date::setYear(int y_year)
{year = y_year;}
void Date::setGrad(int gr){
     if (gr <= 2024)
          graduate = gr; 
     else if (gr >= 2015)
          graduate = gr; 
     else{
         cout << "Invalide graduation year." 
              << " this program will now end." << endl; 
         exit(EXIT_FAILURE);}
}
int Date::getAge() const
{return Age;}
int Date::getDay() const
{return day;}
int Date::getYear() const
{return year;}
int Date::getGrad() const
{return graduate;}
void Date::set_month_string(int m){
	for(int i = 0; i < 12; i++){
		if(i + 1 == m)
			month_string = months[i];}
}
std::string Date::get_month_string() 
{return month_string;}
bool Date::date_valid(Date d_date){
	if(!(d_date.month >  0 && d_date.month < 13)){
		cout << "The month is invalid";
		return false;}
	if(!(d_date.day > 0 && d_date.day < 32)){
		cout << "The day is invalid";
		return false;}
	if(!(d_date.year > 1900 && d_date.year < 2015)){
		cout << "The year is invalid";
		return false;}
	return true;
}
