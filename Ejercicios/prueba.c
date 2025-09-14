#include <stdio.h>
#include <string.h>

int main() {
    int ac, op;
    char con[50];

    // Contadores de votos
    int comida = 0, tardeada = 0, excursion = 0, billar = 0, patinar = 0;

    do {
        printf("\n=== Sistema de Votaciones para el Festival ===\n");
        printf("¿Qué desea hacer?\n");
        printf("1. Votar\n");
        printf("2. Conocer resultados\n");
        printf("3. Salir\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nElija una actividad:\n");
                printf("1. Comida\n");
                printf("2. Tardeada\n");
                printf("3. Viaje de excursión\n");
                printf("4. Billar\n");
                printf("5. Patinar en hielo\n");
                scanf("%d", &ac);

                switch (ac) {
                    case 1:
                        comida++;
                        printf("Ha elegido Comida, gracias por su voto.\n");
                        break;
                    case 2:
                        tardeada++;
                        printf("Ha elegido Tardeada, gracias por su voto.\n");
                        break;
                    case 3:
                        excursion++;
                        printf("Ha elegido Viaje de excursión, gracias por su voto.\n");
                        break;
                    case 4:
                        billar++;
                        printf("Ha elegido Billar, gracias por su voto.\n");
                        break;
                    case 5:
                        patinar++;
                        printf("Ha elegido Patinar en hielo, gracias por su voto.\n");
                        break;
                    default:
                        printf("Opción no válida.\n");
                }
                break;

            case 2:

                do {
                    printf("\nIngrese la contraseña para ver los resultados: ");
                    scanf("%s", con);

                    if (strcmp(con, "votosplis") != 0) {
                        printf("Contraseña inválida.\n");
                    }
                } while (strcmp(con, "votosplis") != 0);

                printf("\n=== RESULTADOS ===\n");
                printf("Comida: %d votos\n", comida);
                printf("Tardeada: %d votos\n", tardeada);
                printf("Excursión: %d votos\n", excursion);
                printf("Billar: %d votos\n", billar);
                printf("Patinar en hielo: %d votos\n", patinar);


                int max = comida;
                char ganador[30] = "Comida";

                if (tardeada > max) { max = tardeada; strcpy(ganador, "Tardeada"); }
                if (excursion > max) { max = excursion; strcpy(ganador, "Excursión"); }
                if (billar > max) { max = billar; strcpy(ganador, "Billar"); }
                if (patinar > max) { max = patinar; strcpy(ganador, "Patinar en hielo"); }

                printf("\nEl ganador es: %s con %d votos.\n", ganador, max);
                break;

            case 3:
                printf("\nSaliendo del programa. Buen día.\n");
                break;

            default:
                printf("Opción no válida.\n");
        }

    } while (op != 3);

    return 0;
}
