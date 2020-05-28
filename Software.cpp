#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class Account {
public:
  void Add();
  void old();
  void Display();
  void displaymon();
  void Set();
  void budget();
  int expenses();
  void edit();
private:
  int Groceries=0;
  int Vegetables=0;
  int Snacks=0;
  int Medicines=0;
  int Petrol=0;
  int Bills=0;
  int year=0;
  int month=0;
  int date=0;
  int total=0;
};

void Account::edit(){
    ifstream fin;
    fin.open("Account.dat");
    if(!fin){
        cout<<"No entries present"<<endl;
        fin.close();
    }
    else{
    fin.close();
    int dt=0,mn=0,yr=0;
    char choice;
    cout<<"Enter the year: ";
    cin>>yr;
    cout<<"Enter the month (5 for May): ";
    cin>>mn;
    cout<<"Enter the date: ";
    cin>>dt;
    fstream file;
    bool check = false;
    file.open("Account.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char *)this,sizeof(*this));
    while(!file.eof()){
        if(this->date == dt && this->month == mn && this->year == yr){
            check = true;
            int newTotal=0;
            cout<<"Groceries: "<<this->Groceries<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' or choice == 'Y'){
                cout<<"Enter new amount for Groceries: ";
                cin>>this->Groceries;
            }
            cout<<"Vegetables: "<<this->Vegetables<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' or choice == 'Y'){
                cout<<"Enter new amount for Vegetables: ";
                cin>>this->Vegetables;
            }
            cout<<"Snacks: "<<this->Snacks<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' or choice == 'Y'){
                cout<<"Enter new amount for Snacks: ";
                cin>>this->Snacks;
            }
            cout<<"Medicines: "<<this->Medicines<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' or choice == 'Y'){
                cout<<"Enter new amount for Medicines: ";
                cin>>this->Medicines;
            }
            cout<<"Petrol/Diesel: "<<this->Petrol<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' or choice == 'Y'){
                cout<<"Enter new amount for Petrol/Diesel: ";
                cin>>this->Petrol;
            }
            cout<<"Other Bills: "<<this->Bills<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' or choice == 'Y'){
                cout<<"Enter new amount for Other Bills: ";
                cin>>this->Bills;
            }
            cout<<"\n Successfully Edited!"<<endl;
            newTotal = (Groceries+Snacks+Vegetables+Medicines+Petrol+Bills);
            this->total = newTotal;
            file.seekp(-std::streampos{sizeof (*this)}, std::ios::cur);
            file.write((char *)this,sizeof(*this));
            break;
        }
        file.read((char *)this,sizeof(*this));
    }
    if (check == false){
        cout<<"\nNo entry found"<<endl;
    }
    }
}
int Account::expenses(){
  int total=0,mon=0;
  time_t t = time(0);
  struct tm * timeStruct = localtime(&t);
  mon= 1 + timeStruct->tm_mon;
  ifstream fin;
  fin.open("Account.dat");
  if(!fin){
    return 0;
  }
  else{
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof()){
      if(this->month == mon){
      total = total + this->total;
      }
      fin.read((char *)this,sizeof(*this));
    }
    return total;
  }
}

void Account::budget(){
  bool chk = false;
  int exp = 0;
  exp = expenses();
  ifstream fin;
  fin.open("Account.dat");
  if(fin){
  fin.read((char *)this,sizeof(*this));
   while(!fin.eof()){
      if(this->year == 0){
        chk = true;
        cout<<endl;
	      cout<<"Budget for this month: "<<date<<endl;
	      cout<<"Total expenses: "<<exp<<endl;
	      cout<<"Remaining budget: "<<(date-exp);
        cout<<endl<<endl;
	  }
      fin.read((char *)this,sizeof(*this));
    }
    if(chk == false){
      cout<<"Remainder: Budget not set"<<endl<<endl;
      cout<<"Total expenses: "<<exp<<endl;
    }
  }
  else{
    cout<<"Remainder: Budget not set"<<endl<<endl;
    cout<<"Total expenses: "<<exp<<endl;
    cout<<endl;
  }
  fin.close();
}

