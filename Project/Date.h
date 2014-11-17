/*
  Specification File for Date input
*/

#ifndef DATE_H
#define DATE_H
#include <string>

using namespace std;


class Date
{
	public:
        static std::string months[12];
        std::string month_string;
		int Age, month;
		int day;
		int year;
		int graduate; 
	public:
		//Default Constructors
		Date(); 
		Date(int month, int day, int year);
		//Displays date 
		static void display_date(Date d_date);
		static bool date_valid(Date d_date);
		//Mutator Functions for Date Header File
		void setAge(int a);
		void set_month_string(int month);
		void setDay(int day);
		void setYear(int year);
		void setGrad(int grad); 
	    //Accessor Functions for Date Header File
		std::string get_month_string();
		int getAge() const;
		int getDay() const;
		int getYear() const;
		int getGrad() const; 
		//Destructor for previous Constructors
		~Date();
};
#endif
