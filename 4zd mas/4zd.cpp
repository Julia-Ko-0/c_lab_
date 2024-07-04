#include <iostream>
#include <cstdio>

int main(){
    float ost,ost_6;
    int a;
    //int mas[]= {1,2,3,6,23};
   
    std::cout<<"сколько будет чисел в массиве: ";
    std::cin>>a;
     int mas[a];
     for (int i = 0; i < a; i++)
    {
       std::cout<<"\n число "<<i<<"=";
       std::cin>>mas[i];
    }
    for (int i = 0; i < a; i++)
    {
       
       ost =  mas[i]%10;
       if(ost == 3){
           std::cout<<"\n элемент оканчив на 3: "<<mas[i];
       std::cout<<"\n номер элемента:  "<<i+1;
       }
       
    
    }
    for (int i = 0; i < sizeof(mas)/sizeof(mas[0]); i++){
        ost_6 = mas[i]%6;
        ost =  mas[i]%10;
        if(ost_6 == 0 && ost == 3){
        std::cout<<"\n \n кратны 6 и оканчив на 3:  "<<mas[i];
       }
    }
      for (int i = 0; i < sizeof(mas)/sizeof(mas[0]); i++){
        ost_6 = mas[i]%6;
        if(ost_6 == 0 ){
        std::cout<<"\n \n кратны 6 :  "<<mas[i];
       }
    }
    
}