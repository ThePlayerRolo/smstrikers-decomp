#ifndef _NLDLRING_H_
#define _NLDLRING_H_

// Doubly Linked Ring

// bool nlDLRingIsEnd<nlTask>(nlTask*, nlTask*);
// void nlDLRingGetStart<nlTask>(nlTask*);
// void nlDLRingAddStart<nlTask>(nlTask**, nlTask*);
// void nlDLRingInsert<nlTask>(nlTask**, nlTask*, nlTask*);

#include "types.h"

template<typename T>
void nlDLRingInsert(T** head, T* afterNode, T* newNode) {
    if (newNode == nullptr) {
        return;
    }
    
    if (*head == nullptr) {
        // Empty ring - create a self-referencing node
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }
    
    if (afterNode == nullptr) {
        // Insert at the end of the ring
        T* lastNode = (*head)->prev;
        
        newNode->next = *head;
        newNode->prev = lastNode;
        
        lastNode->next = newNode;
        (*head)->prev = newNode;
    } else {
        // Insert after the specified node
        T* nextNode = afterNode->next;
        
        newNode->next = nextNode;
        newNode->prev = afterNode;
        
        afterNode->next = newNode;
        nextNode->prev = newNode;
    }
}

template<typename T>
void nlDLRingAddStart(T** head, T* newNode) {
    if (newNode == nullptr) {
        return;
    }
    
    if (*head == nullptr) {
        // Empty ring - create a self-referencing node
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        // Insert at the beginning of the ring
        T* oldHead = *head;
        
        // newNode becomes the new head
        newNode->next = oldHead;
        newNode->prev = oldHead->prev;
        
        // Update the old head's prev pointer
        oldHead->prev = newNode;
        
        // Update the last node's next pointer
        newNode->prev->next = newNode;
        
        // Update head pointer
        *head = newNode;
    }
}

template<typename T>
T* nlDLRingGetStart(T* current) {
    // Navigate to the start of the ring (head node)
    if (current == nullptr) {
        return nullptr;
    }
    
    T* start = current;
    // Traverse backwards until we reach the head (where prev->next == current)
    while (start->prev != nullptr && start->prev->next != start) {
        start = start->prev;
    }
    
    return start;
}

template<typename T>
bool nlDLRingIsEnd(T* head, T* current) {
    // Check if current node is the end of the ring (points back to head)
    if (current == nullptr || head == nullptr) {
        return true;
    }
    
    // In a doubly-linked ring, the end is when current->next == head
    // or when current == head and we've completed a full cycle
    return current->next == head;
}

#endif // _NLDLRING_H_
