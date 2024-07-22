// gen time: 2024-07-21 07:31:36 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_ent_Team_h__
#define __gen_t_ent_Team_h__

#include <common.h>
#include <gen/t.ent.Object.h>

typedef struct EScope EScope;
typedef struct String String;
typedef struct ent_Player ent_Player;
typedef struct ent_Team ent_Team;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_AttributeApplication logic_AttributeApplication;


// type: ent.Team, kind: HOBJ, pType: 0x02A76E333F98
struct ent_Team {
  // super: ent.Object
  ent_Object                super;

  // cls: ent.Team, begin_offset: 0x00E0
  int                       teamId;             // +00E0
  hl_types_ArrayObj*        players;            // +00E8: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        playersAlive;       // +00F0: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        playersDead;        // +00F8: HOBJ hl.types.ArrayObj
  // total_size: 0x0100
}; // ent_Team (ent.Team)

_Static_assert(sizeof(ent_Team) == 0x0100, "cls ent.Team has wrong size");


extern void ent_Team_init(ent_Team* obj);
extern void ent_Team_addPlayer(ent_Team* obj, ent_Player* arg1);
extern void ent_Team_removePlayer(ent_Team* obj, ent_Player* arg1);
extern bool ent_Team_isAlive(ent_Team* obj, void* arg1);
extern hl_types_ArrayObj* ent_Team_getPlayersAlive(ent_Team* obj);
extern hl_types_ArrayObj* ent_Team_getDeadPlayers(ent_Team* obj);
extern void ent_Team_propagateClearAtbCache(ent_Team* obj, int arg1, EScope* arg2, void* arg3, logic_AttributeApplication* arg4);
extern int ent_Team___net_mark_teamId(ent_Team* obj, int arg1);
extern int ent_Team_set_teamId(ent_Team* obj, int arg1);
extern int ent_Team_get_networkPropTeamId(ent_Team* obj);
extern void ent_Team_networkFlush(ent_Team* obj, hxbit_Serializer* arg1);
extern void ent_Team_networkSync(ent_Team* obj, hxbit_Serializer* arg1);
extern String* ent_Team_networkGetName(ent_Team* obj, int arg1, void* arg2);
extern int ent_Team_getCLID(ent_Team* obj);
extern void ent_Team_serialize(ent_Team* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Team_getSerializeSchema(ent_Team* obj);
extern void ent_Team_unserializeInit(ent_Team* obj);
extern void ent_Team_unserialize(ent_Team* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_Team_h__
