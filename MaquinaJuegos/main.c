#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos de funciones
void mostrarBienvenida();
void mostrarMenu();
void limpiarPantalla();
void jugarAkineitor();
void jugarGato();
void jugarCuatroEnLinea();
void jugarMemorama();

// Función principal
int main() {
    int opcion;

    mostrarBienvenida();
    do {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarPantalla();
        switch (opcion) {
            case 1:
                jugarAkineitor();
                break;
            case 2:
                jugarGato();
                break;
            case 3:
                jugarCuatroEnLinea();
                break;
            case 4:
                jugarMemorama();
                break;
            case 5:
                printf("Saliendo del programa. ¡Hasta pronto!\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}

// Implementaciones de funciones

void mostrarBienvenida() {
    printf("===================================\n");
    printf("      BIENVENIDO A LA CONSOLA      \n");
    printf("===================================\n\n");
}

void mostrarMenu() {
    printf("\n========== MENU PRINCIPAL ==========\n");
    printf("1. Akineitor Numerico\n");
    printf("2. Gato\n");
    printf("3. Cuatro en Linea\n");
    printf("4. Memorama\n");
    printf("5. Salir\n");
    printf("====================================\n");
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void jugarAkineitor() {
    int nivel = 1, intentos = 7, numeroSecreto, guess;

    printf("¡Bienvenido a Akineitor Numerico!\n");
    srand(time(NULL)); // Semilla para números aleatorios

    while (nivel <= 5) {
        numeroSecreto = rand() % (nivel * 10) + 1; // Rango dinámico por nivel
        printf("Nivel %d: Adivina el numero entre 1 y %d.\n", nivel, nivel * 10);

        for (int i = 1; i <= intentos; i++) {
            printf("Intento %d/%d: ", i, intentos);
            scanf("%d", &guess);

            if (guess == numeroSecreto) {
                printf("¡Correcto! Has pasado al siguiente nivel.\n");
                nivel++;
                break;
            } else if (guess < numeroSecreto) {
                printf("Pista: El numero es mayor.\n");
            } else {
                printf("Pista: El numero es menor.\n");
            }

            if (i == intentos) {
                printf("¡Perdiste! El numero era %d. Nivel alcanzado: %d\n", numeroSecreto, nivel);
                return;
            }
        }
    }
    printf("¡Felicidades! Has completado todos los niveles.\n");
}

void jugarGato() {
    char tablero[3][3];
    int fila, columna, turno = 1, ganador = 0, modoJuego;
    char jugador;

    // Preguntar el modo de juego
    printf("Selecciona el modo de juego:\n");
    printf("1. Dos jugadores\n");
    printf("2. Contra la máquina\n");
    printf("Selecciona una opción: ");
    scanf("%d", &modoJuego);

    if (modoJuego != 1 && modoJuego != 2) {
        printf("Opción inválida. Regresando al menú principal.\n");
        return;
    }

    // Inicializar tablero
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tablero[i][j] = ' ';

    printf("¡Bienvenido al Juego del Gato!\n");
    while (ganador == 0 && turno <= 9) {
        limpiarPantalla();
        printf("Turno %d: ", turno);
        if (modoJuego == 2 && turno % 2 == 0) {
            printf("CPU (O)\n");
        } else {
            printf("Jugador %c\n", turno % 2 == 0 ? 'O' : 'X');
        }

        // Imprimir tablero
        printf("  0   1   2\n");
        for (int i = 0; i < 3; i++) {
            printf("%d", i);
            for (int j = 0; j < 3; j++) {
                printf(" %c ", tablero[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf(" ---+---+---\n");
        }

        jugador = turno % 2 == 0 ? 'O' : 'X';

        if (modoJuego == 2 && turno % 2 == 0) {
            // Movimiento de la CPU
            srand(time(NULL));
            do {
                fila = rand() % 3;
                columna = rand() % 3;
            } while (tablero[fila][columna] != ' '); // Buscar una posición válida
            printf("La CPU eligió: %d %d\n", fila, columna);
        } else {
            // Movimiento de los jugadores
            printf("Seleccione fila y columna (ejemplo: 0 1): ");
            scanf("%d %d", &fila, &columna);

            if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ') {
                printf("Movimiento inválido. Intente de nuevo.\n");
                continue;
            }
        }

        tablero[fila][columna] = jugador;

        // Verificar si hay un ganador
        for (int i = 0; i < 3; i++) {
            if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) ganador = 1;
            if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) ganador = 1;
        }
        if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ganador = 1;
        if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) ganador = 1;

        if (ganador) {
            limpiarPantalla();
            printf("¡Ganador: %c!\n", jugador);
            break;
        }
        turno++;
    }

    if (!ganador) {
        printf("¡Es un empate!\n");
    }
}


void jugarCuatroEnLinea() {
    printf("¡Juego de Cuatro en Linea en desarrollo!\n");
    // Aquí iría la lógica para el juego de Cuatro en Línea
}

void jugarMemorama() {
    printf("¡Juego del Memorama en desarrollo!\n");
    // Aquí iría la lógica para el Memorama
}

