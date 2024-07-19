// gen time: 2024-07-14 04:39:25 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_ent_MobileEntity_h__
#define __gen_t_ent_MobileEntity_h__

#include <common.h>
#include <gen/t.ent.Entity.h>

typedef struct String String;
typedef struct ent_ActionEndReason ent_ActionEndReason;
typedef struct ent_EActionState ent_EActionState;
typedef struct ent_Faction ent_Faction;
typedef struct ent_MobileEntity ent_MobileEntity;
typedef struct ent_MovementMode ent_MovementMode;
typedef struct ent_Structure ent_Structure;
typedef struct ent_Zone ent_Zone;
typedef struct ent_ZoneCell ent_ZoneCell;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_RotationFilter lib_RotationFilter;
typedef struct world_PathGrid world_PathGrid;


// type: ent.MobileEntity, kind: HOBJ, pType: 0x02748E3E5B18
struct ent_MobileEntity {
  // super: ent.Entity
  ent_Entity                super;

  // cls: ent.MobileEntity, begin_offset: 0x0358
  ent_MovementMode*         movementMode;       // +0358: HENUM ent.MovementMode
  double                    moveSpeed;          // +0360
  hl_types_ArrayObj*        currentPath;        // +0368: HOBJ hl.types.ArrayObj
  h2d_col_PointImpl*        nextPathTarget;     // +0370: HOBJ h2d.col.PointImpl
  bool                      pendingPath;        // +0378
  double                    curMaxSpeed;        // +0380
  double                    distToTargetPos;    // +0388
  double                    stopTolerance;      // +0390
  double                    headingDirection;   // +0398
  double                    avoidDist;          // +03A0
  double                    avoidanceAngle;     // +03A8
  hl_types_ArrayObj*        avoidanceTargets;   // +03B0: HOBJ hl.types.ArrayObj
  lib_RotationFilter*       rotationFilter;     // +03B8: HOBJ lib.RotationFilter
  ent_Entity*               _structure;         // +03C0: HOBJ ent.Entity
  h2d_col_PointImpl*        movePt;             // +03C8: HOBJ h2d.col.PointImpl
  double                    baseSpeed;          // +03D0
  double                    baseRotSpeed;       // +03D8
  double                    baseRotTilt;        // +03E0
  double                    baseAccel;          // +03E8
  double                    lastNoCollisionTimeInPath; // +03F0
  double                    lastPathMoveTime;   // +03F8
  double                    lastSufficientPathMovementTime; // +0400
  h2d_col_PointImpl*        lastUpdatePos;      // +0408: HOBJ h2d.col.PointImpl
  double                    ignoreAllyCollisionsTime; // +0410
  double                    lastBigRepulsion;   // +0418
  double                    __ref_moveSpeed;    // +0420
  // total_size: 0x0428
}; // ent_MobileEntity (ent.MobileEntity)

_Static_assert(sizeof(ent_MobileEntity) == 0x0428, "cls ent.MobileEntity has wrong size");


