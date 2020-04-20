#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class gameData
{
	int num=0;
	int tries=0;
	int numsTried[5];
public:
	gameData();
	void setNum();
	void setTries();
	int getNum();
	int getTries();
	void mainMenu();
	void howToPlay();
	void startGame();
	void wrongInput();
	void playAgain();
};

void gameData::playAgain()
{
	cout << "Would you like to play again?(Y/N)\n";
	char choice;
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		setTries();
		setNum();
		startGame();
	}
	else
	{
		setTries();
		setNum();
		mainMenu();
	}
}
void gameData::wrongInput()
{
	cout << "Invalid input, please try again.\n";
	system("pause");
	mainMenu();
}
void gameData::startGame()
{
	system("CLS");
	int guess = 0;
	cout << "\t\tThe computer have chosen a random number between 1-10! Try to guess it.\n\n";

	for (int i = tries; i > 0 ; i--)
	{
		system("CLS");
		cout << "What's your guess?\n\t\t\t\tTries remaining: ";
		for (int j = 0; j < tries; j++)
			cout << "x ";
		cout << "\n\n";
		if (i == 5)
			cin >> numsTried[i];

	    else
		{
			cout << "\n\n\t\t\t\tYou have already tried those numbers: ";
			for (int k = 5; k > tries; k--)
				cout << this->numsTried[k] << " ";
			cout << "\n\n";
			cin >> numsTried[i];
		}
		

		if (numsTried[i] == num)
		{
			cout << "YOU WIN!\n\n";
			playAgain();
		}
		else
		{
			guess++;
			tries--; 
			continue;
		}
	}
	cout << "\n\nYou ran out of tries.\n\nThe correct number was: " << num << "\n\n";
	playAgain();
}
void gameData::howToPlay()
{
	system("CLS");
	cout << "\t\t\tThe Guessing Game: How To Play\t\t\t\n\n";
	cout << "The computer will pick a random number between 1-10 and you will have to guess it, you are offered 5 tries\nthe count of those tries will appear on screen.\nGood Luck!\n";
	system("pause");
	mainMenu();
}

void gameData::mainMenu()
{
	system("CLS");
	cout << "\t\tWelcome to The Guessing Game\t\t\n\n";
	cout << "1) Start Game\n2) How To Play\n3) Exit\n\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: startGame(); break;
	case 2: howToPlay(); break;
	case 3: return;
	default: wrongInput(); break;
	}
	
}


int gameData::getNum()
{
	return num;
}

int gameData::getTries()
{
	return tries;
}

void gameData::setTries()
{
	tries = 5;
}

void gameData::setNum()
{
	srand(time(0));
	num = 1 + (rand() % 10);
}

gameData::gameData()
{
	tries = 5;
	setNum();
}




int main()
{
	gameData obj1;
	cout << obj1.getNum() << " " << obj1.getTries();
	obj1.mainMenu();
}