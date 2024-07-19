// gen time: 2024-07-14 04:10:50 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_ent_BaseBuilding_h__
#define __gen_t_ent_BaseBuilding_h__

#include <common.h>
#include <gen/t.ent.Entity.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_BaseBuilding ent_BaseBuilding;
typedef struct ent_DeathReason ent_DeathReason;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Structure ent_Structure;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hrt_prefab_Resource hrt_prefab_Resource;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_Application logic_Application;
typedef struct prefab_FXAnimation prefab_FXAnimation;


// type: ent.BaseBuilding, kind: HOBJ, pType: 0x02748E3E4DD8
struct ent_BaseBuilding {
  // super: ent.Entity
  ent_Entity                super;

  // cls: ent.BaseBuilding, begin_offset: 0x0358
  ent_Structure*            structure;          // +0358: HOBJ ent.Structure
  String*                   kind;               // +0360: HOBJ String
  int                       upgradeID;          // +0368
  int                       status;             // +036C
  void*                     inf;                // +0370: HVIRTUAL
  int64                     thisTarget;         // +0378
  double                    airfieldRange;      // +0380
  double                    tempVal;            // +0388
  bool                      playingDeath;       // +0390
  bool                      wasWorking;         // +0391
  // total_size: 0x0392
}; // ent_BaseBuilding (ent.BaseBuilding)

_Static_assert(sizeof(ent_BaseBuilding) == 0x0398, "cls ent.BaseBuilding has wrong size");


