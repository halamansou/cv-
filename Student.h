#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
	private:
		int Level;
		string Subjects;
	public:
		Student();
		Student(int , string ,string ,int ,string);
		~Student();
		void setLevel(int );
		void setSubjects(string );
		int getLevel();
		string getSubjects();
		void Add(); 
		static void Display(){
			string line;
			fstream myfile;
			myfile.open("student.txt",ios::in);
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
			string id, name,phone, level,subject;
			string phone_check;
			fstream myfile;
			myfile.open("student.txt",ios::in);
            cout<<"\n Enter phone number to know all informations about your student :\n";
            cin>>phone_check;
            int search_item=0;
            cout<<"\n\t ID\t Name \tphone\tlevel\tsubject\n";
            while(!myfile.eof())
    {
        getline(myfile,id,'|');
        getline(myfile,name,'|');
        getline(myfile,phone,'|');
        getline(myfile,level,'|');
        getline(myfile,subject);
        if(phone==phone_check)
        {
            cout<<"\n\t"<<id<<"\t"<<name<<"\t"<<phone<<"\t"<<level<<"\t"<<subject<<"\n";
            search_item=1;
            break;
        }

    }
    if(search_item==0)
    {
        cout<<"\n Sorry, The Information Of This student Does not Exist In Our System\n";
    }
    myfile.close();
		}
		
		void Update();
		void Delete();	
};

#endif
