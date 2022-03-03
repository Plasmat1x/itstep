#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void dices(int& p)
{
    p = rand() % 6 + 1;

    switch (p)
    {
    case 1:
        std::cout << R"(
 - - -  
|     |
|  *  |
|     |
 - - - 
)";
        break;
    case 2:
        std::cout << R"(
 - - -  
|    *|
|     |
|*    |
 - - - 
)";
        break;
    case 3:
        std::cout << R"(
 - - -  
|    *|
|  *  |
|*    |
 - - - 
)";
        break;
    case 4:
        std::cout << R"(
 - - -  
|*   *|
|     |
|*   *|
 - - - 
)";
        break;
    case 5:
        std::cout << R"(
 - - -  
|*   *|
|  *  |
|*   *|
 - - - 
)";
        break;
    case 6:
        std::cout << R"(
 - - -  
|*   *|
|*   *|
|*   *|
 - - - 
)";
        break;
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    std::cout << "<--Dice-->" << std::endl;

    bool is_game = false;

    int player = 0;
    int ai = 0;
    int cash = 0;
    int bet = 0;
    int bet = 0;

    while (true)
    {
        std::cin >> cash;

        if (cash <= 0)
        {
            std::cout << "Wrong number" << std::endl;
            continue;
        }

        is_game = true;

        break;
    }

    while (is_game)
    {
        system("cls");
        std::cout << "<--Dice->Game-->" << std::endl;
        std::cout << "Cash = " << cash << std::endl;

        do
        {
            std::cout << "Make bet ";
            std::cin >> bet;
            if (bet < 0) std::cout << "wrong" << std::endl;
            else if (bet > cash) std::cout << "to much when you have" << std::endl;
            else if (bet == 0) is_game = false;
            else std::cout << "Bet  accepted" << std::endl;
        } while (bet < 0 || bet > cash);

        dices(player);
        dices(ai);
        
        if (ai == player)
        {
            std::cout << "draw" << std::endl;
        }
        else if (player > ai)
        {
            std::cout << "player win" << std::endl;
            cash += bet * 2;
        }
        else //player < ai
        {
            std::cout << "player lose" << std::endl;
            cash -= bet;
            if (cash == 0)
            {
                std::cout << "you have not enough for next game " << std::endl;
                is_game = false;
            }
        }

        system("pause");
    }
    Sleep(1500);
}

/*
// Dice3.0
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	//заголовок программы
	cout << "---Корсары. Игра в кости!---" << endl;
	//объявление переменных
	int cash = 0, bet = 0, strike_pc = 0, strike_player = 0,strike = 0;
	do //цикл проверки ввода наличности
	{
		cout << "Выворачивай карманы! "; cin >> cash;
		if (cash <= 0)cout << "Кошелек прохудился?" << endl;
	} while (cash <= 0);
	do //цикл повторной игры
	{
		//возврат начальных значений перед началом новой игры
		//обязательно
		strike_pc = 0;
		strike_player = 0;
		//необязательно
		bet = 0;
		strike = 0;
		system("cls"); //очистка экрана перед игрой
		cout << "---Деньги на бочку!---" << endl;
		cout << "У тебя в карманах: " << cash << " писатров!" << endl;
		do //цикл проверки ставки
		{
			cout << "Сколько ставишь? "; cin >> bet;
			if (bet < 0)cout << "Денег нет? Корабль ставишь?" << endl;
			if (bet > cash)cout << "А денег-то хватает?" << endl;
		} while (bet<0 || bet>cash);
		if (bet == 0) //условие выхода из игры
		{
			cout << "Ну ты и слабак! Прощай!" << endl;
			break; //выход из цикла повторной игры
		}
		else //если можно играть(ставка корректная)
		{
			for(int i=1;i<=2;i++) //цикл из двух бросков i==1 - бросок компьютера(Пирата) i==2 - бросок игрока(Корсара)
			{
				strike=rand()%6+1; //делаем бросок самого кубика
				if(i==1) //если бросок компьютера(Пирата)
				{
					strike_pc = strike; //присвоить значение на кубике броску компьютера(Пирата)
					cout << "У Пирата выпало: ";
				}
				else //иначе бросок игрока(Корсара)
				{
					strike_player = strike; //присвоить значение на кубике броску игрока(Корсара)
					cout<<"\nУ Корсара выпало: ";
				}
				//неважно чей сейчас бросок, кубик "рисуется" одинаково
				switch (strike)
				{
				case 1:
					cout << R"(
 _ _ _
|     |
|  *  |
|_ _ _|
)";
					break;
				case 2:
					cout << R"(
 _ _ _
|   * |
|     |
|_*_ _|
)";
					break;
				case 3:
					cout << R"(
 _ _ _
|   * |
|  *  |
|_*_ _|
)";
					break;
				case 4:
					cout << R"(
 _ _ _
| * * |
|     |
|_*_*_|
)";
					break;
				case 5:
					cout << R"(
 _ _ _
| * * |
|  *  |
|_*_*_|
)";
					break;
				case 6:
					cout << R"(
 _ _ _
| * * |
| * * |
|_*_*_|
)";
					break;
				}
				if (strike_pc == strike_player) //если после бросков Пирата и Корсара ничья
				{
					cout<<"\nНичья! Нужно перебросить!\n"<<endl;
					//обнуляем броски игрока и компьютера
					strike_pc = 0;
					strike_player = 0;
					i = 0; //устанавливаем значение счетчика перед броском компьютера
				}
			}
			//броски закончены и есть победитель
			if (strike_pc > strike_player) //условие победы компьютера
			{
				cout << "\nТебе не везет!" << endl;
				cash -= bet; //отнимаем ставку от общей суммы
				cout << "У тебя осталось: " << cash << " пиастров!" << endl;
				if (cash == 0)
				{
					cout << "Мы кредитов не выдаем! Прощай!";
					break;  //выход из цикла повторной игры
				}
			}
			else //иначе победа игрока
			{
				cout << "\nАгрх! Тебе везет!" << endl;
				cash += bet;
				cout << "У тебя теперь: " << cash << " пиастров!" << endl;
			}
		}
		system("pause"); //запрос нажатитя клавиши для продолжения игры
		//Sleep(3000);
	} while (cash > 0);
	Sleep(1500); //задержка в 1500 миллисекунд
}
*/