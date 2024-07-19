// gen time: 2024-07-14 16:20:10 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_Building_h__
#define __gen_t_ent_Building_h__

#include <common.h>
#include <gen/t.ent.BaseBuilding.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_AttackTargetKind ent_AttackTargetKind;
typedef struct ent_Building ent_Building;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct h3d_anim_Animation h3d_anim_Animation;
typedef struct h3d_col_Collider h3d_col_Collider;
typedef struct h3d_scene_Object h3d_scene_Object;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct hxd_res_Model hxd_res_Model;
typedef struct shaders_ColorSet shaders_ColorSet;


// type: ent.Building, kind: HOBJ, pType: 0x01EC714D19D8
struct ent_Building {
  // super: ent.BaseBuilding
  ent_BaseBuilding          super;

  // cls: ent.Building, begin_offset: 0x0392
  h3d_scene_Object*         buildingObj;        // +0398: HOBJ h3d.scene.Object
  shaders_ColorSet*         colorShader;        // +03A0: HOBJ shaders.ColorSet
  h3d_anim_Animation*       constructAnim;      // +03A8: HOBJ h3d.anim.Animation
  double                    infMaxLife;         // +03B0
  hl_types_ArrayObj*        constructMats;      // +03B8: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        neuralNodeFxs;      // +03C0: HOBJ hl.types.ArrayObj
  // total_size: 0x03C8
}; // ent_Building (ent.Building)

_Static_assert(sizeof(ent_Building) == 0x03C8, "cls ent.Building has wrong size");


extern void ent_Building_init(ent_Building* obj);
extern bool ent_Building_isNotInWorld(ent_Building* obj);
extern void ent_Building_finalize(ent_Building* obj);
extern ent_Entity* ent_Building_getSelectOnRemove(ent_Building* obj);
extern void ent_Building_doRemove(ent_Building* obj);
extern EReason* ent_Building_getNoRefundReason(ent_Building* obj);
extern void ent_Building_rpcChangeOwner__impl(ent_Building* obj, ent_Faction* arg1, ent_Faction* arg2);
extern void ent_Building_updateModel(ent_Building* obj);
extern double ent_Building_getFlagOffset(ent_Building* obj);
extern int ent_Building_getBannerWidgetPriority(ent_Building* obj);
extern bool ent_Building_useStaticFlag(ent_Building* obj);
extern bool ent_Building_canShowAlignment(ent_Building* obj);
extern void ent_Building_initVisual(ent_Building* obj);
extern h3d_col_Collider* ent_Building_makeInteractiveCollider(ent_Building* obj);
extern void ent_Building_playAttack__impl(ent_Building* obj, String* arg1, int arg2, ent_Entity* arg3, void* arg4);
extern void ent_Building_pointTowards(ent_Building* obj, ent_Entity* arg1);
extern void ent_Building_updateNeuralNodeFxs(ent_Building* obj);
extern double ent_Building_getMaxLifeAdditiveModifier(ent_Building* obj);
extern double ent_Building_getArmorModifier(ent_Building* obj);
extern double ent_Building_getBasePower(ent_Building* obj);
extern double ent_Building_getPowerModifier(ent_Building* obj, void* arg1);
extern double ent_Building_getBaseMaxLife(ent_Building* obj);
extern double ent_Building_get_maxLife(ent_Building* obj);
extern double ent_Building_getExpectedMaxLife(ent_Building* obj);
extern double ent_Building_getBaseArmor(ent_Building* obj);
extern bool ent_Building_isDamageableEntity(ent_Building* obj);
extern ent_AttackTargetKind* ent_Building_getAssociatedTargetType(ent_Building* obj);
extern void ent_Building_onOver(ent_Building* obj);
extern void ent_Building_onOut(ent_Building* obj);
extern void ent_Building_selectFeedback(ent_Building* obj, void* arg1);
extern h3d_anim_Animation* ent_Building_playAnimRes(ent_Building* obj, String* arg1, hxd_res_Model* arg2, void* arg3);
extern void ent_Building_onUnselect(ent_Building* obj);
extern bool ent_Building_isCulled(ent_Building* obj);
extern void ent_Building_onFinishConstructionClient__impl(ent_Building* obj);
extern void ent_Building_onFinishConstruction(ent_Building* obj);
extern void ent_Building_refreshStatusFX(ent_Building* obj);
extern void ent_Building_frameUpdate(ent_Building* obj, double arg1);
extern bool ent_Building_shouldFixedPosition(ent_Building* obj);
extern void ent_Building_regularUpdate(ent_Building* obj, double arg1);
extern bool ent_Building_isProjectileBlocked(ent_Building* obj);
extern String* ent_Building_getIdStr(ent_Building* obj);
extern void ent_Building_onFinishConstructionClient(ent_Building* obj);
extern void ent_Building_networkFlush(ent_Building* obj, hxbit_Serializer* arg1);
extern void ent_Building_networkSync(ent_Building* obj, hxbit_Serializer* arg1);
extern bool ent_Building_networkRPC(ent_Building* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Building_networkGetName(ent_Building* obj, int arg1, void* arg2);
extern int ent_Building_getCLID(ent_Building* obj);
extern void ent_Building_unserializeInit(ent_Building* obj);
extern void ent_Building_unserialize(ent_Building* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_Building_h__
