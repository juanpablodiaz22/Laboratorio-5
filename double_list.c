#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Se hace una función para crear una nueva lista doblemente enlazada
DoubleList* create_list() {
    DoubleList* new_list = (DoubleList*)malloc(sizeof(DoubleList));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

// Se hace una función para crear un nuevo nodo
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Se hace una función para insertar un nodo al inicio de la lista
void insert_at_beginning(DoubleList* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
}

// Se hace una función para insertar un nodo al final de la lista
void insert_at_end(DoubleList* list, int data) {
    Node* new_node = create_node(data);
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Se hace una función para insertar un nodo en una posición específica de la lista
void insert_at_position(DoubleList* list, int data, int position) {
    if (position == 0) {
        insert_at_beginning(list, data);
        return;
    }

    Node* new_node = create_node(data);
    Node* current = list->head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        insert_at_end(list, data);
    } else {
        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
    }
}

// Se hace una función para eliminar el primer nodo que contenga el valor repetido
void delete_node(DoubleList* list, int data) {
    Node* current = list->head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    free(current);
}

// Se hace una función para buscar un nodo con un valor específico
Node* search_node(DoubleList* list, int data) {
    Node* current = list->head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Se hace una función para imprimir la lista hacia adelante
void print_list_forward(DoubleList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Se hace una función para imprimir la lista hacia atrás
void print_list_backward(DoubleList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Se hace una función para liberar la memoria de la lista
void free_list(DoubleList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}