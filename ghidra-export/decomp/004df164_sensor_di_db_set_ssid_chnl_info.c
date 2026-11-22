// func sensor_di_db_set_ssid_chnl_info @ 004df164 size=1540

undefined4 sensor_di_db_set_ssid_chnl_info(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  time_t tVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  void *__dest;
  char cVar8;
  char *__format;
  char *pcVar9;
  undefined4 uVar10;
  int iVar11;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_ssid_chnl_info ENTER,sensor_id=%d\n",
           "sensor_di_db_set_ssid_chnl_info",0x951,param_1);
  }
  iVar2 = FUN_00407fe0(param_2);
  if (iVar2 < 1) {
    if (sensor_di_warning_switch == 0) {
      return 0;
    }
    pcVar9 = "[SENSOR_DI_WARNING]%s()/line %d : intput ssid_info_cnt <= 0\n";
    uVar10 = 0x95c;
  }
  else {
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    iVar2 = _sensor_di_db_check_sensor_exists_in_cached_list(param_1);
    if (iVar2 == 0) {
      if (sensor_di_debug_switch != 0) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor not exists_in cached list\n",
               "sensor_di_db_set_ssid_chnl_info",0x965);
      }
      FUN_00407f30(l_sensor_di_data_mutex);
      return 0;
    }
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_db_clear_aged_ssid_chnl_info ENTER\n",
             "_sensor_di_db_clear_aged_ssid_chnl_info",0x420);
    }
    iVar2 = iVar2 + 0x18;
    tVar3 = time((time_t *)0x0);
    iVar4 = FUN_00407fe0(iVar2);
    if (iVar4 != 0) {
      iVar4 = FUN_004081b0(iVar2);
      while (iVar11 = iVar4, iVar11 != 0) {
        iVar4 = FUN_00408680(iVar11);
        iVar6 = FUN_004081b0(iVar11 + 0xc);
        while (iVar7 = iVar6, iVar7 != 0) {
          iVar6 = FUN_00408680(iVar7);
          if (0x1e < (uint)(tVar3 - *(int *)(iVar7 + 0xc))) {
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : delete aged bssid_node\n",
                     "_sensor_di_db_clear_aged_ssid_chnl_info",0x43e);
            }
            FUN_00408500(iVar7);
            if (*(int *)(iVar7 + 0x24) != 0) {
              FUN_00407df0();
              *(undefined4 *)(iVar7 + 0x24) = 0;
            }
            FUN_00407df0(iVar7);
          }
        }
        iVar6 = FUN_00407fe0(iVar11 + 0xc);
        if (iVar6 == 0) {
          FUN_00408500(iVar11);
          FUN_00407df0(iVar11);
        }
      }
    }
    iVar4 = FUN_004081b0(param_2);
    for (; iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
      pvVar5 = (void *)FUN_004081b0(iVar2);
      if (pvVar5 != (void *)0x0) {
        cVar8 = *(char *)((int)pvVar5 + 0x49);
        while( true ) {
          if ((cVar8 != '\0') && (*(char *)(iVar4 + 0x49) != '\0')) {
            if (sensor_di_debug_switch == 0) {
              iVar11 = 0;
            }
            else {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : ========find matched old ssid_null=======\n",
                     "sensor_di_db_set_ssid_chnl_info",0x986);
              iVar11 = 0;
            }
            goto LAB_004df284;
          }
          if ((*(char *)(iVar4 + 0x49) == '\0') &&
             (iVar11 = strcmp((char *)((int)pvVar5 + 0x18),(char *)(iVar4 + 0x18)), iVar11 == 0)) {
            iVar11 = 0;
            goto LAB_004df284;
          }
          pvVar5 = (void *)FUN_00408680(pvVar5);
          if (pvVar5 == (void *)0x0) break;
          cVar8 = *(char *)((int)pvVar5 + 0x49);
        }
      }
      iVar11 = 1;
