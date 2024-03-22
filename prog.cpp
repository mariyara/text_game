#include <iostream>
#include "prog.h"
using namespace std;


//�������� ����� �� �����
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
//..........��������..............................................
Human::Human()
{
	HP = 100; //������� ��������
	maxHP = 100;//������������ ��������, ������� ������������� � �������
	XP = 1; // ������� ������
	hunger = 3;// ���-�� ���� �� �������� ������, �� ����� ���� ������ 3
	money = 0; // ������
	luck = 1; // ��������, ���������� �� �������� � ������� (�����, ������, ��������� � ����)
	FirePower = 5; // ���� ���� �����
	AirPower = 5; // ���� ������� �����
	WaterPower = 5; // ���� ���� �����
	EarthPower = 5; // ���� ����� �����
	heal = 5; // �������� ������� � ���
	shield = 0; // ���, ������� ���� ������ � �����
}
Human Choose(Human*& Player)
{
	std::cout << "������-�����, ����� ��� ���� ������ ������, ���������� ������ ��������, ������ ������..." << endl;
	std::cout << "����, �����, ������ � �����. ��� ������� ���� ��� � ���� � ��������, ��� ��� � ������ ������ ���� ������ � ������� �������," << endl;
	std::cout << "������� �������������� ���� �����..." << endl;
	std::cout << "�� ������� ��� ���������� -- �������� ���������� ������ � ��������� ���� ������� ���������." << endl;
	std::cout << "���������� ������ � ������� �������������� ��� ������ ��������, ������� ���������� ���� ���. ��������� ����." << endl;
	std::cout << "������ ��������� ���� ���������� � �����, �� ��� �� ��� ���� ��������. � ����� �� �������� ������� ���������� ��." << endl;
	std::cout << "���� �������� �������� ���� ��� ������� ����. � �� ������������ ���������� �� ��� �� �� �� ����� �������� ���������� ������" << endl;
	std::cout << "� ������� ��� � ��� �����..." << endl;
	std::cout << "����� ����� ����� �����, ��� �������... \n1.���� \n2.��� \n3.������ " << endl << endl;
	int a;
	while (true)
	{
		cin >> a;
		system("cls");
		if (a >= 1 && a <= 3) break;
		else {
			cin.clear();
			cin.ignore();
			std::cout << "������ ���� �� ���� �������(����� �� 1 �� 3): \n1.���� \n2.��� \n3.������" << endl;
		}
	}
	switch (a)
	{
	case 1:
		Player = new  Warrior();
		std::cout << "�� ��������� ���� �����. ����� �������� ���������� ������, ���� ����� � ������������ �������� �������� ������ ������," << endl;
		std::cout << "� ����� �� �������� �� ���� � ����... " << endl;
		break;
	case 2:
		Player = new Magician();
		std::cout << "�� ��������� ���� ����. ����� �������� ���������� ������, ���� ����� � ������������ �������� ������ ����������," << endl;
		std::cout << "� ����� �� �������� �� ���� � ����... " << endl;
		break;
	case 3:
		Player = new Cleric();
		std::cout << "�� ��������� ���� �������. ����� �������� ���������� ������, ���� ����� �������� ����� ���� ����� � ������," << endl;
		std::cout << "� ����� �� �������� �� ���� � ����... " << endl;
		break;
	}
	return Human();
}
void Human::HowAreYou()
{
	std::cout << "��������: " << HP << "\n�������: " << XP << "\n���� �� �������� ������: " << hunger << "\n�����: " << money << "\n�����: " << luck << endl;
}//����� ��������, ������, ������, �����, �����
//------------------���--------------------------------
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
	std::cout << "���� �� �������� ������: " << hunger << endl;
}
//-----------------�����-------------------------------
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
			cout << "�� �� � ������..." << endl;
			money -= CityLevel * 10 - 1;
		}
	}
	else cout << "�������-�� ��������..." << endl;

	cout << "���� �� �������� ������: " << hunger << endl;
}