extern ent_Faction* ent_BaseBuilding_get_owner(ent_BaseBuilding* obj);
extern bool ent_BaseBuilding_get_isWorking(ent_BaseBuilding* obj);
extern bool ent_BaseBuilding_get_inConstruction(ent_BaseBuilding* obj);
extern String* ent_BaseBuilding_set_kind(ent_BaseBuilding* obj, String* arg1);
extern void ent_BaseBuilding_reload(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_finalize(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_init(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_doRemove(ent_BaseBuilding* obj);
extern bool ent_BaseBuilding_isNotInWorld(ent_BaseBuilding* obj);
extern EReason* ent_BaseBuilding_getAirfieldNoUseReason(ent_BaseBuilding* obj, ent_Faction* arg1, void* arg2);
extern double ent_BaseBuilding_getAirfieldRange(ent_BaseBuilding* obj);
extern double ent_BaseBuilding_getBaseAttackRange(ent_BaseBuilding* obj);
extern double ent_BaseBuilding_getAttackRangeFactor(ent_BaseBuilding* obj);
extern bool ent_BaseBuilding_hasAttacks(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_makeAttackComponents(ent_BaseBuilding* obj);
extern hl_types_ArrayObj* ent_BaseBuilding_getAttackCombos(ent_BaseBuilding* obj, hl_types_ArrayObj* arg1);
extern bool ent_BaseBuilding_checkConditions(ent_BaseBuilding* obj, void* arg1);
extern bool ent_BaseBuilding_checkWorkingConditions(ent_BaseBuilding* obj);
extern int ent_BaseBuilding_getCurrentStatus(ent_BaseBuilding* obj);
extern double ent_BaseBuilding_getConstructionProgress(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_die(ent_BaseBuilding* obj, void* arg1);
extern void ent_BaseBuilding_onDeath(ent_BaseBuilding* obj, ent_DeathReason* arg1);
extern bool ent_BaseBuilding_canAutoRemoveVisual(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_playDeath__impl(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_onFinishConstruction(ent_BaseBuilding* obj);
extern bool ent_BaseBuilding_isMasterpiece(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_applyConstructionFinishedEffects(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_applyDestroyedEffects(ent_BaseBuilding* obj, ent_Faction* arg1);
extern void ent_BaseBuilding_applyEffects(ent_BaseBuilding* obj, int arg1, ent_Faction* arg2);
extern bool ent_BaseBuilding_canRegen(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_onChangeOwner(ent_BaseBuilding* obj, ent_Faction* arg1, ent_Faction* arg2);
extern void ent_BaseBuilding_rpcChangeOwner__impl(ent_BaseBuilding* obj, ent_Faction* arg1, ent_Faction* arg2);
extern void ent_BaseBuilding_updateAttributes(ent_BaseBuilding* obj, double arg1);
extern prefab_FXAnimation* ent_BaseBuilding_playTraitsFx(ent_BaseBuilding* obj, hrt_prefab_Resource* arg1, String* arg2, void* arg3, void* arg4, void* arg5, int arg6, hl_types_ArrayObj* arg7);
extern void ent_BaseBuilding_onTraitStart(ent_BaseBuilding* obj, logic_Application* arg1);
extern void ent_BaseBuilding_updateTraitBlockers(ent_BaseBuilding* obj);
extern hl_types_ArrayObj* ent_BaseBuilding_getAffectingAtbApps(ent_BaseBuilding* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern void ent_BaseBuilding_refreshStatusFX(ent_BaseBuilding* obj);
extern bool ent_BaseBuilding_updateStatus(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_regularUpdate(ent_BaseBuilding* obj, double arg1);
extern EReason* ent_BaseBuilding_getRefundReason(ent_BaseBuilding* obj);
extern bool ent_BaseBuilding_get_refundable(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_doRequestRefund(ent_BaseBuilding* obj);
extern hl_types_ArrayObj* ent_BaseBuilding_getRefund(ent_BaseBuilding* obj);
extern String* ent_BaseBuilding_getRefundTitle(ent_BaseBuilding* obj, void* arg1);
extern String* ent_BaseBuilding_getRefundDesc(ent_BaseBuilding* obj);
extern String* ent_BaseBuilding_getExposedName(ent_BaseBuilding* obj);
extern int ent_BaseBuilding_getCLID(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_serialize(ent_BaseBuilding* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_BaseBuilding_getSerializeSchema(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_unserializeInit(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_unserialize(ent_BaseBuilding* obj, hxbit_Serializer* arg1);
extern ent_Structure* ent_BaseBuilding___net_mark_structure(ent_BaseBuilding* obj, ent_Structure* arg1);
extern ent_Structure* ent_BaseBuilding_set_structure(ent_BaseBuilding* obj, ent_Structure* arg1);
extern int ent_BaseBuilding_get_networkPropStructure(ent_BaseBuilding* obj);
extern String* ent_BaseBuilding___net_mark_kind(ent_BaseBuilding* obj, String* arg1);
extern int ent_BaseBuilding_get_networkPropKind(ent_BaseBuilding* obj);
extern int ent_BaseBuilding___net_mark_upgradeID(ent_BaseBuilding* obj, int arg1);
extern int ent_BaseBuilding_set_upgradeID(ent_BaseBuilding* obj, int arg1);
extern int ent_BaseBuilding_get_networkPropUpgradeID(ent_BaseBuilding* obj);
extern int ent_BaseBuilding___net_mark_status(ent_BaseBuilding* obj, int arg1);
extern int ent_BaseBuilding_set_status(ent_BaseBuilding* obj, int arg1);
extern int ent_BaseBuilding_get_networkPropStatus(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_playDeath(ent_BaseBuilding* obj);
extern void ent_BaseBuilding_rpcChangeOwner(ent_BaseBuilding* obj, ent_Faction* arg1, ent_Faction* arg2);
extern void ent_BaseBuilding_networkFlush(ent_BaseBuilding* obj, hxbit_Serializer* arg1);
extern void ent_BaseBuilding_networkSync(ent_BaseBuilding* obj, hxbit_Serializer* arg1);
extern bool ent_BaseBuilding_networkRPC(ent_BaseBuilding* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_BaseBuilding_networkGetName(ent_BaseBuilding* obj, int arg1, void* arg2);


#endif // __gen_t_ent_BaseBuilding_h__