LAB_004df284:
      if ((*(char *)(iVar4 + 0x49) != '\0') && (sensor_di_debug_switch != 0)) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : ====== find input ssid_null, new_ssid_flag=%d ===========\n"
               ,"sensor_di_db_set_ssid_chnl_info",0x993,iVar11);
      }
      if (iVar11 == 0) {
LAB_004df2f4:
        iVar11 = (int)pvVar5 + 0xc;
        if (iVar11 == 0) {
          if (sensor_di_err_switch != 0) {
            uVar10 = 0x488;
            __format = "[SENSOR_DI_ERROR]%s()/line %d : input invalid\n";
            pcVar9 = "_sensor_di_db_set_ssid_chnl_info_set_bssidinfo";
LAB_004df39c:
            printf(__format,pcVar9,uVar10);
          }
        }
        else {
          iVar6 = FUN_00407fe0(iVar4 + 0xc);
          if (iVar6 == 0) {
            if (sensor_di_debug_switch != 0) {
              __format = "[SENSOR_DI_DEBUG]%s()/line %d : bssid_cnt <=0\n";
              uVar10 = 0x48e;
              pcVar9 = "_sensor_di_db_set_ssid_chnl_info_set_bssidinfo";
              goto LAB_004df39c;
            }
          }
          else {
            for (iVar6 = FUN_004081b0(iVar4 + 0xc); iVar6 != 0; iVar6 = FUN_00408680(iVar6)) {
              pvVar5 = (void *)FUN_004081b0(iVar11);
              for (; pvVar5 != (void *)0x0; pvVar5 = (void *)FUN_00408680(pvVar5)) {
                iVar7 = memcmp((void *)((int)pvVar5 + 0x1c),(void *)(iVar6 + 0x1c),6);
                if (iVar7 == 0) goto LAB_004df448;
              }
              pvVar5 = (void *)FUN_00408450(0x28,0x4aa);
              if (pvVar5 == (void *)0x0) {
                if (sensor_di_warning_switch != 0) {
                  printf("[SENSOR_DI_WARNING]%s()/line %d : bssid_node mem malloc fail\n",
                         "_sensor_di_db_set_ssid_chnl_info_set_bssidinfo",0x4ad);
                }
              }
              else {
                memset(pvVar5,0,0x28);
                FUN_004086b0(iVar11,pvVar5);
LAB_004df448:
                tVar3 = time((time_t *)0x0);
                *(time_t *)((int)pvVar5 + 0xc) = tVar3;
                *(undefined2 *)((int)pvVar5 + 0x10) = *(undefined2 *)(iVar6 + 0x10);
                *(undefined2 *)((int)pvVar5 + 0x12) = *(undefined2 *)(iVar6 + 0x12);
                *(undefined2 *)((int)pvVar5 + 0x14) = *(undefined2 *)(iVar6 + 0x14);
                *(undefined2 *)((int)pvVar5 + 0x16) = *(undefined2 *)(iVar6 + 0x16);
                *(undefined2 *)((int)pvVar5 + 0x18) = *(undefined2 *)(iVar6 + 0x18);
                memcpy((void *)((int)pvVar5 + 0x1c),(void *)(iVar6 + 0x1c),6);
                *(undefined2 *)((int)pvVar5 + 0x1a) = 0;
                *(undefined4 *)((int)pvVar5 + 0x24) = 0;
                uVar1 = *(ushort *)(iVar6 + 0x1a);
                *(ushort *)((int)pvVar5 + 0x1a) = uVar1;
                if (uVar1 != 0) {
                  __dest = (void *)FUN_00408450((uint)uVar1 * 6,0x464);
                  *(void **)((int)pvVar5 + 0x24) = __dest;
                  if (__dest == (void *)0x0) {
                    if (sensor_di_err_switch != 0) {
                      printf("[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n",
                             "_sensor_di_db_set_ssid_chnl_info_set_stainfo",0x467);
                    }
                    if (sensor_di_err_switch == 0) {
                      iVar7 = *(int *)((int)pvVar5 + 0x24);
                    }
                    else {
                      printf("[SENSOR_DI_ERROR]%s()/line %d : set_ssid_chnl_info_set_bssidinfo fail EXIT\n"
                             ,"_sensor_di_db_set_ssid_chnl_info_set_stainfo",0x474);
                      iVar7 = *(int *)((int)pvVar5 + 0x24);
                    }
                    if (iVar7 != 0) {
                      FUN_00407df0();
                      *(undefined4 *)((int)pvVar5 + 0x24) = 0;
                      *(undefined2 *)((int)pvVar5 + 0x1a) = 0;
                    }
                  }
                  else {
                    memcpy(__dest,*(void **)(iVar6 + 0x24),(uint)*(ushort *)((int)pvVar5 + 0x1a) * 6
                          );
                  }
                }
              }
            }
          }
        }
      }
      else {
        pvVar5 = (void *)FUN_00408450(0x4c,0x998);
        if (pvVar5 != (void *)0x0) {
          memset(pvVar5,0,0x4c);
          FUN_0051ad88((int)pvVar5 + 0xc);
          strncpy((char *)((int)pvVar5 + 0x18),(char *)(iVar4 + 0x18),0x31);
          *(undefined1 *)((int)pvVar5 + 0x49) = *(undefined1 *)(iVar4 + 0x49);
          FUN_004086b0(iVar2,pvVar5);
          goto LAB_004df2f4;
        }
        if (sensor_di_warning_switch != 0) {
          pcVar9 = "sensor_di_db_set_ssid_chnl_info";
          __format = "[SENSOR_DI_WARNING]%s()/line %d : ssid_node mem malloc fail\n";
          uVar10 = 0x99b;
          goto LAB_004df39c;
        }
      }
    }
    FUN_00407f30(l_sensor_di_data_mutex);
    if (sensor_di_debug_switch == 0) {
      return 0;
    }
    pcVar9 = "[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_ssid_chnl_info success EXIT\n";
    uVar10 = 0x9a9;
  }
  printf(pcVar9,"sensor_di_db_set_ssid_chnl_info",uVar10);
  return 0;
}

