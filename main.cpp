#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include<iostream>
#include<fstream>
#include <string>

using namespace std;


class Contact
{
private:
    char firstName[20];
    char lastName[20];
    long PhoneNumber;
    bool isInFavorite = false;
    bool isBlocked = false;
    int temp;
public:
    void clearScreen();
    void splashScreen();
    void insertFirst(int);
    void insertLast(int);
    void editPhoneNumber(string,bool);
    void deletePhoneNumber(string);
    void display(bool, bool);
    void displayName(string);
    void displayPhoneNumber(long);
    void sortA_Z();
    void block(int id);
    int  search(string);
    int  searchPhoneNumber(long);
};

Contact contact;

void Contact::clearScreen()
{
    system("clear");
}

void Contact::splashScreen()
{
    cout<<"\tMicroLink I.T college Department of Computer Science";
    cout<<"\n\t\tAssignment of Fundamental Programming II  ";
    cout<<"\n\t\t\t\tSection Two";
    cout<<"\n\n\tGROUP MEMBERS: ";
    cout<<"\n\tNo  FullName          Id_Num";
    cout<<"\n\t1.  Ebisa     Kebede  15026";
    cout<<"\n\t2.  Mayko     Solomon 15026";
    cout<<"\n\t3.  kalkidan  Alemu   15026\n\n"<<endl;

}


void Contact::insertLast(int numRec)
{
    ofstream theFile("Records.txt", ios::app);
    int n = 1;
    while(n<=numRec)
    {
        contact.clearScreen();
        cout<<"\n\t ADDING NEW CONTACT"<<endl;
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\tEnter Record "<<n<<endl;
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\t\t Enter First Name: ";
        cin>>contact.firstName;
        cout<<"\n\t\t Enter Last Name: ";
        cin>>contact.lastName;
        cout<<"\n\t\t Enter Your Number: ";
        cin>>contact.PhoneNumber;
        cout<<"\n\t\t Do you wann enter to Favorite [press 1 else 0]: ";
        cin>>contact.temp;
        if(contact.temp == 1)
        {
            contact.isInFavorite = true;
        }
        else
        {
            contact.isInFavorite = false;
        }
        contact.isBlocked =false;
        contact.isBlocked =false;
        cout<<"\n\t---------------------------------------"<<endl;
        //assign object value to txt file
        theFile << contact.firstName <<" "<<contact.lastName<<" "<<contact.PhoneNumber<<" "<<contact.isBlocked<<" "<<contact.isInFavorite<<endl;

        n++;
    }
    theFile.close();
    cout<<"\n\t---------------------------------------"<<endl;
    cout<<"\n\t Record successfully added!"<<endl;
    cout<<"\n\t---------------------------------------"<<endl;
}

void Contact::insertFirst(int numRec)
{
    ifstream file ("Records.txt");
    ofstream Temp("temp.txt");
    cout<<"\n\t---------------------------------------"<<endl;
    int n = 1;
    while(n<=numRec)
    {
        contact.clearScreen();
        cout<<"\n\t ADDING NEW CONTACT"<<endl;
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\tEnter Record "<<n<<endl;
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\t\t Enter First Name: ";
        cin>>contact.firstName;
        cout<<"\n\t\t Enter Last Name: ";
        cin>>contact.lastName;
        cout<<"\n\t\t Enter Your Number: ";
        cin>>contact.PhoneNumber;
        cout<<"\n\t\t Do you wann enter to Favorite [press 1 else 0]: ";
        cin>>contact.temp;
        if(contact.temp == 1)
        {
            contact.isInFavorite = true;
        }
        else
        {
            contact.isInFavorite = false;
        }
        contact.isBlocked = false;
        cout<<"\n\t---------------------------------------"<<endl;
        //assign object value to txt file
        Temp << contact.firstName <<" "<<contact.lastName<<" "<<contact.PhoneNumber<<" "<<contact.isBlocked<<" "<<contact.isInFavorite<<endl;

        n++;
    }

    cout<<"\n\t---------------------------------------"<<endl;
    while(file >> contact.firstName>>contact.lastName>>contact.PhoneNumber>>contact.isBlocked>>contact.isInFavorite )
    {
        Temp << contact.firstName <<" "<<contact.lastName<<" "<<contact.PhoneNumber<<" "<<contact.isBlocked<<" "<<contact.isInFavorite<<endl;
    }

    Temp.close();
    file.close();
    remove("Records.txt");
    rename("temp.txt","Records.txt");
    contact.clearScreen();
    cout<<"\n\t---------------------------------------"<<endl;
    cout<<"\n\t Record successfully added!"<<endl;
    cout<<"\n\t---------------------------------------"<<endl;

}

