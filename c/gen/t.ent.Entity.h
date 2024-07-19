// gen time: 2024-07-14 04:39:46 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_ent_Entity_h__
#define __gen_t_ent_Entity_h__

#include <common.h>
#include <gen/t.ent.Object.h>

typedef struct EReason EReason;
typedef struct EScope EScope;
typedef struct ETargetKind ETargetKind;
typedef struct String String;
typedef struct ent_ActionEndReason ent_ActionEndReason;
typedef struct ent_AttackKind ent_AttackKind;
typedef struct ent_AttackTargetKind ent_AttackTargetKind;
typedef struct ent_AttackType ent_AttackType;
typedef struct ent_Carrier ent_Carrier;
typedef struct ent_DamageSource ent_DamageSource;
typedef struct ent_DeathReason ent_DeathReason;
typedef struct ent_EActionState ent_EActionState;
typedef struct ent_EActionTarget ent_EActionTarget;
typedef struct ent_EAlignment ent_EAlignment;
typedef struct ent_EKind ent_EKind;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_GamePlane ent_GamePlane;
typedef struct ent_JobKind ent_JobKind;
typedef struct ent_State ent_State;
typedef struct ent_StateInfo ent_StateInfo;
typedef struct ent_Structure ent_Structure;
typedef struct ent_Team ent_Team;
typedef struct ent_Zone ent_Zone;
typedef struct ent_ZoneCell ent_ZoneCell;
typedef struct ent_comp_AttackComponent ent_comp_AttackComponent;
typedef struct ent_comp_CarrierComponent ent_comp_CarrierComponent;
typedef struct ent_comp_EntityComponent ent_comp_EntityComponent;
typedef struct ent_comp_OccupierKind ent_comp_OccupierKind;
typedef struct ent_comp_SubUnitHandler ent_comp_SubUnitHandler;
typedef struct h2d_Object h2d_Object;
typedef struct h2d_Text h2d_Text;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct h3d_VectorImpl h3d_VectorImpl;
typedef struct h3d_col_Collider h3d_col_Collider;
typedef struct h3d_scene_Graphics h3d_scene_Graphics;
typedef struct h3d_scene_Interactive h3d_scene_Interactive;
typedef struct h3d_scene_Object h3d_scene_Object;
typedef struct haxe_ds_StringMap haxe_ds_StringMap;
typedef struct hl_Class hl_Class;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hrt_prefab_Resource hrt_prefab_Resource;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_AnimPlayer lib_AnimPlayer;
typedef struct lib_RangeFX lib_RangeFX;
typedef struct lib_SceneObject lib_SceneObject;
typedef struct lib_SoundObject lib_SoundObject;
typedef struct logic_Application logic_Application;
typedef struct logic_AttributeApplication logic_AttributeApplication;
typedef struct logic_ProgressBarHandler logic_ProgressBarHandler;
typedef struct logic_Upgrades logic_Upgrades;
typedef struct prefab_FXAnimation prefab_FXAnimation;
typedef struct shaders_ColorSet shaders_ColorSet;
typedef struct shaders_Dithering shaders_Dithering;
typedef struct ui_comp_DynElement ui_comp_DynElement;
typedef struct ui_comp_Widget ui_comp_Widget;


// type: ent.Entity, kind: HOBJ, pType: 0x02748E3E4738
struct ent_Entity {
  // super: ent.Object
  ent_Object                super;

  // cls: ent.Entity, begin_offset: 0x00E0
  ent_EKind*                ekind;              // +00E0: HENUM ent.EKind
  double                    createdAt;          // +00E8
  double                    posx;               // +00F0
  double                    posy;               // +00F8
  double                    rotation;           // +0100
  double                    tilt;               // +0108
  double                    pitch;              // +0110
  double                    targetTilt;         // +0118
  double                    targetPitch;        // +0120
  double                    lastClickTime;      // +0128
  ent_State*                state;              // +0130: HENUM ent.State
  ent_StateInfo*            stateInfo;          // +0138: HOBJ ent.StateInfo
  ent_Entity*               _owner;             // +0140: HOBJ ent.Entity
  void*                     action;             // +0148: HVIRTUAL
  hl_types_ArrayObj*        actionQueue;        // +0150: HOBJ hl.types.ArrayObj
  logic_Upgrades*           upgrades;           // +0158: HOBJ logic.Upgrades
  hxbit_ArrayProxyData*     components;         // +0160: HOBJ hxbit.ArrayProxyData
  ent_comp_AttackComponent* attacks;            // +0168: HOBJ ent.comp.AttackComponent
  hl_types_ArrayObj*        subAttacks;         // +0170: HOBJ hl.types.ArrayObj
  ent_comp_CarrierComponent* carrierComp;       // +0178: HOBJ ent.comp.CarrierComponent
  ent_comp_SubUnitHandler*  subUnitHandler;     // +0180: HOBJ ent.comp.SubUnitHandler
  logic_ProgressBarHandler* progBars;           // +0188: HOBJ logic.ProgressBarHandler
  ent_JobKind*              currentJobKind;     // +0190: HENUM ent.JobKind
  void*                     currentJobFunc;     // +0198: HFUN
  void*                     currentJobOnStop;   // +01A0: HFUN
  ent_ZoneCell*             cell;               // +01A8: HOBJ ent.ZoneCell
  lib_SceneObject*          obj;                // +01B0: HOBJ lib.SceneObject
  h3d_scene_Object*         modelObj;           // +01B8: HOBJ h3d.scene.Object
  bool                      preSelected;        // +01C0
  bool                      inVisibleCell;      // +01C1
  lib_RangeFX*              rangePreviewFX;     // +01C8: HOBJ lib.RangeFX
  bool                      visibleLocal;       // +01D0
  double                    alphaLocal;         // +01D8
  void*                     ditheringCallBack;  // +01E0: HFUN
  ent_Carrier*              carrier;            // +01E8: HOBJ ent.Carrier
  ent_comp_CarrierComponent* transport;         // +01F0: HOBJ ent.comp.CarrierComponent
  void*                     model;              // +01F8: HVIRTUAL
  void*                     modelMesh;          // +0200: HVIRTUAL
  int                       cullingDist;        // +0208
  double                    modelRad;           // +0210
  double                    cachedModelScale;   // +0218
  h3d_scene_Interactive*    selectInt;          // +0220: HOBJ h3d.scene.Interactive
  ui_comp_Widget*           bannerWidget;       // +0228: HOBJ ui.comp.Widget
  ui_comp_DynElement*       bannerComp;         // +0230: HOBJ ui.comp.DynElement
  lib_SoundObject*          soundObj;           // +0238: HOBJ lib.SoundObject
  shaders_Dithering*        dithering;          // +0240: HOBJ shaders.Dithering
  bool                      lockSyncVisibility; // +0248
  bool                      startedInit;        // +0249
  double                    nextJobCheck;       // +0250
  bool                      forcedOutline;      // +0258
  bool                      prevCloaked;        // +0259
  hl_types_ArrayObj*        detectingEntities;  // +0260: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        queuedActionsWaypoints; // +0268: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        animDynObjects;     // +0270: HOBJ hl.types.ArrayObj
  h2d_Text*                 debugStatusTxt;     // +0278: HOBJ h2d.Text
  String*                   debugStatusStr;     // +0280: HOBJ String
  h3d_scene_Graphics*       debugCombatGraphics; // +0288: HOBJ h3d.scene.Graphics
  ent_EAlignment*           lastAlignment;      // +0290: HENUM ent.EAlignment
  shaders_ColorSet*         alignmentShader;    // +0298: HOBJ shaders.ColorSet
  double                    alignmentAmount;    // +02A0
  hl_types_ArrayObj*        detectedEntities;   // +02A8: HOBJ hl.types.ArrayObj
  bool                      alreadyDetected;    // +02B0
  haxe_ds_StringMap*        traitNextApplicationTime; // +02B8: HOBJ haxe.ds.StringMap
  hl_types_ArrayObj*        combatInfos;        // +02C0: HOBJ hl.types.ArrayObj
  int                       combatState;        // +02C8
  double                    life;               // +02D0
  double                    lifeLostInCombat;   // +02D8
  double                    lifeChangeOnTrait;  // +02E0
  hl_types_ArrayObj*        oncePerCombatTraitsApplied; // +02E8: HOBJ hl.types.ArrayObj
  double                    prevArmor;          // +02F0
  double                    armorDamage;        // +02F8
  hl_types_ArrayObj*        comboCache;         // +0300: HOBJ hl.types.ArrayObj
  double                    nextAttackARatio;   // +0308
  ent_Entity*               lastHurtBy;         // +0310: HOBJ ent.Entity
  double                    overkillDmg;        // +0318
  double                    prevMaxLife;        // +0320
  double                    prevMaxArmor;       // +0328
  bool                      wasFighting;        // +0330
  double                    __ref_rotation;     // +0338
  double                    __ref_life;         // +0340
  double                    __ref_prevMaxLife;  // +0348
  double                    __ref_prevMaxArmor; // +0350
  // total_size: 0x0358
}; // ent_Entity (ent.Entity)