//___________�������� �������__________________
void Human::FireUp(int a, int mon)
{
	if (money >= mon) {
		FirePower += a;
		money -= mon;
	}
	else {
		cout << "�������-�� ��������.." << endl;
	}
}
void Human::WaterUp(int a, int mon)
{
	if (money >= mon) {
		WaterPower += a;
		money -= mon;
	}
	else {
		cout << "�������-�� ��������.." << endl;
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
		std::cout << "�������-�� ��������.." << endl;
	}
}
void Human::EarthUp(int a, int mon)
{
	if (money >= mon) {
		EarthPower += a;
		money -= mon;
	}
	else {
		cout << "�������-�� ��������.." << endl;
	}
}
void Human::HealUp(int a, int mon)
{
	if (money >= mon) {
		heal += a;
		money -= mon;
	}
	else {
		cout << "�������-�� ��������.." << endl;
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

//_______������___________________________________________________________________________

//---------------------����--------------------------------------------------
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
	cout << "���� �����: " << FirePower << "\n���� �����: " << AirPower << "\n���� ���������: " << EarthPower << "\n���� ������: " << WaterPower << "\n����������� ����� ����: " << shield << "\n����� ��������������� " << heal << " ��������" << endl << endl;
}

//--------------���---------------------------
void Warrior::StartCombat()
{
	cout << "���� ��������������:" << endl;
	cout << "��������: " << HP << endl;
	cout << "���� �����: " << FirePower << "\n���� �����: " << AirPower << "\n���� ���������: " << EarthPower << "\n���� ������: " << WaterPower << endl;
	cout << "����������� ����� ����: " << shield << "\n����� ��������������� " << heal << " ��������" << endl << endl;

}
void Warrior::Learning(Human*& Player, City*& city)
{
	cout << "������ ��������?\n1.��\n2.���" << endl;
	int a = CinProtection(2, "�� ��� ��� -> 1 ��� 2");
	if (a == 1)
	{
		system("cls");
		cout << "���� ��������������:" << endl;
		ShowHowAreYou();
		cout << "�� ����� ������ ����������� �� ������ ��������� ��������. ���� �� �� �� ������, �� ��� ����� ����" << endl;
		cout << "����� �������� �������, ����� ������������ ������. � ����������� �� ������ ������� ������ ������� ������ ����" << endl;
		cout << "��������, ��� ������� ���� �������� ������, �� � ���� �� ����� ����������, � � ���� ��� ������, ��� � ��" << endl;
		cout << "�������, ��������, ���������� � ����, �� ������ �������� ������ � ��� ����� �� ����..." << endl;
		cout << "�� ���� ������ ��� ����� ����� �����! � ��� �������� ������ �� �� ��������" << endl;
		cout << "��� ���� �����, � ������� ���� ����� �������� �����, �� ����������� � ����, �� ��� � ���� ������ �� ��������..." << endl;
		cout << "������ ��������� ���������������." << endl;
		Monster* m = new Fire(18);
		m->ShowMonster();
		cout << "��� �� ������ ������, ���� ������ ����������� � �������� ������. ����� ��������� ���������� �� ��������" << endl;
	
		int a;
		do { cout << "�������� ������������ �������" << endl; a = ChoiceCommand(); } while (a != 4);
		EarthDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "�������! � ���� ��������� ������� ���� ������! �� ���� �� ���� ������� �����..." << endl;
	
		cout << "������ ���������, ��� �� ���� ����������� ���" << endl;
		do { cout << "�������� ������������ ���" << endl; a = ChoiceCommand(); } while (a != 3);
		AirDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "�� ������ �����, �� ������ ����� ����� �� ��������. �� ��������� � ���� ������, ������� �����������" << endl;
		
		cout << "����� ����, ������ ������ ������ ���� ������?" << endl;
		do { cout << "�������� ������������ ���" << endl; a = ChoiceCommand(); } while (a != 1);
		FireDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "�-��-��, �� ������ �������, ��� ��� ���������� ������ ��� ���������? �� ������ ���������� ��� �������, �� ��� � ��������� �� ���" << endl;
	
		cout << "������ ������������ ��� � ������ �����, ����� ����������. ��� �������� ����, ������� ������� ���� ������, ���� �� ��������" << endl;
		do { cout << "�������� ������ �����" << endl; a = ChoiceCommand(); } while (a != 9);
		Healing(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "���� � ������� ���� ����� ������� ������, �� ���� ����������, ��� ��� ���� ������� ���" << endl;

		cout << "���� ��� ����������! �����! ������� ������� ������!!!!!!!!!!" << endl;
		do { cout << "�������� ������������ �����" << endl; a = ChoiceCommand(); } while (a != 2);
		WaterDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "��� �������, � �� ������...�� ����� ������ ����, ���� �� �������� ������ ����������� ����!" << endl;
		cout << "�� �������� ������. ���� �������� ���������. ����� ������� �� ����� ��������, ����� ������� �� ������! �������� ��� ��� �� ������ ������� 3 ���" << endl;
		Player->Hunger();

		cout << "����� �������� ������� �� ��������� �������, ������������� ��� ����. ��� �� �������, ��� ������ ������� �� ���������" << endl;
		cout << "����� ��� ���� �������� ��������� �����������������, � ����� ���������� ������������ �������� ��������" << endl;
		GetXP(Player, m);
		cout << "��� �� �� ������ �������� ������ �� �������� �������. ��� ������� ���� ����, ��� ������ ����� �� ��������" << endl;
		Drop(Player, m);
		cout << "��, ��. ��� ������������� ���� �������� ��� �������, ������� ����� ����� �������� ������ \n\n\n" << endl;
		cout << "�� ���� ���� ����������� ������. ��� ����� �� ������ �������� ���� ������ � ������. ��� ������ �� �������, ��� ������ � ������������ �����." << endl;
		cout << "��� �� ������ ���������� � ���-������ � �������, � ���� ����� ����� �� ����� �������, �� �� ������� ������� ����� ��� ���� ���-�� ����" << endl;
		cout <<	"��������� �� ���������� ������ ������ ������ ������������ � ���������. �����!" << endl;
		city->Choose(Player);
		city->LevelDown();
	}
	
}
int  Warrior::ChoiceCommand()
{
	if (sip > 0)
	{
		cout << "������ ��������: \n1.������������ ������\n2.������������ ��� � ������ ����� ��������������" << endl << endl;
		int a = CinProtection(2, "������ ��������(����� �� 1 �� 2): \n1.������������ ������\n2.������������ ��� � ������ ����� ��������������");
		switch (a)
		{
		case 1:
		{
			cout << "������ ������: \n1.���\n2.�����\n3.���\n4.�������" << endl << endl;
			int b = CinProtection(4, "������ ������(����� �� 1 �� 4): \n1.���\n2.�����\n3.���\n4.�������");
			return b;
		}
		case 2:
			sip--;
			return 9;
		}
	}
	else
	{
		cout << "����� �������������� �����������" << endl << endl;
		cout << "������ ������: \n1.���\n2.�����\n3.���\n4.�������" << endl << endl;
		int b = CinProtection(4, "������ ������(����� �� 1 �� 4): \n1.���\n2.�����\n3.���\n4.�������");
		return b;
	}

	return 0;
}
void Warrior::RandUp(char a, int b)
{
	switch (a)
	{
	case 'f':
		cout << "������� �������� ������ �������� �� " << b << ". ���� ������: " << WaterPower + b << endl;
		break;
	case 'w':
		cout << "������� �������� ��������� �������� �� " << b << ". ���� ���������: " << EarthPower + b << endl;
		break;
	case 'a':
		cout << "������� �������� ����� �������� �� " << b << ". ���� �����: " << FirePower + b << endl;
		break;
	case 'e':
		cout << "������� �������� ����� �������� �� " << b << ". ���� �����: " << AirPower + b << endl;
		break;
	}
	sip = 3;

}

//--------------�����-------------------------
int  Warrior::Town()
{
	cout << "����� �� ��� ����� ����, ������� ����� ��������.. \n1.��������� \n2.������� \n3.�������� �����" << endl;
	return CinProtection(3, "������, ���� �����(1, 2 ��� 3): \n1.��������� \n2.������� \n3.�������� �����");
}
void Warrior::Shop(int CityLevel)
{
	cout << "��� ���� �����?" << endl;
	cout << "���� ������: " << money << endl;
	cout << "1. �������� ���      " << FirePower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	cout << "2. �������� �����    " << WaterPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	cout << "3. �������� ���      " << AirPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	cout << "4. �������� �������  " << EarthPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	cout << "5. �������� ���      " << shield << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	cout << "6. �������� ����� ��������������  " << heal << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	cout << "7. ��������� �� ������" << endl;
	cout << "8. ����� �� ���������" << endl;

	int a = CinProtection(8, "������ ����� �� 1 �� 8");
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
		cout << "� ����� ���� ��������� ����� �������: ����->�����->������->�����->����" << endl;
		cout << "����������� ������ ������ ��������� �� �������� �����, ������������ ������ ������� ����������(+25%) ����," << endl; 
		cout << "����������� ������ �� ������� ����, ��������������� ������ -- ������� ������� ����" << endl;
		cout << "���� -- ������� 4 ������ ������, ���������� ��� ��� ���������� ����� � � ��� �� ����� ����� ������ ����� ��������������," << endl;
		cout << "�� ������ ���� 3 ���� �� ���, ����� ����� ��� ������������ ����. ������ : ��� -- ����� ������ �������� ������;" << endl;
		cout << "������� -- ������ �������� � ����; ����� -- ����� �������� ����������, �� ������� � ���� ������; ��� -- ������� ��� ��������� �����." << endl;

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
		cout << "�������-�� ��������.." << endl;
	}
}
int  Warrior::Pub(int CityLevel)
{
	cout << "��� ���������?\n ���� ������: " << money << "\n1.������ �� " << CityLevel * 10 - 1 << " �����, ���� �� �������� ������: " << hunger << "\n2.��������� � �����\n3.����� �� �������" << endl;
	return CinProtection(3, "��� ���������?(����� �� 1 �� 3)\n 1.������\n2.��������� � �����\n3.����� �� �������");
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
			cout << "������ ������ ��� ��� � ����! �� ��������� " << luck << " �����(�)";
			break;
		case 2:
			cout << "���������� ����������� ������ �������� ���. �� ��������� " << luck << " �����(�)";
			break;
		case 3:
			cout << "���������� ���������, ��� � ���� ������ ��������, � ����� ����������. �� ��������� " << luck << " �����(�)";
			break;
		}
		srand(time(nullptr));
		if (rand() % 4 == 0 && hunger < 3)
		{
			hunger += 1;
			cout << " � ���-�� ����" << endl;
			cout << "���� �� �������� ������ " << hunger;
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
			cout << "���� ������ ������� ���� ���� ����� ��������-�� �������� �������� ���..." << endl;
			break;
		case 2:
			cout << "����. �������. ����." << endl;
			break;
		case 3:
			cout << "�� ������������ � ������� �����������. �������� �������, ��� ���� ��� �������..." << endl;
			break;
		}
		cout << " ���� �������� ���������� �� 5" << endl;
		if (AreYouAlive())
			cout << "���� �������� : " << HP << endl;
		else { cout << "����� ������� �������...Press F" << endl; }
	}
}






