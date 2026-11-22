// func rdmngr_db_get_radio_cnt_by_ap_id @ 0061e338 size=392

int rdmngr_db_get_radio_cnt_by_ap_id(uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_2f8 [16];
  ushort local_2e8;
  undefined4 local_2b8;
  undefined1 auStack_e0 [196];
  
  memset(auStack_2f8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2f8);
  if (iVar1 == 0) {
    iVar1 = apdb_radio_count_by_id(local_2b8,auStack_e0);
    if (iVar1 == -1) {
      if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d apdb_radio_count_by_id() fail.\n",
               "rdmngr_db_get_radio_cnt_by_ap_id",0x843);
      }
    }
    else {
      uVar4 = 1;
      if ((param_2 != (int *)0x0) || (param_3 != (int *)0x0)) {
        iVar5 = 0;
        iVar2 = 0;
        while ((int)uVar4 <= iVar1) {
          iVar3 = rdmngr_db_get_rd_freq_band(uVar4 & 0xf | (uint)local_2e8 << 4);
          if (iVar3 == 0) {
            iVar2 = iVar2 + 1;
            uVar4 = uVar4 + 1;
          }
          else {
            iVar5 = iVar5 + (uint)(iVar3 == 1);
            uVar4 = uVar4 + 1;
          }
        }
        if (param_2 != (int *)0x0) {
          *param_2 = iVar2;
        }
        if (param_3 != (int *)0x0) {
          *param_3 = iVar5;
        }
      }
    }
  }
  else {
    iVar1 = -1;
    if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() fail:%d.\n",
             "rdmngr_db_get_radio_cnt_by_ap_id",0x83d,param_1);
    }
  }
  return iVar1;
}

