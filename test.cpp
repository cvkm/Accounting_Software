#include <iostream>
#include <ctime>
#include <stdio.h>

void printTime() {
    time_t t = time(0); 
    struct tm * timeStruct = localtime(&t);
    std::cout <<typeid (timeStruct->tm_year).name() << '-' << (timeStruct->tm_mon) << '-'<<  (timeStruct->tm_mday) << std::endl;
}


int main(){
  int a=4,b=6,c=9,d=895487;
  printf("|%5d|%5d|%5d|%5d|", a,b,c,d);
  return 0;
}
