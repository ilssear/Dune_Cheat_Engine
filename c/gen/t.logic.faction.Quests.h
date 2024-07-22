// gen time: 2024-07-21 07:23:49 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_Quests_h__
#define __gen_t_logic_faction_Quests_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct String String;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_Quest logic_faction_Quest;
typedef struct logic_faction_Quests logic_faction_Quests;


// type: logic.faction.Quests, kind: HOBJ, pType: 0x02A76E3207B8
struct logic_faction_Quests {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.Quests, begin_offset: 0x00B0
  double                    nextQuestAppearThreshold; // +00B0
  double                    nextQuestAppearScore; // +00B8
  double                    nextContrabandAppearThreshold; // +00C0
  double                    nextContrabandAppearScore; // +00C8
  double                    nextLandsraadAppearThreshold; // +00D0
  double                    nextLandsraadAppearScore; // +00D8
  double                    nextAssassinationAppearThreshold; // +00E0
  double                    nextAssassinationAppearScore; // +00E8
  hxbit_ArrayProxyData*     currentQuests;      // +00F0: HOBJ hxbit.ArrayProxyData
  hxbit_MapData*            completionsCount;   // +00F8: HOBJ hxbit.MapData
  hxbit_MapData*            lastQuestAppearTime; // +0100: HOBJ hxbit.MapData
  double                    contrabandQuestLastSpawn; // +0108
  int                       questCyclesPassed;  // +0110
  int                       questCycleDuration; // +0114
  int                       contrabandQuestCycleDuration; // +0118
  // total_size: 0x011C
}; // logic_faction_Quests (logic.faction.Quests)

_Static_assert(sizeof(logic_faction_Quests) == 0x0120, "cls logic.faction.Quests has wrong size");


