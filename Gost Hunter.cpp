// GhostHunter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <time.h>

using namespace std;
void FirstChoice();//������ ����� ������, ������� ���������� � ������� ���������, ���� ��������� ����.
void Navigation(int setNavigation);
void ConsolSize(); // ������������� ������ ���� �������. (��������� � �����, �� �������� ���������)
void BigText();// ������� ���� ����.
void Disclaimer();// ������� ������ ��� ������� ����.
void StartMenu();
void StartLocations();// ������ ������� ����� ������ � �����, ������� ���� ����� ��������� ������������, ��� � ����.
void TextWindow();// ������ ������� � ���� � �������. 
void Die(); // ������ �� ����� ��������� ��� ������. 
void Interface();//��������� ������, ���������� ��������, ����, ���������� � �����.
void Action();
void GenerateItem();

void Fight(int mobHeals, int mobDamage);
string GiveKey(bool id);//����� ���� �������� ������������� �������, (��� �� ������ ��� �����) � �� ������ �����, ���� ������ ���� ���� ���. ��� �� ��������� ����� ��������.
//����� (����)

//�������
void Chest();

void Room_Clear_Center();
void Room_Clear_Left();
void Room_Clear_Right();

void Room_A1();

void Room_A2();
void Room_A3();
void Room_A4();
void Room_A5();
void Room_A6();
void Room_A7();
void Room_A8();
void Room_A9();
void Room_A10();
void Room_A11();
void Room_A12();
void Room_A13();
void Room_A14();
void Room_A15();

void ChekDoobleFight();
void ChangeTargetFight(int mobHels_1, int mobDMG_1, int mobHels_2, int mobDMG_2);
void ItemFight();
void SkillsInFight(int lvl);
void Specialization(bool special);
bool mobId[15]{ true , true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true };
bool chekCloseChest[15]{ true , true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true };
bool idlvl[15]{ true , true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true };

int setItem[11];
int z = 0;
int res = 0;
int playerHels = 3;
int playerMana = 5;
int choice, firstChoice;
int key, setNavigation, savePosition, choiceItem;//
char x = 127;
int expirience, mobExp, lvl;
bool speciolization;
bool lose = true;
int deferredDamage;
int newItemDamage[22];
int escapeJump;

string deathWariation[4]{ "������ ��� �����","��������� ��� �� �����", "������� � ��� ���� � �������� �� ����", "��������� ��� �� ������ �������" };
string finishing[6]{ " ������!"," �������� �� �����"," ������ ����", "����������", "��������������", "������ �� ���� �������� ��������" };
string playerName, sayItem, mobName;
string newItem[22];
//�� ��� ����� �� ������ ���� xDDD(�������� �������)
string ratSkils[5]{ "�����", "�������� �����", "����������","������������","������������� ������" };
string magSkils[5]{ "������� ������", "���������", "�������� ����","������ � �����","���������" };
string ratEqip[4]{ "���", "����", "�����", "����" };
string magEqip[4]{ "�����", "������������", "������", "����� ������" };
string skils[5];
string doobleName[2];
//"������","�����","�������","������ - �������","������ ������","������ ������� ������","����������� �������","������ �����", "��������� �������"
int itemDamage[10]{ 2,7,7,5,7,3,5,7,3,0 };
//"�����", "�������� �����", "����������","������������","������������� ������","������� ������", "���������", "�������� ����","������ � �����","���������"
int skilsDamage[5]{ 1,5,9,14,20 };
int eqipDamage[8]{ 1,4,2,4,1,4,2,4 };
int giveMana;

int main()
{

	ConsolSize();
	setlocale(LC_ALL, "russian");

	Disclaimer();
	StartMenu();
	if (playerName == "satan") {
		key += 5;
		playerHels += 100;
		playerMana += 100;
		lvl += 5;

	}
	FirstChoice();
	Room_Clear_Right();






}

void ConsolSize() {

	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { 120,50 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);

}
void Disclaimer() {
	BigText();
	cout << endl << endl;
	cout << "\t\t\t\t\t";
	cout << "\t\t\t\t\t";
	cout << "(�) ������������ ������� ���. �������" << endl;
	cout << "\t\t\t\t\t";
	cout << "\t\t\t\t\t";
	cout << "(c) �������� ������, �������� ��������, �������� ��������" << endl;
	cout << endl;
	cout << "\t\t\t\t";
	cout << "		>>> Press Enter! <<<\n\n\n\n";
	system("pause");
	system("cls");
}
void TextWindow() {
	cout << "\t";
	for (int i = 0; i < 100; i++)
	{
		cout << '#';
	}
	cout << endl;

}

