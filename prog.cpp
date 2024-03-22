#include <iostream>
#include "prog.h"
using namespace std;


//проверка ввода на цифры
int CinProtection(int a, string b)
{
	int v;
	while (true)
	{
		cin >> v;
		//system("cls");
		if (v >= 1 && v <= a) break;
		else {
			cin.clear();
			cin.ignore();
			std::cout << b << endl;
		}
	}
	return v;
}
//..........ПЕРСОНАЖ..............................................
Human::Human()
{
	HP = 100; //уровень здоровья
	maxHP = 100;//максимальное здоровье, которое увеличивается с уровнем
	XP = 1; // уровень игрока
	hunger = 3;// кол-во дней до голодной смерти, не может быть больше 3
	money = 0; // деньги
	luck = 1; // параметр, отвечающий за действия в таверне (драка, фокусы, обращение в веру)
	FirePower = 5; // сила огня героя
	AirPower = 5; // сила воздуха героя
	WaterPower = 5; // сила воды героя
	EarthPower = 5; // сила земли героя
	heal = 5; // параметр лечения в бою
	shield = 0; // щит, который есть только у воина
}
Human Choose(Human*& Player)
{
	std::cout << "Давным-давно, когда еще было только ничего, зародились четыре сущности, четыре стихии..." << endl;
	std::cout << "Вода, Огонь, Воздух и Земля. Они создали этот мир и жили в гармонии, так как у каждой стихии были слабые и сильные стороны," << endl;
	std::cout << "которые компенсировали друг друга..." << endl;
	std::cout << "Но однажды все изменилось -- появился Повелитель Стихий и поработил силу четырех сущностей." << endl;
	std::cout << "Повелитель Стихий с помощью новообретенных сил создал монстров, которые заполонили весь мир. Воцарился Хаос." << endl;
	std::cout << "Многие поселения были превращены в руины, но еще не все было потеряно. В одном из выживших городов рождаешься Ты." << endl;
	std::cout << "Твои родители поведали тебе эту историю мира. И Ты наполняешься решимостью во что бы то ни стало победить Повелителя Стихий" << endl;
	std::cout << "и вернуть мир в эти земли..." << endl;
	std::cout << "Перед тобой стоит выбор, кем вырасти... \n1.Воин \n2.Маг \n3.Клирик " << endl << endl;
	int a;
	while (true)
	{
		cin >> a;
		system("cls");
		if (a >= 1 && a <= 3) break;
		else {
			cin.clear();
			cin.ignore();
			std::cout << "Выбери один из трех классов(цифра от 1 до 3): \n1.Воин \n2.Маг \n3.Клирик" << endl;
		}
	}
	switch (a)
	{
	case 1:
		Player = new  Warrior();
		std::cout << "Ты выбираешь путь Воина. Чтобы победить Повелителя Стихий, тебе нужно в совершенстве овладеть четырьмя видами оружия," << endl;
		std::cout << "а также не помереть по пути к нему... " << endl;
		break;
	case 2:
		Player = new Magician();
		std::cout << "Ты выбираешь путь Мага. Чтобы победить Повелителя Стихий, тебе нужно в совершенстве овладеть магией Разрушения," << endl;
		std::cout << "а также не помереть по пути к нему... " << endl;
		break;
	case 3:
		Player = new Cleric();
		std::cout << "Ты выбираешь путь Клирика. Чтобы победить Повелителя Стихий, тебе нужно укрепить связь твою связь с Богами," << endl;
		std::cout << "а также не помереть по пути к нему... " << endl;
		break;
	}
	return Human();
}
void Human::HowAreYou()
{
	std::cout << "Здоровье: " << HP << "\nУровень: " << XP << "\nДней до голодной смерти: " << hunger << "\nМонет: " << money << "\nУдача: " << luck << endl;
}//вывод здоровья, уровня, голода, денег, удачи
//------------------БОЙ--------------------------------
void Human::GetDamage(int mD)
{
	if (HP > mD)
		HP = HP - mD;
	else HP = 0;
}
void Human::GetDamage(int mD, char el)
{
	if (HP > mD)
		HP = HP - mD;
	else HP = 0;
}
bool Human::AreYouAlive()
{
	if (HP < 1)
	{
		return 0;
	}
	return 1;
}
bool Human::AreYouHungry()
{
	if (hunger < 1)
	{
		return 0;
	}
	return 1;
}
int  Human::GetHP() { return HP; }
int Human::Get_XP(){	return XP;}
void Human::GetHeal()
{
	if (HP + heal < maxHP)
		HP = HP + heal;
	else
		HP = maxHP;
}
void Human::Hunger()
{
	hunger--;
	std::cout << "Дней до голодной смерти: " << hunger << endl;
}
//-----------------ГОРОД-------------------------------
void Human::Eat(int CityLevel)
{
	if (money >= CityLevel * 10 - 1)
	{
		if (hunger < 3)
		{
			hunger += 1;
			money -= CityLevel * 10 - 1;
		}
		else
		{
			cout << "Ну ты и обжора..." << endl;
			money -= CityLevel * 10 - 1;
		}
	}
	else cout << "Деньжат-то маловато..." << endl;

	cout << "Дней до голодной смерти: " << hunger << endl;
}

//___________ПРОКАЧКА НАВЫКОВ__________________
void Human::FireUp(int a, int mon)
{
	if (money >= mon) {
		FirePower += a;
		money -= mon;
	}
	else {
		cout << "Деньжат-то маловато.." << endl;
	}
}
void Human::WaterUp(int a, int mon)
{
	if (money >= mon) {
		WaterPower += a;
		money -= mon;
	}
	else {
		cout << "Деньжат-то маловато.." << endl;
	}
	WaterPower += a;
}
void Human::AirUp(int a, int mon)
{
	if (money >= mon) {
		AirPower += a;
		money -= mon;
	}
	else {
		std::cout << "Деньжат-то маловато.." << endl;
	}
}
void Human::EarthUp(int a, int mon)
{
	if (money >= mon) {
		EarthPower += a;
		money -= mon;
	}
	else {
		cout << "Деньжат-то маловато.." << endl;
	}
}
void Human::HealUp(int a, int mon)
{
	if (money >= mon) {
		heal += a;
		money -= mon;
	}
	else {
		cout << "Деньжат-то маловато.." << endl;
	}
}
//----------------VIRTUAL-------------------
int  Human::ChoiceCommand() { return 0; }
int  Human::Town() { return 0; }
void Human::Shop(int) {}
int  Human::Pub(int) { return 0; }
void Human::Active() {}
void Human::ShowHowAreYou() {}
void Human::StartCombat() {}
void Human::RandUp(char, int) {}
void Human::Learning(Human*&, City*&) {}

//_______КЛАССЫ___________________________________________________________________________

//---------------------ВОИН--------------------------------------------------
Warrior::Warrior()
{
	shield = 10;
	sip = 3;
	FirePower = 8;
	AirPower = 8;
	WaterPower = 8;
	EarthPower = 8;
}
void Warrior::ShowHowAreYou()
{
	HowAreYou();
	cout << "Урон луком: " << FirePower << "\nУрон мечом: " << AirPower << "\nУрон арбалетом: " << EarthPower << "\nУрон копьем: " << WaterPower << "\nПоглащаемый щитом урон: " << shield << "\nЗелье восстанавливает " << heal << " здоровья" << endl << endl;
}

