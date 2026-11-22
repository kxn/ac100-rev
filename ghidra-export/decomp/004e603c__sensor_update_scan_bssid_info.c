// func _sensor_update_scan_bssid_info @ 004e603c size=1164

undefined4 _sensor_update_scan_bssid_info(uint param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  uint extraout_v1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *__src;
  uint uVar7;
  int local_1f78;
  undefined1 auStack_1f74 [4000];
  undefined1 auStack_fd4 [16];
  uint local_fc4 [997];
  uint local_30;
  int local_2c;
  
  memset(auStack_fd4,0,4000);
  memset(auStack_1f74,0,4000);
  local_1f78 = 0;
  if ((param_2 < 1) || ((param_3 != (void *)0x0 && (param_4 != 0)))) {
    uVar7 = param_1 & 0xffff;
    iVar1 = sensor_db_scan_bssid_get(uVar7,auStack_fd4,200,&local_1f78);
    if (iVar1 == 0) {
      local_2c = local_1f78;
      iVar1 = FUN_004080a0(_sensor_scan_bssid_hash_obj,_sensor_scan_bssid_hash_key_func,
                           _sensor_scan_bssid_hash_cmp_func,400);
      if (iVar1 != 0) {
        iVar4 = 0;
        FUN_00407e70();
        iVar6 = 0;
        local_30 = extraout_v1;
        while (iVar6 < param_2) {
          iVar5 = FUN_00407fa0(iVar1,param_3);
          if (iVar5 == 0) {
            if (199 < iVar4) {
              iVar6 = 0;
              if (sensor_warning_switch != '\0') {
                printf("[SENSOR_WARNING]%s()/%d neighbor num exceeds.\n",
                       "_sensor_update_scan_bssid_merge",0x4ca);
                iVar6 = 0;
              }
              goto LAB_004e6328;
            }
            memcpy(auStack_1f74 + iVar4 * 0x14,param_3,0x14);
            iVar5 = FUN_00408380(iVar1,auStack_1f74 + iVar4 * 0x14);
            if (iVar5 != 0) {
              if (sensor_err_switch == '\0') goto LAB_004e6424;
              uVar3 = 0x4d1;
              goto LAB_004e643c;
            }
            iVar4 = iVar4 + 1;
            iVar6 = iVar6 + 1;
            param_3 = (void *)((int)param_3 + 0x14);
          }
          else {
            iVar6 = iVar6 + 1;
            param_3 = (void *)((int)param_3 + 0x14);
          }
        }
        __src = auStack_fd4;
        iVar5 = 0;
LAB_004e6260:
        do {
          iVar6 = 0;
          if (local_2c <= iVar5) {
LAB_004e6328:
            FUN_00408310(iVar1);
            if (iVar6 == 0) {
              iVar1 = sensor_db_update_scan_bssid_info(uVar7,(int)(short)iVar4,auStack_1f74);
              if (iVar1 == 0) {
                if (sensor_debug_switch != '\0') {
                  uVar3 = FUN_00407fe0(&l_scan_bssid_callback_list);
                  printf("[SENSOR_DEBUG]%s()/%d callback list length:%d\n",
                         "_sensor_update_scan_bssid_proc_callback_list",0x48b,uVar3);
                }
                for (iVar1 = FUN_004081b0(&l_scan_bssid_callback_list); iVar1 != 0;
                    iVar1 = FUN_00408680(iVar1)) {
                  if (((*(code **)(iVar1 + 0xc) != (code *)0x0) &&
                      (iVar4 = (**(code **)(iVar1 + 0xc))(uVar7,param_4,param_2), iVar4 == -1)) &&
                     (sensor_debug_switch != '\0')) {
                    printf("[SENSOR_DEBUG]%s()/%d process callback update_all for module failed.\n",
                           "_sensor_update_scan_bssid_proc_callback_list",0x495);
                  }
                }
                return 0;
              }
              if (sensor_err_switch == '\0') {
                return 0xffffffff;
              }
              pcVar2 = "[SENSOR_ERROR]%s()/%d sensor_db_update_scan_bssid_info failed\n";
              uVar3 = 0x50d;
              goto LAB_004e6134;
            }
            goto LAB_004e6234;
          }
          if ((local_30 <= local_fc4[iVar5 * 5]) || (local_30 - local_fc4[iVar5 * 5] < 0x709)) {
            iVar6 = FUN_00407fa0(iVar1);
            if (iVar6 != 0) goto LAB_004e62b0;
            if (iVar4 < 200) {
              memcpy(auStack_1f74 + iVar4 * 0x14,__src,0x14);
              iVar6 = FUN_00408380(iVar1,auStack_1f74 + iVar4 * 0x14);
              if (iVar6 == 0) goto code_r0x004e62f0;
              if (sensor_err_switch == '\0') {
LAB_004e6424:
                iVar4 = 0;
                iVar6 = -1;
              }
              else {
                uVar3 = 0x4e6;
LAB_004e643c:
                iVar4 = 0;
                printf("[SENSOR_ERROR]%s()/%d add scan bssid to hash failed.\n",
                       "_sensor_update_scan_bssid_merge",uVar3);
                iVar6 = -1;
              }
            }
            else {
              iVar6 = 0;
              if (sensor_warning_switch != '\0') {
                printf("[SENSOR_WARNING]%s()/%d neighbor num exceeds.\n",
                       "_sensor_update_scan_bssid_merge",0x4e0);
              }
            }
            goto LAB_004e6328;
          }
LAB_004e62b0:
          iVar5 = iVar5 + 1;
          __src = __src + 0x14;
        } while( true );
      }
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d Create scan bssid hash failed.\n",
               "_sensor_update_scan_bssid_merge",0x4bf);
      }
LAB_004e6234:
      if (sensor_err_switch != '\0') {
        pcVar2 = "[SENSOR_ERROR]%s()/%d _sensor_update_scan_bssid_merge of sensor %d failed\n";
        uVar3 = 0x508;
        goto LAB_004e61c8;
      }
    }
    else if (sensor_err_switch != '\0') {
      pcVar2 = "[SENSOR_ERROR]%s()/%d sensor_db_scan_bssid_get of sensor %d failed\n";
      uVar3 = 0x503;
LAB_004e61c8:
      printf(pcVar2,"_sensor_update_scan_bssid_info",uVar3,param_1);
      return 0xffffffff;
    }
  }
  else if (sensor_err_switch != '\0') {
    pcVar2 = "[SENSOR_ERROR]%s()/%d Input error\n";
    uVar3 = 0x4fd;
LAB_004e6134:
    printf(pcVar2,"_sensor_update_scan_bssid_info",uVar3);
    return 0xffffffff;
  }
  return 0xffffffff;
code_r0x004e62f0:
  iVar4 = iVar4 + 1;
  iVar5 = iVar5 + 1;
  __src = __src + 0x14;
  goto LAB_004e6260;
}

