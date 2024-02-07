
/*
ItemBehaviour is a struct containing various information about how an item should behave
Contributors:
  Seeky (main documentation)
  TheLordScruffy (object id field)
References:
  http://wiki.tockdom.com/wiki/Filesystem/rel/StaticR.rel#Item_behaviour_modifier
*/
#ifndef _ITEMBEHAVIOUR_
#define _ITEMBEHAVIOUR_
#include <kamek.hpp>
#include <MarioKartWii/Item/ItemManager.hpp>
#include <MarioKartWii/System/Identifiers.hpp>

namespace Item {
enum UseType {
    ITEMUSE_USE,
    ITEMUSE_FIRE,
    ITEMUSE_TAIL,
    ITEMUSE_CIRCLE
};

struct Behaviour {
    static Behaviour behaviourTable[19]; //809c36a0, index item id, see http://wiki.tockdom.com/wiki/List_of_Identifiers#Items
    u8 unknkown_0x0;
    u8 unknkown_0x1;
    u8 padding[2]; // Ignored when copying to array
    ItemObjId objId; // see http://wiki.tockdom.com/wiki/List_of_Identifiers#Items
    u32 numberOfItems;
    u32 unknown_0xc;
    u8 unknown_0x10;
    u8 padding2[3]; // Ignored when copying to array
    UseType useType;
    void (*useFunction)(Player& player); // Item is draggable if this is null
}; // Total size 0x1c

void CopyItemBehaviourFromRelToTable(); // 807bcae0, copies individual structs from rodata into table
}//namespace Item

#endif