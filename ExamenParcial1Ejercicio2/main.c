/*Ejercicio 2 Examen Parcial 1
. El grupo Bancario “Estaremos Bien”, quiere desarrollar una aplicación bancaria
que permita realizar lo siguiente:
a. Debe Enviar un mensaje de BIENVENIDA A LA APP y dar apertura a la sección
de LOGIN (Texto a gusto del programador).
b. Debe validar la contraseña del usuario, para esto se cuenta con 3 intentos
para ingresar (La contraseña debe de ser igual a su matrícula).
i. Si la validación falla mandar mensajes de ERROR EN LA CONTRASEÑA y
POSTERIORMENTE USUARIO BLOQUEADO.
ii. Si la validación es correcta, debe mostrar un mensaje de BIENVENIDA
a su BANCA MOVIL y anexar el Monto que tiene en su cuenta (Declarar
una variable e inicializarla con un monto de $5000), posteriormente,
mostrar el MENU DE OPERACIONES.
c. Después de que el usuario valido su información, se mostrará el siguiente
menú, DEPOSITAR, RETIRAR, TRANSFERIR, HABLAR CON UN OPERADOR. Para
las primeras tres opciones se debe de actualizar la variable donde se guarda
el saldo.
i. Realizar todas las operaciones y restricciones necesarias para el
correcto funcionamiento y actualización de los datos.
ii. Cada que se realice alguna operación el usuario debe de volver a mostrar
el saldo actualizado después del movimiento.
iii. Si la opción elegida es la última, solamente mostrar un mensaje de POR
EL MOMENTO TODOS NUESTROS OPERADORES SE ENCUENTRAN
OCUPADOS. SU LLAMADA ESTA SIENDO PROCESADA.
iv. Cuando el usuario realiza cualquier operación y se muestran los
cambios, debe de preguntar si desea realizar otro movimiento, en caso
de seleccionar SI mostrar nuevamente el menú de operaciones; en caso
de NO simplemente mostrar un mensaje de CIERRE DE SESION.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INTENTOS 3
#define CONTRASENA "11276"
#define SALDO_INICIAL 5000

void mostrarMenu();
void depositar(float *saldo);
void retirar(float *saldo);
void transferir(float *saldo);
void bienvenida();

char letra = 164;

int main() {
    char contrasena[20];
    int intentos = 0;
    float saldo = SALDO_INICIAL;
    int opcion;
    char continuar;

    printf("BIENVENIDO A LA APP DEL GRUPO BANCARIO 'ESTAREMOS BIEN'\n");


    while (intentos < MAX_INTENTOS) {
        printf("Ingrese su contrase%ca: ",letra);
        scanf("%s", contrasena);

        if (strcmp(contrasena, CONTRASENA) == 0) {
            system("cls");
            printf("BIENVENIDO a su BANCA MOVIL\n");
            printf("Su saldo inicial es: $%.2f\n", saldo);
            break;
        } else {
            intentos++;
            printf("Error en la contrase%ca\n",letra);

            if (intentos == MAX_INTENTOS) {
                printf("USUARIO BLOQUEADO\n");
                return 0;
            }
        }
    }

    do {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarPantalla();
        switch(opcion) {
            case 1:
                depositar(&saldo);
                break;
            case 2:
                retirar(&saldo);
                break;
            case 3:
                transferir(&saldo);
                break;
            case 4:
                printf("POR EL MOMENTO TODOS NUESTROS OPERADORES SE ENCUENTRAN OCUPADOS. SU LLAMADA ESTA SIENDO PROCESADA.\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }

        printf("Su saldo actual es: $%.2f\n", saldo);
        printf("¿Desea realizar otro movimiento? (S/N): ");
        scanf(" %c", &continuar);
        limpiarPantalla();
    } while (continuar == 'S' || continuar == 's');

    printf("CIERRE DE SESION\n");
    return 0;
}

void mostrarMenu() {
    printf("\nMENU DE OPERACIONES\n");
    printf("1. DEPOSITAR\n");
    printf("2. RETIRAR\n");
    printf("3. TRANSFERIR\n");
    printf("4. HABLAR CON UN OPERADOR\n");
}

void depositar(float *saldo) {
    float monto;
    printf("Ingrese el monto a depositar: $");
    scanf("%f", &monto);
    *saldo += monto;
    printf("Se han depositado $%.2f a su cuenta.\n", monto);
}

void retirar(float *saldo) {
    float monto;
    printf("Ingrese el monto a retirar: $");
    scanf("%f", &monto);
    if (monto > *saldo) {
        printf("Fondos insuficientes.\n");
    } else {
        *saldo -= monto;
        printf("Se han retirado $%.2f de su cuenta.\n", monto);
    }
}

void transferir(float *saldo) {
    float monto;
    printf("Ingrese el monto a transferir: $");
    scanf("%f", &monto);
    if (monto > *saldo) {
        printf("Fondos insuficientes.\n");
    } else {
        *saldo -= monto;
        printf("Se han transferido $%.2f de su cuenta.\n", monto);
    }
}

void limpiarPantalla() {
    system("cls");
}
