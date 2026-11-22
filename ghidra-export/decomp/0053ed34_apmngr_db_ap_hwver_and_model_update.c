// func apmngr_db_ap_hwver_and_model_update @ 0053ed34 size=528

undefined4 apmngr_db_ap_hwver_and_model_update(ushort param_1,ushort *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar4 = (uint)param_1;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  if (((int)uVar4 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < uVar4 && ((int)uVar4 < apmngr_sensor_num_max + 50000)))) {
    if (param_2 != (ushort *)0x0) {
      FUN_004082d0(apmngr_db_mutex,0xffffffff);
      iVar1 = g_apmngr_entry_array;
      uVar2 = uVar4;
      if (49999 < uVar4) {
        uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 1) {
        uVar2 = uVar4;
        if (49999 < uVar4) {
          uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        iVar3 = g_apmngr_entry_array + uVar2 * 0x2d8;
        *(ushort *)(iVar3 + 0x44) = *param_2;
        *(ushort *)(iVar3 + 0x46) = param_2[1];
        if (49999 < uVar4) {
          uVar4 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(iVar1 + uVar4 * 0x2d8 + 0x40) = param_3;
      }
      FUN_00407f30(apmngr_db_mutex);
    }
    local_40 = CONCAT22(param_1,local_40._2_2_);
    uVar5 = 0xffffffff;
    if (param_2 != (ushort *)0x0) {
      local_28 = param_3;
      snprintf((char *)((int)&local_40 + 2),0x14,"%u.%u",(uint)*param_2,(uint)param_2[1]);
      iVar1 = apmngr_db_sqlite_notify_msg(9,&local_40,0x1c);
      if (iVar1 == 0) {
        uVar5 = 0;
      }
    }
  }
  else {
    uVar5 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_hwver_and_model_update",
             0xb3a,uVar4);
    }
  }
  return uVar5;
}

