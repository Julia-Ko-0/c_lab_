#include <iostream>
#include <string>
int main() {
    std::string str;
    int k,a;
    std::cout<<"введите строку ";
    std::getline(std::cin, str);

    std::cout<<"введите значение к ";
    std::cin >>k;
    a=0;
    for (int i = 0; i <k; i++) {
    if (str[i] == '!') {
        a=a+1;
        if (a==2)
        {
            str[i] = '$';
            a=0;
        }
    }
    }

    std::cout  <<"Измененная строка: " << str << std::endl;

    return 0;
}