// including header files
#include<iostream>
#include<conio.h>
#include<fstream>
#include <unistd.h>
using namespace std;

//global variables
string fname,lname,phone_num;

// Functions
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);
void func1();
int j;

int main()
{
    short int choice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\tCONTACT MANAGEMENT SYSTEM.";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input !";
            cout << "\n\tPress Any Key To Continue..";
            getch();
            func1();
            
    }
    return 0;
}

void func1(){
	main();
}

void self_exit()
{
    system("cls");
    cout << "\n\n\n\t\tThank You For Using !";
    exit(1);
}

void help()
{
	system("cls");
    cout << "This displays help\n"<<"read instruction carefully\n";
    sleep(6);
    main();
}

void addContact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");
    cout << "\n\n\tEnter First Name : ";
    cin >> fname;
    cout << "\n\tEnter Last Name : ";
    cin >> lname;
    cout << "\n\tEnter 10-Digit Phone Number : ";
    cin >> phone_num;

    if(check_digits(phone_num) == true)
    {
        if(check_numbers(phone_num) == true)
        {
            if(phone.is_open())
            {
                phone << fname << " " << lname << " " << phone_num << endl;
                cout << "\n\tContact Saved Successfully !";
            }
            else
            {
                cout << "\n\tError Opening File !";
            }
        }
        else
        {
            cout << "\n\tA Phone Number Must Contain Numbers Only !";
        }
    }
    else
    {
        cout << "\n\tA Phone Number Must Contain 10 Digits.";
    }
    phone.close();
    sleep(4);
    main();
}

void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string keyword1,keyword2;
    system("cls");
    cout<<"\n\t\tTo Search-";
    cout << "\n\tEnter Name: ";
    cin >> keyword1;
    cout<<"\n\t Would you wish to enter last name";
    cout<<"\n\tType 1 to enter last name\n\ttype 2 to go for the search now\n";
    cin>>j;
    if(j==1){
    cout << "\tEnter last Name: ";
    cin >> keyword2;
}

  if(j==2){
    while(myfile >> fname >> lname >> phone_num)
    {
        if(keyword1 == fname || keyword2 == lname)
        {
            system("cls");
            cout<<"Instance found in record"<<endl;
            cout << "\n\n\n\t\tContact details..";
            cout << "\n\n\tFirst Name : " << fname;
            cout << "\n\tLast Name : " << lname;
            cout << "\n\tPhone Number : " << phone_num;
            found = true;
            break;
        }
    }
    if(found == false){
    cout << "\n\tNo Such Contact Found";
    sleep(3);
}
sleep(15);
main();
}
  if(j==1){
    while(myfile >> fname >> lname >> phone_num)
    {
        if(keyword1 == fname && keyword2 == lname)
        {
            system("cls");
            cout<<"Instance found in record"<<endl;
            cout << "\n\n\n\t\tContact details..";
            cout << "\n\n\tFirst Name : " << fname;
            cout << "\n\tLast Name : " << lname;
            cout << "\n\tPhone Number : " << phone_num;
            found = true;
            break;
        }
    }
    if(found == false){
    cout << "\n\tNo Such Contact Found";
    sleep(3);
}
sleep(15);
main();
}
else{
	"\n\t INVALID Response";
	sleep(2);
	main();
}
}

bool check_digits(string x)
{
    if(x.length() == 10)
    return true;
    else
    return false;
}

bool check_numbers(string x)
{
    bool check = true;

    for(int i=0; i < x.length(); i++)
    {
        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    return true;
    if(check == false)
    return false;
}


