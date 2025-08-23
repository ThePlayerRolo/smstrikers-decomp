#ifndef _FEASYNCIMAGE_H_
#define _FEASYNCIMAGE_H_


class AsyncImage
{
public:
    void FreeLoadBuffer();
    void CopyFrom(void*, int);
    void CopyFrom(AsyncImage*);
    void SwapTextures();
    void CanSwapTextures() const;
    void Update(bool);
    void QueueLoad(const char*, bool);
    ~AsyncImage();
    AsyncImage(const char*, const char*);
    void TextureLoadComplete(void*, unsigned long, unsigned long);
};

#endif // _FEASYNCIMAGE_H_