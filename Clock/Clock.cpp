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

unsigned int size_ = 256 * 1024;

static std::stringstream ss;
static std::stringstream ss_array;
static std::fstream file_out;

static std::clock_t _s;
static std::clock_t _e;
static std::clock_t _r;

static const long int buf_size = size_;

void fill_array(int* arr, unsigned int size, int a = 256, int b = 0);
void bubble_sort(int* arr, unsigned int size);
void merge_sort(int* arr, int l, int r);
bool descending(int a, int b);
bool ascending(int a, int b);
void selection_sort(int* arr, unsigned int size, bool (*comparsionFcn)(int, int) = nullptr);
void array_print(int* arr, unsigned int size, int n_col, int col_w = 2);
void array_print_infile(int* arr, unsigned int size, int n_col, int col_w = 2);
void runtime_clock(std::string message, std::stringstream& ss);

void clock_start()
{
    _s = std::clock();
}

void clock_end(std::string message, std::stringstream& ss)
{
    _e = std::clock();
    _r = _e - _s;
    ss << std::endl << message << _r << " ms" << std::endl;
}

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
    
    //stress test
    //int arr[1024 * 16];
    //int arr2[1024 * 16];
    //int arr3[1024 * 16];
    //int arr3[1024 * 1024]; //death -> stackoverflow -> 8 byte * 1024 * 1024
    //                  byte kilobyte megabyte
    int* arr3 = new int[size_]; //death -> stackoverflow -> 4 byte * 1024 * 1024 -> transfer to array into heap-+
    //view test
    //int arr[16];
    //int arr2[16];
    //int arr3[16];

    /*
    {
        //arr
        clock_start();
        fill_array(arr, sizeof(arr) / sizeof(int), 256, 0);
        clock_end("fill arr time ", ss);

        clock_start();
        bubble_sort(arr, sizeof(arr) / sizeof(int));
        clock_end("bublle sort arr time ", ss);

        clock_start();
        std::cout << std::hex;
        array_print(arr, sizeof(arr) / sizeof(int), 32);
        std::cout << std::dec;
        clock_end("print arr time ", ss);
    }
    //*/
    /*
    {
        //arr2
        clock_start();
        fill_array(arr2, sizeof(arr2) / sizeof(int), 256, 0);
        clock_end("fill arr2 time ", ss);

        clock_start();
        merge_sort(arr2, 0, sizeof(arr2) / sizeof(int)-1);
        clock_end("merge sort arr2 time ", ss);

        clock_start();
        std::cout << std::hex;
        array_print(arr2, sizeof(arr2) / sizeof(int), 32);
        std::cout << std::dec;
        clock_end("print arr2 time ", ss);
    }
    //*/
    //*
    {
        //arr3
        fill_array(arr3, size_, 256, 0);

        clock_start();
        //selection_sort(arr3, size_, ascending);
        //bubble_sort(arr3, size_);
        merge_sort(arr3, 0, (size_-1));
        clock_end("selection sort arr3 time ", ss);

        
        /*
        file_out.open("output.txt", std::ios::out);
        ss_array << std::hex;
        array_print_infile(arr3, size_, 64);
        ss_array << std::dec;
        */

        std::cout << std::hex;
        array_print(arr3, size_, 64);
        std::cout << std::dec;

    }
    //*/
    ss << std::endl << "programm time " << std::clock() << " ms" << std::endl;
    std::cout << ss.str() << std::endl;
    //file_out << ss_array.str() << std::endl;
    //file_out << ss.str() << std::endl;
    //file_out.close();
    delete arr3;
    //system("pause");
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
        for (int j = 0; j < n_col; j++)
        {
            std::cout << std::setw(col_w) << arr[i] << " ";
            i++;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void array_print_infile(int* arr, unsigned int size, int n_col, int col_w)
{
    for (int i = 0; i < size; )
    {
        for (int j = 0; j < n_col; j++)
        {
            ss_array << std::setw(col_w) << arr[i] << " ";
            i++;
        }
        ss_array << std::endl;
    }

    ss_array << std::endl;
}

/// <summary>
/// функци€ дл€ расчета времени выполнени€ функции переданной в качестве параметра
/// </summary>
/// <param name="func">void fill_array(int* arr, int a, int b = 0);</param>
/// <param name="func">void bubble_sort(int* arr); </param>
/// <param name="func">void array_print(int* arr, int n_col = 16, int col_w = 2);</param>
/// <param name="message"> - string</param>
/// <param name="ss"> - string stream</param>
/*
void runtime_clock(std::string message, std::stringstream& ss)
{
    std::clock_t s_timer;
    std::clock_t e_timer;
    std::clock_t r_time;
    s_timer = std::clock();

    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << message << r_time << " ms" << std::endl;
}
//*/

/*
//callback ref
#include <iostream>
using namespace std;

int my_function(int *arr,int len, bool(*fn)(int,int))
{
    int res = arr[0];

    for(int i = 1; i < len; ++i)
        if(fn(res,arr[i]))
            res = arr[i];

    return res;
}

bool max_(int i, int j) { return i < j; }
bool min_(int i, int j) { return i > j; }

int main()
{
    int arr[5] = {0,-1,2,3,5};

    cout<<"Max elem: "<<my_function(arr,5,max_)<<endl;
    cout<<"Min elem: "<<my_function(arr,5,min_)<<endl;

    return 0;
}
*/

void merge_sort(int* arr, int l, int r)
{
    /*usability
    int main() 
    {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        merge(0, n Ч 1);

        for (int i = 0; i < n; i++)
            cout << a[i] << ї Ђ;

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
            std::swap(r, l);
        return;
    }

    int m = (r + l) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    int* buf = new int[buf_size]();
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

    delete buf;
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
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        int bestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            if (comparsionFcn(arr[bestIndex], arr[currentIndex]))
                bestIndex = currentIndex;
        }
        std::swap(arr[startIndex], arr[bestIndex]);
    }
}
