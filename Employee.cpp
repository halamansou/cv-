#include "Employee.h"

Employee::Employee(){
	setSalary(0.0);
	setDept("Null");
}
Employee::Employee(int ID,string Name,string Phone ,double Salary , string Dept):Person(ID,Name,Phone){
	setSalary(Salary);
	setDept(Dept);
}
void Employee::setSalary(double Salary){
	this->Salary=Salary;
}
double Employee::getSalary(){
	return Salary;
}
void Employee::setDept(string Dept){
	this->Dept=Dept;
}
string Employee::getDept(){
	return Dept;
}
void Employee::Add(){
	ofstream myfile;
	myfile.open("Employee.txt",ios::app);
	int id;
	string name;
	string phone;
	double salary;
	string dept;
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
	cout<<"Enter Dept : ";
	cin>>dept;
	setDept(dept);
	myfile <<getID()<<"|"<<getName()<<"|"<<getPhone()<<"|"<<getSalary()<<"|"<<getDept()<<"\n";
	myfile.close();	
}

void Employee::Update(){
	string phone_check;
	int update_item=0;
	Employee e;
	fstream myfile;
	myfile.open("Employee.txt",ios::in);
	fstream myfile2;
	myfile2.open("file2.txt",ios::out);
	cout<<"Enter phone of employee that you want to update : ";
	cin>>phone_check;
	
	while(!myfile.eof())
	 {
	 		string id, name ,phone, salary ,dept;
			getline(myfile,id,'|');
			getline(myfile,name,'|');
			getline(myfile,phone,'|');
			getline(myfile,salary,'|');
			getline(myfile,dept);
			
			if(phone ==phone_check)
			{
				update_item=1;
				
		 		cout<<"Enter the new details : \n";
		        int id;
		        string name;
				string phone;
				double salary;
				string dept;
				cout<<"Enter ID : ";
				cin>>id;
				e.setID(id);
				cout<<"Enter Name : ";
				cin>>name;
				e.setName(name);
				cout<<"Enter Phone : ";
				cin>>phone;
				e.setPhone(phone);
				cout<<"Enter salary : ";
				cin>>salary;
				e.setSalary(salary);
				cout<<"Enter dept : ";
				cin>>dept;
				e.setDept(dept);
	
        		myfile2<<e.getID()<<'|'<<e.getName()<<'|'<<e.getPhone()<<'|'<<e.getSalary()<<'|'<<e.getDept()<<endl;
	        }
	        else
	        {
	            myfile2<<id<<'|'<<name<<'|'<<phone<<'|'<<salary<<'|'<<dept<<endl;
		
	     	}
    	
  }
 myfile.close();
    myfile2.close();
    remove("Employee.txt");
    rename("file2.txt","Employee.txt"); 
    if(update_item==1)
    {
        cout<<"\n Data Updated Successfully \n";
    }
    else
    {
        cout<<"\n Not Match Our Records \n";
    }
}
void Employee::Delete(){
	Employee e;
	int delete_item=0;
	string phone_check;
	cout<<"please enter phone of employee  that you want to delete: \n";
	cin>>phone_check;
	fstream myfile;
	myfile.open("Employee.txt",ios::in);
	fstream myfile2;
	myfile2.open("file2.txt",ios::out);
	
	if(myfile.is_open()){
		while(!myfile.eof()){
			string id, name ,phone, salary ,dept;
			getline(myfile,id,'|');
			getline(myfile,name,'|');
			getline(myfile,phone,'|');
			getline(myfile,salary,'|');
			getline(myfile,dept);
			if(phone==phone_check){
				delete_item=1;
				continue;
			}
			
			myfile2<<id<<"|"<<name<<"|"<<phone<<"|"<<salary<<"|"<<dept<<endl;
		}
	}
	else{
		cout<<"myfile data not found !";
	}
	myfile.close();
	myfile2.close();	
	
	
		if(delete_item==1){ 
		cout<<"Employee Deleted Successfully";
	}else{
		cout<<"Employee Not Found";
	}

	
	remove("Employee.txt");
    rename("file2.txt","Employee.txt");
	
}

Employee::~Employee()
{
}
