#include "types.h"

// static int g_Region __attribute__((section(".sdata2"))) = 1;
static int const g_Region = 1;

static bool g_bProfiling = false;
static bool g_bTweaking = false;
static bool g_e3_Build = false;
static bool g_Europe = false;
static bool g_bFranticPausing = false;
static int g_Language = 0;
static void* g_pTheLoadingManagerTask = nullptr;

int main(void)
{
    return 0;
}

static void SetupViews()
{
    return;
}

static void Initialize()
{
    return;
}

int GetRegion()
{
    return g_Region;
}
