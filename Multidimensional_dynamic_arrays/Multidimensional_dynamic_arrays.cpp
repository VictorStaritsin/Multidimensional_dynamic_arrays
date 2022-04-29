///*
//Задание 1. Написать функцию, добавляющую столбец
//двухмерному массиву в указанную позицию.
//
//Задание 2. Написать функцию, удаляющую столбец
//двухмерного массива по указанному номеру.
//*/
//
//#include <iostream>
//
//using namespace std;
//
//void fillMassiv(int** pArray, int rowCount, int columnCount);
//void printArray(int** pArray, int rowCount, int columnCount);
//void addColumn(int** pArray, int rowCount, int columnCount, int index);
//void deleteColumn(int** pArray, int rowCount, int columnCount, int index);
//
//int main()
//{
//    setlocale(LC_ALL, "Rus");
//    int const rowCount = 3;
//    int const startColumnCount = 10;
//    int columnCount = 3;
//    int userIndex;
//    int** simpleArray = new int* [rowCount];
//    for (int i = 0; i < rowCount; i++)
//    {
//        simpleArray[i] = new int[startColumnCount];
//    }
//    fillMassiv(simpleArray, rowCount, columnCount);
//    cout << "Начало массива: " << endl;
//    printArray(simpleArray, rowCount, columnCount);
//    //столбец можно добавить как в середину, так и в конец массива. поэтому 0...3
//    cout << "Введи индекс 0..." << columnCount << "  куда хотите поставить столбец: ";
//    cin >> userIndex;
//    if (userIndex >= 0 && userIndex <= columnCount)
//    {
//        columnCount++;
//        addColumn(simpleArray, rowCount, columnCount, userIndex);
//        printArray(simpleArray, rowCount, columnCount);
//    }
//    else
//    {
//        cout << "Неправельное значение" << endl;
//    }
//    //удаление столбца
//    cout << "Введи индекс 0..." << columnCount - 1 << " какой столбец вы хотите удалить: ";
//    cin >> userIndex;
//    if (userIndex >= 0 && userIndex < columnCount)
//    {
//        deleteColumn(simpleArray, rowCount, columnCount, userIndex);
//        columnCount--;
//        printArray(simpleArray, rowCount, columnCount);
//    }
//    else
//    {
//        cout << "Неправельное значение" << endl;
//    }
//    //удаление массива
//    for (int i = 0; i < rowCount; i++)
//    {
//        delete[] simpleArray[i];
//    }
//    delete[] simpleArray;
//}
////инициализация массива
//void fillMassiv(int** pArray, int rowCount, int columnCount)
//{
//    if (pArray == nullptr)
//    {
//        cout << "Ошибка!" << endl;
//        return;
//    }
//
//    int value = 1;
//    for (int i = 0; i < rowCount; i++)
//    {
//        for (int j = 0; j < columnCount; j++)
//        {
//            pArray[i][j] = value;
//            value++;
//        }
//    }
//}
////вывод массива на экран
//void printArray(int** pArray, int rowCount, int columnCount)
//{
//    if (pArray == nullptr)
//    {
//        cout << "Ошибка!" << endl;
//        return;
//    }
//
//    for (int i = 0; i < rowCount; i++)
//    {
//        for (int j = 0; j < columnCount; j++)
//        {
//            cout << pArray[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
////добавление столбца
//void addColumn(int** pArray, int rowCount, int columnCount, int index)
//{
//    if (pArray == nullptr)
//    {
//        cout << "Ошибка!" << endl;
//        return;
//    }
//
//    for (int i = 0; i < rowCount; i++)
//    {
//        for (int j = 0; j < columnCount; j++)
//        {
//            //сдвигаем вправо значения
//            if (j == index)
//            {
//                for (int k = columnCount; k > index; k--)
//                {
//                    pArray[i][k] = pArray[i][k - 1];
//                }
//                //заполняем вставленный столбец 0ми
//                pArray[i][j] = 0;
//            }
//        }
//    }
//}
////удаление столбца
//void deleteColumn(int** pArray, int rowCount, int columnCount, int index)
//{
//    if (pArray == nullptr)
//    {
//        cout << "Ошибка!" << endl;
//        return;
//    }
//
//    for (int i = 0; i < rowCount; i++)
//    {
//        //j < columnCount, чтобы в крайний правый столбец записался мусор,
//        //который до этого был справа, а не осталось правильное значение как до удаления.
//        for (int j = index; j < columnCount; j++)
//        {
//            pArray[i][j] = pArray[i][j + 1];
//        }
//    }
//}

