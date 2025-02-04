#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// primerosPrototipos
void limpiarPantalla();
void jugarGato();
void jugarCuatroEnLinea();
void jugarMemorama();
void jugarAkineitor();
void juegoAleatorio();


int main() {
    int opcion;

    do {
        limpiarPantalla();
        printf("========== CONSOLA DE VIDEOJUEGOS ==========\n");
        printf("1. Gato\n");
        printf("2. Cuatro en Línea\n");
        printf("3. Memorama\n");
        printf("4. Akineitor Numérico\n");
        printf("5. Juego Aleatorio\n");
        printf("6. Salir\n");
        printf("============================================\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                jugarGato();
                break;
            case 2:
                jugarCuatroEnLinea();
                break;
            case 3:
                jugarMemorama();
                break;
            case 4:
                jugarAkinatorNumerico();
                break;
            case 5:
                juegoAleatorio();
                break;
            case 6:
                printf("Gracias por jugar. ¡Hasta la próxima!\n");
                break;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
                sleep(2);
                break;
        }
    } while (opcion != 6);

    return 0;
}

// limpiar pantalla
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// casiTerminado
void jugarGato() {
    int modo, turno = 1;
    char tablero[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int fila, columna;
    int ganador = 0;

    printf("Selecciona el modo de juego:\n");
    printf("1. Dos jugadores\n");
    printf("2. Contra la CPU\n");
    scanf("%d", &modo);

    while (!ganador) {
        limpiarPantalla();
        printf("   0   1   2\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", i);
            for (int j = 0; j < 3; j++) {
                printf(" %c ", tablero[i][j]);
                if (j < 2) printf("|");
            }
            if (i < 2) printf("\n  ---|---|---\n");
            else printf("\n");
        }

        if (turno % 2 == 1 || modo == 1) {
            printf("Turno del jugador %d\n", (turno % 2) ? 1 : 2);
            printf("Ingresa fila y columna (ej: 0 1): ");
            scanf("%d %d", &fila, &columna);
        } else {
            printf("Turno de la CPU\n");
            srand(time(NULL));
            do {
                fila = rand() % 3;
                columna = rand() % 3;
            } while (tablero[fila][columna] != ' ');
        }

        if (tablero[fila][columna] == ' ') {
            tablero[fila][columna] = (turno % 2) ? 'X' : 'O';
            turno++;
        } else {
            printf("Casilla ocupada. Intenta de nuevo.\n");
            sleep(1);
        }

        // Verificar ganador
        for (int i = 0; i < 3; i++) {
            if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
                ganador = (tablero[i][0] == 'X') ? 1 : 2;
            if (tablero[0][i] != ' ' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
                ganador = (tablero[0][i] == 'X') ? 1 : 2;
        }
        if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
            ganador = (tablero[0][0] == 'X') ? 1 : 2;
        if (tablero[0][2] != ' ' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
            ganador = (tablero[0][2] == 'X') ? 1 : 2;

        if (turno > 9 && !ganador) {
            printf("¡Empate!\n");
            break;
        }
    }

    if (ganador) printf("¡El jugador %d gana!\n", ganador);
}

// cuatroenLinea EnProceso........
void jugarCuatroEnLinea() {
    int columna, fila, i, j, ganador = 0;
    char tablero[6][7] = { {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '} };
    int modo, turno = 1;

    printf("Selecciona el modo de juego:\n");
    printf("1. Dos jugadores\n");
    printf("2. Contra la CPU\n");
    scanf("%d", &modo);

    while (!ganador) {
        limpiarPantalla();
        printf("   0   1   2   3   4   5   6\n");
        for (i = 0; i < 6; i++) {
            printf("  ");
            for (j = 0; j < 7; j++) {
                printf(" %c ", tablero[i][j]);
                if (j < 6) printf("|");
            }
            if (i < 5) printf("\n  ---|---|---|---|---|---|---\n");
            else printf("\n");
        }

        if (turno % 2 == 1 || modo == 1) {
            printf("Turno del jugador %d\n", (turno % 2) ? 1 : 2);
            printf("Selecciona la columna (0-6): ");
            scanf("%d", &columna);
        } else {
            printf("Turno de la CPU\n");
            srand(time(NULL));
            do {
                columna = rand() % 7;
            } while (tablero[0][columna] != ' ');
        }

        // Verificar la fila disponible para la columna seleccionada
        for (fila = 5; fila >= 0; fila--) {
            if (tablero[fila][columna] == ' ') {
                tablero[fila][columna] = (turno % 2) ? 'X' : 'O';
                break;
            }
        }

        // Verificar si se ha alcanzado el límite de la columna
        if (fila == -1) {
            printf("Columna llena. Intenta de nuevo.\n");
            sleep(1);
            continue;
        }

        turno++;

        // Verificar ganador
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 7; j++) {
                if (tablero[i][j] != ' ') {
                    // Comprobar horizontal
                    if (j < 4 && tablero[i][j] == tablero[i][j+1] && tablero[i][j] == tablero[i][j+2] && tablero[i][j] == tablero[i][j+3]) {
                        ganador = (tablero[i][j] == 'X') ? 1 : 2;
                    }
                    // Comprobar vertical
                    if (i < 3 && tablero[i][j] == tablero[i+1][j] && tablero[i][j] == tablero[i+2][j] && tablero[i][j] == tablero[i+3][j]) {
                        ganador = (tablero[i][j] == 'X') ? 1 : 2;
                    }
                    // Comprobar diagonal (de abajo hacia arriba)
                    if (i < 3 && j < 4 && tablero[i][j] == tablero[i+1][j+1] && tablero[i][j] == tablero[i+2][j+2] && tablero[i][j] == tablero[i+3][j+3]) {
                        ganador = (tablero[i][j] == 'X') ? 1 : 2;
                    }
                    // Comprobar diagonal (de arriba hacia abajo)
                    if (i > 2 && j < 4 && tablero[i][j] == tablero[i-1][j+1] && tablero[i][j] == tablero[i-2][j+2] && tablero[i][j] == tablero[i-3][j+3]) {
                        ganador = (tablero[i][j] == 'X') ? 1 : 2;
                    }
                }
            }
        }

        if (turno > 42 && !ganador) {
            printf("¡Empate!\n");
            break;
        }
    }

    if (ganador) printf("¡El jugador %d gana!\n", ganador);
}


//Memorama EnProceso........
void jugarMemorama() {
    int filas = 5, columnas = 6;
    char cartas[filas][columnas];
    char cartasDescubiertas[filas][columnas];
    int i, j, turno = 1, jugador = 1, x1, y1, x2, y2, puntos1 = 0, puntos2 = 0;
    int emparejadas = 0;
    char cartasGeneradas[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
    int cartasDisponibles[30] = {0};

    // Inicializar cartas con espacio vacío
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            cartas[i][j] = ' ';
            cartasDescubiertas[i][j] = ' ';
        }
    }

    // Generar cartas aleatorias
    srand(time(NULL));
    for (i = 0; i < 30; i++) {
        int cartaElegida;
        do {
            cartaElegida = rand() % 15;
        } while (cartasDisponibles[cartaElegida] >= 2); // Asegurarse de no repetir una carta más de dos veces

        cartasDisponibles[cartaElegida]++;
        if (cartasDisponibles[cartaElegida] == 1) {
            cartas[i / columnas][i % columnas] = cartasGeneradas[cartaElegida];
        } else {
            for (int k = i; k >= 0; k--) { // Asegurar que el segundo par de cartas esté bien colocado
                if (cartas[k / columnas][k % columnas] == ' ') {
                    cartas[k / columnas][k % columnas] = cartasGeneradas[cartaElegida];
                    break;
                }
            }
        }
    }

    // Función para mostrar el tablero
    void mostrarTablero() {
        printf("\n");
        for (i = 0; i < filas; i++) {
            for (j = 0; j < columnas; j++) {
                printf(" %c ", cartasDescubiertas[i][j]);
                if (j < columnas - 1) printf("|");
            }
            printf("\n");
            if (i < filas - 1) printf(" ---|---|---|---|---|---\n");
        }
        printf("\n");
    }

    // Función para manejar la selección de cartas
    void seleccionarCartas() {
        printf("Jugador %d, selecciona las dos cartas (filas y columnas) para voltear: ", jugador);
        printf("\nPrimer carta (ejemplo: 0 1): ");
        scanf("%d %d", &x1, &y1);

        printf("Segunda carta (ejemplo: 0 1): ");
        scanf("%d %d", &x2, &y2);

        // Validación de las posiciones
        if (x1 == x2 && y1 == y2) {
            printf("No puedes seleccionar la misma carta dos veces.\n");
            sleep(1);
            return;
        }
        if (cartasDescubiertas[x1][y1] != ' ' || cartasDescubiertas[x2][y2] != ' ') {
            printf("Ya has descubierto esas cartas, elige otras.\n");
            sleep(1);
            return;
        }

        // Voltear las cartas seleccionadas
        cartasDescubiertas[x1][y1] = cartas[x1][y1];
        cartasDescubiertas[x2][y2] = cartas[x2][y2];

        mostrarTablero();

        // Comprobar si las cartas son iguales
        if (cartas[x1][y1] == cartas[x2][y2]) {
            printf("¡Bien hecho! Las cartas coinciden.\n");
            if (jugador == 1) puntos1 += 10;
            else puntos2 += 10;
            emparejadas += 2; // Dos cartas emparejadas
        } else {
            printf("¡Intenta de nuevo! Las cartas no coinciden.\n");
            sleep(2); // Mostrar las cartas por 2 segundos
            cartasDescubiertas[x1][y1] = ' ';
            cartasDescubiertas[x2][y2] = ' ';
            jugador = (jugador == 1) ? 2 : 1; // Cambiar de turno
        }
    }

    // Función para el temporizador
    void temporizador(int segundos) {
        for (int t = segundos; t > 0; t--) {
            printf("Tiempo restante: %d segundos\n", t);
            sleep(1);
        }
    }

    // Iniciar el juego
    while (emparejadas < 30) {
        limpiarPantalla();
        mostrarTablero();
        temporizador(30);  // Temporizador de 30 segundos por turno

        seleccionarCartas();

        if (emparejadas == 30) {
            limpiarPantalla();
            printf("Juego terminado!\n");
            printf("Puntos Jugador 1: %d\n", puntos1);
            printf("Puntos Jugador 2: %d\n", puntos2);

            if (puntos1 > puntos2) {
                printf("¡El Jugador 1 gana!\n");
            } else if (puntos2 > puntos1) {
                printf("¡El Jugador 2 gana!\n");
            } else {
                printf("¡Es un empate!\n");
            }
        }
    }
}


// terminado
void jugarAkinatorNumerico() {
    int nivel = 1, intento, maxIntentos, numeroSecreto, i, acertado = 0;
    int rangoInferior, rangoSuperior;
    int intentosRestantes;
    char respuesta[3];

    printf("Bienvenido a Akinator Numérico!\n");
    printf("Elige un nivel entre 1 a 3 (El número secreto será más difícil en cada nivel)\n");
    printf("Nivel 1: 1-50\nNivel 2: 1-100\nNivel 3: 1-200\n");
    printf("Nivel: ");
    scanf("%d", &nivel);

    // Determinar el rango y número máximo de intentos según el nivel
    switch (nivel) {
        case 1:
            rangoInferior = 1;
            rangoSuperior = 50;
            maxIntentos = 7;
            break;
        case 2:
            rangoInferior = 1;
            rangoSuperior = 100;
            maxIntentos = 10;
            break;
        case 3:
            rangoInferior = 1;
            rangoSuperior = 200;
            maxIntentos = 12;
            break;
        default:
            printf("Nivel no válido. Seleccionando nivel 1 por defecto.\n");
            rangoInferior = 1;
            rangoSuperior = 50;
            maxIntentos = 7;
    }

    srand(time(NULL));  // Inicializa la semilla para los números aleatorios
    numeroSecreto = (rand() % (rangoSuperior - rangoInferior + 1)) + rangoInferior;  // Generar número secreto
    intentosRestantes = maxIntentos;

    printf("\n¡He pensado en un número entre %d y %d! Tienes %d intentos para adivinarlo.\n", rangoInferior, rangoSuperior, maxIntentos);

    // Bucle para los intentos
    while (intentosRestantes > 0 && !acertado) {
        printf("\nTienes %d intentos restantes.\n", intentosRestantes);
        printf("Introduce tu intento: ");
        scanf("%d", &intento);

        if (intento < rangoInferior || intento > rangoSuperior) {
            printf("Por favor, ingresa un número entre %d y %d.\n", rangoInferior, rangoSuperior);
            continue;
        }

        if (intento < numeroSecreto) {
            printf("El número secreto es mayor.\n");
        } else if (intento > numeroSecreto) {
            printf("El número secreto es menor.\n");
        } else {
            acertado = 1;
            printf("¡Felicidades! Adivinaste el número secreto.\n");
        }

        intentosRestantes--;
    }

    // Si no adivinó el número, mostrar el número secreto
    if (!acertado) {
        printf("\nLo siento, no adivinaste el número. El número secreto era %d.\n", numeroSecreto);
    }

    // Preguntar si desea jugar nuevamente
    printf("\n¿Deseas jugar nuevamente? (si/no): ");
    scanf("%s", respuesta);

    if (strcmp(respuesta, "si") == 0) {
        jugarAkinatorNumerico();
    } else {
        printf("Gracias por jugar Akinator Numérico.\n");
    }
}


// generaunJuegoAleatorio
void juegoAleatorio() {
    srand(time(NULL)); // x para generar números aleatorios
    int juego = rand() % 4; // Genera un número entre 0 y 3

    printf("Seleccionando un juego al azar...\n");
    sleep(2);

    switch (juego) {
        case 0:
            printf("¡El juego seleccionado es: Gato!\n");
            jugarGato();
            break;
        case 1:
            printf("¡El juego seleccionado es: Cuatro en Línea!\n");
            jugarCuatroEnLinea();
            break;
        case 2:
            printf("¡El juego seleccionado es: Memorama!\n");
            jugarMemorama();
            break;
        case 3:
            printf("¡El juego seleccionado es: Akineitor!\n");
            jugarAkinatorNumerico();
            break;
        default:
            printf("Ocurrió un error inesperado.\n");
            break;
    }
}