void BigText() {

	char bigStringGost[7][25] = {
		{ '#','#','#','#',' ','#',' ',' ','#',' ','#','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ' },
		{ '#',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ' },
		{ '#',' ','#','#',' ','#','#','#','#',' ','#',' ',' ','#',' ','#','#','#','#',' ',' ',' ','#',' ',' ' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ' },
		{ '#','#','#','#',' ','#',' ',' ','#',' ','#','#','#','#',' ','#','#','#','#',' ',' ',' ','#',' ',' ' }
	};
	char bigStringHuner[7][32] = {
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#' },
		{ '#','#','#','#',' ','#',' ',' ','#',' ','#','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#','#',' ',' ','#','#','#','#','#' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#','#','#',' ',' ' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#',' ' },
		{ '#',' ',' ','#',' ','#','#','#','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#','#','#',' ','#',' ',' ',' ','#' }
	};
	cout << "\t\t\t\t\t";
	for (int t = 0; t < 7; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << bigStringGost[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}

	cout << endl;
	cout << "\t\t\t\t\t";
	for (int t = 0; t < 7; t++)
	{
		for (int i = 0; i < 32; i++)
		{
			cout << bigStringHuner[t][i];
		}
		cout << endl << "\t\t\t\t\t";;
	}

}


void StartMenu() {
	BigText();
	cout << endl << endl;
	cout << "\t\t\t\t";
	cout << "\t �������� ���� ������ �����!\n" << "\t\t\t\t\t\t" << "1) ����� ����!\n" << "\t\t\t\t\t\t" << "2) �����\n\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		StartLocations();

		break;
	case 2:
		break;
	default:
		cout << "�������� �����!" << endl;
		main();
	}

}

void StartLocations() {
	int choiceClass;
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_"; - '��� �������� ������.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\t����� ���������� � ��� �����������. ���������� ���, ������ ����������, �����               |" << endl << "\t|";
	cout << "� ����������� ��������. �� �������� �������� �����������, ����������� � ����������� �����,        |" << endl << "\t|";
	cout << "���� ������ �������. �������, ��� ������� � ����� �� ������� �����. ������� ���������,            |" << endl << "\t|";
	cout << "������� �������� ������� � �����, ��� �� ����� � �������. ���������� ���� ��� �� ���              |" << endl << "\t|";
	cout << "������� � ������� � ����. � ��� ������� ������� ��������� ������, ��� ������� ��������� ����.     |" << endl << "\t|";
	cout << "��������� �� ������ ������. � � ����� ������ ������.                                              |" << endl;
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "�������� ����� ������� ��� �������� ����������, � ��� �������� ��� ��������� �������������,       |" << endl << "\t|";
	cout << "��������� ���� �� ��������, ��� ������������ � ���������� ��������. � ��� ��������, ��� ���,      |" << endl << "\t|";
	cout << "��� ������� �����, �� �������� ����� ���������, ������������� ������, ������, ��� ����������      |" << endl << "\t|";
	cout << "�������� �� ����� ��������. ������ ��������� �������...                                           |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();

	system("pause");
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\t� ���, ��������, ������ ����� �� ���� �������, �� �� ������ ������ ����!                   |" << endl << "\t|";
	cout << "��� �������� ����� � �����, ������ ��� �����, ������ �� ������ ������ �����, ���������� ��        |" << endl << "\t|";
	cout << "�����, �������� ��������� � ���������� �������. ���������� ������� ����� �����!                   |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\t� �������� �����������, ��� ����� ��������� ��������, ������� ������� ��� � ���������.     |" << endl << "\t|";// �������� ��������� �� 5 �������� ��-�� ��������� � ������!
	cout << "��� ��, �� ������� �������� ������� � �����������, �� ��� �� ������� ��, ����������� �����.       |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\t��� ������, ������� ������������!                                                          |" << endl << "\t|";
	cout << "                                                                                                  |" << endl;
	TextWindow();

	cout << "\t\t\t\t������� ��� (�� ����������) :";
	cin >> playerName;

	system("pause");
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_12345678|__|"; - '��� �������� ������.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\t������� " << playerName << " � ������ ������ ����� :" << endl << "\t|";
	cout << "\t1) ����.                                                                                   |" << endl << "\t|";
	cout << "\t2) ���.                                                                                    |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\t������� � ����. �� ������ ������� ��������������� ���������.                               |" << endl << "\t|";
	cout << "��� �������� �������� ��������� ���������� ��������, � ���� ������ �������������.                 |" << endl << "\t|";
	cout << "����� ��� ����� ��������� ���������� ������ ��������, ��� � ���� ����������.                      |" << endl << "\t|";
	cout << "� ��������� �����, ����� ���� �������� ��� ������������ � �����, ��� ������� ����������           |" << endl << "\t|";
	cout << "                                                                                                  |" << endl;
	TextWindow();

	cout << "\t\t\t\t������� ����� ������ :";
	cin >> choiceClass;
	if (choiceClass == 1)
	{
		speciolization = false;
	}
	else
	{
		speciolization = true;
	}
	Specialization(speciolization);


	system("pause");
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������. �������� �������� �� cout.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\t������� " << playerName << ", ������ �� ��������� �����. " << endl << "\t|";
	cout << "�� ������ �� ������ ���� � �����. ��� ������� �� ����? ������? ���������? ����� ���� �������?     |" << endl << "\t|";
	cout << "������� �� �� �������� �����? ��� �������� ������ � ������� ��� �������� �������?                 |" << endl << "\t|";
	cout << "������ �����!                                                                                     |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\t1) ���������� ���������� ����� ������ � ����!                                              |" << endl << "\t|";
	cout << "\t2) ������ ��� ���������� �������...                                                        |" << endl << "\t|";
	cout << "                                                                                                  |" << endl;
	TextWindow();

	cout << "\t" << playerName << " �������! (����� ������������ ������ ������ ��������) : ";
	cin >> firstChoice;
	system("pause");
	system("cls");

}

void FirstChoice() {

	cout << endl;
	if (firstChoice == 1)
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\t������ � ������� ������ ����, ��������� ����� ��������� � ������. ������� ������ �����     |" << endl << "\t|";
		cout << "������ � ����, ������� ���� �� �������� ���� ������ ���������, � ������� �������� �������.        |" << endl << "\t|";
		cout << "������ �������� ����, �� �� �� ��������, � ������� ���� ������ ���. ��� � ����������, � �������.  |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\t��� �� ������� ���������...                                                                |" << endl << "\t|";
		cout << "                                                                                                  |" << endl;
		TextWindow();
		system("pause");
		system("cls");
		Room_A2();
	}
	else
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\t�� ����� ��� ������ ���� ���������� �����. �������� ����� ���������� �� ��� ������.        |" << endl << "\t|";
		cout << "� ����� ������, �� �����, �������� ���� ���� ����� - \"���������!\" �� ���������, ���               |" << endl << "\t|";
		cout << "���������� ��� �����. � ������ ������������ ������ �������, ��������� �� ����.                    |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\t������ �� �������� � 20 ������, ������������ � ������ � ������� � �����. �� � �����        |" << endl << "\t|";
		cout << "���������� ����. ������ ����� ������ �����, �� ������ ������ ��� �����, �� �� ������ ���������,   |" << endl << "\t|";
		cout << "��� ������. ������ �������� ��������� ����� ��������� �� ����...                                  |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "  ����� ���� ������� �����, � ����� ������� ��������� �� ����, ������ �������� ���������� ����.   |" << endl << "\t|";
		cout << "��� ������� �� - " << playerName << "...� ��� ��������� ��������� ����� �����...                        " << endl << "\t|";
		cout << "\t������ �����, ��� ������� ������� �����, ��� ���� �� ����� ��, �������� ���� �� ������...  |" << endl;
		TextWindow();
		Die();
		main();
	}
	system("pause");
	system("cls");

}

void Die() {
	char youDie_YOU[6][15]{
		{ '#',' ',' ',' ','#',' ','#','#','#','#',' ','#',' ',' ','#' },
		{ ' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','#' },
		{ ' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#' },
		{ ' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#' },
		{ ' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#' },
		{ ' ',' ','#',' ',' ',' ','#','#','#','#',' ','#','#','#','#' }
	};

	char youDie_DIE[6][11]{
		{ '#','#',' ',' ',' ','#',' ','#','#','#','#' },
		{ '#',' ','#',' ',' ',' ',' ','#',' ',' ','#' },
		{ '#',' ',' ','#',' ','#',' ','#',' ',' ',' ' },
		{ '#',' ',' ','#',' ','#',' ','#','#','#',' ' },
		{ '#',' ',' ','#',' ','#',' ','#',' ',' ',' ' },
		{ '#','#','#',' ',' ','#',' ','#','#','#','#' }
	};

	char youDie_SKULL[12][8]{
		{ ' ',' ','#','#','#','#',' ',' ' },
		{ ' ','#','#','#','#','#','#',' ' },
		{ ' ','#',' ','#','#',' ','#',' ' },
		{ ' ','#','#','#','#','#','#',' ' },
		{ ' ',' ','*','#','#','*',' ',' ' },
		{ '#',' ',' ','#','#',' ',' ','#' },
		{ '#','*',' ',' ',' ',' ','*','#' },
		{ ' ',' ','*',' ',' ','*',' ',' ' },
		{ ' ',' ',' ','#','#',' ',' ',' ' },
		{ ' ',' ','*',' ',' ','*',' ',' ' },
		{ '#','*',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ','#' }

	};

	cout << "\t\t\t\t\t";
	for (int t = 0; t < 6; t++)
	{
		for (int i = 0; i < 15; i++)
		{
			cout << youDie_YOU[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}

	cout << endl;
	cout << "\t\t\t\t\t  ";

	for (int t = 0; t < 6; t++)
	{
		for (int i = 0; i < 11; i++)
		{
			cout << youDie_DIE[t][i];
		}
		cout << endl << "\t\t\t\t\t  ";;
	}
	cout << endl << endl;

	cout << "\t\t\t\t\t   ";

	for (int t = 0; t < 12; t++)
	{
		for (int i = 0; i < 8; i++)
		{
			cout << youDie_SKULL[t][i];
		}
		cout << endl;
		cout << "\t\t\t\t\t   ";
	}
	cout << endl;
	cout << "\t\t\t\t\t";

	cout << "1) ����� ����!\n" << "\t\t\t\t\t" << "2) �����\n\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		StartLocations();

		break;
	case 2:
		break;
	default:
		cout << "�������� �����!" << endl;
		main();
	}



}
void GenerateItem() {
	string item[11]{ "���, ����� �� ���� ��� :-(", "������","�����","�������","������ - �������","������ ������","������ ������� ������","����������� �������","������ �����", "��������� �������","���, ����� �� ���� ��� :-(" };
	srand(time(NULL));//������ ��������!
	int x = rand() % 11;
	if (z < 22)
	{
		sayItem = item[x];
		setItem[x]++;

	}
	else {
		cout << "�� �� ������ ������ ������ �����, ���. ��� �������� ������� ��� �����!";
	}
	if (x > 0 && x < 11)
	{//itemDamage[10]{2,7,7,5,7,3,5,7,3,0};
		newItem[z] = item[x];
		newItemDamage[z] = itemDamage[x - 1];

		z++;

	}
}



void Navigation(int setNavigation) {
	escapeJump = savePosition;
	switch (setNavigation)
	{
	case 0:
		Chest();
		break;
	case 1:
		Room_A1();
		break;
	case 2:
		Room_A2();
		break;
	case 3:
		Room_A3();
		break;
	case 4:
		Room_A4();
		break;
	case 5:
		Room_A5();
		break;
	case 6:
		Room_A6();
		break;
	case 7:
		Room_A7();
		break;
	case 8:
		Room_A8();
		break;
	case 9:
		Room_A9();
		break;
	case 10:
		Room_A10();
		break;
	case 11:
		Room_A11();
		break;
	case 12:
		Room_A12();
		break;
	case 13:
		Room_A13();
		break;
	case 14:
		Room_A14();
		break;
	case 15:
		Room_A15();
		break;

	case 101:
		Room_Clear_Left();
		break;
	case 102:
		Room_Clear_Center();
		break;
	case 103:
		Room_Clear_Right();
		break;

	default:
		break;
	}

}

void Interface() {
	string coordinatePlayer[16]{ "zer0", "W1", "N1", "E1","W2", "N2", "E2", "W3", "N3", "E3", "W4", "N4", "E4", "W5", "N5", "E5" };
	string who;
	if (speciolization) {
		who = "���";
	}
	else {
		who = "����";
	}
	cout << "\n\t��� ������� : " << lvl << ". �� -\"" << who << "\". ���� �� = " << playerHels << ". ���e MP = " << playerMana << endl;
	cout << "\t��� ���� = " << skilsDamage[0] << " DMG." << " ���� ���������� = \"" << coordinatePlayer[savePosition] << "\"." << endl;
	cout << "\t� ��� � ������� : ";

	cout << "����������� ������ : " << key << "." << endl << "\t";

	if (z > 0) {
		for (int i = 0; i < z; i++)
		{

			cout << newItem[i] << "  ";
			if (i > 2)
			{
				cout << endl << "\t";
			}
		}

	}
	cout << endl << "������ ���� : " << expirience << "." << endl;

}
////////////////////////////////////////////////////////////
void Specialization(bool special)
{
	if (special)
	{
		for (int i = 0; i < 4; i++)
		{

			itemDamage[i + 3]++;
			itemDamage[i + 7]--;
			eqipDamage[i]--;
			eqipDamage[i + 4]++;

		}

		for (int i = 0; i < 5; i++)
		{

			skils[i] = magSkils[i];
		}
		playerMana++;
		skilsDamage[0] = 1;

	}
	else {

		for (int i = 0; i < 4; i++)
		{

			itemDamage[i + 3] --;
			itemDamage[i + 7] ++;
			eqipDamage[i]++;
			eqipDamage[i + 4]--;
		}

		itemDamage[0]++;
		for (int i = 0; i < 5; i++)
		{
			skils[i] = ratSkils[i];
		}
		playerHels++;
		skilsDamage[0] = 1;//�������. ��������� ����� �������, �� ��� ������ ����, ����������� ���������� 0, � ��� ������ ����� =2. �� ������ ���. ��� ���������� �� 10 ���, �� ���� �� ���� �����!
	}

}

void ChekDoobleFight() {

	if (mobId[savePosition] = false) {
		idlvl[savePosition] = false;
	}
}
void ChangeTargetFight(int mobHels_1, int mobDMG_1, int mobHels_2, int mobDMG_2) {
	
	int target,x;
	
	string variationOfAttack[7]{ "����������� ��", "�������� � �����������", "��������������", "��������", "����������", "��������� �� ������ ��������", "��������" };
	

	cout << "\n\t " << playerName << " ������� ����!";
	cout << endl;
	x = rand() % 7;
	cout << "\n\t 1) " << variationOfAttack[x]<<" - " << doobleName[0];
	x = rand() % 7;
	cout << "\n\t 2) " << variationOfAttack[x] << " - " << doobleName[1];
	cout << "\n\t 3) ���������� �������... "<<endl<<"\t";
	cin >> target;
	system("cls");
	switch (target)
	{
	case 1:
		mobName = doobleName[0];
		Fight(mobHels_1, mobDMG_1);
		
		break;
		
	case 2:
		mobName = doobleName[1];
		doobleName[1] = doobleName[0];
		Fight(mobHels_2, mobDMG_2);
		
		
		break;
	case 3:
		cout << "\n\t �� ��������� �������, �� ��� ����� ��� ������ ���������� ������!";
		system("pause");
		Navigation(escapeJump);
		playerHels -= mobDMG_1+mobDMG_2;
		Interface();
		system("pause");
		system("cls");
		break;
	default:
		break;
	}
}

void Fight(int mobHeals, int mobDamage) {
	
	
	int choice;
rechoice:
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\t|" << mobName << " ������� ���������. ��� ��� �� ������ ��� � �������, �� ���� ������!\n";
	cout << "\t|                                                                                                  |" << endl;
	cout << "\t| ������ �������� :                                                                                |" << endl;
	cout << "\t| 1) " << skils[0] << endl;
	cout << "\t| 2) ������������ ������.                                                                          |" << endl;
	cout << "\t| 3) ������������ ����������.                                                                      |" << endl;
	cout << "\t| 4) ������.                                                                                       |" << endl;
	TextWindow();
	Interface();
	cout << "\n\t\t������� ���� ����� : ";
	cin >> choice;
	switch (choice)
	{
	case 1:

		cout << "\n\t\t�� ����������� " << "-" << "\"" << skils[0] << "\"" << " �� " << "\"" << mobName << "\"" << " � ���������� " << skilsDamage[0] << " �����!\n";
		mobHeals -= skilsDamage[0];

	chek:

		if (mobHeals > 0)
		{
			cout << endl << "\t" << mobName << " �� ����, � ���� �������� - " << mobHeals << " ��. �� " << mobName << " ����������� ����! �� ��� �������� - " << mobDamage << " �����!\n";
			playerHels -= mobDamage;
			if (playerHels <= 0)
			{
				system("cls");
				int x;
				x = rand() % 4;
				

				cout << "\t\t\t��� ����������� �������������� " << playerName << "...\n\t\t\t�� \"" << mobName << "\" " << deathWariation[x] << "!\n\n";

				Die();
			}
			system("pause");
			system("cls");
			goto rechoice;
		}
		else {
			int y = rand() % 6;
			cout << "\n\t����������! " << mobName << " " << finishing[y] << endl;
			expirience += mobExp;
			playerMana += giveMana;
			mobId[savePosition] = false;
			if (expirience > 9)
			{
				lvl++;
				skilsDamage[0]++;
			}
			Interface();
			system("pause");
			system("cls");
			Navigation(savePosition);
		}

	case 2:
		lose = true;
		SkillsInFight(lvl);
		mobHeals -= deferredDamage;
		deferredDamage = 0;
		if (lose)
		{
			goto chek;
		}
		else {
			Fight(mobHeals, mobDamage);
		}
		break;
		//�������� ����� : ���� 1 ���� 2 ���� 3 ���� 4
	case 3:


		lose = true;
		ItemFight();
		mobHeals -= deferredDamage;
		deferredDamage = 0;
		if (lose)
		{
			goto chek;
		}
		else {
			Fight(mobHeals, mobDamage);
		}
		break;
	case 4:
		cout << "\n\t �� ��������� �������, �� ��������� ����� � �������!";
		system("pause");
		Navigation(escapeJump);
		playerHels -= mobDamage;
		///////////////////////
	default:
		break;
	}
}

void ItemFight() {
	int choice;
	if (z > 0) {
		for (int i = 0; i < z; i++)
		{

			cout << "\t" << i + 1 << ") " << newItem[i] << "\t";
			if (i > 2)
			{
				cout << endl;
			}

		}
	}
	else {
		cout << "\n\t� ��� ��� ��� �����! �� �������� ������ ��� ������ �������� ������!" << endl;
		lose = false;
		system("pause");
		system("cls");
	}

	if (z > 0) {
		cout << "\n\t�������� ����� : ";
		cin >> choice;
		if (newItem[choice - 1] == "������" || newItem[choice - 1] == "�����" || newItem[choice - 1] == "�������")
		{
			if (newItem[choice - 1] == "�������")
			{
				playerMana += newItemDamage[choice - 1];
			}
			playerHels += newItemDamage[choice - 1];

			for (int i = choice; i < z; i++)
			{

				newItem[i - 1] = newItem[i];
				newItemDamage[i - 1] = newItemDamage[i];
				if (i == z - 1)
				{
					newItem[z] = "clear";
					newItemDamage[z] = 0;

				}
			}

			z--;
		}
		else {
			deferredDamage = newItemDamage[choice - 1];

			for (int i = choice; i < z; i++)
			{
				newItem[i - 1] = newItem[i];
				newItemDamage[i - 1] = newItemDamage[i];
				if (i == z - 1)
				{
					newItem[z] = "clear";
					newItemDamage[z] = 0;

				}
			}

			z--;
		}
	}



}


void SkillsInFight(int lvl) {
rechoice:
	int choice;
	if (lvl > 0)
	{
		for (int i = 1; i < lvl; i++)
		{
			cout << "\n\t" << i << ") " << skils[i];
		}
	}
	if (lvl < 1)
	{
		cout << "\n\t� ��� ��� ��� �������! �� �������� ����� ��� ���������� 1 �����, ������� ���� �� 10��." << endl;
		lose = false;
		system("pause");
		system("cls");
	}
	else {
		cout << "\n\t�������� ����� : ";
		cin >> choice;


		if (choice <= lvl && choice < 5)
		{

			switch (choice) {

			case 1:
				system("cls");
				cout << "\n\t\t�� ����������� " << "-" << "\"" << skils[1] << "\"" << " �� " << "\"" << mobName << "\"" << " � ���������� " << skilsDamage[1] << " �����!\n";
				deferredDamage = skilsDamage[1];
				playerMana -= 2;
				system("pause");
				
				break;
			case 2:
				system("cls");
				cout << "\n\t\t�� ����������� " << "-" << "\"" << skils[2] << "\"" << " �� " << "\"" << mobName << "\"" << " � ���������� " << skilsDamage[2] << " �����!\n";
				deferredDamage = skilsDamage[2];
				playerMana -= 4;
				system("pause");
				
				break;
			case 3:
				system("cls");
				cout << "\n\t\t�� ����������� " << "-" << "\"" << skils[3] << "\"" << " �� " << "\"" << mobName << "\"" << " � ���������� " << skilsDamage[3] << " �����!\n";
				deferredDamage = skilsDamage[3];
				playerMana -= 7;
				system("pause");
				
				break;
			case 4:
				system("cls");
				cout << "\n\t\t�� ����������� " << "-" << "\"" << skils[4] << "\"" << " �� " << "\"" << mobName << "\"" << " � ���������� " << skilsDamage[4] << " �����!\n";
				deferredDamage = skilsDamage[4];
				playerMana -= 10;
				system("pause");
				
				break;
			default:

				break;
			}
		}
		else {

			cout << "/n/t�� ��������� ������ �����! �������� ������� �����!";
			system("pause");
			system("cls");
			goto rechoice;

		}
	}
}
void Action(int roomType) {

	cout << endl;
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\t������ �����!!!                                                                            |" << endl << "\t|";
	cout << "\t1) ���� �� �����.                                                                          |" << endl << "\t|";
	cout << "\t2) ���� �� �����.                                                                          |" << endl << "\t|";
	cout << "\t3) ���� �� ������.                                                                         |" << endl << "\t|";
	cout << "\t4) ���������� �� ��.                                                                       |" << endl;
	switch (roomType)
	{

	case 0:
		TextWindow();
		break;
	case 1:
		cout << "\t|\t5) ������� ������!                                                                         |" << endl << "\t";
		cout << "|                                                                                                  |" << endl;
		TextWindow();

	default:
		break;
	}
}


//�������!!!
void Chest() {

	system("cls");
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_|23456789_123|5678|__|"; - '��� �������� ������. �������� �������� �� cout.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\t������� " << playerName << ", �������� ������ �������� ����, ������� � ���� ���� ����?. " << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\t�� ������ �� �������� � ������� �����...                                                   |" << endl << "\t|";
	if (key > 0) {
		GenerateItem();
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\t�������, �� ����� ����!                                                                    |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "������ ��������� ��� ��� ������� ���������. ������� ������ ������� �������, �� ������� ����������.|" << endl << "\t|";
		cout << "�� �������� �������� ����� ������, �� ����� -\"" << sayItem << "\"" << endl << "\t| ";
		cout << "                                                                                                 |" << endl;
		TextWindow();
		key -= 1;
		chekCloseChest[savePosition] = false;

		system("pause");
		system("cls");
		Navigation(savePosition);

	}
	else {


		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_|23456789_123|5678|__|"; - '��� �������� ������. �������� �������� �� cout.
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\t������� �� ��������, �� ���������, ��� ����� � ��� ��� � ���!                              |" << endl << "\t|";
		cout << "\t���� ������� ������ � �� ��������� �� � ���!                                               |" << endl << "\t|";
		cout << "\t������, ���� ������ �� ��������� ��������...                                               |" << endl << "\t|";
		cout << "                                                                                                  |" << endl;
		TextWindow();

		system("pause");
		system("cls");
		Navigation(savePosition);
	}

}
string GiveKey(bool id) {
	if (id)
	{
		key++;
		return "���� �� �������� ����! ";
	}
	else {

		return "���-�� ��� ����� ��� ������...��� �� ��� ��� ����? ";
	}
}
void Room_Clear_Center() {


	cout << "\n\t\t �� ��������� � ����. �� ��� ��� �� ������ ��� ����� � �����.\n\t����� �������� �� ����� �����, ���� �������, ��� ���� ���������� ������ 5 ������ �����������.\n\t�� ����� ���������, ����������� � ����� �������� ���� � ������������� �����.\n";
	system("pause");
	system("cls");
	Navigation(savePosition);
}
void Room_Clear_Left() {

	cout << "\n\t\t �� ��������� � ����. �� ��� ���������� ��� �� �����. ����� ��������� � ���������� �����\n\t� ����� ����� ���������� ��������. ���� �� ���� ��������� ������������ ��������.\n\t�� �������� ������ ����� ������� ������� � ������������� �����.\n";
	system("pause");
	system("cls");
	Navigation(savePosition);
}
void Room_Clear_Right() {


	cout << "\n\t\t �� ��������� � ����. �� ��� ��� ����� � �������� �������, ������� ������������ ���.\n\t������ ������� �������� ������� ���� ����, �� ������ ������ \"����\"! ��� ������� �����.\n\t� ���� ��� �� �� ������, �� ������� ��������� �����.\n";
	system("pause");
	system("cls");
	Navigation(savePosition);
}


void Room_A1() {

	savePosition = 1;
	mobName = "����������";
	mobExp = 1;
	giveMana = 1;


	system("cls");

	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },//0
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//1
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },//2
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },//3
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },//4
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },//5
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },//6
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },//7
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },//8
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },//9
		{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//10
		{ '#',' ','#','*','*','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//11
		{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//12
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },//13
		{ '#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },//14
		{ '#',' ','#','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },//15
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },//16
		{ '#',' ',' ',' ','#',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ','#',' ','#',' ','#' },//17
		{ '#',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ','#' },//18
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },//19
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//20
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//21
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//22
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//23
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//24
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//25
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }//26
		// 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
	};
	if (!mobId[1]) {
		for (int i = 16; i < 21; i++) {
			for (int j = 11; j < 16; j++)
			{
				room[i][j] = ' ';
			}
		}
		room[21][10] = ' ';
		room[21][14] = ' ';
		room[21][11] = '*';
		room[21][13] = '*';
		room[22][11] = 'X';
		room[22][13] = 'X';
		room[23][10] = '#';
		room[23][14] = '#';
		room[24][11] = '#';
		room[24][11] = ' ';
		room[24][13] = '#';
	}

	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
	cout << endl;
rechoice:
	if (mobId[1])
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\t���������� � ��� ������� �� ����������� �� " << mobName << "! ����� ���� " << playerName << "." << endl;
		cout << "\t|���� �������� ���������!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();


		Fight(2, 1);
		Interface();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\t� ������� ������� ���� ������ " << mobName << "\b�. " << endl << "\t|  " << GiveKey(idlvl[1]);
		cout << " " << playerName << " - �� ��������!" << endl;
		cout << "\t|                                                                                                  |" << endl;
		cout << "\t|���� ��������� �� ����! ���� ����������?                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		Interface();
		idlvl[1] = false;

		cout << "\t �������� ����� : ";
		Action(0);
		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:

			Navigation(4);
			break;
		case 2:
			Navigation(101);
			break;
		case 3:
			Navigation(2);
			break;
		case 4:
			Navigation(102);
			break;


		default:
			cout << "�������� �����";
			goto rechoice;
			break;

		}

	}




}

