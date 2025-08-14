#ifndef _FEINGAMEMESSENGERMANAGER_H_
#define _FEINGAMEMESSENGERMANAGER_H_

class FEInGameMessengerManager
{
public:
    enum eTimeStates
    {
        TIME_STATE_0 = 0,
    };

    void Update(float);
    void EnterNewTimeState(FEInGameMessengerManager::eTimeStates);
    ~FEInGameMessengerManager();
};

// class ListContainerBase<FEInGameMessengerManager
// {
// public:
//     void eInGameMessages,
//     NewAdapter<ListEntry<FEInGameMessengerManager::eInGameMessages>>>::DeleteEntry(ListEntry<FEInGameMessengerManager::eInGameMessages>*);
// };

// class nlWalkList<ListEntry<FEInGameMessengerManager
// {
// public:
//     void eInGameMessages>, ListContainerBase<FEInGameMessengerManager::eInGameMessages,
//     NewAdapter<ListEntry<FEInGameMessengerManager::eInGameMessages>>>>(ListEntry<FEInGameMessengerManager::eInGameMessages>*,
//     ListContainerBase<FEInGameMessengerManager::eInGameMessages, NewAdapter<ListEntry<FEInGameMessengerManager::eInGameMessages>>>*, void
//     (ListContainerBase<FEInGameMessengerManager::eInGameMessages,
//     NewAdapter<ListEntry<FEInGameMessengerManager::eInGameMessages>>>::*)(ListEntry<FEInGameMessengerManager::eInGameMessages>*));
// };

// class nlListRemoveStart<ListEntry<FEInGameMessengerManager
// {
// public:
//     void eInGameMessages>>(ListEntry<FEInGameMessengerManager::eInGameMessages>**,
//     ListEntry<FEInGameMessengerManager::eInGameMessages>**);
// };

// class nlListAddEnd<ListEntry<FEInGameMessengerManager
// {
// public:
//     void eInGameMessages>>(ListEntry<FEInGameMessengerManager::eInGameMessages>**,
//     ListEntry<FEInGameMessengerManager::eInGameMessages>**, ListEntry<FEInGameMessengerManager::eInGameMessages>*);
// };

#endif // _FEINGAMEMESSENGERMANAGER_H_
