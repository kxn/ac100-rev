// func apmngr_db_hdap_add @ 005402a4 size=1796

undefined4 apmngr_db_hdap_add(void *param_1,ushort *param_2,void *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *__format;
  uint uVar6;
  ushort *puVar7;
  undefined1 auStack_980 [160];
  ushort local_8e0;
  ushort local_8de;
  undefined1 auStack_8dc [12];
  undefined1 auStack_8d0 [728];
  undefined2 local_5f8 [4];
  undefined1 auStack_5f0 [728];
  undefined1 auStack_318 [736];
  ushort *local_38;
  undefined2 *local_34;
  int local_30;
  
  memset(&local_8e0,0,0x2e8);
  memset(local_5f8,0,0x5c0);
  memset(auStack_980,0,0x9a);
  if (param_2 != (ushort *)0x0) {
    uVar3 = (uint)*param_2;
    if ((int)uVar3 < apmngr_ap_num_max + apmngr_template_num_max) {
      uVar1 = param_2[1];
    }
    else {
      if ((uVar3 < 50000) || (apmngr_sensor_num_max + 50000 <= (int)uVar3)) goto LAB_00540368;
      uVar1 = param_2[1];
    }
    uVar3 = (uint)uVar1;
    if (((int)uVar3 < apmngr_ap_num_max + apmngr_template_num_max) ||
       ((49999 < uVar3 && ((int)uVar3 < apmngr_sensor_num_max + 50000)))) {
      if ((param_1 != (void *)0x0) && (param_3 != (void *)0x0)) {
        memcpy(auStack_980,(void *)((int)param_1 + 0x4e),0x9a);
        FUN_004082d0(apmngr_db_mutex,0xffffffff);
        uVar3 = (uint)*param_2;
        if (49999 < uVar3) {
          uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) != 1) {
          uVar3 = (uint)param_2[1];
          if (49999 < uVar3) {
            uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          if (((*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) != 1) &&
              (iVar4 = FUN_00407fa0(g_apmngr_ap_hash,(int)param_1 + 0x48), iVar4 == 0)) &&
             (iVar4 = FUN_00407fa0(g_apmngr_ap_hash,param_3), iVar4 == 0)) {
            if (((*(int *)((int)param_1 + 0x14) == 7) && (*(int *)((int)param_1 + 0x3c) != 0)) &&
               (apmngr_firm_sensor_num_max <= (int)(g_apmngr_firm_sensor_num + 1))) {
              FUN_00407f30(apmngr_db_mutex);
              if (apmngr_warning_switch == '\0') {
                return 0xffffffff;
              }
              iVar4 = is_target_debug_ap();
              if (iVar4 != 0) {
                printf("[APMNGR_WARNING]%s()/%d Sensor (%d %02X-%02X-%02X-%02X-%02X-%02X) exceeds.\n"
                       ,"apmngr_db_hdap_add",0xcbd,0xffff,(uint)*(byte *)((int)param_1 + 0x48),
                       (uint)*(byte *)((int)param_1 + 0x49),(uint)*(byte *)((int)param_1 + 0x4a),
                       (uint)*(byte *)((int)param_1 + 0x4b),(uint)*(byte *)((int)param_1 + 0x4c),
                       (uint)*(byte *)((int)param_1 + 0x4d));
                return 0xffffffff;
              }
              return 0xffffffff;
            }
            local_34 = local_5f8;
            local_30 = 0;
            puVar7 = param_2;
            local_38 = param_2;
            iVar4 = local_30;
            do {
              local_30 = iVar4;
              uVar1 = *puVar7;
              uVar6 = (uint)uVar1;
              iVar4 = local_30 + 1;
              uVar5 = apmngr_hdap_postfix_get(iVar4);
              snprintf((char *)((int)param_1 + 0x4e),0x9a,"%s%s",auStack_980,uVar5);
              *(ushort *)((int)param_1 + 0x10) = uVar1;
              iVar2 = g_apmngr_entry_array;
              *(ushort *)((int)param_1 + 0x298) = local_38[1];
              uVar3 = uVar6;
              if (49999 < uVar6) {
                uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
              }
              memcpy((void *)(iVar2 + uVar3 * 0x2d8),param_1,0x2d8);
              if (iVar4 == 2) {
                uVar3 = uVar6;
                if (49999 < uVar6) {
                  uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
                }
                memcpy((void *)(iVar2 + uVar3 * 0x2d8 + 0x48),param_3,6);
                uVar3 = uVar6;
                if (49999 < uVar6) {
                  uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
                }
                *(undefined4 *)(iVar2 + uVar3 * 0x2d8 + 0x124) = 0xffffffff;
                uVar3 = uVar6;
                if (49999 < uVar6) {
                  uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
                }
                *(undefined4 *)(iVar2 + uVar3 * 0x2d8 + 0x1b8) = 0xffffffff;
              }
              uVar3 = uVar6;
              if (49999 < uVar6) {
                uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
              }
              FUN_004086b0(g_apmngr_group_array + (uint)*(ushort *)((int)param_1 + 0x12) * 0x84 +
                           0x78,iVar2 + uVar3 * 0x2d8);
              uVar3 = uVar6;
              if (49999 < uVar6) {
                uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
              }
              FUN_00408380(g_apmngr_ap_hash,g_apmngr_entry_array + uVar3 * 0x2d8);
              iVar2 = g_apmngr_entry_array;
              uVar3 = uVar6;
              if (49999 < uVar6) {
                uVar3 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
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
              *local_34 = 0xffff;
              if (49999 < uVar6) {
                uVar6 = (uVar6 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
              }
              puVar7 = puVar7 + 1;
              memcpy(auStack_5f0 + local_30 * 0x2e0,(void *)(iVar2 + uVar6 * 0x2d8),0x2d8);
              local_38 = local_38 + -1;
              local_34 = local_34 + 0x170;
            } while (iVar4 != 2);
            FUN_00407f30(apmngr_db_mutex);
            memcpy((void *)((int)param_1 + 0x4e),auStack_980,0x9a);
            local_8e0 = *param_2;
            local_8de = param_2[1];
            memcpy(auStack_8dc,param_3,6);
            memcpy(auStack_8d0,param_1,0x2d8);
            iVar4 = apmngr_db_sqlite_notify_msg(0x11,&local_8e0,0x2e8);
            if (iVar4 == 0) {
              apmngr_evt_notify(7,local_5f8);
              apmngr_evt_notify(7,auStack_318);
              return 0;
            }
            if (apmngr_err_switch == '\0') {
              return 0xffffffff;
            }
            iVar4 = is_target_debug_ap();
            if (iVar4 == 0) {
              return 0xffffffff;
            }
            __format = "[APMNGR_ERROR]%s()/%d Failed to notify sql daemon to create hdap.\n";
            uVar5 = 0xcf1;
            goto LAB_00540798;
          }
        }
        FUN_00407f30(apmngr_db_mutex);
        return 0xffffffff;
      }
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d ap_entry or peer_mac is null.\n";
      uVar5 = 0xca7;
      goto LAB_00540798;
    }
  }
LAB_00540368:
  if ((apmngr_err_switch == '\0') || (iVar4 = is_target_debug_ap(), iVar4 == 0)) {
    return 0xffffffff;
  }
  __format = "[APMNGR_ERROR]%s()/%d Invalid ap ids.\n";
  uVar5 = 0xca2;
LAB_00540798:
  printf(__format,"apmngr_db_hdap_add",uVar5);
  return 0xffffffff;
}

