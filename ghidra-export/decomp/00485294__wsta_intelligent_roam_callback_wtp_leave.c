// func _wsta_intelligent_roam_callback_wtp_leave @ 00485294 size=656

undefined4 _wsta_intelligent_roam_callback_wtp_leave(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_80;
  int local_7c [15];
  short local_40;
  char local_34;
  
  local_80 = 0;
  memset(local_7c,0,0x54);
  memset(local_7c,0,0x54);
  if (param_1 == 0) {
    uVar5 = 0xffffffff;
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar3 = "[WSTA_ROAM_ERROR]%s()/%d inputs error.\n";
    uVar4 = 0xdd0;
  }
  else {
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar6 = 1;
      local_80 = *(undefined4 *)(param_1 + 0x44);
      iVar1 = rdmngr_db_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_80);
      if (iVar1 < 0) {
        if (wsta_roam_err_switch == '\0') {
          return 0xffffffff;
        }
        printf("[WSTA_ROAM_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
               "_wsta_intelligent_roam_callback_wtp_leave",0xde1,iVar1);
        return 0xffffffff;
      }
LAB_00485388:
      do {
        while( true ) {
          if (iVar1 < iVar6) {
            return 0;
          }
          uVar5 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar6);
          memset(local_7c,0,0x54);
          iVar2 = rdmngr_db_rd_entry_get(uVar5,local_7c);
          if (iVar2 == 0) break;
          if (wsta_roam_err_switch == '\0') {
            iVar6 = iVar6 + 1;
          }
          else {
            uVar5 = 0xdec;
            pcVar3 = "[WSTA_ROAM_ERROR]%s()/%d rdmngr_db_rd_entry_get() failed.\n";
LAB_004853ec:
            printf(pcVar3,"_wsta_intelligent_roam_callback_wtp_leave",uVar5);
            iVar6 = iVar6 + 1;
          }
        }
        if (wsta_roam_debug_switch != '\0') {
          printf("[WSTA_ROAM_DEBUG]%s()/%d rd_id is %d\n",
                 "_wsta_intelligent_roam_callback_wtp_leave",0xdf0,local_7c[0]);
        }
        if (local_7c[0] != -1) {
          if (wsta_roam_debug_switch != '\0') {
            printf("[WSTA_ROAM_DEBUG]%s()/%d rd_entry.rd_cfg.rdState = %d, rd_entry.rd_cfg.realChnl = %d\n"
                   ,"_wsta_intelligent_roam_callback_wtp_leave",0xdf8,(int)local_34,(int)local_40);
          }
          if (local_34 == '\x01') {
            rdmngr_working_channel_set_update((int)local_40,0xffffffff);
            local_40 = -1;
            rdmngr_db_rd_entry_set(local_7c);
            iVar6 = iVar6 + 1;
          }
          else {
            iVar6 = iVar6 + 1;
          }
          goto LAB_00485388;
        }
        if (wsta_roam_debug_switch != '\0') {
          uVar5 = 0xdf4;
          pcVar3 = "[WSTA_ROAM_DEBUG]%s()/%d Invalid rd entry.\n";
          goto LAB_004853ec;
        }
        iVar6 = iVar6 + 1;
      } while( true );
    }
    uVar5 = 0;
    if (wsta_roam_debug_switch == '\0') {
      return 0;
    }
    pcVar3 = "[WSTA_ROAM_DEBUG]%s()/%d wtp is template, don\'t delete it.\n";
    uVar4 = 0xdd7;
  }
  printf(pcVar3,"_wsta_intelligent_roam_callback_wtp_leave",uVar4);
  return uVar5;
}

