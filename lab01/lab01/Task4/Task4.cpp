#include "pch.h"
#include <iostream>
#include <cmath>

void clearCin()
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cout << "Input error. Try again!\n";
}

int choiceAction()
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
			clearCin();
		}
		else
		{
			std::cout << "Your answer: " << choice1 << std::endl;

			if (choice1 == 1 || choice1 == 2 || choice1 == 3 || choice1 == 4 || choice1 == 5 || choice1 == 6 || choice1 == 7)
				return choice1;
			else
				std::cout << "Input error. Try again!\n";
		}
		std::cin.ignore(32767, '\n');
	}
}

int continueOrNo()
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
			clearCin();
		}
		else
		{

			if (choice2 == 1 || choice2 == 2)
				return choice2;
			else
				std::cout << "Input error. Try again!\n";
		}
		std::cin.ignore(32767, '\n');
	}
}

double getNumberSimp(int x)
{
	while (true)
	{
		std::cout << "Enter number " << x << ": ";
		double a;
		std::cin >> a;
		if (std::cin.fail())
		{
			clearCin();
		}
		else
			return a;
		std::cin.ignore(32767, '\n');
	}
}

double getNumberLog()
{
	while (true)
	{
		std::cout << "Enter logarithm: ";
		double a;
		std::cin >> a;
		if (std::cin.fail())
		{
			clearCin();
		}
		else
		{
			if (a <= 0)
				std::cout << "Input error. Try again!\n";
			else
				return a;
		}
		std::cin.ignore(32767, '\n');
	}
}

double getNumberBaseLog()
{
	while (true)
	{
		std::cout << "Enter the base of your logarithm: ";
		double a;
		std::cin >> a;
		if (std::cin.fail())
		{
			clearCin();
		}
		else
		{
			if (a <= 0 || a == 1)
				std::cout << "Input error. Try again!\n";
			else
				return a;
		}
		std::cin.ignore(32767, '\n');
	}
}

double getNumberSqrt()
{
	while (true)
	{
		std::cout << "Enter the number: ";
		double a;
		std::cin >> a;
		if (std::cin.fail())
		{
			clearCin();
		}
		else
		{
			if (a < 0)
				std::cout << "Input error. Try again!\n";
			else
				return a;
		}
		std::cin.ignore(32767, '\n');
	}
}

int main()
{
	int choice2;
	do
	{
		int choice1;
		double a, base, ln1, ln2, result;
		choice1 = choiceAction();
		switch (choice1)
		{
		case 1:
			result = getNumberSimp(1) + getNumberSimp(2);
			std::cout << "Result: " << result << std::endl;
			break;
		case 2:
			result = getNumberSimp(1) - getNumberSimp(2);
			std::cout << "Result: " << result << std::endl;
			break;
		case 3:
			result = getNumberSimp(1) * getNumberSimp(2);
			std::cout << "Result: " << result << std::endl;
			break;
		case 4:
			result = getNumberSimp(1) / getNumberSimp(2);
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
			a = getNumberSimp(1);
			result = pow(a, 2);
			std::cout << "Result: " << result << std::endl;
			break;

		}
		choice2 = continueOrNo();
	} while (choice2 == 1);

	return 0;
}
