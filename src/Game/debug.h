#ifndef _DEBUG_H_
#define _DEBUG_H_

namespace tDebugPrintManager
{

enum eDEBUG_CHANNEL
{
    DEBUG_CHANNEL_DEFAULT = 0,
    DEBUG_CHANNEL_ERROR = 1,
    DEBUG_CHANNEL_WARNING = 2,
    DEBUG_CHANNEL_INFO = 3,
    DEBUG_CHANNEL_DEBUG = 4,
    DEBUG_CHANNEL_TRACE = 5,
    DEBUG_CHANNEL_ALL = 6
};

void Print(eDEBUG_CHANNEL, const char*, ...);
void Initialize();
void ParseDebugChannelFile(const char*);

} // namespace tDebugPrintManager

#endif // _DEBUG_H_
