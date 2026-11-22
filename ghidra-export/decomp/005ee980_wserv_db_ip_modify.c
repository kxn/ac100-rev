// func wserv_db_ip_modify @ 005ee980 size=512

undefined4 wserv_db_ip_modify(uint *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == (uint *)0x0) {
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("<wserv>[warning]%s(): %d  -> entry is null!\r\n","wserv_db_ip_modify",0xcee);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  if (0x1f < *param_1) {
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_ip_modify",0xcf4,*param_1
          );
    return 0xffffffff;
  }
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  pcVar2 = (char *)(DAT_007cbf14 + *param_1 * 0x20);
  if (*pcVar2 == '\0') {
    uVar4 = 0xffffffff;
    if ((g_wserv_warning == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005eea28;
    pcVar2 = "<wserv>[warning]%s(): %d  -> entry.id[%d] is not used!\r\n";
    uVar3 = 0xcfb;
  }
  else {
    iVar1 = memcmp(pcVar2 + 4,param_1,0x1c);
    if (iVar1 != 0) {
      if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> entry.id[%d] something has changed\r\n",
               "wserv_db_ip_modify",0xd01,*param_1);
      }
      uVar4 = 0;
      memcpy((void *)(DAT_007cbf14 + *param_1 * 0x20 + 4),param_1,0x1c);
      goto LAB_005eea28;
    }
    uVar4 = 1;
    if ((g_wserv_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005eea28;
    pcVar2 = "<wserv>[debug]%s(): %d  -> entry.id[%d] no changed\r\n";
    uVar3 = 0xd07;
  }
  printf(pcVar2,"wserv_db_ip_modify",uVar3,*param_1);
LAB_005eea28:
  FUN_00407f30(DAT_007cbef0);
  return uVar4;
}

