// func collect_recover_rdentry_from_ap @ 00624518 size=412

undefined4 collect_recover_rdentry_from_ap(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 local_78;
  undefined2 local_76;
  undefined1 auStack_74 [88];
  
  uVar4 = 1;
  memset(auStack_74,0,0x54);
  if (param_1 != 0) {
    local_78 = *(undefined2 *)(param_1 + 0x44);
    iVar3 = 1;
    local_76 = *(undefined2 *)(param_1 + 0x46);
    iVar1 = rdmngr_db_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_78);
    if (iVar1 < 0) {
      if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
               "collect_recover_rdentry_from_ap",0xa35,iVar1);
      }
    }
    else {
      for (; iVar3 <= iVar1; iVar3 = iVar3 + 1) {
        uVar4 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar3);
        iVar2 = rdmngr_db_rd_entry_get(uVar4,auStack_74);
        if (iVar2 != 0) {
          if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[RDMNGR_ERROR]%s()/%d AP %d\'s rdentry %d missed,need to fix.\n",
                   "collect_recover_rdentry_from_ap",0xa3d,(uint)*(ushort *)(param_1 + 0x10),uVar4);
          }
          rdmngr_db_rd_entry_del(param_1);
          rdmngr_db_ap_connect(param_1,iVar1,*(undefined4 *)(param_1 + 0x40));
          if (*(int *)(param_1 + 0x3c) != 0) {
            rdmngr_db_ap_firm(*(undefined2 *)(param_1 + 0x10),iVar1);
          }
          if (param_2 == (undefined4 *)0x0) {
            return 0;
          }
          *param_2 = 1;
          return 0;
        }
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}

