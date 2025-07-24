#ifndef _NLLEXICALCAST_H_
#define _NLLEXICALCAST_H_

#include "types.h"
#include "strtold.h"

// template<typename To, typename From>
// To LexicalCast(const From& value);

// // Explicit template instantiations for the specific types
// template<>
// int LexicalCast<int, const char*>(const char* const& value) {
//     return 0;
// }

// template<>
// float LexicalCast<float, const char*>(const char* const& value) {
//     return 0.0f;
// }

// template<>
// float LexicalCast<float, bool>(const bool& value) {
//     return 0.0f;
// }

// template<>
// float LexicalCast<float, int>(const int& value) {
//     return 0.0f;
// }

// template<>
// float LexicalCast<float, float>(const float& value) {
//     return 0.0f;
// }

// template<>
// int LexicalCast<int, bool>(const bool& value) {
//     return 0;
// }

// template<>
// int LexicalCast<int, int>(const int& value) {
//     return 0;
// }

// template<>
// int LexicalCast<int, float>(const float& value) {
//     return 0;
// }

// LexicalCast<int, const char*>
int LexicalCast<int,const char*>(const char** arg0) {
    return (int) atof(*arg0);
}

// LexicalCast<float, const char*>
float LexicalCast<float,const char*>(const char** arg0) {
    return (float) atof(*arg0);
}

// LexicalCast<float, bool>
float LexicalCast<float,bool>(const bool* arg0) {
    return (float) *arg0;
}

// LexicalCast<float, int>
float LexicalCast<float,int>(const int* arg0) {
    return (float) *arg0;
}

// LexicalCast<float, float>
float LexicalCast<float,float>(const float* arg0) {
    return *arg0;
}

// LexicalCast<int, bool>
int LexicalCast<int,bool>(const bool* arg0) {
    return (int) *arg0;
}

// LexicalCast<int, int>
int LexicalCast<int,int>(const int* arg0) {
    return *arg0;
}

// LexicalCast<int, float>
int LexicalCast<int,float>(const float* arg0) {
    return (int) *arg0;
}

#endif // _NLLEXICALCAST_H_