//--------------БОЙ---------------------------
void Warrior::StartCombat()
{
	cout << "Твои характеристики:" << endl;
	cout << "Здоровье: " << HP << endl;
	cout << "Урон луком: " << FirePower << "\nУрон мечом: " << AirPower << "\nУрон арбалетом: " << EarthPower << "\nУрон копьем: " << WaterPower << endl;
	cout << "Поглащаемый щитом урон: " << shield << "\nЗелье восстанавливает " << heal << " здоровья" << endl << endl;

}
void Warrior::Learning(Human*& Player, City*& city)
{
	cout << "Пройти обучение?\n1.Да\n2.Нет" << endl;
	int a = CinProtection(2, "Да или нет -> 1 или 2");
	if (a == 1)
	{
		system("cls");
		cout << "Твои характеристики:" << endl;
		ShowHowAreYou();
		cout << "Во время своего приключения ты будешь встречать монстров. Если ты их не убьешь, то они убьют тебя" << endl;
		cout << "Чтобы победить монстра, можно использовать оружие. В зависимости от стихии монстра оружие наносит разный урон" << endl;
		cout << "Например, лук наносит урон летающим тварям, но в воде он будет бесполезен, а в огне лук сгорит, как и ты" << endl;
		cout << "Арбалет, наоборот, эффективен в воде, но против наземных тварей с ним лучше не идти..." << endl;
		cout << "Но зато против них можно пойти мечом! А вот летающих тварей он не достанет" << endl;
		cout << "Еще есть копье, с помощью него можно потыкать огонь, не приближаясь к нему, но вот в воду тыкать не советуем..." << endl;
		cout << "Теперь попробуем потренироваться." << endl;
		Monster* m = new Fire(18);
		m->ShowMonster();
		cout << "Как ты можешь понять, этот монстр принадлежит к огненной стихии. Давай попробуем выстрелить из арбалета" << endl;
	
		int a;
		do { cout << "Попробуй использовать арбалет" << endl; a = ChoiceCommand(); } while (a != 4);
		EarthDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Здорово! У тебя получется нанести урон костру! Но тебя он тоже немного задел..." << endl;
	
		cout << "Теперь посмотрим, как на него подействует меч" << endl;
		do { cout << "Попробуй использовать меч" << endl; a = ChoiceCommand(); } while (a != 3);
		AirDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Ты машешь мечом, но костер этого никак не замечает. Ты подходишь к нему близко, поэтому обжигаешься" << endl;
		
		cout << "Может быть, острые стрелы смогут тебе помочь?" << endl;
		do { cout << "Попробуй использовать лук" << endl; a = ChoiceCommand(); } while (a != 1);
		FireDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "А-ха-ха, ты правда думаешь, что эти деревянные стрелы его остановят? Ты только разжигаешь его сильнее, за что и получаешь по лбу" << endl;
	
		cout << "Можешь использовать щит и выпить зелье, чтобы полечиться. Щит поглотит урон, который нанесет тебе монстр, пока ты лечишься" << endl;
		do { cout << "Попробуй выпить зелье" << endl; a = ChoiceCommand(); } while (a != 9);
		Healing(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Хоть и прошлая твоя атака усилила костер, ты смог полечиться, так как тебя прикрыл щит" << endl;

		cout << "Надо его прикончить! Давай! Никакой жалости костру!!!!!!!!!!" << endl;
		do { cout << "Попробуй использовать копье" << endl; a = ChoiceCommand(); } while (a != 2);
		WaterDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Еще немного, и ты заживо...Но копье спасло тебя, ведь ты наносишь костру увеличенный урон!" << endl;
		cout << "Ты убиваешь Костер. Твой организм истощился. Нужно следить за своей сытостью, иначе помрешь от голода! Максимум без еды ты можешь прожить 3 дня" << endl;
		Player->Hunger();

		cout << "После убийства монстра ты получаешь уровень, эквивалентный его силе. Чем он сильнее, тем больше уровней ты получаешь" << endl;
		cout << "После боя твое здоровье полностью восстанавливается, а также повышается максимальное значение здоровья" << endl;
		GetXP(Player, m);
		cout << "Так же ты можешь получить трофеи за убийство монстра. Чем сильнее твой враг, тем больше монет ты получишь" << endl;
		Drop(Player, m);
		cout << "Ах, да. Еще прокачивается твое владение тем оружием, которым лучше всего убивался монстр \n\n\n" << endl;
		cout << "На пути тебе встречаются города. Тут можно за монеты улучшить свое оружие и поесть. Чем дальше ты зайдешь, тем дороже и качественнее товар." << endl;
		cout << "Так же можешь повздорить с кем-нибудь в таверне, и если удача будет на твоей стороне, то ты выбьешь немного монет или даже чей-то ужин" << endl;
		cout <<	"Подробнее со свойствами своего оружия можешь ознакомиться в оружейной. Удачи!" << endl;
		city->Choose(Player);
		city->LevelDown();
	}
	
}
int  Warrior::ChoiceCommand()
{
	if (sip > 0)
	{
		cout << "Выбери действие: \n1.Использовать оружие\n2.Использовать щит и выпить зелье восстановления" << endl << endl;
		int a = CinProtection(2, "Выбери действие(цифра от 1 до 2): \n1.Использовать оружие\n2.Использовать щит и выпить зелье восстановления");
		switch (a)
		{
		case 1:
		{
			cout << "Выбери оружие: \n1.Лук\n2.Копье\n3.Меч\n4.Арбалет" << endl << endl;
			int b = CinProtection(4, "Выбери оружие(цифра от 1 до 4): \n1.Лук\n2.Копье\n3.Меч\n4.Арбалет");
			return b;
		}
		case 2:
			sip--;
			return 9;
		}
	}
	else
	{
		cout << "Зелье восстановления закончилось" << endl << endl;
		cout << "Выбери оружие: \n1.Лук\n2.Копье\n3.Меч\n4.Арбалет" << endl << endl;
		int b = CinProtection(4, "Выбери оружие(цифра от 1 до 4): \n1.Лук\n2.Копье\n3.Меч\n4.Арбалет");
		return b;
	}

	return 0;
}
void Warrior::RandUp(char a, int b)
{
	switch (a)
	{
	case 'f':
		cout << "Техника владения копьём улучшена на " << b << ". Урон копьём: " << WaterPower + b << endl;
		break;
	case 'w':
		cout << "Техника владения арбалетом улучшена на " << b << ". Урон арбалетом: " << EarthPower + b << endl;
		break;
	case 'a':
		cout << "Техника владения луком улучшена на " << b << ". Урон луком: " << FirePower + b << endl;
		break;
	case 'e':
		cout << "Техника владения мечом улучшена на " << b << ". Урон мечом: " << AirPower + b << endl;
		break;
	}
	sip = 3;

}

//--------------ГОРОД-------------------------
int  Warrior::Town()
{
	cout << "Здесь не так много мест, которые можно посетить.. \n1.Оружейная \n2.Таверна \n3.Покинуть город" << endl;
	return CinProtection(3, "Выбери, куда пойти(1, 2 или 3): \n1.Оружейная \n2.Таверна \n3.Покинуть город");
}
void Warrior::Shop(int CityLevel)
{
	cout << "Что тебе нужно?" << endl;
	cout << "Твои деньги: " << money << endl;
	cout << "1. Улучшить лук      " << FirePower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	cout << "2. Улучшить копье    " << WaterPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	cout << "3. Улучшить меч      " << AirPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	cout << "4. Улучшить арбалет  " << EarthPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	cout << "5. Улучшить щит      " << shield << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	cout << "6. Улучшить зелье восстановления  " << heal << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	cout << "7. Подробнее об оружии" << endl;
	cout << "8. Выйти из оружейной" << endl;

	int a = CinProtection(8, "Выбери цифру от 1 до 8");
	system("cls");
	switch (a)
	{
	case 1:
		FireUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 2:
		WaterUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 3:
		AirUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 4:
		EarthUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 5:
		ShieldUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 6:
		HealUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 7:
		cout << "В нашем мире действует закон природы: ВОДА->ОГОНЬ->ВОЗДУХ->ЗЕМЛЯ->ВОДА" << endl;
		cout << "Одноименная стихия только усиливает на значение урона, доминирующая стихия наносит увеличиный(+25%) урон," << endl; 
		cout << "рецессивная стихия не наносит урон, противоположная стихия -- наносит обычный урон" << endl;
		cout << "Воин -- владеет 4 видами оружия, использует щит для поглощения урона и в это же время может выпить зелье восстановления," << endl;
		cout << "но только лишь 3 раза за бой, зелье после боя восполняется само. Оружие : меч -- хорош против наземных тварей;" << endl;
		cout << "арбалет -- хорошо стреляет в воде; копье -- может поразить противника, не подходя к нему близко; лук -- идеален для воздушных целей." << endl;

		break;
	}
	if (a != 8) {
		Shop(CityLevel);
	}
}
void Warrior::ShieldUp(int a, int mon)
{
	if (money >= mon) {
		shield += a;
		money -= mon;
	}
	else {
		cout << "Деньжат-то маловато.." << endl;
	}
}
int  Warrior::Pub(int CityLevel)
{
	cout << "Чем займешься?\n Твои деньги: " << money << "\n1.Поесть за " << CityLevel * 10 - 1 << " монет, дней до голодной смерти: " << hunger << "\n2.Ввязаться в драку\n3.Выйти из таверны" << endl;
	return CinProtection(3, "Чем займешься?(цифра от 1 до 3)\n 1.Поесть\n2.Ввязаться в драку\n3.Выйти из таверны");
}
void Warrior::Active()
{
	system("cls");
	srand(time(nullptr));

	if (rand() % luck == 0)
	{
		srand(time(nullptr));
		money += luck;
		switch (rand() % 3 + 1)
		{
		case 1:
			cout << "Чайный мастер все еще в деле! Ты получаешь " << luck << " монет(ы)";
			break;
		case 2:
			cout << "Посетители восхищаются твоими навыками боя. Ты получаешь " << luck << " монет(ы)";
			break;
		case 3:
			cout << "Посетители убедились, что у тебя правый коронный, а левый похоронный. Ты получаешь " << luck << " монет(ы)";
			break;
		}
		srand(time(nullptr));
		if (rand() % 4 == 0 && hunger < 3)
		{
			hunger += 1;
			cout << " и чей-то ужин" << endl;
			cout << "Дней до голодной смерти " << hunger;
		}
		cout << endl;
		luck++;
	}
	else
	{
		srand(time(nullptr));
		GetDamage(5);
		switch (rand() % 3 + 1)
		{
		case 1:
			cout << "Тебе стоило оценить свои силы после стольких-то кружечек крепкого чая..." << endl;
			break;
		case 2:
			cout << "Упал. Очнулся. Гипс." << endl;
			break;
		case 3:
			cout << "Ты просыпаешься в местном отрезвителе. Стражник говорит, что тебе еще повезло..." << endl;
			break;
		}
		cout << " Твое здоровье понизилось на 5" << endl;
		if (AreYouAlive())
			cout << "Твое здоровье : " << HP << endl;
		else { cout << "Погиб смертью храбрых...Press F" << endl; }
	}
}






//-----------------------МАГ--------------------------------------------------
Magician::Magician()
{
	FirePower = 10;
	AirPower = 10;
	WaterPower = 10;
	EarthPower = 10;
}
void Magician::ShowHowAreYou()
{
	HowAreYou();
	cout << "Урон огнем: " << FirePower << "\nУрон воздухом: " << AirPower << "\nУрон землей: " << EarthPower << "\nУрон водой: " << WaterPower << endl;
	cout << "Магия лечения восстанавливает " << heal << " здоровья" << endl << endl;
}

//--------------БОЙ--------------------------
void Magician::StartCombat()
{
	cout << "Твои характеристики:" << endl;
	cout << "Здоровье: " << HP << endl;
	cout << "Урон огнем: " << FirePower << "\nУрон воздухом: " << AirPower << "\nУрон землей: " << EarthPower << "\nУрон водой: " << WaterPower << endl;
	cout << "Магия лечения восстанавливает " << heal << " здоровья" << endl << endl;
	
}
int  Magician::ChoiceCommand()
{
	cout << "Выбери действие: \n1.Использовать магию Разрушения\n2.Использовать магию Защиты\n3.Лечиться" << endl << endl;
	int a = CinProtection(3, "Выбери действие(цифра от 1 до 3): \n1.Использовать магию Разрушения\n2.Использовать магию Защиты\n3.Лечиться");
	switch (a)
	{
	case 1:
	{
		cout << "Выбери магию Разрушения: \n1.Пожар\n2.Цунами\n3.Смерч\n4.Землетрясение" << endl << endl;
		int b = CinProtection(4, "Выбери магию Разрушения(цифра от 1 до 4): \n1.Пожар\n2.Цунами\n3.Смерч\n4.Землетрясение");
		return b;
	}
	case 2:
	{   cout << "Выбери магию Защиты: \n1.Огненная карусель\n2.Водоворот\n3.Вихрь\n4.Разлом" << endl << endl;
	int b = CinProtection(4, "Выбери магию Защиты(цифра от 1 до 4): \n1.Огненная карусель\n2.Водоворот\n3.Вихрь\n4.Разлом");
	return b + 4;
	}
	case 3:
		return 9;
	}
	return 0;
}
void FireProtection(Human*& Player, Monster*& m)
{
	switch (m->element)
	{
	case 'f':
		Player->GetDamage(m->mDamage + (Player->FirePower) / 2);
		break;
	case 'w':
		Player->GetDamage(m->mDamage);
		break;
	case 'a':
		if (m->mDamage > Player->FirePower * 5 / 8)
			Player->GetDamage(m->mDamage - Player->FirePower * 5 / 8);
		m->GetDamage(Player->FirePower * 5 / 8);
		break;
	case 'e':
		if (m->mDamage > Player->FirePower / 2)
			Player->GetDamage(m->mDamage - Player->FirePower / 2);
		m->GetDamage(Player->FirePower / 2);
		break;
	}
}
void WaterProtection(Human*& Player, Monster*& m)
{
	switch (m->element)
	{
	case 'w':
		Player->GetDamage(m->mDamage + (Player->WaterPower) / 2);
		break;
	case 'e':
		Player->GetDamage(m->mDamage);
		break;
	case 'f':
		if (m->mDamage > Player->WaterPower * 5 / 8)
			Player->GetDamage(m->mDamage - Player->WaterPower * 5 / 8);
		m->GetDamage(Player->WaterPower * 5 / 8);
		break;
	case 'a':
		if (m->mDamage > Player->WaterPower / 2)
			Player->GetDamage(m->mDamage - Player->WaterPower / 2);
		m->GetDamage(Player->WaterPower / 2);
		break;
	}
}
void AirProtection(Human*& Player, Monster*& m)
{
	switch (m->element)
	{
	case 'a':
		Player->GetDamage(m->mDamage + (Player->AirPower) / 2);
		break;
	case 'f':
		Player->GetDamage(m->mDamage);
		break;
	case 'e':
		if (m->mDamage > Player->AirPower * 5 / 8)
			Player->GetDamage(m->mDamage - Player->AirPower * 5 / 8);
		m->GetDamage(Player->AirPower * 5 / 8);
		break;
	case 'w':
		if (m->mDamage > Player->AirPower / 2)
			Player->GetDamage(m->mDamage - Player->AirPower / 2);
		m->GetDamage(Player->AirPower / 2);
		break;
	}
}
void EarthProtection(Human*& Player, Monster*& m)
{
	switch (m->element)
	{
	case 'e':
		Player->GetDamage(m->mDamage + (Player->EarthPower) / 2);
		break;
	case 'a':
		Player->GetDamage(m->mDamage);
		break;
	case 'w':
		if (m->mDamage > Player->EarthPower * 5 / 8)
			Player->GetDamage(m->mDamage - Player->EarthPower * 5 / 8);
		m->GetDamage(Player->EarthPower * 5 / 8);
		break;
	case 'f':
		if (m->mDamage > Player->EarthPower / 2)
			Player->GetDamage(m->mDamage - Player->EarthPower / 2);
		m->GetDamage(Player->EarthPower / 2);
		break;
	}
}
void Magician::RandUp(char a, int b)
{
	switch (a)
	{
	case 'f':
		cout << "Сила Воды увеличена на " << b << ". Урон Водой: " << WaterPower + b << endl;
		break;
	case 'w':
		cout << "Сила Земли увеличена на " << b << ". Урон Землей: " << EarthPower + b << endl;
		break;
	case 'a':
		cout << "Сила Огня увеличена на " << b << ". Урон Огнем:  " << FirePower + b << endl;
		break;
	case 'e':
		cout << "Сила Воздуха увеличена на " << b << ". Урон Воздухом: " << AirPower + b << endl;
		break;
	}
}

void Magician::Learning(Human*& Player, City*& city)
{
	cout << "Пройти обучение?\n1.Да\n2.Нет" << endl;
	int a = CinProtection(2, "Да или нет -> 1 или 2");
	if (a == 1)
	{
		system("cls");
		cout << "Твои характеристики:" << endl;
		ShowHowAreYou();
		cout << "Во время своего приключения ты будешь встречать монстров. Если ты их не убьешь, то они убьют тебя" << endl;
		cout << "Чтобы победить монстра, ты можешь использовать магию Разрушения" << endl;
		cout << "Вода подавляет Огонь, Огонь подавляет Воздух, Воздух подавляет Землю, Земля подавляет Воду" << endl;
		cout << "Попробуем потренироваться" << endl;
		Monster* m = new Fire(28);
		m->ShowMonster();
		cout << "Как ты можешь понять, этот монстр принадлежит к огненной стихии. Давай попробуем ударить с помощью магии Земли" << endl;
		int a;
		do { cout << "Попробуй использовать магию Разрушения: Землетрясение" << endl; a = ChoiceCommand(); } while (a != 4);
		EarthDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Здорово! Ты у тебя получется нанести урон костру! Но тебя он тоже немного задел..." << endl;

		cout << "Теперь посмотрим, как на него подействует магия Воздуха" << endl;
		do { cout << "Попробуй использовать магию Разрушения: Смерч" << endl; a = ChoiceCommand(); } while (a != 3);
		AirDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Ты машешь руками в попытках сдуть костер. Но ему плевать, хорошо, что он не раздулся еще больше" << endl;

		cout << "Может быть огнем?" << endl;
		do { cout << "Попробуй использовать магию Разрушения: Пожар" << endl; a = ChoiceCommand(); } while (a != 1);
		FireDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Это было не лучшей идеей... Теперь горит все вокруг" << endl;

		cout << "Чтобы восстановить свое здоровье, можешь использовать магию лечения" << endl;
		do { cout << "Попробуй полечиться" << endl; a = ChoiceCommand(); } while (a != 9);
		Healing(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Так как прошлая твоя атака только усилила костер, ты продолжаешь получать урон и магия лечения неэффективна" << endl;

		cout << "Надо потушить это безобразие!" << endl;
		do { cout << "Попробуй использовать магию Разрушения: Цунами" << endl; a = ChoiceCommand(); } while (a != 2);
		WaterDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Вода явно эффективней всего борется с костром. Ты наносишь ему увеличенный урон" << endl;

		cout << "Бой идет на равных, и иногда последний удар монстру может стать последним и для тебя. Поэтому необходимо помнить и о защите" << endl;
		cout << "Ты можешь построить защиту вокруг себя, и монстр попытавшись через нее пробится все еще получит урон, хоть и не такой большой как от магии Разрушения" << endl;
		do { cout << "Попробуй использовать магию Защиты: Водоворот" << endl; a = ChoiceCommand(); } while (a != 6);
		WaterProtection(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Было близко! Но у тебя получилось не умереть" << endl;

		cout << "Ты убиваешь Костер. Твой организм истощился. Нужно следить за своей сытостью, иначе помрешь от голода! Максимум без еды ты можешь прожить 3 дня" << endl;
		Player->Hunger();

		cout << "После убийства монстра ты получаешь уровень, эквивалентный его силе. Чем он сильнее, тем больше уровней ты получаешь" << endl;
		cout << "После боя твое здоровье полностью восстанавливается, а также повышается максимальное значение здоровья" << endl;
		GetXP(Player, m);
		cout << "Так же ты можешь получить трофеи за убийство монстра. Чем сильнее твой враг, тем больше монет ты получишь" << endl;
		Drop(Player, m);
		cout << "Ах, да. Еще прокачивается сила магии той стихии, к которой монстр был слабее\n\n\n" << endl;
		cout << "На пути тебе встречаются города. Тут можно за монеты улучшить силу стихий и поесть. Чем дальше ты зайдешь, тем дороже и качественнее товар." << endl;
		cout << "Так же можешь показать фокусы в таверне, и если удача будет на твоей стороне, то ты заработаешь немного монет или даже чей-то ужин" << endl;
		cout << "Подробнее со своими силами можешь ознакомится в лавке чародея. Удачи!" << endl;
		city->Choose(Player);
		city->LevelDown();
	}
}

//--------------ГОРОД-------------------------
int  Magician::Town()
{
	cout << "Здесь не так много мест, которые можно посетить.. \n1.Лавка Чародея \n2.Таверна\n3.Покинуть город" << endl;
	return CinProtection(3, "Выбери, куда пойти(от 1 до 3): \n1.Лавка Чародея \n2.Таверна \n3.Покинуть город");

}
void Magician::Shop(int CityLevel)
{
	std::cout << "Что тебе нужно?" << endl;
	cout << "Твои деньги: " << money << endl;
	std::cout << "1. Усилить магию Огня      " << FirePower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "2. Усилить магию Воды      " << WaterPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "3. Усилить магию Воздуха   " << AirPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "4. Усилить магию Земли     " << EarthPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "5. Улучшить магию лечения  " << heal << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "6. Как работает магия" << endl;
	std::cout << "7. Выйти из лавки чародея" << endl;

	int a = CinProtection(8, "Выбери цифру от 1 до 8");
	system("cls");
	switch (a)
	{
	case 1:
		FireUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 2:
		WaterUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 3:
		AirUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 4:
		EarthUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 5:
		HealUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 6:
		cout << "В нашем мире действует закон природы: ВОДА->ОГОНЬ->ВОЗДУХ->ЗЕМЛЯ->ВОДА" << endl;
		cout << "Одноименная стихия только усиливает на значение урона, доминирующая стихия наносит увеличиный(+25%) урон," << endl;
		cout << "рецессивная стихия не наносит урон, противоположная стихия -- наносит обычный урон" << endl;
		cout << "Маг -- владеет магией Разрушения : Пожар, Цунами, Смерч, Землетрясение. Может половину магии Разрушения превратить в магию Защиты," << endl;
		cout << "в целом -- магия Разрушающей Защиты : Огненная карусель, Водоворот, Вихрь, Разлом. Может так же лечиться во время боя." << endl;
		break;
	}
	if (a != 7) {
		Shop(CityLevel);
	}
}
int  Magician::Pub(int CityLevel)
{
	cout << "Чем займешься?\n Твои деньги: " << money << "\n1.Поесть за " << CityLevel * 10 - 1 << " монет, дней до голодной смерти: " << hunger << "\n2.Показать посетителям фокусы\n3.Выйти из таверны" << endl;
	return CinProtection(3, "Чем займешься?(цифра от 1 до 3)\n 1.Поесть\n2.Показать посетителям фокусы\n3.Выйти из таверны");
}
void Magician::Active()
{
	system("cls");
	srand(time(nullptr));

	if (rand() % luck == 0)
	{
		srand(time(nullptr));
		money += luck;
		switch (rand() % 3 + 1)
		{
		case 1:
			cout << "Вау! Тебе удалось впечатлить публику такими дешевыми фокусами! Ты получаешь " << luck << " монет(ы)";
			break;
		case 2:
			cout << "Толпа не очень впечатлилась твоими потугами, но сжалилась на тобой. Ты получаешь " << luck << " монет(ы)";
			break;
		case 3:
			cout << "Все настолько были увлечены фокусами, что никто не заметил пропажи...Ты получаешь " << luck << " монет(ы)";
			break;
		}
		srand(time(nullptr));
		if (rand() % 4 == 0 && hunger < 3)
		{
			hunger += 1;
			cout << " и чей-то ужин" << endl;
			cout << "Дней до голодной смерти " << hunger;
		}
		cout << endl;
		luck++;
	}
	else
	{
		srand(time(nullptr));
		GetDamage(5);
		switch (rand() % 3 + 1)
		{
		case 1:
			cout << "Ты и вправду решил проглотить нож?!" << endl;
			break;
		case 2:
			cout << "Не стоило показывать фокус с исчезновением кошелька заядлым разбойникам..." << endl;
			break;
		case 3:
			cout << "Хозяин таверны не поощеряет азартные игры. Он очень-очень вежливо просит убрать игральные карты" << endl;
			break;
		}
		cout << " Твое здоровье понизилось на 5" << endl;
		if (AreYouAlive())
			cout << "Твое здоровье : " << HP << endl;
		else { cout << "Погиб смертью храбрых...Press F" << endl; }

	}
}



//---------------------КЛИРИК--------------------------------------------------
Cleric::Cleric()
{
	FireProtection = 5;
	AirProtection = 5;
	WaterProtection = 5;
	EarthProtection = 5;
}
void Cleric::ShowHowAreYou()
{
	HowAreYou();
	cout << "Связь со Сварогом: " << FirePower << "\nСвязь со Стрибогом: " << AirPower << "\nСвязь с Яровитом: " << EarthPower << "\nСвязь с Перуном: " << WaterPower << endl;
	cout << "Защита Ангелов-Хранителей:" << endl;
	cout << "Защита от огня: " << FireProtection << "\nЗащита от воздуха: " << AirProtection << "\nЗащита от земли: " << EarthProtection << "\nЗащита от воды: " << WaterProtection << endl;
}

//--------------БОЙ---------------------------
void Cleric::StartCombat()
{
	cout << "Твои характеристики:" << endl;
	cout << "Здоровье: " << HP << endl;
	cout << "Связь со Сварогом: " << FirePower << "\nСвязь со Стрибогом: " << AirPower << "\nСвязь с Яровитом: " << EarthPower << "\nСвязь с Перуном: " << WaterPower << endl;
	cout << "Защита Ангелов-Хранителей:" << endl;
	cout << "Защита от огня: " << FireProtection << "\nЗащита от воздуха: " << AirProtection << "\nЗащита от земли: " << EarthProtection << "\nЗащита от воды: " << WaterProtection << endl << endl;

}
int  Cleric::ChoiceCommand()
{
	cout << "Выбери действие: \n1.Помолиться Богам\n2.Лечиться" << endl << endl;
	int a = CinProtection(2, "Выбери действие(цифра 1 или 2): \n1.Помолиться Богам\n2.Излечиться молитвами");
	switch (a)
	{
	case 1:
	{
		cout << "Выбери Бога, которому будешь помолиться: \n1.Сварог\n2.Перун\n3.Стрибог\n4.Яровит" << endl << endl;
		int b = CinProtection(4, "Выбери Бога, которому будешь помолиться(цифра от 1 до 4): \n1.Сварог\n2.Перун\n3.Стрибог\n4.Яровит");
		return b;
	}
	case 2:
	{
		return 9;
	}
	default:
		break;
	}
	return 0;
}
void Cleric::GetDamage(int mDamage, char element)
{
	int Protection = 0;
	switch (element)
	{
	case'f':
		Protection = FireProtection;
		break;
	case'a':
		Protection = AirProtection;
		break;
	case'w':
		Protection = WaterProtection;
		break;
	case'e':
		Protection = EarthProtection;
		break;
	}
	if (HP - mDamage + Protection > 0)
	{
		if (Protection < mDamage)
			HP = HP - mDamage + Protection;
	}
	else HP = 0;
}
void Cleric::GetDamage(int mD)
{
	if (HP > mD)
		HP = HP - mD;
	else HP = 0;
}
void Cleric::RandUp(char a, int b)
{
	switch (a)
	{
	case 'f':
		cout << "Связь с Перуном усилена на " << b << ". Урон Водой: " << WaterPower + b << endl;
		break;
	case 'w':
		cout << "Связь с Яровитом усилена на " << b << ". Урон Землей: " << EarthPower + b << endl;
		break;
	case 'a':
		cout << "Связь с Сварогом усилена на " << b << ". Урон Огнем:  " << FirePower + b << endl;
		break;
	case 'e':
		cout << "Связь с Стрибогом усилена на " << b << ". Урон Воздухом: " << AirPower + b << endl;
		break;
	}
}
void Cleric::Learning(Human*& Player, City*& city)
{
	cout << "Пройти обучение?\n1.Да\n2.Нет" << endl;
	int a = CinProtection(2, "Да или нет -> 1 или 2");
	if (a == 1)
	{
		system("cls");
		cout << "Твои характеристики:" << endl;
		ShowHowAreYou();
		cout << "Во время своего приключения ты будешь встречать монстров, которых создал Повелитель Стихий. Если ты их не убьешь, то они убьют тебя" << endl;
		cout << "Чтобы победить монстра, можно попросить помощь у Богов" << endl;
		cout << "Каждый Бог покровительствует определенной стихии. \nСварог повелевает огнем...\nПерун управляет грозой и молниями...\nСтрибог контролирует стремительные ветра...\nА Яровит является богом плодородия " << endl;
		cout << "Вода подавляет Огонь, Огонь подавляет Воздух, Воздух подавляет Землю, Земля подавляет Воду" << endl;
		cout << "Также у тебя есть пассивная способность -- Ангелы-Хранители, их четверо. Они защитят тебя от части урона или поглотят его полностью" << endl;
		cout << "Попробуем потренироваться. Ты встречаешь Костер." << endl;
		Monster* m = new Fire(11);
		m->ShowMonster();
		cout << "Как ты можешь понять, этот монстр принадлежит к огненной стихии. Давай попробуем ударить с помощью силы Земли" << endl;
		int a;
		do { cout << "Попробуй помолиться Яровиту" << endl; a = ChoiceCommand(); } while (a != 4);
		EarthDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Здорово! Яровит тебя услышал и немного засыпает костер! Твой Ангел Хранитель Огня защищает тебя, ты не получаешь урона" << endl;

		cout << "Теперь посмотрим, как на него подействует сила Воздуха" << endl;
		do { cout << "Попробуй помолится Стрибогу" << endl; a = ChoiceCommand(); } while (a != 3);
		AirDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Стрибог поднял небольшой ветер, но это не помогло. Хорошо, что костер не раздулся еще больше" << endl;

		cout << "Может быть Сварог поможет?" << endl;
		do { cout << "Попробуй помолиться Сварогу" << endl; a = ChoiceCommand(); } while (a != 1);
		FireDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Сварог только подбавил масла в огонь...Костер разгорелся сильнее, теперь защиты Ангела недостаточно" << endl;

		cout << "Попробуй помолиться, чтобы восстановить свое здоровье" << endl;
		do { cout << "Попробуй излечиться молитвами" << endl; a = ChoiceCommand(); } while (a != 9);
		Healing(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Так как прошлая твоя молитва только усилила костер, ты продолжаешь получать урон и молитвы неэффективны" << endl;

		cout << "Только Перун сможет все исправить" << endl;
		do { cout << "Попробуй помолиться Перуну" << endl; a = ChoiceCommand(); } while (a != 2);
		WaterDamage(Player, m);
		cout << "Твое здоровье: " << HP << endl;
		m->HowMonster();
		cout << "Перун вызывает дождь и костер тухнет" << endl;

		cout << "Ты убиваешь Костер. Твой организм истощился. Нужно следить за своей сытостью, иначе помрешь от голода! Максимум без еды ты можешь прожить 3 дня" << endl;
		Player->Hunger();

		cout << "После убийства монстра ты получаешь уровень, эквивалентный его силе. Чем он сильнее, тем больше уровней ты получаешь" << endl;
		cout << "После боя твое здоровье полностью восстанавливается, а также повышается максимальное значение здоровья" << endl;
		GetXP(Player, m);
		cout << "Так же ты можешь получить трофеи за убийство монстра. Чем сильнее твой враг, тем больше монет ты получишь" << endl;
		Drop(Player, m);
		cout << "Ах, да. Еще прокачивается связь с Богом-покровителем, который подавляет стихию убитого монстра\n\n\n" << endl;
		cout << "На пути тебе встречаются города. Тут можно поесть и пожертвовать в Храм для прокачки молитв. Чем дальше ты зайдешь, тем дороже и качественнее товар." << endl;
		cout << "Так же можешь рассказать о своей вере в таверне, и если удача будет на твоей стороне, то кто-нибудь щедро оценит твой вклад в их духовное развитие или даже разделит с тобой ужин" << endl;
		cout << "Подробнее о Богах и своей связи с ними можешь узнать в Храме. Удачи!" << endl;
		city->Choose(Player);
		city->LevelDown();
	}
}
//--------------ГОРОД-----------------------------------------------
int  Cleric::Town()
{
	cout << "Здесь не так много мест, которые можно посетить.. \n1.Храм \n2.Таверна \n3.Покинуть город" << endl;
	return CinProtection(3, "Выбери, куда пойти(1 или 2): \n1.Храм \n2.Таверна \n3.Покинуть город");
}
void Cleric::Shop(int CityLevel)
{
	std::cout << "Добро пожаловать в наш Храм! Хотите сделать пожертвование?\n";
	cout << "Твои деньги: " << money << endl;
	std::cout << "1. Помолиться Сварогу   " << FirePower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "2. Помолиться Перуну    " << WaterPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "3. Помолиться Стрибогу  " << AirPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "4. Помолиться Яровиту   " << EarthPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "5. Поставить свечку Ангелу Огня     " << FireProtection << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "6. Поставить свечку Ангелу Воды     " << WaterProtection << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "7. Поставить свечку Ангелу Воздуха  " << AirProtection << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "8. Поставить свечку Ангелу Земли    " << EarthProtection << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "9. Очищение от грехов " << heal << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " монет" << endl;
	std::cout << "10. Как правильно молиться" << endl;
	std::cout << "11. Покинуть Храм" << endl;


	int a = CinProtection(11, "Выбери цифру от 1 до 11");
	system("cls");
	switch (a)
	{
	case 1:
		FireUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 2:
		WaterUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 3:
		AirUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 4:
		EarthUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 5:
		FireAngelUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 6:
		WaterAngelUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 7:
		AirAngelUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 8:
		EarthAngelUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 9:
		HealUp(CityLevel * 10, CityLevel * 10 - 1);
		break;
	case 10:
		cout << "В нашем мире действует закон природы: ВОДА->ОГОНЬ->ВОЗДУХ->ЗЕМЛЯ->ВОДА" << endl;
		cout << "Одноименная стихия только усиливает на значение урона, доминирующая стихия наносит увеличиный(+25%) урон," << endl;
		cout << "рецессивная стихия не наносит урон, противоположная стихия -- наносит обычный урон" << endl;
		cout << "Клирик -- молится языческим богам. Сварог -- бог войны, Стрибог -- бог ветра, Яровит -- бог плодородия, Перун -- бог грома и дождя."<< endl;
		cout << "Так же у него есть Ангелы-Хранители от каждого бога, которые получают за клирика часть соответствующего урона." << endl;
		break;
	}
	if (a != 11) {
		Shop(CityLevel);
	}
}
//..............Прокачка Ангелов...................
void Cleric::FireAngelUp(int a, int mon)
{
	if (money >= mon) {
		FireProtection += a;
		money -= mon;
	}
	else {
		cout << "Деньжат-то маловато.." << endl;
	}

}
void Cleric::WaterAngelUp(int a, int mon)
{
	if (money >= mon) {
		WaterProtection += a;
		money -= mon;
	}
	else {
		cout << "Деньжат-то маловато.." << endl;
	}

}
void Cleric::AirAngelUp(int a, int mon)
{
	if (money >= mon) {
		AirProtection += a;
		money -= mon;
	}
	else {
		cout << "Деньжат-то маловато.." << endl;
	}
}
void Cleric::EarthAngelUp(int a, int mon)
{
	if (money >= mon) {
		EarthProtection += a;
		money -= mon;
	}
	else {
		cout << "Деньжат-то маловато.." << endl;
	}
}

int  Cleric::Pub(int CityLevel)
{
	cout << "Чем займешься?\n Твои деньги: " << money << "\n1.Поесть за " << CityLevel * 10 - 1 << " монет, дней до голодной смерти: " << hunger << "\n2.Поговорить с посетителями о религии\n3.Выйти из таверны" << endl;
	return CinProtection(3, "Чем займешься?(цифра от 1 до 3)\n 1.Поесть\n2.Поговорить с посетителями о религии\n3.Выйти из таверны");

}
void Cleric::Active()
{
	system("cls");
	srand(time(nullptr));

	if (rand() % luck == 0)
	{
		srand(time(nullptr));
		money += luck;
		switch (rand() % 3 + 1)
		{
		case 1:
			cout << "Посетители думают, что ты сумасшедший, и надеются, что если они дадут тебе немного монет, ты отстанешь. Ты получаешь " << luck << " монет(ы)";
			break;
		case 2:
			cout << "Некоторые посетители всерьез задумались о Богах. Они благодарят тебя за то, что наполнил их жизнь смыслом. Ты получаешь " << luck << " монет(ы)";
			break;
		case 3:
			cout << "Ты пристыдил пару разбойников, пришло их время расплатиться за свои грехи. Ты получаешь " << luck << " монет(ы)";
			break;
		}
		srand(time(nullptr));
		if (rand() % 4 == 0 && hunger < 3)
		{
			hunger += 1;
			cout << " и чей-то ужин" << endl;
			cout << "Дней до голодной смерти " << hunger;
		}
		cout << endl;
		luck++;
	}
	else
	{
		srand(time(nullptr));
		GetDamage(5);
		switch (rand() % 3 + 1)
		{
		case 1:
			cout << "Местный клирик недоволен твоей интерпритацией Божьих слов" << endl;
			break;
		case 2:
			cout << "Упс, похоже в этой таверне сейчас сидят только атеисты..." << endl;
			break;
		case 3:
			cout << "Посетители решили проверить, защищают ли тебя Боги" << endl;
			break;
		}
		cout << " Твое здоровье понизилось на 5" << endl;
		if (AreYouAlive())
			cout << "Твое здоровье : " << HP << endl;
		else { cout << "Погиб смертью храбрых...Press F" << endl; }
	}
}






//___________________________МОНСТРЫ_________________________________________

Monster::Monster(int forse)
{
	mHP = forse;
	mDamage = mHP / 10;

	element = 'n';
}
Monster MeetMonster(int random, Monster*& m, int forse, int randname)
{
	switch (random)
	{
	case 0:
		m = new Fire(forse, randname);
		break;
	case 1:
		m = new Water(forse, randname);
		break;
	case 2:
		m = new Earth(forse, randname);
		break;
	case 3:
		m = new Air(forse, randname);
		break;
	}

	return *m;
}
void Monster::HowMonster()
{
	cout << "Здоровье монстра: " << mHP << "\nСила монстра: " << mDamage << endl << endl;
}
void Monster::GetDamage(int damage)
{
	if (mHP > damage)
	{
		mHP = mHP - damage;
	}
	else mHP = 0;

}
bool Monster::AreYouAlive()
{
	if (mHP < 1)
	{
		return 0;
	}
	return 1;
}
void Monster::ShowMonster() {}
//-----------------------------огонь---------------
Fire::Fire(int force, int randname) : Monster(force)
{
	string FireName[7] = { "Черт","Суккуб","Дьявол","Бес","Цербер", "Саламандр", "Дух Огня" };
	name = FireName[randname];
	element = 'f';
}
Fire::Fire(int force) :Monster(force)
{
	element = 'f';
	name = "Костер";
}
void Fire::ShowMonster()
{
	cout << endl;
	cout << "Перед тобой неожиданно открывается портал из Ада..."<< endl;
	system("pause");
	cout << "Оттуда выходит " << name << endl;
	HowMonster();
}
//-----------------------------земля---------------
Earth::Earth(int force, int randname) : Monster(force)
{
	string EarthName[7] = { "Зомби", "Скелет", "Мумия", "Голем", "Леший", "Огромный червь", "Дух Земли"};
	name = EarthName[randname];
	element = 'e';
}
void Earth::ShowMonster()
{
	cout << endl;
	cout << "Ты слышишь, как из-под земли что-то вылезает..."<<endl;
	system("pause");	
	cout << "Это " << name << endl;
	HowMonster();
}
//-----------------------------вода----------------
Water::Water(int force, int randname) : Monster(force)
{
	string WaterName[7] = { "Водяной", "Русалка", "Лох-Несское чудовище", "Кракен", "Левиафан", "Утопленник", "Дух Воды" };
	name = WaterName[randname];
	element = 'w';
}
void Water::ShowMonster()
{
	cout << endl;
	cout << "Начинается дождь. Твой путь проходит около озера. И вдруг ты видишь, как из воды кто-то выползает... " << endl;
	system("pause");
	cout << "Это " << name << endl;
	HowMonster();
}
//-----------------------------воздух--------------
Air::Air(int force, int randname) : Monster(force)
{
	string AirName[7] = { "Вампир", "Рой", "Грифон", "Призрак", "Баба Яга", "Гарпия", "Дух Воздуха" };
	name = AirName[randname];
	element = 'a';
}
void Air::ShowMonster()
{
	cout << endl;
	cout << "Ты чувствуешь, как воздух вокруг тебя меняется...Ты смотришь вверх и видишь, как на тебя кто-то сваливается..." << endl;
	system("pause");
	cout << "Это " << name << endl;
	HowMonster();
}
//-------------------------------------------------



//........................БОЙ..................................
void Combat(Human*& Player, City*& city)
{

	srand(time(nullptr));
	Monster* m;
	*m = MeetMonster(rand() % 4, m, city->GetMonserHP(rand() % 70 + 25), rand() % 6);
	m->ShowMonster();
	Player->StartCombat();

	while (Player->AreYouAlive() && m->AreYouAlive())
	{
		int a = Player->ChoiceCommand();
		switch (a)
		{
		case 1:
			FireDamage(Player, m);
			break;
		case 2:
			WaterDamage(Player, m);
			break;
		case 3:
			AirDamage(Player, m);
			break;
		case 4:
			EarthDamage(Player, m);
			break;
		case 5:
			FireProtection(Player, m);
			break;
		case 6:
			WaterProtection(Player, m);
			break;
		case 7:
			AirProtection(Player, m);
			break;
		case 8:
			EarthProtection(Player, m);
			break;
		case 9:
			Healing(Player, m);
			break;
		}
		cout << "Твое здоровье: " << Player->GetHP() << endl;
		m->HowMonster();
	}
	system("cls");
	if (!Player->AreYouAlive())
	{
		cout << "Тебя убил монстр" << endl;
	}
	else
	{
		cout << "Ты убиваешь монстра. Твой организм истощился" << endl;
		Player->Hunger();
		if (!Player->AreYouHungry())
		{
			cout << "Ты умираешь от голода" << endl;
		}
		else
		{
			GetXP(Player, m);
			Drop(Player, m);
			
		}
	}

}

void Boss(Human*& Player)
{
	cout << "Ты входишь в Обитель. И тут ты слышишь грозный голос..." << endl;
	cout << "Повелитель стихий: \"Вот мы и встретились...Я много о тебе наслышан...Тобой пройден такой длинный путь...И всего лишь для того... \" " << endl;
	system("pause");
	cout << "ЧТОБЫ УМЕРЕТЬ!" << endl;
	cout << "Повелитель Стихий призывает Дух Огня" << endl;
	Player->StartCombat();
	Monster* m = new Fire(1,6);
	m->HowMonster();
	while (Player->AreYouAlive() && m->AreYouAlive())
	{
		int a = Player->ChoiceCommand();
		switch (a)
		{
		case 1:
			FireDamage(Player, m);
			break;
		case 2:
			WaterDamage(Player, m);
			break;
		case 3:
			AirDamage(Player, m);
			break;
		case 4:
			EarthDamage(Player, m);
			break;
		case 5:
			FireProtection(Player, m);
			break;
		case 6:
			WaterProtection(Player, m);
			break;
		case 7:
			AirProtection(Player, m);
			break;
		case 8:
			EarthProtection(Player, m);
			break;
		case 9:
			Healing(Player, m);
			break;
		}
		cout << "Твое здоровье: " << Player->GetHP() << endl;
		m->HowMonster();
	}
	system("cls");
	if (!Player->AreYouAlive())
	{
		cout << "Повелитель Стихий: \"А я же говорил!!! АХАХАХАХАХАХАХАХАХХАХАХАХАХАХАХАХАХАХА\"" << endl;
		system("pause");
	}
	else
	{
		cout << "Ты убиваешь Дух Огня" << endl;
		cout << "Повелитель Стихий: \"Как так??? А как у тебя получилось??? Кхе-кхе...Тебе просто повезло....\"" << endl;
		system("pause");
		cout << "Повелитель Стихий: \"Но ничего...Дальше тебе не пройти!!!!!\"" << endl;
		cout << "Повелитель Стихий призывает Дух Воды" << endl;
		Player->StartCombat();
		Monster* m = new Water(1, 6);
		m->HowMonster();
		while (Player->AreYouAlive() && m->AreYouAlive())
		{
			int a = Player->ChoiceCommand();
			switch (a)
			{
			case 1:
				FireDamage(Player, m);
				break;
			case 2:
				WaterDamage(Player, m);
				break;
			case 3:
				AirDamage(Player, m);
				break;
			case 4:
				EarthDamage(Player, m);
				break;
			case 5:
				FireProtection(Player, m);
				break;
			case 6:
				WaterProtection(Player, m);
				break;
			case 7:
				AirProtection(Player, m);
				break;
			case 8:
				EarthProtection(Player, m);
				break;
			case 9:
				Healing(Player, m);
				break;
			}
			cout << "Твое здоровье: " << Player->GetHP() << endl;
			m->HowMonster();
		}
		system("cls");
		if (!Player->AreYouAlive())
		{
			cout << "Повелитель Стихий: \"Ну вот и сказочке конееееееееееееец...А кто слушал -- того СМЫЛО! АХАХХАХАХХА \"" << endl;
			system("pause");
		}
		else
		{
			cout << "Ты убиваешь Дух Воды" << endl;
			cout << "Повелитель Стихий: \"Не может быть...Ну все, игры кончились, теперь ты точно проиграешь! МУХАХАХАХАХАХА \"" << endl;
			system("pause");
			cout << "Повелитель Стихий призывает Дух Воздуха" << endl;
			Player->StartCombat();
			Monster* m = new Air(1, 6);
			m->HowMonster();
			while (Player->AreYouAlive() && m->AreYouAlive())
			{
				int a = Player->ChoiceCommand();
				switch (a)
				{
				case 1:
					FireDamage(Player, m);
					break;
				case 2:
					WaterDamage(Player, m);
					break;
				case 3:
					AirDamage(Player, m);
					break;
				case 4:
					EarthDamage(Player, m);
					break;
				case 5:
					FireProtection(Player, m);
					break;
				case 6:
					WaterProtection(Player, m);
					break;
				case 7:
					AirProtection(Player, m);
					break;
				case 8:
					EarthProtection(Player, m);
					break;
				case 9:
					Healing(Player, m);
					break;
				}
				cout << "Твое здоровье: " << Player->GetHP() << endl;
				m->HowMonster();
			}
			system("cls");
			if (!Player->AreYouAlive())
			{
				cout << "Повелитель Стихий: \"Ты заслуживаешь быстрой смерти, раз тебе удалось зайти настолько далеко...Но ты все равно умираешь!!!!\"" << endl;
				system("pause");
			}
			else
			{
				cout << "Ты убиваешь Дух Воздуха" << endl;
				cout << "Повелитель Стихий: *ЯРОЕ НЕГОДОВАНИЕ* \"Да что с тобой не так?! Когда ты уже умрешь, собака?!\"" << endl;
				system("pause");
				cout << "Повелитель Стихий: \"Этот бой будет последним для тебя...\"" << endl;
				cout << "Повелитель Стихий призывает Дух Земли" << endl;
				Player->StartCombat();
				Monster* m = new Earth(1, 6);
				m->HowMonster();
				while (Player->AreYouAlive() && m->AreYouAlive())
				{
					int a = Player->ChoiceCommand();
					switch (a)
					{
					case 1:
						FireDamage(Player, m);
						break;
					case 2:
						WaterDamage(Player, m);
						break;
					case 3:
						AirDamage(Player, m);
						break;
					case 4:
						EarthDamage(Player, m);
						break;
					case 5:
						FireProtection(Player, m);
						break;
					case 6:
						WaterProtection(Player, m);
						break;
					case 7:
						AirProtection(Player, m);
						break;
					case 8:
						EarthProtection(Player, m);
						break;
					case 9:
						Healing(Player, m);
						break;
					}
					cout << "Твое здоровье: " << Player->GetHP() << endl;
					m->HowMonster();
				}
				system("cls");
				if (!Player->AreYouAlive())
				{
					cout << "Повелитель Стихий: \"Ну наконец-то...Ты -- достойный противник...Я запомню тебя...\"" << endl;
					system("pause");
				}
				else
				{
					cout << "Ты убиваешь Дух Земли" << endl;
					cout << "Повелитель Стихий: \"ЧТО??????......\"" << endl;
					cout << "Повелитель Стихий: \"Погоди....Не подходи ко мне....Не надо!....\"" << endl;
					cout << "Ты подходишь ближе к источнику голоса и видишь.... " << endl;
					cout << "...Маленький белый и пушистый комочек" << endl;
					cout << "1. Что?... \n2. Что???????\n3. ЧТООООО??????\n4. ЧТОООООООООООООООО?????????????" << endl;
					int a = CinProtection(5, "5. ЧТОООООООООООО?????????");
					cout << "1. Убить Повелителя Стихий! \n2. Пощадить маленького пушистого котенка..." << endl;
					a = CinProtection(2, "1. Убить Повелителя Стихий! \n2. Пощадить маленького пушистого котенка...");
					if (a == 1)
					{
						cout << "Ты правда убьешь невинного котенка???\n1. Пощадить маленького пушистого котенка...Кыс-кыс-кыс  \n2. ДА!!! Убить Повелителя Стихий!" << endl;
						a = CinProtection(2, "Ты правда убьешь невинного котенка ? ? ? \n1. Пощадить маленького пушистого котенка...Кыс - кыс - кыс\n2.ДА!!!Убить Повелителя Стихий!");
						if (a == 2)
						{
							cout << "Тебя не будет мучить совесть? Ведь нужно жалеть братьев наших меньших..." << endl;
							cout << "1. Но он же уничтожил нашу цивилизацию! Он заслуживает смерти!!!" << endl;
							cout << "2. И правда, он же всего лишь котик...Котики тоже могут ошибаться... " << endl;
							a = CinProtection(2, "\n1. Он заслуживает смерти!!!\n2. Котики тоже могут ошибаться...");
							if (a == 1)
							{
								cout << "Хоть этот выбор даётся тебе с трудом...Ты убиваешь Повелителя Стихий...Перед смертью он издал несколько жалобных \"мяу\"..." << endl;
								system("pause");
								cout << "Ты выходишь из обители с окрававленными руками..." << endl;
								system("pause");
								cout << "Но мир теперь свободен...Гармония вернулась в эти земли..." << endl;
								system("pause");
								cout << "Тебя провозглашают героем и слагают легенды...Баллады пишутся в твою честь и твое имя можно услышать во всех тавернах этого мира" << endl;
								system("pause");
								cout << "Ты, с чувством выполненного долга, идешь на упокой... " << endl;
								system("pause");
								cout << "Но ты никому не расскажешь, даже своим детям и внукам..." << endl;
								system("pause");
								cout << "Как тебе далась эта победа" << endl;
								system("pause");
								cout << "THE GOOD END" << endl;
								system("pause");

							}
							else
							{
								cout << "О нет!...Ты попадаешь под чары Повелителя Стихий и не замечаешь, как из твоей сонной артерии сочится алая кровь... " << endl;
								system("pause");
								cout << "Твое здоровье: -847264728047823748324872047" << endl;
								system("pause");
								cout << "Ты умираешь..." << endl;
								cout << "THE BAD END" << endl;
								system("pause");
							}
						}
						else
						{
							cout << "О нет!...Ты попадаешь под чары Повелителя Стихий и не замечаешь, как из твоей сонной артерии сочится алая кровь... " << endl;
							system("pause");
							cout << "Твое здоровье: -847264728047823748324872047" << endl;
							system("pause");
							cout << "Ты умираешь..." << endl;
							cout << "THE BAD END" << endl;
							system("pause");

						}
					}
					else
					{
						cout << "О нет!...Ты попадаешь под чары Повелителя Стихий и не замечаешь, как из твоей сонной артерии сочится алая кровь... " << endl;
						system("pause");
						cout << "Твое здоровье: -847264728047823748324872047" << endl;
						system("pause");
						cout << "Ты умираешь..." << endl;
						cout << "THE BAD END" << endl;
						system("pause");
					}
				}
			}
		}
	}
}

void FireDamage(Human*& Player, Monster*& m)
{
	switch (m->element)
	{
	case 'a':
	{
		m->GetDamage(Player->FirePower * 5 / 4);
		break;
	}
	case 'e':
	{
		m->GetDamage(Player->FirePower);
		break;
	}
	case 'f':
	{
		m->mDamage = m->mDamage + Player->FirePower;
		break;
	}
	}
	Player->GetDamage(m->mDamage, m->element);
}
void WaterDamage(Human*& Player, Monster*& m)
{
	switch (m->element)
	{
	case 'f':
	{
		m->GetDamage(Player->WaterPower * 5 / 4);
		break;
	}
	case 'a':
	{
		m->GetDamage(Player->WaterPower);
		break;
	}
	case 'w':
	{
		m->mDamage = m->mDamage + Player->WaterPower;
		break;
	}
	}
	Player->GetDamage(m->mDamage, m->element);
}
void AirDamage(Human*& Player, Monster*& m)
{
	switch (m->element)
	{
	case 'e':
	{
		m->GetDamage(Player->AirPower * 5 / 4);
		break;
	}
	case 'w':
	{
		m->GetDamage(Player->AirPower);
		break;
	}
	case 'a':
	{
		m->mDamage = m->mDamage + Player->AirPower;
		break;
	}
	}
	Player->GetDamage(m->mDamage, m->element);
}
void EarthDamage(Human*& Player, Monster*& m)
{
	switch (m->element)
	{
	case 'w':
	{
		m->GetDamage(Player->EarthPower * 5 / 4);
		break;
	}
	case 'f':
	{
		m->GetDamage(Player->EarthPower);
		break;
	}
	case 'e':
	{
		m->mDamage = m->mDamage + Player->EarthPower;
		break;
	}
	}
	Player->GetDamage(m->mDamage, m->element);
}
void Healing(Human*& Player, Monster*& m)
{
	Player->GetHeal();
	if (m->mDamage > Player->shield)
		Player->GetDamage(m->mDamage - Player->shield);
}
void GetXP(Human*& Player, Monster*& m)
{
	Player->XP = Player->XP + m->mDamage / 10 + 1;
	Player->maxHP = Player->maxHP + (m->mDamage / 10 + 1) * 10;
	Player->HP = Player->maxHP;
	cout << "Твое здоровье повысилось на " << (m->mDamage / 10 + 1) * 10 << endl;
	cout << "Твое текущее здоровье: " << Player->HP << endl;
	cout << "Твой уровень повысился на " << (m->mDamage / 10 + 1) << endl;
	cout << "Твой текущий уровень: " << Player->XP << endl;
}
void Drop(Human*& Player, Monster*& m)
{
	Player->money += m->mDamage * 5;
	cout << "Ты получил монеты: " << m->mDamage * 5 << endl;
	cout << "Теперь у тебя монет: " << Player->money << endl;
	srand(time(nullptr));
	int a = rand() % m->mDamage + 1;
	switch (m->element)
	{
	case 'f':
		Player->WaterPower += a;
		break;
	case 'w':
		Player->EarthPower += a;
		break;
	case 'a':
		Player->FirePower += a;
		break;
	case 'e':
		Player->AirPower += a;
		break;
	}
	Player->RandUp(m->element, a);
}

//-------------------ГОРОД--------------------------------
City::City()
{
	level = 1;
}
int  City::GetMonserHP(int a)
{
	return 100 * (level - 1) + a;
}
void City::LevelUp()
{
	level++;
}
void City::LevelDown()
{
	level--;
}
void City::Choose(Human*& Player)
{
	cout << "Ты в городе. ";
	int a = Player->Town();
	switch (a)
	{
	case 1:
		Shop(Player);
		break;
	case 2:
		Pub(Player);
		break;
	case 3:
		Out(Player->Get_XP());
		system("cls");
		break;
	}
}
int  City::GetLevel()
{
	return level;
}
void City::Shop(Human*& Player)
{
	Player->Shop(level);
	Choose(Player);
}
void City::Pub(Human*& Player)
{
	cout << "Ты в таверне. ";
	int a = Player->Pub(level);
	switch (a)
	{
	case 1:
		Player->Eat(level);
		break;
	case 2:
		Player->Active();
		break;
	case 3:
		Choose(Player);
		break;
	}
	if (a != 3 && Player->AreYouAlive())
	{
		Pub(Player);
	}
}
void City::Out(int XP)
{
	int a = 0;
	switch (level)
	{
	case 1:
		LevelUp();
		break;
	case 2:
		cout << "Куда дальше путь держим? \n1.Только вперед!\n2.Пожалуй, стоит вернуться" << endl;
		a = CinProtection(2, "Выбери, куда идти(1 или 2): \n1.Вперед\n2.Назад");
		switch (a)
		{
		case 1:
			LevelUp();
			break;
		case 2:
			LevelDown();
			break;
		}
		break;
	case 3:
		cout << "Куда дальше путь держим? \n1.Только вперед!\n2.Пожалуй, стоит вернуться" << endl;
		a = CinProtection(2, "Выбери, куда идти(1 или 2): \n1.Вперед\n2.Назад");
		switch (a)
		{
		case 1:
			LevelUp();
			break;
		case 2:
			LevelDown();
			break;
		}
		break;
	case 4:
		if (XP < 20)
		{
			cout << "Ты недостаточно силен, чтобы сразиться с Повелителем Стихий! Нужен 20 уровень. Твой уровень: "<< XP << endl;
			cout << "Тебе приходиться вернуться назад" << endl;
			LevelDown();
		}
		else
		{
			cout << "Куда дальше путь держим? \n1.Сразиться с Повелителем Стихий!\n2.Пожалуй, стоит вернуться" << endl;
			a = CinProtection(2, "Выбери, куда идти(1 или 2): \n1.К Повелителю Стихий\n2.Назад");
			switch (a)
			{
			case 1:
				LevelUp();
				break;
			case 2:
				LevelDown();
				break;
			}
			
		}
		break;
	}
}





