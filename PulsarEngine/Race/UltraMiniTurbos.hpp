#ifndef _PUL_UMT_
#define _PUL_UMT_
#include <kamek.hpp>
#include <MarioKartWii/Effect/EffectMgr.hpp>


namespace Pulsar {
namespace Race {
/*Implements UMTs. This is a fully custom version so it has its own rules:
-It takes 550 frames to charge (300 for a SMT)
-It lasts 1.33x as long as a SMT
-It multiplies the kart speed by 1.27 (1.2 for SMTs)
-As long as it is active, all boosts received by the karts will extend that multiplier boost, allowing snaking that preserves the higher multiplier
-In effect though, that last perk is mostly only useful for charging a MT/SMT on a boost panel that was hit after releasing a UMT
*/

enum UMTeffects { //Chips are not implemented currently due to pure laziness
    rk_driftSpark3L_Spark00,
    rk_driftSpark3L_Spark01,
    rk_driftSpark3R_Spark00,
    rk_driftSpark3R_Spark01,
    rk_purpleBoost,
    rk_purpleBoost_2,
    rk_purpleBoost_3,
    rk_purpleBoost_4
    //rk_driftSpark2L_Chip00,
    //rk_driftSpark2R_Chip00,
    //rk_driftSpark3L1T_Chip00 ,
    //rk_driftSpark3L1T_Spark00,
    //rk_driftSpark3L1T_Spark01,
    //rk_driftSpark3R1T_Chip00,
    //rk_driftSpark3R1T_Spark00,
    //rk_driftSpark3R1T_Spark01
};

class ExpPlayerEffects : public Effects::Player {
public:
    static const int SmtEffectsCount = 8;
    static const int UmtEffectsCount = 8;
    explicit ExpPlayerEffects(Kart::Player* kartPlayer) : Effects::Player(kartPlayer) { };
    ~ExpPlayerEffects() override {
        if (isBike){
            EGG::Effect** array = rk_orangeMT;
            if(array != nullptr) {
                for(int i = 0; i < SmtEffectsCount; ++i) delete(array[i]);
                delete[] array;
            }
        }
        else{ 
            EGG::Effect** array = rk_purpleMT;
            if(array != nullptr) {
                for(int i = 0; i < UmtEffectsCount; ++i) delete(array[i]);
                delete[] array;
            }
        }
    }
    EGG::Effect** rk_purpleMT;
    EGG::Effect** rk_orangeMT;
    static const char* UMTNames[8];
    static const char* SMTNames[8];
};
#endif
}//namespace Race
}//namespace Pulsar