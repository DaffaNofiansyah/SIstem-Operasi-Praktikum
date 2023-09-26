#include <stdio.h>
#include <pthread.h>
#define N 16

int sum = 0;

void *array_sum(void *A)
{
    int *arr = (int *)A;
    for (int i = 0; i < N / 4; i++)
    {
        sum += arr[i];
    }
    pthread_exit(NULL);
}

int main()
{
    int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
                51, 67, 7, 77, 4, 73, 52, 91};
    /* TODO: array sum */
    pthread_t t[N / 4];
    for (int i = 0; i < N / 4; i++)
    {
        pthread_create(&t[i], NULL, array_sum, &A[i * 4]);
    }
    for (int i = 0; i < N / 4; i++)
    {
        pthread_join(t[i], NULL);
    }
    printf("%d\n", sum); /* 954 */
    return 0;
}