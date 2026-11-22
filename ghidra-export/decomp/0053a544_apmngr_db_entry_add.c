// func apmngr_db_entry_add @ 0053a544 size=1676

undefined4 apmngr_db_entry_add(void *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined2 local_308 [4];
  undefined1 auStack_300 [728];
  
  memset(local_308,0,0x2e0);
  if ((param_1 == (void *)0x0) ||
     ((uVar5 = (uint)*(ushort *)((int)param_1 + 0x10),
      apmngr_ap_num_max + apmngr_template_num_max <= (int)uVar5 &&
      ((uVar5 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)uVar5)))))) {
    uVar4 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_entry_add",0x76e,0xffff);
    }
  }
  else {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar3 = uVar5;
    if (49999 < uVar5) {
      uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if ((*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) == 1) ||
       (iVar1 = FUN_00407fa0(g_apmngr_ap_hash,(int)param_1 + 0x48), iVar2 = g_apmngr_entry_array,
       iVar1 != 0)) {
      uVar4 = 0xffffffff;
      FUN_00407f30(apmngr_db_mutex);
      if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        uVar3 = uVar5;
        if (49999 < uVar5) {
          uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        uVar4 = 0xffffffff;
        printf("[APMNGR_ERROR]%s()/%d Ap (%d %02X-%02X-%02X-%02X-%02X-%02X) is alreay used[%d] or hash conflict.\n"
               ,"apmngr_db_entry_add",0x77b,uVar5,(uint)*(byte *)((int)param_1 + 0x48),
               (uint)*(byte *)((int)param_1 + 0x49),(uint)*(byte *)((int)param_1 + 0x4a),
               (uint)*(byte *)((int)param_1 + 0x4b),(uint)*(byte *)((int)param_1 + 0x4c),
               (uint)*(byte *)((int)param_1 + 0x4d),
               *(undefined4 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c));
      }
    }
    else if (((*(int *)((int)param_1 + 0x14) == 7) && (*(int *)((int)param_1 + 0x3c) != 0)) &&
            (apmngr_firm_sensor_num_max <= (int)(uint)g_apmngr_firm_sensor_num)) {
      uVar4 = 0xffffffff;
      FUN_00407f30(apmngr_db_mutex);
      if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APMNGR_WARNING]%s()/%d Sensor (%d %02X-%02X-%02X-%02X-%02X-%02X) exceeds.\n",
               "apmngr_db_entry_add",0x783,uVar5,(uint)*(byte *)((int)param_1 + 0x48),
               (uint)*(byte *)((int)param_1 + 0x49),(uint)*(byte *)((int)param_1 + 0x4a),
               (uint)*(byte *)((int)param_1 + 0x4b),(uint)*(byte *)((int)param_1 + 0x4c),
               (uint)*(byte *)((int)param_1 + 0x4d));
      }
    }
    else {
      uVar3 = uVar5;
      if (49999 < uVar5) {
        uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      memcpy((void *)(g_apmngr_entry_array + uVar3 * 0x2d8),param_1,0x2d8);
      uVar3 = uVar5;
      if (49999 < uVar5) {
        uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      FUN_004086b0(g_apmngr_group_array + (uint)*(ushort *)((int)param_1 + 0x12) * 0x84 + 0x78,
                   iVar2 + uVar3 * 0x2d8);
      uVar3 = uVar5;
      if (49999 < uVar5) {
        uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      FUN_00408380(g_apmngr_ap_hash,g_apmngr_entry_array + uVar3 * 0x2d8);
      uVar3 = uVar5;
      if (49999 < uVar5) {
        uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined4 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) = 1;
      if (*(int *)((int)param_1 + 0x14) == 7) {
        g_apmngr_sensor_num = g_apmngr_sensor_num + 1;
        if (*(int *)((int)param_1 + 0x3c) != 0) {
          g_apmngr_firm_sensor_num = g_apmngr_firm_sensor_num + 1;
        }
      }
      else {
        g_apmngr_ap_num = g_apmngr_ap_num + 1;
      }
      FUN_00407f30(apmngr_db_mutex);
      if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(0), iVar2 != 0)) {
        printf("[APMNGR_DEBUG]%s()/%d telnet_status:%d\n","apmngr_db_entry_add",0x797,
               (int)*(char *)((int)param_1 + 0x206));
      }
      iVar2 = apmngr_db_sqlite_notify_msg(0,param_1,0x2d8);
      if (iVar2 == 0) {
        local_308[0] = 0xffff;
        memcpy(auStack_300,param_1,0x2d8);
        uVar4 = 0;
        apmngr_evt_notify(7,local_308);
      }
      else {
        FUN_004082d0(apmngr_db_mutex,0xffffffff);
        uVar4 = g_apmngr_ap_hash;
        iVar2 = g_apmngr_entry_array;
        uVar3 = uVar5;
        if (49999 < uVar5) {
          uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) = 0;
        uVar3 = uVar5;
        if (49999 < uVar5) {
          uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        FUN_00407f40(uVar4,iVar2 + uVar3 * 0x2d8);
        uVar3 = uVar5;
        if (49999 < uVar5) {
          uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        FUN_00408500(g_apmngr_entry_array + uVar3 * 0x2d8);
        iVar2 = g_apmngr_entry_array;
        uVar3 = uVar5;
        if (49999 < uVar5) {
          uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        memset((void *)(g_apmngr_entry_array + uVar3 * 0x2d8),0,0x2d8);
        if (49999 < uVar5) {
          uVar5 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(iVar2 + uVar5 * 0x2d8 + 0x290) = 0xffffffff;
        if (*(int *)((int)param_1 + 0x14) == 7) {
          g_apmngr_sensor_num = g_apmngr_sensor_num + -1;
          if (*(int *)((int)param_1 + 0x3c) != 0) {
            g_apmngr_firm_sensor_num = g_apmngr_firm_sensor_num - 1;
          }
        }
        else {
          g_apmngr_ap_num = g_apmngr_ap_num + -1;
        }
        uVar4 = 0xffffffff;
        FUN_00407f30(apmngr_db_mutex);
        if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APMNGR_ERROR]%s()/%d Failed to notify daemon thread.\n","apmngr_db_entry_add",
                 0x7af);
        }
      }
    }
  }
  return uVar4;
}

