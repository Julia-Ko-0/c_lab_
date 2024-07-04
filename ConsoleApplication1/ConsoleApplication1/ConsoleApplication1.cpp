#include <iostream>;
//void main() {
//	float okl, prem, sal;
//
//	std::cout << "enter oklad ";
//	std::cin >> okl;
//
//	std::cout << "enter premia ";
//	std::cin >> prem;
//	sal =  (okl+prem)*12/100/100;
//	std::cout <<"salary = "<<sal;
//}
void main() {
	float a,b,y,otv;

	std::cout << "enter a ";
	std::cin >> a;

	std::cout << "enter b ";
	std::cin >> b;

	std::cout << "enter y ";
	std::cin >> y;
	otv = (pow((y + 7 * a) + b, 1 / 3)) / (sin(b) + 1 + pow(y + 7 * a, 1 / 3));
	std::cout << "(3kor y+7a+b)/sinb+1+kory+7a = " << otv;
}
