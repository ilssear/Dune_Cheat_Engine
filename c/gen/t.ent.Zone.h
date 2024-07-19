// gen time: 2024-07-14 16:16:36 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_Zone_h__
#define __gen_t_ent_Zone_h__

#include <common.h>
#include <gen/t.ent.Object.h>

typedef struct EScope EScope;
typedef struct String String;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Player ent_Player;
typedef struct ent_Structure ent_Structure;
typedef struct ent_Zone ent_Zone;
typedef struct ent_ZoneCell ent_ZoneCell;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct hl_types_ArrayBytes_Int hl_types_ArrayBytes_Int;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hrt_prefab_Resource hrt_prefab_Resource;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_PolyArea lib_PolyArea;
typedef struct lib_SoundObject lib_SoundObject;
typedef struct logic_Application logic_Application;
typedef struct logic_AttributeApplication logic_AttributeApplication;
typedef struct prefab_FXAnimation prefab_FXAnimation;
typedef struct ui_comp_Widget ui_comp_Widget;
typedef struct ui_hud_ZoneEffects ui_hud_ZoneEffects;
typedef struct world_Cell world_Cell;


// type: ent.Zone, kind: HOBJ, pType: 0x01EC714D08B8
struct ent_Zone {
  // super: ent.Object
  ent_Object                super;

  // cls: ent.Zone, begin_offset: 0x00E0
  String*                   kind;               // +00E0: HOBJ String
  int                       id;                 // +00E8
  ent_Faction*              owner;              // +00F0: HOBJ ent.Faction
  hxbit_ArrayProxyData*     structures;         // +00F8: HOBJ hxbit.ArrayProxyData
  ent_Structure*            spiceArea;          // +0100: HOBJ ent.Structure
  ent_Structure*            mineralArea;        // +0108: HOBJ ent.Structure
  double                    windForce;          // +0110
  double                    baseWormActivity;   // +0118
  void*                     inf;                // +0120: HVIRTUAL
  hl_types_ArrayObj*        hull;               // +0128: HOBJ hl.types.ArrayObj
  lib_PolyArea*             innerArea;          // +0130: HOBJ lib.PolyArea
  lib_PolyArea*             structureArea;      // +0138: HOBJ lib.PolyArea
  hl_types_ArrayObj*        cells;              // +0140: HOBJ hl.types.ArrayObj
  world_Cell*               gen;                // +0148: HOBJ world.Cell
  hl_types_ArrayObj*        armies;             // +0150: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        units;              // +0158: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        entities;           // +0160: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        probes;             // +0168: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        neighbors;          // +0170: HOBJ hl.types.ArrayObj
  int                       uiColor;            // +0178
  bool                      uiDirty;            // +017C
  ui_comp_Widget*           infoWidget;         // +0180: HOBJ ui.comp.Widget
  ui_comp_Widget*           targetedWidget;     // +0188: HOBJ ui.comp.Widget
  ui_hud_ZoneEffects*       zoneEffects;        // +0190: HOBJ ui.hud.ZoneEffects
  lib_SoundObject*          soundObj;           // +0198: HOBJ lib.SoundObject
  bool                      wasDiscovered;      // +01A0
  hl_types_ArrayBytes_Int*  calcDist;           // +01A8: HOBJ hl.types.ArrayBytes_Int
  hl_types_ArrayObj*        tmpZones;           // +01B0: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        tmpStructs;         // +01B8: HOBJ hl.types.ArrayObj
  // total_size: 0x01C0
}; // ent_Zone (ent.Zone)

_Static_assert(sizeof(ent_Zone) == 0x01C0, "cls ent.Zone has wrong size");


