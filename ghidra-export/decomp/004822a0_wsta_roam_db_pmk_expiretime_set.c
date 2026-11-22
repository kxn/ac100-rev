// func wsta_roam_db_pmk_expiretime_set @ 004822a0 size=160

undefined4 wsta_roam_db_pmk_expiretime_set(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (wsta_roam_warning_switch != '\0') {
      printf("[WSTA_ROAM_WARNING]%s()/%d mac is null!\n","wsta_roam_db_pmk_expiretime_set",0x332);
    }
  }
  else {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    iVar1 = FUN_00407fa0(DAT_0076754c,param_1);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x48) = param_2;
    }
    uVar2 = 0;
    FUN_00407f30(l_wsta_roam_data);
  }
  return uVar2;
}

