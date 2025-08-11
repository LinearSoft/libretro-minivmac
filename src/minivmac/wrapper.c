#include <COMOSGLU.h>

#include "wrapper.h"

extern void ii_Keyboard_UpdateKeyMap(ui3r key, blnr down);

static MiniVmacWrap_t minivmac_wrapper;


void retromac_minivmac_wrapper_init(bool isPlus) {
   if(isPlus) {
      minivmac_wrapper.Keyboard_UpdateKeyMap = Keyboard_UpdateKeyMap;
   }
   else
   {
      minivmac_wrapper.Keyboard_UpdateKeyMap = ii_Keyboard_UpdateKeyMap;
   }


}

void retromac_minivmac_deinit() {

}