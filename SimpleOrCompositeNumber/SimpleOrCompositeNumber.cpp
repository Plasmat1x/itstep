#include <iostream>
#include <stdlib.h>

void primeNumber(int number);

int main()
{
	int n;
	do
	{
		system("cls");
		std::cout << "<--Prime-->" << std::endl;
		std::cout << "\nEnter number (0 - for exit): ";
		std::cin >> n;
		primeNumber(n);

		system("pause");
	} while (n != 0);

	return 0;
}

//var - 2 out prime factors of not prime number
bool prim(int n)
{
	for (int d = 2; d <= n / 2; d++)
		if (n % d == 0)
			return false;
	return true;
}
void primeNumber(int number)
{
	int count = 0;

	std::cout << "prime factors: ";
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			count++;
			if (i == 2)
				std::cout << "1 ";
			if(prim(i))
				std::cout << i << " ";
		}
	}

	if (count == 0)
	{
		std::cout << "\nNumber " << number << " Prime\n";
	}
	else
	{
		std::cout << "\nNumber " << number << " not Prime\n";
	}
}

/* 
//var 1 - out all factors of not prime number
void primeNumber(int number)
{
	int count = 0;

	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			count++;
			if (i == 2)
				std::cout << "1 ";

			std::cout << i << " ";
		}
		if (i == number - 1 && count > 0)
			std::cout << number;
	}

	if (count == 0)
	{
		std::cout << "\nPrime\n";
	}
	else
	{
		std::cout << "\nNot Prime\n";
	}
}
*/
