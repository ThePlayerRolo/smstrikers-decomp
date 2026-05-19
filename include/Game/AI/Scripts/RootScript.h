#ifndef _ROOTSCRIPT_H_
#define _ROOTSCRIPT_H_

#include "Game/AI/DecisionEntity.h"
#include "Game/AI/FuzzyVariant.h"

#define SAVECONFIDENCE_NOINLINE
#include "Game/AI/Scripts/SaveConfidence.h"

FuzzyVariant StrategyChoosePlay(cDecisionEntity* pDecision);
int GetNumDecisionEntities();

#endif // _ROOTSCRIPT_H_
