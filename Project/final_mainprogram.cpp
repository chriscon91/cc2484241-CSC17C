/*
  Main program for  Project
  Christian Conable
  CSC 17C 
  11/16/2014
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <stack>
#include <vector>
#include <numeric>
#include <algorithm>
#include "Student.h"
#include "BasicInfo.h"
#include "Date.h"
using namespace std;
//Declare Functions
bool valid_social(string social);
bool has_symbols(string data);
bool data_valid(int lower_range, int upper_range, string data_name, int data);
void display_social(string social_security_number);
void display_social(string social_security_number, int dummy);
int main(int argc, char *argv[]){
    //string variables
    string first, last, state;
    string address, city; 
    string social_security_number;
    //Integer, character and float variables
    map<int, string> grade;  
    stack<string> stackinfo; 
    int classes, value;
    int zip, grad_year; 
    int age, times; 
    int hs_month, hs_day, hs_year;
    char gender, is_correct, stand;
    vector<float> v; 
    int last_years;
    const int this_year = 4;
    const int col = 4;  
       
	//Class Declaration variables
    Student student; 
    BasicInfo set;
    BasicInfo size, employed; 
    Date hs_graduation, date_of_birth, set2;
    int *array; 
    
    cout.setf(ios::fixed); 
    cout.setf(ios::showpoint); 
    cout.precision(3);
    do{
        cout << endl; 
	    cout << setw(60) << "***********************************************" << endl; 
	    cout << setw(60) << "******** College Transfer Application *********" << endl; 
	    cout << setw(60) << "***********************************************" << endl; 
	    cout << "\tIn this program, a transferring college student will enter" 
	         << "\ninformation for the application, and the program will then" 
	         << "\ndisplay the results.\n\n" << endl; 
	    cout << setw(51) << "STUDENT PERSONAL INFORMATION: " << endl; 
	    do{
		    //Enter Student's First name
		    cout << "Student First Name: "; 
		    cin >> first; 
		}while(has_symbols(first) == true);
	    student.setFirst(first); 
	    do{
		    //Enter Student's last name
		    cout << "Student Last Name: "; 
		    cin >> last; 
		}while(has_symbols(first) == true);
	    student.setLast(last);
	    do{
		    //Enter Student's last name
		    cout << "Student's age: "; 
		    cin >> age; 
		}while(data_valid(16, 100, "age", age) == false);
	    set2.setAge(age); 
	    do{
            //Enter student's birthday                  
			cout << "Student's birthday, ex 06 06 1985: ";
			cin >> date_of_birth.month >> date_of_birth.day >> date_of_birth.year;
	    }while(Date::date_valid(date_of_birth) == false);
	    do{
		    //Enter Student's gender
		    cout << "Student's gender, M / F: "; 
		    cin >> gender; 
		}while(!(gender == 'm' || gender == 'f' || gender == 'M' || gender == 'F'));
		do{
		    //Enter Student's Street Address
		    cout << "Street Address: ";
		    cin.ignore();  
		    getline(cin, address);
		}while(has_symbols(address) == true);
	    do{
		    //Enter City 
		    cout << "City: ";  
		    getline(cin, city);
		}while(has_symbols(city) == true);
	    student.setCity(city); 
	    do{
		    //Enter State 
		    cout << "State: ";
		    cin >> state;
		}while(has_symbols(state) == true);
		student.setState(state); 
	    do{
		    //Enter Zip Code
		    cout << "Zip Code: "; 
		    cin >> zip; 
	    }while(data_valid(00000, 99999, "zip code", zip) == false);
	    student.setZip(zip); 
	    do{
            //Enter Social Security Number
    		cout << "Your social security number, 123-45-6789: ";
    		cin >> social_security_number;
		}while(valid_social(social_security_number) == false); 
	    do{
            //Enter Date of graduation from high school
			cout << "Date of high school graduation, ex 06 06 2000: ";
			cin >> hs_graduation.month >> hs_graduation.day >> hs_graduation.year;
	    }while(Date::date_valid(hs_graduation) == false);
	    
	    cout << "How many times did you take the SAT? ";
        cin >> times; 
        if(time < 0 || times > 5){
                cout << "\nInvalid entries." << endl; 
                cout << "How many times did you take the SAT? ";
                cin >> times; 
                while(time < 0 || times > 5){
                    cout << "How many times did you take the SAT? ";
                    cin >> times; 
                }
        }
        int *sctimes = new int[times];                         // <-- SET
        student.Score(sctimes, times);
        cout << endl; 
        //Grade Level Standing you choose to transfer as
        cout << "Choose the grade level standing "
             << "you will be applying for: " << endl << endl; 
        cout << setw(25) << "a. Freshman " << endl; 
        cout << setw(26) << "b  Sophomore " << endl; 
        cout << setw(23) << "c. Junior " << endl;
        cout << setw(23) << "d. Senior " << endl;
        cin >> stand;  
        if(stand == 'a' || stand == 'A')
                 last_years = 1; 
        else if(stand == 'b' || stand == 'B' )
                 last_years = 2; 
        else 
                 last_years = 2;
        float average; 
        float score[last_years][col];
        float st_ave[last_years], total, sum = 0;
        set.setStanding(stand);  
        cout << endl; 
        for (int i = 0; i <= last_years - 1; i++){
           total = 0; 
           for(int j = 0; j < col; j++){
			  do{
                  cout << endl << "Average GPA for " << (i + 1) << " year, "
                       << j + 1 << " quarter: "; 
                  cin >> score[i][j];
				}while(score[i][j] < 0.0e0f || score[i][j] > 4.0e0f); //Score must be between 0 and 4.0
                 v.push_back(score[i][j]);
                 total+= score[i][j]; 
                   
           } 
           st_ave[i] = total/col;
           cout << endl << endl << setw(45) << "Average GPA for " << i + 1 << " year: " << endl; 
           cout << setw(53) << st_ave[i] << "." << endl; 
       } 
       //Calculate addition of all GPA's.
       float total1 = 0.0e0f; 
       for (int i = 0; i < last_years; i++){
            for (int j = 0; j < col; j++)  
                total1 += score[i][j];}
       //Compute and display the cumulative average
       float average1; 
        average1 = total1/(last_years*col); 
       //Compute average GPA.
       float product; 
       product = average1*average;
       //Table showing grade point averages for each quarter
       cout << "Year" << setw(23) << "GPA" << endl; 
       for (int i = 0; i < last_years; i++){
           cout << i + 1 << " "; 
            for (int j = 0; j < col; j++)
                cout << setw(9) << score[i][j]; 
           cout << endl << endl; 
       } 
       // Calculate total gpa's
       sum = accumulate(v.begin(), v.end(), 0.0);
       float final;
       final = sum/(last_years*4);
        cout << "Enter the number of classes you took this\n" 
         << "past quarter (1-6): ";                                // <-- MAP
        cin >> classes;
        if(classes <= 0 || classes > 6){
                   cout << "Invalid entry." << endl;
                   cout << "Enter the number of classes you took this\n" 
                        << "past quarter: "; 
                   cin >> classes; 
                   while (classes <= 0 || classes > 6){
                       cout << "Invalid entry." << endl;
                       cout << "Enter the number of classes you took this\n" 
                            << "past quarter: "; 
                       cin >> classes; 
                   }
        }
        int *gdvalue = new int[classes]; 
        for (int i = 0; i < classes; i++){
            cout << "Enter " << i + 1 << " grade (1-100): "; 
            cin >> gdvalue[i];
            if(gdvalue[i] >= 90)
                grade[gdvalue[i]] = "A"; 
            else if(gdvalue[i] < 90 && gdvalue[i] >= 80)
                grade[gdvalue[i]] = "B";
            else if(gdvalue[i] < 80 && gdvalue[i] >= 70)
                grade[gdvalue[i]] = "C";
            else if(gdvalue[i] < 70 && gdvalue[i] >= 60)
                grade[gdvalue[i]] = "D";
            else
                grade[gdvalue[i]] = "F";
        }
        cout << endl; 
        //Display all the information
        // using stack variable
        stackinfo.push(state); 
        stackinfo.push(city); 
        stackinfo.push(address); 
        stackinfo.push(last); 
        stackinfo.push(first); 
        cout << endl; 
        
        cout << "\n\n\t******Summary Sheet*****\n";
        while(!stackinfo.empty()){
           cout << "\t" << stackinfo.top() << endl; 
           stackinfo.pop();}
        cout << "\t" << student.getZip()<< endl;
        cout << "\tAge: " << set2.getAge() << endl; 
	    cout << "\tDate of Birth: ";
	    Date::display_date(date_of_birth);
	    cout << "\n\tSex: ";
	    if(gender == 'M' || gender == 'm')
	    	cout << "\tMale";
	    else
	    	cout << "\tFemale";
	    cout << "\n\tSSN: ";
	    display_social(social_security_number, 0);
	    cout << endl; 
	    cout << "\tHigh School Graduation date: ";
	    Date::display_date(hs_graduation);
	    cout << endl; 
	    if (stand == 'a' || stand == 'A')
                  cout << "\tFreshman Transfer" << endl;   
        else if (stand == 'b' || stand == 'B')
                  cout << "\tSophomore Transfer." << endl;
        else if (stand == 'c' || stand == 'C')
                  cout << "\tJunior Transfer" << endl; 
        else
                  cout << "\tSenior Transfer " << endl; 
        cout << "\tGrades you received for last quarter: " << endl; 
        for(int i = 0; i < classes; i++){
            cout << "\tGrade " << i + 1 << ": "
                 << grade[gdvalue[i]] << endl; 
        }
        cout << "\tCumulative GPA: " << final << endl; 
	    cout << "\t*************************";
	    cout << "\nIs the above information correct, y/n: ";
	    cin >> is_correct;
	    if(is_correct == 'Y' || is_correct == 'y')
            return 0; 
	}while(is_correct == 'N' || is_correct == 'n');  
    Student new_student = Student(first, last, gender, age, date_of_birth, state, city, zip);
    cin.ignore();
    cin.get();
    system("PAUSE");
    return EXIT_SUCCESS;}
//Validates that the zip code will be five digits long
bool data_valid(int lower_range, int upper_range, string data_name, int data){
	if((data >= lower_range) && (data <= upper_range))
		return true;
	else{
		cout << "The " << data_name << " is not valid";
		cout << endl;
		return false;}}
//String variables must follow specified format in order to run
bool has_symbols(string data){
	for(int i = 0; i < data.length(); i++){
		if(isalnum(data[i]) == false && isspace(data[i]) == false){
			cout << "The input can only have letters";
			cout << "The illegal character: [" << data[i] << "]";
			return true;}
	}
	return false;}
//Validate the format for the social security number
bool valid_social(string social){
	if(social.length() != 11){
		cout << "Social not in right format";
		return false;}
	return true;}
//Display the Social Security Number
void display_social(string social_security_number){
	cout << "***-**-";
	for(int i = 7; i < 11; i++)
		cout << social_security_number[i];}
void display_social(string social_security_number, int dummy){	
	for(int i =0; i < 11; i++)
		cout << social_security_number[i];}

 
