/*---------------------------------------------------------*/
/*                                                         */
/*   DN Jullia 2024.0 -> Part Of DN Family                 */
/*   Environment Source File                               */
/*   Copyright (c) 2024 by Branislav Juhas                 */
/*                                                         */
/*---------------------------------------------------------*/

#include "envt.h"

const int cmNew = 100;
const int cmOpen = 101;
const int cmSave = 102;
const int cmSaveAs = 103;

TEnvironment::TEnvironment() :
    TProgInit(&TEnvironment::initStatusLine,
              &TEnvironment::initMenuBar,
              &TEnvironment::initDeskTop)
{
}

TStatusLine *TEnvironment::initStatusLine(TRect r)
{
    r.a.y = r.b.y - 1;
    return new TStatusLine(r,
        *new TStatusDef(0, 0xFFFF) +
            *new TStatusItem("~F1~ Help", kbF1, cmHelp) +
            *new TStatusItem("~Alt-F4~ Exit", kbAltF4, cmQuit) +
            *new TStatusItem("~F10~ Menu", kbF10, cmMenu)
        );
}

TMenuBar *TEnvironment::initMenuBar(TRect r)
{
    r.b.y = r.a.y + 1;
    return new TMenuBar(r,
        *new TSubMenu("~F~ile", kbAltF) +
            *new TMenuItem("~N~ew", cmNew, kbNoKey, hcNoContext) +
            *new TMenuItem("~O~pen", cmOpen, kbF3, hcNoContext, "F3") +
            *new TMenuItem("~S~ave", cmSave, kbF2, hcNoContext, "F2") +
            *new TMenuItem("Save ~A~s", cmSaveAs, kbNoKey, hcNoContext) +
            newLine() +
            *new TMenuItem("~E~xit", cmQuit, kbAltF4, hcNoContext, "Alt-F4")
        );
}