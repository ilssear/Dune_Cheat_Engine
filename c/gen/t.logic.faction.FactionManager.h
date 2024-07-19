// gen time: 2024-07-14 16:37:32 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_logic_faction_FactionManager_h__
#define __gen_t_logic_faction_FactionManager_h__

#include <common.h>
#include <gen/t.logic.Logic.h>

typedef struct String String;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Object ent_Object;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_Event lib_Event;
typedef struct logic_faction_FactionManager logic_faction_FactionManager;


// type: logic.faction.FactionManager, kind: HOBJ, pType: 0x01EC714D1738
struct logic_faction_FactionManager {
  // super: logic.Logic
  logic_Logic               super;

  // cls: logic.faction.FactionManager, begin_offset: 0x0090
  ent_Faction*              owner;              // +0090: HOBJ ent.Faction
  bool                      ownerIsDefeated;    // +0098
  hxbit_ArrayProxyData*     revealCellTargets;  // +00A0: HOBJ hxbit.ArrayProxyData
  void*                     HVIRTUAL_0x00A8;    // +00A8: HVIRTUAL
  // total_size: 0x00B0
}; // logic_faction_FactionManager (logic.faction.FactionManager)

_Static_assert(sizeof(logic_faction_FactionManager) == 0x00B0, "cls logic.faction.FactionManager has wrong size");


extern ent_Faction* logic_faction_FactionManager_get_factionOwner(logic_faction_FactionManager* obj);
extern void logic_faction_FactionManager_onReady(logic_faction_FactionManager* obj);
extern void logic_faction_FactionManager_onEvent(logic_faction_FactionManager* obj, lib_Event* arg1);
extern hl_types_ArrayObj* logic_faction_FactionManager_getAtbApps(logic_faction_FactionManager* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern void logic_faction_FactionManager_addDescAttributeFlat(logic_faction_FactionManager* obj, ent_Object* arg1, int arg2, void* arg3, void* arg4, void* arg5, void* arg6);
extern void logic_faction_FactionManager_addDescAttributeMultiplier(logic_faction_FactionManager* obj, ent_Object* arg1, int arg2, int64 arg3, void* arg4);
extern void logic_faction_FactionManager_addRevealCellTarget(logic_faction_FactionManager* obj, ent_Entity* arg1);
extern void logic_faction_FactionManager_removeRevealCellTarget(logic_faction_FactionManager* obj, ent_Entity* arg1);
extern hxbit_ArrayProxyData* logic_faction_FactionManager_getRevealCellTargets(logic_faction_FactionManager* obj);
extern void logic_faction_FactionManager_onOwnerDefeated(logic_faction_FactionManager* obj);
extern int logic_faction_FactionManager_getCLID(logic_faction_FactionManager* obj);
extern void logic_faction_FactionManager_serialize(logic_faction_FactionManager* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_FactionManager_getSerializeSchema(logic_faction_FactionManager* obj);
extern void logic_faction_FactionManager_unserializeInit(logic_faction_FactionManager* obj);
extern void logic_faction_FactionManager_unserialize(logic_faction_FactionManager* obj, hxbit_Serializer* arg1);
extern ent_Faction* logic_faction_FactionManager___net_mark_owner(logic_faction_FactionManager* obj, ent_Faction* arg1);
extern ent_Faction* logic_faction_FactionManager_set_owner(logic_faction_FactionManager* obj, ent_Faction* arg1);
extern int logic_faction_FactionManager_get_networkPropOwner(logic_faction_FactionManager* obj);
extern hxbit_ArrayProxyData* logic_faction_FactionManager___net_mark_revealCellTargets(logic_faction_FactionManager* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_FactionManager_set_revealCellTargets(logic_faction_FactionManager* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_FactionManager_get_networkPropRevealCellTargets(logic_faction_FactionManager* obj);
extern void logic_faction_FactionManager_networkFlush(logic_faction_FactionManager* obj, hxbit_Serializer* arg1);
extern void logic_faction_FactionManager_networkSync(logic_faction_FactionManager* obj, hxbit_Serializer* arg1);
extern void logic_faction_FactionManager_networkInitProxys(logic_faction_FactionManager* obj);
extern String* logic_faction_FactionManager_networkGetName(logic_faction_FactionManager* obj, int arg1, void* arg2);


#endif // __gen_t_logic_faction_FactionManager_h__
