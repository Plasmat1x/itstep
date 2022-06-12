#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main()
{
    system("chcp 1251");
    system("cls");

    bool capital = false;
    bool digit = false;
    bool symbol = false;
    bool trash = true;
    bool space = false;

    char* passwd = nullptr;
    char* _BUFFER = new char[255]{};

    do
    {
        capital = false;
        digit = false;
        symbol = false;
        trash = false;
        space = false;

        system("cls");
        
        //TODO msg for password
        std::cout << "Enter passwd: ";

        gets_s(_BUFFER, 255);

        if (strlen(_BUFFER) < 8)
        {
            //TODO msg
            break;
        }

        for (int i = 0; i < strlen(_BUFFER); i++)
        {
            if (_BUFFER[i] < 32 || _BUFFER[i] > 126)
            {
                //TODO delete
                trash = true;
                break;
            }
            if (_BUFFER[i] == 32)
            {
                //TODO msg
                space = true;
                break;
            }
            if (isupper(_BUFFER[i]))
            {
                capital = true;
            }
            if (isdigit(_BUFFER[i]))
            {
                digit = true;
            }
            if (!isalnum(_BUFFER[i]))
            {
                symbol = true;
            }
        }
        if (trash || space)
        {
            //TODO msg
            continue;
        }
        else if (capital && digit && symbol)
        {
            //TODO msg
            passwd = new char[strlen(_BUFFER) + 1]{};
            strcpy_s(passwd, strlen(_BUFFER) + 1, _BUFFER);
            do {
                gets_s(_BUFFER, 255);

                if (strcmp(passwd, _BUFFER) != 0)
                {
                    //TODO msg
                }

            } while (strcmp(passwd, _BUFFER));
            
            delete[] _BUFFER;
        }
        else
        {
            //TODO msgs wrong steps passwdd
        }

    } while (true);

  

    std::cout << "passwd " << passwd << std::endl;

    delete[] passwd;

    return 0;
}

/*

// Password
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //библиотека для работы с символами
#include <stdio.h>

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
    char* Buffer = new char[255]{}; //буфер для ввода и анализа строки
    char* Password = nullptr; //указатель на строку для хранения итогового пароля
    bool Upper = false, Lower = false, Digit = false, Symbol = false, Trash = false, Space = false;
    //флаги букв верхнего и нижнего регистра, цифр, спец. символов, ненужных символов, пробела
    do
    {
        //сбрасываем флаги перед поторным вводом
        Upper = false; Lower = false; Digit = false; Symbol = false; Trash = false; Space = false;
        system("cls");
        cout << R"(Введите пароль, он должен содержать:
1. Не менее 8 символов
2. Буквы верхнего регистра латинского алфавита
3. Буквы нижнего регистра латинского алфавита
4. Цифры
5. Спец. символы
6. Пробелы и буквы нелатинского алфавита нельзя использовать!
)";
        gets_s(Buffer, 255); //для строки как указатель, нужно указывать размер
        if (strlen(Buffer) < 8)
        {
            cout << "Слишком короткий пароль!" << endl;
            system("pause");
        }
        else
        {
            //цикл анализа каждого символа в строке
            for (int i = 0; i < strlen(Buffer); i++)
            {
                if (Buffer[i] < 32 || Buffer[i]>126) //исключение неподходящих символов
                {
                    cout << "Некорректные символы!" << endl;
                    Trash = true;
                    break;
                }
                if (isspace(Buffer[i])) //if(Buffer[i]==32)
                {
                    cout << "Пробелы нельзя использовать!" << endl;
                    Space = true;
                    break;
                }
                //isalpha(); //проверка буква ли
                //если буква верхнего регистра
                if(isupper(Buffer[i])) Upper=true; //if(Buffer[i]>=65&&Buffer[i]<=90)
                //если буква нижнего регистра
                if (islower(Buffer[i])) Lower = true;
                //если цифра
                if (isdigit(Buffer[i])) Digit= true;
                //если спец символ
                if (!isalnum(Buffer[i]))Symbol = true; //isalnum(Buffer[i])вернет 0 если не буква и не цифра
            }
            if (Trash || Space) //если выход из цикла по break
            {
                cout << "Повторите ввод!" << endl;
                system("pause");
            }
            else
                if (Upper && Lower && Digit && Symbol)
                {
                    cout<<"Ваш пароль надежный! Для подтверждения введите его повторно: "<<endl;
                    Password = new char[strlen(Buffer) + 1]{};
                    strcpy_s(Password, strlen(Buffer) + 1, Buffer);
                    //I вариант заново ввод первого пароля при ошибке
                    gets_s(Buffer, 255);
                    if (strcmp(Password, Buffer))
                    {
                        cout << "Пароли не совпадают! Повторите ввод!" << endl;
                        delete[] Password; Password = nullptr; continue; //повторный ввод обоих паролей
                    }else break; //иначе выход из бесконечного цикла
                    //II вариант - повторный ввод повторного пароля при ошибке
                    //do
                    //{
                    //    gets_s(Buffer, 255);
                    //    if (strcmp(Password, Buffer))cout << "Пароли не совпадают! Повторите ввод!" << endl;
                    //} while(strcmp(Password, Buffer)); //вернет 0 если строки равны, 1 если первая больше второй и -1 вторая больше первой
                    //delete[] Buffer;
                    //Buffer = nullptr;
                    //break; //выход из бесконечного цикла
                }
                else
                {
                    cout << "Ваш пароль недостаточно надежный!" << endl;
                    if (!Upper) cout << "Пароль должен содержать хотя бы одну букву верхнего регистра!"<<endl;
                    if (!Lower) cout << "Пароль должен содержать хотя бы одну букву нижнего  регистра!" << endl;
                    if (!Digit) cout << "Пароль должен содержать хотя бы одну цифру!" << endl;
                    if (!Symbol) cout << "Пароль должен содержать хотя бы спец символ!" << endl;
                    cout << "Повторите ввод!" << endl;
                    system("pause");
                }
        }
    } while (true);
    cout << "Пароль " << Password << " успешно сохранен!" << endl;
    delete[] Password;
}

*/