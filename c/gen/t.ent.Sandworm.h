// gen time: 2024-07-14 16:14:14 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_Sandworm_h__
#define __gen_t_ent_Sandworm_h__

#include <common.h>
#include <gen/t.ent.Entity.h>

typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Sandworm ent_Sandworm;
typedef struct ent_Unit ent_Unit;
typedef struct ent_WormState ent_WormState;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct prefab_FXAnimation prefab_FXAnimation;


// type: ent.Sandworm, kind: HOBJ, pType: 0x01EC714D1D18
struct ent_Sandworm {
  // super: ent.Entity
  ent_Entity                super;

  // cls: ent.Sandworm, begin_offset: 0x0358
  ent_WormState*            wormState;          // +0358: HENUM ent.WormState
  double                    stateTime;          // +0360
  hxbit_ArrayProxyData*     alerts;             // +0368: HOBJ hxbit.ArrayProxyData
  ent_Unit*                 curTarget;          // +0370: HOBJ ent.Unit
  double                    spawnTime;          // +0378
  void*                     curPointX;          // +0380: HNULL
  void*                     curPointY;          // +0388: HNULL
  hxbit_MapData*            spotted;            // +0390: HOBJ hxbit.MapData
  hl_types_ArrayObj*        wormsignFXs;        // +0398: HOBJ hl.types.ArrayObj
  prefab_FXAnimation*       preattackSign;      // +03A0: HOBJ prefab.FXAnimation
  double                    avoidRad;           // +03A8
  bool                      inAttack;           // +03B0
  double                    currentStickTime;   // +03B8
  double                    stickTime;          // +03C0
  double                    timeOnAttackRange;  // +03C8
  double                    timeBeforeAttack;   // +03D0
  // total_size: 0x03D8
}; // ent_Sandworm (ent.Sandworm)

_Static_assert(sizeof(ent_Sandworm) == 0x03D8, "cls ent.Sandworm has wrong size");


