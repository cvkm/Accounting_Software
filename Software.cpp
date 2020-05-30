#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int countDig(int a){
    if(a == 0){
        return 1;
    }
    int count = 0;
    while(a != 0){
        a = a/10;
        count++;
    }
    return count;
}


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
  char Groc_notes[100] = "";
  int Vegetables=0;
  char Veg_notes[100] = "";
  int Snacks=0;
  char Snacks_notes[100] = "";
  int Medicines=0;
  char Med_notes[100] = "";
  int Petrol=0;
  char Petrol_notes[100] = "";
  int Milk=0;
  char Milk_notes[100] = "";
  int npaper=0;
  char news_notes[100] = "";
  int flower=0;
  char flower_notes[100] = "";
  int car=0;
  char car_notes[100] = "";
  int shop=0;
  char shop_notes[100] = "";
  int maint=0;
  char maint_notes[100] = "";
  int gas=0;
  char gas_notes[100] = "";
  int maid=0;
  char maid_notes[100] = "";
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
    system("cls");
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
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Groceries: ";
                cin>>this->Groceries;
            }
            cout<<"Vegetables/Fruits: "<<this->Vegetables<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Vegetables: ";
                cin>>this->Vegetables;
            }
            cout<<"Milk: "<<this->Milk<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Milk: ";
                cin>>this->Milk;
            }
            cout<<"Snacks: "<<this->Snacks<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Snacks: ";
                cin>>this->Snacks;
            }
            cout<<"Medicines: "<<this->Medicines<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Medicines: ";
                cin>>this->Medicines;
            }
            cout<<"Petrol/Diesel: "<<this->Petrol<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Petrol/Diesel: ";
                cin>>this->Petrol;
            }
            cout<<"Shopping/Food: "<<this->shop<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Shopping/Food: ";
                cin>>this->shop;
            }
            cout<<"Other Bills: "<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Newspaper Bill: "<<this->npaper<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Newspaper Bill: ";
                cin>>this->npaper;
            }
            cout<<"Flower Bill: "<<this->flower<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Flower Bill: ";
                cin>>this->flower;
            }
            cout<<"Car Cleaning Bill: "<<this->car<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Car Cleaning Bill: ";
                cin>>this->car;
            }
            cout<<"Maintenance: "<<this->maint<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Maintenance: ";
                cin>>this->maint;
            }
            cout<<"Gas Bill: "<<this->gas<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Gas Bill: ";
                cin>>this->gas;
            }
            cout<<"Maid: "<<this->maid<<"  "<<"Do you want to change? (y or n): ";
            cin>>choice;
            if(choice=='y' || choice == 'Y'){
                cout<<"Enter new amount for Maid: ";
                cin>>this->maid;
            }
            }
            cout<<"\n Successfully Edited!"<<endl;
            newTotal = (Groceries+Snacks+Milk+Vegetables+Medicines+Petrol+shop+npaper+car+maid+maint+gas+flower);
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
    char choice;
    ofstream fout;
    fout.open("Account.dat",ios::app|ios::binary);
    system("cls");
    cout<<"Total amount spent on: \n"<<endl;
    cout<<"Groceries: ";
    cin>>Groceries;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Groc_notes,100);
    }
    cout<<"\nVegetables/Fruits: ";
    cin>>Vegetables;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Veg_notes,100);
    }
    cout<<"\nMilk: ";
    cin>>Milk;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Milk_notes,100);
    }
    cout<<"\nSnacks: ";
    cin>>Snacks;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Snacks_notes,100);
    }
    cout<<"\nMedicines: ";
    cin>>Medicines;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Med_notes,100);
    }
    cout<<"\nPetrol/Diesel: ";
    cin>>Petrol;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Petrol_notes,100);
    }
    cout<<"\nShopping/Food: ";
    cin>>shop;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(shop_notes,100);
    }
    cout<<"Do you want to add other bills (y or n): ";
    cin>>choice;
    if(choice=='y'||choice=='Y'){
    cout<<"\nNewspaper Bill: ";
    cin>>npaper;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(news_notes,100);
    }
    cout<<"\nFlower Bill: ";
    cin>>flower;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(flower_notes,100);
    }
    cout<<"\nGas Bill: ";
    cin>>gas;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(gas_notes,100);
    }
    cout<<"\nMaintenance: ";
    cin>>maint;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(maint_notes,100);
    }
    cout<<"\nMaid: ";
    cin>>maid;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(maid_notes,100);
    }
    cout<<"\nCar Cleaning Bill: ";
    cin>>car;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(car_notes,100);
    }
    }
    this->total = (Groceries+Snacks+Milk+Vegetables+Medicines+Petrol+shop+npaper+car+maid+maint+gas+flower);
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
  char choice;
  cout<<"Total amount spent on: \n"<<endl;
    cout<<"Groceries: ";
    cin>>Groceries;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Groc_notes,100);
    }
    cout<<"\nVegetables/Fruits: ";
    cin>>Vegetables;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Veg_notes,100);
    }
    cout<<"\nMilk: ";
    cin>>Milk;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Milk_notes,100);
    }
    cout<<"\nSnacks: ";
    cin>>Snacks;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Snacks_notes,100);
    }
    cout<<"\nMedicines: ";
    cin>>Medicines;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Med_notes,100);
    }
    cout<<"\nPetrol/Diesel: ";
    cin>>Petrol;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(Petrol_notes,100);
    }
    cout<<"\nShopping/Food: ";
    cin>>shop;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(shop_notes,100);
    }
    cout<<"Do you want to add other bills (y or n): ";
    cin>>choice;
    if(choice=='y'||choice=='Y'){
    cout<<"\nNewspaper Bill: ";
    cin>>npaper;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(news_notes,100);
    }
    cout<<"\nFlower Bill: ";
    cin>>flower;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(flower_notes,100);
    }
    cout<<"\nGas Bill: ";
    cin>>gas;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(gas_notes,100);
    }
    cout<<"\nMaintenance: ";
    cin>>maint;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(maint_notes,100);
    }
    cout<<"\nMaid: ";
    cin>>maid;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(maid_notes,100);
    }
    cout<<"\nCar Cleaning Bill: ";
    cin>>car;
    cout<<endl;
    cout<<"Do you want to add notes? (y or n): ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"Enter Notes (Max 100 characters): ";
        cin.ignore();
        cin.getline(car_notes,100);
    }
    }
  this->total = (Groceries+Snacks+Milk+Vegetables+Medicines+Petrol+shop+npaper+car+maid+maint+gas+flower);
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
	cout<<"     CATEGORY      |"<<"    AMOUNT    |"<<setw(9)<<""<<"NOTES"<<endl;
	cout<<"-------------------x-----------------------------------------------------"<<endl;
	cout<<"     Groceries     |"<<"      "<<this->Groceries<<setw(9-countDig(this->Groceries))<<"|"<<setw(3)<<""<<Groc_notes<<endl;
	cout<<"-------------------x-----------------------------------------------------"<<endl;
	cout<<" Vegetables/Fruits |"<<"      "<<this->Vegetables<<setw(9-countDig(this->Vegetables))<<"|"<<setw(3)<<""<<Veg_notes<<endl;
	cout<<"-------------------x-----------------------------------------------------"<<endl;
	cout<<"        Milk       |"<<"      "<<this->Milk<<setw(9-countDig(this->Milk))<<"|"<<setw(3)<<""<<Milk_notes<<endl;
	cout<<"-------------------x-----------------------------------------------------"<<endl;
	cout<<"       Snacks      |"<<"      "<<this->Snacks<<setw(9-countDig(this->Snacks))<<"|"<<setw(3)<<""<<Snacks_notes<<endl;
	cout<<"-------------------x-----------------------------------------------------"<<endl;
	cout<<"     Medicines     |"<<"      "<<this->Medicines<<setw(9-countDig(this->Medicines))<<"|"<<setw(3)<<""<<Med_notes<<endl;
	cout<<"-------------------x-----------------------------------------------------"<<endl;
	cout<<"   Petrol/Diesel   |"<<"      "<<this->Petrol<<setw(9-countDig(this->Petrol))<<"|"<<setw(3)<<""<<Petrol_notes<<endl;
	cout<<"-------------------x-----------------------------------------------------"<<endl;
	cout<<"   Shopping/Food   |"<<"      "<<this->shop<<setw(9-countDig(this->shop))<<"|"<<setw(3)<<""<<shop_notes<<endl;
	if(this->npaper!=0){
        cout<<"-------------------x-----------------------------------------------------"<<endl;
        cout<<"  Newspaper Bill   |"<<"     "<<this->npaper<<setw(9-countDig(this->npaper))<<"|"<<setw(3)<<""<<news_notes<<endl;
	}
    if(this->flower!=0){
        cout<<"-------------------x-----------------------------------------------------"<<endl;
        cout<<"    Flower Bill    |"<<"     "<<this->flower<<setw(9-countDig(this->flower))<<"|"<<setw(3)<<""<<flower_notes<<endl;
	}
	if(this->car!=0){
	    cout<<"-------------------x-----------------------------------------------------"<<endl;
        cout<<" Car Cleaning Bill |"<<"     "<<this->car<<setw(9-countDig(this->car))<<"|"<<setw(3)<<""<<car_notes<<endl;
	}
	if(this->maint!=0){
	    cout<<"-------------------x-----------------------------------------------------"<<endl;
        cout<<"    Maintenance    |"<<"     "<<this->maint<<setw(9-countDig(this->maint))<<"|"<<setw(3)<<""<<maint_notes<<endl;
	}
	if(this->maid!=0){
	    cout<<"-------------------x-----------------------------------------------------"<<endl;
        cout<<"        Maid       |"<<"     "<<this->maid<<setw(9-countDig(this->maid))<<"|"<<setw(3)<<""<<maid_notes<<endl;
	}
	if(this->gas!=0){
	    cout<<"-------------------x-----------------------------------------------------"<<endl;
        cout<<"      Gas Bill     |"<<"     "<<this->gas<<setw(9-countDig(this->gas))<<"|"<<setw(3)<<""<<gas_notes<<endl;
	}
	char dash = 196;
	cout<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash;
	cout<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash;
	cout<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash;
	cout<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<dash<<endl;
	cout<<"       TOTAL       |"<<"      "<<this->total<<setw(9-countDig(this->total))<<"|"<<setw(6)<<""<<"GRAND TOTAL"<<endl;
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
  cout<<"\n Please enter your choice (0-6): ";
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
