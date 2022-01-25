#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <string>
#include <sstream>

void fill_array(int* arr, unsigned int size, int a, int b = 0);
void bubble_sort(int* arr, unsigned int size);
void array_print(int* arr, unsigned int size, int n_col = 16, int col_w = 2);
void runtime_clock(void* func(), std::string message, std::stringstream& ss);

int main()
{
    /*
    //fragment time
    unsigned int start_time = std::clock();
    // do some code ...
    unsigned int end_time = std::clock();
    unsigned int search_time = end_time - start_time; // result time

    //programm time 
    // do some code ...
    unsigned int end_time = std::clock();
    */

    std::stringstream ss;

    std::clock_t s_timer;
    std::clock_t e_timer;
    std::clock_t r_time;

    int arr[1024 * 16];
    int arr2[1024 * 16];

    /*
    //arr random fill
    s_timer = std::clock();
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        arr[i] = (rand() % 255 + 1);
    }
    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << "fill fragment time " << r_time << " ms" << std::endl;

    //bubble sort
    s_timer = std::clock();
    for (int i = 0; i < (sizeof(arr) / sizeof(int)) - 1; i++)
    {
        for (int j = 0; j < (sizeof(arr) / sizeof(int)) - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                float tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << "sort fragment time " << r_time << " ms" << std::endl;

    //arr cout;
    s_timer = std::clock();
    std::cout << std::hex;
    for (int i = 0; i < (sizeof(arr) / sizeof(int)) - 1; i++)
    {
        for (int j = 0; j < (sizeof(arr) / sizeof(int)) - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                float tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    std::cout << std::dec;
    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << "cout fragment time " << r_time << " ms" << std::endl;
    */

    //runtime_clock(fill_array(arr, 256, 0), "fill time ", ss);
    fill_array(arr, sizeof(arr) / sizeof(int), 256, 0);
    fill_array(arr2, sizeof(arr) / sizeof(int), 256, 0);

    bubble_sort(arr, sizeof(arr) / sizeof(int));

    std::cout << std::hex;
    array_print(arr, sizeof(arr) / sizeof(int));
    std::cout << std::dec;

    ss << std::endl << "programm time " << std::clock() << " ms" << std::endl;
    std::cout << ss.str() << std::endl;

    system("pause");
    return EXIT_SUCCESS;
}

void fill_array(int* arr, unsigned int size, int a, int b)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % a) + b;
    }
}

void bubble_sort(int* arr, unsigned int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                float tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void array_print(int* arr, unsigned int size, int n_col, int col_w)
{
    for (int i = 0; i < size; )
    {
        for (int j = 0; j < 16; j++)
        {
            std::cout << std::setw(col_w) << arr[i] << " ";
            i++;
        }
        std::cout << std::endl;
    }
}

/// <summary>
/// функция для расчета времени выполнения функции переданной в качестве параметра
/// </summary>
/// <param name="func">void fill_array(int* arr, int a, int b = 0);</param>
/// <param name="func">void bubble_sort(int* arr); </param>
/// <param name="func">void array_print(int* arr, int n_col = 16, int col_w = 2);</param>
/// <param name="message"> - string</param>
/// <param name="ss"> - string stream</param>
void runtime_clock(void* func(), std::string message, std::stringstream& ss)
{
    std::clock_t s_timer;
    std::clock_t e_timer;
    std::clock_t r_time;
    s_timer = std::clock();

    func();

    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << message << r_time << " ms" << std::endl;
}
