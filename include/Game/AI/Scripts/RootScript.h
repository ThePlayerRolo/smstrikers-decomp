#ifndef _ROOTSCRIPT_H_
#define _ROOTSCRIPT_H_

#include "Game/AI/DecisionEntity.h"
#include "Game/AI/FuzzyVariant.h"

class SaveConfidence
{
public:
    SaveConfidence(float* pFloat)
        : m_savedValue(*pFloat)
        , m_pFloat(pFloat)
    {
        FORCE_DONT_INLINE;
    }
    ~SaveConfidence();
    // ~SaveConfidence()
    // {
    //     *m_pFloat = m_savedValue;
    // }

    float m_savedValue;
    float* m_pFloat;
};

// class SaveConfidence
// {
// public:
//     SaveConfidence(float* pFloat)
//         : m_fSavedVal(*pFloat)
//         , m_pVal(pFloat)
//     {
//     }

//     ~SaveConfidence()
//     {
//         *m_pVal = m_fSavedVal;
//     }

//     float m_fSavedVal;
//     float* m_pVal;
// };

FuzzyVariant StrategyChoosePlay(cDecisionEntity* pDecision);
int GetNumDecisionEntities();

#endif // _ROOTSCRIPT_H_