void Account::Add(){
    int tot=0;
    ofstream fout;
    fout.open("Account.dat",ios::app|ios::binary);
    system("cls");
    cout<<"Total amount spent on: \n"<<endl;
    cout<<"Groceries: ";
    cin>>Groceries;
    cout<<endl;
    cout<<"Vegetables: ";
    cin>>Vegetables;
    cout<<endl;
    cout<<"Snacks: ";
    cin>>Snacks;
    cout<<endl;
    cout<<"Medicines: ";
    cin>>Medicines;
    cout<<endl;
    cout<<"Petrol/Diesel: ";
    cin>>Petrol;
    cout<<endl;
    cout<<"Other Bills: ";
    cin>>Bills;
    cout<<endl;
    this->total = (Groceries + Vegetables + Snacks + Medicines + Petrol + Bills);
    tot = this->total;
    cout<<"Entry added successfully!"<<endl;
    time_t t = time(0);
    struct tm * timeStruct = localtime(&t);
    this->year = 1900 + timeStruct->tm_year;
    this->month = 1 + timeStruct->tm_mon;
    this->date = timeStruct-> tm_mday;
    fout.write((char *)this,sizeof(*this));
    fout.close();
}
void Account::old(){
  int yr=0,mn=0,dt=0,tot=0;
  system("cls");
  cout<<"Enter year: ";
  cin>>yr;
  cout<<"\nEnter month: ";
  cin>>mn;
  cout<<"\nEnter date: ";
  cin>>dt;

  // Checking for previous record

  ifstream fin;
  bool war = false;
  fin.open("Account.dat");
  if(fin){
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof()){
      if(this->year == yr && this->month == mn && this->date == dt){
	war = true;
	break;
      }
      fin.read((char *)this,sizeof(*this));
    }
  }
  fin.close();
  if(war == true){
    cout<<endl;
    cout<<"A previous entry exists for the entered date. You can check the record using the 'View previous entries' option."<<endl;
  }
  else{
  system("cls");
  cout<<"Total amount spent on: \n"<<endl;
  cout<<"Groceries: ";
  cin>>Groceries;
  cout<<endl;
  cout<<"Vegetables: ";
  cin>>Vegetables;
  cout<<endl;
  cout<<"Snacks: ";
  cin>>Snacks;
  cout<<endl;
  cout<<"Medicines: ";
  cin>>Medicines;
  cout<<endl;
  cout<<"Petrol/Diesel: ";
  cin>>Petrol;
  cout<<endl;
  cout<<"Other Bills: ";
  cin>>Bills;
  cout<<endl;
  this->total = (Groceries + Vegetables + Snacks + Medicines + Petrol + Bills);
  tot = this->total;
  cout<<"Entry added successfully!"<<endl;

  this->year = yr;
  this->month = mn;
  this->date = dt;

  // Writing it into the file
  ofstream fout;
  fout.open("Account.dat",ios::app|ios::binary);
  fout.write((char *)this,sizeof(*this));
  fout.close();
  }
}

void Account::Display(){
  bool ret = false;
  ifstream fin;
  fin.open("Account.dat");
  if(!fin){
    cout<<"No entries found. Please add a new entry."<<endl;
    fin.close();
  }
  else{
    int yr,mn,dt;
    system("cls");
    cout<<"Enter Year (Eg: 2020): ";
    cin>>yr;
    cout<<endl;
    cout<<"Enter Month (Eg: 10 for October): ";
    cin>>mn;
    cout<<endl;
    cout<<"Enter Date: ";
    cin>>dt;
    cout<<endl;
    system("cls");
    cout<<"Displaying the entry of: "<<dt<<"/"<<mn<<"/"<<yr<<endl<<endl;
	fin.read((char *)this,sizeof(*this));
    while(!fin.eof()){
      if(this->year == yr && this->month == mn && this->date == dt){
	ret = true;
	cout<<"      Category     |"<<"     Amount"<<endl;
	cout<<"-------------------x----------------"<<endl;
	cout<<"      Groceries    |"<<"     "<<this->Groceries<<endl;
	cout<<"-------------------x----------------"<<endl;
	cout<<"     Vegetables    |"<<"     "<<this->Vegetables<<endl;
	cout<<"-------------------x----------------"<<endl;
	cout<<"       Snacks      |"<<"     "<<this->Snacks<<endl;
	cout<<"-------------------x----------------"<<endl;
	cout<<"      Medicines    |"<<"     "<<this->Medicines<<endl;
	cout<<"-------------------x----------------"<<endl;
	cout<<"    Petrol/Diesel  |"<<"     "<<this->Petrol<<endl;
	cout<<"-------------------x----------------"<<endl;
	cout<<"     Other Bills   |"<<"     "<<this->Bills<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"       Total       |"<<"     "<<this->total<<endl;
	break;
      }
      fin.read((char *)this,sizeof(*this));
    }
    if(ret == false){
      cout<<"Record not found."<<endl;
    }
    fin.close();
  }
}

