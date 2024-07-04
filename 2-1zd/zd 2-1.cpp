#include <iostream>
#include <math.h>
#include<iomanip>
int main(){
    float pi;
    pi = 3,1415;
    float num,y,a,b,h,x,x1,x2,y_pr,y_sl,ymax,ymin;
    a = -2;
    b = 0.8;
    h = 0.2;
    ymax = 0;
    ymin = 0;
    num = 1;
    
    std::cout<<" _______________________________________________________ \n";
    std::cout<<"|num"<<'|'<<std::setw(15)<<" x "<<"|"<<std::setw(15)<<" y "<<"|"<<"в/у"<<"|"<<"разность"<<std::setw(10)<<"| \n" ;
    std::cout<<"|_______________________________________________________| \n";
    for (float i = a; i < b; i+=h){
        
         x = i;       
        std::cout << "|"<<std::setw(2)<<num<<std::setw(2)<<"|"<<std::setw(15)<<x<<"|";
        y=(x*cos(pi/4))/(1-2*cos(pi/4)+pow(x,2));
        y_pr=((x-h)*cos(pi/4))/(1-2*cos(pi/4)+pow(x-h,2));
        y_sl=((x+h)*cos(pi/4))/(1-2*cos(pi/4)+pow(x+h,2));
        if(y>ymax){
            ymax = y;
        }
        else{
            ymin=y;
        }
       std::cout <<std::setw(15)<<y<<"|" <<std::setw(4)<<"|"<<std::setw(18)<<"| \n";
        // std::cout <<std::setw(100)<<std::setw(2)<<" |";
        if(y_sl <b){
              if(y>y_pr){
        std::cout<<"|"<<std::setw(4)<<"|"<<std::setw(16)<<"|"<<std::setw(16)<<"|"<<std::setw(2)<<"+"<<std::setw(2)<<" |"<<std::setw(15)<<y_sl-y<<"| \n";
       }
       else{
            std::cout<<"|"<<std::setw(4)<<"|"<<std::setw(16)<<"|"<<std::setw(16)<<"|"<<std::setw(2)<<"-"<<std::setw(2)<<" |"<<std::setw(15)<<y_sl-y<<"| \n";
       }
        }
     
       num+=1;
    }
    std::cout<<"|___|_______________|_______________|___|_______________| \n";
    std::cout <<"\n ymax= " <<ymax;
    std::cout <<"\n ymin= " <<ymin;
}
    
    