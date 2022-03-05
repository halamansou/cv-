#include "Teacher.h"

Teacher::Teacher(){
	setSalary(0.0);
}
Teacher::Teacher(int ID,string Name,string Phone,double Salary):Person(ID,Name,Phone)
{
	setSalary(Salary);
}
void Teacher::setSalary(double Salary){
	this->Salary=Salary;
}
double Teacher::getSalary(){
	return Salary;
}
void Teacher::Add(){
	ofstream myfile;
	myfile.open("Teacher.txt",ios::app);
	int id;
	string name;
	string phone;
	double salary;
	cout<<"Enter ID : ";
	cin>>id;
	setID(id);
	cout<<"Enter Name : ";
	cin>>name;
	setName(name);
	cout<<"Enter Phone : ";
	cin>>phone;
	setPhone(phone);
	cout<<"Enter Salary : ";
	cin>>salary;
	setSalary(salary);
	myfile <<getID()<<"|"<<getName()<<"|"<<getPhone()<<"|"<<getSalary()<<"\n";
	myfile.close();	
}
void Teacher::Update(){
		string phone_check;
	int update_item=0;
	Teacher t;
	fstream myfile;
	myfile.open("Teacher.txt",ios::in);
	fstream myfile2;
	myfile2.open("file2.txt",ios::out);
	cout<<"Enter phone of teacher that you want to update : ";
	cin>>phone_check;
	
	while(!myfile.eof())
	 {
	 		string id, name ,phone, salary;
			getline(myfile,id,'|');
			getline(myfile,name,'|');
			getline(myfile,phone,'|');
			getline(myfile,salary);
			
			if(phone ==phone_check)
			{
				update_item=1;
				
		 		cout<<"Enter the new details : \n";
		        int id;
		        string name;
				string phone;
				double salary;
				cout<<"Enter ID : ";
				cin>>id;
				t.setID(id);
				cout<<"Enter Name : ";
				cin>>name;
				t.setName(name);
				cout<<"Enter Phone : ";
				cin>>phone;
				t.setPhone(phone);
				cout<<"Enter salary : ";
				cin>>salary;
				t.setSalary(salary);
	
        		myfile2<<t.getID()<<'|'<<t.getName()<<'|'<<t.getPhone()<<'|'<<t.getSalary()<<endl;
	        }
	        else
	        {
	            myfile2<<id<<'|'<<name<<'|'<<phone<<'|'<<salary<<endl;
		
	     	}
    	
  }
    myfile.close();
    myfile2.close();
    remove("Teacher.txt");
    rename("file2.txt","Teacher.txt"); 
    if(update_item==1)
    {
        cout<<"\n Data Updated Successfully \n";
    }
    else
    {
        cout<<"\n Not Match Our Records \n";
    }
}
void Teacher::Delete(){
	Teacher t;
	int delete_item=0;
	string phone_check;
	cout<<"please enter phone that you want to delete: \n";
	cin>>phone_check;
	fstream myfile;
	myfile.open("Teacher.txt",ios::in);
	fstream myfile2;
	myfile2.open("file2.txt",ios::out);
	
	if(myfile.is_open()){
		while(!myfile.eof()){
			string id , name ,phone, salary;
			getline(myfile,id,'|');
			getline(myfile,name,'|');
			getline(myfile,phone,'|');
			getline(myfile,salary);
			if(phone==phone_check){
				delete_item=1;
				continue;
			}
			
			myfile2<<id<<"|"<<name<<"|"<<phone<<"|"<<salary<<endl;
		}
	}
	else{
		cout<<"myfile data not found !";
	}
	myfile.close();
	myfile2.close();	
	
	
if(delete_item==1){ 
		cout<<"teacher Deleted Successfully";
	}else{
		cout<<"teacher Not Found";
	}

	
	remove("Teacher.txt");
    rename("file2.txt","Teacher.txt");
}


Teacher::~Teacher()
{
}
