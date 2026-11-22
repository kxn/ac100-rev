// func wserv_db_ip_del @ 005ee850 size=304

undefined4 wserv_db_ip_del(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 0x20) {
    FUN_004082d0(DAT_007cbef0,0xffffffff);
    if (*(char *)(DAT_007cbf14 + param_1 * 0x20) == '\0') {
      uVar2 = 0xffffffff;
      if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> entry.id[%d] is not used!\r\n","wserv_db_ip_del",0xcd2,
               param_1);
      }
    }
    else {
      FUN_004080f0(DAT_007cbf0c,param_1);
      *(undefined1 *)(DAT_007cbf14 + param_1 * 0x20) = 0;
      DAT_007cbf10 = DAT_007cbf10 + -1;
      uVar2 = 0;
    }
    FUN_00407f30(DAT_007cbef0);
  }
  else {
    uVar2 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_ip_del",0xccb,param_1);
    }
  }
  return uVar2;
}

