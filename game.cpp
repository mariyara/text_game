#include "prog.h"


int main()
{
	setlocale(LC_ALL, "ru");
	Human* Player = nullptr; // создание персонажа
	Choose(Player); // выбор класса персонажа
	City* city = new City;

	system("pause");
	Player->Learning(Player, city);
	system("pause");

	while (Player->AreYouAlive() && city->GetLevel() < 5)
	{
		Combat(Player, city);
		system("pause");
		if (!Player->AreYouAlive() || !Player->AreYouHungry())
		{
			break;
		}
		system("pause");
		city->Choose(Player);
	}
	system("pause");

	if (Player->AreYouAlive())
		Boss(Player);
	system("pause");

	return 0;
}