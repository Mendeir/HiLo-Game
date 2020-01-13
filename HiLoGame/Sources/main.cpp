#include <iostream>
#include <random>
#include <ctime>

namespace MyRandom
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

bool playAgain()
{
	char choice;

	while (true)
	{
		std::cout << "\nWould you like to play again (y/n)? ";
		std::cin >> choice;

		std::cout << '\n';

		std::cin.ignore(32767, '\n');

		if (choice == 'y')
			return true;
		else if (choice == 'n')
			return false;

	}
}

bool printResult(int random, int guess)
{
	if (random > guess)
		std::cout << "Your guess is too low.\n\n";
	if (random < guess)
		std::cout << "Your guess is too high.\n\n";
	if (random == guess)
	{
		return true;
	}

}

int getRandomNumber(int min, int max)
{
	std::uniform_int_distribution hilo{ min, max };

	return hilo(MyRandom::mersenne);
}


int getUserGuess(int counter)
{
	while (true)
	{
		int userGuess1;

		std::cout << "Guess #" << counter << ": ";
		std::cin >> userGuess1;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input! Please try again!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return userGuess1;
		}
	}
}

bool checkAndPrintRandomNumber(int random)
{
	bool checker;
	int counter = 1;

	while (true)
	{
		checker = printResult(random, getUserGuess(counter));

		if (checker == 1)
			return true;
		if (counter == 7)
			return false;
		++counter;
	}


}

int main()
{
	do
	{
		//initialization
		int counter = 1;
		int randomNumber = getRandomNumber(1, 100);
		bool checker;

		//title
		std::cout << "Lets play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n\n";

		checker = checkAndPrintRandomNumber(randomNumber);

		if (checker == false)
		{
			std::cout << "Sorry, you lose. The correct number was " << randomNumber << '\n';

		}
		if (checker == true)
		{
			std::cout << "Correct! You win!" << '\n';

		}
	} while (playAgain());

}