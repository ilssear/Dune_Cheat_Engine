// gen time: 2024-07-21 07:23:49 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_NeuralGrid_h__
#define __gen_t_logic_faction_NeuralGrid_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Structure ent_Structure;
typedef struct ent_Zone ent_Zone;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_NeuralGrid logic_faction_NeuralGrid;


// type: logic.faction.NeuralGrid, kind: HOBJ, pType: 0x02A76E33C378
struct logic_faction_NeuralGrid {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.NeuralGrid, begin_offset: 0x00B0
  hl_types_ArrayObj*        roots;              // +00B0: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        rootsData;          // +00B8: HOBJ hl.types.ArrayObj
  // total_size: 0x00C0
}; // logic_faction_NeuralGrid (logic.faction.NeuralGrid)

_Static_assert(sizeof(logic_faction_NeuralGrid) == 0x00C0, "cls logic.faction.NeuralGrid has wrong size");


extern EReason* logic_faction_NeuralGrid_getAddToNetworkNoReason(logic_faction_NeuralGrid* obj, ent_Structure* arg1, bool arg2);
extern bool logic_faction_NeuralGrid_canAddToNetworkInternal(logic_faction_NeuralGrid* obj, ent_Structure* arg1);
extern EReason* logic_faction_NeuralGrid_implAddToNetwork(logic_faction_NeuralGrid* obj, ent_Structure* arg1);
extern int logic_faction_NeuralGrid_getInProgressNeuralNodeNearby(logic_faction_NeuralGrid* obj, ent_Zone* arg1);
extern bool logic_faction_NeuralGrid_hasConnectedNeuralNode(logic_faction_NeuralGrid* obj, ent_Zone* arg1);
extern void logic_faction_NeuralGrid_resetNetwork(logic_faction_NeuralGrid* obj);
extern ent_Zone* logic_faction_NeuralGrid_getFurtherNodeZone(logic_faction_NeuralGrid* obj);
extern void logic_faction_NeuralGrid_iterateConnections(logic_faction_NeuralGrid* obj, void* arg1);
extern void logic_faction_NeuralGrid_iterateNodes(logic_faction_NeuralGrid* obj, void* arg1);
extern double logic_faction_NeuralGrid_getConnectedZonesLengthFromMB(logic_faction_NeuralGrid* obj);
extern int logic_faction_NeuralGrid_getConnectedZonesLength(logic_faction_NeuralGrid* obj, ent_Zone* arg1);
extern bool logic_faction_NeuralGrid_hasConnectedZoneNearby(logic_faction_NeuralGrid* obj, ent_Zone* arg1);
extern int logic_faction_NeuralGrid_getMaxPathLength(logic_faction_NeuralGrid* obj);
extern void logic_faction_NeuralGrid_onReady(logic_faction_NeuralGrid* obj);
extern void logic_faction_NeuralGrid_initGrid(logic_faction_NeuralGrid* obj);
extern bool logic_faction_NeuralGrid_isEnabled(logic_faction_NeuralGrid* obj);
extern void* logic_faction_NeuralGrid_getNode(logic_faction_NeuralGrid* obj, ent_Zone* arg1);
extern bool logic_faction_NeuralGrid_hasRoot(logic_faction_NeuralGrid* obj);
extern ent_Zone* logic_faction_NeuralGrid_findFirstConnectableProxy(logic_faction_NeuralGrid* obj, ent_Zone* arg1);
extern void logic_faction_NeuralGrid_refreshNetwork(logic_faction_NeuralGrid* obj);
extern void logic_faction_NeuralGrid_proneDeadNodes(logic_faction_NeuralGrid* obj, void* arg1);
extern void logic_faction_NeuralGrid_rpcRefreshNetwork__impl(logic_faction_NeuralGrid* obj);
extern void* logic_faction_NeuralGrid_addZoneToNetwork(logic_faction_NeuralGrid* obj, ent_Zone* arg1, void* arg2, bool arg3);
extern void* logic_faction_NeuralGrid_createNode(logic_faction_NeuralGrid* obj, ent_Zone* arg1, void* arg2, bool arg3);
extern void* logic_faction_NeuralGrid_getAdjacentNeuralNode(logic_faction_NeuralGrid* obj, ent_Zone* arg1);
extern bool logic_faction_NeuralGrid_isProxyZone(logic_faction_NeuralGrid* obj, ent_Zone* arg1);
extern int logic_faction_NeuralGrid_getAdjacentNeuralNodeCount(logic_faction_NeuralGrid* obj, ent_Zone* arg1);
extern void* logic_faction_NeuralGrid_findNode(logic_faction_NeuralGrid* obj, ent_Zone* arg1, void* arg2);
extern void* logic_faction_NeuralGrid_getNodesData(logic_faction_NeuralGrid* obj, void* arg1);
extern void* logic_faction_NeuralGrid_getMaxDistToRootNode(logic_faction_NeuralGrid* obj, void* arg1, int arg2);
extern void logic_faction_NeuralGrid_iterNodesRec(logic_faction_NeuralGrid* obj, void* arg1, void* arg2);
extern void logic_faction_NeuralGrid_iterConnectionsRec(logic_faction_NeuralGrid* obj, void* arg1, void* arg2);
extern ent_Entity* logic_faction_NeuralGrid_getCenterEntity(logic_faction_NeuralGrid* obj, void* arg1);
extern void* logic_faction_NeuralGrid_getCenterPosition(logic_faction_NeuralGrid* obj, void* arg1);
extern int logic_faction_NeuralGrid_countZones(logic_faction_NeuralGrid* obj, void* arg1);
extern void logic_faction_NeuralGrid_getZones(logic_faction_NeuralGrid* obj, void* arg1, hl_types_ArrayObj* arg2);
extern EReason* logic_faction_NeuralGrid_addToNetwork(logic_faction_NeuralGrid* obj, ent_Structure* arg1, void* arg2);
extern bool logic_faction_NeuralGrid_rpcAddToNetwork__impl(logic_faction_NeuralGrid* obj, ent_Structure* arg1);
extern EReason* logic_faction_NeuralGrid_checkAddToNetwork(logic_faction_NeuralGrid* obj, ent_Structure* arg1);
extern bool logic_faction_NeuralGrid_canAddToNetwork(logic_faction_NeuralGrid* obj, ent_Structure* arg1);
extern void logic_faction_NeuralGrid_rpcRefreshNetwork(logic_faction_NeuralGrid* obj);
extern void logic_faction_NeuralGrid_rpcAddToNetwork(logic_faction_NeuralGrid* obj, ent_Structure* arg1, void* arg2);
extern void logic_faction_NeuralGrid_networkFlush(logic_faction_NeuralGrid* obj, hxbit_Serializer* arg1);
extern void logic_faction_NeuralGrid_networkSync(logic_faction_NeuralGrid* obj, hxbit_Serializer* arg1);
extern bool logic_faction_NeuralGrid_networkRPC(logic_faction_NeuralGrid* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* logic_faction_NeuralGrid_networkGetName(logic_faction_NeuralGrid* obj, int arg1, void* arg2);
extern int logic_faction_NeuralGrid_getCLID(logic_faction_NeuralGrid* obj);
extern void logic_faction_NeuralGrid_unserializeInit(logic_faction_NeuralGrid* obj);
extern void logic_faction_NeuralGrid_unserialize(logic_faction_NeuralGrid* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_NeuralGrid_h__
