// func rdmngr_db_rd_entry_max_ssid_get @ 0061f9e0 size=244

undefined4 rdmngr_db_rd_entry_max_ssid_get(uint param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_2e8 [64];
  undefined4 local_2a8;
  undefined1 auStack_d0 [192];
  
  uVar3 = (param_1 << 4) >> 8;
  iVar1 = apmngr_db_entry_get_by_id(uVar3 & 0xffff,auStack_2e8);
  if (iVar1 == -1) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() fail, ap_id=%d.\n";
    uVar2 = 0x10cc;
  }
  else {
    iVar1 = rdmngr_db_get_rd_freq_band(param_1);
    if (iVar1 != -1) {
      uVar2 = apdb_get_max_ssid_by_id(local_2a8,auStack_d0,param_1 & 0xf,iVar1);
      return uVar2;
    }
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_get_rd_freq_band() fail, rd_id=%d.\n";
    uVar2 = 0x10d1;
    uVar3 = param_1;
  }
  printf(__format,"rdmngr_db_rd_entry_max_ssid_get",uVar2,uVar3);
  return 0xffffffff;
}