//-----------------------���--------------------------------------------------
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
	cout << "���� �����: " << FirePower << "\n���� ��������: " << AirPower << "\n���� ������: " << EarthPower << "\n���� �����: " << WaterPower << endl;
	cout << "����� ������� ��������������� " << heal << " ��������" << endl << endl;
}

//--------------���--------------------------
void Magician::StartCombat()
{
	cout << "���� ��������������:" << endl;
	cout << "��������: " << HP << endl;
	cout << "���� �����: " << FirePower << "\n���� ��������: " << AirPower << "\n���� ������: " << EarthPower << "\n���� �����: " << WaterPower << endl;
	cout << "����� ������� ��������������� " << heal << " ��������" << endl << endl;
	
}
int  Magician::ChoiceCommand()
{
	cout << "������ ��������: \n1.������������ ����� ����������\n2.������������ ����� ������\n3.��������" << endl << endl;
	int a = CinProtection(3, "������ ��������(����� �� 1 �� 3): \n1.������������ ����� ����������\n2.������������ ����� ������\n3.��������");
	switch (a)
	{
	case 1:
	{
		cout << "������ ����� ����������: \n1.�����\n2.������\n3.�����\n4.�������������" << endl << endl;
		int b = CinProtection(4, "������ ����� ����������(����� �� 1 �� 4): \n1.�����\n2.������\n3.�����\n4.�������������");
		return b;
	}
	case 2:
	{   cout << "������ ����� ������: \n1.�������� ��������\n2.���������\n3.�����\n4.������" << endl << endl;
	int b = CinProtection(4, "������ ����� ������(����� �� 1 �� 4): \n1.�������� ��������\n2.���������\n3.�����\n4.������");
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
		cout << "���� ���� ��������� �� " << b << ". ���� �����: " << WaterPower + b << endl;
		break;
	case 'w':
		cout << "���� ����� ��������� �� " << b << ". ���� ������: " << EarthPower + b << endl;
		break;
	case 'a':
		cout << "���� ���� ��������� �� " << b << ". ���� �����:  " << FirePower + b << endl;
		break;
	case 'e':
		cout << "���� ������� ��������� �� " << b << ". ���� ��������: " << AirPower + b << endl;
		break;
	}
}

void Magician::Learning(Human*& Player, City*& city)
{
	cout << "������ ��������?\n1.��\n2.���" << endl;
	int a = CinProtection(2, "�� ��� ��� -> 1 ��� 2");
	if (a == 1)
	{
		system("cls");
		cout << "���� ��������������:" << endl;
		ShowHowAreYou();
		cout << "�� ����� ������ ����������� �� ������ ��������� ��������. ���� �� �� �� ������, �� ��� ����� ����" << endl;
		cout << "����� �������� �������, �� ������ ������������ ����� ����������" << endl;
		cout << "���� ��������� �����, ����� ��������� ������, ������ ��������� �����, ����� ��������� ����" << endl;
		cout << "��������� ���������������" << endl;
		Monster* m = new Fire(28);
		m->ShowMonster();
		cout << "��� �� ������ ������, ���� ������ ����������� � �������� ������. ����� ��������� ������� � ������� ����� �����" << endl;
		int a;
		do { cout << "�������� ������������ ����� ����������: �������������" << endl; a = ChoiceCommand(); } while (a != 4);
		EarthDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "�������! �� � ���� ��������� ������� ���� ������! �� ���� �� ���� ������� �����..." << endl;

		cout << "������ ���������, ��� �� ���� ����������� ����� �������" << endl;
		do { cout << "�������� ������������ ����� ����������: �����" << endl; a = ChoiceCommand(); } while (a != 3);
		AirDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "�� ������ ������ � �������� ����� ������. �� ��� �������, ������, ��� �� �� �������� ��� ������" << endl;

		cout << "����� ���� �����?" << endl;
		do { cout << "�������� ������������ ����� ����������: �����" << endl; a = ChoiceCommand(); } while (a != 1);
		FireDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "��� ���� �� ������ �����... ������ ����� ��� ������" << endl;

		cout << "����� ������������ ���� ��������, ������ ������������ ����� �������" << endl;
		do { cout << "�������� ����������" << endl; a = ChoiceCommand(); } while (a != 9);
		Healing(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "��� ��� ������� ���� ����� ������ ������� ������, �� ����������� �������� ���� � ����� ������� ������������" << endl;

		cout << "���� �������� ��� ����������!" << endl;
		do { cout << "�������� ������������ ����� ����������: ������" << endl; a = ChoiceCommand(); } while (a != 2);
		WaterDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "���� ���� ����������� ����� ������� � �������. �� �������� ��� ����������� ����" << endl;

		cout << "��� ���� �� ������, � ������ ��������� ���� ������� ����� ����� ��������� � ��� ����. ������� ���������� ������� � � ������" << endl;
		cout << "�� ������ ��������� ������ ������ ����, � ������ ����������� ����� ��� �������� ��� ��� ������� ����, ���� � �� ����� ������� ��� �� ����� ����������" << endl;
		do { cout << "�������� ������������ ����� ������: ���������" << endl; a = ChoiceCommand(); } while (a != 6);
		WaterProtection(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "���� ������! �� � ���� ���������� �� �������" << endl;

		cout << "�� �������� ������. ���� �������� ���������. ����� ������� �� ����� ��������, ����� ������� �� ������! �������� ��� ��� �� ������ ������� 3 ���" << endl;
		Player->Hunger();

		cout << "����� �������� ������� �� ��������� �������, ������������� ��� ����. ��� �� �������, ��� ������ ������� �� ���������" << endl;
		cout << "����� ��� ���� �������� ��������� �����������������, � ����� ���������� ������������ �������� ��������" << endl;
		GetXP(Player, m);
		cout << "��� �� �� ������ �������� ������ �� �������� �������. ��� ������� ���� ����, ��� ������ ����� �� ��������" << endl;
		Drop(Player, m);
		cout << "��, ��. ��� ������������� ���� ����� ��� ������, � ������� ������ ��� ������\n\n\n" << endl;
		cout << "�� ���� ���� ����������� ������. ��� ����� �� ������ �������� ���� ������ � ������. ��� ������ �� �������, ��� ������ � ������������ �����." << endl;
		cout << "��� �� ������ �������� ������ � �������, � ���� ����� ����� �� ����� �������, �� �� ����������� ������� ����� ��� ���� ���-�� ����" << endl;
		cout << "��������� �� ������ ������ ������ ����������� � ����� �������. �����!" << endl;
		city->Choose(Player);
		city->LevelDown();
	}
}

//--------------�����-------------------------
int  Magician::Town()
{
	cout << "����� �� ��� ����� ����, ������� ����� ��������.. \n1.����� ������� \n2.�������\n3.�������� �����" << endl;
	return CinProtection(3, "������, ���� �����(�� 1 �� 3): \n1.����� ������� \n2.������� \n3.�������� �����");

}
void Magician::Shop(int CityLevel)
{
	std::cout << "��� ���� �����?" << endl;
	cout << "���� ������: " << money << endl;
	std::cout << "1. ������� ����� ����      " << FirePower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "2. ������� ����� ����      " << WaterPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "3. ������� ����� �������   " << AirPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "4. ������� ����� �����     " << EarthPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "5. �������� ����� �������  " << heal << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "6. ��� �������� �����" << endl;
	std::cout << "7. ����� �� ����� �������" << endl;

	int a = CinProtection(8, "������ ����� �� 1 �� 8");
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
		cout << "� ����� ���� ��������� ����� �������: ����->�����->������->�����->����" << endl;
		cout << "����������� ������ ������ ��������� �� �������� �����, ������������ ������ ������� ����������(+25%) ����," << endl;
		cout << "����������� ������ �� ������� ����, ��������������� ������ -- ������� ������� ����" << endl;
		cout << "��� -- ������� ������ ���������� : �����, ������, �����, �������������. ����� �������� ����� ���������� ���������� � ����� ������," << endl;
		cout << "� ����� -- ����� ����������� ������ : �������� ��������, ���������, �����, ������. ����� ��� �� �������� �� ����� ���." << endl;
		break;
	}
	if (a != 7) {
		Shop(CityLevel);
	}
}
int  Magician::Pub(int CityLevel)
{
	cout << "��� ���������?\n ���� ������: " << money << "\n1.������ �� " << CityLevel * 10 - 1 << " �����, ���� �� �������� ������: " << hunger << "\n2.�������� ����������� ������\n3.����� �� �������" << endl;
	return CinProtection(3, "��� ���������?(����� �� 1 �� 3)\n 1.������\n2.�������� ����������� ������\n3.����� �� �������");
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
			cout << "���! ���� ������� ���������� ������� ������ �������� ��������! �� ��������� " << luck << " �����(�)";
			break;
		case 2:
			cout << "����� �� ����� ������������ ������ ��������, �� ��������� �� �����. �� ��������� " << luck << " �����(�)";
			break;
		case 3:
			cout << "��� ��������� ���� �������� ��������, ��� ����� �� ������� �������...�� ��������� " << luck << " �����(�)";
			break;
		}
		srand(time(nullptr));
		if (rand() % 4 == 0 && hunger < 3)
		{
			hunger += 1;
			cout << " � ���-�� ����" << endl;
			cout << "���� �� �������� ������ " << hunger;
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
			cout << "�� � ������� ����� ���������� ���?!" << endl;
			break;
		case 2:
			cout << "�� ������ ���������� ����� � ������������� �������� ������� �����������..." << endl;
			break;
		case 3:
			cout << "������ ������� �� ��������� �������� ����. �� �����-����� ������� ������ ������ ��������� �����" << endl;
			break;
		}
		cout << " ���� �������� ���������� �� 5" << endl;
		if (AreYouAlive())
			cout << "���� �������� : " << HP << endl;
		else { cout << "����� ������� �������...Press F" << endl; }

	}
}



