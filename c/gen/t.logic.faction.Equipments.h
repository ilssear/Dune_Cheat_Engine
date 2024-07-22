// gen time: 2024-07-21 07:22:47 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_Equipments_h__
#define __gen_t_logic_faction_Equipments_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_Equipments logic_faction_Equipments;


// type: logic.faction.Equipments, kind: HOBJ, pType: 0x02A76E320EF8
struct logic_faction_Equipments {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.Equipments, begin_offset: 0x00B0
  hxbit_MapData*            equipped;           // +00B0: HOBJ hxbit.MapData
  bool                      barracksHasBeenOpened; // +00B8
  // total_size: 0x00B9
}; // logic_faction_Equipments (logic.faction.Equipments)

_Static_assert(sizeof(logic_faction_Equipments) == 0x00C0, "cls logic.faction.Equipments has wrong size");


extern void logic_faction_Equipments_onReady(logic_faction_Equipments* obj);
extern void logic_faction_Equipments_init(logic_faction_Equipments* obj);
extern void logic_faction_Equipments_patchEntity(logic_faction_Equipments* obj, int arg1);
extern hl_types_ArrayObj* logic_faction_Equipments_getEquippableUnits(logic_faction_Equipments* obj);
extern int logic_faction_Equipments_getEquippedCount(logic_faction_Equipments* obj);
extern bool logic_faction_Equipments_hasUnlockedSlot(logic_faction_Equipments* obj, int arg1);
extern bool logic_faction_Equipments_canEdit(logic_faction_Equipments* obj);
extern void logic_faction_Equipments_refreshEquipments(logic_faction_Equipments* obj);
extern EReason* logic_faction_Equipments_implRemoveEquipment(logic_faction_Equipments* obj, String* arg1, String* arg2, void* arg3);
extern EReason* logic_faction_Equipments_getApplyAnyReason(logic_faction_Equipments* obj, String* arg1, int arg2);
extern EReason* logic_faction_Equipments_implApply(logic_faction_Equipments* obj, String* arg1, String* arg2, int arg3);
extern hl_types_ArrayObj* logic_faction_Equipments_getRemoveCost(logic_faction_Equipments* obj, void* arg1, void* arg2, int arg3);
extern hxbit_ArrayProxyData* logic_faction_Equipments_getCurrentFor(logic_faction_Equipments* obj, void* arg1);
extern int logic_faction_Equipments_countCurrentFor(logic_faction_Equipments* obj, void* arg1);
extern int logic_faction_Equipments_getMaxSlots(logic_faction_Equipments* obj, String* arg1);
extern int logic_faction_Equipments_getBaseMaxSlots(logic_faction_Equipments* obj);
extern int logic_faction_Equipments_countUsedExtraSlots(logic_faction_Equipments* obj);
extern bool logic_faction_Equipments_isExtraSlot(logic_faction_Equipments* obj, String* arg1, int arg2);
extern bool logic_faction_Equipments_isUsingExtraSlot(logic_faction_Equipments* obj, String* arg1);
extern EReason* logic_faction_Equipments_removeEquipment(logic_faction_Equipments* obj, String* arg1, String* arg2, void* arg3, void* arg4);
extern bool logic_faction_Equipments_rpcRemoveEquipment__impl(logic_faction_Equipments* obj, String* arg1, String* arg2, void* arg3);
extern EReason* logic_faction_Equipments_checkRemoveEquipment(logic_faction_Equipments* obj, String* arg1, String* arg2, void* arg3);
extern bool logic_faction_Equipments_canRemoveEquipment(logic_faction_Equipments* obj, String* arg1, String* arg2, void* arg3);
extern EReason* logic_faction_Equipments_apply(logic_faction_Equipments* obj, String* arg1, String* arg2, int arg3, void* arg4);
extern bool logic_faction_Equipments_rpcApply__impl(logic_faction_Equipments* obj, String* arg1, String* arg2, int arg3);
extern EReason* logic_faction_Equipments_checkApply(logic_faction_Equipments* obj, String* arg1, String* arg2, int arg3);
extern bool logic_faction_Equipments_canApply(logic_faction_Equipments* obj, String* arg1, String* arg2, int arg3);
extern hxbit_MapData* logic_faction_Equipments___net_mark_equipped(logic_faction_Equipments* obj, hxbit_MapData* arg1);
extern hxbit_MapData* logic_faction_Equipments_set_equipped(logic_faction_Equipments* obj, hxbit_MapData* arg1);
extern int logic_faction_Equipments_get_networkPropEquipped(logic_faction_Equipments* obj);
extern void logic_faction_Equipments_rpcRemoveEquipment(logic_faction_Equipments* obj, String* arg1, String* arg2, void* arg3, void* arg4);
extern void logic_faction_Equipments_rpcApply(logic_faction_Equipments* obj, String* arg1, String* arg2, int arg3, void* arg4);
extern void logic_faction_Equipments_networkFlush(logic_faction_Equipments* obj, hxbit_Serializer* arg1);
extern void logic_faction_Equipments_networkSync(logic_faction_Equipments* obj, hxbit_Serializer* arg1);
extern void logic_faction_Equipments_networkInitProxys(logic_faction_Equipments* obj);
extern bool logic_faction_Equipments_networkRPC(logic_faction_Equipments* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* logic_faction_Equipments_networkGetName(logic_faction_Equipments* obj, int arg1, void* arg2);
extern int logic_faction_Equipments_getCLID(logic_faction_Equipments* obj);
extern void logic_faction_Equipments_serialize(logic_faction_Equipments* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_Equipments_getSerializeSchema(logic_faction_Equipments* obj);
extern void logic_faction_Equipments_unserializeInit(logic_faction_Equipments* obj);
extern void logic_faction_Equipments_unserialize(logic_faction_Equipments* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_Equipments_h__
