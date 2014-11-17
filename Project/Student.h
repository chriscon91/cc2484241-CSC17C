/*
  Description: Specification File 
  for Student Information
*/
#ifndef STUDENT_H
#define STUDENT_H
#include "BasicInfo.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <iterator>
#include <string>
#include <cstring>

using namespace std; 

class Student : public BasicInfo{
	private:
        set<int> major; 
        queue<int> major2; 
        typedef set<int>::iterator it; 
        it iterator;
        int *num, n;
		std::string State;
		std::string social_number;
		std::string city;
		std::string first_n;
		std::string last_n;
		Date hs_grad_date;
		static const int size;
		int Zip;
	public:
        //Default Constructor for Student Header File   
		Student();
		//Constructors for Student Header File
		Student(std::string first, std::string last);
		Student(std::string first, std::string last, char gender, int age, Date dob, std::string state, std::string city, int zip);
		~Student();
		//Display Graduation Date
		void Grad();
		//Mutator Functions 
		
		//Set Container used for SAT scores
		void Score(int *, int);
		void setFirst(std::string fst);
        void setLast(std::string lst);  
		void setState(std::string st);
		void setCity(std::string c);
		void setZip(int z);
		void setSocial(std::string social);
		void setGrad() const;
		//Validate the social security number
		bool valid_social(string social);
		//Display social security number
		void display_social();
		void display_social(int dummy);
		//Accessor Functions
		std::string getFirst() const; 
		std::string getLast() const; 
		std::string getState() const;
		std::string getCity() const;
		int getZip() const;
		std::string getSocial() const; 
		std::string get_social();
};
#endif
