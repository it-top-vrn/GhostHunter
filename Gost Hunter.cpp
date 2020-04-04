#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <time.h>

using namespace std;

void FirstChoice();//Первый выбор игрока, который отправляет в функцию навигации, либо завершает игру.
void Navigation(int setNavigation);
void ConsolSize(); // Утснаваливает размер окна консоли. (подглядел в гугле, но пришлось повозится)
void BigText();// Выводит Лого игры.
void Disclaimer();// Выводит прочее при запуске игры.
void StartMenu();
void StartLocations();// Первая локация перед входом в замок, которая худо бедно объясняет пользователю, что к чему.
void TextWindow();// Рисует полоску в окне с текстом. 
void Die(); // Выводи на экран сообщение при смерти. 
void Interface();//Интерфейс игрока, отображает здоровье, ману, снаряжение и карту.
void Action();
void GenerateItem();

void Fight(int mobHeals, int mobDamage);
string GiveKey(bool id);//принимает значение идендификации комнаты, (был ли раньше тут игрок) и на основе этого, либо выдает ключ, либо нет. Так же дополняет текст находкой.

//комнаты
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

void GiveMeAmo(int eqipDMG, int eqipName, int typeEqip);
void ChekDoobleFight();
void ChangeTargetFight(int mobHels_1, int mobDMG_1, int mobHels_2, int mobDMG_2);
void ItemFight();
void SkillsInFight(int lvl);
void Specialization(bool special);
bool mobId[15]{ true , true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true };
bool chekCloseChest[15]{ true , true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true };
bool idlvl[15]{ true , true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true };
bool secretDevice[4]{ false , false , false , false };
int saveJump;
int indicationEqip = 0;
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
string eqipInInterface = "";
string deathWariation[4]{ "снесло вам бошку","разорвало вас на части", "содрало с вас кожу и напялило на себя", "накормило вас несвежей шаурмой" };
string finishing[6]{ " сражен!"," разорван на части"," сожран вами", "нашинкован", "отформатирован", "ощутил на себе жестокое убийство" };
string playerName, sayItem, mobName;
string newItem[22];
//ох тут будет ща полная жопа xDDD(описание навыков)
string ratSkils[5]{ "Порез", "Сквозной порез", "Фаршмашина","Изничтожение","Ультимативная смерть" };
string magSkils[5]{ "Огненая стрела", "Огнехлыст", "Костяные шипы","Смерть с небес","Армагедон" };
string ratEqip[4]{ "Меч", "Коса", "Броня", "Шлем" };
string magEqip[4]{ "Посох", "Некрономикон", "Мантия", "Сфера стихий" };
string skils[5];
string doobleName[2];
//"Яблоко","Зелье","Элексир","Свиток - Фаербол","Свиток Молния","Свиток ледяная стрела","Серебрянные дротики","Святая бомба", "Освященый сюрикен"
int itemDamage[10]{ 2,7,7,5,7,3,5,7,3,0 };
//"Порез", "Сквозной порез", "Фаршмашина","Изничтожение","Ультимативная смерть","Огненая стрела", "Огнехлыст", "Костяные шипы","Смерть с небес","Армагедон"
int skilsDamage[5]{ 1,5,9,14,20 };
int eqipDamage[8]{ 1,4,2,4,1,4,2,4 };
int giveMana;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	ConsolSize();
	
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
	cout << "(с) Компьютерная академи ШАГ. Воронеж" << endl;
	cout << "\t\t\t\t\t";
	cout << "\t\t\t\t\t";
	cout << "(c) Старинин Андрей, Питецкий Владимир" << endl;
	cout << "\t\t\t\t\t";
	cout << "\t\t\t\t\t";
	cout << "(c) Кристина Аристова" << endl;
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
	cout << "\t Сделайте свой первый выбор!\n" << "\t\t\t\t\t\t" << "1) Новая Игра!\n" << "\t\t\t\t\t\t" << "2) Выход\n\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		StartLocations();

		break;
	case 2:
		break;
	default:
		cout << "Неверный выбор!" << endl;
		main();
	}

}

void StartLocations() {
	int choiceClass;
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_"; - 'это разметка текста.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tДобро пожаловать в мир приключений. Прекрасный мир, полный опасностей, зомби               |" << endl << "\t|";
	cout << "и кровожадных монстров. Вы - отважный искатель приключений, отправились в заброшенный замок,        |" << endl << "\t|";
	cout << "дабы спасти дракона. Дракона, что заточен в башне на вершине замка. Злобная принцесса,            |" << endl << "\t|";
	cout << "обманом заманила дракона в башню, где он попал в ловушку. Магические цепи тут же его              |" << endl << "\t|";
	cout << "сковали и прижали к полу. И чем сильнее пытался вырваться дракон, тем сильнее сжимались цепи.     |" << endl << "\t|";
	cout << "Сжимались до хруста костей. И в итоге дракон сдался.                                              |" << endl;
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "Испльзуя кровь дракона, как источник бессмертия, и как материал для ужасающих эксперементов,       |" << endl << "\t|";
	cout << "принцесса сама не заметила, как превратилась в ужаснейшее чудовище. И все подданые, все - все,      |" << endl << "\t|";
	cout << "кто населял замок, со временем, стали монстрами, неупокоенными душами, тенями, что вынужденны      |" << endl << "\t|";
	cout << "скитатся по замку вечность. Таково проклятие дракона...                                           |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();

	system("pause");
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tИ так, старнник, теперь, узнав об этой истории, вы не можете пройти мимо!                   |" << endl << "\t|";
	cout << "Вам придется войти в замок, пройти три этажа, сразив на каждом своего босса, взобраться на        |" << endl << "\t|";
	cout << "башню, победить принцессу и освободить дракона. Освободить дракона любой ценой!                   |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\tВ процессе приключения, вам будут встречаться предметы, которые помогут в сражениях.     |" << endl << "\t|";// Смещение центровки на 5 символов из-за табуляции в начале!
	cout << "Так же, вы сможите отыскать сундуки с сокровищами, но что бы открыть их, понадобятся ключи.       |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\tДля начала, давайте познакомимся!                                                          |" << endl << "\t|";
	cout << "                                                                                                  |" << endl;
	TextWindow();

	cout << "\t\t\t\tВведите имя (на английском) :";
	cin >> playerName;

	system("pause");
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_12345678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tОтлично, " << playerName << ". А теперь выбери класс :" << endl << "\t|";
	cout << "\t1) Воин.                                                                                   |" << endl << "\t|";
	cout << "\t2) Маг.                                                                                    |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\tВыбирай с умом. От выбора зависят характеристики предметов.                               |" << endl << "\t|";
	cout << "Маг получает усиление, используя магические предметы, а воин - ратные, соответсвенно.                 |" << endl << "\t|";
	cout << "Также маг менее эффективно использует ратные предметы, как и воин магические.                      |" << endl << "\t|";
	cout << "У некоторых боссов, может быть слабость или спротивление к магии, или ратному вооружению           |" << endl << "\t|";
	cout << "                                                                                                  |" << endl;
	TextWindow();

	cout << "\t\t\t\tВведите номер класса :";
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
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста. Выровняй разметку по cout.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tОтлично, " << playerName << ", теперь ты полностью готов. " << endl << "\t|";
	cout << "Ты стоишь на пороге врат в замок. Что ожидает за ними? Смерть? Сокровища? Может быть любовь?     |" << endl << "\t|";
	cout << "Решишься ли ты отворить врата? Или поддашься страху и убежишь, как пугливый котёнок?                 |" << endl << "\t|";
	cout << "Сделай выбор!                                                                                     |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\t1) Распахнуть обветшалые врата ударом с ноги!                                              |" << endl << "\t|";
	cout << "\t2) Бежать, как испуганный котёнок...                                                        |" << endl << "\t|";
	cout << "                                                                                                  |" << endl;
	TextWindow();

	cout << "\t" << playerName << ", выбирай! (Выбор производится вводом номера варианта) : ";
	cin >> firstChoice;
	system("pause");
	system("cls");

}

