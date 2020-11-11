#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv) {
    char *sourceFile = argv[1];
    char *destinationFile = argv[2];

    //int open("ruta al arcivo", modo, permisos) abir archivos

    int fd = open("./lee.c", O_RDONLY, 0);
    if (fd < 0) {
        printf("Error al abrir el archivo. \n");
        return -1; //error
    }
    int dFd = open(destinationFile, O_WRONLY | O_CREAT, 0600);

    char c;
    while (read(fd, &c, 1)) {
        write(dFd, &c, 1);
    }
    close(fd);
    close(dFd);
    return 0;

}
