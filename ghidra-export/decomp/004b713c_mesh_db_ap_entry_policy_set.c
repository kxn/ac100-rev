// func mesh_db_ap_entry_policy_set @ 004b713c size=324

undefined4 mesh_db_ap_entry_policy_set(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if (iVar1 <= (int)param_1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_ap_entry_policy_set",0x249);
    return 0xffffffff;
  }
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  uVar3 = DAT_00767eb4;
  pcVar2 = (char *)(DAT_00767f6c + param_1 * 8);
  if (*pcVar2 == '\0') {
    if (mesh_debug_switch == '\0') goto LAB_004b7228;
    pcVar2 = "[MESH_DEBUG]%s()/%d AP id(%d) is not used\n";
    uVar3 = 0x250;
  }
  else {
    iVar1 = *(int *)(pcVar2 + 4);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x30) = param_3;
      *(undefined4 *)(iVar1 + 0x2c) = param_2;
      FUN_00407f30(uVar3);
      return 0;
    }
    if (mesh_err_switch == '\0') goto LAB_004b7228;
    pcVar2 = "[MESH_ERROR]%s()/%d entry of ap_id %d is NULL\n";
    uVar3 = 599;
  }
  printf(pcVar2,"mesh_db_ap_entry_policy_set",uVar3,param_1);
LAB_004b7228:
  FUN_00407f30(DAT_00767eb4);
  return 0xffffffff;
}