void Contact::editPhoneNumber(string k, bool block)
{
    ofstream Temp("temp.txt");
    ifstream file ("Records.txt");
    cout<<"\n\t---------------------------------------"<<endl;
    while(file >> contact.firstName>>contact.lastName>>contact.PhoneNumber>>contact.isBlocked>>contact.isInFavorite )
    {

        if(!block)
        {
            if(contact.firstName == k)
            {
                contact.clearScreen();
                cout<<"\n\t EDIT CONTACT"<<endl;
                cout<<"\n\t---------------------------------------"<<endl;
                cout<<"\n\t\t Enter First Name: ";
                cin>>contact.firstName;
                cout<<"\n\t\t Enter Last Name: ";
                cin>>contact.lastName;
                cout<<"\n\t\t Enter Your Number: ";
                cin>>contact.PhoneNumber;
                cout<<"\n\t\t Do you wann enter to Favorite [press 1 else 0]: ";
                cin>>contact.temp;
                if(contact.temp == 1)
                {
                    contact.isInFavorite = true;
                }
                else
                {
                    contact.isInFavorite = false;
                }
            }
            else if(contact.lastName == k)
            {
                contact.clearScreen();
                cout<<"\n\t ADDING NEW CONTACT"<<endl;
                cout<<"\n\t---------------------------------------"<<endl;
                cout<<"\n\t\t Enter First Name: ";
                cin>>contact.firstName;
                cout<<"\n\t\t Enter Last Name: ";
                cin>>contact.lastName;
                cout<<"\n\t\t Enter Your Number: ";
                cin>>contact.PhoneNumber;
                cout<<"\n\t\t Do you wann enter to Favorite [press 1 else 0]: ";
                cin>>contact.temp;
                if(contact.temp == 1)
                {
                    contact.isInFavorite = true;
                }
                else
                {
                    contact.isInFavorite = false;
                }
            }

        }
        else
        {
            contact.isBlocked = true;
        }
        Temp << contact.firstName <<" "<<contact.lastName<<" "<<contact.PhoneNumber<<" "<<contact.isBlocked<<" "<<contact.isInFavorite<<endl;
    }
    Temp.close();
    file.close();
    remove("Records.txt");
    rename("temp.txt","Records.txt");
    contact.clearScreen();

    if(!block)
    {
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\t Contact successfully edited!"<<endl;
        cout<<"\n\t---------------------------------------"<<endl;
    }
    else
    {
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\t Contact successfully blocked!"<<endl;
        cout<<"\n\t---------------------------------------"<<endl;
    }



}


void Contact::deletePhoneNumber(string key)
{
    ifstream file ("Records.txt");
    ofstream Temp("temp.txt");
    cout<<"\n\t---------------------------------------"<<endl;
    while(file >> contact.firstName>>contact.lastName>>contact.PhoneNumber>>contact.isBlocked>>contact.isInFavorite )
    {
        if(contact.firstName == key);
        else if(contact.lastName == key);
        else
        {
            Temp << contact.firstName <<" "<<contact.lastName<<" "<<contact.PhoneNumber<<" "<<contact.isBlocked<<" "<<contact.isInFavorite<<endl;
        }

    }
    Temp.close();
    file.close();
    remove("Records.txt");
    rename("temp.txt","Records.txt");
    contact.clearScreen();
    cout<<"\n\t---------------------------------------"<<endl;
    cout<<"\n\t Record successfully deleted!"<<endl;
    cout<<"\n\t---------------------------------------"<<endl;

}


void Contact::display(bool blocked, bool favorite)
{
    cout<<"\n\tALL Contacts"<<endl;
    cout<<"\n\t---------------------------------------"<<endl;
    int n=0;
    ifstream file ("Records.txt");

    //check if the file is empty

    cout <<"\n\tNo    FullName     phonenumber "<<endl;
    while(file >> contact.firstName>>contact.lastName>>contact.PhoneNumber>>contact.isBlocked>>contact.isInFavorite)
    {
        if(blocked)
        {
            if(contact.isBlocked == 1)
                cout <<"\n\t"<<++n<<". "<< contact.firstName <<" "<< contact.lastName<<" "<<contact.PhoneNumber<<endl;
        }
        else if(favorite)
        {
            if(contact.isInFavorite == 1)
                cout <<"\n\t"<<++n<<". "<< contact.firstName <<" "<< contact.lastName<<" "<<contact.PhoneNumber<<endl;
        }
        else if(!blocked && !favorite)
        {
            cout <<"\n\t"<<++n<<". "<< contact.firstName <<" "<< contact.lastName<<" "<<contact.PhoneNumber<<endl;
        }

    }
    cout<<"\n\t---------------------------------------"<<endl;

    file.close();
}


