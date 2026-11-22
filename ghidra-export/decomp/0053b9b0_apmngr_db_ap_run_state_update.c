// func apmngr_db_ap_run_state_update @ 0053b9b0 size=840

undefined4 apmngr_db_ap_run_state_update(ushort param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_v1;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_28;
  int local_24;
  
  uVar4 = (uint)param_1;
  local_28 = 0;
  local_24 = 0;
  if (((int)uVar4 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < uVar4 && ((int)uVar4 < apmngr_sensor_num_max + 50000)))) {
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
      *(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x2ac) = param_2;
      if (param_2 == 0) {
        uVar2 = uVar4;
        if (49999 < uVar4) {
          uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (*(int *)(iVar1 + uVar2 * 0x2d8 + 0x290) != -1) {
          uVar2 = uVar4;
          if (49999 < uVar4) {
            uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          FUN_00408060(*(undefined4 *)(iVar1 + uVar2 * 0x2d8 + 0x290));
        }
        iVar1 = g_apmngr_entry_array;
        uVar2 = uVar4;
        if (49999 < uVar4) {
          uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x290) = 0xffffffff;
        uVar2 = uVar4;
        if (49999 < uVar4) {
          uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(iVar1 + uVar2 * 0x2d8 + 0x288) = 0;
        uVar2 = uVar4;
        if (49999 < uVar4) {
          uVar2 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(iVar1 + uVar2 * 0x2d8 + 0x28c) = 0;
        if (49999 < uVar4) {
          uVar4 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(iVar1 + uVar4 * 0x2d8 + 0x284) = 0;
      }
      else if (param_2 == 2) {
        if (49999 < uVar4) {
          uVar4 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        FUN_00407e70();
        *(undefined4 *)(iVar1 + uVar4 * 0x2d8 + 0x284) = extraout_v1;
      }
      uVar3 = 0xffffffff;
      FUN_00407f30(apmngr_db_mutex);
      local_28 = CONCAT22(param_1,local_28._2_2_);
      local_24 = param_2;
      iVar1 = apmngr_db_sqlite_notify_msg(0xd,&local_28,8);
      if (iVar1 == 0) {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xffffffff;
      FUN_00407f30(apmngr_db_mutex);
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_run_state_update",0x885,
             uVar4);
    }
  }
  return uVar3;
}

