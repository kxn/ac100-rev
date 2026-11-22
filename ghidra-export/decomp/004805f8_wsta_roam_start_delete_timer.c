// func wsta_roam_start_delete_timer @ 004805f8 size=96

undefined4 wsta_roam_start_delete_timer(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
    if (wsta_roam_err_switch != '\0') {
      printf("[WSTA_ROAM_ERROR]%s()/%d inputs error.\n","wsta_roam_start_delete_timer",0x15f);
    }
  }
  else {
    uVar1 = 0;
    wsta_roam_db_pmk_start_del_timer(param_1 + 0x68);
  }
  return uVar1;
}

