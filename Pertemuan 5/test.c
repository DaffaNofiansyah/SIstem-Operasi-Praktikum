#include <stdio.h>
#include <pthread.h>

void *hello(void *arg)
{
    printf("hello from thread %d\n", ((int *)arg)[0]);
    pthread_exit(NULL);
}
int main()
{
    pthread_t t;
    int id[] = {1};
    pthread_create(&t, NULL, hello, &id[0]);
    pthread_join(t, NULL);
    return 0;
}