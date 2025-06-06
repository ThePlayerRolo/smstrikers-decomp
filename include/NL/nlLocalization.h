#ifndef _NLLOCALIZATION_H_
#define _NLLOCALIZATION_H_


class nlLocalization
{
public:
    enum nlLanguage {
        NL_LANGUAGE_ENGLISH,
    };

    void Load(nlLocalization::nlLanguage, bool);
    void Initialize();
};

#endif // _NLLOCALIZATION_H_
