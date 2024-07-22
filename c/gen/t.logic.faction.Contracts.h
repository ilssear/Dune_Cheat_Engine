// gen time: 2024-07-21 07:22:47 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_Contracts_h__
#define __gen_t_logic_faction_Contracts_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_Contract logic_faction_Contract;
typedef struct logic_faction_Contracts logic_faction_Contracts;


// type: logic.faction.Contracts, kind: HOBJ, pType: 0x02A76E336978
struct logic_faction_Contracts {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.Contracts, begin_offset: 0x00B0
  logic_faction_Contract*   contract;           // +00B0: HOBJ logic.faction.Contract
  hxbit_ArrayProxyData*     nextImperialTaxFactors; // +00B8: HOBJ hxbit.ArrayProxyData
  int                       passedContracts;    // +00C0
  double                    tradeRatio;         // +00C8
  // total_size: 0x00D0
}; // logic_faction_Contracts (logic.faction.Contracts)

_Static_assert(sizeof(logic_faction_Contracts) == 0x00D0, "cls logic.faction.Contracts has wrong size");


extern double logic_faction_Contracts_set_tradeRatio(logic_faction_Contracts* obj, double arg1);
extern EReason* logic_faction_Contracts_implSetTradeRatio(logic_faction_Contracts* obj, double arg1);
extern void logic_faction_Contracts_finalize(logic_faction_Contracts* obj);
extern void logic_faction_Contracts_regularUpdate(logic_faction_Contracts* obj, double arg1);
extern void logic_faction_Contracts_nextContract(logic_faction_Contracts* obj, void* arg1);
extern hl_types_ArrayObj* logic_faction_Contracts_getOutValueFlatModifiers(logic_faction_Contracts* obj);
extern hl_types_ArrayObj* logic_faction_Contracts_getOutValueAddFactors(logic_faction_Contracts* obj);
extern hl_types_ArrayObj* logic_faction_Contracts_getOutValueMultFactors(logic_faction_Contracts* obj);
extern double logic_faction_Contracts_getBaseOutValue(logic_faction_Contracts* obj);
extern double logic_faction_Contracts_getOutValue(logic_faction_Contracts* obj);
extern double logic_faction_Contracts_getNextContractDate(logic_faction_Contracts* obj);
extern double logic_faction_Contracts_getContractLength(logic_faction_Contracts* obj);
extern double logic_faction_Contracts_getTimeToNextContract(logic_faction_Contracts* obj);
extern double logic_faction_Contracts_getContractProgress(logic_faction_Contracts* obj);
extern bool logic_faction_Contracts_isOverflowing(logic_faction_Contracts* obj);
extern double logic_faction_Contracts_getEffectiveTradeRatio(logic_faction_Contracts* obj);
extern void* logic_faction_Contracts_getIncoming(logic_faction_Contracts* obj, int arg1);
extern void* logic_faction_Contracts_getOutcoming(logic_faction_Contracts* obj, int arg1);
extern int logic_faction_Contracts_getInResource(logic_faction_Contracts* obj);
extern int logic_faction_Contracts_getOutResource(logic_faction_Contracts* obj);
extern void logic_faction_Contracts_onOwnerDefeated(logic_faction_Contracts* obj);
extern EReason* logic_faction_Contracts_setTradeRatio(logic_faction_Contracts* obj, double arg1, void* arg2);
extern bool logic_faction_Contracts_rpcSetTradeRatio__impl(logic_faction_Contracts* obj, double arg1);
extern EReason* logic_faction_Contracts_checkSetTradeRatio(logic_faction_Contracts* obj, double arg1);
extern bool logic_faction_Contracts_canSetTradeRatio(logic_faction_Contracts* obj, double arg1);
extern logic_faction_Contract* logic_faction_Contracts___net_mark_contract(logic_faction_Contracts* obj, logic_faction_Contract* arg1);
extern logic_faction_Contract* logic_faction_Contracts_set_contract(logic_faction_Contracts* obj, logic_faction_Contract* arg1);
extern int logic_faction_Contracts_get_networkPropContract(logic_faction_Contracts* obj);
extern hxbit_ArrayProxyData* logic_faction_Contracts___net_mark_nextImperialTaxFactors(logic_faction_Contracts* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Contracts_set_nextImperialTaxFactors(logic_faction_Contracts* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Contracts_get_networkPropNextImperialTaxFactors(logic_faction_Contracts* obj);
extern int logic_faction_Contracts___net_mark_passedContracts(logic_faction_Contracts* obj, int arg1);
extern int logic_faction_Contracts_set_passedContracts(logic_faction_Contracts* obj, int arg1);
extern int logic_faction_Contracts_get_networkPropPassedContracts(logic_faction_Contracts* obj);
extern double logic_faction_Contracts___net_mark_tradeRatio(logic_faction_Contracts* obj, double arg1);
extern int logic_faction_Contracts_get_networkPropTradeRatio(logic_faction_Contracts* obj);
extern void logic_faction_Contracts_rpcSetTradeRatio(logic_faction_Contracts* obj, double arg1, void* arg2);
extern void logic_faction_Contracts_networkFlush(logic_faction_Contracts* obj, hxbit_Serializer* arg1);
extern void logic_faction_Contracts_networkSync(logic_faction_Contracts* obj, hxbit_Serializer* arg1);
extern void logic_faction_Contracts_networkInitProxys(logic_faction_Contracts* obj);
extern bool logic_faction_Contracts_networkRPC(logic_faction_Contracts* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* logic_faction_Contracts_networkGetName(logic_faction_Contracts* obj, int arg1, void* arg2);
extern int logic_faction_Contracts_getCLID(logic_faction_Contracts* obj);
extern void logic_faction_Contracts_serialize(logic_faction_Contracts* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_Contracts_getSerializeSchema(logic_faction_Contracts* obj);
extern void logic_faction_Contracts_unserializeInit(logic_faction_Contracts* obj);
extern void logic_faction_Contracts_unserialize(logic_faction_Contracts* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_Contracts_h__
