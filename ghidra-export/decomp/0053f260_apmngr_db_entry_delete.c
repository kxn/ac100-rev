// func apmngr_db_entry_delete @ 0053f260 size=1324

undefined4 apmngr_db_entry_delete(ushort param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort local_res0 [8];
  
  uVar4 = (uint)param_1;
  local_res0[0] = param_1;
  if (((int)uVar4 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < uVar4 && ((int)uVar4 < apmngr_sensor_num_max + 50000)))) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar3 = (uint)local_res0[0];
    uVar4 = uVar3;
    if (49999 < uVar3) {
      uVar4 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar4 * 0x2d8 + 0x1c) == 1) {
      uVar4 = uVar3;
      if (49999 < uVar3) {
        uVar4 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar4 * 0x2d8 + 0x290) != -1) {
        if (49999 < uVar3) {
          uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        FUN_00408060(*(undefined4 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x290));
      }
      iVar2 = 0;
      do {
        uVar3 = (uint)local_res0[0];
        uVar4 = uVar3;
        if (49999 < uVar3) {
          uVar4 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (*(int *)(g_apmngr_entry_array + uVar4 * 0x2d8 + (iVar2 + 10) * 4 + 4) != -1) {
          if (49999 < uVar3) {
            uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          FUN_00407f20(*(undefined4 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + (iVar2 + 10) * 4 + 4))
          ;
        }
        iVar1 = g_apmngr_entry_array;
        iVar2 = iVar2 + 1;
      } while (iVar2 != 2);
      uVar3 = (uint)local_res0[0];
      uVar4 = uVar3;
      if (49999 < uVar3) {
        uVar4 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      iVar2 = *(int *)(g_apmngr_entry_array + uVar4 * 0x2d8 + 0x3c);
      uVar4 = uVar3;
      if (49999 < uVar3) {
        uVar4 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined4 *)(g_apmngr_entry_array + uVar4 * 0x2d8 + 0x1c) = 0;
      if (49999 < uVar3) {
        uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      FUN_00407f40(g_apmngr_ap_hash,iVar1 + uVar3 * 0x2d8);
      uVar4 = (uint)local_res0[0];
      if (49999 < uVar4) {
        uVar4 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      FUN_00408500(g_apmngr_entry_array + uVar4 * 0x2d8);
      iVar1 = g_apmngr_entry_array;
      uVar3 = (uint)local_res0[0];
      uVar4 = uVar3;
      if (49999 < uVar3) {
        uVar4 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar4 * 0x2d8 + 0x14) == 7) {
        g_apmngr_sensor_num = g_apmngr_sensor_num + -1;
        uVar4 = uVar3;
        if (49999 < uVar3) {
          uVar4 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (*(int *)(g_apmngr_entry_array + uVar4 * 0x2d8 + 0x3c) != 0) {
          g_apmngr_firm_sensor_num = g_apmngr_firm_sensor_num + -1;
        }
      }
      else {
        g_apmngr_ap_num = g_apmngr_ap_num + -1;
      }
      if (49999 < uVar3) {
        uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      memset((void *)(g_apmngr_entry_array + uVar3 * 0x2d8),0,0x2d8);
      uVar5 = apmngr_db_mutex;
      uVar4 = (uint)local_res0[0];
      if (49999 < uVar4) {
        uVar4 = (uVar4 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined4 *)(iVar1 + uVar4 * 0x2d8 + 0x290) = 0xffffffff;
      uVar6 = 0;
      FUN_00407f30(uVar5);
      uVar5 = 0xe;
      if (iVar2 != 0) {
        uVar5 = 0xf;
      }
      iVar2 = apmngr_db_sqlite_notify_msg(uVar5,local_res0,2);
      if (((iVar2 != 0) && (uVar6 = 0xffffffff, apmngr_err_switch != '\0')) &&
         (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APMNGR_ERROR]%s()/%d Failed to notify daemon thread.\n","apmngr_db_entry_delete",
               0xbae);
      }
    }
    else {
      if ((apmngr_warning_switch != '\0') &&
         (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 != 0)) {
        printf("[APMNGR_WARNING]%s()/%d Ap id[%d] is not used.\n","apmngr_db_entry_delete",0xb8a,
               (uint)local_res0[0]);
      }
      uVar6 = 0xffffffff;
      FUN_00407f30(apmngr_db_mutex);
    }
  }
  else {
    uVar6 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_entry_delete",0xb83,
             (uint)local_res0[0]);
    }
  }
  return uVar6;
}

