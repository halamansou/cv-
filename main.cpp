#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Employee.h"
using namespace std;

int main() {
	Student s;
	Teacher t;
	Employee e;
	Person p;
		cout <<" \t\tWELCOME in our system about school management\t\t \n";
    int option ;
    cout<<"  \n1 if you are student  \n2 if you are teacher  \n3 if you are employee \n" ;
    cout << "Enter your option  :  " ;
    cin >> option ;
  switch(option) {
   	case 1 :
   		int choice;
   		while(true){
   		cout << "student : \n" << "  \n1 if you want to add  \n2 if you want to search  \n3 if you want to display \n4 if you want to update \n5 if you want to delete \n6 if you want to exit\n"  ;
    	cout<< "Enter your option :  " ;
    	cin>>choice;
    	switch (choice){
    		case 1 :
    			s.Add();
    			break ;
    		case 2 :
				s.Search_By_phone();
				break ;
    		case 3 :
				s.Display();
				break ;
				
			case 4:
				s.Update();
				break;
			case 5:
				s.Delete();
				break;
				
			case 6 :
				exit(0);
			default :
			cout << " Please enter correct choose \n" ;	
		}
	}
		break ;
	case 2 :
		int c;
		while(true){
		cout << "teacher :\n " <<"  \n1 if you want to add  \n2 if you want to search  \n3 if you want to display \n4 if you want to update \n5 if you want to delete \n6 if you want to exit\n" ;
		cout<< "Enter your option :  "; 
		cin>>c;
	    	switch (c){
    		case 1 :
    			t.Add();
    			break ;
    		case 2 :
				t.Search_By_phone();
				break ;
    		case 3 :
				t.Display();
				break ;
				
			case 4:
				t.Update();
				break;
			case 5:
				t.Delete();
				break;
				
			case 6 :
					exit(0);
			default :
			cout << " Please enter correct choose \n" ;	
		}
	}
		break  ;
	case 3 :
		int ch;
		while(true){
		cout << "employee : \n" <<   "  \n1 if you want to add  \n2 if you want to search  \n3 if you want to display \n4 if you want to update \n5 if you want to delete \n6 if you want to exit\n";
		cout<< "Enter your option :  " ;
		cin>>ch;
			switch (ch){
    		case 1 :
    			e.Add();
    			break ;
    		case 2 :
				e.Search_By_phone();
				break ;
    		case 3 :
				e.Display();
				break ;
				
			case 4 :
				e.Update();
				break;
			case 5 :
				e.Delete();
				break;
				
			case 6 :
				exit(0);
			default :
			cout << " Please enter correct choose \n" ;	
		}
	}
		break ;
	default:
		cout << " please enter correct number  : \n ";	
    		
	}

}
