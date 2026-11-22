// func mesh_db_ap_entry_tmp_re_roam_timer_op @ 004b73bc size=612

undefined4 mesh_db_ap_entry_tmp_re_roam_timer_op(ushort param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar6 = (uint)param_1;
  iVar2 = apmngr_db_get_ap_max();
  if (iVar2 <= (int)uVar6) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_ap_entry_tmp_re_roam_timer_op",0x289);
    return 0xffffffff;
  }
  iVar2 = uVar6 * 8;
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  if ((*(char *)(DAT_00767f6c + iVar2) == '\0') ||
     (iVar3 = *(int *)((char *)(DAT_00767f6c + iVar2) + 4), *(int *)(iVar3 + 0x10) == 0)) {
LAB_004b75d4:
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d AP id(%d) is not used or not CAP\n",
             "mesh_db_ap_entry_tmp_re_roam_timer_op",0x290,uVar6);
    }
  }
  else {
    if (param_2 == 0) {
      cVar1 = *(char *)(iVar3 + 0x34);
    }
    else {
      if (param_3 == 0) goto LAB_004b75d4;
      cVar1 = *(char *)(iVar3 + 0x34);
    }
    if ((cVar1 != '\0') && (*(int *)(iVar3 + 0x38) != -1)) {
      if ((param_2 != 0) || (param_4 == 0)) {
        FUN_00408060();
      }
      *(undefined4 *)(*(int *)(DAT_00767f6c + iVar2 + 4) + 0x38) = 0xffffffff;
    }
    *(bool *)(*(int *)(DAT_00767f6c + iVar2 + 4) + 0x34) = param_2 != 0;
    if (param_2 == 0) {
LAB_004b7564:
      FUN_00407f30(DAT_00767eb4);
      return 0;
    }
    puVar4 = (ushort *)FUN_00408450(2,0x2a5);
    if (puVar4 != (ushort *)0x0) {
      *puVar4 = param_1;
      iVar3 = *(int *)(DAT_00767f6c + iVar2 + 4);
      uVar5 = FUN_00408340(tmp_re_roam_open_time,0,param_3,puVar4,uac_mem_free_my,
                           "mesh_db_ap_entry_tmp_re_roam_timer_op",0x2ab);
      *(undefined4 *)(iVar3 + 0x38) = uVar5;
      if (*(int *)(*(int *)(DAT_00767f6c + iVar2 + 4) + 0x38) != -1) goto LAB_004b7564;
      if (mesh_err_switch != '\0') {
        printf("[MESH_ERROR]%s()/%d Timer add failed for ap id %d.\n",
               "mesh_db_ap_entry_tmp_re_roam_timer_op",0x2ae,uVar6);
      }
      *(undefined1 *)(*(int *)(DAT_00767f6c + iVar2 + 4) + 0x34) = 0;
    }
  }
  FUN_00407f30(DAT_00767eb4);
  return 0xffffffff;
}

