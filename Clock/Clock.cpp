//file in ASCII(1251) code page
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <fstream>

unsigned int size_ = 1024; //you can change size;

static const int buf_size = size_;

void fill_array(int* arr, unsigned int size, int a = 256, int b = 0);

void bubble_sort(int* arr, unsigned int size);

void merge_sort(int* arr, int l, int r);

bool descending(int a, int b);
bool ascending(int a, int b);
void selection_sort(int* arr, unsigned int size, bool (*comparsionFcn)(int, int) = nullptr);

void array_print(std::stringstream& ss, int* arr, unsigned int size, int n_col, int col_w = 2);
void array_print_infile(std::stringstream& ss, int* arr, unsigned int size, int n_col, int col_w = 2);

void runtime_clock(int* arr, unsigned int size, std::stringstream& ss, void (*CallbackFcn)(int*, unsigned int));
void runtime_clock(int* arr, int l, int r, std::stringstream& ss, void (*CallbackFcn)(int*, int, int));
void runtime_clock(int* arr, unsigned int size, std::stringstream& ss, bool (*comparsionFcn)(int, int), void (*CallBackFcn)(int*, unsigned int, bool (*comparsionFcn)(int, int)));

int main()
{
    /*
    //fragment time
    unsigned int start_time = std::clock();
    // do some code 
    d_time = std::clock();
    unsigned int search_time = end_time - start_time; // result time

    //programm time 
    // do some code
    unsigned int end_time = std::clock();
    */
    
    system("chcp 1251");
    system("cls");

    static std::stringstream ss;
    static std::stringstream arrss;
    static std::fstream file_out;

    int* arr = new int[size_];

    std::cout << "<-- Провека времени работы алгоритмов -->" << std::endl;
    std::cout << "Размер массива: " << size_ * 4 << " байтов | количество элементов массива: " << size_ << std::endl;
    std::cout << 
R"(
Меню:
    1 - Сортировка пузырьком
    2 - Сортировка слиянием
    3 - Сортировка выборкой
    0 - Выход
)" << std::endl;

    int menu_state = 0;
    std::cout << "Введите номер команды > ";
    std::cin >> menu_state;
    std::cout << "Подождите производится сортировка..." << std::endl;
    if (size_ > 1024)
        std::cout << "Это на долго. Сверните консоль, найлейте чайку, время от времени разворачиваете и смотрите ..." << std::endl;

    fill_array(arr, size_);

    switch (menu_state)
    {
    case 0:
        delete[] arr;
        return EXIT_SUCCESS;
    case 1: // bubble sort
    {
        runtime_clock(arr, size_, ss, bubble_sort);

        break;
    }
    case 2: // merge sort
    {
        runtime_clock(arr, 0, size_ - 1, ss, merge_sort);

        break;
    }
    case 3: // selection sort
    {
        menu_state = 0;
        std::cout << R"(В каком порядке сортировать:
    0 - по возрастанию
    1 - по убыванию)" << std::endl;
        std::cout << "Введите номер команды > ";
        std::cin >> menu_state;
        std::cout << std::endl;

        if(menu_state == 0)
            runtime_clock(arr, size_, ss, ascending, selection_sort);
        else
            runtime_clock(arr, size_, ss, descending, selection_sort);

        break;
    }
    default: break;
    }

    menu_state = 0;
    std::cout <<
        R"(
Куда производить вывод:
    0 - В консоль
    1 - В файл

)" << std::endl;

    std::cout << "Введите номер команды > ";
    std::cin >> menu_state;
    std::cout << std::endl;

    switch (menu_state)
    {
    case 0:
        system("cls");

        arrss << std::hex;
        array_print(arrss, arr, size_, 16, 2);
        arrss << std::dec;

        ss << std::endl << "Время выполнения программы " << std::clock() << " ms" << std::endl;
        std::cout << arrss.str() << std::endl;
        std::cout << ss.str() << std::endl;

        system("pause");

        break;
    case 1:
        system("cls");

        arrss << std::hex;
        array_print_infile(arrss, arr, (int)size_, 16, 2);
        arrss << std::dec;
        ss << std::endl << "время выполнения программы " << std::clock() << " ms" << std::endl;
        
        file_out.open("output.txt", std::ios::out);
        file_out << arrss.str() << std::endl;
        file_out << ss.str();
        file_out.close();

        break;
    default:
        break;
    }



    system("chcp 866");
    system("cls");

    delete[] arr;
    return EXIT_SUCCESS;
}

