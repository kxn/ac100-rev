// func wsta_roam_db_pmk_start_del_timer @ 004821f4 size=172

undefined4 wsta_roam_db_pmk_start_del_timer(int param_1)

{
  int iVar1;
  int extraout_v1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (wsta_roam_warning_switch != '\0') {
      printf("[WSTA_ROAM_WARNING]%s()/%d mac is null!\n","wsta_roam_db_pmk_start_del_timer",0x319);
    }
  }
  else {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    uVar2 = 0xffffffff;
    iVar1 = FUN_00407fa0(DAT_0076754c,param_1);
    if (iVar1 != 0) {
      uVar2 = 0;
      FUN_00407e70();
      *(int *)(iVar1 + 0x48) = extraout_v1 + 0x3c;
    }
    FUN_00407f30(l_wsta_roam_data);
  }
  return uVar2;
}

