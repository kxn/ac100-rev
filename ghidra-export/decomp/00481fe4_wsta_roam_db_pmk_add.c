// func wsta_roam_db_pmk_add @ 00481fe4 size=528

undefined4 wsta_roam_db_pmk_add(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  
  if (param_1 == 0) {
    if (wsta_roam_warning_switch == '\0') {
      return 0xffffffff;
    }
    printf("[WSTA_ROAM_WARNING]%s()/%d entry is null!\n","wsta_roam_db_pmk_add",0x2e4);
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 8) < 0) ||
     (uVar1 = wserv_profile_get_max_wservice(), uVar1 <= *(uint *)(param_1 + 8))) {
    if (wsta_roam_warning_switch == '\0') {
      return 0xffffffff;
    }
    printf("[WSTA_ROAM_WARNING]%s()/%d invalid wserv_id[%d]!\n","wsta_roam_db_pmk_add",0x2ea,
           *(undefined4 *)(param_1 + 8));
    return 0xffffffff;
  }
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  iVar2 = FUN_00407fa0(DAT_0076754c,param_1 + 0x10);
  if (iVar2 == 0) {
    iVar2 = FUN_004085b0(DAT_00767544);
    if (iVar2 == -1) {
      uVar5 = 2;
      if (wsta_roam_warning_switch != '\0') {
        printf("[WSTA_ROAM_WARNING]%s()/%d uac_id_alloc() fail!\n","wsta_roam_db_pmk_add",0x2f9);
      }
      goto LAB_004820bc;
    }
    piVar6 = (int *)(DAT_00767548 + iVar2 * 0x4c);
    if (*piVar6 == 0) {
      memcpy((void *)(DAT_00767548 + iVar2 * 0x4c + 8),(void *)(param_1 + 8),0x44);
      uVar5 = DAT_0076754c;
      *piVar6 = 1;
      piVar6[1] = iVar2;
      iVar3 = FUN_00408380(uVar5,piVar6);
      if (iVar3 == 0) {
        DAT_00767550 = DAT_00767550 + 1;
        goto LAB_004820b8;
      }
      uVar5 = 0xffffffff;
      if (wsta_roam_err_switch == '\0') goto LAB_004820bc;
      __format = "[WSTA_ROAM_ERROR]%s()/%d uac_hash_add() fail, wsra_id = %d!\n";
      uVar4 = 0x308;
    }
    else {
      uVar5 = 0xffffffff;
      if (wsta_roam_warning_switch == '\0') goto LAB_004820bc;
      __format = "[WSTA_ROAM_WARNING]%s()/%d entry.id[%d] has been used!\n";
      uVar4 = 0x300;
    }
    uVar5 = 0xffffffff;
    printf(__format,"wsta_roam_db_pmk_add",uVar4,iVar2);
  }
  else {
    memcpy((void *)(iVar2 + 8),(void *)(param_1 + 8),0x44);
LAB_004820b8:
    uVar5 = 0;
  }
LAB_004820bc:
  FUN_00407f30(l_wsta_roam_data);
  return uVar5;
}

