# Многопоточность
## Потоки в классе.

Непосредственно класс
```
#include<thread>

class Core
{
private:
    //var

    //func
    void fnc();

public:

    Core();
    ~Core();

    void run();
};
```


*Пример кода из книг*
```
void fnc();
int main()
{
    std::thread t(fnc);

    t.join();
}
```

функция класса с созданием и вызова потока
```
void Core::run()
{
    std::thread t(&Core::fnc, this);

    t.join();
}
```


для использование функций членов класса
должна быть либо статик функция
```  
static void fnc();
```


либо ссылкой на функцию + экземпляр класса (формулировка не точная)
*Для вызова члена класса, вне класса*
```
std::thread t(&Core::fnc, Core());
```


*вызов члена класса внутри класса, тоже самое что и пример сверху, за исключением того что будет работать только в классе где вызывается*
```
std::thread t(&Core::fnc, this);
```


## Указатели и потоки

*Создание указателя на поток в полях класса*
```
#include<thread>

class Core
{
private:
    //var
    std::thread* t;
    //func
    void fnc();

public:

    Core();
    ~Core();

    void run();
};
```


*Функция с выделением в куче места под поток и вызов*
```
void Core::run()
{
    t = new std::thread(&Core::fnc, this);

    t->join();

    delete t;
}
```

## Потоки с параметрами

Для передачи функции с параметрами используется:
```
#include<iostream>
#include<cstdlib>
#include<thread>

namespace tz
{
    void fnc();
    void fncx(int a, int b);
    void testmain();
};

void tz::fnc()
{
    std::cout << "hello thread" << std::endl;
}

void tz::fncx(int a, int b)
{
    std::cout << "hello param thread " << a+b << std::endl;
}

void tz::testmain()
{
{
    std::thread t(tz::fnc);                             //yep
    t.detach();
  //std::thread t((tz::fncx)(5,6));                     //nope
  //std::thread t{ tz::fncx(5,6) };                     //nope
  //std::thread t((*tx)(int, int));                     //nope
  //std::thread t(tz::fncx, 5, 6);                      //yep
  //std::thread t{ tz::fncx, 5, 6 };                    //yep
  //std::thread t{ tz::clbck, tz::fncx, 50, 60 };       //nope    //попытка передачи функции в качестве параметра
  //std::thread t{ tz::clbck, (tz::fncx)(50,60)};       //nope
  //std::thread t{ tz::clbck, tz::fncx(50,60)};         //nope

  //int a = 50, b = 60;                                 
  //std::thread t{ [a,b]()->void                        //yep    //удалось сделать через лямбда-функцию 
  //{
  //    fncx(a,b);
  //}
  //};
    t = std::thread(tz::fncx, 20, 20);                  //yep    //финт ушами без создания новой перемнной

    t.join();
}
```

## Chrono управляй временем

В данном случае используется для создания искусственного различия в скорости
*пример кода в использовании (используется подобная функция для второго потока с другим временем ожидания потока)*
```
void Core::fnc()
{
    std::cout << "<----thread start---->" << std::endl;

    for (int i = 0; i < 25; i++)
    {
        std::cout << " THREAD::ITERATION::" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
    }

    std::cout << "<----thread end---->" << std::endl;
}
```