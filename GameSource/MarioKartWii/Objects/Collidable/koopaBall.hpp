#ifndef _KOOPABALL_
#define _KOOPABALL_
#include <kamek.hpp>
#include <MarioKartWii/Objects/Collidable/ObjectCollidable.hpp>

namespace Objects {

class KoopaBall : public ObjectCollidable { //ObjectNum 0xcf = 207
    explicit KoopaBall(const KMP::Holder<GOBJ>& gobjHolder); //80770384
    ~KoopaBall() override; //80771f70 vtable 808cf410
    void OnStart() override; //0xC 807703d0
    void Update() override; //0x14 80770adc
    u32 GetPropertiesBitfield() override; //0x2c 80771f68
    void UpdateShadow() override; //0x70 80771e24
    ObjToKartHit OnCollision(const Kart::Player& kartPlayer, ObjToKartHit default, KartToObjHit kartToObj) const override; //0xc0 80771bf4
    const Vec3& GetCollisionTranslation() const override; //0xd4 80771f60

}; //0x130

}//namespace Objects



#endif