//---------------------������--------------------------------------------------
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
	cout << "����� �� ��������: " << FirePower << "\n����� �� ���������: " << AirPower << "\n����� � ��������: " << EarthPower << "\n����� � �������: " << WaterPower << endl;
	cout << "������ �������-����������:" << endl;
	cout << "������ �� ����: " << FireProtection << "\n������ �� �������: " << AirProtection << "\n������ �� �����: " << EarthProtection << "\n������ �� ����: " << WaterProtection << endl;
}

//--------------���---------------------------
void Cleric::StartCombat()
{
	cout << "���� ��������������:" << endl;
	cout << "��������: " << HP << endl;
	cout << "����� �� ��������: " << FirePower << "\n����� �� ���������: " << AirPower << "\n����� � ��������: " << EarthPower << "\n����� � �������: " << WaterPower << endl;
	cout << "������ �������-����������:" << endl;
	cout << "������ �� ����: " << FireProtection << "\n������ �� �������: " << AirProtection << "\n������ �� �����: " << EarthProtection << "\n������ �� ����: " << WaterProtection << endl << endl;

}
int  Cleric::ChoiceCommand()
{
	cout << "������ ��������: \n1.���������� �����\n2.��������" << endl << endl;
	int a = CinProtection(2, "������ ��������(����� 1 ��� 2): \n1.���������� �����\n2.���������� ���������");
	switch (a)
	{
	case 1:
	{
		cout << "������ ����, �������� ������ ����������: \n1.������\n2.�����\n3.�������\n4.������" << endl << endl;
		int b = CinProtection(4, "������ ����, �������� ������ ����������(����� �� 1 �� 4): \n1.������\n2.�����\n3.�������\n4.������");
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
		cout << "����� � ������� ������� �� " << b << ". ���� �����: " << WaterPower + b << endl;
		break;
	case 'w':
		cout << "����� � �������� ������� �� " << b << ". ���� ������: " << EarthPower + b << endl;
		break;
	case 'a':
		cout << "����� � �������� ������� �� " << b << ". ���� �����:  " << FirePower + b << endl;
		break;
	case 'e':
		cout << "����� � ��������� ������� �� " << b << ". ���� ��������: " << AirPower + b << endl;
		break;
	}
}
void Cleric::Learning(Human*& Player, City*& city)
{
	cout << "������ ��������?\n1.��\n2.���" << endl;
	int a = CinProtection(2, "�� ��� ��� -> 1 ��� 2");
	if (a == 1)
	{
		system("cls");
		cout << "���� ��������������:" << endl;
		ShowHowAreYou();
		cout << "�� ����� ������ ����������� �� ������ ��������� ��������, ������� ������ ���������� ������. ���� �� �� �� ������, �� ��� ����� ����" << endl;
		cout << "����� �������� �������, ����� ��������� ������ � �����" << endl;
		cout << "������ ��� ����������������� ������������ ������. \n������ ���������� �����...\n����� ��������� ������ � ��������...\n������� ������������ ������������� �����...\n� ������ �������� ����� ���������� " << endl;
		cout << "���� ��������� �����, ����� ��������� ������, ������ ��������� �����, ����� ��������� ����" << endl;
		cout << "����� � ���� ���� ��������� ����������� -- ������-���������, �� �������. ��� ������� ���� �� ����� ����� ��� �������� ��� ���������" << endl;
		cout << "��������� ���������������. �� ���������� ������." << endl;
		Monster* m = new Fire(11);
		m->ShowMonster();
		cout << "��� �� ������ ������, ���� ������ ����������� � �������� ������. ����� ��������� ������� � ������� ���� �����" << endl;
		int a;
		do { cout << "�������� ���������� �������" << endl; a = ChoiceCommand(); } while (a != 4);
		EarthDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "�������! ������ ���� ������� � ������� �������� ������! ���� ����� ��������� ���� �������� ����, �� �� ��������� �����" << endl;

		cout << "������ ���������, ��� �� ���� ����������� ���� �������" << endl;
		do { cout << "�������� ��������� ��������" << endl; a = ChoiceCommand(); } while (a != 3);
		AirDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "������� ������ ��������� �����, �� ��� �� �������. ������, ��� ������ �� �������� ��� ������" << endl;

		cout << "����� ���� ������ �������?" << endl;
		do { cout << "�������� ���������� �������" << endl; a = ChoiceCommand(); } while (a != 1);
		FireDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "������ ������ �������� ����� � �����...������ ���������� �������, ������ ������ ������ ������������" << endl;

		cout << "�������� ����������, ����� ������������ ���� ��������" << endl;
		do { cout << "�������� ���������� ���������" << endl; a = ChoiceCommand(); } while (a != 9);
		Healing(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "��� ��� ������� ���� ������� ������ ������� ������, �� ����������� �������� ���� � ������� ������������" << endl;

		cout << "������ ����� ������ ��� ���������" << endl;
		do { cout << "�������� ���������� ������" << endl; a = ChoiceCommand(); } while (a != 2);
		WaterDamage(Player, m);
		cout << "���� ��������: " << HP << endl;
		m->HowMonster();
		cout << "����� �������� ����� � ������ ������" << endl;

		cout << "�� �������� ������. ���� �������� ���������. ����� ������� �� ����� ��������, ����� ������� �� ������! �������� ��� ��� �� ������ ������� 3 ���" << endl;
		Player->Hunger();

		cout << "����� �������� ������� �� ��������� �������, ������������� ��� ����. ��� �� �������, ��� ������ ������� �� ���������" << endl;
		cout << "����� ��� ���� �������� ��������� �����������������, � ����� ���������� ������������ �������� ��������" << endl;
		GetXP(Player, m);
		cout << "��� �� �� ������ �������� ������ �� �������� �������. ��� ������� ���� ����, ��� ������ ����� �� ��������" << endl;
		Drop(Player, m);
		cout << "��, ��. ��� ������������� ����� � �����-������������, ������� ��������� ������ ������� �������\n\n\n" << endl;
		cout << "�� ���� ���� ����������� ������. ��� ����� ������ � ������������ � ���� ��� �������� ������. ��� ������ �� �������, ��� ������ � ������������ �����." << endl;
		cout << "��� �� ������ ���������� � ����� ���� � �������, � ���� ����� ����� �� ����� �������, �� ���-������ ����� ������ ���� ����� � �� �������� �������� ��� ���� �������� � ����� ����" << endl;
		cout << "��������� � ����� � ����� ����� � ���� ������ ������ � �����. �����!" << endl;
		city->Choose(Player);
		city->LevelDown();
	}
}
//--------------�����-----------------------------------------------
int  Cleric::Town()
{
	cout << "����� �� ��� ����� ����, ������� ����� ��������.. \n1.���� \n2.������� \n3.�������� �����" << endl;
	return CinProtection(3, "������, ���� �����(1 ��� 2): \n1.���� \n2.������� \n3.�������� �����");
}
void Cleric::Shop(int CityLevel)
{
	std::cout << "����� ���������� � ��� ����! ������ ������� �������������?\n";
	cout << "���� ������: " << money << endl;
	std::cout << "1. ���������� �������   " << FirePower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "2. ���������� ������    " << WaterPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "3. ���������� ��������  " << AirPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "4. ���������� �������   " << EarthPower << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "5. ��������� ������ ������ ����     " << FireProtection << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "6. ��������� ������ ������ ����     " << WaterProtection << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "7. ��������� ������ ������ �������  " << AirProtection << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "8. ��������� ������ ������ �����    " << EarthProtection << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "9. �������� �� ������ " << heal << " + " << CityLevel * 10 << "\t" << CityLevel * 10 - 1 << " �����" << endl;
	std::cout << "10. ��� ��������� ��������" << endl;
	std::cout << "11. �������� ����" << endl;


	int a = CinProtection(11, "������ ����� �� 1 �� 11");
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
		cout << "� ����� ���� ��������� ����� �������: ����->�����->������->�����->����" << endl;
		cout << "����������� ������ ������ ��������� �� �������� �����, ������������ ������ ������� ����������(+25%) ����," << endl;
		cout << "����������� ������ �� ������� ����, ��������������� ������ -- ������� ������� ����" << endl;
		cout << "������ -- ������� ��������� �����. ������ -- ��� �����, ������� -- ��� �����, ������ -- ��� ����������, ����� -- ��� ����� � �����."<< endl;
		cout << "��� �� � ���� ���� ������-��������� �� ������� ����, ������� �������� �� ������� ����� ���������������� �����." << endl;
		break;
	}
	if (a != 11) {
		Shop(CityLevel);
	}
}
//..............�������� �������...................
void Cleric::FireAngelUp(int a, int mon)
{
	if (money >= mon) {
		FireProtection += a;
		money -= mon;
	}
	else {
		cout << "�������-�� ��������.." << endl;
	}

}
void Cleric::WaterAngelUp(int a, int mon)
{
	if (money >= mon) {
		WaterProtection += a;
		money -= mon;
	}
	else {
		cout << "�������-�� ��������.." << endl;
	}

}
void Cleric::AirAngelUp(int a, int mon)
{
	if (money >= mon) {
		AirProtection += a;
		money -= mon;
	}
	else {
		cout << "�������-�� ��������.." << endl;
	}
}
void Cleric::EarthAngelUp(int a, int mon)
{
	if (money >= mon) {
		EarthProtection += a;
		money -= mon;
	}
	else {
		cout << "�������-�� ��������.." << endl;
	}
}

int  Cleric::Pub(int CityLevel)
{
	cout << "��� ���������?\n ���� ������: " << money << "\n1.������ �� " << CityLevel * 10 - 1 << " �����, ���� �� �������� ������: " << hunger << "\n2.���������� � ������������ � �������\n3.����� �� �������" << endl;
	return CinProtection(3, "��� ���������?(����� �� 1 �� 3)\n 1.������\n2.���������� � ������������ � �������\n3.����� �� �������");

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
			cout << "���������� ������, ��� �� �����������, � ��������, ��� ���� ��� ����� ���� ������� �����, �� ���������. �� ��������� " << luck << " �����(�)";
			break;
		case 2:
			cout << "��������� ���������� ������� ���������� � �����. ��� ���������� ���� �� ��, ��� �������� �� ����� �������. �� ��������� " << luck << " �����(�)";
			break;
		case 3:
			cout << "�� ��������� ���� �����������, ������ �� ����� ������������ �� ���� �����. �� ��������� " << luck << " �����(�)";
			break;
		}
		srand(time(nullptr));
		if (rand() % 4 == 0 && hunger < 3)
		{
			hunger += 1;
			cout << " � ���-�� ����" << endl;
			cout << "���� �� �������� ������ " << hunger;
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
			cout << "������� ������ ��������� ����� �������������� ������ ����" << endl;
			break;
		case 2:
			cout << "���, ������ � ���� ������� ������ ����� ������ �������..." << endl;
			break;
		case 3:
			cout << "���������� ������ ���������, �������� �� ���� ����" << endl;
			break;
		}
		cout << " ���� �������� ���������� �� 5" << endl;
		if (AreYouAlive())
			cout << "���� �������� : " << HP << endl;
		else { cout << "����� ������� �������...Press F" << endl; }
	}
}






