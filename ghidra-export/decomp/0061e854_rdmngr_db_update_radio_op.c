// func rdmngr_db_update_radio_op @ 0061e854 size=468

undefined4 rdmngr_db_update_radio_op(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar5 = DAT_007cc65c;
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      FUN_004082d0(DAT_007cc64c,0xffffffff);
      iVar5 = *(int *)(DAT_007cc650 + uVar1 * 8 + 4);
      if (iVar5 != 0) {
        uVar6 = 1;
        if (param_2 == 1) {
          *(undefined1 *)(iVar5 + 0x4c) = 0;
          *(undefined1 *)(iVar5 + 0x4e) = 4;
        }
        else if (param_2 == 2) {
          if (*(char *)(iVar5 + 0x4c) == '\0') {
            uVar6 = 3;
          }
          *(undefined1 *)(iVar5 + 0x4e) = uVar6;
        }
        if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d rdState is %d.\n","rdmngr_db_update_radio_op",0xfd9,
                 (uint)*(byte *)(iVar5 + 0x4e));
        }
        FUN_00407f30(DAT_007cc64c);
        return 0;
      }
      if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d idx[%d] is invalid!\n","rdmngr_db_update_radio_op",0xfc9,uVar1
              );
      }
      FUN_00407f30(DAT_007cc64c);
      return 0xffffffff;
    }
  }
  if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d Invalid rd_id[%d].\n","rdmngr_db_update_radio_op",0xfc2,param_1);
  }
  return 0xffffffff;
}

