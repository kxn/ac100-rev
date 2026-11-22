// func rdmngr_db_get_rd_entry_firm @ 0061d22c size=1

bool rdmngr_db_get_rd_entry_firm(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar5 = DAT_007cc65c;
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      FUN_004082d0(DAT_007cc64c,0xffffffff);
      piVar6 = *(int **)(DAT_007cc650 + uVar1 * 8 + 4);
      bVar7 = false;
      if ((piVar6 != (int *)0x0) && (*piVar6 != -1)) {
        bVar7 = *(char *)((int)piVar6 + 0x4d) != '\0';
      }
      FUN_00407f30(DAT_007cc64c);
      return bVar7;
    }
  }
  if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d idx[%d] is invalid!\n","rdmngr_db_get_rd_entry_firm",0xee1,uVar1);
  }
  return false;
}

