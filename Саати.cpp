#include <iostream>
#include<string>
using namespace std;

int main()
{
    
    setlocale(LC_ALL, "rus");
    bool key;
    string amount;

    do                                 // Проверка строки данных на число
    {
        key = true;
        cout << "Введите количество критериев: ";
        cin >> amount;
        for (int i = 0; i < amount.length(); i++)
        {
            if ((!isdigit(amount[i])) and (amount[i] != '-'))
            {
                key = false;
                cout << "Вы ввели не число. Попробуйте ввести еще раз" << endl;
            }
        }
    } while (!key);
    float rows = std::stof(amount);

    float** arr = new float* [rows];   // Динамический двумерный массив данных попарного сравнения критериев
    float* arrSum = new float[rows];   // Динамический одномерный массив суммы строк

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new float[rows];
    }

    cout << "\nВведите данные попарного сравнения критериев!(десятичные числа записываются через точку)\n";
    for (int i = 0; i < rows; i++)    // Ввод с клавиатуры данных попарного сравнения критериев
    {
        for (int j = i; j < rows; j++)
        {
            if (i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                cout << i + 1 << "-й критерий по отношению к  ";
                cout << j + 1 << "-ому критерию: ";
                cin >> arr[i][j];
            }
        }
    }

    for (int i = rows - 1; i >= 1; --i)    // Ввод с клавиатуры данных попарного сравнения критериев
    {
        for (int j = i - 1; j >= 0; --j)
        {
            arr[i][j] = (1 / arr[j][i]);
        }
    }

    cout << "\nТаблица данных попарного сравнения критериев: \n";
    for (int i = 0; i < rows; i++)    // Вывод на экран массива данных попарного сравнения критериев
    {
        arrSum[i] = 0;
        for (int j = 0; j < rows; j++)
        {
            cout << arr[i][j] << "\t";
            arrSum[i] += arr[i][j];
        }
        cout << endl;
    }

    cout << "\nСумма по строкам\n";  // Подсчет суммы по строкам данных
    float arrSumO(NULL);
    for (int i = 0; i < rows; i++)
    {
        cout << i + 1 << "-й критерий: " << arrSum[i] << endl;
        arrSumO = arrSumO + arrSum[i];
    }
    cout << "\nОбщая сумма строк!\n"; // Подсчет общей суммы строк данных
    cout << arrSumO << endl;

    cout << "\nСумма всех весовых коэффициентов\n";
    float SumO;                       // Вывод суммы всех весовых коэффициентов 
    SumO = (arrSumO / arrSumO);
    cout << SumO << endl;

    cout << "\nВесовые коэффициенты каждого критерия\n";
    for (int i = 0; i < rows; i++)    // Вывод весовых коэффициентов каждого критерия
    {
        cout << i + 1 << "-й критерий: " << round(arrSum[i] / arrSumO * 100) / 100 << endl;
    }

    for (int i = 0; i < rows; i++)    // Освобождение памяти от динамических массивов
    {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] arrSum;
}