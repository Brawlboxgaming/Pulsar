#ifndef _NW4R_G3D_DRAW_
#define _NW4R_G3D_DRAW_
#include <types.hpp>
#include <core/nw4r/g3d/g3dObj.hpp>
#include <core/nw4r/g3d/res/ResMdl.hpp>
#include <core/nw4r/g3d/workmem.hpp>
#include <core/nw4r/math.hpp>

namespace nw4r {
namespace g3d {
class DrawResMdlReplacement;

enum ResMdlDrawMode {
    //Renders opaque polygons in the order determined by the converter
    RESMDL_DRAWMODE_SORT_OPA_NONE   = 0x00000000,
    //Z-sorts and renders the opaque polygons (starting from the foreground)
    RESMDL_DRAWMODE_SORT_OPA_Z      = 0x00000001,
    //Renders translucent polygons in the order determined by the converter
    RESMDL_DRAWMODE_SORT_XLU_NONE   = 0x00000000,
    //Z-sorts and renders the translucent polygons (starting from the back)
    RESMDL_DRAWMODE_SORT_XLU_Z      = 0x00000002,
    //Materials are rendered without being sent to the GP
    RESMDL_DRAWMODE_IGNORE_MATERIAL = 0x00000004,
    //Renders with the light disabled (enable state of GXSetChanCtrl will be FALSE)
    RESMDL_DRAWMODE_FORCE_LIGHTOFF  = 0x00000008,
    //Make sure PPCSync() is not called before the render
    RESMDL_DRAWMODE_NOPPCSYNC       = 0x00000010,
    //RESMDL_DRAWMODE_SORT_OPA_NONE | RESMDL_DRAWMODE_SORT_XLU_Z This is the default.
    RESMDL_DRAWMODE_DEFAULT         = RESMDL_DRAWMODE_SORT_OPA_NONE | RESMDL_DRAWMODE_SORT_XLU_Z,
    //RESMDL_DRAWMODE_SORT_OPA_NONE | RESMDL_DRAWMODE_SORT_XLU_NONE
    REDMDL_DRAWMODE_SORT_NONE       = RESMDL_DRAWMODE_SORT_OPA_NONE | RESMDL_DRAWMODE_SORT_XLU_NONE,
    //RESMDL_DRAWMODE_SORT_OPA_Z | RESMDL_DRAWMODE_SORT_XLU_Z
    RESMDL_DRAWMODE_SORT_Z          = RESMDL_DRAWMODE_SORT_OPA_Z | RESMDL_DRAWMODE_SORT_XLU_Z
};

detail::workmem::MdlZ* SetUpMdlZ(u32* pNumMdlZ, const ResMdl mdl, const math::MTX34* pViewPos, const u8* pByteCode, DrawResMdlReplacement* pRep); //80068ec0

void DrawResMdlDirectly(const ResMdl mdl, const math::MTX34* viewPos, const math::MTX33* viewNrm, const math::MTX34* viewEnv, const u8* opa, const u8* xlu,
    DrawResMdlReplacement* rep, u32 resMdlDrawMode = RESMDL_DRAWMODE_DEFAULT); //80069000

void DrawResMdlLoop(const ResMdl mdl, const detail::workmem::MdlZ* mdlZArray, u32 mdlZCount, DrawResMdlReplacement* replacement, u32 resMdlDrawMode); //80068d60
void DrawResMdlLoop(const ResMdl mdl, const detail::workmem::MdlZ* mdlZArray, u32 mdlZCount, u32 resMdlDrawMode); //80068c50
void DrawResMdlLoop(const ResMdl mdl, const u8* byteCode, DrawResMdlReplacement* replacement, u32 resMdlDrawMode); //80068a80
void DrawResMdlLoop(const ResMdl mdl, const u8* byteCode, u32 resMdlDrawMode); //80068940



}//namespace g3d  
}//namespace nw4r 


#endif