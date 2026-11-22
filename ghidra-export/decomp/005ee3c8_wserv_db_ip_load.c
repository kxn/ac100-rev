// func wserv_db_ip_load @ 005ee3c8 size=392

undefined4 wserv_db_ip_load(uint *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (param_1 == (uint *)0x0) {
    if (g_wserv_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar2 = "<wserv>[error]%s(): %d  -> entry is null!\r\n";
      uVar3 = 0xc4b;
      goto LAB_005ee48c;
    }
  }
  else {
    if (*param_1 < 0x20) {
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      pcVar2 = (char *)(DAT_007cbf14 + *param_1 * 0x20);
      if (*pcVar2 == '\0') {
        memcpy(pcVar2 + 4,param_1,0x1c);
        *(undefined1 *)(DAT_007cbf14 + *param_1 * 0x20) = 1;
        FUN_00408440(DAT_007cbf0c,*param_1);
        DAT_007cbf10 = DAT_007cbf10 + 1;
        uVar3 = 0;
      }
      else {
        uVar3 = 0xffffffff;
        if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> entry.id[%d] has been used!\r\n","wserv_db_ip_load",
                 0xc58,*param_1);
        }
      }
      FUN_00407f30(DAT_007cbef0);
      return uVar3;
    }
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar2 = "<wserv>[warning]%s(): %d  -> uac_id_alloc fail!\r\n";
      uVar3 = 0xc51;
LAB_005ee48c:
      printf(pcVar2,"wserv_db_ip_load",uVar3);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

