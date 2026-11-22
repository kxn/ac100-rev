// func wserv_db_ip_add @ 005ee6b4 size=412

uint wserv_db_ip_add(uint *param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 == (uint *)0x0) {
    uVar1 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[error]%s(): %d  -> entry is null!\r\n","wserv_db_ip_add",0xc9d);
    }
  }
  else {
    FUN_004082d0(DAT_007cbef0,0xffffffff);
    uVar1 = FUN_004085b0(DAT_007cbf0c);
    *param_1 = uVar1;
    if (uVar1 < 0x20) {
      pcVar3 = (char *)(DAT_007cbf14 + uVar1 * 0x20);
      if (*pcVar3 == '\0') {
        memcpy(pcVar3 + 4,param_1,0x1c);
        *(undefined1 *)(DAT_007cbf14 + *param_1 * 0x20) = 1;
        DAT_007cbf10 = DAT_007cbf10 + 1;
        uVar1 = *param_1;
      }
      else {
        uVar1 = 0xffffffff;
        if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> entry.id[%d] has been used!\r\n","wserv_db_ip_add",
                 0xcab,*param_1);
        }
      }
    }
    else {
      uVar1 = 0xffffffff;
      if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> uac_id_alloc fail!\r\n","wserv_db_ip_add",0xca5);
      }
    }
    FUN_00407f30(DAT_007cbef0);
    if (uVar1 == 0xffffffff) {
      FUN_004080f0(DAT_007cbf0c,*param_1);
    }
  }
  return uVar1;
}