extern double ent_MobileEntity_set_moveSpeed(ent_MobileEntity* obj, double arg1);
extern double ent_MobileEntity_set_headingDirection(ent_MobileEntity* obj, double arg1);
extern ent_Structure* ent_MobileEntity_get_structure(ent_MobileEntity* obj);
extern ent_Structure* ent_MobileEntity_set_structure(ent_MobileEntity* obj, ent_Structure* arg1);
extern double ent_MobileEntity_set_rotation(ent_MobileEntity* obj, double arg1);
extern world_PathGrid* ent_MobileEntity_get_pathGrid(ent_MobileEntity* obj);
extern void ent_MobileEntity_init(ent_MobileEntity* obj);
extern void ent_MobileEntity_onReady(ent_MobileEntity* obj);
extern void ent_MobileEntity_reload(ent_MobileEntity* obj);
extern void ent_MobileEntity_initRotFilter(ent_MobileEntity* obj);
extern void ent_MobileEntity_onPosChanged(ent_MobileEntity* obj, double arg1, double arg2);
extern void ent_MobileEntity_updateZone(ent_MobileEntity* obj);
extern void ent_MobileEntity_frameUpdate(ent_MobileEntity* obj, double arg1);
extern void ent_MobileEntity_clientUpdate(ent_MobileEntity* obj, double arg1);
extern double ent_MobileEntity_getInterpSpeed(ent_MobileEntity* obj);
extern void ent_MobileEntity_clientInterpolate(ent_MobileEntity* obj, double arg1);
extern double ent_MobileEntity_getSpeed(ent_MobileEntity* obj, void* arg1);
extern double ent_MobileEntity_getRotationSpeed(ent_MobileEntity* obj);
extern double ent_MobileEntity_getRotationTilt(ent_MobileEntity* obj);
extern double ent_MobileEntity_getAccelerationSpeed(ent_MobileEntity* obj);
extern ent_MovementMode* ent_MobileEntity_set_movementMode(ent_MobileEntity* obj, ent_MovementMode* arg1);
extern hl_types_ArrayObj* ent_MobileEntity_set_currentPath(ent_MobileEntity* obj, hl_types_ArrayObj* arg1);
extern void ent_MobileEntity_updateMovementPath(ent_MobileEntity* obj);
extern void ent_MobileEntity_pathTo(ent_MobileEntity* obj, h2d_col_PointImpl* arg1, void* arg2);
extern void ent_MobileEntity_moveOrder(ent_MobileEntity* obj, h2d_col_PointImpl* arg1);
extern void ent_MobileEntity_moveTo(ent_MobileEntity* obj, h2d_col_PointImpl* arg1, void* arg2);
extern void ent_MobileEntity_followTarget(ent_MobileEntity* obj, ent_Entity* arg1);
extern void ent_MobileEntity_jobMove(ent_MobileEntity* obj, h2d_col_PointImpl* arg1, void* arg2);
extern void ent_MobileEntity_stopMove(ent_MobileEntity* obj);
extern void ent_MobileEntity_onTransitStart(ent_MobileEntity* obj);
extern bool ent_MobileEntity_isCulled(ent_MobileEntity* obj);
extern h2d_col_PointImpl* ent_MobileEntity_getMoveTargetPos(ent_MobileEntity* obj, ent_MovementMode* arg1);
extern h2d_col_PointImpl* ent_MobileEntity_getMovementModeTarget(ent_MobileEntity* obj, ent_MovementMode* arg1);
extern double ent_MobileEntity_getDistToTarget(ent_MobileEntity* obj);
extern double ent_MobileEntity_getDistToTargetSq(ent_MobileEntity* obj);
extern h2d_col_PointImpl* ent_MobileEntity_getNextPathPos(ent_MobileEntity* obj);
extern h2d_col_PointImpl* ent_MobileEntity_getCurrentPathEnd(ent_MobileEntity* obj);
extern void* ent_MobileEntity_getCurrentPathLength(ent_MobileEntity* obj);
extern bool ent_MobileEntity_hasMoveTarget(ent_MobileEntity* obj);
extern ent_Zone* ent_MobileEntity_getCurrentZoneDestination(ent_MobileEntity* obj);
extern bool ent_MobileEntity_canPatrol(ent_MobileEntity* obj);
extern void ent_MobileEntity_patrolAround(ent_MobileEntity* obj, h2d_col_PointImpl* arg1, ent_ZoneCell* arg2, void* arg3, void* arg4);
extern void ent_MobileEntity_patrolZone(ent_MobileEntity* obj, ent_Zone* arg1, void* arg2, void* arg3);
extern bool ent_MobileEntity_isFlying(ent_MobileEntity* obj);
extern int ent_MobileEntity_get_collisionMask(ent_MobileEntity* obj);
extern bool ent_MobileEntity_needsMoveToTurn(ent_MobileEntity* obj);
extern bool ent_MobileEntity_hasSmoothRotation(ent_MobileEntity* obj);
extern bool ent_MobileEntity_canMove(ent_MobileEntity* obj);
extern bool ent_MobileEntity_isCloseToBase(ent_MobileEntity* obj);
extern bool ent_MobileEntity_isMovingOutOfZone(ent_MobileEntity* obj);
extern void ent_MobileEntity_updateAnimation(ent_MobileEntity* obj);
extern void ent_MobileEntity_resetMove(ent_MobileEntity* obj);
extern bool ent_MobileEntity_hasControl(ent_MobileEntity* obj);
extern void ent_MobileEntity_doActionInternal(ent_MobileEntity* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern void ent_MobileEntity_doEndCurrentAction(ent_MobileEntity* obj, ent_ActionEndReason* arg1);
extern void ent_MobileEntity_updateCurrentAction(ent_MobileEntity* obj, double arg1);
extern void ent_MobileEntity_setActionState(ent_MobileEntity* obj, ent_EActionState* arg1);
extern hl_types_ArrayObj* ent_MobileEntity_getPossibleActionsOnTarget(ent_MobileEntity* obj, ent_Entity* arg1, ent_Zone* arg2);
extern void ent_MobileEntity_chooseJob(ent_MobileEntity* obj);
extern void ent_MobileEntity_update(ent_MobileEntity* obj, double arg1);
extern void ent_MobileEntity_regularUpdate(ent_MobileEntity* obj, double arg1);
extern void ent_MobileEntity_updateMovement(ent_MobileEntity* obj, double arg1);
extern bool ent_MobileEntity_canCollide(ent_MobileEntity* obj, ent_Entity* arg1);
extern void ent_MobileEntity_regUpdateMovement(ent_MobileEntity* obj, double arg1);
extern hl_types_ArrayObj* ent_MobileEntity_findAvoidanceTargets(ent_MobileEntity* obj, double arg1, double arg2, double arg3);
extern bool ent_MobileEntity_ignoresAllyCollisions(ent_MobileEntity* obj);
extern bool ent_MobileEntity_ignoresCollisionsWith(ent_MobileEntity* obj, ent_Entity* arg1);
extern void ent_MobileEntity_moveBy(ent_MobileEntity* obj, double arg1);
extern double ent_MobileEntity_compareDirections(ent_MobileEntity* obj, h2d_col_PointImpl* arg1, ent_MobileEntity* arg2);
extern double ent_MobileEntity_getRotatingMoveSpeedFactor(ent_MobileEntity* obj, double arg1);
extern bool ent_MobileEntity_isFollowing(ent_MobileEntity* obj, ent_Entity* arg1);
extern double ent_MobileEntity_getFollowingDistance(ent_MobileEntity* obj, ent_Entity* arg1);
extern ent_Entity* ent_MobileEntity_getFollowTarget(ent_MobileEntity* obj);
extern bool ent_MobileEntity_isMoving(ent_MobileEntity* obj);
extern int ent_MobileEntity_getCLID(ent_MobileEntity* obj);
extern void ent_MobileEntity_serialize(ent_MobileEntity* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_MobileEntity_getSerializeSchema(ent_MobileEntity* obj);
extern void ent_MobileEntity_unserializeInit(ent_MobileEntity* obj);
extern void ent_MobileEntity_unserialize(ent_MobileEntity* obj, hxbit_Serializer* arg1);
extern ent_MovementMode* ent_MobileEntity___net_mark_movementMode(ent_MobileEntity* obj, ent_MovementMode* arg1);
extern int ent_MobileEntity_get_networkPropMovementMode(ent_MobileEntity* obj);
extern double ent_MobileEntity___net_mark_moveSpeed(ent_MobileEntity* obj, double arg1);
extern int ent_MobileEntity_get_networkPropMoveSpeed(ent_MobileEntity* obj);
extern ent_Entity* ent_MobileEntity___net_mark__structure(ent_MobileEntity* obj, ent_Entity* arg1);
extern ent_Entity* ent_MobileEntity_set__structure(ent_MobileEntity* obj, ent_Entity* arg1);
extern int ent_MobileEntity_get_networkProp_structure(ent_MobileEntity* obj);
extern void ent_MobileEntity_networkFlush(ent_MobileEntity* obj, hxbit_Serializer* arg1);
extern void ent_MobileEntity_networkSync(ent_MobileEntity* obj, hxbit_Serializer* arg1);
extern String* ent_MobileEntity_networkGetName(ent_MobileEntity* obj, int arg1, void* arg2);


#endif // __gen_t_ent_MobileEntity_h__
