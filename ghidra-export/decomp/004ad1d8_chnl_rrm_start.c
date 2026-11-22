// func chnl_rrm_start @ 004ad1d8 size=624

undefined4 chnl_rrm_start(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 local_68 [20];
  
  iVar1 = rrm_db_state_get();
  memcpy(local_68,&g_collect_ctl,0x4c);
  if ((iVar1 == 0) || (iVar1 == 7)) {
    uVar3 = 0;
    mesh_db_mesh_enable_get(local_68);
    if (g_chnl_enable != 0) {
      iVar1 = wsta_intelligent_roam_do_acs();
      if (iVar1 == 0) {
        if (rrm_acs_timer != -1) {
          FUN_00408060();
        }
        iVar1 = get_acs_timeout();
        rrm_acs_timer = FUN_00408340(iVar1 + 6,0,rrm_acs_timeout,0,0,"chnl_rrm_start",0x61b);
        if (rrm_acs_timer == -1) {
          uVar3 = 0xffffffff;
          rrm_db_state_set(7);
        }
        else {
          uVar3 = 0;
          rrm_db_state_set(3);
          rrm_acs_time = 0;
        }
      }
      else {
        rrm_db_state_set(1);
        iVar1 = 0;
        piVar4 = (int *)&ap_para;
        uVar3 = apmngr_db_get_ap_max();
        rrm_destroy_ap_para_all();
        do {
          iVar2 = rrm_ap_para_create(uVar3,iVar1);
          *piVar4 = iVar2;
          if (iVar2 == 0) goto LAB_004ad420;
          iVar1 = iVar1 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar1 != 3);
        apmngr_db_foreach_proc(0xf0000,rrm_collect_active_ap,local_68);
        if (((*ap_para < 1) && (*DAT_00767bfc < 1)) && (*DAT_00767c00 < 1)) {
          uVar3 = 0xfffffffd;
          rrm_db_state_set(7);
        }
        else {
          rrm_pkt_chnl_ctl_update_to_all_ap(local_68[0]);
          if (rrm_collect_timer != -1) {
            FUN_00408060();
          }
          rrm_collect_timer =
               FUN_00408340(rrm_collect_time,0,rrm_timeout,0,0,"chnl_rrm_start",0x648);
          if (rrm_collect_timer != -1) {
            return 0;
          }
LAB_004ad420:
          uVar3 = 0xffffffff;
          rrm_db_state_set(7);
        }
        rrm_destroy_ap_para_all();
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
    if (rrm_err_switch != '\0') {
      printf("[RRM_ERROR]%s()/%d You can\'t do rrm in state(%d),please wait for a moment\n",
             "chnl_rrm_start",0x60c,iVar1);
    }
  }
  return uVar3;
}

