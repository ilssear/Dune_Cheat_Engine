// gen time: 2024-07-14 16:23:46 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_SpiceHarvester_h__
#define __gen_t_ent_SpiceHarvester_h__

#include <common.h>
#include <gen/t.ent.Unit.h>

typedef struct ent_SpiceHarvester ent_SpiceHarvester;
typedef struct hxbit_Serializer hxbit_Serializer;


// type: ent.SpiceHarvester, kind: HOBJ, pType: 0x01EC714D2158
struct ent_SpiceHarvester {
  // super: ent.Unit
  ent_Unit                  super;

  // cls: ent.SpiceHarvester, begin_offset: 0x04D1
  // total_size: 0x04D1
}; // ent_SpiceHarvester (ent.SpiceHarvester)

_Static_assert(sizeof(ent_SpiceHarvester) == 0x04D8, "cls ent.SpiceHarvester has wrong size");


extern int ent_SpiceHarvester_getCLID(ent_SpiceHarvester* obj);
extern void ent_SpiceHarvester_networkFlush(ent_SpiceHarvester* obj, hxbit_Serializer* arg1);
extern void ent_SpiceHarvester_networkSync(ent_SpiceHarvester* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_SpiceHarvester_h__
