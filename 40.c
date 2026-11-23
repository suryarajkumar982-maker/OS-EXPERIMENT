/*
 * Experiment 16: Shared Memory (System V IPC)
 * Name: Manish. Y
 * Register Number: 1921260121
 */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shmid;
    char *str;

    shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);

    str = (char *)shmat(shmid, NULL, 0);

    printf("Enter a message: ");
    fgets(str, 100, stdin);

    printf("Message in shared memory: %s", str);

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
