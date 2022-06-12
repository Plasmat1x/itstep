#include <iostream>

/*
“Написать программу учета сдачи зачетов при помощи битовых полей. 
Структура содержит поля: фамилия, группа, зачеты (битовое поле) и экзамены (битовое поле). 
Экзамены - 3 бита (значение от 1 до 5) зачеты - 1 бит(1 сдал, 0 не сдал). 
Создать трех студентов разной успеваемости и вывести данные о них на экран”
*/

struct Student
{
    //size 32
    char name[32];
    //size 8
    char group[8];

    //size <1
    unsigned short mathematicZ : 1;
    unsigned short languageZ : 1;
    unsigned short profile1Z : 1;
    unsigned short profile2Z : 1;

    //size >1
    unsigned short mathematicE : 3;
    unsigned short languageE : 3;
    unsigned short profile1E : 3;
    unsigned short profile2E : 3;

    //total 42
};

Student arr[3]{
    {"mike", "group01", 1,1,1,1, 5,5,5,5},
    {"alex", "group02", 0,1,0,1, 3,4,2,5},
    {"deni", "group03", 1,0,0,0, 3,2,2,2}
};

void printStud(Student s);

int main()
{

    for (int i = 0; i < 3; i++)
    {
        printStud(arr[i]);
    }

    return 0;
}

void printStud(Student s)
{
    std::cout << s.name << "   " << s.group << "\n";
    std::cout << "        Math, Language, profile1, profile2\n";
    std::cout << "zacheti: " << s.mathematicZ << ", " << s.languageZ << ", " << s.profile1Z << ", " << s.profile2Z << "\n";
    std::cout << "exameni: " << s.mathematicE << ", " << s.languageE << ", " << s.profile1E << ", " << s.profile2E << "\n";
    std::cout << std::endl;
}

