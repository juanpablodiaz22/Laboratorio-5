#include "double_list.h"
#include <stdio.h>

int main() {
    DoubleList* list = create_list();

    // Se insertan los nodos al inicio
    insert_at_beginning(list, 5);
    insert_at_beginning(list, 15);
    insert_at_beginning(list, 25);

    // Se insertan los nodos al final
    insert_at_end(list, 35);
    insert_at_end(list, 45);

    // Se inserta un nodo en una posición específica
    insert_at_position(list, 20, 2);
    
 
    // Se imprime la lista hacia adelante
    printf("Lista hacia adelante: ");
    print_list_forward(list);

    // Se imprime la lista hacia atrás
    printf("Lista hacia atrás: ");
    print_list_backward(list);

    // Se inserta un nodo en una posicion especifica 
    insert_at_position(list, 20, 2);
    printf("Lista despues de insertar 20 en la posicion 2: ");
    print_list_forward(list);

    // Busca un nodo
    int search_data = 20;
    Node* found_node = search_node(list, search_data);
    if (found_node) {
        printf("Elemento %d encontrado.\n", search_data);
    } else {
        printf("Elemento %d no encontrado.\n", search_data);
    }

    // Elimina un nodo
    delete_node(list, 20);

    // Se imprime la lista después de eliminación
    printf("Lista después de eliminar el nodo 20: ");
    print_list_forward(list);

    // Se libera memoria
    free_list(list);

    return 0;
}