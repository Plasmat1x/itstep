#include <iostream>
#include <cstdlib>
#include <Windows.h>

int snowflakemain();
int housemain();
int powtable();

int main()
{
    //system("cls");
    //snowflakemain();
    //system("pause");
    //system("cls");
    housemain();
    //system("pause");
    //system("cls");
    //powtable();
    //system("pause");

    return 0;
}

int housemain()
{
    std::cout << "<<house drawing>>" << std::endl;

    int N = 14;
    int aN = 10;
    //int N = 13;
    //int N = 9;

// i == j
// i+j == N-1
// i = N / 2
// j = N / 2
// i>= j && i+j >= N-1

    std::cout << "enter size ";
    std::cin >> N;
    std::cout << std::endl;

    for (int i = 0; i < N; i++) //roof
    {
        for (int j = 0; j < N; j++)
        {
            if ((i >= 1 && j >= 1) && (j >= 0 && j <= N - 5))
            {
                if ((i >= 2 && i <= 4)) std::cout << "~0~~~";
    
            }

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

                if (i == 3 * N / 4 - 1 && j == N / 2 + 1)std::cout << "___  "; //?????????????? ???????????? ???????????????????????????? ????????
                else if (i == 3 * N / 4 - 1 && j == N / 2 - 2) std::cout << "  ___"; //?????????????? ?????????? ???????????????????????????? ????????
                else if (i == 3 * N / 4 && j == N / 2 + 1)std::cout << "   \\ "; //???????????? ?????????????? ????????
                else if (i == 3 * N / 4 && j == N / 2 - 2)std::cout << " /   "; //?????????? ?????????????? ????????
                else if (i == 3 * N / 4 + 2 && j == N / 2 - 2)std::cout << " \\___"; //?????????? ???????????? ???????? ????????
                else if (i == 3 * N / 4 + 2 && j == N / 2 + 1)std::cout << "___/ "; //???????????? ???????????? ???????? ????????
                else if (i == 3 * N / 4 - 1 && (j == N / 2 || j == N / 2 - 1))std::cout << "__ __"; //?????????????? ?????????????????????? ???????????????????????????? ????????
                else if (i == 3 * N / 4 + 2 && (j == N / 2 || j == N / 2 - 1))std::cout << "__|__"; //???????????? ?????????????????????? ???????????????????????? ????????
                else if (i == 3 * N / 4 && (j == N / 2 || j == N / 2 - 1))std::cout << "  |  "; //?????????????? ?????????????????????? ???????????????????????? ????????
                else if (i == 3 * N / 4 + 1 && j == N / 2 + 1)std::cout << "---- "; //???????????? ?????????????????????? ???????????????????????????? ????????
                else if (i == 3 * N / 4 + 1 && j == N / 2 - 2)std::cout << " ----"; //?????????? ?????????????????????? ???????????????????????????? ????????
                else if (i == 3 * N / 4 + 1 && (j == N / 2 || j == N / 2 - 1))std::cout << "--|--"; //?????????????????????? ????????
                else if (((i <= N / 2 + 2) && (i >= N / 2 - 1)) && (j == N / 2 + 2))std::cout << "|###|"; //?????????? ???? ????????????????
                else if ((i >= j) && (i + j >= N - 1))std::cout << "|===|"; //???????????????? ?? ??????????
                else std::cout << "     "; //????????
            }

        }
        std::cout << std::endl;
    }
    /*
    for (int i = 0; i < N ; i++) // main construction
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
            else if (((i >= N / 2 - 2) && (i <= N / 2 + 2)) && ((j <= N - 2) && (j >= N - 5))) //window
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
    */

    for (int i = 0; i < N; i++) // main construction
    {
        for (int j = 0; j < N + aN; j++)
        {
            if (j == 1 && i >= 2) // left door
            {
                if (i == 2) std::cout << "_____";
                else if (i == N - 1) std::cout << "|____";
                else if (i == N / 2 + 1) std::cout << "| -- ";
                else if (i < N) std::cout << "|    ";
                else std::cout << "     ";
            }
            else if (j == 2 && i >= 2) // right door
            {
                if (i == 2) std::cout << "_____";
                else if (i == N - 1) std::cout << "____|";
                else if (i < N) std::cout << "    |";
                else std::cout << "     ";
            }
            else if (((i >= N / 2 - 2) && (i <= N / 2 + 2)) && ((j <= N - 2) && (j >= N - 5))) //window
            {
                if ((j == N - aN) && (i >= N / 2 - 1 && i <= N / 2 + 1)) std::cout << "|    ";
                else if ((j == N - 2) && (i >= N / 2 - 1 && i <= N / 2 + 1)) std::cout << "    |";
                else if ((j == N - 4 || j == N - 3) && (i >= N / 2 - 1 && i <= N / 2 + 1)) std::cout << "  |  ";
                else if ((j <= N - 2 && j >= N - 7) && (i == N / 2 - 2) || (i == N / 2 + 2)) std::cout << "-----";
                else std::cout << "     ";
            }
            else if (i < N && j < N) std::cout << "[###]";
            else if (j >= N && j <= N + 5)
            {      
                /*
                if (i == N - 6) std::cout      << "     " << "     " << "wwwww" << "     " << "     ";
                else if (i == N - 5) std::cout << "     " << "wwwww" << "wwwww" << "wwwww" << "     ";
                else if (i == N - 4) std::cout << "     " << "wwwww" << "wwwww" << "wwwww" << "     ";
                else if (i == N - 3) std::cout << "wwwww" << "wwwww" << "wwwww" << "wwwww" << "wwwww";
                else if (i == N - 2) std::cout << "wwwww" << "wwwww" << "wwwww" << "wwwww" << "wwwww";
                else if (i == N - 1) std::cout << "wwwww" << "wwwww" << "wwwww" << "wwwww" << "wwwww";
                else if (i == N)     std::cout << "     " << "wwwww" << "wwwww" << "wwwww" << "     ";
                else std::cout << "     ";
                */
                if (i == N - 8 && j == N + 3) std::cout << "w";
                else if ((i >= N - 7 && i <= N - 1) && (j >= N + 2 && j <= N + 4)) std::cout << "w";
                else if ((i >= N - 4 && i <= N - 2) && j == N+1) std::cout << "w";
                else if ((i >= N - 4 && i <= N - 2) && j == N + 5) std::cout << "w";
                else std::cout << " ";
            }
            else std::cout << "     ";
        }
        std::cout << std::endl;
    }

    return 0;
}

