// func rdmngr_db_rd_entry_get @ 0061ed2c size=444

undefined4 rdmngr_db_rd_entry_get(undefined4 param_1,void *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *__src;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar5 = DAT_007cc65c;
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      if (param_2 != (void *)0x0) {
        FUN_004082d0(DAT_007cc64c,0xffffffff);
        __src = *(int **)(DAT_007cc650 + uVar1 * 8 + 4);
        if ((__src != (int *)0x0) && (*__src != -1)) {
          memcpy(param_2,__src,0x54);
          FUN_00407f30(DAT_007cc64c);
          return 0;
        }
        if ((rdmngr_warning_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[RDMNGR_WARNING]%s()/%d Radio id:0x%x is not used.\n","rdmngr_db_rd_entry_get",
                 0x10bb,param_1);
        }
        FUN_00407f30(DAT_007cc64c);
        return 0xffffffff;
      }
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 != 0) {
        printf("[RDMNGR_ERROR]%s()/%d entry is null.\n","rdmngr_db_rd_entry_get",0x10b3);
        return 0xffffffff;
      }
      return 0xffffffff;
    }
  }
  if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d Invalid radio id:0x%x.\n","rdmngr_db_rd_entry_get",0x10ad,param_1)
    ;
    return 0xffffffff;
  }
  return 0xffffffff;
}

