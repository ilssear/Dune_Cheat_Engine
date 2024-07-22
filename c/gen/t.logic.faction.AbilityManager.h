// gen time: 2024-07-21 07:22:25 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_AbilityManager_h__
#define __gen_t_logic_faction_AbilityManager_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct DisplayTarget DisplayTarget;
typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Object ent_Object;
typedef struct ent_Zone ent_Zone;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct haxe_ds_StringMap haxe_ds_StringMap;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_Logic logic_Logic;
typedef struct logic_faction_Ability logic_faction_Ability;
typedef struct logic_faction_AbilityManager logic_faction_AbilityManager;
typedef struct logic_faction_ActiveAbility logic_faction_ActiveAbility;


// type: logic.faction.AbilityManager, kind: HOBJ, pType: 0x02A76E3238D8
struct logic_faction_AbilityManager {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.AbilityManager, begin_offset: 0x00B0
  hxbit_ArrayProxyData*     cooldowns;          // +00B0: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     ongoingAbilities;   // +00B8: HOBJ hxbit.ArrayProxyData
  logic_faction_Ability*    selectedAbility;    // +00C0: HOBJ logic.faction.Ability
  hl_types_ArrayObj*        tmpAffectedUnits;   // +00C8: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        tmpAbilityTargets;  // +00D0: HOBJ hl.types.ArrayObj
  void*                     cdDummy;            // +00D8: HVIRTUAL
  // total_size: 0x00E0
}; // logic_faction_AbilityManager (logic.faction.AbilityManager)

_Static_assert(sizeof(logic_faction_AbilityManager) == 0x00E0, "cls logic.faction.AbilityManager has wrong size");


