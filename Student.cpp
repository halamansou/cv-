#include "Student.h"

Student::Student(){
	setLevel(0);
	setSubjects("no subjects");
}
Student::Student(int ID,string Name,string Phone ,int Level, string Subjects):Person(ID,Name,Phone)
{
	setLevel(Level);
	setSubjects(Subjects);
}
void Student::setLevel(int Level){
	this->Level=Level;
}
void Student::setSubjects(string Subjects){
	this->Subjects=Subjects;
}
int Student::getLevel(){
	return Level;
}
string Student::getSubjects(){
	return Subjects;
}
void Student::Add(){
	ofstream myfile;
	myfile.open("student.txt",ios::app);
	int id;
	string name;
	string phone;
	int level;
	string subjects;
	cout<<"Enter ID : ";
	cin>>id;
	setID(id);
	cout<<"Enter Name : ";
	cin>>name;
	setName(name);
	cout<<"Enter Phone : ";
	cin>>phone;
	setPhone(phone);
	cout<<"Enter Level : ";
	cin>>level;
	setLevel(level);
	cout<<"Enter Subject : ";
	cin>>subjects;
	setSubjects(subjects);
	myfile <<getID()<<"|"<<getName()<<"|"<<getPhone()<<"|"<<getLevel()<<"|"<<getSubjects()<<"\n";
	myfile.close();	
}
void Student::Update(){
	string phone_check;
	int update_item=0;
	Student s;
	fstream myfile;
	myfile.open("student.txt",ios::in);
	fstream myfile2;
	myfile2.open("file2.txt",ios::out);
	cout<<"Enter phone of student that you want to update : ";
	cin>>phone_check;
	
	while(!myfile.eof())
	 {
	 		string id, name ,phone, level ,subject;
			getline(myfile,id,'|');
			getline(myfile,name,'|');
			getline(myfile,phone,'|');
			getline(myfile,level,'|');
			getline(myfile,subject);
			
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
				s.setID(id);
				cout<<"Enter Name : ";
				cin>>name;
				s.setName(name);
				cout<<"Enter Phone : ";
				cin>>phone;
				s.setPhone(phone);
				cout<<"Enter Level : ";
				cin>>level;
				s.setLevel(level);
				cout<<"Enter Subject : ";
				cin>>subjects;
				s.setSubjects(subjects);
	
        		myfile2<<s.getID()<<'|'<<s.getName()<<'|'<<s.getPhone()<<'|'<<s.getLevel()<<'|'<<s.getSubjects()<<endl;
	        }
	        else
	        {
	            myfile2<<id<<'|'<<name<<'|'<<phone<<'|'<<level<<'|'<<subject<<endl;
		
	     	}
    	
  }
  myfile.close();
    myfile2.close();
    remove("student.txt");
    rename("file2.txt","student.txt"); 
    if(update_item==1)
    {
        cout<<"\n Data Updated Successfully \n";
    }
    else
    {
        cout<<"\n Not Match Our Records \n";
    }
}



void Student::Delete(){
	
	Student s;
	string phone_check;
	fstream myfile;
	int delete_item=0;
	myfile.open("student.txt",ios::in);
	fstream myfile2;
	myfile2.open("file2.txt",ios::out);
	cout<<"please enter phone of student that you want to delete : \n";
	cin>>phone_check;
	if(myfile.is_open()){
		while(!myfile.eof()){
	
			string id, name ,phone, level ,subject;
			getline(myfile,id,'|');
			getline(myfile,name,'|');
			getline(myfile,phone,'|');
			getline(myfile,level,'|');
			getline(myfile,subject);
			if(phone==phone_check){
				delete_item=1;
				continue;
			}
			myfile2<<id<<"|"<<name<<"|"<<phone<<"|"<<level<<"|"<<subject<<"\n";	
			
		}
	}
	else
	{
		cout<<"myfile data not found !";
	}
	myfile.close();
	myfile2.close();
		
	if(delete_item==1){ 
		cout<<"Student Deleted Successfully";
	}else{
		cout<<"Student Not Found";
	}

	
	remove("student.txt");
    rename("file2.txt","student.txt");
	
}


Student::~Student()
{
}
