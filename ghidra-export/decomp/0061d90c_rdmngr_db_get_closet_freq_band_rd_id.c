// func rdmngr_db_get_closet_freq_band_rd_id @ 0061d90c size=344

uint rdmngr_db_get_closet_freq_band_rd_id(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_2f8 [16];
  ushort local_2e8;
  undefined4 local_2b8;
  undefined1 auStack_e0 [196];
  
  memset(auStack_2f8,0,0x2d8);
  iVar2 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2f8);
  if (iVar2 == 0) {
    iVar2 = apdb_radio_count_by_id(local_2b8,auStack_e0);
    if (iVar2 == -1) {
      uVar4 = 0xffffffff;
      if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d apdb_radio_count_by_id() fail.\n",
               "rdmngr_db_get_closet_freq_band_rd_id",0x8c6);
      }
    }
    else {
      uVar6 = 1;
      uVar4 = 0xffffffff;
      bVar1 = iVar2 < 1;
      while (!bVar1) {
        uVar5 = uVar6 & 0xf | (uint)local_2e8 << 4;
        iVar3 = rdmngr_db_get_rd_freq_band(uVar5);
        if (param_2 == iVar3) {
          param_3 = param_3 + -1;
          uVar4 = uVar5;
        }
        uVar6 = uVar6 + 1;
        if (param_3 < 1) {
          return uVar5;
        }
        bVar1 = iVar2 < (int)uVar6;
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() fail:%d.\n",
             "rdmngr_db_get_closet_freq_band_rd_id",0x8c0,param_1);
    }
  }
  return uVar4;
}

