// func test_begin_acs @ 0048a3a8 size=492

undefined4 test_begin_acs(uint param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_2f8;
  undefined4 local_2f4;
  int local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [732];
  
  memset(auStack_2e8,0,0x2d8);
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  iVar1 = serv_wtp_address_arg_init(&local_2f8);
  if (iVar1 == -1) {
    uVar4 = 1;
    if (wsta_roam_err_switch == '\0') {
      return 1;
    }
    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d serv arg init failed\n";
    uVar3 = 0xe8a;
LAB_0048a4cc:
    printf(pcVar2,"test_begin_acs",uVar3);
  }
  else {
    if (param_1 == 0xffffffff) {
      iVar1 = apmngr_db_get_all_addr_by_capacity(&local_2f8,1,1,0x15f0000,1,0x48);
      if ((iVar1 == 0) && (local_2f0 != 0)) {
LAB_0048a450:
        uVar4 = 0;
        iVar1 = _wsta_intelligent_roam_start_acs_send(&local_2f8,auStack_2e8);
        if ((iVar1 != -1) || (uVar4 = 1, wsta_roam_err_switch == '\0')) goto LAB_0048a468;
        pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d send packet to AP failed\n";
        uVar3 = 0xeac;
      }
      else {
        uVar4 = 0;
        if (wsta_roam_err_switch == '\0') goto LAB_0048a468;
        pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d no AP need to send configure\n";
        uVar3 = 0xe94;
      }
LAB_0048a560:
      printf(pcVar2,"test_begin_acs",uVar3);
    }
    else {
      iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2e8);
      if (iVar1 == -1) {
        uVar4 = 0xffffffff;
        if (wsta_roam_err_switch == '\0') {
          return 0xffffffff;
        }
        pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d get ap entry by id failed.\n";
        uVar3 = 0xe9e;
        goto LAB_0048a4cc;
      }
      iVar1 = apmngr_db_get_addr_by_capacity(param_1 & 0xffff,&local_2f8,1,1,0x15f0000,1,0x48);
      if ((iVar1 != -1) && (local_2f0 != 0)) goto LAB_0048a450;
      uVar4 = 0;
      if (wsta_roam_err_switch != '\0') {
        pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d no AP need to send configure\n";
        uVar3 = 0xea4;
        goto LAB_0048a560;
      }
    }
LAB_0048a468:
    serv_wtp_address_arg_destroy(&local_2f8);
  }
  return uVar4;
}

