#include "NL/nlTask.h"
#include "NL/nlMemory.h"
#include "NL/nlTicker.h"
#include "NL/nlDLRing.h"

#define assert(condition) ((condition) ? ((void)0) : ((void)0))

nlTaskManager* nlTaskManager::m_pInstance = nullptr;

/**
 * Offset/Address/Size: 0x0 | 0x801D28FC | size: 0xC
 */
void nlTaskManager::SetTimeDilation(float timeDilation)
{
    m_pInstance->m_timeDilation = timeDilation;
}

/**
 * Offset/Address/Size: 0xC | 0x801D2908 | size: 0xC
 */
void nlTaskManager::SetNextState(unsigned int nextState)
{
    m_pInstance->m_nextState = nextState;
}

/**
 * Offset/Address/Size: 0x18 | 0x801D2914 | size: 0x150
 */
void nlTaskManager::RunAllTasks()
{
}

/**
 * Offset/Address/Size: 0x168 | 0x801D2A64 | size: 0xC4
 */
void nlTaskManager::AddTask(nlTask* arg0, unsigned int arg1, unsigned int arg2)
{
    arg0->m_unk_0x0C = arg1;
    arg0->m_unk_0x10 = arg2;
    arg0->m_unk_0x14 = nlGetTicker();
    
    if (m_pInstance->m_taskRingHead == nullptr) {
        nlDLRingAddStart<nlTask>(&m_pInstance->m_taskRingHead, arg0);
        return;
    }
    
    // Find the appropriate position to insert the task based on priority
    nlTask* currentTask = nlDLRingGetStart<nlTask>(m_pInstance->m_taskRingHead);
    while (currentTask != nullptr) {
        if (currentTask->m_unk_0x0C >= arg1) {
            currentTask = currentTask->next;
        } else if (!nlDLRingIsEnd<nlTask>(m_pInstance->m_taskRingHead, currentTask)) {
            currentTask = currentTask->prev;
        } else {
            break;
        }
    }
    
    nlDLRingInsert<nlTask>(&m_pInstance->m_taskRingHead, currentTask, arg0);
}

/**
 * Offset/Address/Size: 0x22C | 0x801D2B28 | size: 0x74
 */
void nlTaskManager::Startup(unsigned int arg0)
{
    // void* this_00 = nlMalloc(0x1C, 8, FALSE);
    // m_pInstance = new (this_00) nlTaskManager();


    m_pInstance = (nlTaskManager*)nlMalloc(0x1C, 8, 0);
    assert(m_pInstance != NULL);
    m_pInstance->m_taskCount = arg0;
    m_pInstance->m_unk_0x08 = arg0; // m_previousState ?
    m_pInstance->m_nextState = arg0;
    m_pInstance->m_taskRingHead = nullptr;  // Initialize task ring head to null
    m_pInstance->m_timeDilation = 1.0f;
    m_pInstance->m_flags = 0;    
}

/**
 * Offset/Address/Size: 0x0 | 0x801D2B9C | size: 0x20
 */
// bool nlDLRingIsEnd<nlTask>(nlTask*, nlTask*)
// {
// }

/**
 * Offset/Address/Size: 0x20 | 0x801D2BBC | size: 0x18
 */
// void nlDLRingGetStart<nlTask>(nlTask*)
// {
// }

/**
 * Offset/Address/Size: 0x38 | 0x801D2BD4 | size: 0x38
 */
// void nlDLRingAddStart<nlTask>(nlTask**, nlTask*)
// {
// }

/**
 * Offset/Address/Size: 0x70 | 0x801D2C0C | size: 0x2C
 */
// void nlDLRingInsert<nlTask>(nlTask**, nlTask*, nlTask*)
// {
// }