void FirstChoice() {

	cout << endl;
	if (firstChoice == 1)
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tРезким и жестким ударом ноги, трухлявая дверь сорвалась с петель. Спертый воздуг резко     |" << endl << "\t|";
		cout << "ударил в лицо, грязные окна не впускали свет внутрь помещения, а потолок украшала паутина.        |" << endl << "\t|";
		cout << "Сердце забилось чаще, но вы не струсили, и сделали свой первый шаг. Шаг в неведанное, в пустоту.  |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\tШаг навстречу опасности...                                                                |" << endl << "\t|";
		cout << "                                                                                                  |" << endl;
		TextWindow();
		system("pause");
		system("cls");
		Room_A2();
	}
	else
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tТы стоял под гнётом стен ужасающего замка. Страшные звуки доносились из его глубин.        |" << endl << "\t|";
		cout << "В твоей голове, по кругу, мелькала одни лишь мысль - \"Опасность!\" Ты понимаешь, что               |" << endl << "\t|";
		cout << "оставаться тут нелья. И, приняв единственное верное решение, кидаешься на утек.                    |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\tОднако, не пробежав и 20 метров, спотыкаешься о корень и падаешь в грязь. Ты в ужасе        |" << endl << "\t|";
		cout << "поднимаешь лицо. Вязкая грязь залила глаза, ты видишь силуэт над собой, но не можешь разобрать,   |" << endl << "\t|";
		cout << "что видишь. Только странные чавкающие звуки доносятся до тебя...                                  |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "  Тупая боль пробила грудь, и слезы неволей вырвались на ружу, небеса разорвал оглушающий крик.   |" << endl << "\t|";
		cout << "Это кричишь ты - " << playerName << "...И это последние мгновения твоей жизни...                        " << endl << "\t|";
		cout << "\tОстрая кость, что служила монстру рукой, или была ей когда - то, пронзила тебя насквозь...  |" << endl;
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

	cout << "1) Новая Игра!\n" << "\t\t\t\t\t" << "2) Выход\n\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		main();
		break;
	case 2:
		break;
	default:
		cout << "Неверный выбор!" << endl;
		main();
	}



}
void GenerateItem() {
	string item[11]{ "Кек, здесь ничего нет :-(", "Яблоко","Зелье","Элексир","Свиток - <Фаербол>","Свиток - <Молния>","Свиток - <Ледяная стрела>","Серебряные дротики","Святая бомба", "Освященный сюрикен","Кек, здесь ничего нет :-(" };
	//Обрати внимание!
	int x = rand() % 11;
	if (z < 22)
	{
		sayItem = item[x];
		setItem[x]++;

	}
	else {
		cout << "Вы не можете унести больше вещей, увы. Вам пришлось бросить эту затею!";
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
		who = "Маг";
	}
	else {
		who = "Воин";
	}
	cout << "\n\tВаш уровень : " << lvl << ". Вы -\"" << who << "\". Ваше НР = " << playerHels << ". Вашe MP = " << playerMana << endl;
	cout << "\tВаш урон = " << skilsDamage[0] << " DMG." << " Ваши коардинаты = \"" << coordinatePlayer[savePosition] << "\"." << endl;
	cout << "\tУ вас в наличии : ";

	cout << "Колличество ключей : " << key << "." << endl << "\t";

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
	if (eqipInInterface != "") {
		if (indicationEqip % 3 == 0)
		{
			cout << endl;
		}
		cout << "Шмот: " << eqipInInterface << endl;

	}
	cout << endl << "Боевой опыт : " << expirience << "." << endl << "\n\t";

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
		skilsDamage[0] = 1;//костыль. Непонятно каким образом, но при выборе мага, скилдемейдж становится 0, а при выборе война =2. Хз почему так. Все просмотрел по 10 раз, ни чего не могу найти!
	}

}

