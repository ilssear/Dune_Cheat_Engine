#include <common.h>
#include <gen/t.ent.Unit.h>

struct {
  ent_Unit*     _this;
  ent_Faction*  _player;
  ent_Faction*  _ai;
  double		_arg1;
  double		_retVal;
  double		_BaseMaxLife;
  double		_MaxLifeAdd;
} ent_Unit_updateLife_dbg;

#define dbg ent_Unit_updateLife_dbg

// Other functions to use:
// extern double ent_Unit_getBaseMaxLife(ent_Unit* obj);
// extern double ent_Unit_getMaxLifeAdditiveModifier(ent_Unit* obj);

extern
void ent_Unit_updateLife_org(ent_Unit* obj, double arg1);
void ent_Unit_updateLife_new(ent_Unit* obj, double arg1) {
  dbg._this = obj; // this Unit
  ent_Faction* fac = ent_Entity_get_owner(obj); // get unit faction
  bool isPlayer = fac && !(fac->isAI);

  double r = arg1; // get expected value

  if (isPlayer) {
    dbg._player = fac;
    dbg._retVal = r;
    dbg._BaseMaxLife = ent_Unit_getBaseMaxLife(obj);
    dbg._MaxLifeAdd = ent_Unit_getMaxLifeAdditiveModifier(obj);
	r = dbg._BaseMaxLife;
  } else if (fac) {
		dbg._ai = fac;
  }
  ent_Unit_updateLife_org(obj, r);
}

/*
extern 
bool ent_Unit_canSafeRegen_old(ent_Unit* obj);
bool ent_Unit_canSafeRegen_new(ent_Unit* obj) {
  dbg._this = obj; // this Unit
  ent_Faction* fac = ent_Entity_get_owner(obj); // get unit faction
  bool isPlayer = fac && !(fac->isAI);

  if (isPlayer) {
    return true;
  } else if (fac) {
		return ent_Unit_canSafeRegen_old(obj);
  }
  
}
*/