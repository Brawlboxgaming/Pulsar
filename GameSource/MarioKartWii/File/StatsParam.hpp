#ifndef _STATSPARAM_
#define _STATSPARAM_
#include <kamek.hpp>
//https://wiki.tockdom.com/wiki/KartParam.bin
//https://wiki.tockdom.com/wiki/DriverParam.bin

enum WheelCount {
    WHEELS_4_COUNT,
    WHEELS_2_COUNT,
    WHEELS_2_QUACKER,
    WHEELS_3_BLUE_FALCON
};

enum KartType {
    KART = 0x0,
    OUTSIDE_BIKE = 0x1,
    INSIDE_BIKE = 0x2
};



struct StatsParamFile {
    struct Entry { //https://wiki.tockdom.com/wiki/KartParam.bin
        WheelCount wheelCount;
        KartType type;
        u32 weightClass;
        float float_0xC;
        float weight; //0x10
        float bumpDeviationLevel; //0x14
        float baseSpeed; //0x18
        float handlingSpeedMultiplier; //0x1c
        float tilt; //0x20
        float standard_acceleration_as[4]; //0x24
        float standard_acceleration_ts[3]; //0x34
        float drift_acceleration_as[2]; //0x40
        float drift_acceleration_ts[1]; //0x48
        float manualHandling; //0x4c
        float autoHandling; //0x50
        float handlingReactivity; //0x54
        float manualDrift; //0x58
        float automaticDrift; //0x5c
        float driftReactivity; //0x60
        float targetAngle; //0x64
        float unknown_0x68;
        u32 mt;
        float speedFactors[32];
        float handlingFactors[32];
        float rotatingItemObjParams[4];
        float vertical_tilt; //0x184
        float megaScale;
        float unknown_0x188;
    }; //total size 0x18c
    u32 entryCount; //kart/driver count
    Entry entries[1]; //array of size entrycount
};

typedef StatsParamFile KartParamBin;
typedef StatsParamFile DriverParamBin;


#endif