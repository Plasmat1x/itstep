#include <iostream>

/*
“Написать программу "Видеосалон", содержащую: 
1. Структуру "Фильм" с полями: Название фильма, жанр, год выпуска и цена. 
2. Функции для работы с объектами структуры. 
3. Создать динамический массив объектов структуры, заполнить его с клавиатуры, 
    организовать в нем поиск по году или жанру с помощью функции работающими 
    с объектами структуры. Вывести результаты поиска на экран”
*/

struct Date
{
    unsigned short day = 0;
    unsigned short month = 0;
    int year = 0;
};

struct Film
{
    const char* name = "empty";
    const char* genre = "empty";
    Date date {0,0,0};
    unsigned short price = 0;
};

void printDate(Date date);
Date input(unsigned short day, unsigned short month, int year);
void printFilm(Film film);

int size = 10;
Film* arr = nullptr;

int main()
{
    arr = new Film[size];

    bool loop = true;
    while (loop)
    {
        system("cls");
        std::cout << "viedo market\n\n" << std::endl;
        //todo menu
        std::cout << R"(
1. Add film;
2. Film list;
2. Find film;
0. Exit;


)";
        //replece all input method on profile string input
        char input[255] {};
        std::cout << "Enter action: ";
        std::cin >> input;
        unsigned int iter = 0;
        switch (input[0])
        {
        default:
            std::cout << "invalid action" << std::endl;
            break;
        case '0':
            loop = false;
            break;
        case '1':
        {
            if (iter > 9)
            {
                std::cout << "cant add more films";
                break;
            }

            std::cout << "Enter film name: ";
            std::cin >> input; 
            arr[iter].name = input;

            std::cout << "Enter genre: ";
            std::cin >> input;
            arr[iter].genre = input;

            unsigned short u_input = 0;
            std::cout << "Enter date: \n";
            {
              
                int i_input = 0;
                std::cout << "Enter day: ";
                std::cin >> u_input;
                arr[iter].date.day = u_input;

                std::cout << "Enter month: ";
                std::cin >> u_input;
                arr[iter].date.month = u_input;

                std::cout << "Enter year: ";
                std::cin >> i_input;
                arr[iter].date.year = i_input;
            }

            std::cout << "Enter price: ";
            std::cin >> u_input;
            arr[iter].price = u_input;

            iter++;
        }
        break;
        case '2':
        {
            for (int i = 0; i < size; i++)
            {
                std::cout << i << ". " << arr[i].name << "   ";
                printDate(arr[i].date);
                std::cout << "\n";
            }
            system("pause");
        }
        break;
        case '3':
        {
           /*
           todo list:
           0. input string;
           1. sort algorithm
           2. search algorithm
           3. return finded data
           4. printFilm(searchResult);
           */    
        }
        break;
        }
    }

    delete[] arr;
    return 0;
}

Date input(unsigned short day, unsigned short month, int year)
{
    return Date{ day, month, year };
}

void printDate(Date date)
{
    std::cout << date.day << "." << date.month << "." << date.year;
}

void printFilm(Film film)
{
    std::cout << film.name << "\nGenre: " << film.genre << "\ndate: ";
    printDate(film.date);
    std::cout << "\nprice: " << film.price << std::endl;
}