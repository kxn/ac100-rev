// func wserv_db_ip_get_entry_by_id @ 005ee550 size=356

undefined4 wserv_db_ip_get_entry_by_id(uint param_1,void *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (param_2 == (void *)0x0) {
    if (g_wserv_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("<wserv>[error]%s(): %d  -> entry is null!\r\n","wserv_db_ip_get_entry_by_id",0xc76);
      return 0xffffffff;
    }
  }
  else {
    if (param_1 < 0x20) {
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      pcVar2 = (char *)(DAT_007cbf14 + param_1 * 0x20);
      if (*pcVar2 == '\0') {
        uVar3 = 0xffffffff;
        if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> id[%d] has not been used!\r\n",
                 "wserv_db_ip_get_entry_by_id",0xc83,param_1);
        }
      }
      else {
        memcpy(param_2,pcVar2 + 4,0x1c);
        uVar3 = 0;
      }
      FUN_00407f30(DAT_007cbef0);
      return uVar3;
    }
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_ip_get_entry_by_id",
             0xc7c,param_1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

