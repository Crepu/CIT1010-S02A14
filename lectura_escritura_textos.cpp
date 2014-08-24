#include <iostream.h>
#include <stdlib.h>
#include <fstream.h>
#include <iomanip>

using namespace std;

int write(void);
int write(void)
{
    ofstream outfile;
    char firstname[18],
         lastname[25],
         address[28],
         city[18],
         state[3],
         zipcode[6],
         phonenumber[11];
    int index;

    outfile.open("L:\\BU-521\\PersonalData.txt",ios::app);

    cout<<"Enter your First Name: ";
    cin>>firstname;
    cin.ignore();
    cout<<"Enter your Last Name: ";
    cin>>lastname;
    cin.ignore();
    cout<<"Enter your Address: ";
    cin.getline(address, sizeof(address));
    cin.ignore();
    cout<<"Enter your City: ";
    cin.getline(city, 18);
    cout<<"Enter your State: ";
    cin.getline(state, sizeof(state));
    cin.ignore();
    cout<<"Enter your ZipCode: ";
    cin.getline(zipcode, 6);
    cout<<"Enter your Phone Number: ";
    cin.getline(phonenumber, sizeof(phonenumber));
    cin.ignore();

    outfile<<firstname<<setw(2)<<lastname<<setw(2)<<address<<setw(2)<<city<<setw(2)<<state<<setw(2)<<zipcode<<setw(2)<<phonenumber<<endl;
    outfile.close();
    cout<<"Writing Completed."<<endl;
    return 0;
}

int read(void);
int read(void)
{
    ifstream input;
    input.open("L:\\BU-521\\PersonalData.txt",ios::in);

    char firstname[18],
         lastname[25],
         address[28],
         city[18],
         state[3],
         zipcode[6],
         phonenumber[11];

    int counter =1;
    while(!input.eof())
    {
        input>>firstname>>lastname>>address>>city>>state>>zipcode>>phonenumber;
        cout<<"Information Required. "<<endl;
        cout<<firstname<<setw(1)<<lastname<<endl;
        cout<<address<<endl;
        cout<<city<<setw(2)<<state<<setw(2)<<zipcode<<endl;
        cout<<phonenumber<<endl;
        counter++;
        cout<<endl;
    }
    cout<<"Reading Completed. "<<endl;
    input.close();
    return 0;
}

 
int main()
{
      int choice;
      char ch;

      do{
          cout<<endl;
          cout<<"Please choose from the following: \n";
          cout<<"\t1. Read Data. \n";
          cout<<"\t2. Write Data. \n";
          cout<<"\t3. Quit. \n";
          cout<<endl;
          cout<<"Your choice: ";
          cin>>choice;


           switch(choice)
          {
             case 1:
                     read();
                   break;
             case 2:
                     write();
                   break;
             case 3:

                   break;
             default:
                   cout<<"\tInvalid entry!"<<endl;
           }
           cout<<"\nWould you like to try again (y/n): ";
           cin>>ch;

     }while(ch == 'y' || ch == 'Y');

      system("PAUSE");
      return 0;
}

