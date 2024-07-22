// gen time: 2024-07-21 07:31:36 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_ent_StateInfo_h__
#define __gen_t_ent_StateInfo_h__

#include <common.h>
#include <gen/t.net.Serializable.h>

typedef struct String String;
typedef struct ent_StateInfo ent_StateInfo;
typedef struct hxbit_ObjProxy_Oability_Data_AbilityKind_end_Float hxbit_ObjProxy_Oability_Data_AbilityKind_end_Float;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;


// type: ent.StateInfo, kind: HOBJ, pType: 0x02A76E31D798
struct ent_StateInfo {
  // super: net.Serializable
  net_Serializable          super;

  // cls: ent.StateInfo, begin_offset: 0x0038
  bool                      replicated;         // +0038
  hxbit_ObjProxy_Oability_Data_AbilityKind_end_Float* skillLock; // +0040: HOBJ hxbit.ObjProxy_Oability_Data_AbilityKind_end_Float
  double                    vibrationsAccum;    // +0048
  double                    vibrationsThreshold; // +0050
  bool                      hasGoneLowHealth;   // +0058
  double                    nextMissileTime;    // +0060
  double                    __ref_vibrationsAccum; // +0068
  // total_size: 0x0070
}; // ent_StateInfo (ent.StateInfo)

_Static_assert(sizeof(ent_StateInfo) == 0x0070, "cls ent.StateInfo has wrong size");


extern bool ent_StateInfo_getEnableReplication(ent_StateInfo* obj);
extern bool ent_StateInfo___net_mark_replicated(ent_StateInfo* obj, bool arg1);
extern bool ent_StateInfo_set_replicated(ent_StateInfo* obj, bool arg1);
extern int ent_StateInfo_get_networkPropReplicated(ent_StateInfo* obj);
extern hxbit_ObjProxy_Oability_Data_AbilityKind_end_Float* ent_StateInfo___net_mark_skillLock(ent_StateInfo* obj, hxbit_ObjProxy_Oability_Data_AbilityKind_end_Float* arg1);
extern hxbit_ObjProxy_Oability_Data_AbilityKind_end_Float* ent_StateInfo_set_skillLock(ent_StateInfo* obj, hxbit_ObjProxy_Oability_Data_AbilityKind_end_Float* arg1);
extern int ent_StateInfo_get_networkPropSkillLock(ent_StateInfo* obj);
extern double ent_StateInfo___net_mark_vibrationsAccum(ent_StateInfo* obj, double arg1);
extern double ent_StateInfo_set_vibrationsAccum(ent_StateInfo* obj, double arg1);
extern int ent_StateInfo_get_networkPropVibrationsAccum(ent_StateInfo* obj);
extern double ent_StateInfo___net_mark_vibrationsThreshold(ent_StateInfo* obj, double arg1);
extern double ent_StateInfo_set_vibrationsThreshold(ent_StateInfo* obj, double arg1);
extern int ent_StateInfo_get_networkPropVibrationsThreshold(ent_StateInfo* obj);
extern bool ent_StateInfo___net_mark_hasGoneLowHealth(ent_StateInfo* obj, bool arg1);
extern bool ent_StateInfo_set_hasGoneLowHealth(ent_StateInfo* obj, bool arg1);
extern int ent_StateInfo_get_networkPropHasGoneLowHealth(ent_StateInfo* obj);
extern double ent_StateInfo___net_mark_nextMissileTime(ent_StateInfo* obj, double arg1);
extern double ent_StateInfo_set_nextMissileTime(ent_StateInfo* obj, double arg1);
extern int ent_StateInfo_get_networkPropNextMissileTime(ent_StateInfo* obj);
extern void ent_StateInfo_networkFlush(ent_StateInfo* obj, hxbit_Serializer* arg1);
extern void ent_StateInfo_networkSync(ent_StateInfo* obj, hxbit_Serializer* arg1);
extern String* ent_StateInfo_networkGetName(ent_StateInfo* obj, int arg1, void* arg2);
extern int ent_StateInfo_getCLID(ent_StateInfo* obj);
extern void ent_StateInfo_serialize(ent_StateInfo* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_StateInfo_getSerializeSchema(ent_StateInfo* obj);
extern void ent_StateInfo_unserializeInit(ent_StateInfo* obj);
extern void ent_StateInfo_unserialize(ent_StateInfo* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_StateInfo_h__
