// func wips_whitelist_update_with_scan_info @ 004c91b0 size=960

undefined4 wips_whitelist_update_with_scan_info(uint param_1,void *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 local_258;
  uint local_254;
  undefined2 local_250;
  undefined1 auStack_24c [524];
  char *local_40;
  int local_3c;
  int local_38;
  char *local_34;
  uint local_30;
  
  local_30 = param_1 & 0xffff;
  if (g_wips_enable == 0) {
    return 0;
  }
  memset(auStack_24c,0,0x205);
  local_258 = 0;
  local_254 = 0;
  local_250 = 0;
  pcVar2 = (char *)FUN_00408450(param_3 * 0x32,0xaf4);
  iVar3 = FUN_00408450(param_3 << 2,0xaf5);
  iVar4 = FUN_00408450(param_3 * 10,0xaf6);
  iVar5 = FUN_00408450(param_3 * 10,0xaf7);
  uVar8 = 0xffffffff;
  if (pcVar2 != (char *)0x0) {
    if (((iVar3 != 0) && (iVar4 != 0)) && (iVar5 != 0)) {
      iVar11 = 0;
      iVar10 = 0;
      iVar9 = 0;
      for (local_3c = 0; local_3c < param_3; local_3c = local_3c + 1) {
        local_38 = (int)*(char *)((int)param_2 + 0x46);
        local_40 = (char *)(int)*(char *)((int)param_2 + 0xc);
        cVar1 = *(char *)((int)param_2 + 0xb);
        if (((cVar1 != '\x01') && (cVar1 != '\x03')) && (cVar1 != '\x04')) {
          memcpy(&local_258,param_2,6);
          iVar6 = stats_db_bssid_get(&local_258);
          if (iVar6 == 0) {
            if (sensor_debug_switch != '\0') {
              printf("[SENSOR_DEBUG]%s()/%d bssid_info: ap_id: %d, radio_id: %d, wlan_id: %d\n",
                     "wips_whitelist_update_with_scan_info",0xb16,local_254 & 0xffff,
                     (uint)local_250._0_1_,(uint)(byte)local_250);
            }
            if (cVar1 == '\0') {
              iVar6 = iVar10 * 10;
              iVar10 = iVar10 + 1;
              memcpy((void *)(iVar4 + iVar6),&local_258,10);
            }
            else {
              iVar6 = iVar11 * 10;
              iVar11 = iVar11 + 1;
              memcpy((void *)(iVar5 + iVar6),&local_258,10);
            }
          }
        }
        if (local_40 != (char *)0x1) {
          local_40 = (char *)((int)param_2 + 0x14);
          iVar6 = wserv_db_get_entry_by_ssid(local_40,local_38,auStack_24c);
          if (iVar6 == 0) {
            local_34 = pcVar2;
            for (iVar6 = 0; iVar6 < iVar9; iVar6 = iVar6 + 1) {
              iVar7 = strncmp(local_34,local_40,0x32);
              local_34 = local_34 + 0x32;
              if (iVar7 == 0) {
                if ((iVar6 != -1) && (*(int *)(iVar3 + iVar6 * 4) == local_38)) goto LAB_004c9008;
                break;
              }
            }
            strcpy(pcVar2 + iVar9 * 0x32,local_40);
            iVar6 = iVar9 * 4;
            iVar9 = iVar9 + 1;
            *(int *)(iVar3 + iVar6) = local_38;
          }
        }
LAB_004c9008:
        param_2 = (void *)((int)param_2 + 0x48);
      }
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d ssid_list_len: %d\n","wips_whitelist_update_with_scan_info",
               0xb44,iVar9);
      }
      if (iVar9 != 0) {
        wips_ssid_whitelist_add_send(pcVar2,iVar3,iVar9,local_30);
      }
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d bssid_list_len: %d\n","wips_whitelist_update_with_scan_info",
               0xb49,iVar10);
      }
      if (iVar10 != 0) {
        FUN_004c8a08(iVar4,iVar10,local_30);
      }
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d update_bssid_list_len: %d\n",
               "wips_whitelist_update_with_scan_info",0xb4f,iVar11);
      }
      uVar8 = 0;
      if (iVar11 != 0) {
        FUN_004c8a08(iVar5,iVar11,local_30);
      }
    }
    FUN_00407df0(pcVar2);
  }
  if (iVar3 != 0) {
    FUN_00407df0(iVar3);
  }
  if (iVar4 != 0) {
    FUN_00407df0(iVar4);
  }
  if (iVar5 != 0) {
    FUN_00407df0(iVar5);
  }
  return uVar8;
}

