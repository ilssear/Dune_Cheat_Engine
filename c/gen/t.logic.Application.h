// gen time: 2024-07-21 07:20:41 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_Application_h__
#define __gen_t_logic_Application_h__

#include <common.h>
#include <gen/t.net.Serializable.h>

typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Object ent_Object;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_Application logic_Application;
typedef struct logic_EApplicationStyle logic_EApplicationStyle;
typedef struct logic_ESourceKind logic_ESourceKind;


// type: logic.Application, kind: HOBJ, pType: 0x02A76E324D58
struct logic_Application {
  // super: net.Serializable
  net_Serializable          super;

  // cls: logic.Application, begin_offset: 0x0038
  int                       uid;                // +0038
  String*                   id;                 // +0040: HOBJ String
  logic_EApplicationStyle*  style;              // +0048: HENUM logic.EApplicationStyle
  ent_Faction*              faction;            // +0050: HOBJ ent.Faction
  ent_Object*               instigator;         // +0058: HOBJ ent.Object
  double                    startTime;          // +0060
  hxbit_ArrayProxyData*     atbUIDs;            // +0068: HOBJ hxbit.ArrayProxyData
  hl_types_ArrayObj*        appConditions;      // +0070: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        blockingConditions; // +0078: HOBJ hl.types.ArrayObj
  logic_ESourceKind*        src;                // +0080: HENUM logic.ESourceKind
  int                       stackCount;         // +0088
  // total_size: 0x008C
}; // logic_Application (logic.Application)

_Static_assert(sizeof(logic_Application) == 0x0090, "cls logic.Application has wrong size");


extern void logic_Application_alive(logic_Application* obj);
extern int logic_Application___net_mark_uid(logic_Application* obj, int arg1);
extern int logic_Application_set_uid(logic_Application* obj, int arg1);
extern int logic_Application_get_networkPropUid(logic_Application* obj);
extern String* logic_Application___net_mark_id(logic_Application* obj, String* arg1);
extern String* logic_Application_set_id(logic_Application* obj, String* arg1);
extern int logic_Application_get_networkPropId(logic_Application* obj);
extern logic_EApplicationStyle* logic_Application___net_mark_style(logic_Application* obj, logic_EApplicationStyle* arg1);
extern logic_EApplicationStyle* logic_Application_set_style(logic_Application* obj, logic_EApplicationStyle* arg1);
extern int logic_Application_get_networkPropStyle(logic_Application* obj);
extern ent_Faction* logic_Application___net_mark_faction(logic_Application* obj, ent_Faction* arg1);
extern ent_Faction* logic_Application_set_faction(logic_Application* obj, ent_Faction* arg1);
extern int logic_Application_get_networkPropFaction(logic_Application* obj);
extern ent_Object* logic_Application___net_mark_instigator(logic_Application* obj, ent_Object* arg1);
extern ent_Object* logic_Application_set_instigator(logic_Application* obj, ent_Object* arg1);
extern int logic_Application_get_networkPropInstigator(logic_Application* obj);
extern double logic_Application___net_mark_startTime(logic_Application* obj, double arg1);
extern double logic_Application_set_startTime(logic_Application* obj, double arg1);
extern int logic_Application_get_networkPropStartTime(logic_Application* obj);
extern hxbit_ArrayProxyData* logic_Application___net_mark_atbUIDs(logic_Application* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_Application_set_atbUIDs(logic_Application* obj, hxbit_ArrayProxyData* arg1);
extern int logic_Application_get_networkPropAtbUIDs(logic_Application* obj);
extern hl_types_ArrayObj* logic_Application___net_mark_appConditions(logic_Application* obj, hl_types_ArrayObj* arg1);
extern hl_types_ArrayObj* logic_Application_set_appConditions(logic_Application* obj, hl_types_ArrayObj* arg1);
extern int logic_Application_get_networkPropAppConditions(logic_Application* obj);
extern hl_types_ArrayObj* logic_Application___net_mark_blockingConditions(logic_Application* obj, hl_types_ArrayObj* arg1);
extern hl_types_ArrayObj* logic_Application_set_blockingConditions(logic_Application* obj, hl_types_ArrayObj* arg1);
extern int logic_Application_get_networkPropBlockingConditions(logic_Application* obj);
extern logic_ESourceKind* logic_Application___net_mark_src(logic_Application* obj, logic_ESourceKind* arg1);
extern logic_ESourceKind* logic_Application_set_src(logic_Application* obj, logic_ESourceKind* arg1);
extern int logic_Application_get_networkPropSrc(logic_Application* obj);
extern int logic_Application___net_mark_stackCount(logic_Application* obj, int arg1);
extern int logic_Application_set_stackCount(logic_Application* obj, int arg1);
extern int logic_Application_get_networkPropStackCount(logic_Application* obj);
extern void logic_Application_networkFlush(logic_Application* obj, hxbit_Serializer* arg1);
extern void logic_Application_networkSync(logic_Application* obj, hxbit_Serializer* arg1);
extern void logic_Application_networkInitProxys(logic_Application* obj);
extern String* logic_Application_networkGetName(logic_Application* obj, int arg1, void* arg2);
extern int logic_Application_getCLID(logic_Application* obj);
extern void logic_Application_serialize(logic_Application* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_Application_getSerializeSchema(logic_Application* obj);
extern void logic_Application_unserializeInit(logic_Application* obj);
extern void logic_Application_unserialize(logic_Application* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_Application_h__
