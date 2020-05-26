#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

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

void clrscr(){
  cout << "\033[2J\033[1;1H";
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
  ofstream fout;
  fout.open("Account.dat",ios::app|ios::binary);
  clrscr();
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
  clrscr();
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
  clrscr;
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
    clrscr();
    cout<<"Enter Year (Eg: 2020): ";
    cin>>yr;
    cout<<endl;
    cout<<"Enter Month (Eg: 10 for October): ";
    cin>>mn;
    cout<<endl;
    cout<<"Enter Date: ";
    cin>>dt;
    cout<<endl;
    clrscr();
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
    cout<<"No entries found. Please add a new entry."<<endl;
    fin.close();
  }
  cout<<"Enter month (Eg: 10 for October): ";
  cin>>mt;
  clrscr();
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
      cout<<"No entries found"<<endl;
    }
    fin.close();
  }


void Account::Set(){
  int budget;
  cout<<"Please enter the budget for this month: ";
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
  cout<<"3. Set monthly budget"<<endl;
  cout<<"4. Display a specific entry"<<endl;
  cout<<"5. Display monthly stats"<<endl;
  cout<<"6. Exit"<<endl;
  cout<<"\n Please enter your choice (1-6): ";
  cin>>choice;
  return choice;
}

int main()
{
  switch(menu()){
  case 1: {
    Account a1;
    a1.Add();
    return 0;
  }

  case 2: {
    Account a1;
    a1.old();
    return 0;
  }

  case 3: {
    Account a1;
    a1.Set();
    return 0;
  }
    
  case 4: {
    Account a1;
    a1.Display();
    return 0;
  }

  case 5: {
    Account a1;
    a1.displaymon();
    return 0;
  }
    
  case 6: {
    cout<<"Thank you for using the portal. Have a nice day!"<<endl;
    return 0;
  }

  default:{
    cout<<"Please choose between (1-6)."<<endl;
    return 0;
  }  
  return 0;
}

  
}  
