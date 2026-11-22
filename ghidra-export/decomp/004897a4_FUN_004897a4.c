// func FUN_004897a4 @ 004897a4 size=396

undefined4 FUN_004897a4(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_2f8;
  undefined4 local_2f4;
  int local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar4 = 0xa01;
LAB_004898fc:
    printf(pcVar2,"local_wsta_intelligent_roam_set_params",uVar4);
    return 0xffffffff;
  }
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  iVar1 = serv_wtp_address_arg_init(&local_2f8);
  if (iVar1 == -1) {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d serv arg init failed\n";
    uVar4 = 0xa08;
    goto LAB_004898fc;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(local_2d8,&local_2f8,1,1,0x15f0000,1,0x19);
  if ((iVar1 == -1) || (local_2f0 == 0)) {
    uVar4 = 0;
    if (wsta_roam_debug_switch == '\0') goto LAB_00489864;
    pcVar2 = "[WSTA_ROAM_DEBUG]%s()/%d no AP need to send configure\n";
    uVar3 = 0xa0f;
  }
  else {
    uVar4 = 0;
    iVar1 = _wsta_intelligent_roam_ctl_packet_send(&local_2f8);
    if ((iVar1 != -1) || (uVar4 = 0xffffffff, wsta_roam_err_switch == '\0')) goto LAB_00489864;
    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d send packet to AP failed\n";
    uVar3 = 0xa16;
  }
  printf(pcVar2,"local_wsta_intelligent_roam_set_params",uVar3);
LAB_00489864:
  serv_wtp_address_arg_destroy(&local_2f8);
  return uVar4;
}

