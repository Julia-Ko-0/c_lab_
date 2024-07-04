#include <iostream>
int main(){
      srand(time(0));
     int a,b;
     std::cout<<"сколько будет Чисел в обьекте: ";
    std::cin>>a;
      std::cout<<"сколько будет обьектов в массиве: ";
    std::cin>>b;
    int **mas = new int*[b];
    for(int i=0; i<b;i++){
        
        mas[i] = new int[a];
    }
    for(int x=0; x<b;x++){
        // std::cout<<x;
        for(int j=0; j<a;j++){

               mas[x][j] = rand()%(100-0+1)+1;
                        std::cout<< mas[x][j]<<"\t";
               
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    for(int p=0; p<b;p++){
        if(p%2==0){
            for (int q = 0; q < a;q++)
            {
                std::cout<<mas[p][q]<<"\t";
            }
            std::cout<<"\n";
        }
     
        else{
            for (int m =(a-1); m > -1;m--)
        {   
            std::cout<<mas[p][m]<<"\t";
        }
          std::cout<<"\n";
        }
           
     }
    
}