void Room_A2() {
	savePosition = 2;

	system("cls");
	cout << endl;
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#'},
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ','#','*','*','*','#',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ','*',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ','#',' ',' ','V',' ',' ','#',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }

	};
rechoice:
	if (chekCloseChest[2] == false)
	{
		room[13][10] = '*';
		room[13][11] = '*';
		room[13][12] = '*';
		room[13][13] = '*';
		room[13][14] = '*';
		room[14][10] = '#';
		room[14][14] = '#';
		room[16][10] = 'E';
		room[16][11] = 'M';
		room[16][12] = 'P';
		room[16][13] = 'T';
		room[16][14] = 'Y';
		room[18][12] = ' ';
	}

	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
	cout << endl;
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\t���������� � ��� ������� �� ���������� ���� ������. ���� ���� ����, ������� �������!       |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();


	Action(1);
	Interface();

	cout << endl << endl << "\t\t\t\t\t�������� ����� : ";
	cin >> choice;
	switch (choice) {
	case 1:
		Navigation(5);
		break;
	case 2:
		Navigation(1);
		break;
	case 3:
		Navigation(3);
		break;
	case 4:
		cout << "\n\t\t��! " << playerName << ", ���� ����� ��� ���. ������ � �����!";
		system("pause");
		goto rechoice;
	case 5:
		if (chekCloseChest[2] == true) {
			Navigation(0);

		}
		else {
			system("cls");
			cout << "\n\n\t\t\t �-�-�, �������� �� ��� ��������� ���� ������. ��������, ��� �� ���� ������!\n\n";
			system("pause");

			goto rechoice;
		}
		break;
	default:
		break;
	}

}
void Room_A3() {
	savePosition = 3;
	system("cls");
	cout << endl;
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#','*','*','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','#',' ','#' },//14
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*',' ',' ','#','#',' ','#' },//15
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },//16
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },//17
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ','*','#','#','*',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },//18
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },//19
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//20
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//21
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','A','P','L','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//22
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//23
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//24
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//25
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }//26
	};//   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
	if (idlvl[3] == false) {
		room[15][13] = ' ';
		room[15][11] = '*';
		room[19][10] = ' ';
		room[19][11] = '*';
		room[19][12] = '*';
		room[22][10] = 'S';
		room[22][11] = 'T';
		room[22][12] = 'U';
		room[22][13] = 'B';
	}

	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}

	cout << endl;
	if (idlvl[3])
	{

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
		cout << "\t|                                                                                                 |" << endl << "\t|";
		cout << "\t���������� � ��� ������� �� ��������, ������, ���������, � �������� ������ - \"������\"!    |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t| �� � ������ ���������, ��� ������� ����... ������ ������� ���� ��� �����, �� ����������, ���    |" << endl;
		cout << "\t| ������ �� � ��������� �������������� ����! ���� ���� ��� �� ���������, � ����! " << playerName << "!" << endl;
		cout << "\t| �� � �������� ������������ ���������� � ������, ��� ������� � ���� ���������� ���, ����������   |" << endl;
		cout << "\t| ������� ������, �� �� ������ ������ ������������, � ���� �� ���� ������� ��������� �����.       |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t| ���� �������������� " << playerName << ", � ���� ��� �������� ��� ������!" << endl;
		cout << "\t| ������� �������� ���: +" << itemDamage[0] << " HP!" << endl;
		cout << "\t|                                                                                                 |" << endl;
		playerHels += itemDamage[0];
		idlvl[3] = false;
		TextWindow();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
		cout << "\t|                                                                                                 |" << endl << "\t|";
		cout << "\t���������� � ��� ������� �� ��������, �� ���� �� ����������������� �� �������!            |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t| �� � ������ �������, � ������� ����� � ������������ �� ��� 4 ����. ��������, ��� �����          |" << endl;
		cout << "\t| ���-�� �������� �������� �������. ���������, ���?                                               |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t| �� ����������� ������ ���������� �����, � ���� ���� ������ ���� ���������� ������!              |" << endl;


		TextWindow();

	}

	Action(0);
	Interface();

	cout << endl << endl << "\t\t\t\t\t�������� ����� : ";
	cin >> choice;
	switch (choice) {
	case 1:
		Navigation(6);
		break;
	case 2:
		Navigation(2);
		break;
	case 3:
		Navigation(103);
		break;
	case 4:
		Navigation(102);
		break;
	default:
		break;
	}






}
void Room_A4() {
	savePosition = 4;
	
	system("cls");
	cout << endl;
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#'},
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ','#','*','*','*','#',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ','*',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ','#',' ',' ','V',' ',' ','#',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','W',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }

	};
