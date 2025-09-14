#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 100
#define MAX 100

int main() {
    char usuarios[MAX_USUARIOS][20];
    char contraseñas[MAX_USUARIOS][20];
    int totalUsuarios = 0;

    FILE *archivo = fopen("usuarios.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de usuarios.\n");
        return 1;
    }

    while (fscanf(archivo, "%s %s", usuarios[totalUsuarios], contraseñas[totalUsuarios]) == 2) {
        totalUsuarios++;
    }
    fclose(archivo);

    char usuarioIngresado[20];
    char contraseñaIngresada[20];
    int intentos = 0;
    int accesoConcedido = 0;

    while (intentos < 3) {
        printf("Ingrese su nombre de usuario: ");
        scanf("%s", usuarioIngresado);
        printf("Ingrese la contraseña: ");
        scanf("%s", contraseñaIngresada);

        for (int i = 0; i < totalUsuarios; i++) {
            if (strcmp(usuarioIngresado, usuarios[i]) == 0 &&
                strcmp(contraseñaIngresada, contraseñas[i]) == 0) {

                printf("Acceso concedido. Bienvenido, %s.\n", usuarioIngresado);
                accesoConcedido = 1;

                // Inicia el menú de productos
                char producto[100];
                int opcion;

                do {
                    printf("\n--- MENU ---\n");
                    printf("1. Consultar producto\n");
                    printf("2. Agregar producto\n");
                    printf("3. Quitar producto\n");
                    printf("4. Salir\n");
                    printf("Elige una opcion: ");
                    scanf("%d", &opcion);
                    while (getchar() != '\n'); // Limpia el buffer del scanf

                    switch (opcion) {
                        case 1:
                            archivo = fopen("Productos.txt", "r");
                            if (archivo == NULL) {
                                printf("No se pudo abrir el archivo.\n");
                                break;
                            }

                            printf("\nInventario:\n");
                            while (fgets(producto, sizeof(producto), archivo)) {
                                printf("- %s", producto);
                            }

                            fclose(archivo);
                            break;

                        case 2:
                            archivo = fopen("Productos.txt", "a");
                            if (archivo == NULL) {
                                printf("No se pudo abrir el archivo.\n");
                                break;
                            }

                            printf("Ingrese el producto a agregar: ");
                            fgets(producto, sizeof(producto), stdin);
                            producto[strcspn(producto, "\n")] = 0;

                            fprintf(archivo, "%s\n", producto);
                            fclose(archivo);

                            printf("Producto agregado a la lista.\n");
                            break;

                        case 3: {
                            archivo = fopen("Productos.txt", "r");
                            if (archivo == NULL) {
                                printf("No se pudo abrir el archivo.\n");
                                break;
                            }

                            char productos[MAX][100];
                            int total = 0;

                            while (fgets(productos[total], sizeof(productos[total]), archivo) != NULL && total < MAX) {
                                productos[total][strcspn(productos[total], "\n")] = 0;
                                total++;
                            }

                            fclose(archivo);

                            if (total == 0) {
                                printf("No hay productos para eliminar.\n");
                                break;
                            }

                            printf("\nProductos en la lista:\n");
                            for (int i = 0; i < total; i++) {
                                printf("%d. %s\n", i + 1, productos[i]);
                            }

                            int indice;
                            printf("Ingrese el número del producto que desea eliminar: ");
                            scanf("%d", &indice);
                            while (getchar() != '\n');

                            if (indice < 1 || indice > total) {
                                printf("Número inválido.\n");
                                break;
                            }

                            archivo = fopen("Productos.txt", "w");
                            if (archivo == NULL) {
                                printf("No se pudo escribir el archivo.\n");
                                break;
                            }

                            for (int i = 0; i < total; i++) {
                                if (i != indice - 1) {
                                    fprintf(archivo, "%s\n", productos[i]);
                                }
                            }

                            fclose(archivo);
                            printf("Producto eliminado correctamente.\n");
                            break;
                        }

                        case 4:
                            printf("Saliendo del menú\n");
                            break;

                        default:
                            printf("❗ Opción no válida. Intente nuevamente.\n");
                            break;
                    }

                } while (opcion != 4);

                break;
            }
        }

        if (accesoConcedido) break;

        printf("Usuario o contraseña incorrectos. Intentos restantes: %d\n", 2 - intentos);
        intentos++;
    }

    if (!accesoConcedido) {
        printf("Acceso denegado. Demasiados intentos.\n");
    }

    return 0;
}
