#ifndef _SIMMER_H_
#define _SIMMER_H_

#include "NL/nlBasicString.h"

class Simulator
{
public:
    Simulator();
    void InitializeStats();
};

template <typename StringType>
class Tokenizer
{
public:
    StringType m_source;
    StringType m_delimiter;

    class iterator
    {
    public:
        const Tokenizer* mTokenizer;
        const char* mIter;
        const char* mEnd;
        StringType mToken;

        iterator(const Tokenizer& tokenizer, const char* endPtr);
        iterator& operator++();
        void FindNextToken();

        bool operator!=(const iterator& other) const
        {
            return mIter != other.mIter;
        }
    };

    Tokenizer(const StringType& source, const StringType& delimiter)
        : m_source(source)
        , m_delimiter(delimiter)
    {
    }

    iterator begin() const;
    iterator end() const;
};

#endif // _SIMMER_H_
