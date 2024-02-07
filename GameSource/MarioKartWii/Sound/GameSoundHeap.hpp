#ifndef _AUDIO_HEAP_MGR_
#define _AUDIO_HEAP_MGR_

#include <kamek.hpp>
#include <core/egg/Audio/AudioHeap.hpp>
#include <core/egg/mem/Heap.hpp>
#include <core/egg/mem/Disposer.hpp>
#include <MarioKartWii/System/Identifiers.hpp>

/*
Contributors:
-Melg
*/

using namespace nw4r;

class GameSoundHeapImpl : public EGG::SoundHeapMgr {
public:
    ~GameSoundHeapImpl(); //806fdeac
    using EGG::SoundHeapMgr::LoadState; //806fe1b4 vtable 808c7a10
    using EGG::SoundHeapMgr::GetCurrentLevel; //806fe240
    using EGG::SoundHeapMgr::SaveState;  //806fe0e0
};
size_assert(GameSoundHeapImpl, 0xF0);

class GameSoundHeap : public GameSoundHeapImpl {
public:
    //a 2nd vtable existing (with the same funcs) shows this template system is incorrect OR that disposers work differently than though
    static GameSoundHeap* sInstance; //809c2350 vtable 808c79f0 
    GameSoundHeap* CreateInstance(); //806fdc1c
    void DestroyInstance(); //806fdcec
    GameSoundHeap(); //806fde08
    ~GameSoundHeap(); //806fdf18
    u32 SetType(); //806fe084 returns the size of the heap that'll contain the sound heap
    void Initialize(EGG::Heap* heap); //806fdffc heap size is implictly obtained through size
    void DestroySoundHeap(); //806fe044
    EGG::TDisposer<MarioKartWiiSoundHeap> disposer; //806fdae4 vtable 808c7a04
    bool isInitialized; //0x100
    u8 padding[3];
    u32 type; //0x104 only seems to be used to get the heap size
};
size_assert(GameSoundHeap, 0x108);



#endif