#ifndef _NLDLRING_H_
#define _NLDLRING_H_

// Doubly Linked Ring

#include "types.h"

template <typename T>
void nlDLRingInsert(T** head, T* afterNode, T* newNode)
{

    afterNode->prev->next = newNode;
    newNode->prev = afterNode->prev;
    newNode->next = afterNode;
    afterNode->prev = newNode;
    if ((void*)*head == afterNode)
    {
        *head = newNode;
    }
}

template <typename T>
void nlDLRingAddStart(T** head, T* newNode)
{
    T* temp;

    temp = *head;
    if (temp == NULL)
    {
        *head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
        return;
    }

    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev = newNode;
}

template <typename T>
T* nlDLRingGetStart(T* current)
{
    if (current == NULL)
    {
        return NULL;
    }
    return current->prev;
}

template <typename T>
bool nlDLRingIsEnd(T* head, T* current)
{
    if (head == NULL)
    {
        return true;
    }
    return head == current;
}

#endif // _NLDLRING_H_