extern hxbit_ArrayProxyData* logic_faction_Quests_set_currentQuests(logic_faction_Quests* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Quests_get_questCyclesPassed(logic_faction_Quests* obj);
extern int logic_faction_Quests_get_questCycleDuration(logic_faction_Quests* obj);
extern int logic_faction_Quests_get_contrabandQuestCycleDuration(logic_faction_Quests* obj);
extern void logic_faction_Quests_init(logic_faction_Quests* obj);
extern void logic_faction_Quests_dailyUpdate(logic_faction_Quests* obj);
extern void logic_faction_Quests_regularUpdate(logic_faction_Quests* obj, double arg1);
extern bool logic_faction_Quests_isNewQuestDay(logic_faction_Quests* obj, int arg1);
extern void logic_faction_Quests_checkNewBasicQuests(logic_faction_Quests* obj);
extern void logic_faction_Quests_unlockContrabandQuests(logic_faction_Quests* obj);
extern void logic_faction_Quests_checkNewContrabandQuests(logic_faction_Quests* obj);
extern void logic_faction_Quests_requestNextBasicQuest(logic_faction_Quests* obj);
extern void logic_faction_Quests_requestNextContrabandQuest(logic_faction_Quests* obj);
extern bool logic_faction_Quests_tryStartQuest(logic_faction_Quests* obj, String* arg1);
extern void logic_faction_Quests_startQuest(logic_faction_Quests* obj, String* arg1);
extern bool logic_faction_Quests_hasQuest(logic_faction_Quests* obj, String* arg1);
extern void logic_faction_Quests_completeQuest(logic_faction_Quests* obj, logic_faction_Quest* arg1);
extern void logic_faction_Quests_endQuest(logic_faction_Quests* obj, logic_faction_Quest* arg1);
extern int logic_faction_Quests_getCycleDurationForQuest(logic_faction_Quests* obj, void* arg1);
extern hl_types_ArrayObj* logic_faction_Quests_getAvailableQuestsOfType(logic_faction_Quests* obj, int arg1);
extern bool logic_faction_Quests_isQuestValid(logic_faction_Quests* obj, void* arg1);
extern double logic_faction_Quests___net_mark_nextQuestAppearThreshold(logic_faction_Quests* obj, double arg1);
extern double logic_faction_Quests_set_nextQuestAppearThreshold(logic_faction_Quests* obj, double arg1);
extern int logic_faction_Quests_get_networkPropNextQuestAppearThreshold(logic_faction_Quests* obj);
extern double logic_faction_Quests___net_mark_nextQuestAppearScore(logic_faction_Quests* obj, double arg1);
extern double logic_faction_Quests_set_nextQuestAppearScore(logic_faction_Quests* obj, double arg1);
extern int logic_faction_Quests_get_networkPropNextQuestAppearScore(logic_faction_Quests* obj);
extern double logic_faction_Quests___net_mark_nextContrabandAppearThreshold(logic_faction_Quests* obj, double arg1);
extern double logic_faction_Quests_set_nextContrabandAppearThreshold(logic_faction_Quests* obj, double arg1);
extern int logic_faction_Quests_get_networkPropNextContrabandAppearThreshold(logic_faction_Quests* obj);
extern double logic_faction_Quests___net_mark_nextContrabandAppearScore(logic_faction_Quests* obj, double arg1);
extern double logic_faction_Quests_set_nextContrabandAppearScore(logic_faction_Quests* obj, double arg1);
extern int logic_faction_Quests_get_networkPropNextContrabandAppearScore(logic_faction_Quests* obj);
extern double logic_faction_Quests___net_mark_nextLandsraadAppearThreshold(logic_faction_Quests* obj, double arg1);
extern double logic_faction_Quests_set_nextLandsraadAppearThreshold(logic_faction_Quests* obj, double arg1);
extern int logic_faction_Quests_get_networkPropNextLandsraadAppearThreshold(logic_faction_Quests* obj);
extern double logic_faction_Quests___net_mark_nextLandsraadAppearScore(logic_faction_Quests* obj, double arg1);
extern double logic_faction_Quests_set_nextLandsraadAppearScore(logic_faction_Quests* obj, double arg1);
extern int logic_faction_Quests_get_networkPropNextLandsraadAppearScore(logic_faction_Quests* obj);
extern double logic_faction_Quests___net_mark_nextAssassinationAppearThreshold(logic_faction_Quests* obj, double arg1);
extern double logic_faction_Quests_set_nextAssassinationAppearThreshold(logic_faction_Quests* obj, double arg1);
extern int logic_faction_Quests_get_networkPropNextAssassinationAppearThreshold(logic_faction_Quests* obj);
extern double logic_faction_Quests___net_mark_nextAssassinationAppearScore(logic_faction_Quests* obj, double arg1);
extern double logic_faction_Quests_set_nextAssassinationAppearScore(logic_faction_Quests* obj, double arg1);
extern int logic_faction_Quests_get_networkPropNextAssassinationAppearScore(logic_faction_Quests* obj);
extern hxbit_ArrayProxyData* logic_faction_Quests___net_mark_currentQuests(logic_faction_Quests* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Quests_get_networkPropCurrentQuests(logic_faction_Quests* obj);
extern hxbit_MapData* logic_faction_Quests___net_mark_completionsCount(logic_faction_Quests* obj, hxbit_MapData* arg1);
extern hxbit_MapData* logic_faction_Quests_set_completionsCount(logic_faction_Quests* obj, hxbit_MapData* arg1);
extern int logic_faction_Quests_get_networkPropCompletionsCount(logic_faction_Quests* obj);
extern hxbit_MapData* logic_faction_Quests___net_mark_lastQuestAppearTime(logic_faction_Quests* obj, hxbit_MapData* arg1);
extern hxbit_MapData* logic_faction_Quests_set_lastQuestAppearTime(logic_faction_Quests* obj, hxbit_MapData* arg1);
extern int logic_faction_Quests_get_networkPropLastQuestAppearTime(logic_faction_Quests* obj);
extern double logic_faction_Quests___net_mark_contrabandQuestLastSpawn(logic_faction_Quests* obj, double arg1);
extern double logic_faction_Quests_set_contrabandQuestLastSpawn(logic_faction_Quests* obj, double arg1);
extern int logic_faction_Quests_get_networkPropContrabandQuestLastSpawn(logic_faction_Quests* obj);
extern void logic_faction_Quests_networkFlush(logic_faction_Quests* obj, hxbit_Serializer* arg1);
extern void logic_faction_Quests_networkSync(logic_faction_Quests* obj, hxbit_Serializer* arg1);
extern void logic_faction_Quests_networkInitProxys(logic_faction_Quests* obj);
extern String* logic_faction_Quests_networkGetName(logic_faction_Quests* obj, int arg1, void* arg2);
extern int logic_faction_Quests_getCLID(logic_faction_Quests* obj);
extern void logic_faction_Quests_serialize(logic_faction_Quests* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_Quests_getSerializeSchema(logic_faction_Quests* obj);
extern void logic_faction_Quests_unserialize(logic_faction_Quests* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_Quests_h__
