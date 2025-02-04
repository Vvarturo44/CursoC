/* Ejercicio 1 Examen Parcial 1
El grupo de 3ro B de la Secundaria Benito Juárez, tiene 10 estudiantes y tres
asignaturas diferentes (Español, Matemáticas e Historia). Desarrolla un
programa que realice lo siguiente.
a. Debe solicitar las calificaciones de los estudiantes.
b. Debe calcular y mostrar los promedios individuales de los estudiantes.
c. Debe calcular y mostrar el promedio de cada una de las asignaturas.
d. Debe de calcular y mostrar el promedio general que obtuvo el grupo en el
semestre.
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_ESTUDIANTES 10

char letra = 164;

void solicitarCalificaciones(int calificaciones[][3]);
void calcularPromedios(int calificaciones[][3], float promediosIndividuales[], float *promedioEspanol, float *promedioMatematicas, float *promedioHistoria, float *promedioGeneral);
void limpiarPantalla();

int main() {
    int calificaciones[NUM_ESTUDIANTES][3];
    float promediosIndividuales[NUM_ESTUDIANTES];
    float promedioEspanol, promedioMatematicas, promedioHistoria, promedioGeneral;

    solicitarCalificaciones(calificaciones);
    limpiarPantalla();
    calcularPromedios(calificaciones, promediosIndividuales, &promedioEspanol, &promedioMatematicas, &promedioHistoria, &promedioGeneral);
    limpiarPantalla();
    printf("Promedios individuales:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, promediosIndividuales[i]);
    }

    printf("Promedio de Espa%c""ol: %.2f\n", letra, promedioEspanol);
    printf("Promedio de Matematicas: %.2f\n", promedioMatematicas);
    printf("Promedio de Historia: %.2f\n", promedioHistoria);
    printf("Promedio general del grupo: %.2f\n", promedioGeneral);

    return 0;
}

void solicitarCalificaciones(int calificaciones[][3]) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        for (int j = 0; j < 3; j++) {
            char asignatura[20];
            switch (j) {
                case 0: sprintf(asignatura, "Espa%c""ol", letra); break;
                case 1: strcpy(asignatura, "Matematicas"); break;
                case 2: strcpy(asignatura, "Historia"); break;
            }
            do {
                printf("Ingresa la calificacion del estudiante %d entre 1 y 10 para %s: ", i + 1, asignatura);
                scanf("%d", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("Error: Ingrese una calificacion valida.\n");
                }
            } while (calificaciones[i][j] < 0);
        }
    }
}

void calcularPromedios(int calificaciones[][3], float promediosIndividuales[], float *promedioEspanol, float *promedioMatematicas, float *promedioHistoria, float *promedioGeneral) {
    int sumaEspanol = 0, sumaMatematicas = 0, sumaHistoria = 0;

    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        promediosIndividuales[i] = (calificaciones[i][0] + calificaciones[i][1] + calificaciones[i][2]) / 3.0;
        sumaEspanol += calificaciones[i][0];
        sumaMatematicas += calificaciones[i][1];
        sumaHistoria += calificaciones[i][2];
    }

    *promedioEspanol = sumaEspanol / (float)NUM_ESTUDIANTES;
    *promedioMatematicas = sumaMatematicas / (float)NUM_ESTUDIANTES;
    *promedioHistoria = sumaHistoria / (float)NUM_ESTUDIANTES;
    *promedioGeneral = (*promedioEspanol + *promedioMatematicas + *promedioHistoria) / 3.0;
}

void limpiarPantalla() {
    system("cls");
}
