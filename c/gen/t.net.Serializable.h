// gen time: 2024-07-14 04:39:47 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_net_Serializable_h__
#define __gen_t_net_Serializable_h__

#include <common.h>
typedef struct EReason EReason;
typedef struct Game Game;
typedef struct String String;
typedef struct hl_types_ArrayDyn hl_types_ArrayDyn;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkHost hxbit_NetworkHost;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_Event lib_Event;
typedef struct net_Serializable net_Serializable;


// type: net.Serializable, kind: HOBJ, pType: 0x02748E3E41D8
struct net_Serializable {
  hl_type* pType;

  // cls: net.Serializable, begin_offset: 0x0008
  int                       __uid;              // +0008
  hxbit_NetworkHost*        __host;             // +0010: HOBJ hxbit.NetworkHost
  int                       __bits1;            // +0018
  int                       __bits2;            // +001C
  void*                     __next;             // +0020: HVIRTUAL
  void*                     HVIRTUAL_0x0028;    // +0028: HVIRTUAL
  void*                     HVIRTUAL_0x0030;    // +0030: HVIRTUAL
  // total_size: 0x0038
}; // net_Serializable (net.Serializable)

_Static_assert(sizeof(net_Serializable) == 0x0038, "cls net.Serializable has wrong size");


extern int net_Serializable_get_uniqueID(net_Serializable* obj);
extern bool net_Serializable_get_isAuth(net_Serializable* obj);
extern bool net_Serializable_get_isLocalAuth(net_Serializable* obj);
extern Game* net_Serializable_get_game(net_Serializable* obj);
extern bool net_Serializable_get_isGameServer(net_Serializable* obj);
extern bool net_Serializable_getEnableReplication(net_Serializable* obj);
extern void net_Serializable_netRemove(net_Serializable* obj);
extern void net_Serializable_netFlush(net_Serializable* obj);
extern void net_Serializable_simulate(net_Serializable* obj, void* arg1);
extern void net_Serializable_onEvent(net_Serializable* obj, lib_Event* arg1);
extern String* net_Serializable_getLogID(net_Serializable* obj);
extern bool net_Serializable_enableApiLog(net_Serializable* obj);
extern void net_Serializable_apiLog(net_Serializable* obj, String* arg1, hl_types_ArrayDyn* arg2, EReason* arg3);
extern bool net_Serializable_propHasMeta(net_Serializable* obj, int arg1, String* arg2);
extern bool net_Serializable_networkAllow(net_Serializable* obj, int arg1, int arg2, void* arg3);
extern int net_Serializable_getCLID(net_Serializable* obj);
extern void net_Serializable_serialize(net_Serializable* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* net_Serializable_getSerializeSchema(net_Serializable* obj);
extern void net_Serializable_unserializeInit(net_Serializable* obj);
extern void net_Serializable_unserialize(net_Serializable* obj, hxbit_Serializer* arg1);
extern void net_Serializable_networkSetBit(net_Serializable* obj, int arg1);
extern bool net_Serializable_get_enableReplication(net_Serializable* obj);
extern bool net_Serializable_get_enableAutoReplication(net_Serializable* obj);
extern bool net_Serializable_set_enableReplication(net_Serializable* obj, bool arg1);
extern bool net_Serializable_set_enableAutoReplication(net_Serializable* obj, bool arg1);
extern void net_Serializable_networkCancelProperty(net_Serializable* obj, int arg1);
extern void net_Serializable_networkLocalChange(net_Serializable* obj, void* arg1);
extern void net_Serializable_alive(net_Serializable* obj);
extern void net_Serializable_networkFlush(net_Serializable* obj, hxbit_Serializer* arg1);
extern void net_Serializable_networkSync(net_Serializable* obj, hxbit_Serializer* arg1);
extern void net_Serializable_networkInitProxys(net_Serializable* obj);
extern bool net_Serializable_networkRPC(net_Serializable* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* net_Serializable_networkGetName(net_Serializable* obj, int arg1, void* arg2);


#endif // __gen_t_net_Serializable_h__
