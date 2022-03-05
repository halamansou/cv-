#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
	private:
		double Salary;
		string Dept;
	public:
		Employee();
		Employee(int ,string ,string ,double  , string );
		void setSalary(double);
		double getSalary();
		void setDept(string);
		string getDept();
		void Add();
		static void Display(){
			string line;
			fstream myfile;
			myfile.open("Employee.txt",ios::in);
			if(myfile.is_open()){
				while(!myfile.eof()){
					getline(myfile,line);
					string delimeter="|";
					int pos=0;
					string token;
					while ((pos=line.find(delimeter))!=std::string::npos){
						token=line.substr(0,pos);
						cout<<token<<"\t";
						line.erase(0,pos+delimeter.length());
		}
		cout<<line<<"\n";
				}
			}else{
				cout<<"can not open this file ";
			}
		}
		void Search_By_phone()const{
			string id, name,phone, salary,Dept;
			string phone_check;
		    fstream myfile;
            myfile.open("Employee.txt",ios::in);
            cout<<"\n Enter phone number to know all informations about your employee :\n";
            cin>>phone_check;
            int search_item=0;
            cout<<"\n\t ID\t Name \tphone\tsalary\tdept\n";
            while(!myfile.eof())
    {
        getline(myfile,id,'|');
        getline(myfile,name,'|');
        getline(myfile,phone,'|');
        getline(myfile,salary,'|');
        getline(myfile,Dept);
        if(phone==phone_check)
        {
            cout<<"\n\t"<<id<<"\t"<<name<<"\t"<<phone<<"\t"<<salary<<"\t"<<Dept<<"\n";
            search_item=1;
            break;
        }
		}
		if(search_item==0)
    {
        cout<<"\n Sorry, The Information Of This employee Does not Exist In Our System\n";
    }
    myfile.close();
	}
		void Update();
		void Delete();
		~Employee();
};

#endif
