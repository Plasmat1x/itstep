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
#include <ctype.h> //���������� ��� ������ � ���������
#include <stdio.h>

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
    char* Buffer = new char[255]{}; //����� ��� ����� � ������� ������
    char* Password = nullptr; //��������� �� ������ ��� �������� ��������� ������
    bool Upper = false, Lower = false, Digit = false, Symbol = false, Trash = false, Space = false;
    //����� ���� �������� � ������� ��������, ����, ����. ��������, �������� ��������, �������
    do
    {
        //���������� ����� ����� �������� ������
        Upper = false; Lower = false; Digit = false; Symbol = false; Trash = false; Space = false;
        system("cls");
        cout << R"(������� ������, �� ������ ���������:
1. �� ����� 8 ��������
2. ����� �������� �������� ���������� ��������
3. ����� ������� �������� ���������� ��������
4. �����
5. ����. �������
6. ������� � ����� ������������ �������� ������ ������������!
)";
        gets_s(Buffer, 255); //��� ������ ��� ���������, ����� ��������� ������
        if (strlen(Buffer) < 8)
        {
            cout << "������� �������� ������!" << endl;
            system("pause");
        }
        else
        {
            //���� ������� ������� ������� � ������
            for (int i = 0; i < strlen(Buffer); i++)
            {
                if (Buffer[i] < 32 || Buffer[i]>126) //���������� ������������ ��������
                {
                    cout << "������������ �������!" << endl;
                    Trash = true;
                    break;
                }
                if (isspace(Buffer[i])) //if(Buffer[i]==32)
                {
                    cout << "������� ������ ������������!" << endl;
                    Space = true;
                    break;
                }
                //isalpha(); //�������� ����� ��
                //���� ����� �������� ��������
                if(isupper(Buffer[i])) Upper=true; //if(Buffer[i]>=65&&Buffer[i]<=90)
                //���� ����� ������� ��������
                if (islower(Buffer[i])) Lower = true;
                //���� �����
                if (isdigit(Buffer[i])) Digit= true;
                //���� ���� ������
                if (!isalnum(Buffer[i]))Symbol = true; //isalnum(Buffer[i])������ 0 ���� �� ����� � �� �����
            }
            if (Trash || Space) //���� ����� �� ����� �� break
            {
                cout << "��������� ����!" << endl;
                system("pause");
            }
            else
                if (Upper && Lower && Digit && Symbol)
                {
                    cout<<"��� ������ ��������! ��� ������������� ������� ��� ��������: "<<endl;
                    Password = new char[strlen(Buffer) + 1]{};
                    strcpy_s(Password, strlen(Buffer) + 1, Buffer);
                    //I ������� ������ ���� ������� ������ ��� ������
                    gets_s(Buffer, 255);
                    if (strcmp(Password, Buffer))
                    {
                        cout << "������ �� ���������! ��������� ����!" << endl;
                        delete[] Password; Password = nullptr; continue; //��������� ���� ����� �������
                    }else break; //����� ����� �� ������������ �����
                    //II ������� - ��������� ���� ���������� ������ ��� ������
                    //do
                    //{
                    //    gets_s(Buffer, 255);
                    //    if (strcmp(Password, Buffer))cout << "������ �� ���������! ��������� ����!" << endl;
                    //} while(strcmp(Password, Buffer)); //������ 0 ���� ������ �����, 1 ���� ������ ������ ������ � -1 ������ ������ ������
                    //delete[] Buffer;
                    //Buffer = nullptr;
                    //break; //����� �� ������������ �����
                }
                else
                {
                    cout << "��� ������ ������������ ��������!" << endl;
                    if (!Upper) cout << "������ ������ ��������� ���� �� ���� ����� �������� ��������!"<<endl;
                    if (!Lower) cout << "������ ������ ��������� ���� �� ���� ����� �������  ��������!" << endl;
                    if (!Digit) cout << "������ ������ ��������� ���� �� ���� �����!" << endl;
                    if (!Symbol) cout << "������ ������ ��������� ���� �� ���� ������!" << endl;
                    cout << "��������� ����!" << endl;
                    system("pause");
                }
        }
    } while (true);
    cout << "������ " << Password << " ������� ��������!" << endl;
    delete[] Password;
}

*/