void ChekDoobleFight() {

	if (mobId[savePosition] = false) {
		idlvl[savePosition] = false;
	}
}
void ChangeTargetFight(int mobHels_1, int mobDMG_1, int mobHels_2, int mobDMG_2) {

	int target, x;

	string variationOfAttack[7]{ "Наброситься на", "Истезать с жестокостью", "Раскритиковать", "Выбесить", "Соблазнить", "Накормить несвежей шавермой", "Гопануть" };


	cout << "\n\t " << playerName << " Выбирай цель!";
	cout << endl;
	x = rand() % 7;
	cout << "\n\t 1) " << variationOfAttack[x] << " - " << doobleName[0];
	x = rand() % 7;
	cout << "\n\t 2) " << variationOfAttack[x] << " - " << doobleName[1];
	cout << "\n\t 3) Попытаться сбежать... " << endl << "\t";
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
		cout << "\n\t Вы пытаетесь сбежать, но обе твари вам сперва отвешивают оплеух!";
		system("pause");
		Navigation(escapeJump);
		playerHels -= mobDMG_1 + mobDMG_2;
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
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\t|" << mobName << " грозный противник. Так как ты застал его в расплох, то ходи первым!\n";
	cout << "\t|                                                                                                  |" << endl;
	cout << "\t| Выбери действие :                                                                                |" << endl;
	cout << "\t| 1) " << skils[0] << endl;
	cout << "\t| 2) Использовать навыки.                                                                          |" << endl;
	cout << "\t| 3) Использовать инвернтарь.                                                                      |" << endl;
	cout << "\t| 4) Бежать.                                                                                       |" << endl;
	TextWindow();
	Interface();
	cout << "\n\t\tВведите свой выбор : ";
	cin >> choice;
	switch (choice)
	{
	case 1:

		cout << "\n\t\tВы используете " << "-" << "\"" << skils[0] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[0] << " урона!\n";
		mobHeals -= skilsDamage[0];

	chek:

		if (mobHeals > 0)
		{
			cout << endl << "\t" << mobName << " не умер, у него осталось - " << mobHeals << " НР. Но " << mobName << " разочарован вами! За это получите - " << mobDamage << " урона!\n";
			playerHels -= mobDamage;
			if (playerHels <= 0)
			{
				system("cls");
				int x;
				x = rand() % 4;


				cout << "\t\t\tМои глубочайшие соболезнования " << playerName << "...\n\t\t\tНо \"" << mobName << "\" " << deathWariation[x] << "!\n\n";

				Die();
			}
			system("pause");
			system("cls");
			goto rechoice;
		}
		else {
			int y = rand() % 6;
			cout << "\n\tПозравляем! " << mobName << " " << finishing[y] << endl;
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
		//Выберите навык : скил 1 скил 2 скил 3 скил 4
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
		cout << "\n\t Вы пытаетесь сбежать, но получаете пинок в догонку!";
		system("pause");
		playerHels -= mobDamage;
		idlvl[savePosition] = true;
		mobId[savePosition] = true;
		Navigation(escapeJump);
		
		///////////////////////
	default:
		break;
	}
}
void GiveMeAmo(int eqipDMG, int eqipName, int typeEqip) {
	int spec;
	string eqip;
	string saying[2]{ ". Это будет очень полезено в бою!",". Это будет, весьма бесполезным приобретением!" };
	if (typeEqip == 1) {
		eqip = ratEqip[eqipName];
	}
	else if (typeEqip == 2) {
		eqip = magEqip[eqipName];
	}
	if (speciolization) {
		skilsDamage[0] += eqipDamage[eqipDMG];
		if (typeEqip == 1) { spec = 1; }
		else { spec = 0; }
	}
	else {
		skilsDamage[0] += eqipDamage[eqipDMG];
		if (typeEqip == 1) { spec = 0; }
		else { spec = 1; }
	}
	cout << "\n\tЗдорово! Вы нашли : " << eqip << saying[spec] << endl << endl;
	TextWindow();
	cout << endl;
	eqipInInterface += " " + eqip;
	indicationEqip++;

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
		cout << "\n\tУ вас еще нет вещей! Вы получите шмотки как только вскорете сундук!" << endl;
		lose = false;
		system("pause");
		system("cls");
	}

	if (z > 0) {
		cout << "\n\tСделайте выбор : ";
		cin >> choice;
		if (newItem[choice - 1] == "Яблоко" || newItem[choice - 1] == "Зелье" || newItem[choice - 1] == "Элексир" || newItem[choice - 1] == "Самогон Деда")
		{
			if (newItem[choice - 1] == "Элексир")
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
		cout << "\n\tУ вас еще нет навыков! Вы получите навык как достигните 1 ровня, который дают за 10хр." << endl;
		lose = false;
		system("pause");
		system("cls");
	}
	else {
		cout << "\n\tСделайте выбор : ";
		cin >> choice;


		if (choice <= lvl && choice < 5)
		{

			switch (choice) {

			case 1:
				system("cls");
				cout << "\n\t\tВы используете " << "-" << "\"" << skils[1] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[1] << " урона!\n";
				deferredDamage = skilsDamage[1];
				playerMana -= 2;
				system("pause");

				break;
			case 2:
				system("cls");
				cout << "\n\t\tВы используете " << "-" << "\"" << skils[2] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[2] << " урона!\n";
				deferredDamage = skilsDamage[2];
				playerMana -= 4;
				system("pause");

				break;
			case 3:
				system("cls");
				cout << "\n\t\tВы используете " << "-" << "\"" << skils[3] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[3] << " урона!\n";
				deferredDamage = skilsDamage[3];
				playerMana -= 7;
				system("pause");

				break;
			case 4:
				system("cls");
				cout << "\n\t\tВы используете " << "-" << "\"" << skils[4] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[4] << " урона!\n";
				deferredDamage = skilsDamage[4];
				playerMana -= 10;
				system("pause");

				break;
			default:

				break;
			}
		}
		else {

			cout << "/n/tНе правильно набран номер! Попытйте счастье снова!";
			system("pause");
			system("cls");
			goto rechoice;

		}
	}
}
void Action(int roomType) {

	cout << endl;
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\tСделай выбор!!!                                                                            |" << endl << "\t|";
	cout << "\t1) Идти на Север.                                                                          |" << endl << "\t|";
	cout << "\t2) Идти на Запад.                                                                          |" << endl << "\t|";
	cout << "\t3) Идти на Восток.                                                                         |" << endl << "\t|";
	cout << "\t4) Отправится на юг.                                                                       |" << endl;
	switch (roomType)
	{

	case 0:
		TextWindow();
		break;
	case 1:
		cout << "\t|\t5) Открыть сундук!                                                                         |" << endl << "\t";
		cout << "|                                                                                                  |" << endl;
		TextWindow();

	default:
		break;
	}
}


//Комнаты!!!
void Chest() {

	system("cls");
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_|23456789_123|5678|__|"; - 'это разметка текста. Выровняй разметку по cout.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tОтлично " << playerName << ", отакрыть сундук отличная идея, надеюсь у тебя есть ключ?. " << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\tТы шаришь по карманам в поисках ключа...                                                   |" << endl << "\t|";
	if (key > 0) {
		GenerateItem();
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\tШикарно, вы нашли ключ!                                                                    |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "Теперь посмотрим чем Вам удалось поживиться. Тяжелая крышка старого сундука, со скрипом отворяется.|" << endl << "\t|";
		cout << "Вы не можите поверить своим глазам, вы нашли -\"" << sayItem << "\"" << endl << "\t| ";
		cout << "                                                                                                 |" << endl;
		TextWindow();
		key -= 1;
		chekCloseChest[savePosition] = false;

		system("pause");
		system("cls");
		Navigation(savePosition);

	}
	else {


		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_|23456789_123|5678|__|"; - 'это разметка текста. Выровняй разметку по cout.
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\tПошарив по карманам, Вы понимаете, что ключа у Вас так и нет!                              |" << endl << "\t|";
		cout << "\tВаши попытки тщетны и Вы остаётесь ни с чем!                                               |" << endl << "\t|";
		cout << "\tХорошо, хоть сундук не обратился монстром...                                               |" << endl << "\t|";
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
		return "Зато вы находите ключ! ";
	}
	else {

		return "Кто-то уже здесь все собрал...Кто бы это мог быть? ";
	}
}
void Room_Clear_Center() {


	cout << "\n\t\t Вы подходите к окну. За ним вид на дорогу, что ведет к замку.\n\tТуман стелется до самой земли, Ваши попытки, что - либо разглядеть дальше 5 метров провалились.\n\tВы тяжко вздыхаете, вспоминаете о нелёгком деле и возвращаетесь назад.\n";
	system("pause");
	system("cls");
	Navigation(savePosition);
}
void Room_Clear_Left() {

	cout << "\n\t\t Вы подходите к окну. За ним прекрасный вид на океан. Волны врезаются в прибрежные скалы,\n\t взрываются фонтаном. Даже досюда доносится океаническая свежесть.\n\tВы вдыхаете полную грудь свежего воздуха и возвращаетесь назад.\n";
	system("pause");
	system("cls");
	Navigation(savePosition);
}
void Room_Clear_Right() {


	cout << "\n\t\t Вы подходите к окну. За ним вид скалы у подножья которых, щетиной расположился лес.\n\tКривые деревья которого наводят лишь ужас, он словно кричит \"Беги\"! Это мёртвые земли.\n\tИ пока еще не мертвы, Вы спешите вернуться назад.\n";
	system("pause");
	system("cls");
	Navigation(savePosition);
}


void Room_A1() {

	savePosition = 1;
	mobName = "Приведение";
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
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату, ты натыкаешься на " << mobName << "! Очень жаль, " << playerName << "." << endl;
		cout << "\t|Тебе придется сражаться!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();


		Fight(2, 1);
		Interface();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВ комнате остался лишь трупак " << mobName << "\bя. " << endl << "\t|  " << GiveKey(idlvl[1]);
		cout << " " << playerName << " - ты везунчик!" << endl;
		cout << "\t|                                                                                                  |" << endl;
		cout << "\t|Пора убираться от сюда! Куда отправимся?                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		Interface();
		idlvl[1] = false;

		cout << "\t Сделайте выбор : ";
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
			cout << "Неверный выбор";
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
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\tВорвавшись в эту комнату ты наблюдаешь лишь сундук. Если есть ключ, попытай счастье!       |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();


	Action(1);
	Interface();

	cout << endl << endl << "\t\t\t\t\tСделайте выбор : ";
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
		cout << "\n\t\tЭй! " << playerName << ", пути назад уже нет. Только в перед!";
		system("pause");
		goto rechoice;
	case 5:
		if (chekCloseChest[2] == true) {
			Navigation(0);

		}
		else {
			system("cls");
			cout << "\n\n\t\t\t Э-э-э, как бы Вы уже открывали этот сундук. Выберите, что - нибудь другое!\n\n";
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
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                 |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату, ты находишь сочное, хрустящее, с наливным бочком - \"Яблоко\"!    |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t| Но, к сожалению, Вас одолели бесы... Яблоко пленило весь разум, Вы чувствуете, что    |" << endl;
		cout << "\t| больше не в состоянии контролировать себя! Ваши руки вас не слушаются, о боже! " << playerName << "!" << endl;
		cout << "\t| Вы с огромным наслаждением впиваетесь в яблоко, его сладкий и чуть кисловатый сок, взрывается   |" << endl;
		cout << "\t| радугой вкусов, Вы не можете больше сдерживаться. Эхом от стен комнаты раздается хруст.       |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t| Ваша несдержанность, " << playerName << ", в этот раз принесла пользу!" << endl;
		cout << "\t| Яблочко даровало Вам: +" << itemDamage[0] << " HP!" << endl;
		cout << "\t|                                                                                                 |" << endl;
		playerHels += itemDamage[0];
		idlvl[3] = false;
		TextWindow();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                 |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату, ты едва не подскальзываешься на огрызке!            |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t| Но, к счастью, с грацией кошки, Вы приземлились на все 4 лапы. Очевидно, что здесь          |" << endl;
		cout << "\t| кто-то раскидал яблочные огрызки. Интересно, кто?                                               |" << endl;
		cout << "\t|                                                                                                 |" << endl;
		cout << "\t| Мы обязательно отыщем нарушителя позже, а пока, надо решить куда отправиться дальше!              |" << endl;


		TextWindow();

	}

	Action(0);
	Interface();

	cout << endl << endl << "\t\t\t\t\tСделайте выбор : ";
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
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\tВорвавшись в эту комнату, ты наблюдаешь Целых два(!) Сундука. Если есть ключ, попытай счастье!       |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();


	Action(1);
	Interface();

	cout << endl << endl << "\t\t\t\t\tСделайте выбор : ";
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
				cout << "\n\n\t\t\t Э-э-э, как бы вы уже открывали этот сундук. Выберите, что - нибудь другое!\n\n";
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
	mobName = "Приведение";
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
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату, ты натыкаешься на " << mobName << "! Очень жаль, " << playerName << "." << endl;
		cout << "\t|Тебе придется сражаться!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();


		Fight(2, 1);
		Interface();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВ комнате остался лишь трупак " << mobName << "\bя. " << endl;
		cout << "|\t " << playerName << ", ты все еще надеешься, что - то получить в награду?! Пфф..." << endl;
		cout << "\t|                                                                                                  |" << endl;
		cout << "\t|Хватит стоять как истукан! Пора убираться отсюда! Куда отправимся?                               |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		Interface();
		idlvl[5] = false;

		cout << "\t Сделайте выбор : ";
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
			cout << "Неверный выбор";
			goto rechoice;
			break;

		}

	}
}
void Room_A6() {

	savePosition = 6;
	mobName = "Приведение";
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
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату ты натыкаешься на " << mobName << "! Очень жаль " << playerName << "." << endl;
		cout << "\t|Тебе придется сражаться!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();


		Fight(2, 1);
		Interface();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВ комнате остался лишь трупак " << mobName << "\bя. " << endl << "\t|  " << GiveKey(idlvl[6]);
		cout << " " << playerName << " - ты везунчик!" << endl;
		cout << "\t|                                                                                                  |" << endl;
		cout << "\t|Пора рвать когти! Куда ворвемся теперь?                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		Interface();
		idlvl[6] = false;

		cout << "\t Сделайте выбор : ";
		Action(0);
		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:

			Navigation(9);
			break;
		case 2:
			Navigation(5);
			break;
		case 3:
			Navigation(103);
			break;
		case 4:
			Navigation(3);
			break;


		default:
			cout << "Неверный выбор";
			//goto rechoice;
			break;

		}

	}

}
void Room_A7() {
	
	savePosition = 7;
	doobleName[0] = "Озорное Приведение";
	doobleName[1] = "Приведение Повар";

	if (mobId[7]) {
		mobName = doobleName[0];
	}
	else { mobName = doobleName[1]; }

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
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату ты натыкаешься на:\n\t " << doobleName[0] << " и его коварную подружку! - " << doobleName[1] << "! Очень жаль, " << playerName << "." << endl;
		cout << "\t|Надеюсь ты справишься! В любом случае, тебе лучше бы справиться...                                |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		cout << endl;
		cout << "\t Ладно-ладно, " << playerName << " в этот раз я тебе, так уж и быть помогу!" << endl;
		cout << "\t Для начала, " << playerName << " выбери цель, а затем тип атаки.\n";
		TextWindow();
		saveJump = escapeJump;
		ChangeTargetFight(2, 1, 2, 1);
		Interface();


	}
	
	else if (mobId[7] == false && idlvl[7] == true) {
		escapeJump = saveJump;
		idlvl[7] = false;
		system("cls");
		cout << "\n\t Здорово " << playerName << ", осталось добить второго!";
		system("pause");
		Fight(2, 1);
		

	}
	else if (mobId[7] == false && idlvl[7] == false) {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВ комнате остался лишь трупак " << doobleName[0] << " и " << doobleName[1] << endl << "\t|  " << GiveKey(idlvl[6]);
		cout << " " << playerName << " - ты везунчик!" << endl;
		cout << "\t|                                                                                                  |" << endl;
		cout << "\t|Пора рвать когти! Куда ворвемся теперь?                                                           |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		if (chekCloseChest[7]) {
			cout << "\n\t Постой " << playerName << " Ты незаметил красивый блестящий мечь, что весит на стене?\n\n\t";
			system("pause");
			GiveMeAmo(0, 0, 1);
			chekCloseChest[7] = false;
		}
		Interface();
		system("pause");
		system("cls");

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
		cout << "\t Сделайте выбор : ";
		Action(0);
		Interface();



		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:

			Navigation(10);
			break;
		case 2:
			Navigation(101);
			break;
		case 3:
			Navigation(8);
			break;
		case 4:
			Navigation(4);
			break;


		default:
			cout << "Неверный выбор";
			//goto rechoice;
			break;

		}
	}
}
void Room_A8() {
	savePosition = 8;
	mobName = "Приведение";
	mobExp = 1;
	giveMana = 1;
	system("cls");

	if (mobId[8])
	{
		
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
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//11
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//12
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },//13
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },//14
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },//15
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },//16
			{ '#',' ','#',' ','#',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ','#',' ','#',' ','#' },//17
			{ '#',' ','#','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ','#' },//18
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
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату ты натыкаешься на " << mobName << "! Очень жаль " << playerName << "." << endl;
		cout << "\t|Тебе придется сражаться!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		Interface();
		system("pause");
		system("cls");
		Fight(2, 1);
		



	}
	else {
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
		{ '#',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ','#','X','#','X','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*','O','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }

		};
		if (chekCloseChest[8] == false)
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
	cout << endl;
	TextWindow();
	cout << "\t|                                                                                                  |" << endl;
	cout << "\tВ комнате остался лишь трупак " << mobName << "\bя. " << endl;
	cout <<"\t|" << playerName << " - ты везунчик!" << endl;
	cout << "\t|                                                                                                  |" << endl;
	if (idlvl[8])
	{
	cout << "\t|Ты находишь Самогон Деда! А так же обнаруживаешь в комнате сундук!                                |" << endl;
	
	newItem[z] = "Самогон Деда";
	newItemDamage[z] = 10;
	z++;
	idlvl[8] = false;
	}
	else {
	cout << "\t|В углу пылиться старый сундук.                                                                    |" << endl;
	}
	
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();
	Action(1);
	Interface();
	
	cout << "\n\t\t Ну и куда отправимся теперь? : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		Navigation(11);
		break;
	case 2:
		Navigation(7);
		break;
	case 3:
		Navigation(9);
		break;
	case 4:
		Navigation(5);
		break;
	case 5:
		if (chekCloseChest[8] == true) {
			Navigation(0);

		}
		else {
			system("cls");
			cout << "\n\n\t\t\t Э-э-э, как бы Вы уже открывали этот сундук. Выберите, что - нибудь другое!\n\n";
			system("pause");

			Room_A9();
		}
		break;
	default:
		break;
	}
	
}
void Room_A9() {
	savePosition = 9;
	mobName = "Призрак";
	mobExp = 2;
	giveMana = 2;
	system("cls");

	if (mobId[9])
	{

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
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//11
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//12
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },//13
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },//14
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },//15
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },//16
			{ '#',' ','#',' ','#',' ',' ','*',' ',' ',' ','#','#','#',' ',' ',' ','*',' ','*','#',' ','#',' ','#' },//17
			{ '#',' ','#','#',' ',' ',' ',' ','#',' ','*',' ','#',' ','*',' ','#',' ',' ',' ',' ','#','#',' ','#' },//18
			{ '#',' ','#',' ',' ',' ',' ','#','#',' ','#','#','*','#','#',' ','#','#',' ',' ',' ',' ','#',' ','#' },//19
			{ '#','*',' ',' ',' ',' ',' ',' ','#',' ','*','#',' ','#','*',' ','#',' ',' ',' ',' ',' ',' ','*','#' },//20
			{ '#',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*','#','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','#' },//21
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//22
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','#' },//23
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','#' },//24
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#' },//25
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }//26
			// 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
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
		
		cout << endl;
		TextWindow();
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату ты натыкаешься на " << mobName << "! Очень жаль " << playerName << "." << endl;
		cout << "\t|Тебе придется сражаться!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		Interface();
		cout << endl;
		Fight(4, 2);




	}
	else {
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
		{ '#',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ','*',' ','#','X','#','X','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ','*',' ',' ','*','O','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ','*',' ','*','*','*',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }

		};
		if (chekCloseChest[9] == false)
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
	cout << endl;
	TextWindow();
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\tВ комнате остался лишь трупак " << mobName << "а. Так же, здесь пылиться старый сундук. " << endl; 
	cout << "\t| " << playerName << " - ты везунчик!" << endl;
	cout << "\t|                                                                                                  |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();
	Action(1);
	Interface();
	
	cout << "\n\t\t Ну и куда отправимся теперь? : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		Navigation(12);
		break;
	case 2:
		Navigation(8);
		break;
	case 3:
		Navigation(103);
		break;
	case 4:
		Navigation(6);
		break;
	case 5:
		if (chekCloseChest[9] == true) {
			Navigation(0);

		}
		else {
			system("cls");
			cout << "\n\n\t\t\t Э-э-э, как бы Вы уже открывали этот сундук. Выберите, что - нибудь другое!\n\n";
			system("pause");

			Room_A9();
		}
		break;

	default:
		break;
	}
}
void Room_A10() {
	savePosition = 10;

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
	if (chekCloseChest[10] == false)
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
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\tВорвавшись в эту комнату ты наблюдаешь лишь сундук. Если есть ключ, попытай счастье!       |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();


	Action(1);
	Interface();

	cout << endl << endl << "\t\t\t\t\tСделайте выбор : ";
	cin >> choice;
	switch (choice) {
	case 1:
		Navigation(13);
		break;
	case 2:
		Navigation(101);
		break;
	case 3:
		Navigation(11);
		break;
	case 4:
		Navigation(7);
		break;
	case 5:
		if (chekCloseChest[10] == true) {
			Navigation(0);

		}
		else {
			system("cls");
			cout << "\n\n\t\t\t Э-э-э, как бы Вы уже открывали этот сундук. Выберите, что - нибудь другое!\n\n";
			system("pause");

			goto rechoice;
		}
		break;
	default:
		break;
	}
}
void Room_A11() {

	savePosition = 11;
	mobName = "Призрак";
	mobExp = 2;
	giveMana = 2;


	system("cls");

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
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//11
			{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//12
			{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },//13
			{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },//14
			{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },//15
			{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },//16
			{ '#',' ','#',' ','#',' ',' ','*',' ',' ',' ','#','#','#',' ',' ',' ','*',' ','*','#',' ','#',' ','#' },//17
			{ '#',' ','#','#',' ',' ',' ',' ','#',' ','*',' ','#',' ','*',' ','#',' ',' ',' ',' ','#','#',' ','#' },//18
			{ '#',' ','#',' ',' ',' ',' ','#','#',' ','#','#','*','#','#',' ','#','#',' ',' ',' ',' ','#',' ','#' },//19
			{ '#','*',' ',' ',' ',' ',' ',' ','#',' ','*','#',' ','#','*',' ','#',' ',' ',' ',' ',' ',' ','*','#' },//20
			{ '#',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*','#','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','#' },//21
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//22
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','#' },//23
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','#' },//24
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#' },//25
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }//26
			// 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
	};
	if (!mobId[11]) {
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
	if (mobId[11])
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату ты натыкаешься на " << mobName << "! Очень жаль " << playerName << "." << endl;
		cout << "\t|Тебе придется сражаться!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();

		Fight(4, 2);
		Interface();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВ комнате остался лишь трупак " << mobName << "a. " << endl << "\t|  " << GiveKey(idlvl[11]);
		cout << " " << playerName << " - ты везунчик!" << endl;
		cout << "\t|                                                                                                  |" << endl;
		if (chekCloseChest[11]) {

			cout << "\t|И только ты собрался уходить, как сладкий, девичий голос позвал тебя по имени...                  |" << endl;
			cout << "\t| " << playerName << "... " << playerName << endl;
			cout << "\t|Вы оборачиваетесь, и с ужасом видете еще одного призрака! Или приведение! Или...В общем это!      |" << endl;
			TextWindow();
			Interface();
			system("pause");
			system("cls");

			char room[27][25]{

			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
			{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
			{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
			{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
			{ '#',' ','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/',' ','#' },
			{ '#',' ','|','\\',' ',' ',' ',' ',' ',' ','#','$','$','$','$',' ',' ',' ',' ',' ',' ','/','|',' ','#' },
			{ '#',' ','|',' ','\\',' ',' ',' ',' ','$','$','$','$','$','$','$','$',' ',' ',' ','/',' ','|',' ','#' },
			{ '#',' ','|',' ',' ','\\',' ',' ','$','$','$','$','#','$','$','$','$','$',' ','/',' ',' ','|',' ','#' },
			{ '#',' ','|',' ',' ','|',' ',' ','$','$','$','#','#','$','$','$','$','$',' ','|',' ',' ','|',' ','#' },
			{ '#',' ','|',' ',' ','|',' ','$','$','$','#','#','#','#','$','$','$','$','$','|',' ',' ','|',' ','#' },
			{ '#',' ','|',' ','*','|',' ','$','$','*','*','#','#','*','*','$','$','$','$','|','*',' ','|',' ','#' },
			{ '#',' ','|',' ',' ','|',' ','@','*','=','=','#','#','=','=','$','$','$','@','|',' ',' ','|',' ','#' },
			{ '#',' ','|',' ',' ','|','*','@','*','(',')','#','#','(',')','$','$','$','@','|',' ',' ','|',' ','#' },
			{ '#',' ','|',' ',' ','|',' ','@','*','*','#','#','#','#','#','$','$','$','@','\\',' ',' ','|',' ','#' },
			{ '#',' ','|',' ','/',' ',' ','$','*','*','*','#','#','#','#','$','$','$',' ',' ','\\',' ','|',' ','#' },
			{ '#',' ','|','/',' ',' ',' ','$','*','*','*',' ','#','#','#','$','$','$',' ',' ',' ','\\','|',' ','#' },
			{ '#',' ','/',' ',' ',' ',' ','$','*','*','#','#','#','#','#','$','$','$',' ',' ',' ',' ','|',' ','#' },
			{ '#','*',' ',' ',' ',' ',' ','$','&','*','#','V','V','#','#','$','$','$',' ',' ',' ',' ',' ','*','#' },
			{ '#',' ',' ',' ',' ',' ',' ','$','&','&','#','#','#','#',' ','$','$','$',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ','$','&',' ',' ','#','#',' ',' ','$','$','$',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ','$','&',' ','|',' ',' ','|',' ','$','$',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ','$',' ',' ','|',' ',' ','|',' ','$',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#',' ',' ',' ',' ',' ',' ',' ',' ','/','|',' ',' ','|','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
			{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
			};
		    
			chekCloseChest[11] = false;
		
			cout << endl << "\t\t\t\t\t";
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
			cout << "\t| - Постой путник, позволь помочь тебе в твоем не легком странствии...                             |" << endl;
			cout << "\t|                                                                                                  |" << endl;
			cout << "\t|1) Напасть на духа.                                                                               |" << endl;
			cout << "\t|2) Выслушать духа.                                                                                |" << endl;
			cout << "\t|3) Дать деру.                                                                                     |" << endl;
			TextWindow();
			cout << "\t Сделайте выбор : ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				system("cls");
				TextWindow();
				cout << "\t| Вы решаетесь атаковать духа, но первая же ваша атака проскальзывает сквозь эктоплазму чудища!    |" << endl;
				cout << "\t| Дух издает неистовый вой, глаза его воспылали алым пламенем, и вас тут же объял огонь...         |" << endl;
				TextWindow();
				system("pause");
				system("cls");
				Die();
				break;
			case 2:
				system("cls");
				TextWindow();
				cout << "\t| Я рада, что ты сделал правильный выбор," << playerName << "! Я лишь хочу помочь тебе в странствии." << endl;
				cout << "\t| Много столетий назад, я стала узником этого замка, и умираю от скуки. Давай поиграем?            |" << endl;
				cout << "\t| В награду я помогу тебе победить \"Босса\" этажа, и возможно поведую тайну... Но это не точно... |" << endl;
				cout << "\t|                                                                                                  |" << endl;
				cout << "\t| Согласен ли ты на такие условия?                                                                 |" << endl;
				TextWindow();
				cout << "\t1) Да.\t2)Да.";
				cin >> choice;
				system("cls");

				TextWindow();
				cout << "\t| И так первая загадка, ответом на которую является первая слабость босса.                         |" << endl;
				cout << "\t|                                                                                                  |" << endl;
				cout << "\t|\tОднажды нищий поспорил с бедным, что сможет убрать текст этой загадки.                     |" << endl;
				cout << "\t|И как видите, - выиграл спор. Конечно, нищий спросил:  - \"Как это у тебя получилось?\"             |" << endl;
				cout << "\t|На, что бездомный дал ответ: - \"Это особая, уличная <empty>!\". Так, что же это?                   |" << endl;
				cout << "\t|1) Выпивка.\t2) Крыса.\t3) Магия.\t4) Улица.                                           |" << endl;
				TextWindow();
				cout << "\tВведите номер ответа : ";
				cin >> choice;
				if (choice == 3)
				{
					system("cls");
					TextWindow();
					cout << "\t|\t И это правильный ответ. Действительно первая слабость боса - \"Магия\", а значит маг и его  |" << endl;
					cout << "\t| \"штуки\" наносят дополнительный урон.                                                             |" << endl;
					cout << "\t|                                                                                                  |" << endl;
					cout << "\t|\tИ так, следущая загадка!                                                                   |" << endl;
					cout << "\t| Как известно, слабое место духа - его душа. А где обитает здоровый дух?                          |" << endl;
					if (speciolization)
					{
						cout << "\t| По скольку ты маг, дам тебе подсказку. \"В здоровом <empty>, здоровый дух\".                     |" << endl;
					}
					cout << "\t|1) В пятке.t2) В живых.\t3) В дядьке.\t4) В теле.                                           |" << endl;
					TextWindow();
					cout << "\tВведите номер ответа : ";
					cin >> choice;
					if (choice == 4)
					{
						system("cls");
						TextWindow();
						cout << "\t|\t И это правильный ответ. Действительно слабость боса - \"Тело\", а значит попадая          |" << endl;
						cout << "\t| по \"телу\" вы наносите дополнительный урон.                                                       |" << endl;
						cout << "\t|                                                                                                  |" << endl;
						cout << "\t|\tТак как вы разгадали обе загадки, я дам вам, то что сберечь сумела от времени.             |" << endl;
						cout << "\t| Вы получили : \"Артефакт в виде черепа\"                                                           |" << endl;
						secretDevice[1] = true;
						eqipInInterface += " Череп";

						if (!speciolization)
						{
							cout << "\t| По скольку ты воин, вот тебе еще совет -  \"В сунудках бывает не только золото, но и монстры\".    |" << endl;
						}
						cout << "\t| Ну, а теперь отправляйся на встречу приключениям!                                                |" << endl;
						TextWindow();
						system("pause");
						Navigation(savePosition);
					}
					else {
						system("cls");
						TextWindow();
						cout << "\t| Вы ошиблись, у вас будет время подумать до схватки с босом. А пока увы...                        |" << endl;
						cout << "\t| Могу пожелать лишь удачи. Дух вернулась к своим насущным делам.                                  |" << endl;
						TextWindow();
						system("pause");
						Navigation(savePosition);
					}
				}
				else {
					system("cls");
					TextWindow();
					cout << "\t| Вы ошиблись, у вас будет время подумать до схватки с босом. А пока увы...                        |" << endl;
					cout << "\t| Могу пожелать лишь удачи. Дух вернулась к своим насущным делам.                                  |" << endl;
					TextWindow();
					system("pause");
					Navigation(savePosition);
				}


				break;
			case 3:
				system("cls");
				TextWindow();
				cout << "\t| Вы решились бежать, но ценой чего? Дух на вас обиделась...                                       |" << endl;
				cout << "\t| Могу пожелать лишь удачи. Дух вернулась к своим насущным делам.                                  |" << endl;
				TextWindow();
				system("pause");
				Navigation(escapeJump);
				break;
			}

			
		}else{

		TextWindow();
		cout << "\t| Дух устала, и не хочет больше с вами говорить...                                                 |" << endl;
		cout << "\t| Могу пожелать лишь удачи. Вы и Дух вернулись к своим насущным делам.                             |" << endl;
		TextWindow();
		idlvl[11] = false;
	
		cout << "\t Сделайте выбор : ";
		Action(0);
		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:

			Navigation(14);
			break;
		case 2:
			Navigation(10);
			break;
		case 3:
			Navigation(12);
			break;
		case 4:
			Navigation(8);
			break;


		default:
			cout << "Неверный выбор";
			//goto rechoice;
			break;

		}
		
    }
	}
}
void Room_A12() {
	savePosition = 12;
	mobName = "Приведение";
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
	if (!mobId[12]) {
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
	if (mobId[12])
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату ты натыкаешься на " << mobName << "! Очень жаль " << playerName << "." << endl;
		cout << "\t|Тебе придется сражаться!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();


		Fight(2, 1);
		Interface();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВ комнате остался лишь трупак " << mobName << "\bя. " << endl << "\t|  " << GiveKey(idlvl[12]);
		cout << " " << playerName << " - ты везунчик!" << endl;
		if (chekCloseChest[12]) {
		cout << "\t|Так-же, вам удалось урвать Грязный носок! Просто возьмите его с собой...                          |" << endl;
		z++;
		newItem[z] = "Грязный носок";
		newItemDamage[z] = 5;
		chekCloseChest[12] = false;
		}
		cout << "\t|                                                                                                  |" << endl;
		cout << "\t|Пора рвать когти! Куда ворвемся теперь?                                                           |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		Interface();
		idlvl[12] = false;

		cout << "\t Сделайте выбор : ";
		Action(0);
		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:

			Navigation(15);
			break;
		case 2:
			Navigation(11);
			break;
		case 3:
			Navigation(103);
			break;
		case 4:
			Navigation(9);
			break;


		default:
			cout << "Неверный выбор";
			//goto rechoice;
			break;

		}

	}

}
void Room_A13() {
	savePosition = 13;
	doobleName[0] = "Озорное Приведение";
	doobleName[1] = "Привередливый Призрак";

	if (mobId[7]) {
		mobName = doobleName[0];
	}
	else { mobName = doobleName[1]; }

	mobExp = 2;
	giveMana = 2;


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
		{ '#',' ','#',' ',' ','_','_',' ',' ',' ','#','#','#','#','#',' ','*','#','#','#','*',' ','#',' ','#' },//19
		{ '#','*',' ',' ','/','_','_','\\',' ',' ','#','#',' ','#','#',' ','#',' ','#',' ','#',' ',' ','*','#' },//20
		{ '#',' ',' ','|','\\',' ',' ','/','|',' ','#','#','#','#','#',' ','#','#','#','#','#',' ',' ',' ','#' },//21
		{ '#',' ',' ','|','_','\\','/','_','|',' ','*','#','#','#','*',' ','*','#',' ','#','*',' ',' ',' ','#' },//22
		{ '#',' ',' ','|',' ',' ',' ',' ','|',' ',' ','*','#','*',' ',' ',' ','*','#','*',' ',' ',' ',' ','#' },//23
		{ '#',' ',' ','|',' ',' ',' ',' ','|',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#' },//24
		{ '#',' ',' ','|','_','_','_','_','|',' ',' ',' ','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','#' },//25
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }//26
		// 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
	};
	if (!mobId[13]) {
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

	if (!idlvl[13])
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
	if (chekCloseChest[13] == false) {
		room[24][4] = 'E';
		room[24][5] = 'M';
		room[24][6] = 'P';
		room[24][7] = 'T';
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
	if (mobId[13])
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату ты натыкаешься на:\n\t " << doobleName[0] << " и его коварную подружку! - " << doobleName[1] << "! Очень жаль, " << playerName << "." << endl;
		cout << "\t|Надеюсь ты справишься! В любом случае, тебе лучше бы справиться...                                |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		cout << endl;
		cout << "\t Ладно-ладно, " << playerName << " в этот раз я тебе, так уж и быть помогу!" << endl;
		cout << "\t Для начала, " << playerName << " выбери цель, а затем тип атаки.\n";
		TextWindow();
		saveJump = escapeJump;
		ChangeTargetFight(2, 1, 4, 2);
		Interface();


	}

	else if (mobId[13] == false && idlvl[13] == true) {
		escapeJump = saveJump;
		idlvl[13] = false;
		system("cls");
		cout << "\n\t Здорово " << playerName << ", осталось добить второго!";
		system("pause");
		Fight(4, 2);


	}
	else if (mobId[7] == false && idlvl[7] == false) {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВ комнате остался лишь трупак " << doobleName[0] << " и " << doobleName[1] << endl << "\t|  " << GiveKey(idlvl[13]);
		cout << " " << playerName << " - ты везунчик!" << endl;
		cout << "\t|                                                                                                  |" << endl;
		cout << "\t|Пора рвать когти! Куда ворвемся теперь?                                                           |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		if (chekCloseChest[13]) {
			cout << "\n\t Постой " << playerName << " Ты забыл вскрыть сундук?\n\n\t";
			system("pause");
			if (key>0)
			{
			chekCloseChest[13] = false;
			Chest();
			
			}
			else {
			Chest();
			}
			
		}
		Interface();
		system("pause");
		system("cls");

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
		cout << "\t Сделайте выбор : ";
		Action(0);
		Interface();



		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:

			Navigation(100);
			break;
		case 2:
			Navigation(101);
			break;
		case 3:
			Navigation(14);
			break;
		case 4:
			Navigation(10);
			break;


		default:
			cout << "Неверный выбор";
			//goto rechoice;
			break;

		}
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
	cout << "Если ты попал сюда, то чо то не так.";
	system("pause");
	system("cls");
}


//закончились комнаты!!
