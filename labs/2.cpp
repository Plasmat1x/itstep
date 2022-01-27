#include <iostream>
#include <iomanip>
#include <locale>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "windows-1256");

    //Задание 1
    std::cout << "Куплет из песни \"ТЫЖПРОГРАММИСТ\", исполнитель HTP" << std::endl;
    std::cout << std::endl
    << "Тыжпрограммист - защитник планеты\n"
    << "Чинит всё, от холодильника до лыж\n"
    << "Процессор не включается, или интернета нету\n"
    << "Срочно посылай в космос сигнал \"Тыж\"\n"
    << "Тыж-тыж-тыж программист\n"
    << "Тыж-тыж-тыж программист\n"
    << "Тыж-тыж-тыж программист\n"
    << "Тыж-тыж-тыж программист\n"
    << std::endl;


    //Задание 2
    std::cout << "Каждый охотник желает знать где сидит фазан." << std::endl;
    std::cout 
    << "К - красный - (Каждый)\n" 
    << "\tО - оранжевый - (охотник)\n" 
    << "\t\tЖ - желтый - (желает)\n"
    << "\t\t\tЗ - зеленый - (знать)\n"
    << "\t\t\t\tГ - голубой - (где)\n"
    << "\t\t\t\t\tС - синий - (сидит)\n"
    << "\t\t\t\t\t\tФ - фиолетовый - (фазан)\n"
    << std::endl;

    //Задание 3
    std::cout << "|" << std::setfill('=') << std::setw(20) << "|" << std::endl;
    std::cout << "|" << std::setfill(' ') << std::setw(20) << "-Срочно продам код-" << "|" << std::endl;
    std::cout << "|" << std::setfill(' ') << std::setw(20) << "т.8(800)-555-35-35" << "|" << std::endl;
    std::cout << "|" << std::setfill('=') << std::setw(20) << "|" << std::endl;
    std::cout << std::setfill(' ');
    for(int str = 0; str < 6; str++)
    {
        for(int tab = 0; tab < 5; tab++)
        {
            switch(str)
            {
                case 0:
                {
                    std::cout << "|" << std::setw(3) << "8";
                    break;
                }
                case 1:
                {
                    std::cout << "|" << std::setw(3) << "800";
                    break;
                }
                case 2:
                {
                    std::cout << "|" << std::setw(3) << "555";
                    break;
                }
                case 3:
                {
                    std::cout << "|" << std::setw(3) << "35";
                    break;
                }
                case 4:
                {
                    std::cout << "|" << std::setw(3) << "35";
                    break;
                }
                case 5:
                {
                    std::cout << "|" << std::setfill('-') << std::setw(4);
                    break;
                }
            }
        }
        std::cout << "|" << std::endl << std::setfill(' ');
    }
    std::cout << std::endl;
        
    return 0;
}