// func rdmngr_db_next_rd_entry_get @ 0061eee8 size=1

undefined4 rdmngr_db_next_rd_entry_get(uint param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_350;
  undefined4 auStack_34c [21];
  undefined1 auStack_2f8 [16];
  ushort uStack_2e8;
  int iStack_2bc;
  undefined4 uStack_2b8;
  undefined2 uStack_2b4;
  undefined2 uStack_2b2;
  undefined1 auStack_e0 [192];
  
  memset(auStack_2f8,0,0x2d8);
  uStack_350 = 0;
  memset(auStack_34c,0,0x54);
  iVar1 = apmngr_db_entry_get_by_id((param_1 << 0xc) >> 0x10,auStack_2f8);
  if (iVar1 != -1) {
    param_1 = param_1 & 0xf;
    do {
      if (iStack_2bc != 0) {
        uStack_350 = CONCAT22(uStack_2b4,uStack_2b2);
        iVar1 = rdmngr_db_get_ap_radio_cnt(uStack_2b8,auStack_e0,&uStack_350);
        if (iVar1 < 0) {
          if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(uStack_2e8), iVar3 != 0)) {
            printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
                   "rdmngr_db_next_rd_entry_get",0x1082,iVar1);
          }
        }
        else {
          uVar2 = (uint)uStack_2e8;
          if ((int)param_1 < iVar1) {
            memset(auStack_34c,0,0x54);
            iVar1 = rdmngr_db_rd_entry_get(param_1 + 1 & 0xf | uVar2 << 4,auStack_34c);
            if (iVar1 == 0) {
              FUN_004082d0(DAT_007cc64c,0xffffffff);
              memcpy(param_2,auStack_34c,0x54);
              FUN_00407f30(DAT_007cc64c);
              if (rdmngr_debug_switch == 0) {
                return 0;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return 0;
              }
              printf("[RDMNGR_DEBUG]%s()/%d rd_id is %d\n","rdmngr_db_next_rd_entry_get",0x1094,
                     auStack_34c[0]);
              return 0;
            }
            if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(uStack_2e8), iVar1 != 0)) {
              printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_entry_get() failed.\n",
                     "rdmngr_db_next_rd_entry_get",0x108e);
            }
          }
          else {
            param_1 = 0;
          }
        }
      }
      iVar1 = apmngr_db_entry_next_get(uStack_2e8,auStack_2f8);
    } while (iVar1 == 0);
  }
  return 0xffffffff;
}

