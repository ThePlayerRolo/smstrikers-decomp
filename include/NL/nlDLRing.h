#ifndef _NLDLRING_H_
#define _NLDLRING_H_

// Doubly Linked Ring

#include "types.h"

template <typename T>
void nlDLRingInsert(T** head, T* afterNode, T* newNode)
{

    afterNode->m_next->m_prev = newNode;
    newNode->m_next = afterNode->m_next;
    newNode->m_prev = afterNode;
    afterNode->m_next = newNode;
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
        newNode->m_next = newNode;
        newNode->m_prev = newNode;
        return;
    }

    temp->m_next->m_prev = newNode;
    newNode->m_next = temp->m_next;
    newNode->m_prev = temp;
    temp->m_next = newNode;
}

template <typename T>
void nlDLRingAddEnd(T** head, T* newNode)
{
    nlDLRingAddStart(head, newNode);
    *head = newNode;
}

template <typename T>
T* nlDLRingGetStart(T* current)
{
    if (current == NULL)
    {
        return NULL;
    }
    return current->m_next;
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

template <typename T>
void nlDLRingRemove(T** head, T* current)
{
    T* tmp_node = current->m_next;
    
    if (tmp_node == current) 
    {
        *head = NULL;
        return;
    }
    
    current->m_prev->m_next = tmp_node;
    current->m_next->m_prev = current->m_prev;
    
    if (*head == current) 
    {
        *head = current->m_prev;
    }    
}

template <typename T>
bool nlDLRingValidateContainsElement(T* head, const T* node)
{
    if (head == NULL) {
        return false;
    }

    T* var_r5 = head->m_next;
loop_3:
    if (node == var_r5) 
    {
        return true;
    }

    if (var_r5 != head) 
    {
        var_r5 = var_r5->m_next;
        goto loop_3;
    }

    return false;    
}

template <typename T>
void nlDLRingAppendRing(T **head, T *current) {
    T *temp_r5;
    T *temp_r6;

    if (current != NULL) 
    {
        temp_r5 = *head;
        if (temp_r5 == NULL) 
        {
            *head = current;
            return;
        }

        temp_r6 = temp_r5->m_next;
        temp_r5->m_next = current->m_next;
        current->m_next->m_prev = *head;
        current->m_next = temp_r6;
        temp_r6->m_prev = current;
        *head = current;
    }
}

template <typename T>
bool nlDLRingRemoveSafely(T** head, const T* node)
{
    T *temp_r0;

    if (nlDLRingValidateContainsElement(*head, node) == 0) {
        return false;
    }    

    temp_r0 = node->m_next;
    if (temp_r0 == node) {
        *head = NULL;
        return 1;
    }
    node->m_prev->m_next = temp_r0;
    node->m_next->m_prev = node->m_prev;
    if (*head == node) 
    {
        *head = node->m_prev;
        return true;
    }

    return true;
}

#endif // _NLDLRING_H_
