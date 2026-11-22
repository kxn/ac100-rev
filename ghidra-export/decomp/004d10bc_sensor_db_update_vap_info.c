// func sensor_db_update_vap_info @ 004d10bc size=948

undefined4 sensor_db_update_vap_info(ushort param_1,short param_2,byte *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  void *pvVar8;
  char *__format;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  uVar12 = (uint)param_1;
  iVar13 = (int)param_2;
  if (((uVar12 < 50000) || (iVar7 = apmngr_db_get_sensor_max(), iVar7 + 50000 <= (int)uVar12)) ||
     ((0 < iVar13 && (param_3 == (byte *)0x0)))) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_db_update_vap_info",0x373);
    return 0xffffffff;
  }
  FUN_004082d0(g_sensor_mutex,0xffffffff);
  iVar10 = uVar12 * 0x18 + -1200000;
  iVar7 = g_sensor_entry_array + iVar10;
  if (*(char *)(iVar7 + 2) == '\0') {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Entry id %d is not used\n","sensor_db_update_vap_info",0x379,
             uVar12);
    }
LAB_004d13a0:
    uVar9 = 0xffffffff;
    FUN_00407f30(g_sensor_mutex);
  }
  else {
    if ((*(short *)(iVar7 + 0xe) != 0) && (iVar11 = 0, *(int *)(iVar7 + 0x14) != 0)) {
      for (; iVar7 = g_sensor_entry_array + iVar10, iVar11 < *(short *)(iVar7 + 0xe);
          iVar11 = iVar11 + 1) {
        iVar7 = FUN_00407fa0(g_sensor_vap_hash,*(int *)(iVar7 + 0x14) + iVar11 * 0xc);
        if (iVar7 != 0) {
          FUN_00407f40(g_sensor_vap_hash,iVar7);
          FUN_00407df0(iVar7);
        }
      }
      FUN_00407df0(*(undefined4 *)(iVar7 + 0x14));
      *(undefined4 *)(g_sensor_entry_array + iVar10 + 0x14) = 0;
    }
    iVar7 = g_sensor_entry_array + iVar10;
    *(short *)(iVar7 + 0xe) = param_2;
    if (0 < iVar13) {
      uVar9 = FUN_00408450(iVar13 * 0xc,0x38d);
      *(undefined4 *)(iVar7 + 0x14) = uVar9;
      pvVar8 = *(void **)(g_sensor_entry_array + iVar10 + 0x14);
      if (pvVar8 == (void *)0x0) {
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d Malloc failed\n","sensor_db_update_vap_info",0x390);
        }
        *(undefined2 *)(g_sensor_entry_array + iVar10 + 0xe) = 0;
        goto LAB_004d13a0;
      }
      memcpy(pvVar8,param_3,iVar13 * 0xc);
      iVar13 = 0;
      while (iVar13 < *(short *)(g_sensor_entry_array + iVar10 + 0xe)) {
        iVar7 = FUN_00407fa0(g_sensor_vap_hash,param_3);
        if (iVar7 == 0) {
          pvVar8 = (void *)FUN_00408450(0x10,0x39d);
          if (pvVar8 == (void *)0x0) {
            if (sensor_err_switch == '\0') goto LAB_004d13a0;
            __format = "[SENSOR_ERROR]%s()/%d Malloc failed\n";
            uVar9 = 0x3a0;
          }
          else {
            memset(pvVar8,0,0x10);
            memcpy(pvVar8,param_3,0xc);
            uVar9 = g_sensor_vap_hash;
            *(ushort *)((int)pvVar8 + 0xc) = param_1;
            iVar7 = FUN_00408380(uVar9,pvVar8);
            if (iVar7 == 0) goto LAB_004d12e0;
            FUN_00407df0(pvVar8);
            if (sensor_err_switch == '\0') goto LAB_004d13a0;
            __format = "[SENSOR_ERROR]%s()/%d Add bssid item to hash failed\n";
            uVar9 = 0x3aa;
          }
          printf(__format,"sensor_db_update_vap_info",uVar9);
          goto LAB_004d13a0;
        }
        if (sensor_err_switch == '\0') {
LAB_004d12e0:
          iVar13 = iVar13 + 1;
          param_3 = param_3 + 0xc;
        }
        else {
          pbVar1 = param_3 + 1;
          bVar6 = *param_3;
          pbVar2 = param_3 + 2;
          iVar13 = iVar13 + 1;
          pbVar3 = param_3 + 3;
          pbVar4 = param_3 + 4;
          pbVar5 = param_3 + 5;
          param_3 = param_3 + 0xc;
          printf("[SENSOR_ERROR]%s()/%d Bssid[[%02x:%02x:%02x:%02x:%02x:%02x]] conflict,add to hash failed\n"
                 ,"sensor_db_update_vap_info",0x39a,(uint)bVar6,(uint)*pbVar1,(uint)*pbVar2,
                 (uint)*pbVar3,(uint)*pbVar4,(uint)*pbVar5);
        }
      }
    }
    uVar9 = 0;
    FUN_00407f30(g_sensor_mutex);
  }
  return uVar9;
}

