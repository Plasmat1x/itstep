#include <iostream>
#include <algorithm>
#include <utility>

// ��� ������� ������� �������� �������


void selectionSort(int* array, int size, bool (*comparsionFcn)(int, int))
{
    // ���������� ������ ������� �������
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // smallestIndex - ��� ������ ����������� ��������, ������� �� ���������� �� ����� �������
        int bestIndex = startIndex;

        // ���� ���������� ������� ����� ���������� � ������� (�������� �� startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // ���� ������� ������� ������ ������ ����������� ���������� ����������� ��������,
            if (comparsionFcn(array[bestIndex], array[currentIndex])) // ��������� ����������� �����
                // �� ��� ��� ����� ���������� ������� � ���� ��������
                bestIndex = currentIndex;
        }

        // ������ ������� ��� ��������� ������� � ��������� ���������� ���������
        std::swap(array[startIndex], array[bestIndex]);
    }
}

// ��� ������� ���������, ������� ��������� ���������� � ������� ����������� (�������� ��������, ��� �� �� ������� ascending(), ��� � � �������, ����������� ����)
bool ascending(int a, int b)
{
    return a > b; // ������ �������, ���� ������ ������� ������ �������
}

// ��� ������� ���������, ������� ��������� ���������� � ������� ��������
bool descending(int a, int b)
{
    return a < b; // ������ �������, ���� ������ ������� ������ �������
}

void printArray(int* array, int size)
{
    for (int index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << '\n';
}

int main()
{
    int array[8] = { 4,8,5,6,2,3,1,7 };

    selectionSort(array, 8, descending);
    printArray(array, 8);

    selectionSort(array, 8, ascending);
    printArray(array, 8);

    return 0;
}

/*

int boo()
{
    return 7;
}

int doo()
{
    return 8;
}

int moo(int a)
{
    return a;
}

int main()
{

    std::cout << boo << std::endl;

    int (*fcnPtr)() = boo;
    fcnPtr = doo;

    int (*fcnPtr1)(int) = moo;
    (*fcnPtr1)(7);
    fcnPtr1(8);

    std::cout << fcnPtr1(8) << std::endl;

    return 0;
}

*/