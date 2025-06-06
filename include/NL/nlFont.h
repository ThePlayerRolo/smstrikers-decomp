#ifndef _NLFONT_H_
#define _NLFONT_H_


class nlFont
{
public:
    typedef struct {
        // TODO: Define GlyphInfo struct
    } GlyphInfo;

    typedef struct {
        // TODO: Define GlyphInfo struct
    } KernPair;

    void GetCharWidth(unsigned short, unsigned short) const;
    void DisableScissorBox() const;
    // void SetScissorBox(const nlFont::ScissorBox&) const;
    // void DrawString(eGLView, const FontCharString&, const nlVector2&, const nlColour&, const nlColour&, int, nlFont::TextPass, bool, unsigned long*, nlColour*) const;
    void Load(const char*, char*, unsigned long);
    // void GlyphInfo::SortProc(const nlFont::GlyphInfo*, const nlFont::GlyphInfo*);
    // void KernPair::SortProc(const nlFont::KernPair*, const nlFont::KernPair*);

    ~nlFont();
    nlFont();
};


// class ListContainerBase<nlFont
// {
// public:
//     ListContainerBase<nlFont::GlyphInfo, BasicSlotPoolHigh<ListEntry<nlFont::GlyphInfo>>>::DeleteEntry(ListEntry<nlFont::GlyphInfo>*);
//     ListContainerBase<nlFont::KernPair, BasicSlotPoolHigh<ListEntry<nlFont::KernPair>>>::DeleteEntry(ListEntry<nlFont::KernPair>*);
// };


// class BasicSlotPoolHigh<ListEntry<nlFont
// {
// public:
//     BasicSlotPoolHigh<ListEntry<nlFont::GlyphInfo>>::freeFN(void*);
//     BasicSlotPoolHigh<ListEntry<nlFont::GlyphInfo>>::allocFN(unsigned long);
//     BasicSlotPoolHigh<ListEntry<nlFont::KernPair>>::freeFN(void*);
//     BasicSlotPoolHigh<ListEntry<nlFont::KernPair>>::allocFN(unsigned long);
// };


// class nlQSort<nlFont
// {
// public:
//     nlQSort<nlFont::GlyphInfo>(nlFont::GlyphInfo*, int, int (*)(const nlFont::GlyphInfo*, const nlFont::GlyphInfo*));
//     nlQSort<nlFont::KernPair>(nlFont::KernPair*, int, int (*)(const nlFont::KernPair*, const nlFont::KernPair*));
// };


// class nlBSearch<nlFont
// {
// public:
//     nlBSearch<nlFont::KernPair, nlFont::KernPair>(const nlFont::KernPair&, nlFont::KernPair*, int);
// };


// class nlWalkList<ListEntry<nlFont
// {
// public:
//     nlWalkList<ListEntry<nlFont::GlyphInfo>, ListContainerBase<nlFont::GlyphInfo, BasicSlotPoolHigh<ListEntry<nlFont::GlyphInfo>>>>(ListEntry<nlFont::GlyphInfo>*, ListContainerBase<nlFont::GlyphInfo, BasicSlotPoolHigh<ListEntry<nlFont::GlyphInfo>>>*, void (ListContainerBase<nlFont::GlyphInfo, BasicSlotPoolHigh<ListEntry<nlFont::GlyphInfo>>>::*)(ListEntry<nlFont::GlyphInfo>*));
//     nlWalkList<ListEntry<nlFont::KernPair>, ListContainerBase<nlFont::KernPair, BasicSlotPoolHigh<ListEntry<nlFont::KernPair>>>>(ListEntry<nlFont::KernPair>*, ListContainerBase<nlFont::KernPair, BasicSlotPoolHigh<ListEntry<nlFont::KernPair>>>*, void (ListContainerBase<nlFont::KernPair, BasicSlotPoolHigh<ListEntry<nlFont::KernPair>>>::*)(ListEntry<nlFont::KernPair>*));
// };


// class nlListRemoveStart<ListEntry<nlFont
// {
// public:
//     nlListRemoveStart<ListEntry<nlFont::GlyphInfo>>(ListEntry<nlFont::GlyphInfo>**, ListEntry<nlFont::GlyphInfo>**);
//     nlListRemoveStart<ListEntry<nlFont::KernPair>>(ListEntry<nlFont::KernPair>**, ListEntry<nlFont::KernPair>**);
// };


// class nlListAddStart<ListEntry<nlFont
// {
// public:
//     nlListAddStart<ListEntry<nlFont::KernPair>>(ListEntry<nlFont::KernPair>**, ListEntry<nlFont::KernPair>*, ListEntry<nlFont::KernPair>**);
//     nlListAddStart<ListEntry<nlFont::GlyphInfo>>(ListEntry<nlFont::GlyphInfo>**, ListEntry<nlFont::GlyphInfo>*, ListEntry<nlFont::GlyphInfo>**);
// };

#endif // _NLFONT_H_
