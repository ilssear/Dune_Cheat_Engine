// gen time: 2024-07-21 07:25:07 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_TutorialManager_h__
#define __gen_t_logic_faction_TutorialManager_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct String String;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_Tutorial logic_faction_Tutorial;
typedef struct logic_faction_TutorialManager logic_faction_TutorialManager;
typedef struct logic_faction_TutorialType logic_faction_TutorialType;
typedef struct ui_comp_BaseElement ui_comp_BaseElement;


// type: logic.faction.TutorialManager, kind: HOBJ, pType: 0x02A76E31F4D8
struct logic_faction_TutorialManager {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.TutorialManager, begin_offset: 0x00B0
  hxbit_ArrayProxyData*     activeTutorials;    // +00B0: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     completedTutorials; // +00B8: HOBJ hxbit.ArrayProxyData
  hl_types_ArrayObj*        tutorialEndCallbacks; // +00C0: HOBJ hl.types.ArrayObj
  // total_size: 0x00C8
}; // logic_faction_TutorialManager (logic.faction.TutorialManager)

_Static_assert(sizeof(logic_faction_TutorialManager) == 0x00C8, "cls logic.faction.TutorialManager has wrong size");


extern void logic_faction_TutorialManager_init(logic_faction_TutorialManager* obj);
extern bool logic_faction_TutorialManager_canTriggerTuto(logic_faction_TutorialManager* obj, String* arg1);
extern void logic_faction_TutorialManager_dismissTutorial(logic_faction_TutorialManager* obj, String* arg1);
extern bool logic_faction_TutorialManager_isDismissed(logic_faction_TutorialManager* obj, String* arg1);
extern void logic_faction_TutorialManager_skipTutorial(logic_faction_TutorialManager* obj, String* arg1);
extern void logic_faction_TutorialManager_skipAll(logic_faction_TutorialManager* obj);
extern logic_faction_Tutorial* logic_faction_TutorialManager_triggerTutorial(logic_faction_TutorialManager* obj, String* arg1, ui_comp_BaseElement* arg2, void* arg3, logic_faction_TutorialType* arg4);
extern void logic_faction_TutorialManager_regularUpdate(logic_faction_TutorialManager* obj, double arg1);
extern void logic_faction_TutorialManager_checkTutoTriggers(logic_faction_TutorialManager* obj);
extern hxbit_ArrayProxyData* logic_faction_TutorialManager___net_mark_activeTutorials(logic_faction_TutorialManager* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_TutorialManager_set_activeTutorials(logic_faction_TutorialManager* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_TutorialManager_get_networkPropActiveTutorials(logic_faction_TutorialManager* obj);
extern hxbit_ArrayProxyData* logic_faction_TutorialManager___net_mark_completedTutorials(logic_faction_TutorialManager* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_TutorialManager_set_completedTutorials(logic_faction_TutorialManager* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_TutorialManager_get_networkPropCompletedTutorials(logic_faction_TutorialManager* obj);
extern void logic_faction_TutorialManager_networkFlush(logic_faction_TutorialManager* obj, hxbit_Serializer* arg1);
extern void logic_faction_TutorialManager_networkSync(logic_faction_TutorialManager* obj, hxbit_Serializer* arg1);
extern void logic_faction_TutorialManager_networkInitProxys(logic_faction_TutorialManager* obj);
extern String* logic_faction_TutorialManager_networkGetName(logic_faction_TutorialManager* obj, int arg1, void* arg2);
extern int logic_faction_TutorialManager_getCLID(logic_faction_TutorialManager* obj);
extern void logic_faction_TutorialManager_serialize(logic_faction_TutorialManager* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_TutorialManager_getSerializeSchema(logic_faction_TutorialManager* obj);
extern void logic_faction_TutorialManager_unserializeInit(logic_faction_TutorialManager* obj);
extern void logic_faction_TutorialManager_unserialize(logic_faction_TutorialManager* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_TutorialManager_h__
