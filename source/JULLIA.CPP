/*---------------------------------------------------------*/
/*                                                         */
/*   DN Jullia 2024.0 -> Part Of DN Family                 */
/*   Jullia Main Source File                               */
/*   Copyright (c) 2024 by Branislav Juhas                 */
/*                                                         */
/*---------------------------------------------------------*/

#define Uses_TApplication
#define Uses_TKeys
#define Uses_TRect
#define Uses_TStatusLine
#define Uses_TStatusItem
#define Uses_TStatusDef
#define Uses_TDeskTop
#include <tv.h>

class TJullia : public TApplication
{

public:
    TJullia();
    static TStatusLine *initStatusLine( TRect r );
};

TJullia::TJullia() :
    TProgInit( &TJullia::initStatusLine,
               &TJullia::initMenuBar,
               &TJullia::initDeskTop
             )
{
}

TStatusLine *TJullia::initStatusLine(TRect r)
{
    r.a.y = r.b.y - 1;
    return new TStatusLine( r,
        *new TStatusDef( 0, 0xFFFF ) +
            *new TStatusItem( "~F1~ Help", kbF1, cmHelp ) +
            *new TStatusItem( "~Alt-F4~ Exit", kbAltF4, cmQuit ) +
            *new TStatusItem( "~F10~ Menu", kbF10, cmMenu )
        );
}

int main()
{
    TJullia jullia;
    jullia.run();
    return 0;
}