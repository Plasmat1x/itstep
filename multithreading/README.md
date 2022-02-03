
##Потоки в классе.

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


####Указатели и потоки

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