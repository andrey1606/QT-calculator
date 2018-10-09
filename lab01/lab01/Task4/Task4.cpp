#include "pch.h"
#include <iostream>
#include <cmath>

int getChoice1()
{
	while (true)
	{
		std::cout << "Hello, my dear. What do you want to do? \n";
		std::cout << "1) Addition\n";
		std::cout << "2) Subtraction\n";
		std::cout << "3) Multiplication\n";
		std::cout << "4) Division\n";
		std::cout << "5) Logarithm\n";
		std::cout << "6) Square root\n";
		std::cout << "7) Exponentiation 2\n";
		int choice1;
		std::cin >> choice1;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cout << "Your answer: " << choice1 << std::endl;

			if (choice1 == 1 || choice1 == 2 || choice1 == 3 || choice1 == 4 || choice1 == 5 || choice1 == 6 || choice1 == 7)
				return choice1;
			else
				std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		std::cin.ignore(32767, '\n');
	}
}

int getChoice2()
{
	while (true)
	{
		std::cout << "Do you want to try again? \n";
		std::cout << "1) Yes\n";
		std::cout << "2) No\n";
		int choice2;
		std::cin >> choice2;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{

			if (choice2 == 1 || choice2 == 2)
				return choice2;
			else
				std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		std::cin.ignore(32767, '\n');
	}
}

double getNumberSimp1()
{
	std::cout << "Enter number 1: ";
	double a;
	std::cin >> a;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Oops, that input is invalid.  Please try again.\n";
	}
	else
		return a;
	std::cin.ignore(32767, '\n');
}

double getNumberSimp2()
{
	std::cout << "Enter number 2: ";
	double b;
	std::cin >> b;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Oops, that input is invalid.  Please try again.\n";
	}
	else
		return b;
	std::cin.ignore(32767, '\n');
}

double getNumberLog()
{
	std::cout << "Enter logarithm: ";
	double a;
	std::cin >> a;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Oops, that input is invalid.  Please try again.\n";
	}
	else
	{
		if (a <= 0)
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		else
			return a;
	}
	std::cin.ignore(32767, '\n');
}

double getNumberBaseLog()
{
	std::cout << "Enter the base of your logarithm: ";
	double a;
	std::cin >> a;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Oops, that input is invalid.  Please try again.\n";
	}
	else
	{
		if (a <= 0 || a == 1)
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		else
			return a;
	}
	std::cin.ignore(32767, '\n');
}

double getNumberSqrt()
{
	std::cout << "Enter the number: ";
	double a;
	std::cin >> a;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Oops, that input is invalid.  Please try again.\n";
	}
	else
	{
		if (a < 0)
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		else
			return a;
	}
	std::cin.ignore(32767, '\n');
}

int main()
{
	int choice1, choice2;
	double a, base, ln1, ln2, result;
	do
	{

		choice1 = getChoice1();
		switch (choice1)
		{
		case 1:
			result = getNumberSimp1() + getNumberSimp2();
			std::cout << "Result: " << result << std::endl;
			break;
		case 2:
			result = getNumberSimp1() - getNumberSimp2();
			std::cout << "Result: " << result << std::endl;
			break;
		case 3:
			result = getNumberSimp1() * getNumberSimp2();
			std::cout << "Result: " << result << std::endl;
			break;
		case 4:
			result = getNumberSimp1() / getNumberSimp2();
			std::cout << "Result: " << result << std::endl;
			break;
		case 5:
			a = getNumberLog();
			base = getNumberBaseLog();
			ln1 = log(a);
			ln2 = log(base);
			result = ln1 / ln2;
			std::cout << "Result: " << result << std::endl;
			break;
		case 6:
			a = getNumberSqrt();
			result = sqrt(a);
			std::cout << "Result: " << result << std::endl;
			break;
		case 7:
			a = getNumberSimp1();
			result = pow(a, 2);
			std::cout << "Result: " << result << std::endl;
			break;

		}
		choice2 = getChoice2();
	} while (choice2 == 1);

	return 0;
}