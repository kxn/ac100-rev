// func wsta_roam_db_sta_tmprcd_add @ 00482864 size=372

undefined4 wsta_roam_db_sta_tmprcd_add(void *param_1)

{
  void *pvVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  if (param_1 == (void *)0x0) {
    return 0xffffffff;
  }
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  pvVar1 = (void *)FUN_00407fa0(DAT_00767560,param_1);
  if (pvVar1 != (void *)0x0) {
    uVar4 = 0;
    memcpy(pvVar1,param_1,0x40);
    goto LAB_004828c8;
  }
  iVar2 = FUN_00407ed0(DAT_00767560);
  if (iVar2 < max_roam_sta) {
    pvVar1 = (void *)FUN_004082a0(1,0x40,0x3d8);
    if (pvVar1 != (void *)0x0) {
      memcpy(pvVar1,param_1,0x40);
      uVar4 = 0;
      iVar2 = FUN_00408380(DAT_00767560,pvVar1);
      if (iVar2 != 0) {
        if (wsta_roam_err_switch != '\0') {
          printf("[WSTA_ROAM_ERROR]%s()/%d uac_hash_add() fail!\n","wsta_roam_db_sta_tmprcd_add",
                 0x3e2);
        }
        FUN_00407df0(pvVar1);
        uVar4 = 0xffffffff;
      }
      goto LAB_004828c8;
    }
    if (wsta_roam_err_switch == '\0') goto LAB_004828c8;
    __format = "[WSTA_ROAM_ERROR]%s()/%d malloc fail!\n";
    uVar3 = 0x3db;
  }
  else {
    if (wsta_roam_warning_switch == '\0') goto LAB_004828c8;
    __format = "[WSTA_ROAM_WARNING]%s()/%d entry is full!\n";
    uVar3 = 0x3d4;
  }
  printf(__format,"wsta_roam_db_sta_tmprcd_add",uVar3);
LAB_004828c8:
  FUN_00407f30(l_wsta_roam_data);
  return uVar4;
}

