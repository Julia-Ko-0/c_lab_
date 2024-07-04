
#include <iostream>

int main()
{

	double x, z, otv;
	std::cout << "ln(x+0,5)+(e^x -e^-x)\n";
	std::cin >> z;

	if (z < -1) x = (-z / 3);
	else x = fabs(z);
	otv = (log(x + 0,5) + (exp(x) - exp(-x)));
	std::cout << otv;
}
