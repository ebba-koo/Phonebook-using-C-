#include<iostream>
#include<string.h>

//clear screen header file
#include <stdlib.h>

//read and  write file
#include<fstream>

using namespace std;

int count=0; //use for counter
class Record
{
private:
    char nameFirst[20];
    char nameSecond[20];
    int age;
    char sex[10];
    int id;
public:
    void addrecord(int i);
    int getid();
    void editrecord(int k);
    int search(int k);
    void displayAll();
    void displayId(int k);
};
Record record;



void Record::addrecord(int numRec)
{
//accept name, age, sex and id and assign
    ofstream theFile("Records.txt");
    int n = 1;
    while(n<=numRec)
    {
        system("cls");
        cout<<"\n\t ADDING NEW RECORD"<<endl;
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\t\t Enter First Name: ";
        cin>>record.nameFirst;
        cout<<"\n\t\t Enter Last Name: ";
        cin>>record.nameSecond;
        cout<<"\n\t\t Enter your Age: ";
        cin>>record.age;
        cout<<"\n\t\t Enter your Sex: ";
        cin>>record.sex;
        cout<<"\n\t\t Enter your Id: ";
        cin>>record.id;
        cout<<"\n\t---------------------------------------"<<endl;
        //assign object value to txt file
        theFile << record.id <<" "<< record.nameFirst <<" "<<record.nameSecond<<" "<<record.sex<<" "<<record.age<<endl;

        n++;
    }
    theFile.close();
}
void Record::editrecord(int k)
{
//accept name, age, sex and id and edit
    ifstream theFile("Records.txt");
    cout<<"\n\t---------------------------------------"<<endl;
    while(theFile >> record.id >> record.nameFirst >> record.nameSecond >> record.sex >> record.age )
    {
        if(record.id == k)
        {
            cout<<"\n\t\t Enter First Name: ";
            cin>>record.nameFirst;
            cout<<"\n\t\t Enter Last Name: ";
            cin>>record.nameSecond;
            cout<<"\n\t\t Enter your Age: ";
            cin>>record.age;
            cout<<"\n\t\t Enter your Sex: ";
            cin>>record.sex;
            cout<<"\n\t\t Enter your Id: ";
            cin>>record.id;
        }

    }
    cout<<"\n\t Record successfully edited!"<<endl;
    cout<<"\n\t---------------------------------------"<<endl;

}
void deleterecord(int m)
{
//first search id m and delete from Record Array
}
int Record::getid()
{
//return id


}
void Record::displayAll()
{
//display name, id, sex and age
    ifstream theFile("Records.txt");
    cout<<"\n\tALL RECORDS"<<endl;
    cout<<"\n\t---------------------------------------"<<endl;
    while(theFile >> record.id >> record.nameFirst >> record.nameSecond >> record.sex >> record.age )
    {
        cout <<"\n\t"<< record.id <<" "<< record.nameFirst <<" "<<record.nameSecond<<" "<<record.sex<<" "<<record.age<<endl;
    }
    cout<<"\n\t---------------------------------------"<<endl;
}


void Record::displayId(int id)
{
//display name, id, sex and age
    ifstream theFile("Records.txt");
    cout<<"\n\t---------------------------------------"<<endl;
    while(theFile >> record.id >> record.nameFirst >> record.nameSecond >> record.sex >> record.age )
    {
        if(record.id == id)
        {
            cout <<"\n\t"<< record.id <<" "<< record.nameFirst <<" "<<record.nameSecond<<" "<<record.sex<<" "<<record.age<<endl;
        }
    }
    cout<<"\n\t---------------------------------------"<<endl;
}
int Record::search(int k)
{
//compare id with k and return 1 if the same else 0
    ifstream theFile("Records.txt");
    while(theFile >> record.id >> record.nameFirst >> record.nameSecond >> record.sex >> record.age )
    {
        if(record.id == k)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int choice,n,numRec,k,key;
    n=0;

    do
    {
        cout<<"\n\t PERSONEL RECORDS"<<endl;
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\t\t1-Add New Record"<<endl;
        cout<<"\n\t\t2-Search Record"<<endl;
        cout<<"\n\t\t3-Edit Record"<<endl;
        cout<<"\n\t\t4-Delete Record"<<endl;
        cout<<"\n\t\t5-Display All Records"<<endl;
        cout<<"\n\t\t0-EXIT"<<endl;
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\t\tEnter Your choice:";
        cin>>choice;
        if(choice==1)
        {
            system("cls");
            cout<<"\n\t\tEnter Number of Records: ";
            cin>>numRec;
            record.addrecord(numRec);
//ask number of records to be saved and accept records
        }
        else if(choice==2)
        {
//accept id to be searched and call search function and displays if get
            system("cls");
            cout<<"\n\t\tEnter id to search: ";
            cin>>k;
            if(record.search(k) == 1)
            {
                record.displayId(k);
            }
            else
            {
                cout<<"\n\t\tNo Result! Try Again."<<endl;
            }


        }
        else if(choice==3)
        {
//accept id to be edited then search index then edit by accepting all information
            system("cls");
            cout<<"\n\t\tEnter id to edit record: ";
            cin>>k;
            if(record.search(k) == 1)
            {
                record.editrecord(k);
            }
            else
            {
                cout<<"\n\t\tThe record not available! Try Again."<<endl;
            }
        }
        else if(choice==4)
        {
//accept id to be deleted then search index then rearrange the array
        }
        else if(choice==5)
        {
//call display function repeatedly until the end of records
            system("cls");
            record.displayAll();
        }
        else if(choice==0);
//do nothing but exit
        else
        {
//display the message that it is invalid input
            system("cls");
            cout<<"Invalid choice! Try again!"<<endl;
        }
    }
    while(choice!=0);
}
