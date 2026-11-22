// func band_navigation_db_init @ 0055fad0 size=584

undefined4 band_navigation_db_init(void)

{
  int iVar1;
  undefined4 local_a0;
  char *local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 *local_90;
  undefined4 local_8c;
  undefined2 local_88;
  undefined2 local_86;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  char *local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined2 local_64;
  undefined2 local_62;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  char *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  char *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  int local_18;
  undefined4 local_14;
  
  band_navigation_db_mutex = FUN_00407f00("band_navigation_rdt_mutex",1);
  if (band_navigation_db_mutex == 0) {
    if ((band_navigation_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BAND_NAVIGATION_ERR]%s()/%d Create database mutex failed.\n",
             "band_navigation_db_init",0x49);
    }
  }
  else {
    band_navigation_cfg = band_navigation_config_create();
    if (band_navigation_cfg == 0) {
      if ((band_navigation_err_switch != 0) &&
         (iVar1 = is_target_debug_ap(band_navigation_db_mutex), iVar1 != 0)) {
        printf("[BAND_NAVIGATION_ERR]%s()/%d create band_navigation_cfg failed.\n",
               "band_navigation_db_init",0x50);
      }
    }
    else {
      local_84 = band_navigation_cfg + 4;
      local_a0 = 0;
      local_98 = 0;
      local_80 = 0;
      local_74 = 0;
      local_6c = 0;
      local_78 = "5g_threshold";
      local_60 = band_navigation_cfg + 8;
      local_9c = "enable";
      local_90 = &onoff_map;
      local_58 = 2;
      local_94 = 1;
      local_88 = 1;
      local_8c = 10;
      local_54 = "dif_threshold";
      local_3c = band_navigation_cfg + 0xc;
      local_86 = 4;
      local_18 = band_navigation_cfg + 0x10;
      local_7c = 1;
      local_34 = 3;
      local_70 = 1;
      local_68 = 10;
      local_64 = 1;
      local_62 = 4;
      local_4c = 1;
      local_44 = 10;
      local_40 = 1;
      local_3e = 4;
      local_30 = "max_fail_num";
      local_5c = 0;
      local_50 = 0;
      local_48 = 0;
      local_38 = 0;
      local_2c = 0;
      local_28 = 1;
      local_20 = 10;
      local_1a = 4;
      local_24 = 0;
      local_1c = 1;
      local_14 = 0;
      iVar1 = FUN_00408120("apmng_band_navigation","settings",&local_a0,4);
      if (iVar1 == 0) {
        return 0;
      }
      if ((band_navigation_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[BAND_NAVIGATION_ERR]%s()/%d uci req parse failed.\n","band_navigation_db_init",100)
        ;
      }
      band_navigation_config_destroy(band_navigation_cfg);
      band_navigation_cfg = 0;
    }
    FUN_00408360(band_navigation_db_mutex);
    band_navigation_db_mutex = 0;
  }
  return 0xffffffff;
}

