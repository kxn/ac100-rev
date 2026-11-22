// func mesh_db_ap_entry_child_num_get @ 004b787c size=256

undefined4 mesh_db_ap_entry_child_num_get(uint param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    pcVar2 = (char *)(DAT_00767f6c + param_1 * 8);
    if ((*pcVar2 != '\0') && (*(int *)(pcVar2 + 4) != 0)) {
      FUN_004082d0(DAT_00767eb4,0xffffffff);
      uVar3 = FUN_00407fe0(*(int *)(DAT_00767f6c + param_1 * 8 + 4) + 0x20);
      FUN_00407f30(DAT_00767eb4);
      return uVar3;
    }
    if (mesh_warning_switch != '\0') {
      printf("[MESH_WARNING]%s()/%d AP id(%d) is used\n","mesh_db_ap_entry_child_num_get",0x300,
             param_1);
      return 0xffffffff;
    }
  }
  else if (mesh_err_switch != '\0') {
    printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_ap_entry_child_num_get",0x2fb);
    return 0xffffffff;
  }
  return 0xffffffff;
}

