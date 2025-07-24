#ifndef _NLLEXICALCAST_H_
#define _NLLEXICALCAST_H_

#include "types.h"
#include "strtold.h"

// Template declaration
template<typename To, typename From>
To LexicalCast(const From& value);

// Template specializations
template<>
int LexicalCast<int, const char*>(const char* const& value) {
    return (int) atof(value);
}

template<>
float LexicalCast<float, const char*>(const char* const& value) {
    return (float) atof(value);
}

template<>
float LexicalCast<float, bool>(const bool& value) {
    return (float) value;
}

template<>
float LexicalCast<float, int>(const int& value) {
    return (float) value;
}

template<>
float LexicalCast<float, float>(const float& value) {
    return value;
}

template<>
int LexicalCast<int, bool>(const bool& value) {
    return (int) value;
}

template<>
int LexicalCast<int, int>(const int& value) {
    return value;
}

template<>
int LexicalCast<int, float>(const float& value) {
    return (int) value;
}

#endif // _NLLEXICALCAST_H_