extern void logic_faction_AbilityManager_patchEntity(logic_faction_AbilityManager* obj, int arg1);
extern bool logic_faction_AbilityManager_isDisplayable(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, ent_Faction* arg3);
extern EReason* logic_faction_AbilityManager_checkDisplayable(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, ent_Faction* arg3);
extern hl_types_ArrayObj* logic_faction_AbilityManager_getRefundAmount(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2);
extern EReason* logic_faction_AbilityManager_implCancelAbility(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2);
extern EReason* logic_faction_AbilityManager_implToggleOffAbility(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, void* arg3);
extern bool logic_faction_AbilityManager_forceCancelAbility(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2);
extern void logic_faction_AbilityManager_doCancelAbility__impl(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2, void* arg3);
extern void logic_faction_AbilityManager_cancelObsolete(logic_faction_AbilityManager* obj, DisplayTarget* arg1, ent_Faction* arg2, bool arg3, void* arg4);
extern void logic_faction_AbilityManager_autoTrigger(logic_faction_AbilityManager* obj, DisplayTarget* arg1, int arg2);
extern EReason* logic_faction_AbilityManager_getBlocking(logic_faction_AbilityManager* obj, void* arg1, ent_Entity* arg2, void* arg3);
extern EReason* logic_faction_AbilityManager_resolveDiplomaticStatusValidity(logic_faction_AbilityManager* obj, void* arg1, ent_Entity* arg2);
extern EReason* logic_faction_AbilityManager_implUseAbility(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, ent_Faction* arg3, void* arg4, void* arg5, void* arg6);
extern void logic_faction_AbilityManager_useAbilityOnConfirm(logic_faction_AbilityManager* obj, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5);
extern EReason* logic_faction_AbilityManager_implUseAbilityOn(logic_faction_AbilityManager* obj, String* arg1, void* arg2, void* arg3, void* arg4);
extern void logic_faction_AbilityManager_doUseAbilityOn(logic_faction_AbilityManager* obj, void* arg1, void* arg2);
extern logic_Logic* logic_faction_AbilityManager_getApplyTarget(logic_faction_AbilityManager* obj, void* arg1, void* arg2);
extern double logic_faction_AbilityManager_getCostMultiplier(logic_faction_AbilityManager* obj, void* arg1, String* arg2, DisplayTarget* arg3);
extern hl_types_ArrayObj* logic_faction_AbilityManager_getTargetCost(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, h2d_col_PointImpl* arg3, ent_Zone* arg4, ent_Faction* arg5, void* arg6, hl_types_ArrayObj* arg7);
extern hl_types_ArrayObj* logic_faction_AbilityManager_getCost(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, void* arg3);
extern hl_types_ArrayObj* logic_faction_AbilityManager_getAbilityReplacementCost(logic_faction_AbilityManager* obj, String* arg1, hl_types_ArrayObj* arg2);
extern void logic_faction_AbilityManager_getAbilityArmyTargets(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, hl_types_ArrayObj* arg3);
extern haxe_ds_StringMap* logic_faction_AbilityManager_getActiveAbilitiesUpkeep(logic_faction_AbilityManager* obj, String* arg1);
extern void* logic_faction_AbilityManager_doUseAbility(logic_faction_AbilityManager* obj, void* arg1, void* arg2);
extern bool logic_faction_AbilityManager_abilityCanBeUsedOn(logic_faction_AbilityManager* obj, void* arg1, void* arg2, void* arg3);
extern EReason* logic_faction_AbilityManager_noUseReasonOn(logic_faction_AbilityManager* obj, void* arg1, void* arg2, void* arg3);
extern double logic_faction_AbilityManager_getInitTime(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2);
extern double logic_faction_AbilityManager_getCooldownRatio(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2);
extern void* logic_faction_AbilityManager_getCurrentCooldownInfo(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2);
extern void* logic_faction_AbilityManager_getCooldown(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2);
extern void logic_faction_AbilityManager_setCooldown(logic_faction_AbilityManager* obj, void* arg1, double arg2, DisplayTarget* arg3);
extern logic_faction_ActiveAbility* logic_faction_AbilityManager_getProgress(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2);
extern void logic_faction_AbilityManager_applyOtherEffectFXs(logic_faction_AbilityManager* obj, void* arg1, hl_types_ArrayObj* arg2, String* arg3);
extern void logic_faction_AbilityManager_onAbilityEnd(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2, ent_Object* arg3, bool arg4, h2d_col_PointImpl* arg5, logic_faction_ActiveAbility* arg6);
extern EReason* logic_faction_AbilityManager_getCancellationBlockReason(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2);
extern bool logic_faction_AbilityManager_isCurrentlyActive(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2);
extern bool logic_faction_AbilityManager_isCurrentlyActiveOn(logic_faction_AbilityManager* obj, String* arg1, ent_Object* arg2);
extern bool logic_faction_AbilityManager_activeAbilityIsOver(logic_faction_AbilityManager* obj, logic_faction_ActiveAbility* arg1);
extern bool logic_faction_AbilityManager_activeAbilityIs(logic_faction_AbilityManager* obj, logic_faction_ActiveAbility* arg1, String* arg2, DisplayTarget* arg3);
extern logic_faction_ActiveAbility* logic_faction_AbilityManager_getActiveAbility(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2, void* arg3);
extern hl_types_ArrayObj* logic_faction_AbilityManager_getActiveAbilities(logic_faction_AbilityManager* obj, DisplayTarget* arg1, void* arg2);
extern void logic_faction_AbilityManager_onTick(logic_faction_AbilityManager* obj, logic_faction_ActiveAbility* arg1);
extern void logic_faction_AbilityManager_tickAbility(logic_faction_AbilityManager* obj, logic_faction_ActiveAbility* arg1, double arg2);
extern void logic_faction_AbilityManager_update(logic_faction_AbilityManager* obj, double arg1);
extern EReason* logic_faction_AbilityManager_cancelAbility(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2, void* arg3);
extern bool logic_faction_AbilityManager_rpcCancelAbility__impl(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2);
extern EReason* logic_faction_AbilityManager_checkCancelAbility(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2);
extern bool logic_faction_AbilityManager_canCancelAbility(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2);
extern EReason* logic_faction_AbilityManager_toggleOffAbility(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, void* arg3);
extern EReason* logic_faction_AbilityManager_checkToggleOffAbility(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, void* arg3);
extern bool logic_faction_AbilityManager_canToggleOffAbility(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, void* arg3);
extern EReason* logic_faction_AbilityManager_useAbility(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, ent_Faction* arg3, void* arg4, void* arg5, void* arg6);
extern EReason* logic_faction_AbilityManager_checkUseAbility(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, ent_Faction* arg3, void* arg4, void* arg5, void* arg6);
extern bool logic_faction_AbilityManager_canUseAbility(logic_faction_AbilityManager* obj, void* arg1, DisplayTarget* arg2, ent_Faction* arg3, void* arg4, void* arg5, void* arg6);
extern EReason* logic_faction_AbilityManager_useAbilityOn(logic_faction_AbilityManager* obj, String* arg1, void* arg2, void* arg3, void* arg4, void* arg5);
extern bool logic_faction_AbilityManager_rpcUseAbilityOn__impl(logic_faction_AbilityManager* obj, String* arg1, void* arg2, void* arg3, void* arg4);
extern EReason* logic_faction_AbilityManager_checkUseAbilityOn(logic_faction_AbilityManager* obj, String* arg1, void* arg2, void* arg3, void* arg4);
extern bool logic_faction_AbilityManager_canUseAbilityOn(logic_faction_AbilityManager* obj, String* arg1, void* arg2, void* arg3, void* arg4);
extern hxbit_ArrayProxyData* logic_faction_AbilityManager___net_mark_cooldowns(logic_faction_AbilityManager* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_AbilityManager_set_cooldowns(logic_faction_AbilityManager* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_AbilityManager_get_networkPropCooldowns(logic_faction_AbilityManager* obj);
extern hxbit_ArrayProxyData* logic_faction_AbilityManager___net_mark_ongoingAbilities(logic_faction_AbilityManager* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_AbilityManager_set_ongoingAbilities(logic_faction_AbilityManager* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_AbilityManager_get_networkPropOngoingAbilities(logic_faction_AbilityManager* obj);
extern void logic_faction_AbilityManager_doCancelAbility(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2, void* arg3);
extern void logic_faction_AbilityManager_rpcCancelAbility(logic_faction_AbilityManager* obj, String* arg1, DisplayTarget* arg2, void* arg3);
extern void logic_faction_AbilityManager_rpcUseAbilityOn(logic_faction_AbilityManager* obj, String* arg1, void* arg2, void* arg3, void* arg4, void* arg5);
extern void logic_faction_AbilityManager_networkFlush(logic_faction_AbilityManager* obj, hxbit_Serializer* arg1);
extern void logic_faction_AbilityManager_networkSync(logic_faction_AbilityManager* obj, hxbit_Serializer* arg1);
extern void logic_faction_AbilityManager_networkInitProxys(logic_faction_AbilityManager* obj);
extern bool logic_faction_AbilityManager_networkRPC(logic_faction_AbilityManager* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* logic_faction_AbilityManager_networkGetName(logic_faction_AbilityManager* obj, int arg1, void* arg2);
extern int logic_faction_AbilityManager_getCLID(logic_faction_AbilityManager* obj);
extern void logic_faction_AbilityManager_serialize(logic_faction_AbilityManager* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_AbilityManager_getSerializeSchema(logic_faction_AbilityManager* obj);
extern void logic_faction_AbilityManager_unserializeInit(logic_faction_AbilityManager* obj);
extern void logic_faction_AbilityManager_unserialize(logic_faction_AbilityManager* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_AbilityManager_h__
