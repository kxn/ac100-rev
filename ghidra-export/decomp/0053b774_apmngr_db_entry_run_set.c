// func apmngr_db_entry_run_set @ 0053b774 size=572

undefined4 apmngr_db_entry_run_set(ushort param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  ushort local_44;
  undefined1 local_42;
  undefined1 auStack_41 [37];
  
  uVar3 = (uint)param_1;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  memset(&local_44,0,0x24);
  if ((((int)uVar3 < apmngr_ap_num_max + apmngr_template_num_max) ||
      ((49999 < uVar3 && ((int)uVar3 < apmngr_sensor_num_max + 50000)))) && (param_2 != (void *)0x0)
     ) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    iVar1 = g_apmngr_entry_array;
    uVar2 = uVar3;
    if (49999 < uVar3) {
      uVar2 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 1) {
      uVar2 = uVar3;
      if (49999 < uVar3) {
        uVar2 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      memcpy((void *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x208),param_2,0x90);
      if (49999 < uVar3) {
        uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      uVar4 = 0xffffffff;
      local_42 = (undefined1)*(undefined4 *)(iVar1 + uVar3 * 0x2d8 + 0xc);
      FUN_00407f30(apmngr_db_mutex);
      local_58 = CONCAT22(param_1,local_58._2_2_);
      local_44 = param_1;
      FUN_004084f0((int)param_2 + 0x10,0x10,auStack_41);
      memcpy(&local_54,param_2,0x10);
      iVar1 = apmngr_db_sqlite_notify_msg(10,&local_58,0x14);
      if ((iVar1 == 0) && (iVar1 = apmngr_db_sqlite_notify_msg(0x18,&local_44,0x24), iVar1 == 0)) {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 0xffffffff;
      FUN_00407f30(apmngr_db_mutex);
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d] or run_info is NULL.\n",
             "apmngr_db_entry_run_set",0x860,uVar3);
    }
  }
  return uVar4;
}