void fill_array(int* arr, unsigned int size, int a, int b)
{
    for (unsigned int i = 0; i < size; i++)
    {
        arr[i] = (rand() % a) + b;
    }
}

void bubble_sort(int* arr, unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; i++)
    {
        for (unsigned int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void array_print(std::stringstream& ss, int* arr, unsigned int size, int n_col, int col_w)
{
    for (unsigned int i = 0; i < size; )
    {
        for (int j = 0; j < n_col; j++)
        {
            ss << std::setw(col_w) << arr[i] << " ";
            i++;
        }
        ss << std::endl;
    }

    ss << std::endl;
}

void array_print_infile(std::stringstream& ss, int* arr, unsigned int size, int n_col, int col_w)
{
    for (unsigned int i = 0; i < size; )
    {
        for (int j = 0; j < n_col; j++)
        {
            ss << std::setw(col_w) << arr[i] << " ";
            i++;
        }
        ss << std::endl;
    }

    ss << std::endl;
}

void runtime_clock(int* arr, unsigned int size, std::stringstream& ss, void (*CallbackFcn)(int*, unsigned int))
{
    std::clock_t s_timer;
    std::clock_t e_timer;
    std::clock_t r_time;
    s_timer = std::clock();

    CallbackFcn(arr, size);

    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << "Сортировка пузырьком " << r_time << " ms" << std::endl;

}

void runtime_clock(int* arr, int l, int r, std::stringstream& ss, void (*CallbackFcn)(int*, int, int))
{
    std::clock_t s_timer;
    std::clock_t e_timer;
    std::clock_t r_time;
    s_timer = std::clock();

    CallbackFcn(arr, l, r);

    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << "Сортировка слиянием " << r_time << " ms" << std::endl;
}

void runtime_clock(int* arr, unsigned int size, std::stringstream& ss, bool (*comparsionFcn)(int, int), void (*CallbackFcn)(int*, unsigned int, bool (*comparsionFcn)(int, int)))
{
    std::clock_t s_timer;
    std::clock_t e_timer;
    std::clock_t r_time;
    s_timer = std::clock();

    CallbackFcn(arr, size, comparsionFcn);

    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << "Сортировка выборкой " << r_time << " ms" << std::endl;
}

void merge_sort(int* arr, int l, int r)
{
    /*usability
    int main() 
    {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        merge(0, n — 1);

        for (int i = 0; i < n; i++)
            cout << a[i] << » «;

        getch();
        return 0;
    }
    */

    int tmp = 0;

    if (r == l)
        return;
    if (r - l == 1) 
    {
        if (arr[r] < arr[l])
            std::swap(arr[r], arr[l]);
        return;
    }

   

    int m = (r + l) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    int* buf = new int[buf_size];
    int xl = l;
    int xr = m + 1;
    int cur = 0;

    while (r - l + 1 != cur)
    {
        /*
        if (xl > m)
            buf[cur++] = a[xr++];
        else if (xr > r)
            buf[cur++] = a[xl++];
        else if (a[xl] > a[xr])
            buf[cur++] = a[xr++];
        else buf[cur++] = a[xl++];
        */

        if (xl > m)
            buf[cur++] = arr[xr++];
        else if (xr > r)
            buf[cur++] = arr[xl++];
        else if (arr[xl] > arr[xr])
            buf[cur++] = arr[xr++];
        else
            buf[cur++] = arr[xl++];
    }
    for (int i = 0; i < cur; i++)
        arr[i + l] = buf[i];

    delete[] buf;
}

bool ascending(int a, int b)
{
    return a > b;
}

bool descending(int a, int b)
{
    return a < b;
}

void selection_sort(int* arr, unsigned int size, bool (*comparsionFcn)(int, int))
{
    for (unsigned int startIndex = 0; startIndex < size; ++startIndex)
    {
        int bestIndex = startIndex;

        for (unsigned int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            if (comparsionFcn(arr[bestIndex], arr[currentIndex]))
                bestIndex = currentIndex;
        }
        std::swap(arr[startIndex], arr[bestIndex]);
    }
}
