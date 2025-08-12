#ifndef _NLLIST_H_
#define _NLLIST_H_

#include "types.h"

template <typename T>
class ListEntry
{
public:
    /* 0x00 */ ListEntry<T>* next;
    /* 0x04 */ ListEntry<T>* prev; // not sure if this is used
    /* 0x08 */ T data;

    ListEntry()
        : next(nullptr)
        , data(nullptr)
    {
    }

    ListEntry(T* data)
        : next(nullptr)
        , data(data)
    {
    }
};

template <typename T>
class NewAdapter
{
public:
    static void DeleteEntry(ListEntry<T>* entry)
    {
        if (entry)
        {
            delete entry;
        }
    }
};

template <typename T, typename Adapter>
class ListContainerBase
{
public:
    typedef typename Adapter::EntryType EntryType;

    void DeleteEntry(EntryType* entry) { Adapter::DeleteEntry(entry); }

    // Add more list operations as needed
    void AddEntry(EntryType* entry)
    {
        // Implementation for adding entries
    }

    void RemoveEntry(EntryType* entry)
    {
        // Implementation for removing entries
    }
};

template <typename T>
void nlListRemoveStart(ListEntry<T>** head, ListEntry<T>** tail)
{
    if (!head || !*head)
        return;

    ListEntry<T>* oldHead = *head;
    *head = oldHead->next;

    if (*head)
    {
        (*head)->prev = nullptr;
    }
    else
    {
        // List is now empty
        *tail = nullptr;
    }

    delete oldHead;
}

template <typename T>
void nlListAddStart(ListEntry<T>** head, ListEntry<T>* newEntry, ListEntry<T>** tail)
{
    if (!newEntry)
        return;

    newEntry->next = *head;
    newEntry->prev = nullptr;

    if (*head)
    {
        (*head)->prev = newEntry;
    }
    else
    {
        // List was empty, update tail
        *tail = newEntry;
    }

    *head = newEntry;
}

template <typename T>
void nlDeleteList(T** head)
{
    T* next;
    while (*head != NULL)
    {
        next = (*head)->next;
        delete *head;
        *head = next;
    }
    *head = NULL;
}

#endif
