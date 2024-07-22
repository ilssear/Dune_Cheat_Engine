// gen time: 2024-07-21 08:20:02 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_ent_ResourcesGenerator_h__
#define __gen_t_ent_ResourcesGenerator_h__

#include <common.h>
#include <gen/t.net.Serializable.h>

typedef struct String String;
typedef struct ent_ResourcesGenerator ent_ResourcesGenerator;
typedef struct ent_Zone ent_Zone;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;


// type: ent.ResourcesGenerator, kind: HOBJ, pType: 0x02A76E31DE18
struct ent_ResourcesGenerator {
  // super: net.Serializable
  net_Serializable          super;

  // cls: ent.ResourcesGenerator, begin_offset: 0x0038
  String*                   kind;               // +0038: HOBJ String
  hxbit_MapData*            resources;          // +0040: HOBJ hxbit.MapData
  void*                     inf;                // +0048: HVIRTUAL
  // total_size: 0x0050
}; // ent_ResourcesGenerator (ent.ResourcesGenerator)

_Static_assert(sizeof(ent_ResourcesGenerator) == 0x0050, "cls ent.ResourcesGenerator has wrong size");


extern void ent_ResourcesGenerator_alive(ent_ResourcesGenerator* obj);
extern void ent_ResourcesGenerator_init(ent_ResourcesGenerator* obj);
extern void ent_ResourcesGenerator_add(ent_ResourcesGenerator* obj, String* arg1, double arg2, void* arg3);
extern void* ent_ResourcesGenerator_get(ent_ResourcesGenerator* obj, String* arg1);
extern void ent_ResourcesGenerator_set(ent_ResourcesGenerator* obj, String* arg1, double arg2);
extern void* ent_ResourcesGenerator_keys(ent_ResourcesGenerator* obj);
extern void ent_ResourcesGenerator_setStartResources(ent_ResourcesGenerator* obj, ent_Zone* arg1);
extern void ent_ResourcesGenerator_forceResourceProd(ent_ResourcesGenerator* obj, String* arg1, void* arg2);
extern String* ent_ResourcesGenerator___net_mark_kind(ent_ResourcesGenerator* obj, String* arg1);
extern String* ent_ResourcesGenerator_set_kind(ent_ResourcesGenerator* obj, String* arg1);
extern int ent_ResourcesGenerator_get_networkPropKind(ent_ResourcesGenerator* obj);
extern hxbit_MapData* ent_ResourcesGenerator___net_mark_resources(ent_ResourcesGenerator* obj, hxbit_MapData* arg1);
extern hxbit_MapData* ent_ResourcesGenerator_set_resources(ent_ResourcesGenerator* obj, hxbit_MapData* arg1);
extern int ent_ResourcesGenerator_get_networkPropResources(ent_ResourcesGenerator* obj);
extern void ent_ResourcesGenerator_networkFlush(ent_ResourcesGenerator* obj, hxbit_Serializer* arg1);
extern void ent_ResourcesGenerator_networkSync(ent_ResourcesGenerator* obj, hxbit_Serializer* arg1);
extern String* ent_ResourcesGenerator_networkGetName(ent_ResourcesGenerator* obj, int arg1, void* arg2);
extern int ent_ResourcesGenerator_getCLID(ent_ResourcesGenerator* obj);
extern void ent_ResourcesGenerator_serialize(ent_ResourcesGenerator* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_ResourcesGenerator_getSerializeSchema(ent_ResourcesGenerator* obj);
extern void ent_ResourcesGenerator_unserialize(ent_ResourcesGenerator* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_ResourcesGenerator_h__
