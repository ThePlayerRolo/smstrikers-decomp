#ifndef _FESCROLLTEXT_H_
#define _FESCROLLTEXT_H_

class TLTextInstance;
class FEScrollText
{
public:
    void ApplyNewTextInstancePointer(TLTextInstance*, float, float);
    void Update(float);
    void SetDisplayMessage(const char*);
    void SetDisplayMessage(unsigned long);
    // void SetDisplayMessage(const BasicString<unsigned short, Detail::TempStringAllocator>&);
    FEScrollText(TLTextInstance*, int, int);
};

// class nlBSearch<nlFont
// {
// public:
//     void GlyphInfo, nlFont::GlyphInfo>(const nlFont::GlyphInfo&, nlFont::GlyphInfo*, int);
// };

#endif // _FESCROLLTEXT_H_