extern h2d_col_PointImpl* ent_Sandworm_get_curPoint(ent_Sandworm* obj);
extern h2d_col_PointImpl* ent_Sandworm_set_curPoint(ent_Sandworm* obj, h2d_col_PointImpl* arg1);
extern double ent_Sandworm_get_timeInState(ent_Sandworm* obj);
extern ent_WormState* ent_Sandworm_set_wormState(ent_Sandworm* obj, ent_WormState* arg1);
extern double ent_Sandworm_get_avoidanceRadius(ent_Sandworm* obj);
extern void ent_Sandworm_initVisual(ent_Sandworm* obj);
extern double ent_Sandworm_getRad(ent_Sandworm* obj, int arg1);
extern double ent_Sandworm_getFxRange(ent_Sandworm* obj);
extern double ent_Sandworm_getAttackRadius(ent_Sandworm* obj);
extern void ent_Sandworm_init(ent_Sandworm* obj);
extern void ent_Sandworm_updateBehavior(ent_Sandworm* obj, double arg1);
extern void ent_Sandworm_doRemove(ent_Sandworm* obj);
extern void ent_Sandworm_doRemoveVisual(ent_Sandworm* obj);
extern void ent_Sandworm_startRoam(ent_Sandworm* obj, void* arg1);
extern void ent_Sandworm_tryAttack(ent_Sandworm* obj);
extern void ent_Sandworm_attackFx__impl(ent_Sandworm* obj, ent_Unit* arg1, hl_types_ArrayObj* arg2);
extern void ent_Sandworm_updateFX(ent_Sandworm* obj, double arg1);
extern void ent_Sandworm_update(ent_Sandworm* obj, double arg1);
extern void ent_Sandworm_frameUpdate(ent_Sandworm* obj, double arg1);
extern String* ent_Sandworm_color(ent_Sandworm* obj, String* arg1, int arg2);
extern void ent_Sandworm_updateMovement(ent_Sandworm* obj, double arg1);
extern ent_Unit* ent_Sandworm_getBestSpottingUnit(ent_Sandworm* obj, ent_Faction* arg1);
extern void ent_Sandworm_updateFactionsSpotting(ent_Sandworm* obj, void* arg1);
extern void ent_Sandworm_updateTargeting(ent_Sandworm* obj, void* arg1, double arg2);
extern void ent_Sandworm_targetEntity(ent_Sandworm* obj, ent_Unit* arg1, void* arg2);
extern bool ent_Sandworm_isInOuterRange(ent_Sandworm* obj, ent_Unit* arg1);
extern void ent_Sandworm_regularUpdate(ent_Sandworm* obj, double arg1);
extern void ent_Sandworm_frameRegularUpdate(ent_Sandworm* obj, double arg1);
extern int ent_Sandworm_getCLID(ent_Sandworm* obj);
extern void ent_Sandworm_serialize(ent_Sandworm* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Sandworm_getSerializeSchema(ent_Sandworm* obj);
extern void ent_Sandworm_unserializeInit(ent_Sandworm* obj);
extern void ent_Sandworm_unserialize(ent_Sandworm* obj, hxbit_Serializer* arg1);
extern ent_WormState* ent_Sandworm___net_mark_wormState(ent_Sandworm* obj, ent_WormState* arg1);
extern int ent_Sandworm_get_networkPropWormState(ent_Sandworm* obj);
extern double ent_Sandworm___net_mark_stateTime(ent_Sandworm* obj, double arg1);
extern double ent_Sandworm_set_stateTime(ent_Sandworm* obj, double arg1);
extern int ent_Sandworm_get_networkPropStateTime(ent_Sandworm* obj);
extern hxbit_ArrayProxyData* ent_Sandworm___net_mark_alerts(ent_Sandworm* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Sandworm_set_alerts(ent_Sandworm* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Sandworm_get_networkPropAlerts(ent_Sandworm* obj);
extern ent_Unit* ent_Sandworm___net_mark_curTarget(ent_Sandworm* obj, ent_Unit* arg1);
extern ent_Unit* ent_Sandworm_set_curTarget(ent_Sandworm* obj, ent_Unit* arg1);
extern int ent_Sandworm_get_networkPropCurTarget(ent_Sandworm* obj);
extern double ent_Sandworm___net_mark_spawnTime(ent_Sandworm* obj, double arg1);
extern double ent_Sandworm_set_spawnTime(ent_Sandworm* obj, double arg1);
extern int ent_Sandworm_get_networkPropSpawnTime(ent_Sandworm* obj);
extern void* ent_Sandworm___net_mark_curPointX(ent_Sandworm* obj, void* arg1);
extern void* ent_Sandworm_set_curPointX(ent_Sandworm* obj, void* arg1);
extern int ent_Sandworm_get_networkPropCurPointX(ent_Sandworm* obj);
extern void* ent_Sandworm___net_mark_curPointY(ent_Sandworm* obj, void* arg1);
extern void* ent_Sandworm_set_curPointY(ent_Sandworm* obj, void* arg1);
extern int ent_Sandworm_get_networkPropCurPointY(ent_Sandworm* obj);
extern hxbit_MapData* ent_Sandworm___net_mark_spotted(ent_Sandworm* obj, hxbit_MapData* arg1);
extern hxbit_MapData* ent_Sandworm_set_spotted(ent_Sandworm* obj, hxbit_MapData* arg1);
extern int ent_Sandworm_get_networkPropSpotted(ent_Sandworm* obj);
extern void ent_Sandworm_attackFx(ent_Sandworm* obj, ent_Unit* arg1, hl_types_ArrayObj* arg2);
extern void ent_Sandworm_networkFlush(ent_Sandworm* obj, hxbit_Serializer* arg1);
extern void ent_Sandworm_networkSync(ent_Sandworm* obj, hxbit_Serializer* arg1);
extern void ent_Sandworm_networkInitProxys(ent_Sandworm* obj);
extern bool ent_Sandworm_networkRPC(ent_Sandworm* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Sandworm_networkGetName(ent_Sandworm* obj, int arg1, void* arg2);


#endif // __gen_t_ent_Sandworm_h__
