#include <iostream>
#include <algorithm>
#include <utility>

// Эта функция выводит значения массива


void selectionSort(int* array, int size, bool (*comparsionFcn)(int, int))
{
    // Перебираем каждый элемент массива
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // smallestIndex - это индекс наименьшего элемента, который мы обнаружили до этого момента
        int bestIndex = startIndex;

        // Ищем наименьший элемент среди оставшихся в массиве (начинаем со startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // Если текущий элемент меньше нашего предыдущего найденного наименьшего элемента,
            if (comparsionFcn(array[bestIndex], array[currentIndex])) // СРАВНЕНИЕ ВЫПОЛНЯЕТСЯ ЗДЕСЬ
                // то это наш новый наименьший элемент в этой итерации
                bestIndex = currentIndex;
        }

        // Меняем местами наш стартовый элемент с найденным наименьшим элементом
        std::swap(array[startIndex], array[bestIndex]);
    }
}

// Вот функция сравнения, которая выполняет сортировку в порядке возрастания (обратите внимание, это та же функция ascending(), что и в примере, приведенном выше)
bool ascending(int a, int b)
{
    return a > b; // меняем местами, если первый элемент больше второго
}

// Вот функция сравнения, которая выполняет сортировку в порядке убывания
bool descending(int a, int b)
{
    return a < b; // меняем местами, если второй элемент больше первого
}

void printArray(int* array, int size)
{
    for (int index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << '\n';
}

int main()
{
    int array[8] = { 4,8,5,6,2,3,1,7 };

    selectionSort(array, 8, descending);
    printArray(array, 8);

    selectionSort(array, 8, ascending);
    printArray(array, 8);

    return 0;
}

/*

int boo()
{
    return 7;
}

int doo()
{
    return 8;
}

int moo(int a)
{
    return a;
}

int main()
{

    std::cout << boo << std::endl;

    int (*fcnPtr)() = boo;
    fcnPtr = doo;

    int (*fcnPtr1)(int) = moo;
    (*fcnPtr1)(7);
    fcnPtr1(8);

    std::cout << fcnPtr1(8) << std::endl;

    return 0;
}

*/