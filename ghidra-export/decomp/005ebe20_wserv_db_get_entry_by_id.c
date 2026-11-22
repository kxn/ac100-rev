// func wserv_db_get_entry_by_id @ 005ebe20 size=372

undefined4 wserv_db_get_entry_by_id(uint param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == (void *)0x0) {
    if (g_wserv_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("<wserv>[error]%s(): %d  -> entry is null!\r\n","wserv_db_get_entry_by_id",0x8b4);
      return 0xffffffff;
    }
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < l_wserv_profile)) {
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      iVar1 = DAT_007cbefc + param_1 * 0x21c;
      if (*(int *)(iVar1 + 0xc) == 0) {
        uVar2 = 0xffffffff;
        if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> id[%d] has not been used!\r\n",
                 "wserv_db_get_entry_by_id",0x8c1,param_1);
        }
      }
      else {
        memcpy(param_2,(void *)(iVar1 + 0x10),0x205);
        uVar2 = 0;
      }
      FUN_00407f30(DAT_007cbef0);
      return uVar2;
    }
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_get_entry_by_id",0x8ba,
             param_1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

