#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


void signalHandler(int signum){
    int status;
    wait(&status);
    printf("Mi hijo termino con status\n %d", status);
}

void controlC(int signum){
    printf("hahahahah no me matas");
}

int main(int argc, char **argv) {
    // Numero de veces a ejecutar es igual a 2 ^ n -> n = numero de forks
    signal(17, signalHandler);
    signal(2, controlC);
    unsigned pid = fork();
    if (pid == 0) {
        sleep(5);
        printf("Soy el proceso hijo \n");
        //execv(argv[1], &argv[1]); // ejecuta el proceso especificado y remplaza todo el codigo restante
        return 10; // para manejo de errores
    }
    else {
        printf("Soy el proceso padre y mi hijo es %u\n", pid);

        while (1) {
            sleep(2);
            printf("trabajando \n");
        }
    }
        
    printf("Hola mundo \n");
    return 0;
}