extern void ent_Zone_init(ent_Zone* obj);
extern void ent_Zone_onReady(ent_Zone* obj);
extern void ent_Zone_initWidgets(ent_Zone* obj);
extern void ent_Zone_updateEffects(ent_Zone* obj);
extern void ent_Zone_doRemove(ent_Zone* obj);
extern void ent_Zone_finalize(ent_Zone* obj);
extern void ent_Zone_initSpice(ent_Zone* obj);
extern ent_Faction* ent_Zone_get_factionOwner(ent_Zone* obj);
extern void ent_Zone_addEntity(ent_Zone* obj, ent_Entity* arg1);
extern void ent_Zone_removeEntity(ent_Zone* obj, ent_Entity* arg1);
extern void ent_Zone_forceSpecialAreaVillageProd(ent_Zone* obj, String* arg1, void* arg2, void* arg3);
extern bool ent_Zone_isRealZone(ent_Zone* obj);
extern String* ent_Zone_getExposedName(ent_Zone* obj);
extern ent_ZoneCell* ent_Zone_getCellAt(ent_Zone* obj, h2d_col_PointImpl* arg1);
extern h2d_col_PointImpl* ent_Zone_getRandomPoint(ent_Zone* obj, h2d_col_PointImpl* arg1);
extern h2d_col_PointImpl* ent_Zone_findRandomPoint(ent_Zone* obj, void* arg1);
extern h2d_col_PointImpl* ent_Zone_getRandomStructurePoint(ent_Zone* obj, h2d_col_PointImpl* arg1);
extern h2d_col_PointImpl* ent_Zone_findRandomStructurePoint(ent_Zone* obj, void* arg1);
extern h2d_col_PointImpl* ent_Zone_getCenter(ent_Zone* obj);
extern hl_types_ArrayObj* ent_Zone_getAffectingAtbApps(ent_Zone* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern void ent_Zone_propagateClearAtbCache(ent_Zone* obj, int arg1, EScope* arg2, void* arg3, logic_AttributeApplication* arg4);
extern void ent_Zone_onTraitStartEffects(ent_Zone* obj, logic_Application* arg1);
extern void ent_Zone_onTraitEndEffects(ent_Zone* obj, logic_Application* arg1, bool arg2);
extern void ent_Zone_playSound(ent_Zone* obj, String* arg1, String* arg2);
extern void ent_Zone_tryPlaySound(ent_Zone* obj, String* arg1);
extern lib_SoundObject* ent_Zone_getSoundObject(ent_Zone* obj);
extern void ent_Zone_initTraitsFx(ent_Zone* obj);
extern bool ent_Zone_hasTraitFxs(ent_Zone* obj, String* arg1);
extern void ent_Zone_addTraitFxs(ent_Zone* obj, String* arg1);
extern void ent_Zone_removeTraitFxs(ent_Zone* obj, String* arg1);
extern void ent_Zone_updateTraitFxs(ent_Zone* obj, double arg1);
extern prefab_FXAnimation* ent_Zone_playTraitsFx(ent_Zone* obj, hrt_prefab_Resource* arg1, String* arg2, void* arg3, void* arg4, void* arg5, int arg6, hl_types_ArrayObj* arg7);
extern prefab_FXAnimation* ent_Zone_playFX(ent_Zone* obj, hrt_prefab_Resource* arg1, String* arg2, void* arg3, void* arg4);
extern void ent_Zone_regularUpdate(ent_Zone* obj, double arg1);
extern void ent_Zone_frameRegularUpdate(ent_Zone* obj, double arg1);
extern void ent_Zone_updateAttributes(ent_Zone* obj);
extern void ent_Zone_updateGiveTraits(ent_Zone* obj, hl_types_ArrayObj* arg1);
extern double ent_Zone_getCurrentWormActivity(ent_Zone* obj);
extern bool ent_Zone_hasKnownMinerals(ent_Zone* obj, ent_Faction* arg1);
extern int ent_Zone_getDistanceToZone(ent_Zone* obj, ent_Zone* arg1);
extern hl_types_ArrayObj* ent_Zone_getZonesAtDistance(ent_Zone* obj, int arg1);
extern int ent_Zone_getDistanceToPlayerTerritory(ent_Zone* obj, ent_Faction* arg1, void* arg2);
extern int ent_Zone_getDistanceToPlayerBase(ent_Zone* obj, ent_Faction* arg1, void* arg2);
extern double ent_Zone_getMinDistanceToPlayerBase(ent_Zone* obj);
extern h2d_col_PointImpl* ent_Zone_getSafeSpawnPoint(ent_Zone* obj, h2d_col_PointImpl* arg1, void* arg2, void* arg3);
extern h2d_col_PointImpl* ent_Zone_getSpawnPoint(ent_Zone* obj, void* arg1, h2d_col_PointImpl* arg2, void* arg3, void* arg4);
extern bool ent_Zone_hasSpice(ent_Zone* obj);
extern ent_Structure* ent_Zone_getSpiceArea(ent_Zone* obj);
extern bool ent_Zone_anyWormAround(ent_Zone* obj, h2d_col_PointImpl* arg1, double arg2);
extern bool ent_Zone_anyWormAroundSpice(ent_Zone* obj);
extern hl_types_ArrayBytes_Int* ent_Zone_calcDistanceFrom(ent_Zone* obj);
extern void ent_Zone_calcDistanceRec(ent_Zone* obj, ent_Zone* arg1, hl_types_ArrayBytes_Int* arg2, int arg3);
extern hl_types_ArrayObj* ent_Zone_getZonesInRange(ent_Zone* obj, int arg1);
extern bool ent_Zone_isDiscovered(ent_Zone* obj, ent_Faction* arg1);
extern bool ent_Zone_isExplored(ent_Zone* obj, ent_Faction* arg1);
extern bool ent_Zone_isReconned(ent_Zone* obj, ent_Faction* arg1);
extern bool ent_Zone_isStaticReconned(ent_Zone* obj, ent_Faction* arg1);
extern bool ent_Zone_isDeepDesert(ent_Zone* obj);
extern bool ent_Zone_isPole(ent_Zone* obj);
extern bool ent_Zone_isOrbit(ent_Zone* obj);
extern bool ent_Zone_isInteresting(ent_Zone* obj);
extern bool ent_Zone_isSignature(ent_Zone* obj);
extern bool ent_Zone_hasNaturalResources(ent_Zone* obj);
extern bool ent_Zone_hasStructure(ent_Zone* obj, String* arg1);
extern bool ent_Zone_hasBuilding(ent_Zone* obj, String* arg1);
extern ent_Structure* ent_Zone_getBuilding(ent_Zone* obj, String* arg1);
extern ent_Structure* ent_Zone_getMainBase(ent_Zone* obj);
extern bool ent_Zone_hasMainBase(ent_Zone* obj, void* arg1);
extern void ent_Zone_updateOwner(ent_Zone* obj);
extern bool ent_Zone_isOnNeuralGrid(ent_Zone* obj);
extern ent_Structure* ent_Zone_getStructureKind(ent_Zone* obj, String* arg1);
extern hl_types_ArrayObj* ent_Zone_getAllStructuresKind(ent_Zone* obj, String* arg1);
extern void ent_Zone_changeOwner(ent_Zone* obj, ent_Faction* arg1, void* arg2);
extern bool ent_Zone_hasAllyArmy(ent_Zone* obj, ent_Faction* arg1);
extern bool ent_Zone_hasVillages(ent_Zone* obj, void* arg1);
extern hl_types_ArrayObj* ent_Zone_getVillages(ent_Zone* obj, void* arg1);
extern ent_Structure* ent_Zone_getVillage(ent_Zone* obj);
extern bool ent_Zone_hasInfiltrationCell(ent_Zone* obj, ent_Faction* arg1);
extern ent_Structure* ent_Zone_getMainStructure(ent_Zone* obj);
extern ent_Structure* ent_Zone_getNearestVillageFrom(ent_Zone* obj, double arg1, double arg2, void* arg3);
extern ent_Structure* ent_Zone_getRandomVillage(ent_Zone* obj, void* arg1);
extern ent_Structure* ent_Zone_getSietch(ent_Zone* obj);
extern void* ent_Zone_getOverInfo(ent_Zone* obj);
extern int ent_Zone_set_uiColor(ent_Zone* obj, int arg1);
extern bool ent_Zone_borderIsVisibleFor(ent_Zone* obj, ent_Player* arg1);
extern bool ent_Zone_borderIsVisibleThroughFogFor(ent_Zone* obj, ent_Player* arg1);
extern double ent_Zone_getHegemonyProduction(ent_Zone* obj);
extern double ent_Zone_getSpecialHegemonyProduction(ent_Zone* obj);
extern void* ent_Zone_getLogData(ent_Zone* obj);
extern String* ent_Zone___net_mark_kind(ent_Zone* obj, String* arg1);
extern String* ent_Zone_set_kind(ent_Zone* obj, String* arg1);
extern int ent_Zone_get_networkPropKind(ent_Zone* obj);
extern int ent_Zone___net_mark_id(ent_Zone* obj, int arg1);
extern int ent_Zone_set_id(ent_Zone* obj, int arg1);
extern int ent_Zone_get_networkPropId(ent_Zone* obj);
extern ent_Faction* ent_Zone___net_mark_owner(ent_Zone* obj, ent_Faction* arg1);
extern ent_Faction* ent_Zone_set_owner(ent_Zone* obj, ent_Faction* arg1);
extern int ent_Zone_get_networkPropOwner(ent_Zone* obj);
extern hxbit_ArrayProxyData* ent_Zone___net_mark_structures(ent_Zone* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Zone_set_structures(ent_Zone* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Zone_get_networkPropStructures(ent_Zone* obj);
extern ent_Structure* ent_Zone___net_mark_spiceArea(ent_Zone* obj, ent_Structure* arg1);
extern ent_Structure* ent_Zone_set_spiceArea(ent_Zone* obj, ent_Structure* arg1);
extern int ent_Zone_get_networkPropSpiceArea(ent_Zone* obj);
extern ent_Structure* ent_Zone___net_mark_mineralArea(ent_Zone* obj, ent_Structure* arg1);
extern ent_Structure* ent_Zone_set_mineralArea(ent_Zone* obj, ent_Structure* arg1);
extern int ent_Zone_get_networkPropMineralArea(ent_Zone* obj);
extern double ent_Zone___net_mark_windForce(ent_Zone* obj, double arg1);
extern double ent_Zone_set_windForce(ent_Zone* obj, double arg1);
extern int ent_Zone_get_networkPropWindForce(ent_Zone* obj);
extern double ent_Zone___net_mark_baseWormActivity(ent_Zone* obj, double arg1);
extern double ent_Zone_set_baseWormActivity(ent_Zone* obj, double arg1);
extern int ent_Zone_get_networkPropBaseWormActivity(ent_Zone* obj);
extern void ent_Zone_networkFlush(ent_Zone* obj, hxbit_Serializer* arg1);
extern void ent_Zone_networkSync(ent_Zone* obj, hxbit_Serializer* arg1);
extern void ent_Zone_networkInitProxys(ent_Zone* obj);
extern String* ent_Zone_networkGetName(ent_Zone* obj, int arg1, void* arg2);
extern int ent_Zone_getCLID(ent_Zone* obj);
extern void ent_Zone_serialize(ent_Zone* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Zone_getSerializeSchema(ent_Zone* obj);
extern void ent_Zone_unserializeInit(ent_Zone* obj);
extern void ent_Zone_unserialize(ent_Zone* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_Zone_h__
