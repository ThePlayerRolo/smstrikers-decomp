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
ListEntry<T>* nlListRemoveStart(ListEntry<T>** head, ListEntry<T>** tail)
{
    ListEntry<T>* first = *head;
    if (first == 0)
        return 0;

    if (tail != 0)
    {
        if (*tail == first)
            *tail = 0;
    }

    // Remove first element
    ListEntry<T>* tmp = *head;
    *head = tmp->next;
    return tmp;
}

template <typename T>
void nlListAddStart(ListEntry<T>** head, ListEntry<T>* entry, ListEntry<T>** tail)
{
    if (tail != 0)
    {
        if (*head == 0)
        {
            *tail = entry;
        }
    }

    // Insert at start
    entry->next = *head;
    *head = entry;
}

template <typename T>
void nlListAddStart(T** head, T* entry, T** tail)
{
    if (tail != 0)
    {
        if (*head == 0)
        {
            *tail = entry;
        }
    }

    // Insert at start
    entry->next = *head;
    *head = entry;
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
