#include <iostream>

int main()
{
    std::cout << "<<house drawing>>" << std::endl;

    int N = 14;
    //int N = 13;
    //int N = 9;

// i == j
// i+j == N-1
// i = N / 2
// j = N / 2
// i>= j && i+j >= N-1

    std::cout << "enter size "; 
    //std::cin >> N;
    std::cout << std::endl;

    for (int i = 0; i < N; i++) //roof
    {
        for (int j = 0; j < N; j++)
        {
            if (N % 2)
            {
                if (i == 3 * N / 4 && j == N / 2 - 1) std::cout << "-----";
                else if (i == 3 * N / 4 && j == N / 2 + 1) std::cout << "-----";
                else if ((i == 3 * N / 4 - 1 || i == 3 * N / 4 + 1) && j == N / 2) std::cout << "  |  ";
                else if (i == 3 * N / 4 && j == N / 2) std::cout << "--|--";
                else if ((i >= N / 2 - 1 && i <= N / 2 + 2) && j == N / 2 + 2) std::cout << "|###|";
                else if (i >= j && i + j >= N - 1) std::cout << "|===|";
                else std::cout << "     ";
            }
            else
            {
				/*
                if (i == 3 * N / 4 && j == N / 2 - 2) std::cout << "-----";
                else if (i == 3 * N / 4 && j == N / 2 + 1) std::cout << "-----";
                else if ((i == 3 * N / 4 - 1 || i == 3 * N / 4 + 1) && (j == N / 2 || j == N / 2 - 1)) std::cout << "  |  ";
				else if (i == 3 * N / 4 && j == N / 2 - 1) std::cout << "--|--";
				else if (i == 3 * N / 4 && j == N / 2) std::cout << "--|--";
                else if ((i >= N / 2 - 1 && i <= N / 2 + 2) && j == N / 2 + 2) std::cout << "|###|";
                else if (i >= j && i + j >= N - 1) std::cout << "|===|";
                else std::cout << "     ";
				*/

                if (i == 3 * N / 4 - 1 && j == N / 2 + 1)std::cout << "___  "; //верхняя правая горизонтальная рама
                else if (i == 3 * N / 4 - 1 && j == N / 2 - 2) std::cout << "  ___"; //верхняя левая горизонтальная рама
                else if (i == 3 * N / 4 && j == N / 2 + 1)std::cout << "   \\ "; //правый верхний угол
                else if (i == 3 * N / 4 && j == N / 2 - 2)std::cout << " /   "; //левый верхний угол
                else if (i == 3 * N / 4 + 2 && j == N / 2 - 2)std::cout << " \\___"; //левый нижний угол окна
                else if (i == 3 * N / 4 + 2 && j == N / 2 + 1)std::cout << "___/ "; //правый нижний угол окна
                else if (i == 3 * N / 4 - 1 && (j == N / 2 || j == N / 2 - 1))std::cout << "__ __"; //верхние центральные горизонтальные рамы
                else if (i == 3 * N / 4 + 2 && (j == N / 2 || j == N / 2 - 1))std::cout << "__|__"; //нижние центральные вертикальные рамы
                else if (i == 3 * N / 4 && (j == N / 2 || j == N / 2 - 1))std::cout << "  |  "; //верхние центральные вертикальные рамы
                else if (i == 3 * N / 4 + 1 && j == N / 2 + 1)std::cout << "---- "; //правая центральная горизонтальная рама
                else if (i == 3 * N / 4 + 1 && j == N / 2 - 2)std::cout << " ----"; //левая центральная горизонтальная рама
                else if (i == 3 * N / 4 + 1 && (j == N / 2 || j == N / 2 - 1))std::cout << "--|--"; //перекрестие окна
                else if (((i <= N / 2 + 2) && (i >= N / 2 - 1)) && (j == N / 2 + 2))std::cout << "|###|"; //труба из кирпичей
                else if ((i >= j) && (i + j >= N - 1))std::cout << "|===|"; //черепица в крыше
                else std::cout << "     "; //небо
            }
            
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N; i++) // main construction
    {
        for (int j = 0; j < N; j++)
        {
            if (j == 1 && i >= 2) // left door
            {
                if (i == 2) std::cout << "_____";
                else if (i == N - 1) std::cout << "|____";
                else if (i == N / 2 + 1) std::cout << "| -- ";
                else std::cout << "|    ";
            }
            else if (j == 2 && i >= 2) // right door
            {
                if (i == 2) std::cout << "_____";
                else if (i == N - 1) std::cout << "____|";
                else std::cout << "    |";
            }
            else if (((i >= N/2-2) && (i <= N/2+2)) && ((j <= N - 2) && (j >= N - 5))) //window
            {
                if ((j == N - 5) && (i >= N / 2 - 1 && i <= N / 2 + 1)) std::cout << "|    ";
                else if ((j == N - 2) && (i >= N / 2 - 1 && i <= N / 2 + 1)) std::cout << "    |";
                else if ((j == N - 4 || j == N - 3) && (i >= N / 2 - 1 && i <= N / 2 + 1)) std::cout << "  |  ";
                else if ((j <= N - 2 && j >= N - 7) && (i == N / 2 - 2) || (i == N / 2 + 2)) std::cout << "-----";
                else std::cout << "     ";
            }
            else
            {
                std::cout << "[###]";
            }
        }
        std::cout << std::endl;
    }

}

/*
// Home
#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout<<"---Программа построения домика!---"<<endl;
	int N = 0; //размер поля (ширина домика)
	cout << "Введите ширину домика не меньше 9: "; cin >> N;
	//можно добавить проверку ввода размера
	//крыша
	for (int i = 0; i < N; i++) //цикл по строкам
	{
		for (int j = 0; j < N; j++) //цикл по столбцам
		{
			if (N % 2 == 0) //если ширина дома четная
			{
				if((i==3*N/4-1||i==3*N/4+1)&&j==N/2)cout<<"  |   "; //центральные вертикальные рамы
				else
				if(i==3*N/4&&j==N/2+1)cout<<" - -  "; //правая центральная горизонтальная рама
				else
				if(i==3*N/4&&j==N/2-1)cout<<" - - -"; //левая центральная горизонтальная рама
				else
				if(i==3*N/4&&j==N/2)cout<<" -|- -"; //перекрестие окна
				else
				if((i>=N/2-1&&i<=N/2+2)&&j==N/2+2)cout<<"|###| "; //труба из кирпичей
				else
				if(i>=j&&i+j>=N-1)cout<<"|===| "; //черепица в крыше
				else cout << "      "; //небо
			}
			else //если ширина дома нечетная
			{
				if((i==3*N/4-1||i==3*N/4+1)&&j==N/2)cout<<"  |   "; //центральные вертикальные рамы
				else
				if(i==3*N/4&&j==N/2+1)cout<<" - -  "; //правая центральная горизонтальная рама
				else
				if(i==3*N/4&&j==N/2-1)cout<<" - - -"; //левая центральная горизонтальная рама
				else
				if(i==3*N/4&&j==N/2)cout<<" -|- -"; //перекрестие окна
				else
				if((i>=N/2-1&&i<=N/2+2)&&j==N/2+2)cout<<"|###| "; //труба из кирпичей
				else
				if(i>=j&&i+j>=N-1)cout<<"|===| "; //черепица в крыше
				else cout << "      "; //небо
			}
		}
		cout << endl;
	}
	//стены
	for (int i = 0; i < N; i++) //цикл по строкам
	{
		for (int j = 0; j < N; j++) //цикл по столбцам
		{
			if (i==N-1&&j==2)cout << " _ _| "; //правая нижняя граница двери
			else
			if(i==N-1&&j==1)cout<<"|_ _ _"; //левая нижняя граница двери
			else
			if(i==2&&(j==1||j==2))cout<<"_ _ _ "; //верх двери
			else
			if(i>2&&j==2)cout<<"    | "; //правая сторона двери
			else
			if(i==N/2+1&&j==1)cout<<"| O   "; //ручка, на 1 строку ниже середины стены
			else
			if(i>2&&j==1)cout<<"|     "; //левая сторона двери
			else
			if((i==N/2-2||i==N/2+2)&&(j>=N-5&&j<=N-2))cout<<"- - - "; //верхняя и нижняя рамы окна
			else
			if((i>=N/2-1&&i<=N/2+1)&&j==N-5)cout<<"|     "; //левая рама окна
			else
			if((i>=N/2-1&&i<=N/2+1)&&j==N-2)cout<<"    | "; //правая рама окна
			else
			if((i>=N/2-1&&i<=N/2+1)&&(j==N-4||j==N-3))cout<<"  |   "; //вертикальные центральные рамы окна
			else cout << "|###| "; //кирпичи в стене
		}
		cout << endl;
	}
}

*/