#ifndef PERSON_H
#define PERSON_H
#include<fstream>
#include<iostream>
#include <string.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;


class Person
{
	protected:
		int ID;
		string Name,Phone;
	public:
		Person();
		Person(int , string  , string );
		~Person();
		void setID(int);
		void setPhone(string);
		void setName(string);
		int getID();
		string getPhone();
		string getName();
		void Add();
		static void Display(){
			string line;
			fstream myfile;
			myfile.open("person.txt",ios::in);
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
			string id,name,phone;
			string phone_check;
			fstream myfile;
			myfile.open("person.txt",ios::in);
			cout<<"\n Enter phone number to know all informations about your person :\n";
            cin>>phone_check;
            int search_item=0;
            cout<<"\n\t ID\t Name \tphone\n";
            while(!myfile.eof()){
            	getline(myfile,id,'|');
            	getline(myfile,name,'|');
            	getline(myfile,phone);
            	if(phone==phone_check){
            		cout<<"\n\t"<<id<<"\t"<<name<<"\t"<<phone<<"\n";
                    search_item=1;
                    break;
				}
			}
			if(search_item==0)
    {
        cout<<"\n Sorry, The Information Of This person Does not Exist In Our System\n";
    }
    myfile.close();
		}
		void Update();
		void Delete();

};

#endif

