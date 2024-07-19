// gen time: 2024-07-14 04:39:47 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_ent_Object_h__
#define __gen_t_ent_Object_h__

#include <common.h>
#include <gen/t.logic.Logic.h>

typedef struct EScope EScope;
typedef struct ESourceKind ESourceKind;
typedef struct ETargetKind ETargetKind;
typedef struct ProductionKind ProductionKind;
typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Object ent_Object;
typedef struct ent_Resources ent_Resources;
typedef struct ent_Structure ent_Structure;
typedef struct haxe_ds_ObjectMap haxe_ds_ObjectMap;
typedef struct haxe_ds_StringMap haxe_ds_StringMap;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hrt_prefab_Resource hrt_prefab_Resource;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_Application logic_Application;
typedef struct logic_AttributeApplication logic_AttributeApplication;
typedef struct logic_AttributesManager logic_AttributesManager;
typedef struct logic_TradeManager logic_TradeManager;
typedef struct logic_TraitsManager logic_TraitsManager;
typedef struct net_Serializable net_Serializable;
typedef struct prefab_FXAnimation prefab_FXAnimation;


// type: ent.Object, kind: HOBJ, pType: 0x02748E3E4598
struct ent_Object {
  // super: logic.Logic
  logic_Logic               super;

  // cls: ent.Object, begin_offset: 0x0090
  logic_AttributesManager*  attributes;         // +0090: HOBJ logic.AttributesManager
  ent_Resources*            resources;          // +0098: HOBJ ent.Resources
  net_Serializable*         _traits;            // +00A0: HOBJ net.Serializable
  haxe_ds_StringMap*        traitsFx;           // +00A8: HOBJ haxe.ds.StringMap
  hl_types_ArrayObj*        traitsFxIds;        // +00B0: HOBJ hl.types.ArrayObj
  logic_TradeManager*       tradeManager;       // +00B8: HOBJ logic.TradeManager
  hxbit_MapData*            chosenConsts;       // +00C0: HOBJ hxbit.MapData
  haxe_ds_ObjectMap*        atbValCache;        // +00C8: HOBJ haxe.ds.ObjectMap
  haxe_ds_ObjectMap*        atbHasCache;        // +00D0: HOBJ haxe.ds.ObjectMap
  double                    atbClearTimer;      // +00D8
  // total_size: 0x00E0
}; // ent_Object (ent.Object)

_Static_assert(sizeof(ent_Object) == 0x00E0, "cls ent.Object has wrong size");


