#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));

    const int ROWS = 5;
    const int COLS = 8;

    int arr[ROWS][COLS] = {};

    bool Double_n;

    //-------------------------------------------------//
    for (int i = 0; i < ROWS; i++) // ������
    {
        for (int j = 0; j < COLS;)
        {    
            Double_n = false;  // ���������� ��� ����������� ������
            int new_n = rand() % 100;// ���������� ��� ��������� ����� �������

            //---��������
            for (int k = 0; k < i; k++) // �������� ������� �� ������������ �����
            {
                for (int w = 0; w < j; w++)
                {
                    if (arr[k][w] == new_n)
                    {
                        Double_n = true;
                    }
                }
            }

            if (!Double_n)  // ������������ ������� ����������� �����
            {
                arr[i][j] = new_n;
                j++;
            }
        }
    }
    cout << "\n \n" << endl;

    //---min
    int min = arr[0][0];
    for (int k = 0; k < ROWS; k++) // �������� ������� �� ������������ �����
    {
        for (int w = 0; w < COLS; w++)
        {
            if (arr[k][w] < min)
            {
                min = arr[k][w];
            }
        }
    }


    for (int i = 0; i < ROWS; i++) // �������� ������� �� ������������ �����
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << "\t";
        }

        cout << endl;
    }
    cout << "\n \n" << endl;
}