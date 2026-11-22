// func rdmngr_db_rd_entry_set @ 0061fad4 size=416

undefined4 rdmngr_db_rd_entry_set(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *__dest;
  
  if (param_1 == (undefined4 *)0x0) {
    if (rdmngr_err_switch != 0) {
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      printf("[RDMNGR_ERROR]%s()/%d entry is null.\n","rdmngr_db_rd_entry_set",0x10ec);
      return 0xffffffff;
    }
  }
  else {
    uVar1 = rdmngr_db_generate_rd_idx_by_rd_id(*param_1);
    iVar5 = DAT_007cc65c;
    if (-1 < (int)uVar1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar4 = apmngr_db_get_sensor_max();
      if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
        FUN_004082d0(DAT_007cc64c,0xffffffff);
        __dest = *(void **)(DAT_007cc650 + uVar1 * 8 + 4);
        if (__dest != (void *)0x0) {
          memcpy(__dest,param_1,0x54);
          FUN_00407f30(DAT_007cc64c);
          return 0;
        }
        if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[RDMNGR_ERROR]%s()/%d Invalid rd idx:%d\n","rdmngr_db_rd_entry_set",0x10fb,uVar1);
        }
        FUN_00407f30(DAT_007cc64c);
        return 0xffffffff;
      }
    }
    if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d Invalid rd idx:%d\n","rdmngr_db_rd_entry_set",0x10f4,uVar1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

