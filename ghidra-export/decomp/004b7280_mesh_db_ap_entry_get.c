// func mesh_db_ap_entry_get @ 004b7280 size=316

undefined4 mesh_db_ap_entry_get(uint param_1,void *param_2)

{
  int iVar1;
  char *pcVar2;
  void *__src;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((iVar1 <= (int)param_1) || (param_2 == (void *)0x0)) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_ap_entry_get",0x269);
    return 0xffffffff;
  }
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  pcVar2 = (char *)(DAT_00767f6c + param_1 * 8);
  if (*pcVar2 == '\0') {
    if (mesh_debug_switch == '\0') goto LAB_004b7364;
    pcVar2 = "[MESH_DEBUG]%s()/%d AP id(%d) is not used\n";
    uVar3 = 0x270;
  }
  else {
    __src = *(void **)(pcVar2 + 4);
    if (__src != (void *)0x0) {
      memcpy(param_2,__src,0x3c);
      FUN_00407f30(DAT_00767eb4);
      return 0;
    }
    if (mesh_err_switch == '\0') goto LAB_004b7364;
    pcVar2 = "[MESH_ERROR]%s()/%d entry of ap_id %d is NULL\n";
    uVar3 = 0x277;
  }
  printf(pcVar2,"mesh_db_ap_entry_get",uVar3,param_1);
LAB_004b7364:
  FUN_00407f30(DAT_00767eb4);
  return 0xffffffff;
}

