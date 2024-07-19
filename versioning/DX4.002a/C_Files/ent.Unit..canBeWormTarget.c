
#include <common.h>
#include <gen/t.ent.Unit.h>

struct {
  ent_Unit*     _this;
  ent_Faction*  _player;
  ent_Faction*  _ai;
  bool			_retVal;
} ent_Unit_canBeWormTarget_dbg;

#define dbg ent_Unit_canBeWormTarget_dbg

extern
bool ent_Unit_canBeWormTarget_org(ent_Unit* obj, void* arg1);
bool ent_Unit_canBeWormTarget_new(ent_Unit* obj, void* arg1) {
  dbg._this = obj;

  ent_Faction* fac = ent_Entity_get_owner(obj);
  bool isPlayer = fac && !(fac->isAI);
  bool r = ent_Unit_canBeWormTarget_org(obj, arg1);
  
  if (isPlayer) {
    dbg._player = fac;
    dbg._retVal = r;
	r = false;
  } else if (fac) { // is AI
		dbg._ai = fac;
  }
  return r;
}

