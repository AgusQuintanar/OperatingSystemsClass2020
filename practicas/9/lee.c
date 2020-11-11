#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    //int open("ruta al arcivo", modo, permisos) abir archivos

    int fd = open("./lee.c", O_RDONLY, 0);
    if (fd < 0) {
        printf("Error al abrir el archivo. \n");
        return -1; //error
    }
    char c;
    while (read(fd, &c, 1)) {
        printf("%c", c);
    }
    close(fd);
    return 0;

}