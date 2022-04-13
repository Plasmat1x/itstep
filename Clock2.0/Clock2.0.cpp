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
#include <thread>
#include <Windows.h>

#include "thread_guard.h"

//                      KB     MB     GB    reuslt size in RAM 4 * 1024 * 1024 * 1024 = 4 GB
//unsigned int size_ = 1024 * 1024 * 1024;

unsigned int size_ = 1024 * 100;
//unsigned int size_ = 256; //you can change size;

unsigned int size_byte = size_ * sizeof(int);
unsigned int size_hepify = size_byte / sizeof(int);

static int buf_size = size_;

std::thread t;

void fill_array(int* arr, unsigned int size, int a = 256, int b = 0);

void bubble_sort(int* arr, unsigned int size);

void merge_sort(int* arr, int l, int r);

bool descending(int a, int b);
bool ascending(int a, int b);
void selection_sort(int* arr, unsigned int size, bool (*comparsionFcn)(int, int) = nullptr);

void array_print(std::stringstream& ss, int* arr, unsigned int size, int n_col, int col_w = 2);
void array_print_infile(std::fstream& fs, int* arr, unsigned int size, int n_col, int col_w = 2);

void heapify(int* arr, int n, int i);
void heap_sort(int* arr, unsigned int n);

void quick_sort(int* arr, int l, int r);

void insert_sort(int* arr, unsigned int n);

/*
void runtime_clock(int* arr, unsigned int size, std::stringstream& ss, void (*CallbackFcn)(int*, unsigned int));
void runtime_clock(int* arr, int l, int r, std::stringstream& ss, void (*CallbackFcn)(int*, int, int));
void runtime_clock(int* arr, unsigned int size, std::stringstream& ss, bool (*comparsionFcn)(int, int), void (*CallBackFcn)(int*, unsigned int, bool (*comparsionFcn)(int, int)));
//*/

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
    system("chcp 65001");
    
    static std::stringstream ss;
    static std::stringstream arrss;
    static std::fstream file_out;
    static std::fstream file_sorted_array_out;
    static std::fstream file_arry_out;

    int* arr = new int[size_];

    fill_array(arr, size_);
    file_arry_out.open("array_out.txt", std::ios::out);
    file_arry_out << std::uppercase << std::hex;
    array_print_infile(file_arry_out, arr, size_, 16);
    file_arry_out << std::nouppercase << std::dec;
    file_arry_out.close();
    std::cout << "pre-sorted file output in array_out.txt" << std::endl;

    std::cout << "\n<-- time check for algorithm -->\n" << std::endl;
    std::cout << "array size: " << size_ * 4 << " byte | elements count of array: " << size_ << std::endl;
    std::cout << "thread available: " << std::thread::hardware_concurrency() << std::endl;
    std::cout <<
        R"(
_______________________________________________________MENU__________________________________________________
                                     ====================================================================
                                     |           time difficult                | additiona data         |
                                     ====================================================================
                                     |    best     |   averge    |   worst     |        worst           |
                                     ====================================================================
    1 - bubble  sort.----------------| O(n)        | O(n^2)      | O(n^2)      | O(1)                   |
    2 - merge   sort.----------------| O(n log(n)) | O(n log(n)) | O(n log(n)) | O(n)                   |
    3 - selection sort.--------------| O(n^2)      | O(n^2)      | O(n^2)      | O(1)                   |
    4 - quick sort.------------------| O(n log(n)) | O(n log(n)) | O(n^2)      | O(n)                   |
    5 - heap sort.-------------------| O(n log(n)) | O(n log(n)) | O(n log(n)) | O(1)                   |
    6 - insertion sort.--------------| O(n)        | O(n^2)      | O(n^2)      | O(1)                   |
    ! - block sort.------------------| O(n+k)      | O(n+k)      | O(n^2)      | O(nk)                  |
    ! - radix sort.------------------| O(nk)       | O(nk)       | O(nk)       | O(n+k)                 |
                                     ====================================================================
   99 - without sort
    0 - exit
