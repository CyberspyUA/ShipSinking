#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 10;

int maxships = 10;

int matrix[rows][elements];

void Clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Show()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int NumberOfShips()
{
	int c = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			if (matrix[i][j] == 1)
				c++;
		}
	}

	return c;
}

void SetShips()
{
	int s = 0;
	while (s < maxships)
	{
		int x = rand() % rows;
		int y = rand() % elements;
		if (matrix[x][y] != 1)
		{
			s++;
			matrix[x][y] = 1;
		}
	}
}

bool Attack(int x, int y)
{
	if (matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}
	return false;
}

int main()
{
	srand(time(NULL));
	Clear();
	SetShips();
	int pos1, pos2, attempts = 0, total_attempts = 0, sinked_ships_num=0;
	char prompt;
	cout << "Welcome to ship sinking game! \n" << "Rules: input coordinates with number from 0 to 9 like this\n"<<"Please input location: 0 0 \n"<< "Then you will see the result of you attack!\n"<<"Every 3 attempts game will suggest you to surrender\n"<<"Good Luck!\n";
	while (true)
	{
		cout << "Please input location: "; cin >> pos1 >> pos2;
		if (Attack(pos1, pos2)) {
			cout << "You hitted the ship!!!" << endl;
			attempts = 0;
			total_attempts++;
			sinked_ships_num++;
		}
		else {
			cout << "Sorry no ship at that position!" << endl;
			attempts++;
			total_attempts++;
		}
		cout << "Number of ships left: " << NumberOfShips() << endl;
		if (attempts == 3) {
			cout << "Do you want to surrender (y/n)? "; cin >> prompt;
			if (prompt == 'y')
				break;
			if (prompt == 'n')
				attempts = 0;
		}
	}
	cout << "Game over!" << endl;
	Show();
	cout << " \n Total number of attempts: " << total_attempts<<"\n";
	cout << " \n Total number of sinked ships: " << sinked_ships_num << "\n";
	system("pause");
	return 0;
}