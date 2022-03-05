#include "Person.h"
#include<fstream>
Person::Person(){
	setID(0);
	setName("no name");
	setPhone("Null");
}
Person::Person(int ID , string Name , string Phone)
{
	setID(ID);
	setName(Name);
	setPhone(Phone);
}
void Person::setID(int ID){
	this->ID=ID;
}
void Person::setPhone(string Phone){
	this->Phone=Phone;
}
void Person::setName(string Name){
	this->Name=Name;
}

int Person::getID(){
	return ID;
}
string Person::getPhone(){
	return Phone;
}
string Person::getName(){
	return Name;
}

void Person::Add(){
	ofstream myfile;
	Person p;
	myfile.open("person.txt",ios::app);
	int id;
	string name;
	string phone;
	cout<<"Enter ID : ";
	cin>>id;
	p.setID(id);
	cout<<"Enter Name : ";
	cin>>name;
	p.setName(name);
	cout<<"Enter Phone : ";
	cin>>phone;
	p.setPhone(phone);
	myfile <<p.getID()<<"|"<<p.getName()<<"|"<<p.getPhone()<<"\n";
	myfile.close();	
}

void Update(){
string phone_check;
	int update_item=0;
	Person p;
	fstream myfile;
	myfile.open("person.txt",ios::in);
	fstream myfile2;
	myfile2.open("file2.txt",ios::out);
	cout<<"Enter phone of person that you want to update : ";
	cin>>phone_check;
	
	while(!myfile.eof())
	 {
	 		string id, name ,phone;
			getline(myfile,id,'|');
			getline(myfile,name,'|');
			getline(myfile,phone);
			
			if(phone ==phone_check)
			{
				update_item=1;
				
		 		cout<<"Enter the new details : \n";
		        int id;
		        string name;
				string phone;
				int level;
				string subjects;
				cout<<"Enter ID : ";
				cin>>id;
				p.setID(id);
				cout<<"Enter Name : ";
				cin>>name;
				p.setName(name);
				cout<<"Enter Phone : ";
				cin>>phone;
				p.setPhone(phone);
	
        		myfile2<<p.getID()<<'|'<<p.getName()<<'|'<<p.getPhone()<<endl;
	        }
	        else
	        {
	            myfile2<<id<<'|'<<name<<'|'<<phone<<'|'<<endl;
		
	     	}
    	
  }
    myfile.close();
    myfile2.close();
    remove("person.txt");
    rename("file2.txt","person.txt"); 
    if(update_item==1)
    {
        cout<<"\n Data Updated Successfully \n";
    }
    else
    {
        cout<<"\n Not Match Our Records \n";
    }
}

void Delete(){
		Person P;
		int delete_item=0;
	string phone_check;
	cout<<"please enter phone of your person that you want to delete: \n";
	cin>>phone_check;
	fstream myfile;
	myfile.open("person.txt",ios::in);
	fstream myfile2;
	myfile2.open("file2.txt",ios::out);
	
	if(myfile.is_open()){
		while(!myfile.eof()){
			string id,name ,phone;
			getline(myfile,id,'|' );
			getline(myfile,name,'|');
			getline(myfile,phone,'|');
			if(phone==phone_check){
				delete_item=1;
				continue;
			}
			
			myfile2<<id<<"|"<<name<<"|"<<phone<<endl;}
		}
	
	else{
	
		cout<<"myfile data not found !";
	}
	myfile.close();
	myfile2.close();

if(delete_item==1){ 
		cout<<"person Deleted Successfully";
	}else{
		cout<<"person Not Found";
	}

	
	remove("person.txt");
    rename("file2.txt","person.txt");
	
}

Person::~Person()
{
}

