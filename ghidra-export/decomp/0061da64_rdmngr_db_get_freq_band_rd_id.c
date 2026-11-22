// func rdmngr_db_get_freq_band_rd_id @ 0061da64 size=332

uint rdmngr_db_get_freq_band_rd_id(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_2f0 [16];
  ushort local_2e0;
  undefined4 local_2b0;
  undefined1 auStack_d8 [192];
  
  memset(auStack_2f0,0,0x2d8);
  iVar2 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2f0);
  if (iVar2 == 0) {
    uVar5 = 1;
    iVar2 = apdb_radio_count_by_id(local_2b0,auStack_d8);
    if (iVar2 == -1) {
      if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d apdb_radio_count_by_id() fail.\n",
               "rdmngr_db_get_freq_band_rd_id",0x8a2);
      }
    }
    else {
      bVar1 = iVar2 < 1;
      while (!bVar1) {
        uVar4 = uVar5 & 0xf | (uint)local_2e0 << 4;
        iVar3 = rdmngr_db_get_rd_freq_band(uVar4);
        param_3 = param_3 - (uint)(param_2 == iVar3);
        uVar5 = uVar5 + 1;
        if (param_3 < 1) {
          return uVar4;
        }
        bVar1 = iVar2 < (int)uVar5;
      }
    }
  }
  else if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() fail:%d.\n",
           "rdmngr_db_get_freq_band_rd_id",0x89c,param_1);
  }
  return 0xffffffff;
}

