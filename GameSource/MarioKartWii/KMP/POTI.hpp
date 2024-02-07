#ifndef _POTI_
#define _POTI_
#include <MarioKartWii/KMP/KMPBlockBase.hpp>

struct POTIPoint {
    Vec3 position;
    u16 settings[2]; //0x10 speed and then object specific setting
};


struct POTI { //routes
    u16 pointCount;
    bool isCurved;
    bool isNotCyclic;
    //Points points each entry has an array of points
};

typedef struct KMPBlock<POTI> POTIBlock;

#endif