______________________________________________________________________________________________________________
)" << std::endl;

    int menu_state = 0;
    std::cout << "enter command number > ";
    std::cin >> menu_state;

    bool sort = true;
    switch (menu_state)
    {
    case 0:
        delete[] arr;
        return EXIT_SUCCESS;
    case 1: // bubble sort
    {
        ss << "bubble sort ";
        //runtime_clock(arr, size_, ss, bubble_sort);
        //пример в боевом коде
        unsigned int l_s = size_;
        std::stringstream* l_ss = &ss;
        t = std::thread(
            [arr, l_s, l_ss, &sort]()->void
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                std::cout << "thread created::sort start" << std::endl;
                std::clock_t s_timer;
                std::clock_t e_timer;
                std::clock_t r_time;
                s_timer = std::clock();

                bubble_sort(arr, l_s);

                e_timer = std::clock();
                r_time = e_timer - s_timer;
                (*l_ss) << r_time << " ms" << std::endl;
                std::cout << "thread destructed::sort end" << std::endl;
                sort = false;
            });
        t.detach();
        break;
    }
    case 2: // merge sort
    {
        ss << "merge sort ";
        //runtime_clock(arr, 0, size_ - 1, ss, merge_sort);
        unsigned int l_s = size_;
        std::stringstream* l_ss = &ss;
        t = std::thread(
            [arr, l_s, l_ss, &sort]()->void
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                std::cout << "thread created::sort start" << std::endl;
                std::clock_t s_timer;
                std::clock_t e_timer;
                std::clock_t r_time;
                s_timer = std::clock();

                merge_sort(arr, 0, l_s - 1);

                e_timer = std::clock();
                r_time = e_timer - s_timer;
                (*l_ss) << r_time << " ms" << std::endl;
                std::cout << "thread destructed::sort end" << std::endl;
                sort = false;
            });
        t.detach();
        break;
    }
    case 3: // selection sort
    {
        ss << "selection sort ";
        menu_state = 0;
        std::cout << R"(how sort:
    0 - ascending
    1 - descending)" << std::endl;
        std::cout << "enter command number > ";
        std::cin >> menu_state;
        std::cout << std::endl;

        if (menu_state == 0)
        {
            //runtime_clock(arr, size_, ss, ascending, selection_sort);
            unsigned int l_s = size_;
            std::stringstream* l_ss = &ss;
            t = std::thread([arr, l_s, l_ss, &sort]()->void
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                    std::cout << "thread created::sort start" << std::endl;
                    std::clock_t s_timer;
                    std::clock_t e_timer;
                    std::clock_t r_time;
                    s_timer = std::clock();

                    selection_sort(arr, l_s, ascending);

                    e_timer = std::clock();
                    r_time = e_timer - s_timer;
                    (*l_ss) << r_time << " ms" << std::endl;
                    std::cout << "thread destructed::sort end" << std::endl;
                    sort = false;
                });
            t.detach();
        }
        else
        {
            //runtime_clock(arr, size_, ss, descending, selection_sort);
            unsigned int l_s = size_;
            std::stringstream* l_ss = &ss;
            t = std::thread([arr, l_s, l_ss, &sort]()->void
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                    std::cout << "thread created::sort start" << std::endl;
                    std::clock_t s_timer;
                    std::clock_t e_timer;
                    std::clock_t r_time;
                    s_timer = std::clock();

                    selection_sort(arr, l_s, descending);

                    e_timer = std::clock();
                    r_time = e_timer - s_timer;
                    (*l_ss) << r_time << " ms" << std::endl;
                    std::cout << "thread destructed::sort end" << std::endl;
                    sort = false;
                });
            t.detach();
        }   

        break;
    }
    case 4: // quick sort
    {
        ss << "quick sort ";
        //runtime_clock(arr, 0, size_ - 1, ss, quick_sort);

        unsigned int l_s = size_;
        std::stringstream* l_ss = &ss;
        t = std::thread([arr, l_s, l_ss, &sort]()->void
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                std::cout << "thread created::sort start" << std::endl;
                std::clock_t s_timer;
                std::clock_t e_timer;
                std::clock_t r_time;
                s_timer = std::clock();

                quick_sort(arr, 0, l_s - 1);

                e_timer = std::clock();
                r_time = e_timer - s_timer;
                (*l_ss) << r_time << " ms" << std::endl;
                std::cout << "thread destructed::sort end" << std::endl;
                sort = false;
            });
        t.detach();

        break;
    }

    case 5: // heap sort
    {
        ss << "heap sort ";
        //runtime_clock(arr, size_hepify, ss, heap_sort);

        unsigned int l_s = size_;
        std::stringstream* l_ss = &ss;
        t = std::thread([arr, l_s, l_ss, &sort]()->void
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                std::cout << "thread created::sort start" << std::endl;
                std::clock_t s_timer;
                std::clock_t e_timer;
                std::clock_t r_time;
                s_timer = std::clock();

                heap_sort(arr, l_s);

                e_timer = std::clock();
                r_time = e_timer - s_timer;
                (*l_ss) << r_time << " ms" << std::endl;
                std::cout << "thread destructed::sort end" << std::endl;
                sort = false;
            });
        t.detach();

        break;
    }
    case 6: //insertion sort
    {
        ss << "insertion sort ";
        //runtime_clock(arr, size_, ss, insert_sort);
        unsigned int l_s = size_;
        std::stringstream* l_ss = &ss;
        t = std::thread([arr, l_s, l_ss, &sort]()->void
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                std::cout << "thread created::sort start" << std::endl;
                std::clock_t s_timer;
                std::clock_t e_timer;
                std::clock_t r_time;
                s_timer = std::clock();

                insert_sort(arr, l_s);

                e_timer = std::clock();
                r_time = e_timer - s_timer;
                (*l_ss) << r_time << " ms" << std::endl;
                std::cout << "thread destructed::sort end" << std::endl;
                sort = false;
            });
        t.detach();
        break;
    }
    case 99:
        ss << "without sort " << std::endl;
        break;
    default: break;
    }

    menu_state = 0;
    std::cout <<
        R"(
