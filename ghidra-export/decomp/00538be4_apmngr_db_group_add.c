// func apmngr_db_group_add @ 00538be4 size=328

undefined4 apmngr_db_group_add(ushort param_1,char *param_2)

{
  char *__format;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)param_1;
  if (((int)uVar3 < apmngr_group_num_max) && (param_2 != (char *)0x0)) {
    iVar2 = g_apmngr_group_array + uVar3 * 0x84;
    if (*(int *)(iVar2 + 0x10) == 0) {
      FUN_004082d0(apmngr_db_mutex,0xffffffff);
      *(ushort *)(iVar2 + 0xc) = param_1;
      *(undefined4 *)(iVar2 + 0x10) = 1;
      strncpy((char *)(iVar2 + 0x14),param_2,0x61);
      *(undefined1 *)(iVar2 + 0x75) = 0;
      FUN_0051ad88(iVar2 + 0x78);
      FUN_004086b0(&g_apmngr_group_list,iVar2);
      FUN_00407f30(apmngr_db_mutex);
      return 0;
    }
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      __format = "[APMNGR_ERROR]%s()/%d Group id[%d] already in use.\n";
      uVar1 = 0x5c5;
LAB_00538cac:
      printf(__format,"apmngr_db_group_add",uVar1,uVar3);
      return 0xffffffff;
    }
  }
  else if (apmngr_err_switch != '\0') {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Invalid group id[%d] or group_name is NULL.\n";
    uVar1 = 0x5be;
    goto LAB_00538cac;
  }
  return 0xffffffff;
}

