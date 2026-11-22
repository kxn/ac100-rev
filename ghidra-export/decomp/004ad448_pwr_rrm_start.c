// func pwr_rrm_start @ 004ad448 size=556

undefined4 pwr_rrm_start(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_68 [80];
  
  iVar1 = rrm_db_state_get();
  memcpy(auStack_68,&g_collect_ctl,0x4c);
  if ((((iVar1 != 0) && (iVar1 != 7)) && (iVar1 != 3)) && (iVar1 != 6)) {
    if (rrm_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[RRM_ERROR]%s()/%d You can\'t do rrm in state(%d),please wait for a moment\n",
           "pwr_rrm_start",0x65e,iVar1);
    return 0xffffffff;
  }
  iVar1 = get_wireless_cur_network_mode();
  if (iVar1 != 2) {
    if (rrm_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[RRM_ERROR]%s()/%d not support pwr rrm when ap mode isn\'t default mode\n",
           "pwr_rrm_start",0x664);
    return 0xffffffff;
  }
  iVar1 = 0;
  mesh_db_mesh_enable_get(auStack_68);
  if (g_pwr_enable == 0) {
    return 0;
  }
  rrm_db_state_set(4);
  if (param_1 != 0) {
    uVar2 = apmngr_db_get_ap_max();
    piVar4 = (int *)&ap_pwr_para;
    rrm_destroy_ap_pwr_para_all();
    do {
      iVar3 = rrm_ap_pwr_para_create(uVar2,iVar1);
      *piVar4 = iVar3;
      if (iVar3 == 0) goto LAB_004ad660;
      iVar1 = iVar1 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar1 != 3);
    apmngr_db_foreach_proc(0xf0000,rrm_pwr_collect_active_ap,auStack_68);
    if (((*ap_pwr_para < 1) && (*DAT_00767bf0 < 1)) && (*DAT_00767bf4 < 1)) {
      uVar2 = 0xfffffffd;
      rrm_db_state_set(7);
      goto LAB_004ad5ec;
    }
  }
  rrm_pkt_pwr_ctl_update_to_all_ap();
  if (rrm_collect_timer != -1) {
    FUN_00408060();
  }
  rrm_collect_timer = FUN_00408340(rrm_collect_time,0,rrm_timeout,0,0,"pwr_rrm_start",0x691);
  if (rrm_collect_timer != -1) {
    return 0;
  }
LAB_004ad660:
  uVar2 = 0xffffffff;
  rrm_db_state_set(7);
LAB_004ad5ec:
  rrm_destroy_ap_pwr_para_all();
  return uVar2;
}