int snowflakemain()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "<-- Art -->" << std::endl;

    int N = 0;
    bool var = false; //???????????????????? ?????? ???????????????? ??????????
    char s;

    std::cout << "Enter size > ";
    std::cin >> N;
    std::cout << "Enter sym > ";
    std::cin >> s;

    if (var) // ?? ??????????????????
    {
        for (int i = 0; i < N; i++) // line
        {
            for (int j = 0; j < N; j++) // column
            {
                // i == j
                // i+j == N-1
                // i = N / 2
                // j = N / 2

                if (N % 2)
                {
                    if ((i == j) ||
                        (i + j == N - 1) ||
                        (i == N / 2) ||
                        (j == N / 2))
                    {
                        std::cout << s<<" ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }

                }
                else
                {
                    if ((i == j) ||
                        (i + j == N - 2) ||
                        (i == N / 2 - 1) ||
                        (j == N / 2 - 1))
                    {
                        std::cout << s << " ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                }

            }
            std::cout << std::endl;
        }
    }
    else // ?? ??????????????????????
    {
        for (int i = 0; i < N; i++) // line
        {
            for (int j = 0; j < N; j++) // column
            {
                // i == j
                // i+j == N-1
                // i = N / 2
                // j = N / 2

                if (N % 2)
                {
                    if ((i == j) ||
                        (i + j == N - 1) ||
                        (i == N / 2) ||
                        (j == N / 2))
                    {
                        std::cout << s<<" ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }

                }
                else
                {
                    if ((i == j) ||
                        (i + j == N - 1) ||
                        (i == N / 2) ||
                        (i == N / 2 - 1) ||
                        (j == N / 2) ||
                        (j == N / 2 - 1))
                    {
                        std::cout << s<< " ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                }

            }
            std::cout << std::endl;
        }
    }

    return 0;
}

int powtable()
{
    std::cout << "<<pow table>>" << std::endl;

    for (int i = 2; i < 7; i++)
    {

        for (int j = 1; j < 9; j++)
        {
            std::cout << std::pow(i, j) << "\t\t";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
// Home
#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    cout<<"---?????????????????? ???????????????????? ????????????!---"<<endl;
    int N = 0; //???????????? ???????? (???????????? ????????????)
    cout << "?????????????? ???????????? ???????????? ???? ???????????? 9: "; cin >> N;
    //?????????? ???????????????? ???????????????? ?????????? ??????????????
    //??????????
    for (int i = 0; i < N; i++) //???????? ???? ??????????????
    {
        for (int j = 0; j < N; j++) //???????? ???? ????????????????
        {
            if (N % 2 == 0) //???????? ???????????? ???????? ????????????
            {
                if((i==3*N/4-1||i==3*N/4+1)&&j==N/2)cout<<"  |   "; //?????????????????????? ???????????????????????? ????????
                else
                if(i==3*N/4&&j==N/2+1)cout<<" - -  "; //???????????? ?????????????????????? ???????????????????????????? ????????
                else
                if(i==3*N/4&&j==N/2-1)cout<<" - - -"; //?????????? ?????????????????????? ???????????????????????????? ????????
                else
                if(i==3*N/4&&j==N/2)cout<<" -|- -"; //?????????????????????? ????????
                else
                if((i>=N/2-1&&i<=N/2+2)&&j==N/2+2)cout<<"|###| "; //?????????? ???? ????????????????
                else
                if(i>=j&&i+j>=N-1)cout<<"|===| "; //???????????????? ?? ??????????
                else cout << "      "; //????????
            }
            else //???????? ???????????? ???????? ????????????????
            {
                if((i==3*N/4-1||i==3*N/4+1)&&j==N/2)cout<<"  |   "; //?????????????????????? ???????????????????????? ????????
                else
                if(i==3*N/4&&j==N/2+1)cout<<" - -  "; //???????????? ?????????????????????? ???????????????????????????? ????????
                else
                if(i==3*N/4&&j==N/2-1)cout<<" - - -"; //?????????? ?????????????????????? ???????????????????????????? ????????
                else
                if(i==3*N/4&&j==N/2)cout<<" -|- -"; //?????????????????????? ????????
                else
                if((i>=N/2-1&&i<=N/2+2)&&j==N/2+2)cout<<"|###| "; //?????????? ???? ????????????????
                else
                if(i>=j&&i+j>=N-1)cout<<"|===| "; //???????????????? ?? ??????????
                else cout << "      "; //????????
            }
        }
        cout << endl;
    }
    //??????????
    for (int i = 0; i < N; i++) //???????? ???? ??????????????
    {
        for (int j = 0; j < N; j++) //???????? ???? ????????????????
        {
            if (i==N-1&&j==2)cout << " _ _| "; //???????????? ???????????? ?????????????? ??????????
            else
            if(i==N-1&&j==1)cout<<"|_ _ _"; //?????????? ???????????? ?????????????? ??????????
            else
            if(i==2&&(j==1||j==2))cout<<"_ _ _ "; //???????? ??????????
            else
            if(i>2&&j==2)cout<<"    | "; //???????????? ?????????????? ??????????
            else
            if(i==N/2+1&&j==1)cout<<"| O   "; //??????????, ???? 1 ???????????? ???????? ???????????????? ??????????
            else
            if(i>2&&j==1)cout<<"|     "; //?????????? ?????????????? ??????????
            else
            if((i==N/2-2||i==N/2+2)&&(j>=N-5&&j<=N-2))cout<<"- - - "; //?????????????? ?? ???????????? ???????? ????????
            else
            if((i>=N/2-1&&i<=N/2+1)&&j==N-5)cout<<"|     "; //?????????? ???????? ????????
            else
            if((i>=N/2-1&&i<=N/2+1)&&j==N-2)cout<<"    | "; //???????????? ???????? ????????
            else
            if((i>=N/2-1&&i<=N/2+1)&&(j==N-4||j==N-3))cout<<"  |   "; //???????????????????????? ?????????????????????? ???????? ????????
            else cout << "|###| "; //?????????????? ?? ??????????
        }
        cout << endl;
    }
}

*/