//___________________________�������_________________________________________

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
	cout << "�������� �������: " << mHP << "\n���� �������: " << mDamage << endl << endl;
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
//-----------------------------�����---------------
Fire::Fire(int force, int randname) : Monster(force)
{
	string FireName[7] = { "����","������","������","���","������", "���������", "��� ����" };
	name = FireName[randname];
	element = 'f';
}
Fire::Fire(int force) :Monster(force)
{
	element = 'f';
	name = "������";
}
void Fire::ShowMonster()
{
	cout << endl;
	cout << "����� ����� ���������� ����������� ������ �� ���..."<< endl;
	system("pause");
	cout << "������ ������� " << name << endl;
	HowMonster();
}
//-----------------------------�����---------------
Earth::Earth(int force, int randname) : Monster(force)
{
	string EarthName[7] = { "�����", "������", "�����", "�����", "�����", "�������� �����", "��� �����"};
	name = EarthName[randname];
	element = 'e';
}
void Earth::ShowMonster()
{
	cout << endl;
	cout << "�� �������, ��� ��-��� ����� ���-�� ��������..."<<endl;
	system("pause");	
	cout << "��� " << name << endl;
	HowMonster();
}
//-----------------------------����----------------
Water::Water(int force, int randname) : Monster(force)
{
	string WaterName[7] = { "�������", "�������", "���-������� ��������", "������", "��������", "����������", "��� ����" };
	name = WaterName[randname];
	element = 'w';
}
void Water::ShowMonster()
{
	cout << endl;
	cout << "���������� �����. ���� ���� �������� ����� �����. � ����� �� ������, ��� �� ���� ���-�� ���������... " << endl;
	system("pause");
	cout << "��� " << name << endl;
	HowMonster();
}
//-----------------------------������--------------
Air::Air(int force, int randname) : Monster(force)
{
	string AirName[7] = { "������", "���", "������", "�������", "���� ���", "������", "��� �������" };
	name = AirName[randname];
	element = 'a';
}
void Air::ShowMonster()
{
	cout << endl;
	cout << "�� ����������, ��� ������ ������ ���� ��������...�� �������� ����� � ������, ��� �� ���� ���-�� �����������..." << endl;
	system("pause");
	cout << "��� " << name << endl;
	HowMonster();
}
//-------------------------------------------------



