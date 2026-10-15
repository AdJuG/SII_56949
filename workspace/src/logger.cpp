#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

struct MensajePunto {
    int idJugador;
    int puntos;
    bool finJuego;
};

#define X1 "/tmp/fifo_tenis"  // Nombre/ruta de la FIFO
#define X2 X1, 0666 // Ruta y permisos para mkfifo
#define X3 (fd = open(X1, O_RDONLY)) < 0  // Apertura lectura y comprobación de error
#define X4 read(fd, &msg, sizeof(struct MensajePunto)) > 0  // Bucle lectura de datos
#define X5 fd // Descriptor archivo para close
#define X6 X1 // Ruta FIFO para unlink

int main(int argc, char **argv) {
    int fd;
    struct MensajePunto msg;

    // borrar FIFO por si existiera previamente
    unlink(X1);

    /* crear el FIFO */
    if (mkfifo(X2)<0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO */
    if (X3) {
        perror("No puede abrirse el FIFO");
        return(1);
    }
    /* Leer de la FIFO */
    while (X4) {
	printf("Jugador %d marca 1 punto, lleva un total de %d puntos.\n", msg.idJugador, msg.puntos);

        if (msg.finJuego || msg.puntos >= 3) {
            printf("El Jugador %d ha alcanzado 3 puntos. Finalizando logger...\n", msg.idJugador);
            break;
        }
    }
    close(X5);
    unlink(X6);
    return(0);
}