output destination:
    0 - console
    1 - file
    2 - only timing print

)" << std::endl;

    std::cout << "enter command number > ";
    std::cin >> menu_state;
    std::cout << std::endl;
    
    //красивостей на время ожидания сортировки
    while (sort)
    {
        for (int i = 0; i < 3; i++)
        {
            Sleep(1500);
            std::cout << ". ";    
        }
        Sleep(1500);
        std::cout << "\r\r\r\r\r\r";
        std::cout << "      ";
        std::cout << "\r\r\r\r\r\r";
    }

    std::cout << std::endl;
    std::cout << "______________________________________________________________________________________________________________" << std::endl;
    switch (menu_state)
    {
    case 0:
        if (size_byte < 1024 * 1024 * 256 * 4)
        {
            arrss << std::uppercase << std::hex;
            array_print(arrss, arr, size_, 16, 2);
            arrss << std::nouppercase << std::dec;
        }
        else
        {
            std::cout << "output in console canceled, to big size" << std::endl;
        }

        ss << std::endl << "app time " << std::clock() << " ms" << std::endl;
        std::cout << arrss.str() << std::endl;
        std::cout << "______________________________________________________________________________________________________________" << std::endl;
        std::cout << ss.str() << std::endl;
        std::cout << "______________________________________________________________________________________________________________" << std::endl;
        system("pause");

        break;
    case 1:

        file_sorted_array_out.open("array_sort_out.txt", std::ios::out);
        file_sorted_array_out << std::uppercase << std::hex;
        array_print_infile(file_sorted_array_out, arr, (int)size_, 16, 2);
        file_sorted_array_out << std::nouppercase << std::dec;
        file_sorted_array_out.close();
        ss << std::endl << "data size: " << size_byte << "byte" << std::endl;
        ss << std::endl << "app time " << std::clock() << " ms" << std::endl;
        file_out.open("output.txt", std::ios::out);
        file_out << ss.str();
        file_out.close();

        break;
    default:
        ss << std::endl << "app time " << std::clock() << " ms" << std::endl;
        std::cout << ss.str() << std::endl;
        std::cout << "______________________________________________________________________________________________________________" << std::endl;
        system("pause");
        break;
    }

    delete[] arr;
    return EXIT_SUCCESS;
}

void insert_sort(int* arr, unsigned int n)
{
    for (int i = 0; i < (int)n; i++)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
        {
            std::swap(arr[j - 1], arr[j]);
        }
}

void quick_sort(int* arr, int l, int r)
{
    int i = l;
    int j = r;
    int p = arr[(l + r) / 2];

    while (i <= j)
    {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;

        if (i <= j)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
            i++; j--;
        }
    }

    if (l < j) quick_sort(arr, l, j);
    if (i < r) quick_sort(arr, i, r);
}

void heapify(int* arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }

}

void heap_sort(int* arr, unsigned int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

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

void array_print_infile(std::fstream& fs, int* arr, unsigned int size, int n_col, int col_w)
{
    for (unsigned int i = 0; i < size; )
    {
        for (int j = 0; j < n_col; j++)
        {
            fs << std::setw(col_w) << arr[i] << " ";
            i++;
        }
        fs << std::endl;
    }

    fs << std::endl;
}

/*
void runtime_clock(int* arr, unsigned int size, std::stringstream& ss, void (*CallbackFcn)(int*, unsigned int))
{
    std::clock_t s_timer;
    std::clock_t e_timer;
    std::clock_t r_time;
    s_timer = std::clock();

    CallbackFcn(arr, size);

    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << r_time << " ms" << std::endl;

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
    ss << r_time << " ms" << std::endl;
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
    ss << r_time << " ms" << std::endl;
}
//*/
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
