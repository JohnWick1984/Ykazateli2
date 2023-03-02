// Ykazateli1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;


int Determ(int* ar, int SIZE)
{
    int k = SIZE;

    for (int i = 0;i <= k;i++)
    {

        int prov = 0;
        for (int j = i + 1;j <= k;j++)
        {
            if (*(ar + i) == *(ar + j) && prov == 0)
            {
                prov = 1;
            }
            else if (prov == 1)
            {
                *(ar + j - 1) = *(ar + j);
            }
            if (j == k && prov == 1)
            {
                *(ar + j) = *(ar + j) + 1;
            }
        }

        if (prov == 1)
        {
            k--;
            i--;
        }
    }
    return k;
}



int main()
{
        setlocale(0, "");
        srand(time(NULL));

        int size1 = 10;
        int size2 = 10;
        cout << " Введите размер первого массива " << endl;
        cin >> size1;

        cout << " Введите размер второго массива " << endl;
        cin >> size2;

        int* arr1 = new int[size1];
        int* arr2 = new int[size2];
        cout << "*****Первый массив  А[N]*******" << "\n";
        for (int i = 0; i < size1; i++)
        {
            arr1[i] = rand() % 10;
            cout << arr1[i] << " ";
        }
        cout << endl;
        int tmp1;

        for (int i = 0;i < (size1); i++)
        {
            for (int j = (size1 - 1);j > i;j--)
            {
                if (arr1[j] < arr1[j - 1])
                {
                    tmp1 = arr1[j];
                    arr1[j] = arr1[j - 1];
                    arr1[j - 1] = tmp1;
                }
            }
        }
        cout << "*****Второй массив  B[N]*******" << "\n";
        for (int i = 0; i < size2; i++)
        {
            arr2[i] = rand() % 10;
            cout << arr2[i] << " ";
        }
        cout << endl;
        int tmp2;

        for (int i = 0;i < (size2); i++)
        {
            for (int j = (size2 - 1);j > i;j--)
            {
                if (arr2[j] < arr2[j - 1])
                {
                    tmp2 = arr2[j];
                    arr2[j] = arr2[j - 1];
                    arr2[j - 1] = tmp2;
                }
            }
        }
        int* arr3 = new int[size1 + size2];

        cout << endl;


        int k = 0;
        int l = 0;

        for (int i = 0;i < size2;i++)
        {
            for (int j = 0;j < size1;j++)
            {
                if (*(arr2 + i) == *(arr1 + j))
                {
                    l++;

                }
            }
            if (l == 0)
            {
                *(arr3 + k) = *(arr2 + i);
                k++;
            }
            l = 0;
        }


        for (int i = 0;i < size1;i++)
        {
            for (int j = 0;j < size2;j++)
            {
                if (*(arr1 + i) == *(arr2 + j))
                {
                    l++;

                }
            }
            if (l == 0)
            {
                *(arr3 + k) = *(arr1 + i);
                k++;
            }
            l = 0;
        }

        k--;

        k = Determ(arr3, k);

        cout << "******Элементы, которые не являются общими для  А и В********** " << endl;

        for (int i = 0; i <= k; i++)
        {
            cout << *(arr3 + i) << " ";
        }
        cout << endl;

        return 0;


}
