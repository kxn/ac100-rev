// func band_navigation_init @ 0055f964 size=356

undefined4 band_navigation_init(void)

{
  int iVar1;
  char *__format;
  char *pcVar2;
  undefined4 uVar3;
  char *local_18;
  undefined4 local_14;
  code *local_10;
  undefined4 local_c;
  
  iVar1 = band_navigation_db_init();
  if (iVar1 != 0) {
    if (band_navigation_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[BAND_NAVIGATION_ERR]%s()/%d init band navigation database failed\n",
           "band_navigation_init",0x14b);
    return 0xffffffff;
  }
  iVar1 = FUN_004084d0("apmng_band_navigation",2,band_navigation_jcs_set);
  if (iVar1 == 0) {
    local_c = 0;
    local_18 = "band navigation";
    local_14 = 0x64000000;
    local_10 = band_navigation_wtp_packt_send;
    iVar1 = multi_link_reg(&local_18);
    if (iVar1 != -1) {
      apmngr_support_capacity_register(3);
      udbg_help_register("band_navigation","band_navigation_debug_help()");
      return 0;
    }
    if ((band_navigation_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_0055fa54;
    __format = "[BAND_NAVIGATION_ERR]%s()/%d register callback to multi link failed.\n";
    pcVar2 = "band_navigation_multilink_callback_init";
    uVar3 = 0x12d;
  }
  else {
    if ((band_navigation_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_0055fa54;
    __format = "[BAND_NAVIGATION_ERR]%s()/%d register callback to jcs failed\n";
    pcVar2 = "band_navigation_init";
    uVar3 = 0x152;
  }
  printf(__format,pcVar2,uVar3);
LAB_0055fa54:
  band_navigation_db_destroy();
  return 0xffffffff;
}

