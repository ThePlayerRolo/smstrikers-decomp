#ifndef _NLTEXTESCAPE_H_
#define _NLTEXTESCAPE_H_


class nlEscapeSequence
{
public:
    void GetExtendedColour();

    nlEscapeSequence(const unsigned short*);
};


// Binary search function template
template<typename T, typename U>
T* nlBSearch(const U& key, T* array, int size);


// Quicksort function template
template<typename T>
void nlQSort(T* array, int size, int (*compare)(const T*, const T*));


// Default quicksort comparison function template
template<typename T>
int nlDefaultQSortComparer(const T* a, const T* b);

#endif // _NLTEXTESCAPE_H_
