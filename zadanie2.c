#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Podaj liczbe N jako argument\n");
        return 1;
    }

    int N = atoi(argv[1]);

    for (int i=0;i<N;i++) {
        pid_t pid = fork();
        if(pid == 0) {
            printf("Jestem potomkiem moj pid: %d, a pid mojego rodzica to: %d\n", getpid(), getppid());
            exit(i);
        }
    }
    for(int i=0;i<N;i++) {
        int status;
        wait(&status);
        if(WIFEXITED(status)) {
            printf("Potomek zakonczyl sie kodem %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}