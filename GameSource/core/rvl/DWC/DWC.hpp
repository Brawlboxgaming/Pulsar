#ifndef _DWC_ //to split into multiple files ultimately
#define _DWC_
#include <types.hpp>

//Credit Seeky

namespace DWC { //this is C, but don't care

extern char loginRegion[8]; //80384fd0




struct LoginID {
    u64 userId;
    u32 playerId;
};

struct UserData { //https://wiki.tockdom.com/wiki/Rksys.dat#DWC_User_Data
    u32 size;
    LoginID pseudoId;
    LoginID authenticID;
    int gsProfileId; //0x1c
    int flag;
    u32 gamecode; //always RMCJ
    u32 unknown_0x28[0x3c - 0x28];
    u32 crc32;
};

struct ConnectionUserData {
    u8 localPlayerCount;
    u8 unknown_0x1[3];
};

struct Friend {
    u32 bitflag;
    u32 pid;
    u32 unknown_0x4;
};

struct FriendUpdate {
    u8 unknown[4];
    u32 pid;
};

int Printf(u32 level, const char*, ...);
s32 GetLastErrorEx(u32* errorCode, u32* errorType); //800ccb64

}//namespace DWC


#endif