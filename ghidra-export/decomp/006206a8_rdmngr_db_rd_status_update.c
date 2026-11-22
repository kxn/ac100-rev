// func rdmngr_db_rd_status_update @ 006206a8 size=396

undefined4 rdmngr_db_rd_status_update(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar5 = DAT_007cc65c;
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      puVar6 = (undefined4 *)FUN_00408450(8,0xd77);
      if (puVar6 == (undefined4 *)0x0) {
        return 0xffffffff;
      }
      puVar6[1] = param_2;
      *puVar6 = param_1;
      FUN_004082d0(DAT_007cc64c,0xffffffff);
      if (*(int *)(DAT_007cc650 + uVar1 * 8 + 4) == 0) {
        if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[RDMNGR_ERROR]%s()/%d rd_id[%d] is invalid!\n","rdmngr_db_rd_status_update",0xd85,
                 param_1);
        }
        FUN_00407f30(DAT_007cc64c);
        FUN_00407df0(puVar6);
        return 0xffffffff;
      }
      rdmngr_db_msg_send(3,puVar6);
      FUN_00407f30(DAT_007cc64c);
      return 0;
    }
  }
  if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d rd_id[%d] is invalid!\n","rdmngr_db_rd_status_update",0xd74,
           param_1);
    return 0xffffffff;
  }
  return 0xffffffff;
}

