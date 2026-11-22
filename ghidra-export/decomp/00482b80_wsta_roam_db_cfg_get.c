// func wsta_roam_db_cfg_get @ 00482b80 size=144

undefined4 wsta_roam_db_cfg_get(void *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0xffffffff;
    if (wsta_roam_warning_switch != '\0') {
      printf("[WSTA_ROAM_WARNING]%s()/%d cfg is null!\n","wsta_roam_db_cfg_get",0x43a);
    }
  }
  else {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    memcpy(param_1,&l_wsta_roam_cfg,0x22);
    uVar1 = 0;
    FUN_00407f30(l_wsta_roam_data);
  }
  return uVar1;
}

