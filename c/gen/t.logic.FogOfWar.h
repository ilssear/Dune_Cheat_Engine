// gen time: 2024-07-21 07:20:41 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_FogOfWar_h__
#define __gen_t_logic_FogOfWar_h__

#include <common.h>
#include <gen/t.net.Serializable.h>

typedef struct ent_ZoneCell ent_ZoneCell;
typedef struct h2d_Graphics h2d_Graphics;
typedef struct h2d_Scene h2d_Scene;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_FogLayer logic_FogLayer;
typedef struct logic_FogOfWar logic_FogOfWar;
typedef struct shaders_ColorSet shaders_ColorSet;
typedef struct world_Layer world_Layer;


// type: logic.FogOfWar, kind: HOBJ, pType: 0x02A76E31D8F8
struct logic_FogOfWar {
  // super: net.Serializable
  net_Serializable          super;

  // cls: logic.FogOfWar, begin_offset: 0x0038
  world_Layer*              fowMask;            // +0038: HOBJ world.Layer
  world_Layer*              targetMask;         // +0040: HOBJ world.Layer
  double                    scaleFromWorld;     // +0048
  h2d_Scene*                scene;              // +0050: HOBJ h2d.Scene
  hl_types_ArrayObj*        cache;              // +0058: HOBJ hl.types.ArrayObj
  shaders_ColorSet*         visibleShader;      // +0060: HOBJ shaders.ColorSet
  shaders_ColorSet*         visitedShader;      // +0068: HOBJ shaders.ColorSet
  // total_size: 0x0070
}; // logic_FogOfWar (logic.FogOfWar)

_Static_assert(sizeof(logic_FogOfWar) == 0x0070, "cls logic.FogOfWar has wrong size");


extern void logic_FogOfWar_alive(logic_FogOfWar* obj);
extern void logic_FogOfWar_dispose(logic_FogOfWar* obj);
extern void logic_FogOfWar_init(logic_FogOfWar* obj);
extern void logic_FogOfWar_beginDraw(logic_FogOfWar* obj);
extern void logic_FogOfWar_endDraw(logic_FogOfWar* obj);
extern void logic_FogOfWar_update(logic_FogOfWar* obj, double arg1);
extern h2d_Graphics* logic_FogOfWar_getGraphics(logic_FogOfWar* obj, ent_ZoneCell* arg1);
extern void logic_FogOfWar_preload(logic_FogOfWar* obj);
extern void logic_FogOfWar_discoverZone(logic_FogOfWar* obj, ent_ZoneCell* arg1, logic_FogLayer* arg2);
extern void logic_FogOfWar_networkFlush(logic_FogOfWar* obj, hxbit_Serializer* arg1);
extern void logic_FogOfWar_networkSync(logic_FogOfWar* obj, hxbit_Serializer* arg1);
extern int logic_FogOfWar_getCLID(logic_FogOfWar* obj);
extern void logic_FogOfWar_unserializeInit(logic_FogOfWar* obj);
extern void logic_FogOfWar_unserialize(logic_FogOfWar* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_FogOfWar_h__
