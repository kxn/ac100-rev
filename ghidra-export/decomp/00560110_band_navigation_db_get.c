// func band_navigation_db_get @ 00560110 size=180

undefined4 band_navigation_db_get(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((band_navigation_cfg == (void *)0x0) || (param_1 == (void *)0x0)) {
    uVar2 = 0xffffffff;
    if ((band_navigation_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BAND_NAVIGATION_ERR]%s()/%d band navigation global cfg or band_navigation_config_obj to be set is NULL\n"
             ,"band_navigation_db_get",0x140);
    }
  }
  else {
    FUN_004082d0(band_navigation_db_mutex,0xffffffff);
    uVar2 = 0;
    memcpy(param_1,band_navigation_cfg,0x14);
    FUN_00407f30(band_navigation_db_mutex);
  }
  return uVar2;
}

