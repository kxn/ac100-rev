// func rdmngr_db_get_rd_entry_chnl @ 0061d068 size=452

int rdmngr_db_get_rd_entry_chnl(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar5 = DAT_007cc65c;
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      FUN_004082d0(DAT_007cc64c,0xffffffff);
      iVar5 = *(int *)(DAT_007cc650 + uVar1 * 8 + 4);
      if (iVar5 == 0) {
        if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[RDMNGR_ERROR]%s()/%d idx[%d] is invalid!\n","rdmngr_db_get_rd_entry_chnl",0xebd,
                 uVar1);
        }
        FUN_00407f30(DAT_007cc64c);
        return -1;
      }
      iVar5 = (int)*(short *)(iVar5 + 0x3c);
      if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        uVar1 = (uint)(param_1 << 4) >> 8;
        iVar2 = multi_link_status_get(uVar1 & 0xffff);
        if (iVar2 == 0) {
          puVar6 = &DAT_00708bf0;
        }
        else {
          puVar6 = &DAT_0070b7ac;
        }
        printf("[RDMNGR_DEBUG]%s()/%d rd_id:%d,ap_id:%d,chnl:%d,link:%s\n",
               "rdmngr_db_get_rd_entry_chnl",0xec6,param_1,uVar1,iVar5,puVar6);
      }
      FUN_00407f30(DAT_007cc64c);
      return iVar5;
    }
  }
  if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d idx[%d] is invalid!\n","rdmngr_db_get_rd_entry_chnl",0xeb6,uVar1);
  }
  return -1;
}

