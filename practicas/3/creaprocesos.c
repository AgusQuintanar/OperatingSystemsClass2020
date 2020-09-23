#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    // Numero de veces a ejecutar es igual a 2 ^ n -> n = numero de forks
    unsigned pid = fork();
    if (pid == 0) {
        printf("Soy el proceso hijo \n");
        execv(argv[1], &argv[1]); // ejecuta el proceso especificado y remplaza todo el codigo restante
        return 10;
    }
    else {
        int status;
        printf("Soy el proceso padre y mi hijo es %u\n", pid);
        // hacer mas cosas
        //sleep(4); // simulacion de asincrono
        //
        wait(&status);
        printf("Terminando despues del hijo y estatus %p\n", status);

    }
    printf("Hola mundo \n");
    return 0;
}

