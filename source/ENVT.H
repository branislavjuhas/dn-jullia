/*---------------------------------------------------------*/
/*                                                         */
/*   DN Jullia 2024.0 -> Part Of DN Family                 */
/*   Environment Header File                               */
/*   Copyright (c) 2024 by Branislav Juhas                 */
/*                                                         */
/*---------------------------------------------------------*/

#define Uses_TApplication
#define Uses_TKeys
#define Uses_TRect
#define Uses_TStatusLine
#define Uses_TStatusItem
#define Uses_TMenuBar
#define Uses_TSubMenu
#define Uses_TMenuItem
#define Uses_TStatusDef
#define Uses_TDeskTop
#define Uses_TScreen

#include <tv.h>

class TStatusLine;
class TMenuBar;

class TEnvironment : public TApplication
{
    
public:
    TEnvironment();
    static TStatusLine *initStatusLine(TRect r);
    static TMenuBar *initMenuBar(TRect r);
};