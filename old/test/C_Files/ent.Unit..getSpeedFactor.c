#include <common.h>
#include <gen/t.ent.Unit.h>

// Changed function extern double ent_Unit_getSpeedFactor(ent_Unit* obj);

struct {
  ent_Unit*     _this;
  double        _retVal;
  ent_Faction*  _player;
  ent_Faction*  _ai;
} ent_Unit_getSpeedModifier_dbg;

#define dbg ent_Unit_getSpeedModifier_dbg

extern
double ent_Unit_getSpeedFactor_org(ent_Unit* obj);
double ent_Unit_getSpeedFactor_new(ent_Unit* obj) {

  dbg._this = obj;

  ent_Faction* fac = ent_Entity_get_owner(obj);
  bool isPlayer = fac && !(fac->isAI);

  double r = ent_Unit_getSpeedFactor_org(obj);
  // Multiplier
  double m = 1.0; // Keep Harvesters an AI units the same

  if (isPlayer) {
    bool isOrni = ent_Unit_isOrni(obj);
    bool isHarvester = ent_Unit_isHarvester(obj);

    if (isOrni)
      m = 5.0;
    else if (!isHarvester)
      m = 10.0;

    dbg._player = fac;
    dbg._retVal = r;
  } else if (fac) { // is AI
		dbg._ai = fac;
  }

  return m * r;
}

