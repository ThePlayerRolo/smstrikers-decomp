#ifndef _BASICSTADIUM_H_
#define _BASICSTADIUM_H_

#include "NL/nlMath.h"
#include "World.h"

class Event;
class WorldObjectData;

class BasicStadium : public World
{
public:
    virtual ~BasicStadium();
    BasicStadium(const char*);

    virtual void GetTerrainType(const nlVector3&) const;
    virtual void HandleObjectCreation(WorldObjectData *);
    virtual void Render();
    virtual void Update(float);
    virtual void UpdateInReplay(float);
    virtual void FixedUpdate(float);
    virtual void HandleEvent(Event*, void*);
    virtual void CreateHelperObjFromChunk(nlChunk*);
    virtual void DoLoad();
    virtual void DoInitialize();

    void GetCurrentStadium();   
    void BasicStadiumEventHandler(Event*, void*);
};


// class Config
// {
// public:
//     void Get<BasicString<char, Detail::TempStringAllocator>>(const char*, BasicString<char, Detail::TempStringAllocator>);
//     void TagValuePair::Get<BasicString<char, Detail::TempStringAllocator>>() const;
// };

#endif // _BASICSTADIUM_H_
