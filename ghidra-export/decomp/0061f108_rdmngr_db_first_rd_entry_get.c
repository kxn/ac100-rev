// func rdmngr_db_first_rd_entry_get @ 0061f108 size=1

undefined4 rdmngr_db_first_rd_entry_get(void *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_358;
  undefined4 auStack_354 [21];
  undefined1 auStack_300 [16];
  ushort uStack_2f0;
  int iStack_2c4;
  undefined4 uStack_2c0;
  undefined2 uStack_2bc;
  undefined2 uStack_2ba;
  undefined1 auStack_e8 [196];
  
  memset(auStack_300,0,0x2d8);
  uStack_358 = 0;
  memset(auStack_354,0,0x54);
  iVar1 = apmngr_db_first_ap_get(auStack_300);
  if (iVar1 != -1) {
    do {
      if (iStack_2c4 != 0) {
        uVar4 = 1;
        uStack_358 = CONCAT22(uStack_2bc,uStack_2ba);
        iVar1 = rdmngr_db_get_ap_radio_cnt(uStack_2c0,auStack_e8,&uStack_358);
        if (iVar1 < 0) {
          if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(uStack_2f0), iVar2 != 0)) {
            printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
                   "rdmngr_db_first_rd_entry_get",0x1053,iVar1);
          }
        }
        else {
          while ((int)uVar4 <= iVar1) {
            uVar3 = (uint)uStack_2f0;
            memset(auStack_354,0,0x54);
            iVar2 = rdmngr_db_rd_entry_get(uVar4 & 0xf | uVar3 << 4,auStack_354);
            if (iVar2 == 0) {
              FUN_004082d0(DAT_007cc64c,0xffffffff);
              memcpy(param_1,auStack_354,0x54);
              FUN_00407f30(DAT_007cc64c);
              if (rdmngr_debug_switch == 0) {
                return 0;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return 0;
              }
              printf("[RDMNGR_DEBUG]%s()/%d rd_id is %d\n","rdmngr_db_first_rd_entry_get",0x1062,
                     auStack_354[0]);
              return 0;
            }
            if (rdmngr_err_switch == 0) {
              uVar4 = uVar4 + 1;
            }
            else {
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                uVar4 = uVar4 + 1;
              }
              else {
                printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_entry_get() failed.\n",
                       "rdmngr_db_first_rd_entry_get",0x105c);
                uVar4 = uVar4 + 1;
              }
            }
          }
        }
      }
      iVar1 = apmngr_db_entry_next_get(uStack_2f0,auStack_300);
    } while (iVar1 == 0);
  }
  return 0xffffffff;
}

