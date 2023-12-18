#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int* full_array(int* ptrarr, int size);
int put_array(int* ptrarr, int size);
void sort_insert(int* ptrarr, int size);

int main() 
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int* ptrarr;
    int size;
    printf("Введите размер массива > ");
    scanf("%d", &size);
    ptrarr = (double*)malloc(size * sizeof(double));
    if (ptrarr == NULL) 
    {
       puts("error");
       return -1;
    }
    full_array(ptrarr, size);
    clock_t t;
    t = clock();
    sort_insert(ptrarr, size);
    double time = (clock() - t) * 1.0 / CLOCKS_PER_SEC;
    printf("Отсортированный массив: ");
    put_array(ptrarr, size);
    printf("Время выполнения сортировки: %f секунд\n", time);
    free(ptrarr);
}

int* full_array(int* ptrarr, int size)
{
    for (int i = 0; i < size; i++)
    {
        ptrarr[i] = rand() % 100;
    }
    return ptrarr;
}

int put_array(int* ptrarr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", ptrarr[i]);
    }
    printf("\n");
}

void sort_insert(int* ptrarr, int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = ptrarr[i];
        j = i - 1;

        while (j >= 0 && ptrarr[j] > key) {
            ptrarr[j + 1] = ptrarr[j];
            j = j - 1;
        }

        ptrarr[j + 1] = key;
    }
}