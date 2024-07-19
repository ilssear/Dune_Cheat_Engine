// gen time: 2024-07-14 08:48:21 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_ent_HegemonyData_h__
#define __gen_t_ent_HegemonyData_h__

#include <common.h>
#include <gen/t.logic.Logic.h>

typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct ent_HegemonyData ent_HegemonyData;
typedef struct hl_types_ArrayBytes_Float hl_types_ArrayBytes_Float;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;


// type: ent.HegemonyData, kind: HOBJ, pType: 0x02748E3FEC18
struct ent_HegemonyData {
  // super: logic.Logic
  logic_Logic               super;

  // cls: ent.HegemonyData, begin_offset: 0x0090
  hxbit_MapData*            stocks;             // +0090: HOBJ hxbit.MapData
  ent_Faction*              faction;            // +0098: HOBJ ent.Faction
  double                    highest;            // +00A0
  // total_size: 0x00A8
}; // ent_HegemonyData (ent.HegemonyData)

_Static_assert(sizeof(ent_HegemonyData) == 0x00A8, "cls ent.HegemonyData has wrong size");


extern void ent_HegemonyData_patchEntity(ent_HegemonyData* obj, int arg1);
extern bool ent_HegemonyData_shouldAlwaysShow(ent_HegemonyData* obj, void* arg1);
extern void ent_HegemonyData_refreshAlwaysShow(ent_HegemonyData* obj);
extern void ent_HegemonyData_init(ent_HegemonyData* obj);
extern void ent_HegemonyData_add(ent_HegemonyData* obj, String* arg1);
extern double ent_HegemonyData_getValue(ent_HegemonyData* obj, String* arg1, void* arg2);
extern double ent_HegemonyData_getValueByIndex(ent_HegemonyData* obj, String* arg1, void* arg2);
extern double ent_HegemonyData_getModifiedValue(ent_HegemonyData* obj, String* arg1, double arg2);
extern hl_types_ArrayObj* ent_HegemonyData_getValuesDetails(ent_HegemonyData* obj);
extern void ent_HegemonyData_resetProd(ent_HegemonyData* obj);
extern void ent_HegemonyData_setProd(ent_HegemonyData* obj, String* arg1, double arg2, void* arg3);
extern void ent_HegemonyData_calcTotal(ent_HegemonyData* obj);
extern double ent_HegemonyData_getTotal(ent_HegemonyData* obj);
extern void ent_HegemonyData_addValue(ent_HegemonyData* obj, String* arg1, double arg2, void* arg3);
extern void* ent_HegemonyData_getBaseValue(ent_HegemonyData* obj, String* arg1);
extern hl_types_ArrayBytes_Float* ent_HegemonyData_getBaseValues(ent_HegemonyData* obj, String* arg1);
extern hl_types_ArrayBytes_Float* ent_HegemonyData_getThresholdValues(ent_HegemonyData* obj, String* arg1);
extern void ent_HegemonyData_updateHighest(ent_HegemonyData* obj);
extern void ent_HegemonyData_regularUpdate(ent_HegemonyData* obj, double arg1);
extern int ent_HegemonyData_getCLID(ent_HegemonyData* obj);
extern void ent_HegemonyData_serialize(ent_HegemonyData* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_HegemonyData_getSerializeSchema(ent_HegemonyData* obj);
extern void ent_HegemonyData_unserializeInit(ent_HegemonyData* obj);
extern void ent_HegemonyData_unserialize(ent_HegemonyData* obj, hxbit_Serializer* arg1);
extern hxbit_MapData* ent_HegemonyData___net_mark_stocks(ent_HegemonyData* obj, hxbit_MapData* arg1);
extern hxbit_MapData* ent_HegemonyData_set_stocks(ent_HegemonyData* obj, hxbit_MapData* arg1);
extern int ent_HegemonyData_get_networkPropStocks(ent_HegemonyData* obj);
extern ent_Faction* ent_HegemonyData___net_mark_faction(ent_HegemonyData* obj, ent_Faction* arg1);
extern ent_Faction* ent_HegemonyData_set_faction(ent_HegemonyData* obj, ent_Faction* arg1);
extern int ent_HegemonyData_get_networkPropFaction(ent_HegemonyData* obj);
extern double ent_HegemonyData___net_mark_highest(ent_HegemonyData* obj, double arg1);
extern double ent_HegemonyData_set_highest(ent_HegemonyData* obj, double arg1);
extern int ent_HegemonyData_get_networkPropHighest(ent_HegemonyData* obj);
extern void ent_HegemonyData_networkFlush(ent_HegemonyData* obj, hxbit_Serializer* arg1);
extern void ent_HegemonyData_networkSync(ent_HegemonyData* obj, hxbit_Serializer* arg1);
extern void ent_HegemonyData_networkInitProxys(ent_HegemonyData* obj);
extern String* ent_HegemonyData_networkGetName(ent_HegemonyData* obj, int arg1, void* arg2);


#endif // __gen_t_ent_HegemonyData_h__
