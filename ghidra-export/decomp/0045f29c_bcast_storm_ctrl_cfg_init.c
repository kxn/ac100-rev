// func bcast_storm_ctrl_cfg_init @ 0045f29c size=536

undefined4 bcast_storm_ctrl_cfg_init(void)

{
  int iVar1;
  void *__s;
  int iVar2;
  undefined4 local_58;
  char *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
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
  
  iVar1 = FUN_00407f00("bcast_storm_ctrl_cfg_mutex",1);
  if (((iVar1 == 0) && (bcast_storm_ctrl_cfg_err_switch != 0)) &&
     (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : create mutex failed.\n",
           "_bcast_storm_ctrl_cfg_mutex_init",0x57);
  }
  l_bcast_storm_ctrl_cfg_mutex = iVar1;
  if (iVar1 != 0) {
    __s = (void *)FUN_00408450(0xc,0x6f);
    if (__s == (void *)0x0) {
      if ((bcast_storm_ctrl_cfg_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : malloc for l_bcast_storm_ctrl_cfg failed.\n"
               ,"_bcast_storm_ctrl_cfg_create",0x72);
      }
    }
    else {
      memset(__s,0,0xc);
    }
    l_bcast_storm_ctrl_cfg = __s;
    if (__s != (void *)0x0) {
      local_3c = (int)__s + 4;
      local_58 = 0;
      local_50 = 0;
      local_44 = 10;
      local_20 = 10;
      local_38 = 0;
      local_30 = "storm_rate";
      local_2c = 0;
      local_54 = "enable";
      local_48 = &onoff_map;
      local_24 = 0;
      local_14 = 0;
      local_18 = (int)__s + 8;
      local_4c = 1;
      local_40 = 1;
      local_3e = 4;
      local_34 = 1;
      local_28 = 1;
      local_1c = 1;
      local_1a = 4;
      iVar1 = FUN_00408120("apmng_bcast_storm_ctrl","settings",&local_58,2);
      if (iVar1 == 0) {
        bcast_storm_ctrl_debug_init();
        return 0;
      }
      if ((bcast_storm_ctrl_cfg_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : uci req parse failed.\n",
               "_bcast_storm_ctrl_cfg_load",0x9a);
      }
    }
    if (l_bcast_storm_ctrl_cfg_mutex != 0) {
      FUN_00408360();
      l_bcast_storm_ctrl_cfg_mutex = 0;
    }
    _bcast_storm_ctrl_cfg_destroy(l_bcast_storm_ctrl_cfg);
    l_bcast_storm_ctrl_cfg = (void *)0x0;
  }
  return 0xffffffff;
}

