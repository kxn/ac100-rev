// func apmngr_db_ap_mesh_switch_update @ 0053cde8 size=448

undefined4 apmngr_db_ap_mesh_switch_update(ushort param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_20;
  
  uVar3 = (uint)param_1;
  local_20 = 0;
  if (((int)uVar3 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < uVar3 && ((int)uVar3 < apmngr_sensor_num_max + 50000)))) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar2 = uVar3;
    if (49999 < uVar3) {
      uVar2 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 1) {
      if (49999 < uVar3) {
        uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined1 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x207) = param_2;
    }
    uVar4 = 0;
    FUN_00407f30(apmngr_db_mutex);
    local_20 = CONCAT22(param_1,CONCAT11(param_2,(undefined1)local_20));
    iVar1 = apmngr_db_sqlite_notify_msg(0x19,&local_20,4);
    if (((iVar1 != 0) && (uVar4 = 0xffffffff, apmngr_err_switch != '\0')) &&
       (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d apmngr_db_sqlite_notify_msg error\n",
             "apmngr_db_ap_mesh_switch_update",0x9c7);
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_mesh_switch_update",0x9b8,
             uVar3);
    }
  }
  return uVar4;
}

