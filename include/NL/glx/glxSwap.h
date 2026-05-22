#ifndef _GLXSWAP_H_
#define _GLXSWAP_H_

void glxSwapPost(bool);
void glxSwapPre(bool);
void glxInitSwap(void*, void*);
void glxSwapWaitDrawDone();
void glxLoadRestoreState();
void glxLoadSaveState();
void glxSwapLoading(bool bLoadingIndicator, bool bLoadOtherPosition);
void* glxGetBackBuffer();
void* glxGetDisplayedBuffer();
void glxSwapSetBlack(bool);

// class Config
// {
// public:
//     void Get<BasicString<char, Detail::TempStringAllocator>>(const char*, BasicString<char, Detail::TempStringAllocator>);
//     void TagValuePair::Get<BasicString<char, Detail::TempStringAllocator>>() const;
// };

#endif // _GLXSWAP_H_
