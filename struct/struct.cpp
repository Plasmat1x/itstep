// Struct
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//определение структуры, содержащей дату
struct Date //Date - имя нового типа данных
{
    unsigned short Day;  //День
    char Month[12];      //Месяц
    int Year;            //Год
}Today = { 22,"мая",2022 }; //создание глобального объекта типа Date
//функция вывода на экран
void Show(Date D)
{
    //оператор .  - оператор доступа к полям структуры
    cout << D.Day << "." << D.Month << "." << D.Year << endl;
}

Date My_Birthday; //глобальный объект структуры, инициализируется нуля по умолчанию

//функция проверки високосный ли год
bool IsLeapYear(int CheckYear)
{
    //год не високосный если
    if (CheckYear % 4 != 0 || (CheckYear % 100 == 0 && CheckYear % 400 != 0))return false;
    //если условие ложное то год вискокосный
    return true;
}

//функция ввода даты с клавиатуры, принемает адрес объекта типа данных Date и помещает его в указатель на тип данных Date
void Input(Date* PTR)
{
    //cout << "Введите дату:" << endl;
    cout << "Введите день: "; cin >> PTR->Day; //PTR->Day обращение к полю Day через указатель PTR на тип данных Date
    cout << "Введите месяц: "; cin >> PTR->Month; //-> оператор доступа к полю структуры по указателю(селектор)
    cout << "Введите год: "; cin >> PTR->Year;
}
//перегрузка функции Input, возвращающей объект типа данных Date
Date Input()
{
    //создается временный пустой объект
    Date Temp{};
    cout << "Введите дату через Пробелы или Enter: " << endl;
    //ввод значений в объект через оператор .
    cin >> Temp.Day >> Temp.Month >> Temp.Year;
    return Temp; //возвращаем объект типа данных Date

}

int main()
{
    system("chcp 1251");
    system("cls");
    //создаем объект типа данных Date(экземпляр структуры Date)
    Date May9 = { 9,"мая",1945 };; //унифицированая инициализация объекта структуры
    //cout << May9 << endl;
    Date Yesterday{}; //пустой объект типа Date
    Yesterday = { 21,"мая",2022 }; //присваивание нового значения
    cout << Yesterday.Day << "." << Yesterday.Month << "." << Yesterday.Year << endl;
    Yesterday.Year = 2020; //доступ к полю структуры по имени поля
    system("cls");
    Show(May9); //вызов функции с передачей объекта типа данных Date в качестве параметра
    Show(Yesterday);
    Show(My_Birthday);
    Show(Today);
    system("cls");
    if (IsLeapYear(Yesterday.Year))//вызов функции с передачей одно поля объекта Date в качестве параметра
        cout << Yesterday.Year << " год - високосный!" << endl;
    else cout << Yesterday.Year << " год - невисокосный!" << endl;
    if (IsLeapYear(Today.Year))//вызов функции с передачей одно поля объекта Date в качестве параметра
        cout << Today.Year << " год - високосный!" << endl;
    else cout << Today.Year << " год - невисокосный!" << endl;
    system("cls");
    //cout << &Today << endl; //взятие адреса объекта типа данных Date
    cout << "Введите дату рождения: " << endl;
    Input(&My_Birthday); //вызов функции с передачей адреса объекта
    cout << "Введите текущую дату: " << endl;
    Today = Input(); //вызов функции возвращающей объект в результате своей работы
    //if(Today.Day==My_Birthday.Day&&Today.Year==My_Birthday.Year&&!strcmp(Today.Month,My_Birthday.Month)) //полное сравнение даты
    if (Today.Day == My_Birthday.Day && !_stricmp(Today.Month, My_Birthday.Month))
        cout << "Поздравляем с Днем рождения!" << endl;
    else cout << "Очень жаль, но сегодня не Ваш день рождения!" << endl;

}