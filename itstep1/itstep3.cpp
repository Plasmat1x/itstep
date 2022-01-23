#include <iostream>
#include <cstdlib>

void secPart();
void lab();

int main(int argc, char* argv[])
{
    system("chcp 1251");
    system("cls");

    //int A = 0;                                    // переменная = литерал
    //long A = 15L                                  // long
    //auto A = 15.f                                 // float
    //auto A = 15.                                  // double
    //auto A = 15                                   // int
    //bool C = true;                                // true - литерал
    //bool c = 0;                                   // false
    //bool c = 1;                                   // true
    //double D = .256;                              // 0.256...
    //double F = 3.9e-2;                            // exp double
    //double F = 3.9e-2f;                           // exp float
    //char H = 'A';                                 // '' символьный литерал
    //const char[] = "Hello, World!"                // "" строковый литерал
    //arithmetic operators:       + - * / % 

    /*
    int A = 5, B = 3;
    A = (B + 1) / 5

    -3;
    -(-3);
    A + B;

    int A;
    A = A + 10; //A=5+10 //A=15
    cout << "Переменная А: " << A << endl;
    A++;   //аналогично A = A + 1; оператор инкремент
    cout << "Переменная А: " << A << endl;
    A--; //оператор декремент аналогично A = A - 1;
    cout << "Переменная А: " << A << endl;
    ++A;  //префиксная форма оператора инкремент
    cout << "Переменная А: " << A << endl;
    A = 10; //оператор присваивания, перезаписывает прошлое содержимое переменной
    system("cls"); //очистка экрана консоли
    cout << "Переменная А: " << A << endl;
    cout << "Переменная А++: " << A++ << endl;
    cout << "Переменная А: " << A << endl;
    cout << "Переменная ++A: " << ++A << endl;
    cout << "Переменная А: " << A << endl; //A=12
    B = A++; //B=A; A=A+1; //постфиксная форма оператора инкремент сначала
    //переменной B будет присвоено текущее значение переменной А
    //потом значение переменной А будет увеличено на 1
    cout << "Переменная А: " << A << endl;
    cout << "Переменная B: " << B << endl;
    //A=13     //A+B*C    //(A+B)*C
    B = ++A; //A=A+1; B=A; //префиксная форма оператора инкремент сначала
    //текущее значение переменной А будет увеличено на 1
    //потом переменной B будет присвоено новое значение переменной А
    cout << "Переменная А: " << A << endl;
    cout << "Переменная B: " << B << endl;
    A--; //постфиксная форма оператора декремент
    --A; //префиксная форма оператора декремент
    cout << "A%5= " << A % 5 << endl;
    cout << B % 2 << endl; //остаток от деления значения переменной B на 2 определит четное ли
    //значение находится в переменной В или нет
    //*/

    secPart();
    lab();

    return 0;
}

using namespace std;

void secPart()
{
    //иерархия типов данных
    //bool, char, short, unsigned short, int, unsigned int, long, unsigned long
    //long int, unsigned long int, long long, unsigned long long, float, double, long double

    //(double)D // явное преобразование значения переменной D к типу данных double 
    //(тип пременной не меняет), работет там где использованно
    //double(D) // неправильная запись, переиницализация

    //     2       3       1
    // int - float + short * bool
    //                     1. short * bool = short
    //     2. int - float = float
    //             3. float + short = float

    unsigned int A = 3000000000; //unsigned выполнит расширяющее преобразование
    cout << "A= " << A << endl;
    int B = 3.14; //неявное сужающее преобразование литерала(double) к целому типу данных int, отбросит дробную часть
    cout << "B= " << 3 << endl;
    float C = 3.14; //неявное сужающее преобразование от типа данных double к типу данных float
    int D = 1;
    //преобразование типов данных в выражениях
    cout << "D/B= " << (double)D / B << endl; //double/int=double
    //(double)D - явное преобразование значения пременной D к типу данных double
    double E = (float)D / (double)B; //float/double=double
    //явное преобразование(приведение) типов данных, результат будет старшего типа данных (double)
    //сработает только там, где использовано,  переменные D и B останутся типа даннхы int
    cout << "E=" << E << endl; //int/int=int   double=int
    //    2       3       1
    //int - float + short * bool
    //1 short*bool=short
    //2 int-float=float
    //3 float+short=float
    float G = D / 2.0F; //(float)D/2;  int/float=float
    //неявное преобразование результата к нужному типу данных(float) 
    //использованием литерала нужного тпа данных (float)
    cout << "G= " << G << endl;
    double H = ((D / 10) + E) * G;
    cout << "H=" << H << endl;
    //     I    II     III
    //((int/int)+double)*float
    //I   int/int=int          1/10=0
    //II  int+double=double   0+0.33333=0.33333
    //III double*float=double 0.3333*0.5=0.166667
    H = (((double)D / 10) + E) * G;
    cout << "H=" << H << endl;
    //     I    II     III
    //((double/int)+double)*float
    //I   double/int=double          1/10=0.1
    //II  double+double=double   0.1+0.33333=0.43333
    //III double*float=double 0.4333*0.5=0.216667
    H = ((D / 10.0) + E) * G;
    cout << "H=" << H << endl;
    //     I    II     III
    //((int/double)+double)*float
    //I   int/double=double          1/10=0.1
    //II  double+double=double   0.1+0.33333=0.43333
    //III double*float=double 0.4333*0.5=0.216667

}

void lab()
{

}