

#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;


int const n = 5;
int mas[n][n];
int count_double_digit = 0;

void loop()
{
    srand(time(0));
    int a = rand() % 999 - 0;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 999 - 0;
        mas[0][i] = a;
        cout << mas[0][i] << " ";
        if ((mas[0][i] > 9) && (mas[0][i] < 100)) 
        {
            count_double_digit++;
        }
        
    }
    cout << endl;
}
void loop1()
{
    srand(time(0));
    int a = rand() % 999 - 0;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 999 - 0;
        mas[1][i] = a;
        cout << mas[1][i] << " ";
        if ((mas[1][i] > 9) && (mas[1][i] < 100))
        {
            count_double_digit++;
        }
    }
    cout << endl;
}
void loop2()
{
    srand(time(0));
    int a = rand() % 999 - 0;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 999 - 0;
        mas[2][i] = a;
        cout << mas[2][i] << " ";
        if ((mas[2][i] > 9) && (mas[2][i] < 100))
        {
            count_double_digit++;
        }
    }
    cout << endl;
}
void loop3()
{
    srand(time(0));
    int a = rand() % 999 - 0;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 999 - 0;
        mas[3][i] = a;
        cout << mas[3][i] << " ";
        if ((mas[3][i] > 9) && (mas[3][i] < 100))
        {
            count_double_digit++;
        }
    }
    cout << endl;
}
void loop4()
{
    srand(time(0));
    int a = rand() % 999 - 0;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 999 - 0;
        mas[4][i] = a;
        cout << mas[4][i] << " ";
        if ((mas[4][i] > 9) && (mas[4][i] < 100))
        {
            count_double_digit++;
        }
    }
    cout << endl;
}
int main()
{
    int max = 0;
    int min = 1000;

    thread th(loop);
    th.join();
    Sleep(1000);
    thread th1(loop1);
    th1.join();
    Sleep(1000);
    thread th2(loop2);
    th2.join();
    Sleep(1000);
    thread th3(loop3);
    th3.join();
    Sleep(1000);
    thread th4(loop4);
    th4.join();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[i][j] > max)
            {
                max = mas[i][j];
            }

            if (mas[i][j] < min)
            {
                min = mas[i][j];
            }
        }
    }
    setlocale(LC_ALL, "Ukrainian");
    cout << "Количество 2-значных чисел: " << count_double_digit <<endl;
    cout << "Максимальное: " << max << endl << "Минимальное: " << min << endl;
    return 0;
}