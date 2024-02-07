#ifndef _ROUTEHOLDER_
#define _ROUTEHOLDER_
#include <kamek.hpp>
#include <MarioKartWii/KMP/KMPManager.hpp>
#include <MarioKartWii/Route/Route.hpp>

class RouteHolder {
    static RouteHolder* sInstance; //809c22b0
    static RouteHolder* CreateInstance; //806f09c8
    static void DestroyInstance(); //806f0a4c
    RouteHolder(); //806f0a3c inlined
    virtual ~RouteHolder(); //806f0a98 vtable 808c7798
    void Init(); //806f0ad8 builds routes/also builds RouteControllers for routes not linked to an object (since the object does it already)
    u32 CreateRoute(const Vec3& pointsArray, u32 pointCount, u32 isCurved, bool isCylic); //806f0e58 returns route id
    void UpdateRoutePoints(u32 id, const Vec3& pointsArray, u32 pointCountToUpdate); //806f0fc8
    float AddRoutePoint(u32 id, const Vec3& point); //806f1064 returns the new total distance
    Route* GetRouteById(u32 id) const; //806f10fc

    Route** routes; //0x4
    Route** nonObjectRoutes; //0x8 essentially the 0x4 array but object routes are nullptr'd
    u16 routeArraySize; //0xC
    u16 nonObjectRoutesArraySize; //0xE
    u8 unknown_0x10;
    u8 padding; //0x11
    u16 curRouteCount; //0x12 doesn't have to take the whole array, for example cameras create routes midrace
    u16 nonObjectLastRouteIdx; //0x14
    bool hasCPUs; //0x16
    u8 unknown_0x17; //0x17
}; //0x18
#endif