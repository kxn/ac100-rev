// func rdmngr_db_get_rd_status @ 0061d330 size=252

int rdmngr_db_get_rd_status(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar6 = DAT_007cc65c;
  if (-1 < (int)uVar2) {
    iVar3 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    iVar5 = apmngr_db_get_sensor_max();
    if (uVar2 < (uint)((iVar3 + iVar4 + iVar5) * iVar6)) {
      FUN_004082d0(DAT_007cc64c,0xffffffff);
      iVar6 = *(int *)(DAT_007cc650 + uVar2 * 8 + 4);
      if (iVar6 == 0) {
        FUN_00407f30(DAT_007cc64c);
        return 0;
      }
      cVar1 = *(char *)(iVar6 + 0x48);
      FUN_00407f30(DAT_007cc64c);
      return (int)cVar1;
    }
  }
  if ((rdmngr_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d idx[%d] is invalid!\n","rdmngr_db_get_rd_status",0xf04,uVar2);
  }
  return 0;
}