_Static_assert(sizeof(ent_Entity) == 0x0358, "cls ent.Entity has wrong size");


extern void* ent_Entity_get_stats(ent_Entity* obj);
extern double ent_Entity_get_x(ent_Entity* obj);
extern double ent_Entity_get_y(ent_Entity* obj);
extern double ent_Entity_get_z(ent_Entity* obj);
extern double ent_Entity_getWorldZ(ent_Entity* obj);
extern double ent_Entity_getZOffset(ent_Entity* obj);
extern bool ent_Entity_getZSmoothing(ent_Entity* obj);
extern ent_Faction* ent_Entity_get_owner(ent_Entity* obj);
extern ent_Faction* ent_Entity_set_owner(ent_Entity* obj, ent_Faction* arg1);
extern ent_Team* ent_Entity_get_team(ent_Entity* obj);
extern ent_Faction* ent_Entity_get_factionOwner(ent_Entity* obj);
extern void* ent_Entity_set_action(ent_Entity* obj, void* arg1);
extern hxbit_ArrayProxyData* ent_Entity_set_components(ent_Entity* obj, hxbit_ArrayProxyData* arg1);
extern ent_GamePlane* ent_Entity_get_plane(ent_Entity* obj);
extern ent_Carrier* ent_Entity_set_carrier(ent_Entity* obj, ent_Carrier* arg1);
extern ent_comp_CarrierComponent* ent_Entity_set_transport(ent_Entity* obj, ent_comp_CarrierComponent* arg1);
extern bool ent_Entity_get_refundable(ent_Entity* obj);
extern void* ent_Entity_set_model(ent_Entity* obj, void* arg1);
extern void* ent_Entity_get_bannerIcon(ent_Entity* obj);
extern bool ent_Entity_set_lockSyncVisibility(ent_Entity* obj, bool arg1);
extern lib_AnimPlayer* ent_Entity_get_anim(ent_Entity* obj);
extern String* ent_Entity_get_animID(ent_Entity* obj);
extern void ent_Entity_alive(ent_Entity* obj);
extern void ent_Entity_init(ent_Entity* obj);
extern void ent_Entity_finalize(ent_Entity* obj);
extern void ent_Entity_patchEntity(ent_Entity* obj, int arg1);
extern void ent_Entity_onReady(ent_Entity* obj);
extern ent_comp_EntityComponent* ent_Entity_getComponent(ent_Entity* obj, hl_Class* arg1);
extern ent_comp_EntityComponent* ent_Entity_makeComponent(ent_Entity* obj, hl_Class* arg1, void* arg2);
extern void ent_Entity_initComponents(ent_Entity* obj);
extern void ent_Entity_setupComponents(ent_Entity* obj);
extern void ent_Entity_makeAttackComponents(ent_Entity* obj);
extern void ent_Entity_makeCarrierComponent(ent_Entity* obj);
extern void ent_Entity_makeSubUnitComponent(ent_Entity* obj);
extern double ent_Entity_getBaseRefundRate(ent_Entity* obj);
extern bool ent_Entity_canProgressUpgrades(ent_Entity* obj);
extern EReason* ent_Entity_getProgressReason(ent_Entity* obj);
extern double ent_Entity_getUpkeepFlatModif(ent_Entity* obj, int arg1);
extern double ent_Entity_getUpkeepFactor(ent_Entity* obj, int arg1);
extern double ent_Entity_getAdditiveUpkeepFactor(ent_Entity* obj, int arg1);
extern double ent_Entity_getMultiplicativeUpkeepFactor(ent_Entity* obj, int arg1);
extern double ent_Entity_getGlobalUpkeepFlatModif(ent_Entity* obj, int arg1);
extern double ent_Entity_getGlobalAdditiveUpkeepFactor(ent_Entity* obj, int arg1);
extern double ent_Entity_getGlobalMultiplicativeUpkeepFactor(ent_Entity* obj, int arg1);
extern double ent_Entity_getUpkeep(ent_Entity* obj, int arg1, hl_types_ArrayObj* arg2);
extern double ent_Entity_doGetUpkeepDetail(ent_Entity* obj, int arg1, void* arg2);
extern hl_types_ArrayObj* ent_Entity_getUpkeepDetail(ent_Entity* obj, int arg1);
extern hl_types_ArrayObj* ent_Entity_getTotalUpkeep(ent_Entity* obj);
extern double ent_Entity_getFlagOffset(ent_Entity* obj);
extern void ent_Entity_createBanner(ent_Entity* obj);
extern void ent_Entity_enableFlag(ent_Entity* obj, void* arg1);
extern int ent_Entity_getBannerWidgetPriority(ent_Entity* obj);
extern bool ent_Entity_useStaticFlag(ent_Entity* obj);
extern String* ent_Entity_getBannerName(ent_Entity* obj);
extern String* ent_Entity_getUIClassName(ent_Entity* obj);
extern String* ent_Entity_getRichIdKind(ent_Entity* obj);
extern void* ent_Entity_getLogData(ent_Entity* obj);
extern h2d_col_PointImpl* ent_Entity_getSafePosition(ent_Entity* obj, h2d_col_PointImpl* arg1, void* arg2, void* arg3);
extern bool ent_Entity_canReach(ent_Entity* obj, ent_Entity* arg1);
extern hl_types_ArrayObj* ent_Entity_getRefund(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity_getNoRefund(ent_Entity* obj);
extern String* ent_Entity_getRefundTitle(ent_Entity* obj, void* arg1);
extern String* ent_Entity_getRefundDesc(ent_Entity* obj);
extern EReason* ent_Entity_implRequestRefund(ent_Entity* obj);
extern EReason* ent_Entity_getNoRefundReason(ent_Entity* obj);
extern void ent_Entity_doRequestRefund(ent_Entity* obj);
extern void* ent_Entity_resolveModel(ent_Entity* obj);
extern double ent_Entity_getDistTo(ent_Entity* obj, ent_Entity* arg1);
extern double ent_Entity_getDistToSq(ent_Entity* obj, ent_Entity* arg1);
extern double ent_Entity_getDistBetween(ent_Entity* obj, ent_Entity* arg1, void* arg2);
extern double ent_Entity_getOverlap(ent_Entity* obj, ent_Entity* arg1, h2d_col_PointImpl* arg2);
extern h2d_col_PointImpl* ent_Entity_get_position(ent_Entity* obj);
extern h2d_col_PointImpl* ent_Entity_set_position(ent_Entity* obj, h2d_col_PointImpl* arg1);
extern h3d_VectorImpl* ent_Entity_get_position3D(ent_Entity* obj);
extern void ent_Entity_setPosition(ent_Entity* obj, double arg1, double arg2);
extern double ent_Entity_set_posx(ent_Entity* obj, double arg1);
extern double ent_Entity_set_posy(ent_Entity* obj, double arg1);
extern void ent_Entity_onPosChanged(ent_Entity* obj, double arg1, double arg2);
extern bool ent_Entity_isNotInWorld(ent_Entity* obj);
extern bool ent_Entity_isGridRegistered(ent_Entity* obj);
extern double ent_Entity_set_rotation(ent_Entity* obj, double arg1);
extern double ent_Entity_get_radius(ent_Entity* obj);
extern double ent_Entity_get_avoidanceRadius(ent_Entity* obj);
extern double ent_Entity_get_modelScale(ent_Entity* obj);
extern double ent_Entity_getModelScaleModifier(ent_Entity* obj);
extern ent_Zone* ent_Entity_get_zone(ent_Entity* obj);
extern ent_Zone* ent_Entity_get_realZone(ent_Entity* obj);
extern ent_ZoneCell* ent_Entity_set_cell(ent_Entity* obj, ent_ZoneCell* arg1);
extern bool ent_Entity_isNear(ent_Entity* obj, ent_Entity* arg1);
extern double ent_Entity_getNearDistance(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity_getUnitsNearby(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity_getArmiesNearby(ent_Entity* obj, ent_Faction* arg1);
extern hl_types_ArrayObj* ent_Entity_getAllyArmiesNearby(ent_Entity* obj);
extern int ent_Entity_getCarrierCapacity(ent_Entity* obj);
extern int ent_Entity_getCarrierLoad(ent_Entity* obj);
extern EReason* ent_Entity_implCarryEntity(ent_Entity* obj, ent_Entity* arg1);
extern void ent_Entity_updateZone(ent_Entity* obj);
extern void ent_Entity_onZoneChange(ent_Entity* obj, ent_Zone* arg1);
extern void ent_Entity_onCellChange(ent_Entity* obj, ent_ZoneCell* arg1);
extern ent_JobKind* ent_Entity_setJob(ent_Entity* obj, ent_JobKind* arg1, void* arg2, void* arg3);
extern void ent_Entity_chooseJob(ent_Entity* obj);
extern void ent_Entity_updateJob(ent_Entity* obj, double arg1);
extern void ent_Entity_jobStop(ent_Entity* obj);
extern void ent_Entity_jobWait(ent_Entity* obj, double arg1, void* arg2);
extern void ent_Entity_updateState(ent_Entity* obj, double arg1);
extern ent_State* ent_Entity_set_state(ent_Entity* obj, ent_State* arg1);
extern bool ent_Entity_set_inVisibleCell(ent_Entity* obj, bool arg1);
extern bool ent_Entity_get_selected(ent_Entity* obj);
extern lib_SceneObject* ent_Entity_set_obj(ent_Entity* obj, lib_SceneObject* arg1);
extern double ent_Entity_getOrientationSpeed(ent_Entity* obj);
extern bool ent_Entity_orientTo(ent_Entity* obj, double arg1, double arg2, void* arg3);
extern void ent_Entity_addDither(ent_Entity* obj);
extern void ent_Entity_clearDither(ent_Entity* obj);
extern void ent_Entity_playFadeIn__impl(ent_Entity* obj, void* arg1);
extern void ent_Entity_playFadeOut__impl(ent_Entity* obj, void* arg1);
extern shaders_Dithering* ent_Entity_fadeIn(ent_Entity* obj, void* arg1, void* arg2);
extern shaders_Dithering* ent_Entity_fadeOut(ent_Entity* obj, void* arg1, void* arg2);
extern shaders_Dithering* ent_Entity_ditherFade(ent_Entity* obj, bool arg1, double arg2, void* arg3);
extern shaders_Dithering* ent_Entity_ditherFadeTo(ent_Entity* obj, double arg1, void* arg2, void* arg3);
extern void ent_Entity_setDitherAlpha(ent_Entity* obj, double arg1);
extern void ent_Entity_resetDitherAlphaToVal(ent_Entity* obj, double arg1);
extern h3d_col_Collider* ent_Entity_makeInteractiveCollider(ent_Entity* obj);
extern void ent_Entity_initInteractive(ent_Entity* obj);
extern void ent_Entity_setTutoHighlight(ent_Entity* obj, bool arg1);
extern void ent_Entity_doSetOutline(ent_Entity* obj, void* arg1, void* arg2, void* arg3);
extern void ent_Entity_setOutline(ent_Entity* obj, bool arg1);
extern void ent_Entity_setHoverOutline(ent_Entity* obj, bool arg1);
extern String* ent_Entity_getAlignmentColor(ent_Entity* obj, void* arg1);
extern double ent_Entity_getStateAlpha(ent_Entity* obj);
extern bool ent_Entity_isCloaked(ent_Entity* obj);
extern bool ent_Entity_isCloakedItself(ent_Entity* obj);
extern bool ent_Entity_hasCloakedAttribute(ent_Entity* obj);
extern void ent_Entity_updateCloaked(ent_Entity* obj);
extern void ent_Entity_localUpdateCloaked(ent_Entity* obj);
extern bool ent_Entity_canDetect(ent_Entity* obj);
extern double ent_Entity_getDetectionRange(ent_Entity* obj);
extern double ent_Entity_getDetectionRangeModifier(ent_Entity* obj);
extern bool ent_Entity_hasInDetectionRange(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isDetected(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_isCloakedAttack(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_canDetectEntity(ent_Entity* obj, ent_Entity* arg1);
extern void ent_Entity_updateDetection(ent_Entity* obj);
extern double ent_Entity_getWormDetectionRadius(ent_Entity* obj);
extern double ent_Entity_getWormDetectionDelay(ent_Entity* obj);
extern bool ent_Entity_isModelVisibleForFaction(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_isGameplayVisibleForFaction(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_isVisibleForFaction(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_isVisible(ent_Entity* obj);
extern bool ent_Entity_isFlagVisible(ent_Entity* obj);
extern void ent_Entity_syncVisibility(ent_Entity* obj);
extern void ent_Entity_setVisible(ent_Entity* obj, bool arg1);
extern void ent_Entity_onOver(ent_Entity* obj);
extern void ent_Entity_onOut(ent_Entity* obj);
extern bool ent_Entity_canBeSelected(ent_Entity* obj);
extern bool ent_Entity_canBeGroupSelected(ent_Entity* obj);
extern void ent_Entity_goTo(ent_Entity* obj, void* arg1);
extern void ent_Entity_onSelect(ent_Entity* obj, void* arg1);
extern void ent_Entity_select(ent_Entity* obj, void* arg1);
extern void ent_Entity_selectFeedback(ent_Entity* obj, void* arg1);
extern ent_Entity* ent_Entity_getSelectOnRemove(ent_Entity* obj);
extern bool ent_Entity_set_preSelected(ent_Entity* obj, bool arg1);
extern void ent_Entity_onDoubleSelect(ent_Entity* obj);
extern void ent_Entity_onUnselect(ent_Entity* obj);
extern void ent_Entity_displayRangePreview(ent_Entity* obj, void* arg1);
extern void ent_Entity_clearRangePreview(ent_Entity* obj);
extern void ent_Entity_onRightSelect(ent_Entity* obj);
extern void* ent_Entity_rightClickForAction(ent_Entity* obj, void* arg1, hl_types_ArrayObj* arg2, void* arg3, void* arg4);
extern void* ent_Entity_getClientRightClickActions(ent_Entity* obj, void* arg1, hl_types_ArrayObj* arg2);
extern bool ent_Entity_requestAction(ent_Entity* obj, void* arg1, void* arg2, ent_Faction* arg3, void* arg4);
extern bool ent_Entity_networkAllow(ent_Entity* obj, int arg1, int arg2, void* arg3);
extern void ent_Entity_queueAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern EReason* ent_Entity_implServerQueueAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern void ent_Entity_ownerQueueAction__impl(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern void ent_Entity_localQueueAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern EReason* ent_Entity_implClearAllActions(ent_Entity* obj);
extern void ent_Entity_clearActionQueue(ent_Entity* obj);
extern EReason* ent_Entity_implServerClearActionQueue(ent_Entity* obj);
extern void ent_Entity_ownerClearActionQueue__impl(ent_Entity* obj);
extern void ent_Entity_localClearActionQueue(ent_Entity* obj);
extern void ent_Entity_unqueueAction__impl(ent_Entity* obj);
extern void ent_Entity_nextQueuedAction(ent_Entity* obj);
extern bool ent_Entity_hasQueuedAction(ent_Entity* obj);
extern bool ent_Entity_canShowQueuedActions(ent_Entity* obj);
extern void ent_Entity_rpcShowQueuedActionsFeedback__impl(ent_Entity* obj);
extern void ent_Entity_showQueuedActionsFeedback(ent_Entity* obj);
extern void ent_Entity_rpcClearQueuedActionsFeedback__impl(ent_Entity* obj);
extern void ent_Entity_clearQueuedActionsFeedback(ent_Entity* obj);
extern void ent_Entity_initVisual(ent_Entity* obj);
extern void ent_Entity_postInitVisual(ent_Entity* obj);
extern void ent_Entity_removeVisual(ent_Entity* obj);
extern void ent_Entity_doRemoveVisual(ent_Entity* obj);
extern void ent_Entity_resetAlpha(ent_Entity* obj);
extern void ent_Entity_initFxs(ent_Entity* obj);
extern void ent_Entity_onPlayerSwitch(ent_Entity* obj);
extern void ent_Entity_reload(ent_Entity* obj);
extern lib_SceneObject* ent_Entity_removeWaitUntil(ent_Entity* obj, void* arg1);
extern lib_SceneObject* ent_Entity_removeWait(ent_Entity* obj, double arg1, void* arg2);
extern void ent_Entity_removeWithFade__impl(ent_Entity* obj, void* arg1);
extern void ent_Entity_playDeathAnim__impl(ent_Entity* obj, String* arg1, double arg2);
extern bool ent_Entity_canAutoRemoveVisual(ent_Entity* obj);
extern void ent_Entity_doRemove(ent_Entity* obj);
extern String* ent_Entity_getAnimOverride(ent_Entity* obj);
extern void ent_Entity_playAnim(ent_Entity* obj, String* arg1, void* arg2, void* arg3);
extern void ent_Entity_setAnimSpeed(ent_Entity* obj, double arg1);
extern void ent_Entity_onPlayAnim(ent_Entity* obj, void* arg1, String* arg2);
extern void ent_Entity_onLeaveAnim(ent_Entity* obj, void* arg1, void* arg2, String* arg3);
extern void ent_Entity_playAnimSound(ent_Entity* obj, void* arg1, String* arg2);
extern void ent_Entity_playAnimEndSound(ent_Entity* obj, void* arg1, String* arg2);
extern void ent_Entity_playAnimFX(ent_Entity* obj, void* arg1, String* arg2);
extern bool ent_Entity_isPlayingAnim(ent_Entity* obj, String* arg1);
extern bool ent_Entity_curAnimContains(ent_Entity* obj, String* arg1);
extern double ent_Entity_curAnimFrame(ent_Entity* obj);
extern void ent_Entity_debugStatus(ent_Entity* obj, String* arg1);
extern prefab_FXAnimation* ent_Entity_playFX(ent_Entity* obj, hrt_prefab_Resource* arg1, String* arg2, void* arg3, void* arg4);
extern lib_SoundObject* ent_Entity_getSoundObject(ent_Entity* obj);
extern void ent_Entity_playSound(ent_Entity* obj, String* arg1, String* arg2);
extern void ent_Entity_tryPlaySound(ent_Entity* obj, String* arg1);
extern void ent_Entity_setSoundParam(ent_Entity* obj, String* arg1, double arg2);
extern void ent_Entity_frameUpdate(ent_Entity* obj, double arg1);
extern bool ent_Entity_canShowAlignment(ent_Entity* obj);
extern void ent_Entity_updateAlignmentShader(ent_Entity* obj);
extern void ent_Entity_frameRegularUpdate(ent_Entity* obj, double arg1);
extern void ent_Entity_updateWidget(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity_getAffectingAtbApps(ent_Entity* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern hl_types_ArrayObj* ent_Entity_getRegionAffectingAtbApps(ent_Entity* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4, void* arg5);
extern hl_types_ArrayObj* ent_Entity_getRegionAtbApps(ent_Entity* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern double ent_Entity_getAtbValInRegion(ent_Entity* obj, int arg1, void* arg2, ent_Faction* arg3);
extern void ent_Entity_propagateClearAtbCache(ent_Entity* obj, int arg1, EScope* arg2, void* arg3, logic_AttributeApplication* arg4);
extern hl_types_ArrayObj* ent_Entity_getMissingUnlocks(ent_Entity* obj, ETargetKind* arg1, hl_types_ArrayObj* arg2);
extern hl_types_ArrayObj* ent_Entity_getPossibleUnlocks(ent_Entity* obj, ETargetKind* arg1, void* arg2);
extern bool ent_Entity_hasUnlocked(ent_Entity* obj, ETargetKind* arg1);
extern bool ent_Entity_isUnlockSourceRequired(ent_Entity* obj, void* arg1);
extern hl_types_ArrayObj* ent_Entity_getAvailableActions(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity_getPossibleActionsOnTarget(ent_Entity* obj, ent_Entity* arg1, ent_Zone* arg2);
extern bool ent_Entity_getActionRequireConfirm(ent_Entity* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern hl_types_ArrayObj* ent_Entity_getActionStartingCost(ent_Entity* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern hl_types_ArrayObj* ent_Entity_getActionSustainCost(ent_Entity* obj, void* arg1, void* arg2, ent_Faction* arg3, ent_EActionState* arg4);
extern void* ent_Entity_getActionDesc(ent_Entity* obj);
extern void* ent_Entity_getCurrentAction(ent_Entity* obj);
extern void* ent_Entity_getActionProgress(ent_Entity* obj);
extern String* ent_Entity_getCurrentActionKind(ent_Entity* obj);
extern bool ent_Entity_isInAction(ent_Entity* obj, String* arg1);
extern hl_types_ArrayObj* ent_Entity_getCurrentActionSustainCost(ent_Entity* obj);
extern ent_Zone* ent_Entity_getActionTargetZone(ent_Entity* obj);
extern ent_Entity* ent_Entity_getActionTarget(ent_Entity* obj, hl_Class* arg1);
extern hl_types_ArrayObj* ent_Entity_getActionTargets(ent_Entity* obj, hl_Class* arg1);
extern bool ent_Entity_hasZoneAsActionTarget(ent_Entity* obj, String* arg1, ent_Zone* arg2);
extern bool ent_Entity_isDoingBlockingAction(ent_Entity* obj);
extern bool ent_Entity_isActionInState(ent_Entity* obj, String* arg1, ent_EActionState* arg2);
extern ent_EActionState* ent_Entity_getActionState(ent_Entity* obj);
extern void ent_Entity_setActionState(ent_Entity* obj, ent_EActionState* arg1);
extern h2d_col_PointImpl* ent_Entity_getActionTargetDestination(ent_Entity* obj, void* arg1, ent_EActionTarget* arg2);
extern EReason* ent_Entity_getNoActionReason(ent_Entity* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern EReason* ent_Entity_implDoAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern void ent_Entity_doActionInternal(ent_Entity* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern void ent_Entity_rpcPlayActionFeedback__impl(ent_Entity* obj, String* arg1, ent_EActionTarget* arg2);
extern void ent_Entity_playActionFeedback(ent_Entity* obj, String* arg1, ent_EActionTarget* arg2);
extern prefab_FXAnimation* ent_Entity_displayWaypoint(ent_Entity* obj, void* arg1, ent_EActionTarget* arg2, void* arg3);
extern void ent_Entity_requestActionQuote(ent_Entity* obj, void* arg1);
extern void ent_Entity_playActionQuote(ent_Entity* obj, int arg1);
extern void ent_Entity_playActionQuoteRpc__impl(ent_Entity* obj, int arg1);
extern bool ent_Entity_hasActionQuotes(ent_Entity* obj);
extern bool ent_Entity_hasQuoteForAction(ent_Entity* obj, int arg1);
extern void* ent_Entity_getActionQuoteType(ent_Entity* obj, void* arg1);
extern void ent_Entity_setAction(ent_Entity* obj, void* arg1, void* arg2, ent_EActionState* arg3);
extern void ent_Entity_updateCurrentAction(ent_Entity* obj, double arg1);
extern void ent_Entity_endCurrentAction(ent_Entity* obj, ent_ActionEndReason* arg1);
extern EReason* ent_Entity_implCancelAction(ent_Entity* obj);
extern void ent_Entity_doEndCurrentAction(ent_Entity* obj, ent_ActionEndReason* arg1);
extern void ent_Entity_actionSendNotif(ent_Entity* obj, String* arg1, ent_Faction* arg2);
extern bool ent_Entity_isIdle(ent_Entity* obj);
extern void* ent_Entity_getOverInfo(ent_Entity* obj);
extern h2d_Object* ent_Entity_getTipContent(ent_Entity* obj);
extern void ent_Entity_redrawFlag(ent_Entity* obj);
extern void ent_Entity_updateAnimation(ent_Entity* obj);
extern bool ent_Entity_isCulled(ent_Entity* obj);
extern bool ent_Entity_inScreen(ent_Entity* obj);
extern bool ent_Entity_inRect(ent_Entity* obj, double arg1, double arg2, double arg3, double arg4);
extern bool ent_Entity_isOnSand(ent_Entity* obj);
extern void ent_Entity_update(ent_Entity* obj, double arg1);
extern void ent_Entity_clientUpdate(ent_Entity* obj, double arg1);
extern void ent_Entity_regularUpdate(ent_Entity* obj, double arg1);
extern void ent_Entity_updateAlerts(ent_Entity* obj);
extern double ent_Entity_getNearbyDistance(ent_Entity* obj);
extern double ent_Entity_getFarDistance(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity_getNearbyOwnerArmies(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity_getNearbyAtWarArmies(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity_getFarArmies(ent_Entity* obj, void* arg1);
extern void ent_Entity_updateAttributes(ent_Entity* obj, double arg1);
extern double ent_Entity_getDamageModTransfer(ent_Entity* obj);
extern double ent_Entity_getAppFrequencyModifier(ent_Entity* obj, String* arg1);
extern void ent_Entity_allAdjacentZoneStructures(ent_Entity* obj, void* arg1);
extern void ent_Entity_allAdjacentZoneArmies(ent_Entity* obj, void* arg1);
extern void ent_Entity_allAdjacentZoneUnits(ent_Entity* obj, void* arg1);
extern void ent_Entity_updateProgresses(ent_Entity* obj);
extern void ent_Entity_updateTraitStatuses(ent_Entity* obj, double arg1);
extern void ent_Entity_updateSounds(ent_Entity* obj, double arg1);
extern double ent_Entity_getCurrentVibrations(ent_Entity* obj);
extern void ent_Entity_updateVibrations(ent_Entity* obj, double arg1);
extern void ent_Entity_onUpgrade(ent_Entity* obj, void* arg1);
extern void ent_Entity_onCancelUpgrade(ent_Entity* obj, void* arg1);
extern void ent_Entity_onRemoveUpgrade(ent_Entity* obj, void* arg1);
extern bool ent_Entity_isTemporary(ent_Entity* obj);
extern void ent_Entity_onTraitEnd(ent_Entity* obj, logic_Application* arg1, bool arg2);
extern h2d_col_PointImpl* ent_Entity_getDestination(ent_Entity* obj);
extern void ent_Entity_teleport__impl(ent_Entity* obj, void* arg1);
extern void ent_Entity_requestTransit(ent_Entity* obj, h2d_col_PointImpl* arg1);
extern void ent_Entity_abortTransports(ent_Entity* obj);
extern bool ent_Entity_inTransport(ent_Entity* obj);
extern bool ent_Entity_inTransit(ent_Entity* obj);
extern bool ent_Entity_isHidden(ent_Entity* obj);
extern bool ent_Entity_isWaitingForTransit(ent_Entity* obj);
extern bool ent_Entity_hasTransitRequest(ent_Entity* obj);
extern bool ent_Entity_isTransported(ent_Entity* obj);
extern void ent_Entity_onTransitStart(ent_Entity* obj);
extern void ent_Entity_onTransitPickup(ent_Entity* obj);
extern void ent_Entity_onTransitDrop(ent_Entity* obj, h2d_col_PointImpl* arg1);
extern void ent_Entity_onFollowed(ent_Entity* obj, ent_Entity* arg1, bool arg2);
extern bool ent_Entity_canBeRaidedBy(ent_Entity* obj, String* arg1);
extern bool ent_Entity_isEnemy(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isStrictEnemy(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isAlly(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isFriendly(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isForceAlly(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isStrictAlly(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isHostileWith(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isHostileAlly(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isAtWarWith(ent_Entity* obj, ent_Entity* arg1);
extern ent_EAlignment* ent_Entity_getAlignmentWith(ent_Entity* obj, ent_Faction* arg1);
extern ent_Structure* ent_Entity_getClosestSietch(ent_Entity* obj, void* arg1);
extern double ent_Entity_getEngageDist(ent_Entity* obj, ent_Entity* arg1);
extern double ent_Entity_getAttackDist(ent_Entity* obj, ent_Entity* arg1);
extern double ent_Entity_getAOERadius(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isInEngageRange(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isInAttackRange(ent_Entity* obj, ent_Entity* arg1, void* arg2);
extern bool ent_Entity_isInMeleeRange(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isWithinRange(ent_Entity* obj, ent_Entity* arg1, double arg2);
extern hl_types_ArrayObj* ent_Entity_getEntitiesInRadius(ent_Entity* obj, h2d_col_PointImpl* arg1, double arg2, void* arg3);
extern hl_types_ArrayObj* ent_Entity_getUnitsInRadius(ent_Entity* obj, h2d_col_PointImpl* arg1, double arg2, void* arg3);
extern hl_types_ArrayObj* ent_Entity_getArmiesInRadius(ent_Entity* obj, h2d_col_PointImpl* arg1, double arg2, void* arg3);
extern void ent_Entity_getEntitiesInPointRange(ent_Entity* obj, h2d_col_PointImpl* arg1, double arg2, hl_Class* arg3, hl_types_ArrayObj* arg4, void* arg5);
extern bool ent_Entity_isInAirfieldRange(ent_Entity* obj);
extern bool ent_Entity_isPosInAirfieldRange(ent_Entity* obj, h2d_col_PointImpl* arg1);
extern ent_Structure* ent_Entity_getAirfieldStructure(ent_Entity* obj);
extern EReason* ent_Entity_getPosInAirfieldRangeReason(ent_Entity* obj, h2d_col_PointImpl* arg1, ent_Faction* arg2, void* arg3);
extern EReason* ent_Entity_getAirfieldNoUseReason(ent_Entity* obj, ent_Faction* arg1, void* arg2);
extern bool ent_Entity_canUseAirfield(ent_Entity* obj, ent_Faction* arg1);
extern double ent_Entity_getAirfieldRange(ent_Entity* obj);
extern bool ent_Entity_hasAirfield(ent_Entity* obj);
extern double ent_Entity_set_life(ent_Entity* obj, double arg1);
extern double ent_Entity_get_maxLife(ent_Entity* obj);
extern double ent_Entity_getBaseMaxLife(ent_Entity* obj);
extern double ent_Entity_getMaxLifeMultModifier(ent_Entity* obj);
extern double ent_Entity_getMaxLifeAdditiveModifier(ent_Entity* obj);
extern double ent_Entity_get_lifeRatio(ent_Entity* obj);
extern bool ent_Entity_isFullLife(ent_Entity* obj);
extern void ent_Entity_onLifeUpdated(ent_Entity* obj, double arg1);
extern double ent_Entity_get_power(ent_Entity* obj);
extern double ent_Entity_getBasePower(ent_Entity* obj);
extern double ent_Entity_getAdditivePowerModifier(ent_Entity* obj);
extern double ent_Entity_getMultiplicativePowerModifier(ent_Entity* obj);
extern double ent_Entity_getPowerModifier(ent_Entity* obj, void* arg1);
extern double ent_Entity_getPowerModifierAgainst(ent_Entity* obj, ent_Entity* arg1, ent_AttackKind* arg2);
extern double ent_Entity_get_attackRange(ent_Entity* obj);
extern double ent_Entity_getBaseAttackRange(ent_Entity* obj);
extern double ent_Entity_getAttackRangeFactor(ent_Entity* obj);
extern double ent_Entity_getMinRangeFactor(ent_Entity* obj);
extern double ent_Entity_getMinRange(ent_Entity* obj);
extern double ent_Entity_get_meleeRange(ent_Entity* obj);
extern double ent_Entity_getImpactsRadiusOffset(ent_Entity* obj);
extern double ent_Entity_getCurrentComboMinRange(ent_Entity* obj);
extern h2d_col_PointImpl* ent_Entity_getImpactPoint(ent_Entity* obj, h2d_col_PointImpl* arg1, ent_Entity* arg2);
extern h2d_col_PointImpl* ent_Entity_getOriginPoint(ent_Entity* obj, h2d_col_PointImpl* arg1);
extern double ent_Entity_get_armor(ent_Entity* obj);
extern double ent_Entity_get_maxArmor(ent_Entity* obj);
extern double ent_Entity_getBaseArmor(ent_Entity* obj);
extern double ent_Entity_getArmorModifier(ent_Entity* obj);
extern void* ent_Entity_getMaxResStock(ent_Entity* obj, String* arg1);
extern void ent_Entity_refillArmor(ent_Entity* obj);
extern double ent_Entity_setArmor(ent_Entity* obj, double arg1);
extern void ent_Entity_onArmorChange(ent_Entity* obj);
extern double ent_Entity_refreshArmor(ent_Entity* obj);
extern double ent_Entity_reduceArmor(ent_Entity* obj, double arg1);
extern double ent_Entity_getReducedDamage(ent_Entity* obj, double arg1, ent_Entity* arg2, ent_DamageSource* arg3, void* arg4, ent_AttackKind* arg5);
extern bool ent_Entity_canBeAutoTargetted(ent_Entity* obj);
extern bool ent_Entity_canAutoFightWith(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_canFight(ent_Entity* obj);
extern bool ent_Entity_isDamageableEntity(ent_Entity* obj);
extern bool ent_Entity_canBeDamaged(ent_Entity* obj);
extern bool ent_Entity_canDieFromDamage(ent_Entity* obj);
extern bool ent_Entity_canBeAttacked(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_canBeAutoAttacked(ent_Entity* obj);
extern bool ent_Entity_canFightWith(ent_Entity* obj, ent_Entity* arg1, void* arg2);
extern void* ent_Entity_getFightInfo(ent_Entity* obj, ent_Entity* arg1);
extern double ent_Entity_getBullyingTime(ent_Entity* obj, ent_Entity* arg1);
extern double ent_Entity_getOneSidedBullyingTime(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isBullying(ent_Entity* obj, ent_Entity* arg1, void* arg2);
extern bool ent_Entity_isBullied(ent_Entity* obj, ent_Entity* arg1, void* arg2, void* arg3);
extern int ent_Entity_countOpponentsOfKind(ent_Entity* obj, String* arg1);
extern ent_AttackTargetKind* ent_Entity_getAssociatedTargetType(ent_Entity* obj);
extern bool ent_Entity_hasDeathAnim(ent_Entity* obj);
extern bool ent_Entity_hasIdleVariants(ent_Entity* obj);
extern bool ent_Entity_hasAnim(ent_Entity* obj, String* arg1);
extern bool ent_Entity_isAllyWithOccupier(ent_Entity* obj, ent_comp_OccupierKind* arg1);
extern void* ent_Entity_get_attackCombo(ent_Entity* obj);
extern void* ent_Entity_get_attack(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity_getAttackCombos(ent_Entity* obj, hl_types_ArrayObj* arg1);
extern bool ent_Entity_canAutoAttack(ent_Entity* obj);
extern bool ent_Entity_isProjectileBlocked(ent_Entity* obj);
extern h3d_scene_Object* ent_Entity_getAttackMuzzle(ent_Entity* obj, String* arg1);
extern h3d_VectorImpl* ent_Entity_getAttackProjectileOrigin(ent_Entity* obj, h3d_scene_Object* arg1);
extern h3d_VectorImpl* ent_Entity_getDefaultProjectileOrigin(ent_Entity* obj);
extern h3d_VectorImpl* ent_Entity_getAttackProjectileDirection(ent_Entity* obj, h3d_scene_Object* arg1, h2d_col_PointImpl* arg2);
extern double ent_Entity_getNextAttackDamage(ent_Entity* obj);
extern bool ent_Entity_hasAttacks(ent_Entity* obj);
extern bool ent_Entity_canAttackWithNoTarget(ent_Entity* obj);
extern bool ent_Entity_requiresDeployToAttack(ent_Entity* obj);
extern String* ent_Entity_deployedCombo(ent_Entity* obj);
extern double ent_Entity_getAttackSpeed(ent_Entity* obj, ent_AttackType* arg1);
extern double ent_Entity_getAttackSpeedCombo(ent_Entity* obj);
extern double ent_Entity_getAttackSpeedAdditiveModifiers(ent_Entity* obj, ent_AttackType* arg1);
extern double ent_Entity_getAttackSpeedMultiplicativeModifiers(ent_Entity* obj, ent_AttackType* arg1);
extern void ent_Entity_updateAttacks(ent_Entity* obj, ent_Entity* arg1, double arg2);
extern h2d_col_PointImpl* ent_Entity_getAttackPos(ent_Entity* obj);
extern void ent_Entity_playAttack__impl(ent_Entity* obj, String* arg1, int arg2, ent_Entity* arg3, void* arg4);
extern void ent_Entity_playAttackEffects__impl(ent_Entity* obj, String* arg1, int arg2, ent_Entity* arg3, void* arg4);
extern void ent_Entity_playSkill__impl(ent_Entity* obj, String* arg1);
extern void ent_Entity_playSkillStart__impl(ent_Entity* obj, String* arg1);
extern void ent_Entity_playSkillStop__impl(ent_Entity* obj, String* arg1);
extern void ent_Entity_applySkillLock(ent_Entity* obj, String* arg1);
extern bool ent_Entity_isSkillLocked(ent_Entity* obj);
extern void ent_Entity_onFireAttack(ent_Entity* obj, void* arg1, ent_Entity* arg2, h2d_col_PointImpl* arg3, void* arg4);
extern double ent_Entity_getAttackAngleModifier(ent_Entity* obj);
extern void ent_Entity_doAttackEffects(ent_Entity* obj, String* arg1, int arg2, double arg3, ent_Entity* arg4, h3d_VectorImpl* arg5, ent_GamePlane* arg6);
extern void ent_Entity_doAttack(ent_Entity* obj, String* arg1, int arg2, ent_Entity* arg3, h3d_VectorImpl* arg4, ent_GamePlane* arg5);
extern double ent_Entity_getNextAttackARatio(ent_Entity* obj, void* arg1, h3d_VectorImpl* arg2);
extern void ent_Entity_applyArmorDamage(ent_Entity* obj, ent_Entity* arg1, ent_AttackKind* arg2);
extern double ent_Entity_getAoeMaxRadiusModifier(ent_Entity* obj);
extern void ent_Entity_attackAoE(ent_Entity* obj, h2d_col_PointImpl* arg1, ent_GamePlane* arg2, double arg3, ent_AttackKind* arg4, ent_AttackType* arg5, ent_Entity* arg6, ent_DamageSource* arg7, void* arg8, void* arg9, void* arg10, void* arg11);
extern void ent_Entity_attackAura(ent_Entity* obj, void* arg1, double arg2, ent_AttackKind* arg3, ent_AttackType* arg4, ent_Entity* arg5, ent_DamageSource* arg6, void* arg7, void* arg8, void* arg9);
extern void* ent_Entity_getAttackAuraEntityQuery(ent_Entity* obj, void* arg1, int arg2, h3d_VectorImpl* arg3);
extern void ent_Entity_damageAround(ent_Entity* obj, void* arg1, double arg2, ent_AttackKind* arg3, ent_AttackType* arg4, ent_DamageSource* arg5, void* arg6);
extern void ent_Entity_damageInZone(ent_Entity* obj, ent_Zone* arg1, double arg2, ent_DamageSource* arg3, void* arg4);
extern bool ent_Entity_isInLock(ent_Entity* obj);
extern bool ent_Entity_isInAttackLock(ent_Entity* obj);
extern bool ent_Entity_isAggressive(ent_Entity* obj);
extern bool ent_Entity_isDefensive(ent_Entity* obj);
extern double ent_Entity_getDamageModifier(ent_Entity* obj, ent_Entity* arg1, void* arg2);
extern double ent_Entity_getTargetArmorFactor(ent_Entity* obj, ent_Entity* arg1);
extern double ent_Entity_getDamageReduction(ent_Entity* obj, ent_Entity* arg1, ent_DamageSource* arg2);
extern double ent_Entity_getDefenseFactor(ent_Entity* obj, ent_Entity* arg1, ent_DamageSource* arg2, void* arg3, ent_AttackKind* arg4);
extern double ent_Entity_getAttackArmorDamageChance(ent_Entity* obj, ent_Entity* arg1, ent_AttackKind* arg2);
extern void ent_Entity_damageArmor(ent_Entity* obj, ent_Entity* arg1, double arg2);
extern void ent_Entity_hurtBy(ent_Entity* obj, ent_Entity* arg1, double arg2, ent_DamageSource* arg3, ent_AttackKind* arg4, ent_AttackType* arg5, void* arg6, void* arg7);
extern void ent_Entity_onDealDamage(ent_Entity* obj, ent_Entity* arg1, double arg2);
extern void ent_Entity_onReceiveDamage(ent_Entity* obj, ent_Entity* arg1, double arg2, ent_AttackKind* arg3, ent_AttackType* arg4);
extern void ent_Entity_killedBy(ent_Entity* obj, ent_Entity* arg1);
extern void ent_Entity_triggerDeath(ent_Entity* obj, ent_Entity* arg1);
extern void ent_Entity_onDeath(ent_Entity* obj, ent_DeathReason* arg1);
extern bool ent_Entity_isNearFight(ent_Entity* obj);
extern ent_Entity* ent_Entity_getAttackTarget(ent_Entity* obj);
extern ent_Entity* ent_Entity_getFightingTarget(ent_Entity* obj);
extern bool ent_Entity_isAttacking(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isAttackingFaction(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_isInAttackAction(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isFightingWith(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isActivelyFighting(ent_Entity* obj);
extern bool ent_Entity_isFighting(ent_Entity* obj);
extern bool ent_Entity_internalIsFighting(ent_Entity* obj);
extern bool ent_Entity_internalIsActivelyFighting(ent_Entity* obj);
extern bool ent_Entity_isFightingFaction(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_isBullyingFaction(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_hasRecentlyAttackedFaction(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_hasRecentlyAttacked(ent_Entity* obj);
extern bool ent_Entity_wasAttackedByFactionInFight(ent_Entity* obj, ent_Faction* arg1);
extern bool ent_Entity_wasRecentlyAttacked(ent_Entity* obj, ent_Entity* arg1, void* arg2);
extern bool ent_Entity_isFightingAnyFaction(ent_Entity* obj);
extern bool ent_Entity_isEngaging(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_isMeleeEngaged(ent_Entity* obj);
extern bool ent_Entity_isTargetNeutralised(ent_Entity* obj, ent_Entity* arg1);
extern void ent_Entity_onKill(ent_Entity* obj, ent_Entity* arg1);
extern void ent_Entity_onExecute(ent_Entity* obj, ent_Entity* arg1, void* arg2);
extern void ent_Entity_lootKill(ent_Entity* obj, ent_Entity* arg1);
extern void ent_Entity_onEliminate(ent_Entity* obj, ent_Entity* arg1, ent_Entity* arg2);
extern void ent_Entity_updateStats(ent_Entity* obj, double arg1);
extern bool ent_Entity_canRegen(ent_Entity* obj);
extern double ent_Entity_getDailyLifeRegen(ent_Entity* obj);
extern double ent_Entity_getLifeRegenModifier(ent_Entity* obj);
extern double ent_Entity_getDailyLifeDecay(ent_Entity* obj);
extern void ent_Entity_updateLife(ent_Entity* obj, double arg1);
extern void ent_Entity_healBy(ent_Entity* obj, ent_Entity* arg1, double arg2);
extern bool ent_Entity_canDie(ent_Entity* obj);
extern void ent_Entity_die(ent_Entity* obj, void* arg1);
extern void ent_Entity_preDie(ent_Entity* obj);
extern bool ent_Entity_isDead(ent_Entity* obj);
extern bool ent_Entity_isNeutralised(ent_Entity* obj);
extern void ent_Entity_engage(ent_Entity* obj, ent_Entity* arg1);
extern void ent_Entity_refreshCombatImplications(ent_Entity* obj, ent_Entity* arg1, bool arg2, bool arg3);
extern bool ent_Entity_canCauseFightImplications(ent_Entity* obj);
extern void ent_Entity_endCombatWith(ent_Entity* obj, ent_Entity* arg1);
extern void ent_Entity_clearCombat(ent_Entity* obj);
extern void ent_Entity_breakFightWith(ent_Entity* obj, ent_Faction* arg1, ent_Entity* arg2);
extern void ent_Entity_refreshCombatWith(ent_Entity* obj, ent_Entity* arg1, void* arg2, void* arg3);
extern void ent_Entity_startCombat(ent_Entity* obj);
extern void ent_Entity_onCombatStarted(ent_Entity* obj);
extern void ent_Entity_endCombat(ent_Entity* obj);
extern void ent_Entity_updateFighting(ent_Entity* obj, double arg1);
extern void ent_Entity_updateCombatState(ent_Entity* obj);
extern bool ent_Entity_hasCombatEnded(ent_Entity* obj, void* arg1);
extern ent_Entity* ent_Entity_getMostFreshCombatOpponent(ent_Entity* obj);
extern bool ent_Entity_isOnlyAttackedBy(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_hasVillageInRange(ent_Entity* obj, double arg1, void* arg2);
extern bool ent_Entity_isVillageInRange(ent_Entity* obj, ent_Structure* arg1, double arg2, void* arg3);
extern void ent_Entity_handleNewCombatImplications(ent_Entity* obj, ent_Entity* arg1);
extern EReason* ent_Entity_requestRefund(ent_Entity* obj, void* arg1);
extern bool ent_Entity_rpcRequestRefund__impl(ent_Entity* obj);
extern EReason* ent_Entity_checkRequestRefund(ent_Entity* obj);
extern bool ent_Entity_canRequestRefund(ent_Entity* obj);
extern EReason* ent_Entity_carryEntity(ent_Entity* obj, ent_Entity* arg1, void* arg2);
extern bool ent_Entity_rpcCarryEntity__impl(ent_Entity* obj, ent_Entity* arg1);
extern EReason* ent_Entity_checkCarryEntity(ent_Entity* obj, ent_Entity* arg1);
extern bool ent_Entity_canCarryEntity(ent_Entity* obj, ent_Entity* arg1);
extern EReason* ent_Entity_serverQueueAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3, void* arg4);
extern bool ent_Entity_rpcServerQueueAction__impl(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern EReason* ent_Entity_checkServerQueueAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern bool ent_Entity_canServerQueueAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern EReason* ent_Entity_clearAllActions(ent_Entity* obj, void* arg1);
extern bool ent_Entity_rpcClearAllActions__impl(ent_Entity* obj);
extern EReason* ent_Entity_checkClearAllActions(ent_Entity* obj);
extern bool ent_Entity_canClearAllActions(ent_Entity* obj);
extern EReason* ent_Entity_serverClearActionQueue(ent_Entity* obj, void* arg1);
extern bool ent_Entity_rpcServerClearActionQueue__impl(ent_Entity* obj);
extern EReason* ent_Entity_checkServerClearActionQueue(ent_Entity* obj);
extern bool ent_Entity_canServerClearActionQueue(ent_Entity* obj);
extern EReason* ent_Entity_doAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3, void* arg4);
extern bool ent_Entity_rpcDoAction__impl(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern EReason* ent_Entity_checkDoAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern bool ent_Entity_canDoAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern EReason* ent_Entity_cancelAction(ent_Entity* obj, void* arg1);
extern bool ent_Entity_rpcCancelAction__impl(ent_Entity* obj);
extern EReason* ent_Entity_checkCancelAction(ent_Entity* obj);
extern bool ent_Entity_canCancelAction(ent_Entity* obj);
extern ent_EKind* ent_Entity___net_mark_ekind(ent_Entity* obj, ent_EKind* arg1);
extern ent_EKind* ent_Entity_set_ekind(ent_Entity* obj, ent_EKind* arg1);
extern int ent_Entity_get_networkPropEkind(ent_Entity* obj);
extern double ent_Entity___net_mark_createdAt(ent_Entity* obj, double arg1);
extern double ent_Entity_set_createdAt(ent_Entity* obj, double arg1);
extern int ent_Entity_get_networkPropCreatedAt(ent_Entity* obj);
extern double ent_Entity___net_mark_posx(ent_Entity* obj, double arg1);
extern int ent_Entity_get_networkPropPosx(ent_Entity* obj);
extern double ent_Entity___net_mark_posy(ent_Entity* obj, double arg1);
extern int ent_Entity_get_networkPropPosy(ent_Entity* obj);
extern double ent_Entity___net_mark_rotation(ent_Entity* obj, double arg1);
extern int ent_Entity_get_networkPropRotation(ent_Entity* obj);
extern ent_State* ent_Entity___net_mark_state(ent_Entity* obj, ent_State* arg1);
extern int ent_Entity_get_networkPropState(ent_Entity* obj);
extern ent_StateInfo* ent_Entity___net_mark_stateInfo(ent_Entity* obj, ent_StateInfo* arg1);
extern ent_StateInfo* ent_Entity_set_stateInfo(ent_Entity* obj, ent_StateInfo* arg1);
extern int ent_Entity_get_networkPropStateInfo(ent_Entity* obj);
extern ent_Entity* ent_Entity___net_mark__owner(ent_Entity* obj, ent_Entity* arg1);
extern ent_Entity* ent_Entity_set__owner(ent_Entity* obj, ent_Entity* arg1);
extern int ent_Entity_get_networkProp_owner(ent_Entity* obj);
extern void* ent_Entity___net_mark_action(ent_Entity* obj, void* arg1);
extern int ent_Entity_get_networkPropAction(ent_Entity* obj);
extern logic_Upgrades* ent_Entity___net_mark_upgrades(ent_Entity* obj, logic_Upgrades* arg1);
extern logic_Upgrades* ent_Entity_set_upgrades(ent_Entity* obj, logic_Upgrades* arg1);
extern int ent_Entity_get_networkPropUpgrades(ent_Entity* obj);
extern hxbit_ArrayProxyData* ent_Entity___net_mark_components(ent_Entity* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Entity_get_networkPropComponents(ent_Entity* obj);
extern hl_types_ArrayObj* ent_Entity___net_mark_combatInfos(ent_Entity* obj, hl_types_ArrayObj* arg1);
extern hl_types_ArrayObj* ent_Entity_set_combatInfos(ent_Entity* obj, hl_types_ArrayObj* arg1);
extern int ent_Entity_get_networkPropCombatInfos(ent_Entity* obj);
extern int ent_Entity___net_mark_combatState(ent_Entity* obj, int arg1);
extern int ent_Entity_set_combatState(ent_Entity* obj, int arg1);
extern int ent_Entity_get_networkPropCombatState(ent_Entity* obj);
extern double ent_Entity___net_mark_life(ent_Entity* obj, double arg1);
extern int ent_Entity_get_networkPropLife(ent_Entity* obj);
extern double ent_Entity___net_mark_lifeLostInCombat(ent_Entity* obj, double arg1);
extern double ent_Entity_set_lifeLostInCombat(ent_Entity* obj, double arg1);
extern int ent_Entity_get_networkPropLifeLostInCombat(ent_Entity* obj);
extern double ent_Entity___net_mark_armorDamage(ent_Entity* obj, double arg1);
extern double ent_Entity_set_armorDamage(ent_Entity* obj, double arg1);
extern int ent_Entity_get_networkPropArmorDamage(ent_Entity* obj);
extern double ent_Entity___net_mark_prevMaxLife(ent_Entity* obj, double arg1);
extern double ent_Entity_set_prevMaxLife(ent_Entity* obj, double arg1);
extern int ent_Entity_get_networkPropPrevMaxLife(ent_Entity* obj);
extern double ent_Entity___net_mark_prevMaxArmor(ent_Entity* obj, double arg1);
extern double ent_Entity_set_prevMaxArmor(ent_Entity* obj, double arg1);
extern int ent_Entity_get_networkPropPrevMaxArmor(ent_Entity* obj);
extern void ent_Entity_playFadeIn(ent_Entity* obj, void* arg1);
extern void ent_Entity_playFadeOut(ent_Entity* obj, void* arg1);
extern void ent_Entity_ownerQueueAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3);
extern void ent_Entity_ownerClearActionQueue(ent_Entity* obj);
extern void ent_Entity_unqueueAction(ent_Entity* obj);
extern void ent_Entity_rpcShowQueuedActionsFeedback(ent_Entity* obj);
extern void ent_Entity_rpcClearQueuedActionsFeedback(ent_Entity* obj);
extern void ent_Entity_removeWithFade(ent_Entity* obj, void* arg1);
extern void ent_Entity_playDeathAnim(ent_Entity* obj, String* arg1, double arg2);
extern void ent_Entity_rpcPlayActionFeedback(ent_Entity* obj, String* arg1, ent_EActionTarget* arg2);
extern void ent_Entity_playActionQuoteRpc(ent_Entity* obj, int arg1);
extern void ent_Entity_teleport(ent_Entity* obj, void* arg1);
extern void ent_Entity_playAttack(ent_Entity* obj, String* arg1, int arg2, ent_Entity* arg3, void* arg4);
extern void ent_Entity_playAttackEffects(ent_Entity* obj, String* arg1, int arg2, ent_Entity* arg3, void* arg4);
extern void ent_Entity_playSkill(ent_Entity* obj, String* arg1);
extern void ent_Entity_playSkillStart(ent_Entity* obj, String* arg1);
extern void ent_Entity_playSkillStop(ent_Entity* obj, String* arg1);
extern void ent_Entity_rpcRequestRefund(ent_Entity* obj, void* arg1);
extern void ent_Entity_rpcCarryEntity(ent_Entity* obj, ent_Entity* arg1, void* arg2);
extern void ent_Entity_rpcServerQueueAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3, void* arg4);
extern void ent_Entity_rpcClearAllActions(ent_Entity* obj, void* arg1);
extern void ent_Entity_rpcServerClearActionQueue(ent_Entity* obj, void* arg1);
extern void ent_Entity_rpcDoAction(ent_Entity* obj, String* arg1, void* arg2, ent_Faction* arg3, void* arg4);
extern void ent_Entity_rpcCancelAction(ent_Entity* obj, void* arg1);
extern void ent_Entity_networkFlush(ent_Entity* obj, hxbit_Serializer* arg1);
extern void ent_Entity_networkSync(ent_Entity* obj, hxbit_Serializer* arg1);
extern bool ent_Entity_networkRPC(ent_Entity* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Entity_networkGetName(ent_Entity* obj, int arg1, void* arg2);
extern int ent_Entity_getCLID(ent_Entity* obj);
extern void ent_Entity_serialize(ent_Entity* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Entity_getSerializeSchema(ent_Entity* obj);
extern void ent_Entity_unserializeInit(ent_Entity* obj);
extern void ent_Entity_unserialize(ent_Entity* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_Entity_h__
