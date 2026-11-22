// func bcast_storm_ctrl_cfg_dump @ 0045f500 size=176

void bcast_storm_ctrl_cfg_dump(void)

{
  int iVar1;
  
  if (l_bcast_storm_ctrl_cfg != 0) {
    puts("-------------------broadcast storm control config information--------------------");
    printf("state of broadcast storm control(on:1,off:0):%u\n",
           *(undefined4 *)(l_bcast_storm_ctrl_cfg + 4));
    printf("rate of broadcast storm control(Kbps):%u\n",*(undefined4 *)(l_bcast_storm_ctrl_cfg + 8))
    ;
    puts("-------------------------------------end-----------------------------------------");
    return;
  }
  if ((bcast_storm_ctrl_cfg_warning_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[BCAST_STORM_CTRL_CFG_WARNING]%s()/line %d : config not init in memory yet.\n",
           "bcast_storm_ctrl_cfg_dump",0x124);
    return;
  }
  return;
}

