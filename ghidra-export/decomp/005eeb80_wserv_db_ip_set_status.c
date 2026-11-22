// func wserv_db_ip_set_status @ 005eeb80 size=284

undefined4 wserv_db_ip_set_status(uint param_1,char param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (param_1 < 0x20) {
    FUN_004082d0(DAT_007cbef0,0xffffffff);
    pcVar2 = (char *)(DAT_007cbf14 + param_1 * 0x20);
    if (*pcVar2 == '\0') {
      uVar3 = 0xffffffff;
      if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> entry.id[%d] is not used!\r\n","wserv_db_ip_set_status"
               ,0xd2a,param_1);
      }
    }
    else {
      uVar3 = 1;
      if (pcVar2[0x1d] != param_2) {
        uVar3 = 0;
        pcVar2[0x1d] = param_2;
      }
    }
    FUN_00407f30(DAT_007cbef0);
  }
  else {
    uVar3 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_ip_set_status",0xd23,
             param_1);
    }
  }
  return uVar3;
}

