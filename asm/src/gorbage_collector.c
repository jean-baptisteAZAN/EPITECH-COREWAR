/*
** EPITECH PROJECT, 2023
** gorbage_collector.c
** File description:
** Function my_malloc and free
*/

#include "my.h"
#include "asm.h"
#include "op.h"

GarbageCollector gc = { .head = NULL };

void* my_malloc(size_t size_malloc)
{
    void* pointer = malloc(size_malloc);
    if (pointer == NULL) {
        my_printf("Erreur: d'allocation de mémoire.\n");
        return NULL;
    }

    GCNode* node = (GCNode*)malloc(sizeof(GCNode));
    node->pointer = pointer;
    node->next = gc.head;
    gc.head = node;

    return pointer;
}

void full_free(void)
{
    GCNode* node = gc.head;
    while (node != NULL) {
        GCNode* temp = node;
        node = node->next;
        free(temp->pointer);
        free(temp);
    }
    gc.head = NULL;
}

void* my_realloc(void* ptr, size_t size)
{
    if (ptr == NULL)
        return my_malloc(size);
    if (size == 0)
        return NULL;
    void* newPtr = realloc(ptr, size);
    if (newPtr == NULL) {
        my_printf("Erreur: de réallocation mémoire.\n");
        return NULL;
    }
    GCNode* node = gc.head;
    while (node != NULL) {
        if (node->pointer == ptr) {
            node->pointer = newPtr;
            break;
        }
        node = node->next;
    }
    return newPtr;
}

char *my_strdup_mac(char const *src)
{
    int i = 0;
    char *str;
    int j = 0;
    while (src[i] != '\0') {
        i++;
    }
    str = my_malloc(sizeof(char) * (i + 1));
    while (src[j] != '\0') {
        str[j] = src[j];
        j++;
    }
    str[j] = '\0';
    return str;
}
