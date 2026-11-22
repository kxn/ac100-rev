// func _autorrm_tmo_handle @ 004ad674 size=624

void _autorrm_tmo_handle(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = rrm_db_state_get();
  if (rrm_debug_switch != '\0') {
    printf("[RRM_DEBUG]%s()/%d Warning: autorrm timer timeout, do RRM.\n","_autorrm_tmo_handle",
           0x898);
  }
  if ((iVar1 == 0) || (iVar1 == 7)) {
    if (g_chnl_enable == 0) {
      if (g_pwr_enable == 0) {
        uVar2 = 0x397f;
      }
      else {
        iVar1 = uac_wserv_send_pkt_check(0x55);
        if (iVar1 != 0) {
          if (rrm_debug_switch != '\0') {
            printf("[RRM_DEBUG]%s()/%d You can\'t do rrm while radio or wireless operation\n",
                   "_autorrm_tmo_handle",0x8b0);
          }
          uVar2 = 0x8b1;
          goto LAB_004ad838;
        }
        iVar1 = pwr_rrm_start(1);
        if (iVar1 != 0) goto LAB_004ad6d0;
        pwr_rrm_count = pwr_rrm_count + 1;
        rrm_type = 2;
        rrm_callback_proc(0);
        uVar2 = 0x397b;
      }
    }
    else {
      iVar1 = uac_wserv_send_pkt_check();
      if (iVar1 != 0) {
        if (rrm_debug_switch != '\0') {
          printf("[RRM_DEBUG]%s()/%d You can\'t do rrm while radio or wireless operation\n",
                 "_autorrm_tmo_handle",0x8a1);
        }
        uVar2 = 0x8a2;
LAB_004ad838:
        g_autorrm_timer = FUN_00408340(10,0,_autorrm_tmo_handle,0,0,"_autorrm_tmo_handle",uVar2);
        return;
      }
      iVar1 = chnl_rrm_start();
      if (iVar1 != 0) goto LAB_004ad6d0;
      rrm_type = 2;
      rrm_callback_proc(0);
      uVar2 = 0x3978;
    }
    loggerk_reg(0x55,uVar2,0);
  }
  else if (rrm_debug_switch != '\0') {
    printf("[RRM_DEBUG]%s()/%d You can\'t do rrm in state(%d),please wait for a moment\n",
           "_autorrm_tmo_handle",0x89b,iVar1);
  }
LAB_004ad6d0:
  uVar2 = _autorrm_tmo_caculate(1,g_autorrm_date,&g_autorrm_time);
  g_autorrm_timer = FUN_00408340(uVar2,0,_autorrm_tmo_handle,0,0,"_autorrm_tmo_handle",0x8c1);
  if (rrm_debug_switch == '\0') {
    return;
  }
  printf("[RRM_DEBUG]%s()/%d start a timer waiting %ld seconds to timeout.\n","_autorrm_tmo_handle",
         0x8c2,uVar2);
  return;
}

