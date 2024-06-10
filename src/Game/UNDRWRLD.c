#include "common.h"
#include "Game/UNDRWRLD.h"
#include "Game/MATH3D.h"

INCLUDE_ASM("asm/nonmatchings/Game/UNDRWRLD", UNDERWORLD_StartProcess);

INCLUDE_ASM("asm/nonmatchings/Game/UNDRWRLD", UNDERWORLD_RotateScreenStep);

void UNDERWORLD_DoUV(unsigned char *uv, UW_ScreenXY *p0, int tx)
{
    int u;

    u = p0->sx - tx;

    if (u >= 256)
    {
        uv[0] = -1;
    }
    else
    {
        uv[0] = u;
    }

    if (p0->sy >= 256)
    {
        uv[1] = -1;
    }
    else
    {
        uv[1] = (unsigned char)p0->sy;
    }
}

INCLUDE_ASM("asm/nonmatchings/Game/UNDRWRLD", UNDERWORLD_Poly);

INCLUDE_ASM("asm/nonmatchings/Game/UNDRWRLD", UNDERWORLD_DisplayFrame);

INCLUDE_ASM("asm/nonmatchings/Game/UNDRWRLD", UNDERWORLD_SetupSource);

INCLUDE_ASM("asm/nonmatchings/Game/UNDRWRLD", UNDERWORLD_InitDisplayProcess);

INCLUDE_ASM("asm/nonmatchings/Game/UNDRWRLD", UNDERWORLD_LoadLevel);

void UNDERWORLD_UpdatePlayer(Intro *playerIntro, Instance *instance)
{
    SVector offset;

    SUB_SVEC(SVector, &offset, Position, &playerIntro->position, Position, &instance->position);

    STREAM_RelocateInstance(instance, &offset);
}
