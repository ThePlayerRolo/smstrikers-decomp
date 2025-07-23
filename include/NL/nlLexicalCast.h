#ifndef _NLLEXICALCAST_H_
#define _NLLEXICALCAST_H_

#include "types.h"

template<typename To, typename From>
To LexicalCast(const From& value);

// Explicit template instantiations for the specific types
template<>
int LexicalCast<int, const char*>(const char* const& value) {
    return 0;
}

template<>
float LexicalCast<float, const char*>(const char* const& value) {
    return 0.0f;
}

template<>
float LexicalCast<float, bool>(const bool& value) {
    return 0.0f;
}

template<>
float LexicalCast<float, int>(const int& value) {
    return 0.0f;
}

template<>
float LexicalCast<float, float>(const float& value) {
    return 0.0f;
}

template<>
int LexicalCast<int, bool>(const bool& value) {
    return 0;
}

template<>
int LexicalCast<int, int>(const int& value) {
    return 0;
}

template<>
int LexicalCast<int, float>(const float& value) {
    return 0;
}

#endif // _NLLEXICALCAST_H_
