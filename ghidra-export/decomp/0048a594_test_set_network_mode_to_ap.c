// func test_set_network_mode_to_ap @ 0048a594 size=1

undefined4 test_set_network_mode_to_ap(uint param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uStack_2f8;
  undefined4 uStack_2f4;
  int iStack_2f0;
  undefined4 uStack_2ec;
  undefined1 auStack_2e8 [728];
  
  uStack_2f8 = 0;
  uStack_2f4 = 0;
  iStack_2f0 = 0;
  uStack_2ec = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = serv_wtp_address_arg_init(&uStack_2f8);
  if (iVar1 == -1) {
    uVar4 = 1;
    if (wsta_roam_err_switch == '\0') {
      return 1;
    }
    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d serv arg init failed\n";
    uVar3 = 0xebe;
code_r0x0048a6c0:
    printf(pcVar2,"test_set_network_mode_to_ap",uVar3);
  }
  else {
    if (param_1 == 0xffffffff) {
      iVar1 = apmngr_db_get_all_addr_by_capacity(&uStack_2f8,1,1,0x15f0000,1,0x48);
      if ((iVar1 == 0) && (iStack_2f0 != 0)) {
code_r0x0048a640:
        if (wsta_roam_err_switch != '\0') {
          printf("[WSTA_ROAM_ERROR]%s()/%d _wstat_roam_update_wireless_network_mode_to_ap\n",
                 "test_set_network_mode_to_ap",0xede);
        }
        uVar4 = 0;
        iVar1 = _wsta_intelligent_roam_set_wireless_network_mode_send(&uStack_2f8);
        if ((iVar1 != -1) || (uVar4 = 1, wsta_roam_err_switch == '\0')) goto code_r0x0048a660;
        pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d send packet to AP failed\n";
        uVar3 = 0xee1;
      }
      else {
        uVar4 = 0;
        if (wsta_roam_err_switch == '\0') goto code_r0x0048a660;
        pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d no AP need to send configure\n";
        uVar3 = 0xec7;
      }
code_r0x0048a74c:
      printf(pcVar2,"test_set_network_mode_to_ap",uVar3);
    }
    else {
      iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2e8);
      if (iVar1 == -1) {
        uVar4 = 0xffffffff;
        if (wsta_roam_err_switch == '\0') {
          return 0xffffffff;
        }
        pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d get ap entry by id failed.\n";
        uVar3 = 0xed1;
        goto code_r0x0048a6c0;
      }
      iVar1 = apmngr_db_get_addr_by_capacity(param_1 & 0xffff,&uStack_2f8,1,1,0x15f0000,1,0x48);
      if ((iVar1 != -1) && (iStack_2f0 != 0)) goto code_r0x0048a640;
      uVar4 = 0;
      if (wsta_roam_err_switch != '\0') {
        pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d no AP need to send configure\n";
        uVar3 = 0xed7;
        goto code_r0x0048a74c;
      }
    }
code_r0x0048a660:
    serv_wtp_address_arg_destroy(&uStack_2f8);
  }
  return uVar4;
}

