#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Se define la estructura del nodo
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Se define la estructura de la lista doblemente enlazada
typedef struct DoubleList {
    Node* head;
    Node* tail;
} DoubleList;

// Se declaran las funciones solicitadas
DoubleList* create_list();
void insert_at_beginning(DoubleList* list, int data);
void insert_at_end(DoubleList* list, int data);
void insert_at_position(DoubleList* list, int data, int position);
void delete_node(DoubleList* list, int data);
Node* search_node(DoubleList* list, int data);
void print_list_forward(DoubleList* list);
void print_list_backward(DoubleList* list);
void free_list(DoubleList* list);

#endif // DOUBLE_LIST_H