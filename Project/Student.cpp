/*
  Description: Specification File 
  for Student Information
*/

#include "Student.h"
#include "BasicInfo.h"
#include <cstdlib>
#include "Date.h"
#include <string>
#include <set>
#include <queue>
#include <iterator>
#include <iostream> 

using namespace std; 

const int Student::size = 10;
//Definition for Default constructor created 
//in Student header file
Student::Student(){
	first_n = " "; 
	last_n = " ";
    num = 0; 
    n = 0;
 }
//Definition for 1st Constructor created in Student Header File
Student::Student(std::string first, std::string last){
	first_n = " "; 
	last_n = " ";
    num = 0; 
    n = 0;
 }
//Definition for Constructor created in Student Header File
Student::Student(std::string first, std::string last, char gender, int age, Date dob, std::string state, std::string city, int zip){
	first_n = " "; 
	last_n = " ";
    num = 0; 
    n = 0; 
 }
//Destructor for Dynamically allocated variables 
//created in Student Header File
Student::~Student()
{delete [] num;}
//Set Iterator for SAT scores
void Student::Score(int *num, int n){
     int total = 0, average; 
     for(int i = 0; i < n; i++){
            cout << i + 1 << " score: "; 
            cin >> num[i];
            if(num[i] < 1200 || num[i] > 2400){
                      cout << "Invalid score" << endl; 
                      cin >> num[i]; 
                      while(num[i] < 1200 && num[i] > 2400)
                          cin >> num[i]; 
            }
            total += num[i]; 
            // set variable
            major.insert(num[i]);
            // queue variable
            major2.push(num[i]); 
     }   
     cout << "You took the test " << major2.size() << " times." << endl; 
     cout << "Score from the last test was: " << major2.back() << endl;
     cout << "Your scores were: " << endl; 
     while(!major2.empty()){
          cout << "\t" << major2.front() << endl; 
          major2.pop();                      
     } 
     average = total/n; 
     cout << "Your scores from lowest to highest: " << endl; 
     // Use Iterator to display info
     for(iterator = major.begin(); iterator != major.end(); iterator++)
            cout << "\t" << *iterator << endl;
     cout << endl; 
     cout << "Your average score was: " << average << "." << endl; 
}
//Mutator Functions for first and last name 
//Set student's first name
void Student::setFirst(std::string fst)
{first_n = fst;}        
//Set student's last name
void Student::setLast(std::string lst)
{last_n = lst; } 
//Set student's city of residence
void Student::setCity(std::string c)
{city = c;}
//Set the student's state of residency
void Student::setState(std::string st)
{State = st;}
//Set the Zip Code Established in Main
void Student::setZip(int z)
{Zip = z;}
//Set Student's Social Security Number
void Student::setSocial(std::string social)
{social_number = social;}
//Accessor Functions for first and last name
//Get student's first name
std::string Student::getFirst() const
{return first_n; }
//Get student's last name
std::string Student::getLast() const
{return last_n; }
//Get student's city of residence
std::string Student::getCity () const
{return city; }
//Get the state student lives in.           
std::string Student::getState() const
{return State;} 
//Get the student zip code
int Student::getZip() const
{return Zip;}
//Get the student's social security number
std::string Student::getSocial() const
{return social_number;}
//Get the student's high school 
void Student::setGrad() const{
   if (hs_grad_date.year < 1975){
      cout << "I'm sorry but you're"
           << " too old to be going to college." 
           << "\nWe will not be accepting your application." << endl; 
      system("PAUSE"); 
      exit(EXIT_FAILURE);}
   else if (hs_grad_date.year > 2013){
        cout << "Nope you haven't graduated from high school yet." 
             << "\nYour application has been deleted." << endl;
        system("PAUSE");      
        exit(EXIT_FAILURE);}}
//Get Student's Social Security Number
std::string Student::get_social()
{return social_number;}



