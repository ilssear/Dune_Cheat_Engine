// gen time: 2024-07-21 07:20:41 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_AttributeApplication_h__
#define __gen_t_logic_AttributeApplication_h__

#include <common.h>
#include <gen/t.net.Serializable.h>

typedef struct EScope EScope;
typedef struct ESourceKind ESourceKind;
typedef struct ETargetKind ETargetKind;
typedef struct String String;
typedef struct ent_Entity ent_Entity;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_AttributeApplication logic_AttributeApplication;
typedef struct logic_AttributesManager logic_AttributesManager;
typedef struct logic_Logic logic_Logic;


// type: logic.AttributeApplication, kind: HOBJ, pType: 0x02A76E3227D8
struct logic_AttributeApplication {
  // super: net.Serializable
  net_Serializable          super;

  // cls: logic.AttributeApplication, begin_offset: 0x0038
  int                       uid;                // +0038
  String*                   kind;               // +0040: HOBJ String
  double                    val;                // +0048
  logic_AttributesManager*  manager;            // +0050: HOBJ logic.AttributesManager
  ESourceKind*              source;             // +0058: HENUM ESourceKind
  EScope*                   scope;              // +0060: HENUM EScope
  ETargetKind*              target;             // +0068: HENUM ETargetKind
  ETargetKind*              target2;            // +0070: HENUM ETargetKind
  ent_Entity*               faction;            // +0078: HOBJ ent.Entity
  int                       stackCount;         // +0080
  int64                     context;            // +0088
  // total_size: 0x0090
}; // logic_AttributeApplication (logic.AttributeApplication)

_Static_assert(sizeof(logic_AttributeApplication) == 0x0090, "cls logic.AttributeApplication has wrong size");


extern logic_Logic* logic_AttributeApplication_get_owner(logic_AttributeApplication* obj);
extern String* logic_AttributeApplication_toString(logic_AttributeApplication* obj);
extern void logic_AttributeApplication_unserialize(logic_AttributeApplication* obj, hxbit_Serializer* arg1);
extern int logic_AttributeApplication___net_mark_uid(logic_AttributeApplication* obj, int arg1);
extern int logic_AttributeApplication_set_uid(logic_AttributeApplication* obj, int arg1);
extern int logic_AttributeApplication_get_networkPropUid(logic_AttributeApplication* obj);
extern String* logic_AttributeApplication___net_mark_kind(logic_AttributeApplication* obj, String* arg1);
extern String* logic_AttributeApplication_set_kind(logic_AttributeApplication* obj, String* arg1);
extern int logic_AttributeApplication_get_networkPropKind(logic_AttributeApplication* obj);
extern double logic_AttributeApplication___net_mark_val(logic_AttributeApplication* obj, double arg1);
extern double logic_AttributeApplication_set_val(logic_AttributeApplication* obj, double arg1);
extern int logic_AttributeApplication_get_networkPropVal(logic_AttributeApplication* obj);
extern logic_AttributesManager* logic_AttributeApplication___net_mark_manager(logic_AttributeApplication* obj, logic_AttributesManager* arg1);
extern logic_AttributesManager* logic_AttributeApplication_set_manager(logic_AttributeApplication* obj, logic_AttributesManager* arg1);
extern int logic_AttributeApplication_get_networkPropManager(logic_AttributeApplication* obj);
extern ESourceKind* logic_AttributeApplication___net_mark_source(logic_AttributeApplication* obj, ESourceKind* arg1);
extern ESourceKind* logic_AttributeApplication_set_source(logic_AttributeApplication* obj, ESourceKind* arg1);
extern int logic_AttributeApplication_get_networkPropSource(logic_AttributeApplication* obj);
extern EScope* logic_AttributeApplication___net_mark_scope(logic_AttributeApplication* obj, EScope* arg1);
extern EScope* logic_AttributeApplication_set_scope(logic_AttributeApplication* obj, EScope* arg1);
extern int logic_AttributeApplication_get_networkPropScope(logic_AttributeApplication* obj);
extern ETargetKind* logic_AttributeApplication___net_mark_target(logic_AttributeApplication* obj, ETargetKind* arg1);
extern ETargetKind* logic_AttributeApplication_set_target(logic_AttributeApplication* obj, ETargetKind* arg1);
extern int logic_AttributeApplication_get_networkPropTarget(logic_AttributeApplication* obj);
extern ETargetKind* logic_AttributeApplication___net_mark_target2(logic_AttributeApplication* obj, ETargetKind* arg1);
extern ETargetKind* logic_AttributeApplication_set_target2(logic_AttributeApplication* obj, ETargetKind* arg1);
extern int logic_AttributeApplication_get_networkPropTarget2(logic_AttributeApplication* obj);
extern ent_Entity* logic_AttributeApplication___net_mark_faction(logic_AttributeApplication* obj, ent_Entity* arg1);
extern ent_Entity* logic_AttributeApplication_set_faction(logic_AttributeApplication* obj, ent_Entity* arg1);
extern int logic_AttributeApplication_get_networkPropFaction(logic_AttributeApplication* obj);
extern int logic_AttributeApplication___net_mark_stackCount(logic_AttributeApplication* obj, int arg1);
extern int logic_AttributeApplication_set_stackCount(logic_AttributeApplication* obj, int arg1);
extern int logic_AttributeApplication_get_networkPropStackCount(logic_AttributeApplication* obj);
extern void logic_AttributeApplication_networkFlush(logic_AttributeApplication* obj, hxbit_Serializer* arg1);
extern void logic_AttributeApplication_networkSync(logic_AttributeApplication* obj, hxbit_Serializer* arg1);
extern String* logic_AttributeApplication_networkGetName(logic_AttributeApplication* obj, int arg1, void* arg2);
extern int logic_AttributeApplication_getCLID(logic_AttributeApplication* obj);
extern void logic_AttributeApplication_serialize(logic_AttributeApplication* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_AttributeApplication_getSerializeSchema(logic_AttributeApplication* obj);
extern void logic_AttributeApplication_unserializeInit(logic_AttributeApplication* obj);
extern byte* logic_AttributeApplication___string(logic_AttributeApplication* obj);


#endif // __gen_t_logic_AttributeApplication_h__
