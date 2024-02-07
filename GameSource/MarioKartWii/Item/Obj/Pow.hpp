#ifndef _ITEMOBJPOW_
#define _ITEMOBJPOW_
#include <kamek.hpp>
#include <MarioKartWii/Item/Obj/ItemObj.hpp>
#include <MarioKartWii/3D/Model/ModelDirector.hpp>

//_sinit_ at 807b2ed0
namespace Item {
class ObjPow : public Obj {
public:
    static Obj** CreateArray(u32 count); //807b1ab0
    void InitSelf() override; //0x8 807b1ba4 vtable 808d2530
};
size_assert(ObjPow, 0x1a0);

class PowScreen { //one per Screen
    PowScreen(u32 screenId); //807b2540
    ModelDirector* powModel; //0x0
    u32 screenId; //0x4
    u8 unknown_0x8[0x10 - 0x8];
}; //0x10
size_assert(PowScreen, 0x10);

class PowMgr {
public:
    static PowMgr* sInstance; //809c3660
    static PowMgr* CreateInstance(); //807b1bc0
    static void DestroyInstance(); //807b1c70
    PowMgr(); //807b1d18 inlined
    static void Init(); //807b1ca8
    void DeployBlooper(u8 playerId); //807a9128 that player used a blooper which will deploy the blooper model from the character
    u32 unknown_0x0;
    u32 screenCount; //0x4
    u8 unknown_0x8[0x18 - 0x8];
    PowScreen* powScreens[4]; //0x18
};//Total Size 0x54
size_assert(PowMgr, 0x28);
}//namespace Item

#endif