void Contact::displayName(string key)
{
    ifstream file ("Records.txt");

    int n = 0;
    cout<<"\n\t---------------------------------------"<<endl;
    cout <<"\n\tNo    FullName      phonenumber  "<<endl;
    while(file >> contact.firstName>>contact.lastName>>contact.PhoneNumber>>contact.isBlocked>>contact.isInFavorite)
    {
        string phoneNumber = to_string(contact.PhoneNumber);
        if(contact.firstName == key || contact.lastName == key)
            cout <<"\n\t"<<++n<<". "<< contact.firstName <<" "<< contact.lastName <<"     "<<contact.PhoneNumber<<endl;
    }
    cout<<"\n\t---------------------------------------"<<endl;
    file.close();
}
void Contact::displayPhoneNumber(long phonenumber)
{
    int n = 0;
    ifstream file ("Records.txt");
    cout<<"\n\t---------------------------------------"<<endl;
    cout <<"\n\tNo    FullName     phonenumber  "<<endl;
    while(file >> contact.firstName>>contact.lastName>>contact.PhoneNumber>>contact.isBlocked>>contact.isInFavorite)
    {
        if(contact.PhoneNumber == phonenumber)
        {
            cout <<"\n\t"<<++n<<". "<< contact.firstName <<" "<< contact.lastName <<"     "<<contact.PhoneNumber<<endl;
            break;
        }

    }
    cout<<"\n\t---------------------------------------"<<endl;
    file.close();
}
int Contact::search(string k)
{
    ifstream file ("Records.txt");
    while(file >> contact.firstName>>contact.lastName>>contact.PhoneNumber>>contact.isBlocked>>contact.isInFavorite )
    {
        if(contact.firstName == k)
        {
            return 1;
            break;
        }
        else if(contact.lastName == k)
        {
            return 1;
            break;
        }
    }
    return 0;
}


int Contact::searchPhoneNumber(long phonenumber)
{
    ifstream file ("Records.txt");
    while(file >> contact.firstName>>contact.lastName>>contact.PhoneNumber>>contact.isBlocked>>contact.isInFavorite )
    {
        if(contact.PhoneNumber == phonenumber)
        {
            return 1;
            break;
        }
    }
    return 0;
}
void Contact::sortA_Z()
{
    // Empty vector holding all names from file
    vector<string> names;
    ifstream file ("Records.txt");
    ofstream temp("temp.txt");
    if(!file.is_open())
        cout << "Unable to open file\n";

    // this is wrong, by the way: while(in.good()){
    string word;
    while(getline(file, word))
        names.push_back(word);

    sort(names.begin(), names.end());

    for (size_t i = 0; i < names.size(); i++)
        temp << names[i] <<endl;
    file.close();
    temp.close();
    remove("Records.txt");
    rename("temp.txt","Records.txt");


    cout<<"\n\t---------------------------------------"<<endl;
    cout<<"\n\t Record successfully sorted!"<<endl;
    cout<<"\n\t---------------------------------------"<<endl;
}


