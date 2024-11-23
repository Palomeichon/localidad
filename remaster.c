#include<stdio.h>
#include<cs50.h>

int get_inicio(void);
int get_final(int inicio);
int get_menu(void);
void print_numbers(int opc, int inicio, int fin);
void print_and_sum(int tipo, int inicio, int fin);  // Nueva función para imprimir y sumar
void handle_option(int opc, int inicio, int fin);   // Nueva función para manejar las opciones

int main(void) {
    // Bucle principal del programa
    int opc;
    do {
        // Obtener los límites del rango
        int inicio = get_inicio();
        int fin = get_final(inicio);

        // Mostrar el menú y realizar la operación seleccionada
        opc = get_menu();
        handle_option(opc, inicio, fin); // Usar la nueva función para manejar las opciones

    } while (opc != 4); // El ciclo termina cuando el usuario selecciona la opción 4 (Salir)
}

int get_inicio(void) {
    int inicio;
    do {
        inicio = get_int("Ingresa el rango de inicio: ");
    } while (inicio < 0);
    return inicio;
}

int get_final(int inicio) {
    int final;
    do {
        final = get_int("Ingresa el rango de final: ");
        if (final < inicio) {
            printf("El rango final debe ser mayor o igual al rango de inicio. Intenta de nuevo.\n");
        }
    } while (final < inicio);
    return final;
}

int get_menu(void) {
    int opc;
    do {
        opc = get_int("Ingrese según corresponda\n\n[1] Números Pares\n[2] Números Impares\n[3] TODOS\n[4] Salir\n");
        if (opc < 1 || opc > 4) {
            printf("Opción inválida, por favor intenta de nuevo.\n");
        }
    } while (opc < 1 || opc > 4);
    return opc;
}

void handle_option(int opc, int inicio, int fin) {
    if (opc == 1 || opc == 2 || opc == 3) {
        print_numbers(opc, inicio, fin);  // Llamar a la función original
    } else if (opc == 4) {
        printf("Saliendo del programa!!!\n");
    } else {
        printf("Opción inválida, vuelve a intentar.\n");
    }
}

// Nueva función para imprimir y calcular la suma
void print_and_sum(int tipo, int inicio, int fin) {
    int sum = 0;
    if (tipo == 1) { // Pares
        for (int i = inicio; i <= fin; i++) {
            if (i % 2 == 0) {
                printf("%d ", i);
                sum += i;
            }
        }
        printf("\nLa suma de los números pares es: %d\n", sum);
    } else if (tipo == 2) { // Impares
        for (int i = inicio; i <= fin; i++) {
            if (i % 2 != 0) {
                printf("%d ", i);
                sum += i;
            }
        }
        printf("\nLa suma de los números impares es: %d\n", sum);
    }
}

void print_numbers(int opc, int inicio, int fin) {
    // Mostrar los resultados según la opción seleccionada
    if (opc == 1) {
        printf("Números Pares:\n");
        print_and_sum(1, inicio, fin);  // Usar la función para pares
    } else if (opc == 2) {
        printf("Números Impares:\n");
        print_and_sum(2, inicio, fin);  // Usar la función para impares
    } else if (opc == 3) {
        printf("Todos los Números:\n");
        print_and_sum(1, inicio, fin);  // Imprimir pares
        print_and_sum(2, inicio, fin);  // Imprimir impares
    }
}
