#ifndef _FEMAPMENU_H_
#define _FEMAPMENU_H_

class TLInstance;

class FEMapMenu
{
public:
    void ChangeItem(int, TLInstance*);
    void SetAllItemsActive();
    void SetItemActive(int, bool);
    void UpdateHighlighter();
    void SetSelectedItem(int);
    void IsItemActive(int) const;
    void IsSelectedItemActive() const;
    void GetSelectedItem() const;
    void MoveUp(bool);
    void MoveDown(bool);
    void MoveLeft(bool);
    void MoveRight(bool);
    void Update(float);
    void UpdateAllItems();
    void AddItem(int, TLInstance*, int, int, int, int, bool);
    ~FEMapMenu();
    FEMapMenu(TLInstance*, bool);
};

#endif // _FEMAPMENU_H_
