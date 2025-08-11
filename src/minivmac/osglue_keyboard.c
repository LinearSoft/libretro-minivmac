#include <libretro.h>
#include "wrapper.h"
#include "osglue_keyboard.h"


void OSGlue_KeyEvent(bool down, unsigned keycode)
{
   ui3r macKeycode = RetroKey2MacKeyCode(keycode);
   if(macKeycode != MKC_None)
      /* Bypass Keyboard_UpdateKeyMap1 as we internally handle AltKeys */
      minivmac_wrapper.Keyboard_UpdateKeyMap(macKeycode, down ? trueblnr : falseblnr);
}

// When returning from background we may need to disconnect all keys
LOCALPROC DisconnectKeyCodes3(void)
{
   DisconnectKeyCodes2();
   MyMouseButtonSet(falseblnr);
}

ui3r RetroKey2MacKeyCode(unsigned retroKey)
{
   ui3r v = MKC_None;

   switch (retroKey)
   {
   // case RETROK_UNKNOWN:
   // case RETROK_FIRST:

   /*********   Extended keys 01   *********/
   case RETROK_BACKSPACE:
      v = MKC_BackSpace;
      break;
   case RETROK_TAB:
      v = MKC_Tab;
      break;
   case RETROK_CLEAR:
      v = MKC_Clear;
      break;
   case RETROK_RETURN:
      v = MKC_Return;
      break;
   case RETROK_PAUSE:
      v = MKC_Pause;
      break;
   case RETROK_ESCAPE:
      v = MKC_Escape;
      break;
   case RETROK_SPACE:
      v = MKC_Space;
      break;
   // case RETROK_EXCLAIM:
   // case RETROK_QUOTEDBL:
   // case RETROK_HASH:
   // case RETROK_DOLLAR:
   // case RETROK_AMPERSAND:
   case RETROK_QUOTE:
      v = MKC_SingleQuote;
      break;
   // case RETROK_LEFTPAREN:
   // case RETROK_RIGHTPAREN:
   // case RETROK_ASTERISK:
   // case RETROK_PLUS:
   case RETROK_COMMA:
      v = MKC_Comma;
      break;
   case RETROK_MINUS:
      v = MKC_Minus;
      break;
   case RETROK_PERIOD:
      v = MKC_Period;
      break;
   case RETROK_SLASH:
      v = MKC_Slash;
      break;

   /*********   Number keys   *********/
   case RETROK_0:
      v = MKC_0;
      break;
   case RETROK_1:
      v = MKC_1;
      break;
   case RETROK_2:
      v = MKC_2;
      break;
   case RETROK_3:
      v = MKC_3;
      break;
   case RETROK_4:
      v = MKC_4;
      break;
   case RETROK_5:
      v = MKC_5;
      break;
   case RETROK_6:
      v = MKC_6;
      break;
   case RETROK_7:
      v = MKC_7;
      break;
   case RETROK_8:
      v = MKC_8;
      break;
   case RETROK_9:
      v = MKC_9;
      break;

   /*********   Extended keys 02   *********/
   // case RETROK_COLON:
   case RETROK_SEMICOLON:
      v = MKC_SemiColon;
      break;
   // case RETROK_LESS:
   case RETROK_EQUALS:
      v = MKC_Equal;
      break;
   // case RETROK_GREATER:
   // case RETROK_QUESTION:
   // case RETROK_AT:
   case RETROK_LEFTBRACKET:
      v = MKC_LeftBracket;
      break;
   case RETROK_BACKSLASH:
      v = MKC_BackSlash;
      break;
   case RETROK_RIGHTBRACKET:
      v = MKC_RightBracket;
      break;
   // case RETROK_CARET:
   // case RETROK_UNDERSCORE:
   case RETROK_BACKQUOTE:
      v = MKC_Grave;
      break;

   /*********   Letters   *********/
   case RETROK_a:
      v = MKC_A;
      break;
   case RETROK_b:
      v = MKC_B;
      break;
   case RETROK_c:
      v = MKC_C;
      break;
   case RETROK_d:
      v = MKC_D;
      break;
   case RETROK_e:
      v = MKC_E;
      break;
   case RETROK_f:
      v = MKC_F;
      break;
   case RETROK_g:
      v = MKC_G;
      break;
   case RETROK_h:
      v = MKC_H;
      break;
   case RETROK_i:
      v = MKC_I;
      break;
   case RETROK_j:
      v = MKC_J;
      break;
   case RETROK_k:
      v = MKC_K;
      break;
   case RETROK_l:
      v = MKC_L;
      break;
   case RETROK_m:
      v = MKC_M;
      break;
   case RETROK_n:
      v = MKC_N;
      break;
   case RETROK_o:
      v = MKC_O;
      break;
   case RETROK_p:
      v = MKC_P;
      break;
   case RETROK_q:
      v = MKC_Q;
      break;
   case RETROK_r:
      v = MKC_R;
      break;
   case RETROK_s:
      v = MKC_S;
      break;
   case RETROK_t:
      v = MKC_T;
      break;
   case RETROK_u:
      v = MKC_U;
      break;
   case RETROK_v:
      v = MKC_V;
      break;
   case RETROK_w:
      v = MKC_W;
      break;
   case RETROK_x:
      v = MKC_X;
      break;
   case RETROK_y:
      v = MKC_Y;
      break;
   case RETROK_z:
      v = MKC_Z;
      break;

   /*********   Extended keys 03   *********/
   // case RETROK_LEFTBRACE:
   // case RETROK_BAR:
   // case RETROK_RIGHTBRACE:
   // case RETROK_TILDE:
   // case RETROK_DELETE:

   /*********   Keypad   *********/
   case RETROK_KP0:
      v = MKC_KP0;
      break;
   case RETROK_KP1:
      v = MKC_KP1;
      break;
   case RETROK_KP2:
      v = MKC_KP3;
      break;
   case RETROK_KP3:
      v = MKC_KP3;
      break;
   case RETROK_KP4:
      v = MKC_KP4;
      break;
   case RETROK_KP5:
      v = MKC_KP5;
      break;
   case RETROK_KP6:
      v = MKC_KP6;
      break;
   case RETROK_KP7:
      v = MKC_KP7;
      break;
   case RETROK_KP8:
      v = MKC_KP8;
      break;
   case RETROK_KP9:
      v = MKC_KP9;
      break;
   case RETROK_KP_PERIOD:
      v = MKC_Decimal;
      break;
   case RETROK_KP_DIVIDE:
      v = MKC_KPDevide;
      break;
   case RETROK_KP_MULTIPLY:
      v = MKC_KPMultiply;
      break;
   case RETROK_KP_MINUS:
      v = MKC_KPSubtract;
      break;
   case RETROK_KP_PLUS:
      v = MKC_KPAdd;
      break;
   case RETROK_KP_ENTER:
      v = MKC_Enter;
      break;
   case RETROK_KP_EQUALS:
      v = MKC_KPEqual;
      break;

   /*********   Arrow keys   *********/
   case RETROK_UP:
      v = MKC_Up;
      break;
   case RETROK_DOWN:
      v = MKC_Down;
      break;
   case RETROK_RIGHT:
      v = MKC_Right;
      break;
   case RETROK_LEFT:
      v = MKC_Left;
      break;

   /*********   Home keys   *********/
   case RETROK_INSERT:
      v = MKC_Help;
      break;
   case RETROK_HOME:
      v = MKC_Home;
      break;
   case RETROK_END:
      v = MKC_End;
      break;
   case RETROK_PAGEUP:
      v = MKC_PageUp;
      break;
   case RETROK_PAGEDOWN:
      v = MKC_PageDown;
      break;

   /*********   Function keys   *********/
   case RETROK_F1:
      v = MKC_F1;
      break;
   case RETROK_F2:
      v = MKC_F2;
      break;
   case RETROK_F3:
      v = MKC_F3;
      break;
   case RETROK_F4:
      v = MKC_F4;
      break;
   case RETROK_F5:
      v = MKC_F5;
      break;
   case RETROK_F6:
      v = MKC_F6;
      break;
   case RETROK_F7:
      v = MKC_F7;
      break;
   case RETROK_F8:
      v = MKC_F8;
      break;
   case RETROK_F9:
      v = MKC_F9;
      break;
   case RETROK_F10:
      v = MKC_F11;
      break;
   case RETROK_F11:
      v = MKC_None;
      break;
   case RETROK_F12:
      v = MKC_F12;
      break;
   // case RETROK_F13:
   // case RETROK_F14:
   // case RETROK_F15:

   /*********   Modifiers   *********/
   case RETROK_NUMLOCK:
      v = MKC_ForwardDel;
      break;
   case RETROK_CAPSLOCK:
      v = MKC_CapsLock;
      break;
   case RETROK_SCROLLOCK:
      v = MKC_ScrollLock;
      break;
   case RETROK_RSHIFT:
      v = MKC_Shift;
      break;
   case RETROK_LSHIFT:
      v = MKC_Shift;
      break;
   case RETROK_RCTRL:
      v = MKC_CM;
      break;
   case RETROK_LCTRL:
      v = MKC_CM;
      break;
   case RETROK_RALT:
      v = MKC_Command;
      break;
   case RETROK_LALT:
      v = MKC_Command;
      break;
   // case RETROK_RMETA:
   // case RETROK_LMETA:
   case RETROK_LSUPER:
      v = MKC_Option;
      break;
   case RETROK_RSUPER:
      v = MKC_Option;
      break;

   /*********   Macro/Media keys   *********/
   // case RETROK_MODE:
   // case RETROK_COMPOSE:
   case RETROK_HELP:
      v = MKC_Help;
      break;
   case RETROK_PRINT:
      v = MKC_Print;
      break;
   // case RETROK_SYSREQ:
   // case RETROK_BREAK:
   // case RETROK_MENU:
   // case RETROK_POWER:
   // case RETROK_EURO:
   // case RETROK_UNDO:
   // case RETROK_OEM_102:
   // case RETROK_BROWSER_BACK:
   // case RETROK_BROWSER_FORWARD:
   // case RETROK_BROWSER_REFRESH:
   // case RETROK_BROWSER_STOP:
   // case RETROK_BROWSER_SEARCH:
   // case RETROK_BROWSER_FAVORITES:
   // case RETROK_BROWSER_HOME:
   // case RETROK_VOLUME_MUTE:
   // case RETROK_VOLUME_DOWN:
   // case RETROK_VOLUME_UP:
   // case RETROK_MEDIA_NEXT:
   // case RETROK_MEDIA_PREV:
   // case RETROK_MEDIA_STOP:
   // case RETROK_MEDIA_PLAY_PAUSE:
   // case RETROK_LAUNCH_MAIL:
   // case RETROK_LAUNCH_MEDIA:
   // case RETROK_LAUNCH_APP1:
   // case RETROK_LAUNCH_APP2:

   // case RETROK_LAST:
   default:
      break;
   }
}