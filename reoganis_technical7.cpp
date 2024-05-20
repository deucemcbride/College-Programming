#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void create();
void read();
void append();
void menu();

int option;

int main(){
	do{
	menu();
	cin>>option;
	cin.ignore();
		switch(option){
			case 1:
				create();
				break;
			case 2:
				read();
				break;
			case 3:
				append();
				break;
			case 4:
				break;
		}
	} while (option != 4);
	
	return 0;
}

void create(){
	string name, course, email, contactnumber;
	ofstream MyFile("myText.txt");
	cout << "Enter your Name: " << endl;
	getline(cin,name);
	cout << "Enter course: " << endl;
	getline(cin,course);
	cout << "Enter e-mail: " << endl;
	getline(cin,email);
	cout << "Enter contact number: " << endl;
	getline(cin,contactnumber);
	if (MyFile.is_open())
	{
		MyFile << name << endl;
		MyFile << course << endl;
		MyFile << email << endl;
		MyFile << contactnumber << endl;
		MyFile.close();
	}
	else
	cout <<"No File is created";
}

void read(){
	string myText;
	ifstream myReadFile("myText.txt");
	while (getline (myReadFile, myText))
	{
		cout << myText << endl;
	}
	myReadFile.close();
}


void append(){
	ofstream MyFile ("myText.txt", ios::app);
	string newInfo;
	cout << "Enter new information: ";
	getline(cin,newInfo);
	MyFile << newInfo << endl;
}

void menu(){
		cout<<"MENU"<<endl;
		cout<<"[1] Create "<<endl;
		cout<<"[2] Read"<<endl;
		cout<<"[3] Append"<<endl;
}


