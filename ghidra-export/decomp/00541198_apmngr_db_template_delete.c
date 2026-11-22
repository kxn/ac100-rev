// func apmngr_db_template_delete @ 00541198 size=648

undefined4 apmngr_db_template_delete(ushort param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort local_res0 [8];
  
  uVar3 = (uint)param_1;
  local_res0[0] = param_1;
  if (((int)uVar3 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < uVar3 && ((int)uVar3 < apmngr_sensor_num_max + 50000)))) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    iVar1 = g_apmngr_entry_array;
    uVar2 = (uint)local_res0[0];
    uVar3 = uVar2;
    if (49999 < uVar2) {
      uVar3 = (uVar2 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) == 1) {
      uVar3 = uVar2;
      if (49999 < uVar2) {
        uVar3 = (uVar2 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined4 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) = 0;
      if (49999 < uVar2) {
        uVar2 = (uVar2 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      FUN_00407f40(g_apmngr_template_hash,iVar1 + uVar2 * 0x2d8);
      uVar3 = (uint)local_res0[0];
      if (49999 < uVar3) {
        uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      FUN_00408500(g_apmngr_entry_array + uVar3 * 0x2d8);
      g_apmngr_template_num = g_apmngr_template_num + -1;
      uVar3 = (uint)local_res0[0];
      if (49999 < uVar3) {
        uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      memset((void *)(g_apmngr_entry_array + uVar3 * 0x2d8),0,0x2d8);
    }
    uVar4 = 0;
    FUN_00407f30(apmngr_db_mutex);
    iVar1 = apmngr_db_sqlite_notify_msg(0x10,local_res0,2);
    if (((iVar1 != 0) && (uVar4 = 0xffffffff, apmngr_err_switch != '\0')) &&
       (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Failed to notify daemon thread.\n","apmngr_db_template_delete",
             0xd77);
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_template_delete",0xd67,
             (uint)local_res0[0]);
    }
  }
  return uVar4;
}

