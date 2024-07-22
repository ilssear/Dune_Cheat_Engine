// gen time: 2024-07-21 07:31:36 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_ent_SpacingGuildBranch_h__
#define __gen_t_ent_SpacingGuildBranch_h__

#include <common.h>
#include <gen/t.ent.Building.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct ent_SpacingGuildBranch ent_SpacingGuildBranch;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;


// type: ent.SpacingGuildBranch, kind: HOBJ, pType: 0x02A76E31F298
struct ent_SpacingGuildBranch {
  // super: ent.Building
  ent_Building              super;

  // cls: ent.SpacingGuildBranch, begin_offset: 0x03C8
  String*                   giftRes;            // +03C8: HOBJ String
  String*                   requestRes;         // +03D0: HOBJ String
  // total_size: 0x03D8
}; // ent_SpacingGuildBranch (ent.SpacingGuildBranch)

_Static_assert(sizeof(ent_SpacingGuildBranch) == 0x03D8, "cls ent.SpacingGuildBranch has wrong size");


extern void ent_SpacingGuildBranch_init(ent_SpacingGuildBranch* obj);
extern void ent_SpacingGuildBranch_regularUpdate(ent_SpacingGuildBranch* obj, double arg1);
extern double ent_SpacingGuildBranch_getTradingFavor(ent_SpacingGuildBranch* obj);
extern double ent_SpacingGuildBranch_getTradingUpkeep(ent_SpacingGuildBranch* obj, String* arg1);
extern double ent_SpacingGuildBranch_getTradingRate(ent_SpacingGuildBranch* obj, String* arg1, bool arg2);
extern double ent_SpacingGuildBranch_getTradingProd(ent_SpacingGuildBranch* obj, String* arg1);
extern EReason* ent_SpacingGuildBranch_implSetGift(ent_SpacingGuildBranch* obj, String* arg1);
extern EReason* ent_SpacingGuildBranch_implSetRequest(ent_SpacingGuildBranch* obj, String* arg1);
extern bool ent_SpacingGuildBranch_checkWorkingConditions(ent_SpacingGuildBranch* obj);
extern void ent_SpacingGuildBranch_clearTrades(ent_SpacingGuildBranch* obj);
extern void ent_SpacingGuildBranch_rpcChangeOwner__impl(ent_SpacingGuildBranch* obj, ent_Faction* arg1, ent_Faction* arg2);
extern void ent_SpacingGuildBranch_doRemove(ent_SpacingGuildBranch* obj);
extern int ent_SpacingGuildBranch_getCLID(ent_SpacingGuildBranch* obj);
extern void ent_SpacingGuildBranch_serialize(ent_SpacingGuildBranch* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_SpacingGuildBranch_getSerializeSchema(ent_SpacingGuildBranch* obj);
extern void ent_SpacingGuildBranch_unserialize(ent_SpacingGuildBranch* obj, hxbit_Serializer* arg1);
extern EReason* ent_SpacingGuildBranch_setGift(ent_SpacingGuildBranch* obj, String* arg1, void* arg2);
extern bool ent_SpacingGuildBranch_rpcSetGift__impl(ent_SpacingGuildBranch* obj, String* arg1);
extern EReason* ent_SpacingGuildBranch_checkSetGift(ent_SpacingGuildBranch* obj, String* arg1);
extern bool ent_SpacingGuildBranch_canSetGift(ent_SpacingGuildBranch* obj, String* arg1);
extern EReason* ent_SpacingGuildBranch_setRequest(ent_SpacingGuildBranch* obj, String* arg1, void* arg2);
extern bool ent_SpacingGuildBranch_rpcSetRequest__impl(ent_SpacingGuildBranch* obj, String* arg1);
extern EReason* ent_SpacingGuildBranch_checkSetRequest(ent_SpacingGuildBranch* obj, String* arg1);
extern bool ent_SpacingGuildBranch_canSetRequest(ent_SpacingGuildBranch* obj, String* arg1);
extern String* ent_SpacingGuildBranch___net_mark_giftRes(ent_SpacingGuildBranch* obj, String* arg1);
extern String* ent_SpacingGuildBranch_set_giftRes(ent_SpacingGuildBranch* obj, String* arg1);
extern int ent_SpacingGuildBranch_get_networkPropGiftRes(ent_SpacingGuildBranch* obj);
extern String* ent_SpacingGuildBranch___net_mark_requestRes(ent_SpacingGuildBranch* obj, String* arg1);
extern String* ent_SpacingGuildBranch_set_requestRes(ent_SpacingGuildBranch* obj, String* arg1);
extern int ent_SpacingGuildBranch_get_networkPropRequestRes(ent_SpacingGuildBranch* obj);
extern void ent_SpacingGuildBranch_rpcSetGift(ent_SpacingGuildBranch* obj, String* arg1, void* arg2);
extern void ent_SpacingGuildBranch_rpcSetRequest(ent_SpacingGuildBranch* obj, String* arg1, void* arg2);
extern void ent_SpacingGuildBranch_networkFlush(ent_SpacingGuildBranch* obj, hxbit_Serializer* arg1);
extern void ent_SpacingGuildBranch_networkSync(ent_SpacingGuildBranch* obj, hxbit_Serializer* arg1);
extern bool ent_SpacingGuildBranch_networkRPC(ent_SpacingGuildBranch* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_SpacingGuildBranch_networkGetName(ent_SpacingGuildBranch* obj, int arg1, void* arg2);


#endif // __gen_t_ent_SpacingGuildBranch_h__
