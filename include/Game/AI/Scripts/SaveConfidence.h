#ifndef _SAVECONFIDENCE_H_
#define _SAVECONFIDENCE_H_

class SaveConfidence
{
public:
    SaveConfidence(float* pFloat)
        : m_fSavedVal(*pFloat)
        , m_pVal(pFloat)
    {
#ifdef SAVECONFIDENCE_NOINLINE
        FORCE_DONT_INLINE;
#endif
    }

#ifdef SAVECONFIDENCE_NOINLINE
    ~SaveConfidence();
#else
    ~SaveConfidence()
    {
        *m_pVal = m_fSavedVal;
    }
#endif

    float m_fSavedVal;
    float* m_pVal;
};

#endif // _SAVECONFIDENCE_H_