int main()
{
    int choice,n,numRec,reopenCounter;
    string key_;
    char key;
    int _key_;
    n=0;

    //console background color f-white and text color 0-black
    system("color f0");

    //splashScreen
    contact.splashScreen();
    system("pause");
    contact.clearScreen();
    do
    {
        cout<<"\n\t PHONEBOOK ";
        cout<<"\n\t---------------------------------------"<<endl;
        cout<<"\n\t\t1-Insert First"<<endl;
        cout<<"\n\t\t2-Insert Last"<<endl;
        cout<<"\n\t\t3-Edit Phonenumber"<<endl;
        cout<<"\n\t\t4-Delete Phonenumber"<<endl;
        cout<<"\n\t\t5-Display All Phonenumbers"<<endl;
        cout<<"\n\t\t6-Display All Blocked Phonenumbers"<<endl;
        cout<<"\n\t\t7-Display All Favorite Phonenumbers"<<endl;
        cout<<"\n\t\t8-SearchbyName"<<endl;
        cout<<"\n\t\t9-SearchbyPhonenumber"<<endl;
        cout<<"\n\t\t10-Sort[a-z]"<<endl;
        cout<<"\n\t\t11-Block Phonenumber"<<endl;
        cout<<"\n\t\t0-EXIT"<<endl;
        cout<<"\n\t---------------------------------------";
        cout<<"\n\t\tEnter Your choice:";
        cin>>choice;
        if(choice==1)
        {
            contact.clearScreen();
            cout<<"\n\t\tEnter Number of Records: ";
            cin>>numRec;
            contact.insertFirst(numRec);
        }
        else if(choice == 2)
        {
            contact.clearScreen();
            cout<<"\n\t\tEnter Number of Records: ";
            cin>>numRec;
            contact.insertLast(numRec);
        }
        else if(choice == 3)
        {
            contact.clearScreen();
            reopenCounter = 0;
reenter1:
            cout<<"\n\t\tEnter first name(last name) to edit contact: ";
            cin>>key_;
            if(contact.search(key_) == 1)
            {
                contact.editPhoneNumber(key_,false);
            }
            else
            {
                cout<<"\n\t\tThe phone number not available! Try Again."<<endl;
                reopenCounter++;
                if(reopenCounter < 2)
                {
                    goto reenter1;
                }
                else
                {
                    cout<<"\n\t\tTime Out! Try Again later."<<endl;

                }
            }

        }
        else if(choice == 4)
        {
            contact.clearScreen();
            reopenCounter = 0;
reenter2:

            cout<<"\n\t\tEnter first name or last name to delete contact: ";
            cin>>key_;
            if(contact.search(key_) == 1)
            {
                contact.deletePhoneNumber(key_);
            }
            else
            {
                cout<<"\n\t\tThe contact not available! Try Again."<<endl;
                reopenCounter++;
                if(reopenCounter < 2)
                {
                    goto reenter2;
                }
                else
                {
                    cout<<"\n\t\tTime Out! Try Again later."<<endl;

                }
            }

        }
        else if(choice == 5)
        {
            contact.clearScreen();
            contact.display(false, false);
        }
        else if(choice == 6)
        {
            contact.clearScreen();
            contact.display(true, false);
        }
        else if(choice == 7)
        {
            contact.clearScreen();
            contact.display(false,true);
        }
        else if(choice==8)
        {
            contact.clearScreen();
            reopenCounter = 0;
reenter:
            cout<<"\n\t\tEnter first name or last name to search contact: ";
            cin>>key_;
            if(contact.search(key_) == 1)
            {
                contact.displayName(key_);
            }
            else
            {
                cout<<"\n\t\tNo Result! Try Again."<<endl;
                reopenCounter++;
                if(reopenCounter < 2)
                {
                    goto reenter;
                }
                else
                {
                    cout<<"\n\t\tTime Out! Try Again later."<<endl;

                }

            }


        }
        else if(choice==9)
        {
            contact.clearScreen();
            reopenCounter = 0;
reenter4:
            cout<<"\n\t\tEnter first phonenumber to search contact: ";
            cin>>_key_;
            if(contact.searchPhoneNumber(_key_) == 1)
            {
                contact.displayPhoneNumber(_key_);
            }
            else
            {
                cout<<"\n\t\tNo Result! Try Again."<<endl;
                reopenCounter++;
                if(reopenCounter < 2)
                {
                    goto reenter4;
                }
                else
                {
                    cout<<"\n\t\tTime Out! Try Again later."<<endl;

                }

            }

        }
        else if(choice==10)
        {
            contact.clearScreen();
            contact.sortA_Z();

        }
        else if(choice == 11)
        {
            contact.clearScreen();
            reopenCounter = 0;
reenter5:
            cout<<"\n\t\tEnter first name to block contact: ";
            cin>>key_;
            if(contact.search(key_) == 1)
            {
                contact.editPhoneNumber(key_,true);
            }
            else
            {
                cout<<"\n\t\tNo Result! Try Again."<<endl;
                reopenCounter++;
                if(reopenCounter < 2)
                {
                    goto reenter5;
                }
                else
                {
                    cout<<"\n\t\tTime Out! Try Again later."<<endl;

                }

            }

        }
        else if(choice == 12)
        {
            contact.clearScreen();
            reopenCounter = 0;
reenter6:
            cout<<"\n\t\tEnter first name to add Favorite contact: ";
            cin>>key_;
            if(contact.search(key_) == 1)
            {
                contact.editPhoneNumber(key_,true);
            }
            else
            {
                cout<<"\n\t\tNo Result! Try Again."<<endl;
                reopenCounter++;
                if(reopenCounter < 2)
                {
                    goto reenter6;
                }
                else
                {
                    cout<<"\n\t\tTime Out! Try Again later."<<endl;

                }

            }

        }
        else if(choice==0);
        else
        {
            system("clear");
            cout<<"\n\t\tInvalid choice! Try again!"<<endl;
        }

    }
    while(choice!=0);
}




