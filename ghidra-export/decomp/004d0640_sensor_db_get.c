// func sensor_db_get @ 004d0640 size=608

undefined4 sensor_db_get(uint param_1,void *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  
  param_1 = param_1 & 0xffff;
  if (((param_1 < 50000) || (iVar2 = apmngr_db_get_sensor_max(), iVar2 + 50000 <= (int)param_1)) ||
     (param_2 == (void *)0x0)) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_db_get",0x2b2);
    return 0xffffffff;
  }
  FUN_004082d0(g_sensor_mutex,0xffffffff);
  iVar2 = param_1 * 0x18 + -1200000;
  pvVar4 = (void *)(g_sensor_entry_array + iVar2);
  if (*(char *)((int)pvVar4 + 2) == '\0') {
    if (sensor_warning_switch != '\0') {
      printf("[SENSOR_WARNING]%s()/%d Entry id %d is not used\n","sensor_db_get",0x2b8,param_1);
    }
LAB_004d0814:
    uVar5 = 0xffffffff;
    FUN_00407f30(g_sensor_mutex);
  }
  else {
    memcpy(param_2,pvVar4,0x18);
    if (param_3 != 0) {
      *(undefined4 *)((int)param_2 + 0x10) = 0;
      if ((0 < *(short *)((int)pvVar4 + 0xc)) && (*(int *)((int)pvVar4 + 0x10) != 0)) {
        pvVar4 = (void *)FUN_00408450(*(short *)((int)pvVar4 + 0xc) * 0x14,0x2c2);
        *(void **)((int)param_2 + 0x10) = pvVar4;
        if (pvVar4 != (void *)0x0) {
          memcpy(pvVar4,*(void **)(g_sensor_entry_array + iVar2 + 0x10),
                 *(short *)(g_sensor_entry_array + iVar2 + 0xc) * 0x14);
          goto LAB_004d077c;
        }
        if (sensor_err_switch == '\0') goto LAB_004d0814;
        uVar5 = 0x2c5;
LAB_004d0868:
        printf("[SENSOR_ERROR]%s()/%d Malloc failed\n","sensor_db_get",uVar5);
        goto LAB_004d0814;
      }
LAB_004d077c:
      iVar1 = g_sensor_entry_array;
      *(undefined4 *)((int)param_2 + 0x14) = 0;
      iVar3 = (int)*(short *)(iVar1 + iVar2 + 0xe);
      if ((0 < iVar3) && (*(int *)(iVar1 + iVar2 + 0x14) != 0)) {
        pvVar4 = (void *)FUN_00408450(iVar3 * 0xc,0x2ce);
        *(void **)((int)param_2 + 0x14) = pvVar4;
        if (pvVar4 == (void *)0x0) {
          if (sensor_err_switch == '\0') goto LAB_004d0814;
          uVar5 = 0x2d1;
          goto LAB_004d0868;
        }
        memcpy(pvVar4,*(void **)(g_sensor_entry_array + iVar2 + 0x14),
               *(short *)(g_sensor_entry_array + iVar2 + 0xe) * 0xc);
      }
    }
    uVar5 = 0;
    FUN_00407f30(g_sensor_mutex);
  }
  return uVar5;
}