rechoice:
	if (chekCloseChest[4] == false)
	{
		room[13][10] = '*';
		room[13][11] = '*';
		room[13][12] = '*';
		room[13][13] = '*';
		room[13][14] = '*';
		room[14][10] = '#';
		room[14][14] = '#';
		room[16][10] = 'E';
		room[16][11] = 'M';
		room[16][12] = 'P';
		room[16][13] = 'T';
		room[16][14] = 'Y';
		room[18][12] = ' ';
		
		if (idlvl[4] == false)
		{
			room[22][10] = 'E';
			room[22][11] = 'M';
			room[22][12] = 'P';
			room[22][13] = 'T';
			room[22][14] = 'Y';
			room[21][12] = ' ';

		}
	}

	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
	cout << endl;
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\t���������� � ��� ������� �� ���������� ����� ���! �������. ���� ���� ����, ������� �������!       |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();


	Action(1);
	Interface();

	cout << endl << endl << "\t\t\t\t\t�������� ����� : ";
	cin >> choice;
	switch (choice) {
	case 1:
		Navigation(7);
		break;
	case 2:
		Navigation(101);
		break;
	case 3:
		Navigation(5);
		break;
	case 4:
		Navigation(1);
		break;
	case 5:

		if (chekCloseChest[4] == true) {
			Navigation(0);

		}
		else {
			if (idlvl[4] == true) {

				if (key > 0) {
					idlvl[4] = false;
					Chest();
					
				}

				system("cls");
				cout << "\n\n\t\t\t �-�-�, �������� �� ��� ��������� ���� ������. ��������, ��� �� ���� ������!\n\n";
				system("pause");

				goto rechoice;
			}
			break;
	default:
		break;
		}

	}
}
void Room_A5() {

	savePosition = 5;
	mobName = "����������";
	mobExp = 1;
	giveMana = 1;


	system("cls");

	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },//0
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//1
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },//2
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },//3
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },//4
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },//5
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },//6
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },//7
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },//8
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },//9
		{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//10
		{ '#',' ','#','*','*','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//11
		{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//12
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },//13
		{ '#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },//14
		{ '#',' ','#','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },//15
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },//16
		{ '#',' ',' ',' ','#',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ','#',' ','#',' ','#' },//17
		{ '#',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ','#' },//18
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },//19
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//20
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//21
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//22
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//23
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//24
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//25
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }//26
		// 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
	};
	if (!mobId[5]) {
		for (int i = 16; i < 21; i++) {
			for (int j = 11; j < 16; j++)
			{
				room[i][j] = ' ';
			}
		}
		room[21][10] = ' ';
		room[21][14] = ' ';
		room[21][11] = '*';
		room[21][13] = '*';
		room[22][11] = 'X';
		room[22][13] = 'X';
		room[23][10] = '#';
		room[23][14] = '#';
		room[24][11] = '#';
		room[24][11] = ' ';
		room[24][13] = '#';
	}

	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
	cout << endl;
rechoice:
	if (mobId[5])
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\t���������� � ��� ������� �� ����������� �� " << mobName << "! ����� ���� " << playerName << "." << endl;
		cout << "\t|���� �������� ���������!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();


		Fight(2, 1);
		Interface();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\t� ������� ������� ���� ������ " << mobName << "\b�. " << endl;
		cout << " " << playerName << ", �� ��� ��� ���������, ��� �� �������� � �������?! ���..." << endl;
		cout << "\t|                                                                                                  |" << endl;
		cout << "\t|������ ������ ��� �������! ���� ��������� �� ����! ���� ����������?                               |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		Interface();
		idlvl[5] = false;

		cout << "\t �������� ����� : ";
		Action(0);
		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:

			Navigation(8);
			break;
		case 2:
			Navigation(4);
			break;
		case 3:
			Navigation(6);
			break;
		case 4:
			Navigation(2);
			break;


		default:
			cout << "�������� �����";
			goto rechoice;
			break;

		}

	}
}


	void Room_A6() {

		savePosition = 6;
		mobName = "����������";
		mobExp = 1;
		giveMana = 1;


		system("cls");

		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },//0
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//1
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },//2
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },//3
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },//4
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },//5
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },//6
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },//7
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },//8
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },//9
			{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//10
			{ '#',' ','#','*','*','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//11
			{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//12
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },//13
			{ '#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },//14
			{ '#',' ','#','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },//15
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },//16
			{ '#',' ',' ',' ','#',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ','#',' ','#',' ','#' },//17
			{ '#',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ','#' },//18
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },//19
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//20
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//21
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//22
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//23
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//24
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//25
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }//26
			// 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
		};
		if (!mobId[6]) {
			for (int i = 16; i < 21; i++) {
				for (int j = 11; j < 16; j++)
				{
					room[i][j] = ' ';
				}
			}
			room[21][10] = ' ';
			room[21][14] = ' ';
			room[21][11] = '*';
			room[21][13] = '*';
			room[22][11] = 'X';
			room[22][13] = 'X';
			room[23][10] = '#';
			room[23][14] = '#';
			room[24][11] = '#';
			room[24][11] = ' ';
			room[24][13] = '#';
		}

		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
		cout << endl;
	//rechoice:
		if (mobId[6])
		{
			TextWindow();
			//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
			cout << "\t|                                                                                                  |" << endl << "\t|";
			cout << "\t���������� � ��� ������� �� ����������� �� " << mobName << "! ����� ���� " << playerName << "." << endl;
			cout << "\t|���� �������� ���������!                                                                          |" << endl;
			cout << "\t|                                                                                                  |" << endl;
			TextWindow();


			Fight(2, 1);
			Interface();
		}
		else {

			TextWindow();
			//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
			cout << "\t|                                                                                                  |" << endl << "\t|";
			cout << "\t� ������� ������� ���� ������ " << mobName << "\b�. " << endl << "\t|  " << GiveKey(idlvl[6]);
			cout << " " << playerName << " - �� ��������!" << endl;
			cout << "\t|                                                                                                  |" << endl;
			cout << "\t|���� ����� �����! ���� �������� ������?                                                          |" << endl;
			cout << "\t|                                                                                                  |" << endl;
			TextWindow();
			Interface();
			idlvl[6] = false;

			cout << "\t �������� ����� : ";
			Action(0);
			int choice;

			cin >> choice;

			switch (choice)
			{
			case 1:

				Navigation(9);
				break;
			case 2:
				Navigation(103);
				break;
			case 3:
				Navigation(5);
				break;
			case 4:
				Navigation(3);
				break;


			default:
				cout << "�������� �����";
				//goto rechoice;
				break;

			}

		}

			   		 	}
	void Room_A7() {
		savePosition = 7;
		doobleName[0] = "������� ����������";
		doobleName[1] = "���������� �����";
		
		if (mobId[7]) {
			mobName = doobleName[0];
		}else{ mobName = doobleName[1]; }
	
		mobExp = 1;
		giveMana = 1;


		system("cls");

		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },//0
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//1
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },//2
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },//3
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },//4
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },//5
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },//6
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },//7
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },//8
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },//9
			{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//10
			{ '#',' ','#','*','*','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//11
			{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//12
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },//13
			{ '#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },//14
			{ '#',' ','#','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },//15
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },//16
			{ '#',' ',' ',' ','#',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ','#',' ','#',' ','#' },//17
			{ '#',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ','*','#','*',' ','#','#',' ','#' },//18
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ','*','#','#','#','*',' ','#',' ','#' },//19
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ','#',' ','#',' ','#',' ',' ','*','#' },//20
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ','#','#','#','#','#',' ',' ',' ','#' },//21
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','#','*',' ','*','#',' ','#','*',' ',' ',' ','#' },//22
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ','*','#','*',' ',' ',' ',' ','#' },//23
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#' },//24
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','#' },//25
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }//26
			// 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
		};
		if (!mobId[7]) {
			for (int i = 16; i < 21; i++) {
				for (int j = 11; j < 16; j++)
				{
					room[i][j] = ' ';
				}
			}
			room[21][10] = ' ';
			room[21][14] = ' ';
			room[21][11] = '*';
			room[21][13] = '*';
			room[22][11] = 'X';
			room[22][13] = 'X';
			room[23][10] = '#';
			room[23][14] = '#';
			room[24][11] = '#';
			room[24][11] = ' ';
			room[24][13] = '#';
		}

		if (!idlvl[7])
		{

			room[18][17] = ' ';
			room[18][18] = ' ';
			room[18][19] = ' ';
			room[24][18] = ' ';
			room[25][18] = ' ';
			room[25][19] = ' ';
			room[20][17] = 'X';
			room[20][19] = 'X';
			room[22][18] = 'W';
			
		}


		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
		cout << endl;
		//rechoice:
		if (mobId[7])
		{
			TextWindow();
			//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
			cout << "\t|                                                                                                  |" << endl << "\t|";
			cout << "\t���������� � ��� ������� �� ����������� �� " << doobleName[0] << " � ��� ������� ����� - "<< doobleName[1]<< "! ����� ���� " << playerName << "." << endl;
			cout << "\t|������� �� ����������! � ����� ������, ���� ����� �� ����������...                                |" << endl;
			cout << "\t|                                                                                                  |" << endl;
			TextWindow();
			cout << endl;
			cout << "\t �����-�����, " << playerName << " � ���� ��� � ����, ��� �� � ���� ������!"<<endl;
			cout << "\t ��� ������, " << playerName << " ������ ����, � ����� ��� �����.\n";
			TextWindow();
			ChangeTargetFight(2, 1, 2, 1);
			Interface();
			
					
		}
		
		else if (mobId[7] == false && idlvl[7] == true) {
			idlvl[7] = false;
			system("cls");
			cout << "\n\t ������� " << playerName << ", �������� ������ �������!";
			system("pause");
			Fight(2, 1);
			

		}
		else if(mobId[7] == false && idlvl[7] == false) {

			TextWindow();
			//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - '��� �������� ������.
			cout << "\t|                                                                                                  |" << endl << "\t|";
			cout << "\t� ������� ������� ���� ������ " << doobleName[0] << " � "<< doobleName[1] << endl << "\t|  " << GiveKey(idlvl[6]);
			cout << " " << playerName << " - �� ��������!" << endl;
			cout << "\t|                                                                                                  |" << endl;
			cout << "\t|���� ����� �����! ���� �������� ������?                                                          |" << endl;
			cout << "\t|                                                                                                  |" << endl;
			TextWindow();
			Interface();
			

			cout << "\t �������� ����� : ";
			Action(0);
			int choice;

			cin >> choice;

			switch (choice)
			{
			case 1:

				Navigation(9);
				break;
			case 2:
				Navigation(103);
				break;
			case 3:
				Navigation(5);
				break;
			case 4:
				Navigation(3);
				break;


			default:
				cout << "�������� �����";
				//goto rechoice;
				break;

			}
		}
	}
	void Room_A8() {
		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
		};


		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
	}
	void Room_A9() {
		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
		};


		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
	}
	void Room_A10() {
		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
		};


		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
		cout << "���� �� ����� ����, �� �� �� �� ���.";
		system("pause");
		system("cls");
	}
	void Room_A11() {
		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
		};


		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
	}
	void Room_A12() {
		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
		};


		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
	}
	void Room_A13() {
		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
		};


		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
	}
	void Room_A14() {
		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
		};


		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
	}
	void Room_A15() {
		char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
			{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
			{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
			{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
		};


		cout << "\t\t\t\t\t";
		for (int t = 0; t < 27; t++)
		{
			for (int i = 0; i < 25; i++)
			{
				cout << room[t][i];
			}
			cout << endl << "\t\t\t\t\t";
		}
		cout << "���� �� ����� ����, �� �� �� �� ���.";
		system("pause");
		system("cls");
	}
	

	//����������� �������!!