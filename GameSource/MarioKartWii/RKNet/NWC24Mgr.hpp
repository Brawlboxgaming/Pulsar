#ifndef _RKNETMSGBOARDPUBLISHER_
#define _RKNETMSGBOARDPUBLISHER_

#include <core/egg/NWC24Handler.hpp>
#include <core/egg/Thread.hpp>
#include <MarioKartWii/System/Timer.hpp>

class NWC24Mgr : public EGG::Disposer {
public:
    struct AJPGHolder {
        void* ajpgPtr;
        u32 ajpgSize;
    };

    struct NWC24Buffer {
        u8 unknown[0x1c000];
        u8 letter_LZbinary[0x2c258 - 0x1c000]; //0x1c000
        u32 binarySize; //0x2c258
        u32 unknown_0x2c25c;
        NWC24::CHJumpObj chJumpObj; //0x2C260
    }; //0x2c4b8

    struct UnkSub {
        UnkSub(); //8067866c
        u32 _;
    };

    struct UnkSub2 {
        u8 unknown[4];
        Timer timer;
        u8 unknown[0x60]; //0x10
    };

    struct UnkSub3 {
        static UnkSub3* sInstance; //809c2140
        u8 _[0xb0];
    };
    static NWC24Mgr* sInstance; //809c2144
    static NWC24Mgr* CreateInstance(); //80668ab4
    static void DestroyInstance(); //806689b8
    NWC24Mgr(EGG::Heap* heap); //80668b18
    ~NWC24Mgr() override; //80668814 vtable 808c0e48

    void Update(); //80669264
    bool RequestMsgBoardPublish(const wchar_t* message, u32 r5, void* nwc24Buffer, AJPGHolder* holder); //80672350
    void PublishMsgBoardAsync(); //80671c7c creates letter_LZ.bin on the disc, and publishes the message and ajpg to the message board
    void InitCHJObj(void* nwc24Buffer, u32 _420c, u32 _4210); //806720d0
    bool PublishMsgBoard(u32 unused, u64 userId, const wchar_t* message,
        void* nwc24Buffer, u32 _4214, const AJPGHolder** holder, bool r11); //80671df8 actually commits the msg
    u32 GetPublishState() const; //80668fa4
    u32 GetState() const; //80668fac
    u32 GetError() const; //80668fdc

    u8 unknown_0x10;
    u32 publishState; //0x10 1 = still publishing
    u32 state; //0x14
    u8 unknown_0x18[8];
    bool isReady; //0x20
    u8 padding[3];
    UnkSub sub; //0x24
    u8 unknown_0x28[4];

    EGG::TaskThread* taskThread; //0x2c
    u8 unknown_0x30[0x41f0 - 0x30];
    void* unkBuffer; //0x41f0
    u8 unknown_0x41f4[0x4200 - 0x41f4];
    u64 userId; //0x4200
    const wchar_t* message; //0x4208
    u32 r5Arg; //0x420C
    u32 unknown_0x4210[2];
    AJPGHolder* ajpg; //0x4218
    void* nwc24Buffer; //0x4220 
    u8 unknown_0x4224[0x757c - 0x4224];

    u32 error; //0x757c
    u8 unknown_0x7580[8];
    void* unkBuffer2; //0x7588
    EGG::NWC24Handler* nwc24Handler; //0x758c
    u8 unknown_0x7590[4];
    UnkSub2 sub2s[10]; //0x7594
    u8 unknown_0x79f4[0xa008 - 0x79f4]; //0x79f4
}; //0XA008

#endif