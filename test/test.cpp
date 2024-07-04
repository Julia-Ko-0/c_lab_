// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main()
// {
//     vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

//     for (const string& word : msg)
//     {
//         cout << word << " ";
//     }
//     cout << endl;
// }
#include <iostream>;
#include <math.h>;
int main() {
float a,b,y,otv;

std::cout<< "enter a ";
std::cin>>a;

std::cout<< "enter b ";
std::cin >>b;

std::cout<< "enter y ";
std::cin >>y;
otv = (pow((y + 7 * a) + b, 1 / 3)) / (sin(b) + 1 + pow(y + 7 * a, 1 / 3));
std::cout << "(3kor y+7a+b)/sinb+1+kory+7a = " <<otv;
}