// func sensor_di_db_set_rssi_freq_time @ 004dfb64 size=1696

/* WARNING: Removing unreachable block (ram,0x004dfd38) */
/* WARNING: Removing unreachable block (ram,0x004dfc58) */
/* WARNING: Removing unreachable block (ram,0x004dfd70) */

undefined4 sensor_di_db_set_rssi_freq_time(undefined4 param_1,short *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  short sVar12;
  void *__dest;
  int iVar13;
  char *pcVar14;
  undefined2 *puVar15;
  int iVar16;
  int iVar17;
  size_t sVar18;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_rssi_freq_time ENTER,sensor_id=%d\n",
           "sensor_di_db_set_rssi_freq_time",0xa1e,param_1);
  }
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  iVar3 = _sensor_di_db_check_sensor_exists_in_cached_list(param_1);
  if (iVar3 == 0) {
    if (sensor_di_warning_switch != 0) {
      printf("[SENSOR_DI_WARNING]%s()/line %d : sensor not exists_in cached list\n",
             "sensor_di_db_set_rssi_freq_time",0xa28);
    }
    FUN_00407f30(l_sensor_di_data_mutex);
    return 0;
  }
  iVar11 = (int)*(short *)(iVar3 + 0x14);
  if (iVar11 < 0x78) {
    __dest = (void *)(iVar3 + 0x10d52);
    iVar7 = 0x77;
    if (*param_2 / 5 < 0x78) {
      iVar7 = (int)(*param_2 / 5);
    }
    memcpy((void *)((int)__dest + iVar7 * 0x188),param_2,0x188);
    if (iVar11 < iVar7) {
      if (iVar11 < 0) {
        iVar11 = 0;
      }
      else {
        if (iVar11 != 0) {
          for (iVar13 = 0; iVar13 + iVar11 < iVar7; iVar13 = iVar13 + 1) {
            memcpy((void *)((int)__dest + (iVar13 + iVar11) * 0x188),
                   (void *)((int)__dest + (iVar11 + -1) * 0x188),0x188);
          }
          goto LAB_004dfcec;
        }
        iVar11 = 0;
      }
      for (; iVar11 < iVar7; iVar11 = iVar11 + 1) {
        memcpy(__dest,param_2,0x188);
        __dest = (void *)((int)__dest + 0x188);
      }
      *(short *)(iVar3 + 0x14) = (short)iVar7 + 1;
    }
    else {
LAB_004dfcec:
      *(short *)(iVar3 + 0x14) = (short)iVar7 + 1;
    }
  }
  iVar11 = (int)*(short *)(iVar3 + 0x14);
  if ((iVar11 - 3U & 0xffff) < 7) {
    sVar18 = iVar11 << 2;
    puVar15 = (undefined2 *)(iVar3 + 0x31f2);
    if (iVar11 == 0) {
      trap(7);
    }
    puVar4 = (undefined4 *)FUN_00408450(sVar18,0x365);
    if (puVar4 == (undefined4 *)0x0) {
      if (sensor_di_err_switch == 0) {
        iVar11 = (int)*(short *)(iVar3 + 0x14);
      }
      else {
        printf("[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n",
               "_sensor_di_db_set_freq_density_lower_then_ten",0x368);
        iVar11 = (int)*(short *)(iVar3 + 0x14);
      }
    }
    else {
      memset(puVar4,0,sVar18);
      iVar7 = 0xc;
      uVar1 = *(undefined2 *)(iVar3 + 0x10d54);
      uVar2 = *(undefined2 *)(iVar3 + 0x10d56);
      sVar12 = *(short *)(iVar3 + 0x10d58);
      puVar5 = puVar15;
      do {
        iVar7 = iVar7 + -1;
        *puVar5 = uVar1;
        puVar5[1] = uVar2;
        puVar5[2] = sVar12;
        puVar5 = puVar5 + 0xc3;
      } while (iVar7 != 0);
      for (iVar7 = 0; iVar7 < sVar12; iVar7 = iVar7 + 1) {
        memset(puVar4,0,sVar18);
        iVar16 = 0;
        iVar13 = 0;
        pcVar14 = (char *)(iVar3 + iVar7 + 0x10d5a);
        do {
          iVar17 = _sensor_di_db_sort_array_by_ascending_order((int)*pcVar14,puVar4,iVar13,iVar11);
          if (iVar17 == -1) {
            if (sensor_di_err_switch != 0) {
              printf("[SENSOR_DI_ERROR]%s()/line %d : insert tmp_array fail\n",
                     "_sensor_di_db_set_freq_density_lower_then_ten",900);
            }
            goto LAB_004e01f4;
          }
          iVar13 = iVar13 + 1;
          iVar16 = iVar16 + *pcVar14;
          pcVar14 = pcVar14 + 0x188;
        } while (iVar13 < iVar11);
        iVar9 = 0;
        iVar13 = 0;
        iVar6 = 0;
        iVar17 = 0;
        do {
          if (iVar17 == 0) {
            *(char *)(puVar15 + 3) = (char)*puVar4;
          }
          else if (iVar6 < 10 / iVar11) {
            iVar6 = iVar6 + 1;
            if (iVar11 <= iVar13) {
              iVar13 = iVar11 + -1;
            }
            *(char *)((int)puVar15 + iVar9 + 6) = (char)puVar4[iVar13];
          }
          else {
            iVar13 = iVar13 + 1;
            if (iVar11 <= iVar13) {
              iVar13 = iVar11 + -1;
            }
            *(char *)((int)puVar15 + iVar9 + 6) = (char)puVar4[iVar13];
            iVar6 = 1;
          }
          iVar17 = iVar17 + 1;
          iVar9 = iVar9 + 0x186;
        } while (iVar17 != 0xb);
        if (iVar11 == 0) {
          trap(7);
        }
        *(char *)(puVar15 + 0x864) = (char)(iVar16 / iVar11);
        puVar15 = (undefined2 *)((int)puVar15 + 1);
      }
LAB_004e01f4:
      FUN_00407df0(puVar4);
      iVar11 = (int)*(short *)(iVar3 + 0x14);
    }
  }
  else {
    iVar11 = (int)*(short *)(iVar3 + 0x14);
  }
  if (9 < iVar11) {
    puVar15 = (undefined2 *)(iVar3 + 0x31f2);
    sVar12 = (short)(iVar11 / 10) * 10;
    iVar11 = (int)sVar12;
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_db_set_freq_density ENTER, waterfall_cnt=%d\n"
             ,"_sensor_di_db_set_freq_density",0x3c3,iVar11);
    }
    if (iVar11 % 10 == 0) {
      sVar18 = iVar11 << 2;
      puVar4 = (undefined4 *)FUN_00408450(sVar18,0x3d4);
      if (puVar4 == (undefined4 *)0x0) {
        if (sensor_di_err_switch != 0) {
          pcVar14 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
          uVar10 = 0x3d7;
LAB_004e0120:
          printf(pcVar14,"_sensor_di_db_set_freq_density",uVar10);
        }
LAB_004e0058:
        if (sensor_di_debug_switch != 0) {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_db_set_freq_density fail EXIT\n",
                 "_sensor_di_db_set_freq_density",0x414);
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_004dfc00;
      }
      else {
        memset(puVar4,0,sVar18);
        iVar13 = (int)(sVar12 / 10);
        iVar7 = 0xc;
        uVar1 = *(undefined2 *)(iVar3 + 0x10d54);
        uVar2 = *(undefined2 *)(iVar3 + 0x10d56);
        sVar12 = *(short *)(iVar3 + 0x10d58);
        puVar5 = puVar15;
        do {
          iVar7 = iVar7 + -1;
          *puVar5 = uVar1;
          puVar5[1] = uVar2;
          puVar5[2] = sVar12;
          puVar5 = puVar5 + 0xc3;
        } while (iVar7 != 0);
        for (iVar7 = 0; iVar7 < sVar12; iVar7 = iVar7 + 1) {
          memset(puVar4,0,sVar18);
          iVar17 = 0;
          iVar16 = 0;
          pcVar14 = (char *)(iVar3 + iVar7 + 0x10d5a);
          do {
            iVar6 = _sensor_di_db_sort_array_by_ascending_order((int)*pcVar14,puVar4,iVar16,iVar11);
            if (iVar6 == -1) {
              if (sensor_di_err_switch == 0) goto LAB_004e0058;
              pcVar14 = "[SENSOR_DI_ERROR]%s()/line %d : insert tmp_array fail\n";
              uVar10 = 0x3f4;
              goto LAB_004e0120;
            }
            iVar16 = iVar16 + 1;
            iVar17 = iVar17 + *pcVar14;
            pcVar14 = pcVar14 + 0x188;
          } while (iVar16 < iVar11);
          iVar16 = 0;
          iVar6 = 0;
          puVar8 = puVar4;
          do {
            if (iVar6 < iVar11) {
              *(char *)((int)puVar15 + iVar16 + 6) = (char)*puVar8;
            }
            iVar16 = iVar16 + 0x186;
            iVar6 = iVar6 + iVar13;
            puVar8 = puVar8 + iVar13;
          } while (iVar16 != 0xf3c);
          if (iVar11 == 0) {
            trap(7);
          }
          *(char *)(puVar15 + 0x7a1) = (char)puVar4[iVar11 + -1];
          *(char *)(puVar15 + 0x864) = (char)(iVar17 / iVar11);
          puVar15 = (undefined2 *)((int)puVar15 + 1);
        }
      }
      FUN_00407df0(puVar4);
    }
  }
LAB_004dfc00:
  FUN_00407f30(l_sensor_di_data_mutex);
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_rssi_freq_time success EXIT\n",
           "sensor_di_db_set_rssi_freq_time",0xa61);
  }
  return 0;
}