/*
Задание 3. Дана матрица порядка M×N (M строк, N столбцов).
Необходимо заполнить ее значениями и написать
функцию, осуществляющую циклический сдвиг строк
и/или столбцов массива указанное количество раз и в указанную сторону
*/

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int** Create2D(int n, int m)
{
    int** mas = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        mas[i] = (int*)calloc(m, sizeof(int));
    }
    return mas;
}

void Delete2D(int** mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(mas[i]);
    }
    free(mas);
}

void InitArray(int** mas, int n, int m)
{
    for (int i = 0, k = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mas[i][j] = k;//*(*(mas+i)+j)
            k++;
        }
        k = k + 1 - m;
    }
}

void ShowArray(int** mas, int n, int m)
{
    cout << "\n";
    int h = 5 * m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(4) << mas[i][j] << "|";
        }
        cout << "\n";
        for (int i = 0; i < h; i++)
        {
            cout << '-';
        }
        cout << "\n";
    }
    cout << "\n";
}

void ShiftArray(int** mas, int n, int m, char direc, short shift)
{
    int** arr = Create2D(n, m);
    switch (direc)
    {
        /* Если сдвиг влево */
    case 'l':

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((shift + j - m) < 0)
                {
                    arr[i][j] = mas[i][j + shift];
                }
                else
                {
                    arr[i][j] = mas[i][shift + j - m];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mas[i][j] = arr[i][j];
            }
        }
        Delete2D(arr, n);
        break;
        /* Если сдвиг вправо */
    case 'r':
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (m - shift + j > m - 1)
                {
                    arr[i][j] = mas[i][j - shift];
                }
                else
                {
                    arr[i][j] = mas[i][m - shift + j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mas[i][j] = arr[i][j];
            }
        }
        Delete2D(arr, n);
        break;
        /* Если сдвиг вниз */
    case 'd':
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (n - shift + i > n - 1)
                {
                    arr[i][j] = mas[i - shift][j];
                }
                else
                {
                    arr[i][j] = mas[n - shift + i][j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mas[i][j] = arr[i][j];
            }
        }
        Delete2D(arr, n);
        break;
        /* Если сдвиг вверх */
    case 'u':
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (shift + i - n < 0)
                {
                    arr[i][j] = mas[i + shift][j];
                }
                else
                {
                    arr[i][j] = mas[shift + i - n][j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mas[i][j] = arr[i][j];
            }
        }
        Delete2D(arr, n);
    default:
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int row, column;
    int** mas;
    cout << "Введи количество строк ";
    cin >> row;
    cout << "Введи количество столбцов ";
    cin >> column;
    mas = Create2D(row, column);
    InitArray(mas, row, column);
    cout << "\nИсходный массив:\n";
    ShowArray(mas, row, column);
    cout << "Строки = " << row << "\nСтолбцы = " << column << "\n\n";
    char ch;// верх, низ, лево, право
    short sh;// кол-во сдвигов
    cout << "Введи количество замен ";
    cin >> sh;
    cout << "Введи направление:\n";
    cout << "l - на лево;\n"
        "r - на право;\n"
        "u - вверх;\n"
        "d - вниз.\n";
    cin >> ch;
    ShiftArray(mas, row, column, ch, sh);
    ShowArray(mas, row, column);
    Delete2D(mas, row);
    return 0;
}