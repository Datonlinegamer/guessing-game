#include <iostream>
#include <time.h>
#include <string>
using namespace std;


constexpr int KPlayMenu = 1;
constexpr int Quit = 2;
constexpr int KMale = 1;
constexpr int KFemale = 2;
constexpr int KOther = 3;
constexpr int MaxGuesses =5;



string NickName;
string UsersName();
string UsersNickName(int Gender,int Age);

int UsersGuess(int Turn, string nickname);
int DisplayWelcomeMessage();
int UsersGender();
int UsersAge();

bool ReveiwUsersGuess( int Guess,int RandomNumber);
bool KeepPlaying = true;

void DisplayMessage(string Message);
void DisplayGameover(int RandomNumber,string NickName,int AmountOfGuess);
void PlayGame();


int main()
{
	
	srand((unsigned)time(0));
	do
	{
		int Input = DisplayWelcomeMessage();
		switch (Input)
			{
			case KPlayMenu:
			{
				PlayGame();
					break;						

			}
			case Quit:
			{

				DisplayMessage("GoodBye");
				KeepPlaying = false;
				break;
			}
			default:
			{	
				system("cls");
				DisplayMessage(" Invald Input Try again");
				break;
			}

		}

	} while (KeepPlaying);
	
}

	
int DisplayWelcomeMessage()
{
		
	int Input;
	do
	{
		cout << "Welcome to my Guessing game " << endl;
		cout << " You have  Infinite guess's the correct nember between 1 and 20: " << endl;
		cout << "Play now! " << endl;
		cout << "Quit! " << endl;
		cout << "press 1 or 2: " << endl;

		cin >> Input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			system("cls");
			cout << "Invald Entry Try Again" << endl;

		}
		else
		{
			break;
		}

	} while (true);
	
	return Input;
}



void PlayGame()
{
	system("cls");
	int Gender = UsersGender();
	system("cls");
	string Name = UsersName();
	system("cls");
	cout << "welcome " << Name << endl;
	int Age = UsersAge();
	string NickName = UsersNickName(Gender, Age);


	bool IsGameOver = false;
	do
	{
		if (Gender >= KMale && Gender <= KOther)
		{
			int RandomNumber = 1 + rand() % 20;
			cout << RandomNumber << endl;
			bool IsGuessCorrect = false;
			int AmountofGuesses{};

			do
			{
				int Guess = UsersGuess(AmountofGuesses + 1, NickName);
				IsGuessCorrect = ReveiwUsersGuess(Guess, RandomNumber);
				if (IsGuessCorrect)
				{
					break;
				}
				AmountofGuesses++;
			} while (!IsGuessCorrect);
			DisplayGameover(RandomNumber, NickName,AmountofGuesses);
			IsGameOver = true;
		}
		else
		{
			system("cls");
			cout << "Invalid Input. Try again." << endl;
		}

	} while (!IsGameOver);

	
}

void DisplayMessage(string Message)
{
	std::cout << Message << std::endl;
}

void DisplayGameover(int RandomNumber, string NickName, int AmountOfGuessses)
{
	cout << "Good Job "<< NickName<< NickName  << "" << "It Took you:" << " " << AmountOfGuessses << endl;
	cout << "To Guess to number" << RandomNumber << endl;
}



string UsersName()
{
	cout << "What Your name ?:" << endl;
	string Name;
	cin >> Name;
	return Name;
}

string UsersNickName(int Gender, int Age)
{
	if (Gender >= KMale && Gender <= KOther)
	{

		if (Gender == KMale)
		{
			if (Age > 60)
			{
				NickName = "OldGuy";
			}
			else if (Age < 10)
			{
				NickName = "LittleMan";
			}
			else
			{
				NickName = "Bud";
			}
		}
		else if (Gender == KFemale)
		{

			if (Age > 60)
			{
				NickName = "OldLady";
			}
			else if (Age < 10 || Age > 20 && Age < 60)
			{
				NickName = "LittleGirl";
			}
			else
			{
				NickName = "Bud";
			}

		}
		else
		{
			NickName = "Friend";
		}

	}
	return NickName;

}

int UsersGuess(int Turn, string NickName)
{
	int Guess;
	do
	{
		cout << " Guess 1:" << Turn << "Alright" << NickName << "Please Guess a number:" << endl;
		cin >> Guess;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			system("cls");
			cout << "Invald Entry Try Again" << endl;

		}
		else
		{
			break;
		}
	} while (true);
	return Guess;
}

int UsersGender()
{
	int Gender;
	do
	{
		cout << "What's your Gender ?: " << endl;
		cout << " 1)male" << endl;
		cout << " 2)Female" << endl;
		cout << " 3)Other" << endl;
		cout << " Press 1, 2, or 3" << endl;
		cin >> Gender;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			system("cls");
			cout << "Invald Entry Try Again" << endl;

		}
		else
		{
			break;
		}
		
	} while (true);

	return Gender;
}

int UsersAge()
{
	int Age;
	do
	{
		cout << "How old are you ?:" << endl;
		cin >> Age;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			system("cls");
			cout << "Invald Entry Try Again" << endl;

		}
		else
		{
			break;
		}

	} while (true);
	return Age;

}

bool ReveiwUsersGuess(int Guess, int RandomNumber)
{
	if (Guess == RandomNumber)
	{
		cout << "You are correct!!" << endl;
		return true;
	}
	else
	{
		if (Guess > RandomNumber)
		{
			DisplayMessage("You Guessed too high!");
		}
		else if (Guess < RandomNumber)
		{
			DisplayMessage("You Guessed too low!");
		}
		return false;
	}
}



	
	
	

	


