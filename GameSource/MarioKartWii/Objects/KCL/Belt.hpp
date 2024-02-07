#ifndef _BELT_CROSSING_
#define _BELT_CROSSING_
#include <kamek.hpp>
#include <MarioKartWii/Objects/KCL/ObjectKCL.hpp>

namespace Objects {

class Belt : public ObjectKCL {
public:
    //explicit Belt(KMP::Holder<GOBJ>) inlined
    ~Belt() override; //807fc5ec vtable 808d4768
    u32 GetPropertiesBitfield() override; //0x2c 807fd79c
    void LoadAnimations() override; //0x5c 807fd860
    void LoadCollision() override; //0x60 807fd798
    void UpdateCollision() override; //0x74 807fd794
    float GetCollisionDiameter() const override; //0xa0 807fd784
    u32 GetDrawType() const override; //0xb0 807fd930
    void vf_0xb4() override; //0xb4 807fd790

    bool vf_0xc0(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xc0 807fd750
    bool vf_0xc4(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xc4 807fd758
    bool vf_0xc8(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xc8 807fd760
    bool vf_0xcc(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xcc 807fd768

    bool IsCollidingNoTerrainInfoNoTriangleCheck(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xd0 807fd728
    bool IsCollidingAddEntryNoTerrainInfoNoTriangleCheck(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xd4 807fd730
    bool IsColliding(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xd8 807fd738
    bool IsCollidingNoTriangleCheck(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xdc 807fd740

    bool IsCollidingNoTerrainInfo(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret) override; //0xe4 807fd6f4
    bool IsCollidingAddEntryNoTerrainInfo(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret) override; //0xe8 807fd6fc
    bool vf_0xec(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret) override; //0xec 807fd704
    bool IsCollidingAddEntry(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret) override; //0xf0 807fd70c

    bool IsCollidingNoTerrainInfo(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xf4 807fd6cc
    bool IsCollidingAddEntryNoTerrainInfo(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xf8 807fd6d4
    bool vf_0xfc(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0xfc 807fd6dc
    bool IsCollidingAddEntry(const Vec3& pos, const Vec3& prevPos, KCLBitfield accepted, CollisionInfo* info,
        KCLTypeHolder* ret, u32 initialTime, float radius) override; //0x100 807fd6e4

    bool AreItemsAllowed() override; //0x104 807fd6c4
    float vf_0x108() override; //0x108 807fd6b8
    void SetObjInfoIsFilled(CollisionInfo::ObjInfo* objInfo) const override; //0x10c 807fd7fc
    void CalcOtherEntityDistance(CollisionInfo::ObjInfo* otherEntityObjInfo, const Vec3& otherEntityInitialPosition) override; //0x110 807fd6b4
    void UpdateOtherEntityPos(CollisionInfo::ObjInfo* otherEntityObjInfo, Vec3& newEntityPos) override; //0x114 807fd6b0
    void UpdateOtherEntityPosWithRot(CollisionInfo::ObjInfo* otherEntityObjInfo, Vec3& newEntityPos, Vec3& newEntityDir) override; //0x118 807fd6ac
    int vf_0x11c(CollisionInfo::ObjInfo* otherEntityObjInfo) override; //0x11c 807fd6a4
    virtual void vf_0x120(); //0x120 807fc294
    virtual void vf_0x124() = 0; //0x124
    virtual void vf_0x128() = 0; //0x128
    virtual void vf_0x12C(); //0x128 807fd80c
    float speed; //as an absolute value
};
size_assert(Belt, 0xB0);

class BeltEasy : public Belt { //ObjectNum 0x25a = 602
    explicit BeltEasy(const KMP::Holder<GOBJ>& gobjHolder); //807fc578
    ~BeltEasy() override; //807fd8f0 vtable 808d4638
    u32 GetDrawType() const override; //0xb0 807fd8e8
    void vf_0x124() override; //0x124 807fc62c
    void vf_0x128() override; //0x128 807fc6c8
    float unknown_0xB0;
}; //0xb4

class BeltCrossing : public Belt { //ObjectNum 0x25b = 603
public:
    explicit BeltCrossing(const KMP::Holder<GOBJ>& gobjHolder); //807fc764
    ~BeltCrossing() override; //807fd8a8 vtable 808d4508
    u32 GetDrawType() const override; //0xb0 807fd8a0
    void vf_0x124() override; //0x124 807fc7d8
    void vf_0x128() override; //0x128 807fc874
    float unknown_0xB0;
}; //0xb4

class BeltCurveA : public Belt { //ObjectNum 0x25c = 604
    explicit BeltCurveA(const KMP::Holder<GOBJ>& gobjHolder); //807fc90c
    ~BeltCurveA() override; //807fd7bc vtable 808d43d8
    void OnStart() override; //0xC 807fd1ac
    void Update() override; //0x14 807fd1b4
    void LoadModels() override; //0x44 807fccfc
    void LoadAnimations() override; //0x5c 807fcde8
    void UpdateModelMatrix() override; //0x6c 807fd0e8
    u32 GetDrawType() const override; //0xb0 807fd7b4
    void SetObjInfoIsFilled(CollisionInfo::ObjInfo* objInfo) const override; //0x10c 807fd7a4
    void vf_0x124() override; //0x124 807fc9d4
    void vf_0x128() override; //0x128 807fcca4
    void vf_0x12C() override; //0x12C 807fd38c
    u8 initialFastSide; //0xb4 0: right is green first, 1: left is green first
    u8 padding[3];
    u32 framesUntilSwitch; //0xb8
    u32 framesUntilSwitchBack; //0xbc
    ModelDirector* beltCurveB; //0xc0
    ModelDirector* beltCurveC; //0xc4
    Mtx34 speedMtx; //0xc8 instead of a float since this has xz components
};
}//namespace Objects
#endif