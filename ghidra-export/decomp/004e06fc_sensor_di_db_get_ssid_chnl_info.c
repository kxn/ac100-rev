// func sensor_di_db_get_ssid_chnl_info @ 004e06fc size=824

void * sensor_di_db_get_ssid_chnl_info(int param_1,short *param_2)

{
  int iVar1;
  short sVar4;
  void *pvVar2;
  int iVar3;
  char *pcVar5;
  undefined4 uVar6;
  short *psVar7;
  void *__s;
  int iVar8;
  int iVar9;
  
  if (sensor_di_debug_switch == 0) {
    *param_2 = 0;
  }
  else {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : db_get_ssid_info ENTER,sensor_id=%d\n",
           "sensor_di_db_get_ssid_chnl_info",0xb09,param_1);
    *param_2 = 0;
  }
  if (param_1 < 0) {
    if (sensor_di_err_switch != 0) {
      pcVar5 = "[SENSOR_DI_ERROR]%s()/line %d : invalid sensor_id\n";
      uVar6 = 0xb14;
LAB_004e09c8:
      printf(pcVar5,"sensor_di_db_get_ssid_chnl_info",uVar6);
    }
  }
  else {
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    iVar1 = _sensor_di_db_get_sensor_node_from_cached_list(param_1);
    if (iVar1 == 0) {
      if (sensor_di_debug_switch != 0) {
        pcVar5 = "[SENSOR_DI_DEBUG]%s()/line %d : sensor node no found\n";
        uVar6 = 0xb1d;
        goto LAB_004e09c8;
      }
    }
    else {
      sVar4 = FUN_00407fe0(iVar1 + 0x18);
      *param_2 = sVar4;
      if (sVar4 < 1) {
        if (sensor_di_debug_switch != 0) {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : ssidinfo_len=%d\n",
                 "sensor_di_db_get_ssid_chnl_info",0xb25);
        }
        FUN_00407f30(l_sensor_di_data_mutex);
        return (void *)0x0;
      }
      __s = (void *)FUN_00408450(sVar4 * 0x3c,0xb2a);
      if (__s != (void *)0x0) {
        iVar9 = 0;
        memset(__s,0,*param_2 * 0x3c);
        iVar1 = FUN_004081b0(iVar1 + 0x18);
        if (iVar1 != 0) {
          sVar4 = *param_2;
          while (iVar9 < sVar4) {
            psVar7 = (short *)((int)__s + iVar9 * 0x3c);
            memcpy(psVar7 + 4,(void *)(iVar1 + 0x18),0x31);
            *(undefined1 *)((int)psVar7 + 0x39) = *(undefined1 *)(iVar1 + 0x49);
            sVar4 = FUN_00407fe0(iVar1 + 0xc);
            psVar7[2] = 0;
            psVar7[3] = 0;
            *psVar7 = sVar4;
            if (sVar4 == 0) {
LAB_004e080c:
              iVar9 = iVar9 + 1;
            }
            else {
              pvVar2 = (void *)FUN_00408450(sVar4 * 0x28,0xb45);
              *(void **)(psVar7 + 2) = pvVar2;
              if (pvVar2 != (void *)0x0) {
                iVar8 = 0;
                memset(pvVar2,0,*psVar7 * 0x28);
                for (pvVar2 = (void *)FUN_004081b0(iVar1 + 0xc); pvVar2 != (void *)0x0;
                    pvVar2 = (void *)FUN_00408680(pvVar2)) {
                  if (*psVar7 <= iVar8) goto LAB_004e080c;
                  iVar3 = iVar8 * 0x28;
                  iVar8 = iVar8 + 1;
                  memcpy((void *)(*(int *)(psVar7 + 2) + iVar3),pvVar2,0x28);
                  *(undefined2 *)(*(int *)(psVar7 + 2) + iVar3 + 0x1a) = 0;
                  *(undefined4 *)(*(int *)(psVar7 + 2) + iVar3 + 0x24) = 0;
                }
                iVar9 = iVar9 + 1;
              }
            }
            iVar1 = FUN_00408680(iVar1);
            if (iVar1 == 0) break;
            sVar4 = *param_2;
          }
        }
        FUN_00407f30(l_sensor_di_data_mutex);
        if (sensor_di_debug_switch == 0) {
          return __s;
        }
        pcVar5 = "[SENSOR_DI_DEBUG]%s()/line %d : db_get_ssid_info success EXIT\n";
        uVar6 = 0xb63;
        goto LAB_004e0988;
      }
      if (sensor_di_debug_switch != 0) {
        pcVar5 = "[SENSOR_DI_DEBUG]%s()/line %d : mem malloc fail\n";
        uVar6 = 0xb2d;
        goto LAB_004e09c8;
      }
    }
  }
  __s = (void *)0x0;
  FUN_00407f30(l_sensor_di_data_mutex);
  if (sensor_di_warning_switch == 0) {
    return (void *)0x0;
  }
  pcVar5 = "[SENSOR_DI_WARNING]%s()/line %d : db_get_ssid_info fail EXIT\n";
  uVar6 = 0xb67;
LAB_004e0988:
  printf(pcVar5,"sensor_di_db_get_ssid_chnl_info",uVar6);
  return __s;
}

