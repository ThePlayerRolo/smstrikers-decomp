#ifndef _DEBUG_H_
#define _DEBUG_H_

enum eDEBUG_CHANNEL
{
    DEBUG_STARTUP = 0,
    DEBUG_GL,
    DEBUG_GLPLAT,
    DEBUG_RENDER,
    DEBUG_AI,
    DEBUG_CAMERA,
    DEBUG_EVENT,
    DEBUG_FE,
    DEBUG_PHYSICS,
    DEBUG_MEMORY,
    DEBUG_SOUND,
    DEBUG_TASKMAN,
    DEBUG_LOADER,
    DEBUG_MISC,
    DEBUG_REPLAY,
    DEBUG_NIS,
    DEBUG_NET,
    DEBUG_MULTISTREAM,
    DEBUG_WORLD,
    DEBUG_CONFIGSYS,

    DEBUG_CHANNEL_COUNT
};

namespace tDebugPrintManager
{

int Print(eDEBUG_CHANNEL, const char*, ...);
void Initialize();
bool ParseDebugChannelFile(const char*);

} // namespace tDebugPrintManager

#endif // _DEBUG_H_
