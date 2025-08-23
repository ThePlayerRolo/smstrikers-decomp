#ifndef NL_SINGLETON_H
#define NL_SINGLETON_H

template <class T>
class nlSingleton
{
public:
    static T* Instance() { return s_pInstance; }

    static void CreateInstance()
    {
        if (!s_pInstance)
            s_pInstance = new T();
    }

    static void DestroyInstance()
    {
        T* p = s_pInstance;
        if (p)
        {
            delete p;
            s_pInstance = 0;
        }
    }

    static T* s_pInstance;
};

template <class T>
T* nlSingleton<T>::s_pInstance = 0;

#endif // NL_SINGLETON_H
