// func _apmngr_pkt_echo_req_listen @ 0055afe4 size=692

/* WARNING: Type propagation algorithm not settling */

undefined4 _apmngr_pkt_echo_req_listen(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_308 [6];
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0;
  int local_2dc;
  char local_1c0;
  int local_138;
  char local_134;
  uint local_9c;
  int local_68;
  int local_64;
  
  memset(auStack_2f0,0,0x2d8);
  local_308[0] = 1;
  iVar1 = apmngr_db_entry_get_by_mac(param_2,auStack_2f0);
  if (iVar1 == 0) {
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d Get echo request packet.\n","_apmngr_pkt_echo_req_listen",0x794)
      ;
    }
    piVar2 = (int *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x38);
    uVar3 = 0;
    if (piVar2 != (int *)0x0) {
      if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APMNGR_DEBUG]%s()/%d Update AP\'s led info.\n","_apmngr_pkt_echo_req_listen",0x79c)
        ;
      }
      if ((local_64 == 0) && (iVar1 = multi_link_status_get(local_2e0), iVar1 == 1)) {
        local_308[1] = 0;
        local_308[2] = 0;
        local_308[3] = 0;
        local_308[4] = 0;
        iVar1 = serv_wtp_address_arg_init(local_308 + 1);
        if (iVar1 != 0) {
          serv_wtp_address_arg_destroy(local_308 + 1);
          return 0xffffffff;
        }
        serv_wtp_address_arg_add
                  (local_308 + 1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                   *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                   *(undefined4 *)(param_2 + 0x20),*(undefined2 *)(param_2 + 0x24),param_2,
                   local_2dc == 5);
        if (local_134 == '\0') {
          local_308[0] = local_138;
        }
        else {
          apmngr_led_timer_start(local_2e0,local_308);
        }
        apmngr_pkt_led_pkt_send(local_308 + 1,local_308[0]);
        serv_wtp_address_arg_destroy(local_308 + 1);
        apmngr_db_ap_ledsent_set(local_2e0,1);
        uVar3 = 1;
        if (local_308[0] == 0) {
          uVar3 = 2;
        }
        apmngr_db_ap_led_update(local_2e0,uVar3);
        if ((local_9c & 0x400) == 0) {
          return 0;
        }
        if (local_308[0] != 0) {
          return 0;
        }
      }
      else {
        if (local_2dc == 7) {
          return 0;
        }
        iVar1 = 2;
        uVar3 = 1;
        if (*piVar2 == 0) {
          uVar3 = 2;
        }
        apmngr_db_ap_led_update(local_2e0,uVar3);
        if ((local_9c & 0x400) == 0) {
          return 0;
        }
        if (*piVar2 != 0) {
          iVar1 = 1;
        }
        if (local_68 == iVar1) {
          return 0;
        }
      }
      uVar3 = 0;
      if (local_1c0 != '\0') {
        apmngr_evt_notify(6,auStack_2f0);
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_WARNING]%s()/%d Cannot find the ap entry.\n","_apmngr_pkt_echo_req_listen",
             0x790);
    }
  }
  return uVar3;
}

