// gen time: 2024-07-14 16:17:07 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_comp_HarvestComponent_h__
#define __gen_t_ent_comp_HarvestComponent_h__

#include <common.h>
#include <gen/t.ent.comp.EntityComponent.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_Entity ent_Entity;
typedef struct ent_SpiceField ent_SpiceField;
typedef struct ent_Structure ent_Structure;
typedef struct ent_comp_HarvestComponent ent_comp_HarvestComponent;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;


// type: ent.comp.HarvestComponent, kind: HOBJ, pType: 0x01EC714D1F78
struct ent_comp_HarvestComponent {
  // super: ent.comp.EntityComponent
  ent_comp_EntityComponent  super;

  // cls: ent.comp.HarvestComponent, begin_offset: 0x0050
  ent_SpiceField*           currentField;       // +0050: HOBJ ent.SpiceField
  int                       crewPoints;         // +0058
  double                    accDmg;             // +0060
  ent_Structure*            spiceArea;          // +0068: HOBJ ent.Structure
  bool                      wasProducing;       // +0070
  // total_size: 0x0071
}; // ent_comp_HarvestComponent (ent.comp.HarvestComponent)

_Static_assert(sizeof(ent_comp_HarvestComponent) == 0x0078, "cls ent.comp.HarvestComponent has wrong size");


extern ent_Structure* ent_comp_HarvestComponent_get_structure(ent_comp_HarvestComponent* obj);
extern bool ent_comp_HarvestComponent_get_isOvercharge(ent_comp_HarvestComponent* obj);
extern void ent_comp_HarvestComponent_patchEntity(ent_comp_HarvestComponent* obj, int arg1);
extern int ent_comp_HarvestComponent_getMaxCrewPoints(ent_comp_HarvestComponent* obj);
extern EReason* ent_comp_HarvestComponent_implAddCrewPoints(ent_comp_HarvestComponent* obj, void* arg1);
extern bool ent_comp_HarvestComponent_hasMaxCrew(ent_comp_HarvestComponent* obj);
extern void ent_comp_HarvestComponent_updateCrewPoints(ent_comp_HarvestComponent* obj, double arg1);
extern void ent_comp_HarvestComponent_onReceiveDamage(ent_comp_HarvestComponent* obj, ent_Entity* arg1, double arg2);
extern bool ent_comp_HarvestComponent_shouldShowCrewPoints(ent_comp_HarvestComponent* obj);
extern void ent_comp_HarvestComponent_assignSpiceArea(ent_comp_HarvestComponent* obj, ent_Structure* arg1);
extern ent_SpiceField* ent_comp_HarvestComponent_pickSpiceField(ent_comp_HarvestComponent* obj);
extern bool ent_comp_HarvestComponent_isProducing(ent_comp_HarvestComponent* obj);
extern void ent_comp_HarvestComponent_update(ent_comp_HarvestComponent* obj, double arg1);
extern void ent_comp_HarvestComponent_regularUpdate(ent_comp_HarvestComponent* obj, double arg1);
extern bool ent_comp_HarvestComponent_isStandalone(ent_comp_HarvestComponent* obj);
extern double ent_comp_HarvestComponent_getStandaloneProduction(ent_comp_HarvestComponent* obj);
extern double ent_comp_HarvestComponent_getSpiceProduction(ent_comp_HarvestComponent* obj);
extern int ent_comp_HarvestComponent_getCLID(ent_comp_HarvestComponent* obj);
extern void ent_comp_HarvestComponent_serialize(ent_comp_HarvestComponent* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_comp_HarvestComponent_getSerializeSchema(ent_comp_HarvestComponent* obj);
extern void ent_comp_HarvestComponent_unserializeInit(ent_comp_HarvestComponent* obj);
extern void ent_comp_HarvestComponent_unserialize(ent_comp_HarvestComponent* obj, hxbit_Serializer* arg1);
extern EReason* ent_comp_HarvestComponent_addCrewPoints(ent_comp_HarvestComponent* obj, void* arg1, void* arg2);
extern bool ent_comp_HarvestComponent_rpcAddCrewPoints__impl(ent_comp_HarvestComponent* obj, void* arg1);
extern EReason* ent_comp_HarvestComponent_checkAddCrewPoints(ent_comp_HarvestComponent* obj, void* arg1);
extern bool ent_comp_HarvestComponent_canAddCrewPoints(ent_comp_HarvestComponent* obj, void* arg1);
extern ent_SpiceField* ent_comp_HarvestComponent___net_mark_currentField(ent_comp_HarvestComponent* obj, ent_SpiceField* arg1);
extern ent_SpiceField* ent_comp_HarvestComponent_set_currentField(ent_comp_HarvestComponent* obj, ent_SpiceField* arg1);
extern int ent_comp_HarvestComponent_get_networkPropCurrentField(ent_comp_HarvestComponent* obj);
extern int ent_comp_HarvestComponent___net_mark_crewPoints(ent_comp_HarvestComponent* obj, int arg1);
extern int ent_comp_HarvestComponent_set_crewPoints(ent_comp_HarvestComponent* obj, int arg1);
extern int ent_comp_HarvestComponent_get_networkPropCrewPoints(ent_comp_HarvestComponent* obj);
extern double ent_comp_HarvestComponent___net_mark_accDmg(ent_comp_HarvestComponent* obj, double arg1);
extern double ent_comp_HarvestComponent_set_accDmg(ent_comp_HarvestComponent* obj, double arg1);
extern int ent_comp_HarvestComponent_get_networkPropAccDmg(ent_comp_HarvestComponent* obj);
extern ent_Structure* ent_comp_HarvestComponent___net_mark_spiceArea(ent_comp_HarvestComponent* obj, ent_Structure* arg1);
extern ent_Structure* ent_comp_HarvestComponent_set_spiceArea(ent_comp_HarvestComponent* obj, ent_Structure* arg1);
extern int ent_comp_HarvestComponent_get_networkPropSpiceArea(ent_comp_HarvestComponent* obj);
extern void ent_comp_HarvestComponent_rpcAddCrewPoints(ent_comp_HarvestComponent* obj, void* arg1, void* arg2);
extern void ent_comp_HarvestComponent_networkFlush(ent_comp_HarvestComponent* obj, hxbit_Serializer* arg1);
extern void ent_comp_HarvestComponent_networkSync(ent_comp_HarvestComponent* obj, hxbit_Serializer* arg1);
extern bool ent_comp_HarvestComponent_networkRPC(ent_comp_HarvestComponent* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_comp_HarvestComponent_networkGetName(ent_comp_HarvestComponent* obj, int arg1, void* arg2);


#endif // __gen_t_ent_comp_HarvestComponent_h__
