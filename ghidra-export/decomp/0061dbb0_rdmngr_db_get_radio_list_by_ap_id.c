// func rdmngr_db_get_radio_list_by_ap_id @ 0061dbb0 size=488

int rdmngr_db_get_radio_list_by_ap_id
              (uint param_1,int param_2,int param_3,int *param_4,int param_5,int param_6,
              int *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_300 [16];
  ushort local_2f0;
  undefined4 local_2c0;
  undefined1 auStack_e8 [192];
  
  iVar4 = -1;
  memset(auStack_300,0,0x2d8);
  iVar1 = iVar4;
  if ((((param_2 != 0) && (iVar1 = -1, param_4 != (int *)0x0)) && (iVar1 = iVar4, param_5 != 0)) &&
     (param_7 != (int *)0x0)) {
    iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_300);
    if (iVar1 == 0) {
      iVar1 = apdb_radio_count_by_id(local_2c0,auStack_e8);
      if (iVar1 == -1) {
        if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[RDMNGR_ERROR]%s()/%d apdb_radio_count_by_id() fail.\n",
                 "rdmngr_db_get_radio_list_by_ap_id",0x875);
        }
      }
      else {
        uVar5 = 1;
        iVar2 = 0;
        iVar4 = 0;
        while ((int)uVar5 <= iVar1) {
          uVar6 = uVar5 & 0xf | (uint)local_2f0 << 4;
          iVar3 = rdmngr_db_get_rd_freq_band(uVar6);
          if (iVar3 == 0) {
            iVar3 = iVar4 * 4;
            if (param_3 <= iVar4) {
              return -1;
            }
            iVar4 = iVar4 + 1;
            *(uint *)(param_2 + iVar3) = uVar6;
            uVar5 = uVar5 + 1;
          }
          else if (iVar3 == 1) {
            iVar3 = iVar2 * 4;
            if (param_6 <= iVar2) {
              return -1;
            }
            uVar5 = uVar5 + 1;
            iVar2 = iVar2 + 1;
            *(uint *)(param_5 + iVar3) = uVar6;
          }
          else {
            uVar5 = uVar5 + 1;
          }
        }
        *param_4 = iVar4;
        *param_7 = iVar2;
      }
    }
    else {
      iVar1 = iVar4;
      if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() fail:%d.\n",
               "rdmngr_db_get_radio_list_by_ap_id",0x86f,param_1);
      }
    }
  }
  return iVar1;
}

