// func apmngr_db_template_add @ 00540ba8 size=1108

undefined4 apmngr_db_template_add(void *param_1)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  void *__src;
  uint uVar4;
  undefined2 local_308 [4];
  undefined1 auStack_300 [732];
  
  memset(local_308,0,0x2e0);
  if ((param_1 == (void *)0x0) ||
     ((uVar4 = (uint)*(ushort *)((int)param_1 + 0x10),
      apmngr_ap_num_max + apmngr_template_num_max <= (int)uVar4 &&
      ((uVar4 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)uVar4)))))) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Invalid ap id.\n";
    uVar3 = 0xd2b;
  }
  else {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    iVar1 = g_apmngr_entry_array;
    uVar2 = uVar4;
    if (49999 < uVar4) {
      uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    __src = (void *)0x0;
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 0) {
      uVar2 = uVar4;
      if (49999 < uVar4) {
        uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      memcpy((void *)(g_apmngr_entry_array + uVar2 * 0x2d8),param_1,0x2d8);
      uVar2 = uVar4;
      if (49999 < uVar4) {
        uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined4 *)(iVar1 + uVar2 * 0x2d8 + 0x1c) = 1;
      uVar2 = uVar4;
      if (49999 < uVar4) {
        uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      _apmngr_db_entry_group_insert(iVar1 + uVar2 * 0x2d8);
      uVar2 = uVar4;
      if (49999 < uVar4) {
        uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      FUN_00408380(g_apmngr_template_hash,g_apmngr_entry_array + uVar2 * 0x2d8);
      g_apmngr_template_num = g_apmngr_template_num + 1;
      uVar2 = uVar4;
      if (49999 < uVar4) {
        uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      __src = (void *)(g_apmngr_entry_array + uVar2 * 0x2d8);
    }
    FUN_00407f30(apmngr_db_mutex);
    iVar1 = apmngr_db_sqlite_notify_msg(1,param_1,0x2d8);
    if (iVar1 == 0) {
      if (__src == (void *)0x0) {
        return 0;
      }
      local_308[0] = 0xffff;
      memcpy(auStack_300,__src,0x2d8);
      apmngr_evt_notify(7,local_308);
      return 0;
    }
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    iVar1 = g_apmngr_entry_array;
    uVar2 = uVar4;
    if (49999 < uVar4) {
      uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    *(undefined4 *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) = 0;
    uVar2 = uVar4;
    if (49999 < uVar4) {
      uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    FUN_00407f40(g_apmngr_template_hash,iVar1 + uVar2 * 0x2d8);
    uVar2 = uVar4;
    if (49999 < uVar4) {
      uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    FUN_00408500(g_apmngr_entry_array + uVar2 * 0x2d8);
    iVar1 = g_apmngr_entry_array;
    g_apmngr_template_num = g_apmngr_template_num + -1;
    uVar2 = uVar4;
    if (49999 < uVar4) {
      uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    memset((void *)(g_apmngr_entry_array + uVar2 * 0x2d8),0,0x2d8);
    uVar3 = apmngr_db_mutex;
    if (49999 < uVar4) {
      uVar4 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    *(undefined4 *)(iVar1 + uVar4 * 0x2d8 + 0x290) = 0xffffffff;
    FUN_00407f30(uVar3);
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Failed to notify daemon thread.\n";
    uVar3 = 0xd45;
  }
  printf(__format,"apmngr_db_template_add",uVar3);
  return 0xffffffff;
}