void Account::displaymon(){
  int mt=0;
  bool ret = false,first=true;
  ifstream fin;
  fin.open("Account.dat");
  if(!fin){
    cout<<"\nNo entries found. Please add a new entry."<<endl;
    fin.close();
  }
  else {
      cout<<"Enter month (Eg: 10 for October): ";
      cin>>mt;
      system("cls");
      const char * months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
      fin.read((char *)this,sizeof(*this));
      while(!fin.eof()){
        if(this->month == mt){
          if(first==true){
        cout<<"Displaying stats for the month of "<<months[mt-1]<<endl<<endl;
        cout<<setw(9)<<"DAY"<<setw(6)<<"|"<<setw(20)<<"TOTAL EXPENSES"<<""<<endl;
        first = false;
          }
          cout<<setw(9)<<this->date<<setw(6)<<"|"<<setw(20)<<this->total<<""<<endl;
          ret = true;
        }
        fin.read((char *)this,sizeof(*this));
      }
        if(ret == false){
          cout<<"\nNo entries found"<<endl;
        }
        fin.close();
  }
  }


void Account::Set(){
  int budget;
  cout<<"\nPlease enter the budget for this month: ";
  cin >>budget;
  ofstream fout;
  fout.open("Account.dat",ios::app);
  fout.close();
  fstream file;
  bool check = false;
  file.open("Account.dat",ios::in|ios::out|ios::ate|ios::binary);
  file.seekg(0);
  file.read((char *)this,sizeof(*this));
   while(!file.eof()){
      if(this->year == 0){
	check = true;
	date = budget;
	// file.seekp((file.tellg())-sizeof(*this));
	file.seekp(-std::streampos{sizeof (*this)}, std::ios::cur);
	file.write((char *)this,sizeof(*this));
	break;
      }
      file.read((char *)this,sizeof(*this));
   }
   if(check == false){
     this->year = 0;
     this->month = 0;
     this->date = budget;
     ofstream fout;
     fout.open("Account.dat",ios::app|ios::binary);
     fout.write((char *)this,sizeof(*this));
     fout.close();
   }
}

int menu(){
  Account a0;
  int choice=0;
  cout<<"=================================="<<endl;
  cout<<"        ACCOUNTING PORTAL"<<endl;
  cout<<"=================================="<<endl;
  a0.budget();
  cout<<"************** MENU **************"<<endl;
  cout<<endl;
  cout<<"1. Add a new entry"<<endl;
  cout<<"2. Add an old entry"<<endl;
  cout<<"3. Edit an old entry"<<endl;
  cout<<"4. Set monthly budget"<<endl;
  cout<<"5. Display a specific entry"<<endl;
  cout<<"6. Display monthly stats"<<endl;
  cout<<"0. Exit"<<endl;
  cout<<"\n Please enter your choice (1-6): ";
  cin>>choice;
  return choice;
}

int main()
{
  while(1){
      switch(menu()){
      case 1: {
        Account a1;
        a1.Add();
        cout<<"\nPress any key to return to Menu"<<endl;
        getch();
        system("cls");
        break;
      }

      case 2: {
        Account a1;
        a1.old();
        cout<<"\nPress any key to return to Menu"<<endl;
        getch();
        system("cls");
        break;
      }
      case 3: {
        Account a1;
        a1.edit();
        cout<<"\nPress any key to return to Menu"<<endl;
        getch();
        system("cls");
        break;
      }
      case 4: {
        Account a1;
        a1.Set();
        cout<<"\nBudget set successfully!"<<endl;
        cout<<"\nPress any key to return to Menu"<<endl;
        getch();
        system("cls");
        break;
      }

      case 5: {
        Account a1;
        a1.Display();
        cout<<"\nPress any key to return to Menu"<<endl;
        getch();
        system("cls");
        break;
      }

      case 6: {
        Account a1;
        a1.displaymon();
        cout<<"\nPress any key to return to Menu"<<endl;
        getch();
        system("cls");
        break;
      }

      case 0: {
        system("cls");
        cout<<"\nThank you for using the portal. Have a nice day!"<<endl;
        return 0;
      }

      default:{
        cout<<"\nPlease choose between (0-6)."<<endl;
        cout<<"\nPress any key to return to Menu"<<endl;
        getch();
        system("cls");
        break;
      }
    }
  }
    return 0;
}