//........................���..................................
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
		cout << "���� ��������: " << Player->GetHP() << endl;
		m->HowMonster();
	}
	system("cls");
	if (!Player->AreYouAlive())
	{
		cout << "���� ���� ������" << endl;
	}
	else
	{
		cout << "�� �������� �������. ���� �������� ���������" << endl;
		Player->Hunger();
		if (!Player->AreYouHungry())
		{
			cout << "�� �������� �� ������" << endl;
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
	cout << "�� ������� � �������. � ��� �� ������� ������� �����..." << endl;
	cout << "���������� ������: \"��� �� � �����������...� ����� � ���� ��������...����� ������� ����� ������� ����...� ����� ���� ��� ����... \" " << endl;
	system("pause");
	cout << "����� �������!" << endl;
	cout << "���������� ������ ��������� ��� ����" << endl;
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
		cout << "���� ��������: " << Player->GetHP() << endl;
		m->HowMonster();
	}
	system("cls");
	if (!Player->AreYouAlive())
	{
		cout << "���������� ������: \"� � �� �������!!! ��������������������������������������\"" << endl;
		system("pause");
	}
	else
	{
		cout << "�� �������� ��� ����" << endl;
		cout << "���������� ������: \"��� ���??? � ��� � ���� ����������??? ���-���...���� ������ �������....\"" << endl;
		system("pause");
		cout << "���������� ������: \"�� ������...������ ���� �� ������!!!!!\"" << endl;
		cout << "���������� ������ ��������� ��� ����" << endl;
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
			cout << "���� ��������: " << Player->GetHP() << endl;
			m->HowMonster();
		}
		system("cls");
		if (!Player->AreYouAlive())
		{
			cout << "���������� ������: \"�� ��� � �������� �����������������...� ��� ������ -- ���� �����! ����������� \"" << endl;
			system("pause");
		}
		else
		{
			cout << "�� �������� ��� ����" << endl;
			cout << "���������� ������: \"�� ����� ����...�� ���, ���� ���������, ������ �� ����� ����������! �������������� \"" << endl;
			system("pause");
			cout << "���������� ������ ��������� ��� �������" << endl;
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
				cout << "���� ��������: " << Player->GetHP() << endl;
				m->HowMonster();
			}
			system("cls");
			if (!Player->AreYouAlive())
			{
				cout << "���������� ������: \"�� ������������ ������� ������, ��� ���� ������� ����� ��������� ������...�� �� ��� ����� ��������!!!!\"" << endl;
				system("pause");
			}
			else
			{
				cout << "�� �������� ��� �������" << endl;
				cout << "���������� ������: *���� �����������* \"�� ��� � ����� �� ���?! ����� �� ��� ������, ������?!\"" << endl;
				system("pause");
				cout << "���������� ������: \"���� ��� ����� ��������� ��� ����...\"" << endl;
				cout << "���������� ������ ��������� ��� �����" << endl;
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
					cout << "���� ��������: " << Player->GetHP() << endl;
					m->HowMonster();
				}
				system("cls");
				if (!Player->AreYouAlive())
				{
					cout << "���������� ������: \"�� �������-��...�� -- ��������� ���������...� ������� ����...\"" << endl;
					system("pause");
				}
				else
				{
					cout << "�� �������� ��� �����" << endl;
					cout << "���������� ������: \"���??????......\"" << endl;
					cout << "���������� ������: \"������....�� ������� �� ���....�� ����!....\"" << endl;
					cout << "�� ��������� ����� � ��������� ������ � ������.... " << endl;
					cout << "...��������� ����� � �������� �������" << endl;
					cout << "1. ���?... \n2. ���???????\n3. �������??????\n4. ������������������?????????????" << endl;
					int a = CinProtection(5, "5. ��������������?????????");
					cout << "1. ����� ���������� ������! \n2. �������� ���������� ��������� �������..." << endl;
					a = CinProtection(2, "1. ����� ���������� ������! \n2. �������� ���������� ��������� �������...");
					if (a == 1)
					{
						cout << "�� ������ ������ ��������� �������???\n1. �������� ���������� ��������� �������...���-���-���  \n2. ��!!! ����� ���������� ������!" << endl;
						a = CinProtection(2, "�� ������ ������ ��������� ������� ? ? ? \n1. �������� ���������� ��������� �������...��� - ��� - ���\n2.��!!!����� ���������� ������!");
						if (a == 2)
						{
							cout << "���� �� ����� ������ �������? ���� ����� ������ ������� ����� �������..." << endl;
							cout << "1. �� �� �� ��������� ���� �����������! �� ����������� ������!!!" << endl;
							cout << "2. � ������, �� �� ����� ���� �����...������ ���� ����� ���������... " << endl;
							a = CinProtection(2, "\n1. �� ����������� ������!!!\n2. ������ ���� ����� ���������...");
							if (a == 1)
							{
								cout << "���� ���� ����� ����� ���� � ������...�� �������� ���������� ������...����� ������� �� ����� ��������� �������� \"���\"..." << endl;
								system("pause");
								cout << "�� �������� �� ������� � �������������� ������..." << endl;
								system("pause");
								cout << "�� ��� ������ ��������...�������� ��������� � ��� �����..." << endl;
								system("pause");
								cout << "���� ������������� ������ � ������� �������...������� ������� � ���� ����� � ���� ��� ����� �������� �� ���� �������� ����� ����" << endl;
								system("pause");
								cout << "��, � �������� ������������ �����, ����� �� ������... " << endl;
								system("pause");
								cout << "�� �� ������ �� ����������, ���� ����� ����� � ������..." << endl;
								system("pause");
								cout << "��� ���� ������ ��� ������" << endl;
								system("pause");
								cout << "THE GOOD END" << endl;
								system("pause");

							}
							else
							{
								cout << "� ���!...�� ��������� ��� ���� ���������� ������ � �� ���������, ��� �� ����� ������ ������� ������� ���� �����... " << endl;
								system("pause");
								cout << "���� ��������: -847264728047823748324872047" << endl;
								system("pause");
								cout << "�� ��������..." << endl;
								cout << "THE BAD END" << endl;
								system("pause");
							}
						}
						else
						{
							cout << "� ���!...�� ��������� ��� ���� ���������� ������ � �� ���������, ��� �� ����� ������ ������� ������� ���� �����... " << endl;
							system("pause");
							cout << "���� ��������: -847264728047823748324872047" << endl;
							system("pause");
							cout << "�� ��������..." << endl;
							cout << "THE BAD END" << endl;
							system("pause");

						}
					}
					else
					{
						cout << "� ���!...�� ��������� ��� ���� ���������� ������ � �� ���������, ��� �� ����� ������ ������� ������� ���� �����... " << endl;
						system("pause");
						cout << "���� ��������: -847264728047823748324872047" << endl;
						system("pause");
						cout << "�� ��������..." << endl;
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
	cout << "���� �������� ���������� �� " << (m->mDamage / 10 + 1) * 10 << endl;
	cout << "���� ������� ��������: " << Player->HP << endl;
	cout << "���� ������� ��������� �� " << (m->mDamage / 10 + 1) << endl;
	cout << "���� ������� �������: " << Player->XP << endl;
}
void Drop(Human*& Player, Monster*& m)
{
	Player->money += m->mDamage * 5;
	cout << "�� ������� ������: " << m->mDamage * 5 << endl;
	cout << "������ � ���� �����: " << Player->money << endl;
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

//-------------------�����--------------------------------
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
	cout << "�� � ������. ";
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
	cout << "�� � �������. ";
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
		cout << "���� ������ ���� ������? \n1.������ ������!\n2.�������, ����� ���������" << endl;
		a = CinProtection(2, "������, ���� ����(1 ��� 2): \n1.������\n2.�����");
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
		cout << "���� ������ ���� ������? \n1.������ ������!\n2.�������, ����� ���������" << endl;
		a = CinProtection(2, "������, ���� ����(1 ��� 2): \n1.������\n2.�����");
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
			cout << "�� ������������ �����, ����� ��������� � ����������� ������! ����� 20 �������. ���� �������: "<< XP << endl;
			cout << "���� ����������� ��������� �����" << endl;
			LevelDown();
		}
		else
		{
			cout << "���� ������ ���� ������? \n1.��������� � ����������� ������!\n2.�������, ����� ���������" << endl;
			a = CinProtection(2, "������, ���� ����(1 ��� 2): \n1.� ���������� ������\n2.�����");
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





