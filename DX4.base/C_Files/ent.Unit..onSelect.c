
#include <common.h>
#include <gen/t.ent.Unit.h>

struct {
  ent_Unit*     _this;					// 0x00 
  ent_Faction*  _faction_ptr;			// 0x08
  String*       _faction_kind; 			// 0x10
  String*       _faction_get_leader;	// 0x18 
  String*       _faction_getIdStr; 		// 0x20
  String*       _unit_kind;				// 0x28
  double        _unit_speedFactor;		// 0x30
  int			_unit_maxLevel;			// 0x38
  bool          _faction_isAI;			// 0x3C
  bool          _canBeWormTarget;		// 0x3D
} ent_Unit_onSelect_dbg;

#define dbg ent_Unit_onSelect_dbg

// Functions to use:
// extern bool ent_Unit_canBeWormTarget(ent_Unit* obj, void* arg1);
// extern String* ent_Faction_get_leader(ent_Faction* obj);
// extern String* ent_Faction_getIdStr(ent_Faction* obj);

extern 
void ent_Unit_onSelect_org(ent_Unit* obj, void* arg1);

void ent_Unit_onSelect_new(ent_Unit* obj, void* arg1) {
  dbg._this = obj;
  ent_Faction* fac = ent_Entity_get_owner(obj);
  dbg._faction_ptr = fac;

  if (fac) {
    dbg._faction_kind = fac->kind;
    dbg._faction_get_leader = ent_Faction_get_leader(fac);
    dbg._faction_getIdStr = ent_Faction_getIdStr(fac);
    dbg._faction_isAI = fac->isAI;
  }
  
  dbg._canBeWormTarget = ent_Unit_canBeWormTarget(obj, arg1);
  dbg._unit_kind = obj->kind;
  dbg._unit_speedFactor = obj->speedFactor;
  dbg._unit_maxLevel = obj->maxLevel;
  ent_Unit_onSelect_org(obj, arg1);
}

