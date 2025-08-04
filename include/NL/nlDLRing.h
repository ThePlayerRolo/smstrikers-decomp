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
T* nlDLRingGetEnd(T* current)
{
    if (current != 0) {
        return current;
    }
    return NULL;
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

template<typename T, typename CallbackType>
void nlWalkDLRing(T* head, CallbackType* callback, void (CallbackType::*callbackFunc)(T*))
{
    nlWalkRing(head, callback, callbackFunc);
}

template<typename T, typename CallbackType>
void nlWalkRing(T* head, CallbackType* callback, void (CallbackType::*callbackFunc)(T*))
{
    if (head != NULL) 
    {
        T* current = head;  // This likely uses r27
        do {
            current = current->m_next;  // This likely uses r30/r31
            (callback->*callbackFunc)(current);  // This uses r28, r29
        } while (current != head);
    }
}

// =======================================================
// Iterator for nlDLRing
// =======================================================

template <typename T>
class nlDLListIterator
{
public:
    typedef T ValueType;
    typedef T* Pointer;
    typedef T& Reference;

    nlDLListIterator(Pointer head)
    {
        m_head = head;
        m_current = (head ? head->m_next : 0);
        m_first = true;
    }

    bool hasNext() const
    {
        return (m_current != 0) && (m_first || m_current != m_head);
    }

    Pointer next()
    {
        if (!hasNext())
            return 0;

        Pointer ret = m_current;
        m_current = m_current->m_next;
        m_first = false;
        return ret;
    }

    void reset()
    {
        m_current = (m_head ? m_head->m_next : 0);
        m_first = true;
    }

private:
    Pointer m_head;
    Pointer m_current;
    bool m_first;
};

#endif // _NLDLRING_H_
