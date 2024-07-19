// gen time: 2024-07-14 16:48:17 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_comp_EntityComponent_h__
#define __gen_t_ent_comp_EntityComponent_h__

#include <common.h>
#include <gen/t.net.Serializable.h>

typedef struct String String;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Zone ent_Zone;
typedef struct ent_comp_EntityComponent ent_comp_EntityComponent;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct hrt_prefab_Resource hrt_prefab_Resource;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_SceneObject lib_SceneObject;
typedef struct logic_TraitsManager logic_TraitsManager;
typedef struct logic_Upgrades logic_Upgrades;
typedef struct prefab_FXAnimation prefab_FXAnimation;


// type: ent.comp.EntityComponent, kind: HOBJ, pType: 0x01EC714D1598
struct ent_comp_EntityComponent {
  // super: net.Serializable
  net_Serializable          super;

  // cls: ent.comp.EntityComponent, begin_offset: 0x0038
  ent_Entity*               entity;             // +0038: HOBJ ent.Entity
  bool                      inited;             // +0040
  void*                     oldHxBitFields;     // +0048: HDYN
  // total_size: 0x0050
}; // ent_comp_EntityComponent (ent.comp.EntityComponent)

_Static_assert(sizeof(ent_comp_EntityComponent) == 0x0050, "cls ent.comp.EntityComponent has wrong size");


extern void ent_comp_EntityComponent_init(ent_comp_EntityComponent* obj, ent_Entity* arg1);
extern void ent_comp_EntityComponent_finalize(ent_comp_EntityComponent* obj);
extern void ent_comp_EntityComponent_alive(ent_comp_EntityComponent* obj);
extern void ent_comp_EntityComponent_patchEntity(ent_comp_EntityComponent* obj, int arg1);
extern void ent_comp_EntityComponent_initFxs(ent_comp_EntityComponent* obj);
extern void ent_comp_EntityComponent_update(ent_comp_EntityComponent* obj, double arg1);
extern void ent_comp_EntityComponent_regularUpdate(ent_comp_EntityComponent* obj, double arg1);
extern void ent_comp_EntityComponent_frameUpdate(ent_comp_EntityComponent* obj, double arg1);
extern void ent_comp_EntityComponent_breakFightWith(ent_comp_EntityComponent* obj, ent_Faction* arg1, ent_Entity* arg2);
extern void ent_comp_EntityComponent_onReceiveDamage(ent_comp_EntityComponent* obj, ent_Entity* arg1, double arg2);
extern ent_Entity* ent_comp_EntityComponent_set_entity(ent_comp_EntityComponent* obj, ent_Entity* arg1);
extern bool ent_comp_EntityComponent_networkAllow(ent_comp_EntityComponent* obj, int arg1, int arg2, void* arg3);
extern bool ent_comp_EntityComponent_enableApiLog(ent_comp_EntityComponent* obj);
extern void ent_comp_EntityComponent_onEntityRemoved(ent_comp_EntityComponent* obj);
extern void ent_comp_EntityComponent_remove(ent_comp_EntityComponent* obj);
extern ent_Faction* ent_comp_EntityComponent_get_owner(ent_comp_EntityComponent* obj);
extern ent_Faction* ent_comp_EntityComponent_set_owner(ent_comp_EntityComponent* obj, ent_Faction* arg1);
extern h2d_col_PointImpl* ent_comp_EntityComponent_get_position(ent_comp_EntityComponent* obj);
extern h2d_col_PointImpl* ent_comp_EntityComponent_set_position(ent_comp_EntityComponent* obj, h2d_col_PointImpl* arg1);
extern ent_Zone* ent_comp_EntityComponent_get_zone(ent_comp_EntityComponent* obj);
extern double ent_comp_EntityComponent_get_x(ent_comp_EntityComponent* obj);
extern double ent_comp_EntityComponent_get_y(ent_comp_EntityComponent* obj);
extern double ent_comp_EntityComponent_get_z(ent_comp_EntityComponent* obj);
extern lib_SceneObject* ent_comp_EntityComponent_get_obj(ent_comp_EntityComponent* obj);
extern double ent_comp_EntityComponent_get_life(ent_comp_EntityComponent* obj);
extern double ent_comp_EntityComponent_set_life(ent_comp_EntityComponent* obj, double arg1);
extern double ent_comp_EntityComponent_get_maxLife(ent_comp_EntityComponent* obj);
extern double ent_comp_EntityComponent_get_power(ent_comp_EntityComponent* obj);
extern double ent_comp_EntityComponent_get_armor(ent_comp_EntityComponent* obj);
extern double ent_comp_EntityComponent_get_maxArmor(ent_comp_EntityComponent* obj);
extern logic_Upgrades* ent_comp_EntityComponent_get_upgrades(ent_comp_EntityComponent* obj);
extern logic_TraitsManager* ent_comp_EntityComponent_get_traits(ent_comp_EntityComponent* obj);
extern double ent_comp_EntityComponent_getConst(ent_comp_EntityComponent* obj, String* arg1);
extern prefab_FXAnimation* ent_comp_EntityComponent_playFX(ent_comp_EntityComponent* obj, hrt_prefab_Resource* arg1, String* arg2, void* arg3);
extern void ent_comp_EntityComponent_networkFlush(ent_comp_EntityComponent* obj, hxbit_Serializer* arg1);
extern void ent_comp_EntityComponent_networkSync(ent_comp_EntityComponent* obj, hxbit_Serializer* arg1);
extern int ent_comp_EntityComponent_getCLID(ent_comp_EntityComponent* obj);
extern void ent_comp_EntityComponent_unserializeInit(ent_comp_EntityComponent* obj);
extern void ent_comp_EntityComponent_unserialize(ent_comp_EntityComponent* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_comp_EntityComponent_h__
