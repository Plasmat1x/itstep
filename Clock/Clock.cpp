#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>

static std::stringstream ss;

static std::clock_t _s;
static std::clock_t _e;
static std::clock_t _r;

void fill_array(int* arr, unsigned int size, int a, int b = 0);
void bubble_sort(int* arr, unsigned int size);
void megrge_sort(int* arr, int l, int r);
void selection_sort(int* arr, unsigned int size);
void array_print(int* arr, unsigned int size, int n_col = 16, int col_w = 2);
//void runtime_clock(std::string message, std::stringstream& ss);

template<typename... Args>
void runtime_clock(std::string message, std::stringstream& ss , void (*CallBackFcn)(Args... args));

void clock_start()
{
    _s = std::clock();
}

void clock_end(std::string message, std::stringstream& ss)
{
    _e = std::clock();
    _r = _e - _s;
    ss << message << _r << " ms" << std::endl;
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
    /*
    clock_start();
    fill_array(arr, sizeof(arr) / sizeof(int), 256, 0);
    clock_end("fill arr time ", ss);

    clock_start();
    fill_array(arr2, sizeof(arr) / sizeof(int), 256, 0);
    clock_end("fill arr2 time ", ss);

    clock_start();
    bubble_sort(arr, sizeof(arr) / sizeof(int));
    clock_end("bublle sort arr time ", ss);

    clock_start();
    std::cout << std::hex;
    array_print(arr, sizeof(arr) / sizeof(int));
    std::cout << std::dec;
    clock_end("print arr time ", ss);
    */


    runtime_clock("something", ss, fill_array);

    ss << std::endl << "programm time " << std::clock() << " ms" << std::endl;
    std::cout << ss.str() << std::endl;

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
        for (int j = 0; j < 16; j++)
        {
            std::cout << std::setw(col_w) << arr[i] << " ";
            i++;
        }
        std::cout << std::endl;
    }
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
*/

template<typename... Args>
void runtime_clock(std::string message, std::stringstream& ss, void (*CallBackFcn)(Args... args))
{
    std::clock_t s_timer;
    std::clock_t e_timer;
    std::clock_t r_time;
    s_timer = std::clock();

    //CallBackFcn(...(args));

    e_timer = std::clock();
    r_time = e_timer - s_timer;
    ss << message << r_time << " ms" << std::endl;
}

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

void megrge_sort(int* arr, int l, int r)
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

    megrge_sort(arr, l, m);
    megrge_sort(arr, m + 1, r);
    int buf[256];
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
}

void selection_sort(int* arr, unsigned int size)
{

}