extern logic_TraitsManager* ent_Object_get_traits(ent_Object* obj);
extern bool ent_Object_get_noAttributes(ent_Object* obj);
extern bool ent_Object_isDead(ent_Object* obj);
extern bool ent_Object_smartAtbCacheClear(ent_Object* obj);
extern void ent_Object_regularUpdate(ent_Object* obj, double arg1);
extern void ent_Object_frameUpdate(ent_Object* obj, double arg1);
extern void ent_Object_serverFrameUpdate(ent_Object* obj, double arg1);
extern void ent_Object_frameRegularUpdate(ent_Object* obj, double arg1);
extern void ent_Object_doRemove(ent_Object* obj);
extern void ent_Object_init(ent_Object* obj);
extern void ent_Object_onReady(ent_Object* obj);
extern void ent_Object_reload(ent_Object* obj);
extern void ent_Object_patchEntity(ent_Object* obj, int arg1);
extern void ent_Object_initFxs(ent_Object* obj);
extern String* ent_Object_getExposedName(ent_Object* obj);
extern String* ent_Object_getExposedRichName(ent_Object* obj);
extern logic_AttributeApplication* ent_Object_addAttribute(ent_Object* obj, String* arg1, void* arg2, ESourceKind* arg3, ETargetKind* arg4, ETargetKind* arg5, EScope* arg6, ent_Faction* arg7);
extern logic_AttributeApplication* ent_Object_addAttributeRaw(ent_Object* obj, int arg1, void* arg2);
extern void ent_Object_propagateClearAtbCache(ent_Object* obj, int arg1, EScope* arg2, void* arg3, logic_AttributeApplication* arg4);
extern void ent_Object_forceFullAtbCacheClear(ent_Object* obj);
extern void ent_Object_triggerCache(ent_Object* obj, int arg1, EScope* arg2, void* arg3, logic_AttributeApplication* arg4);
extern bool ent_Object_removeAttribute(ent_Object* obj, int arg1);
extern hl_types_ArrayObj* ent_Object_getAtbApps(ent_Object* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4, void* arg5);
extern hl_types_ArrayObj* ent_Object_appendAtbApps(ent_Object* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4, void* arg5);
extern hl_types_ArrayObj* ent_Object_appendUniqueAtbApps(ent_Object* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern hl_types_ArrayObj* ent_Object_getAffectingAtbApps(ent_Object* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern bool ent_Object_hasAttribute(ent_Object* obj, int arg1, void* arg2, ent_Faction* arg3, ent_Object* arg4);
extern bool ent_Object_hasAtbUId(ent_Object* obj, int arg1);
extern double ent_Object_getAtbVal(ent_Object* obj, int arg1, void* arg2, ent_Faction* arg3);
extern int ent_Object_getAtbCount(ent_Object* obj, int arg1, void* arg2, ent_Faction* arg3);
extern ent_Object* ent_Object_getAttributeInstigator(ent_Object* obj, logic_AttributeApplication* arg1);
extern logic_Application* ent_Object_getAttributeSourceTrait(ent_Object* obj, logic_AttributeApplication* arg1);
extern ent_Structure* ent_Object_getAttributeSourceUpgradeStruct(ent_Object* obj, logic_AttributeApplication* arg1);
extern void* ent_Object_getAttributeSourceTreaty(ent_Object* obj, logic_AttributeApplication* arg1);
extern String* ent_Object_getModifiedTrait(ent_Object* obj, String* arg1);
extern void ent_Object_onTraitStart(ent_Object* obj, logic_Application* arg1);
extern void ent_Object_onTraitApplicationEffects__impl(ent_Object* obj, logic_Application* arg1);
extern int ent_Object_getStackingLimit(ent_Object* obj, String* arg1);
extern bool ent_Object_reachedStackLimit(ent_Object* obj, String* arg1, ent_Faction* arg2);
extern void ent_Object_onTraitStartEffects(ent_Object* obj, logic_Application* arg1);
extern void ent_Object_onTraitEnd(ent_Object* obj, logic_Application* arg1, bool arg2);
extern void ent_Object_onTraitEndEffects(ent_Object* obj, logic_Application* arg1, bool arg2);
extern void ent_Object_initTraitsFx(ent_Object* obj);
extern void ent_Object_syncTraitFxs(ent_Object* obj, String* arg1);
extern bool ent_Object_hasTraitFxs(ent_Object* obj, String* arg1);
extern void ent_Object_updateTraitFxs(ent_Object* obj, double arg1);
extern void ent_Object_addTraitFxs(ent_Object* obj, String* arg1);
extern void ent_Object_removeTraitFxs(ent_Object* obj, String* arg1);
extern prefab_FXAnimation* ent_Object_playFX(ent_Object* obj, hrt_prefab_Resource* arg1, String* arg2, void* arg3, void* arg4);
extern prefab_FXAnimation* ent_Object_playTraitsFx(ent_Object* obj, hrt_prefab_Resource* arg1, String* arg2, void* arg3, void* arg4, void* arg5, int arg6, hl_types_ArrayObj* arg7);
extern void ent_Object_playSound(ent_Object* obj, String* arg1, String* arg2);
extern void ent_Object_tryPlaySound(ent_Object* obj, String* arg1);
extern void* ent_Object_getBaseMaxResStock(ent_Object* obj, String* arg1);
extern void* ent_Object_getMaxResStock(ent_Object* obj, String* arg1);
extern double ent_Object_getResource(ent_Object* obj, int arg1);
extern void ent_Object_emptyResources(ent_Object* obj);
extern hl_types_ArrayObj* ent_Object_getAllResources(ent_Object* obj);
extern hl_types_ArrayObj* ent_Object_getResourcesDetails(ent_Object* obj);
extern bool ent_Object_hasResource(ent_Object* obj, int arg1, double arg2);
extern bool ent_Object_hasResources(ent_Object* obj, hl_types_ArrayObj* arg1);
extern double ent_Object_getMissingResource(ent_Object* obj, String* arg1, double arg2);
extern hl_types_ArrayObj* ent_Object_getMissingResources(ent_Object* obj, hl_types_ArrayObj* arg1);
extern bool ent_Object_useResource(ent_Object* obj, String* arg1, double arg2, void* arg3);
extern bool ent_Object_useResources(ent_Object* obj, hl_types_ArrayObj* arg1, void* arg2);
extern bool ent_Object_hasAnyResource(ent_Object* obj);
extern void ent_Object_setResource(ent_Object* obj, String* arg1, double arg2);
extern bool ent_Object_hasAccessToRes(ent_Object* obj, int arg1);
extern double ent_Object_addResource(ent_Object* obj, String* arg1, double arg2, void* arg3, void* arg4);
extern void ent_Object_addResources(ent_Object* obj, hl_types_ArrayObj* arg1, void* arg2, void* arg3);
extern void ent_Object_consumeResources(ent_Object* obj, hl_types_ArrayObj* arg1, void* arg2, void* arg3);
extern void ent_Object_addDescAttributeFlat(ent_Object* obj, ent_Object* arg1, int arg2, void* arg3, void* arg4, void* arg5, void* arg6);
extern void ent_Object_addDescAttributeMultiplier(ent_Object* obj, ent_Object* arg1, int arg2, int64 arg3, void* arg4);
extern double ent_Object_getTransactionableResourceProduction(ent_Object* obj, String* arg1, ProductionKind* arg2, void* arg3, void* arg4);
extern ent_Object* ent_Object_getTransactionReceiver(ent_Object* obj);
extern hl_types_ArrayObj* ent_Object_getTransactionResultsFromSource(ent_Object* obj, ESourceKind* arg1);
extern void ent_Object_updateTransactionInfo(ent_Object* obj);
extern void ent_Object_setConst(ent_Object* obj, String* arg1, double arg2);
extern void* ent_Object_getConst(ent_Object* obj, String* arg1);
extern void ent_Object_clearAtbCache(ent_Object* obj, int arg1);
extern void ent_Object_clearSelfAtbCache(ent_Object* obj, void* arg1);
extern void* ent_Object_getLogData(ent_Object* obj);
extern int ent_Object_getCLID(ent_Object* obj);
extern void ent_Object_serialize(ent_Object* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Object_getSerializeSchema(ent_Object* obj);
extern void ent_Object_unserializeInit(ent_Object* obj);
extern void ent_Object_unserialize(ent_Object* obj, hxbit_Serializer* arg1);
extern logic_AttributesManager* ent_Object___net_mark_attributes(ent_Object* obj, logic_AttributesManager* arg1);
extern logic_AttributesManager* ent_Object_set_attributes(ent_Object* obj, logic_AttributesManager* arg1);
extern int ent_Object_get_networkPropAttributes(ent_Object* obj);
extern ent_Resources* ent_Object___net_mark_resources(ent_Object* obj, ent_Resources* arg1);
extern ent_Resources* ent_Object_set_resources(ent_Object* obj, ent_Resources* arg1);
extern int ent_Object_get_networkPropResources(ent_Object* obj);
extern net_Serializable* ent_Object___net_mark__traits(ent_Object* obj, net_Serializable* arg1);
extern net_Serializable* ent_Object_set__traits(ent_Object* obj, net_Serializable* arg1);
extern int ent_Object_get_networkProp_traits(ent_Object* obj);
extern logic_TradeManager* ent_Object___net_mark_tradeManager(ent_Object* obj, logic_TradeManager* arg1);
extern logic_TradeManager* ent_Object_set_tradeManager(ent_Object* obj, logic_TradeManager* arg1);
extern int ent_Object_get_networkPropTradeManager(ent_Object* obj);
extern hxbit_MapData* ent_Object___net_mark_chosenConsts(ent_Object* obj, hxbit_MapData* arg1);
extern hxbit_MapData* ent_Object_set_chosenConsts(ent_Object* obj, hxbit_MapData* arg1);
extern int ent_Object_get_networkPropChosenConsts(ent_Object* obj);
extern void ent_Object_onTraitApplicationEffects(ent_Object* obj, logic_Application* arg1);
extern void ent_Object_networkFlush(ent_Object* obj, hxbit_Serializer* arg1);
extern void ent_Object_networkSync(ent_Object* obj, hxbit_Serializer* arg1);
extern void ent_Object_networkInitProxys(ent_Object* obj);
extern bool ent_Object_networkRPC(ent_Object* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Object_networkGetName(ent_Object* obj, int arg1, void* arg2);


#endif // __gen_t_ent_Object_h__
