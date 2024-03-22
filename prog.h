#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <xkeycheck.h>

using namespace std;

int CinProtection(int, string);
class Monster;
class City;
// ПЕРСОНАЖ
class Human {
public:
	Human();
	virtual void ShowHowAreYou();
	virtual void StartCombat();
	virtual void GetDamage(int, char);
	virtual int ChoiceCommand();
	virtual int Town();
	virtual void Shop(int);
	virtual int Pub(int);
	virtual void Active();
	virtual void GetDamage(int);
	virtual void RandUp(char, int);
	virtual void Learning(Human*&, City*&);
	bool AreYouAlive();
	bool AreYouHungry();
	int GetHP();
	int Get_XP();
	void Eat(int);
	void Hunger();
protected:
	int HP; //Здоровье
	int maxHP; // максимальное здоровье
	int XP; // опыт
	int hunger; // голод
	int money; // деньги
	int luck; // удача
	int FirePower; // урон огнем
	int AirPower; // урон воздухом
	int WaterPower; // урон водой
	int EarthPower; // урон землей
	int heal;
	int shield;
	void HowAreYou(); // характеристики Human
	void GetHeal();
	void FireUp(int, int);
	void WaterUp(int, int);
	void AirUp(int, int);
	void EarthUp(int, int);
	void HealUp(int, int);


	friend void FireDamage(Human*&, Monster*&);
	friend void WaterDamage(Human*&, Monster*&);
	friend void AirDamage(Human*&, Monster*&);
	friend void EarthDamage(Human*&, Monster*&);

	friend void FireProtection(Human*&, Monster*&);
	friend void WaterProtection(Human*&, Monster*&);
	friend void AirProtection(Human*&, Monster*&);
	friend void EarthProtection(Human*&, Monster*&);

	friend void Healing(Human*&, Monster*&);
	friend void GetXP(Human*&, Monster*&);
	friend void Drop(Human*&, Monster*&);
};

Human Choose(Human*&); // выбор класса
// КЛАССЫ
class Warrior : public Human
{
public:

	Warrior();
	void ShowHowAreYou();
	void StartCombat();
	int ChoiceCommand();
	int Town();
	void Shop(int);
	void ShieldUp(int, int);
	int Pub(int);
	void Active();
	void RandUp(char, int);
	void Learning(Human*&, City*&);

private:
	int sip;

};
class Magician : public Human
{
public:
	Magician();
	void ShowHowAreYou();
	void StartCombat();
	int ChoiceCommand();
	int Town();
	void Shop(int);
	int Pub(int);
	void Active();
	void RandUp(char, int);
	void Learning(Human*&, City*&);
};
void FireProtection(Human*&, Monster*&);
void WaterProtection(Human*&, Monster*&);
void Airrotection(Human*&, Monster*&);
void EarthProtection(Human*&, Monster*&);
class Cleric : public Human
{
public:
	Cleric();
	void ShowHowAreYou();
	void StartCombat();
	int ChoiceCommand();
	void GetDamage(int, char);
	int Town();
	void Shop(int);
	void FireAngelUp(int, int);
	void WaterAngelUp(int, int);
	void AirAngelUp(int, int);
	void EarthAngelUp(int, int);
	int Pub(int);
	void Active();
	void GetDamage(int);
	void RandUp(char, int);
	void Learning(Human*&, City*&);
private:
	int FireProtection; // защита от огня
	int AirProtection; // защита от воздуха
	int WaterProtection; // защита от воды
	int EarthProtection; // защита от земли

};


// МОНСТРЫ
class Monster
{
public:
	Monster(int);
	virtual void ShowMonster();
	bool AreYouAlive();
	void HowMonster();
protected:

	int mHP;
	int mDamage;
	string name;
	char element;
	void GetDamage(int);


	friend void FireDamage(Human*&, Monster*&);
	friend void WaterDamage(Human*&, Monster*&);
	friend void AirDamage(Human*&, Monster*&);
	friend void EarthDamage(Human*&, Monster*&);

	friend void FireProtection(Human*&, Monster*&);
	friend void WaterProtection(Human*&, Monster*&);
	friend void AirProtection(Human*&, Monster*&);
	friend void EarthProtection(Human*&, Monster*&);

	friend void Healing(Human*&, Monster*&);
	friend void GetXP(Human*&, Monster*&);
	friend void Drop(Human*&, Monster*&);

};
Monster MeetMonster(int, Monster*&, int, int);
class Fire : public Monster
{
public:
	Fire(int, int);
	Fire(int);
	void ShowMonster();
};
class Earth : public Monster
{
public:
	Earth(int, int);
	void ShowMonster();
};
class Water : public Monster
{
public:
	Water(int, int);
	void ShowMonster();
};
class Air : public Monster
{
public:
	Air(int, int);
	void ShowMonster();
};

//----------БОЙ-------------------
void FireDamage(Human*&, Monster*&);
void WaterDamage(Human*&, Monster*&);
void AirDamage(Human*&, Monster*&);
void EarthDamage(Human*&, Monster*&);

void Combat(Human*&, City*&);
void Boss(Human*&);
void Healing(Human*&, Monster*&);
void GetXP(Human*&, Monster*&);

void Drop(Human*&, Monster*&);


// ГОРОД
class City
{
public:
	City();
	int GetMonserHP(int);
	void LevelUp();
	void LevelDown();
	void Choose(Human*&);
	int GetLevel();
private:
	void Shop(Human*&);
	void Pub(Human*&);
	void Out(int);
	int level;
};
void Learning(Human*&);
