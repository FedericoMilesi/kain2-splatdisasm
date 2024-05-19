#include "common.h"
#include "Game/TYPES.h"

void PIPE3D_AspectAdjustMatrix(MATRIX *matrix)
{
    int temp, temp2, temp3; // not from decls.h

    temp = matrix->m[1][0];
    temp2 = matrix->m[1][1];
    temp3 = matrix->m[1][2];

    matrix->m[1][0] = temp;
    matrix->m[1][1] = temp2;
    matrix->m[1][2] = temp3;

    matrix->m[0][0] = (matrix->m[0][0] * 512) / 320;
    matrix->m[0][1] = (matrix->m[0][1] * 512) / 320;
    matrix->m[0][2] = (matrix->m[0][2] * 512) / 320;
}

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_CalculateWCTransform);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_InvertTransform);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_MatrixColumnLength);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_NormalizeMatrix);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_TransformVerticesToWorld);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_InstanceTransformAndDraw);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_InstanceListTransformAndDrawFunc);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_InstanceListTransformAndDraw);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_TransformFromZAxis);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_CalcWorldToSplitPlaneTransform);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_TransformAnimatedSplitInstanceVertices);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_TransformSplitInstanceVertices);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_AnimateTextures);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_AnimateTerrainTextures);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_HalvePlaneInstanceTransformAndDraw);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_HalvePlaneGetRingPoints);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_DoGlow);

INCLUDE_ASM("asm/nonmatchings/Game/PIPE3D", PIPE3D_Segment2ScreenPt);
