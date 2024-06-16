#include "common.h"
#include "Game/VOICEXA.h"
#include "Game/GAMELOOP.h"

extern char D_800D1EB0[];

XAVoiceTracker voiceTracker;

void VOICEXA_Init()
{
    int i;
    CdlFILE fp;
    XAVoiceTracker *vt;
    char fileName[32];

    vt = &voiceTracker;

    if ((gameTrackerX.debugFlags & 0x80000))
    {
        vt->voiceStatus = 0;
        vt->cdStatus = 0;

        vt->reqIn = 0;
        vt->reqOut = 0;
        vt->reqsQueued = 0;

        vt->cdCmdIn = 0;
        vt->cdCmdOut = 0;
        vt->cdCmdsQueued = 0;

        vt->voiceCmdIn = 0;
        vt->voiceCmdOut = 0;
        vt->voiceCmdsQueued = 0;

        for (i = 0; i < 30; i++)
        {
            sprintf(&fileName[0], D_800D1EB0, i);

            if (CdSearchFile(&fp, &fileName[0]) == 0)
            {
                vt->xaFileInfo[i].startPos = 0;
            }
            else
            {
                vt->xaFileInfo[i].startPos = CdPosToInt(&fp.pos);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", putCdCommand);

void VOICEXA_CdSyncCallback(unsigned char status, unsigned char *result)
{
    XAVoiceTracker *vt;

    (void)result;

    vt = &voiceTracker;

    if (status == 2)
    {
        vt->cdStatus = 0;

        if (++vt->cdCmdOut == 8)
        {
            vt->cdCmdOut = 0;
        }

        vt->cdCmdsQueued--;

        CdSyncCallback(vt->prevCallback);
    }
    else
    {
        vt->cdStatus = 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", processCdCommands);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", putVoiceCommand);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", processVoiceCommands);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", voiceCmdPlay);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", voiceCmdStop);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", voiceCmdPause);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", voiceCmdResume);

void voiceCmdNull()
{
}

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", VOICEXA_Play);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", VOICEXA_FinalStatus);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", VOICEXA_Pause);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", VOICEXA_Resume);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", VOICEXA_Tick);

INCLUDE_ASM("asm/nonmatchings/Game/VOICEXA", VOICEXA_IsPlaying);
