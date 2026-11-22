// func sensor_db_add @ 004d0164 size=852

undefined4 sensor_db_add(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  uint uVar5;
  
  uVar1 = *param_1;
  if (((uVar1 < 50000) || (iVar2 = apmngr_db_get_sensor_max(), iVar2 + 50000 <= (int)(uint)uVar1))
     || ((0 < (short)param_1[6] && (*(int *)(param_1 + 8) == 0)))) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_db_add",0x262);
    return 0xffffffff;
  }
  FUN_004082d0(g_sensor_mutex,0xffffffff);
  iVar2 = g_sensor_entry_array;
  pvVar4 = (void *)(g_sensor_entry_array + (uint)*param_1 * 0x18 + -1200000);
  if (*(char *)((int)pvVar4 + 2) != '\0') {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Entry id %d is already used\n","sensor_db_add",0x268);
    }
    goto LAB_004d03b8;
  }
  memcpy(pvVar4,param_1,0x18);
  *(undefined4 *)(iVar2 + (uint)*param_1 * 0x18 + -0x124f70) = 0;
  if ((short)param_1[6] < 1) {
LAB_004d02cc:
    iVar2 = g_sensor_entry_array;
    *(undefined4 *)(g_sensor_entry_array + (uint)*param_1 * 0x18 + -0x124f6c) = 0;
    if ((short)param_1[7] < 1) {
LAB_004d0350:
      uVar3 = g_sensor_mutex;
      *(undefined1 *)(g_sensor_entry_array + (uint)*param_1 * 0x18 + -0x124f7e) = 1;
      FUN_00407f30(uVar3);
      return 0;
    }
    uVar1 = *param_1;
    uVar3 = FUN_00408450((short)param_1[7] * 0xc,0x27d);
    *(undefined4 *)(iVar2 + (uint)uVar1 * 0x18 + -0x124f6c) = uVar3;
    pvVar4 = *(void **)(g_sensor_entry_array + (uint)*param_1 * 0x18 + -0x124f6c);
    if (pvVar4 != (void *)0x0) {
      memcpy(pvVar4,*(void **)(param_1 + 10),(short)param_1[7] * 0xc);
      goto LAB_004d0350;
    }
    if (sensor_err_switch == '\0') {
      uVar1 = *param_1;
    }
    else {
      printf("[SENSOR_ERROR]%s()/%d Malloc failed\n","sensor_db_add",0x280);
      uVar1 = *param_1;
    }
    if (*(int *)(g_sensor_entry_array + (uint)uVar1 * 0x18 + -0x124f70) == 0) {
      uVar5 = (uint)*param_1;
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(g_sensor_entry_array + (uint)*param_1 * 0x18 + -0x124f70) = 0;
      uVar5 = (uint)*param_1;
    }
  }
  else {
    uVar1 = *param_1;
    uVar3 = FUN_00408450((short)param_1[6] * 0x14,0x270);
    *(undefined4 *)(iVar2 + (uint)uVar1 * 0x18 + -0x124f70) = uVar3;
    pvVar4 = *(void **)(g_sensor_entry_array + (uint)*param_1 * 0x18 + -0x124f70);
    if (pvVar4 != (void *)0x0) {
      memcpy(pvVar4,*(void **)(param_1 + 8),(short)param_1[6] * 0x14);
      goto LAB_004d02cc;
    }
    if (sensor_err_switch == '\0') {
      uVar5 = (uint)*param_1;
    }
    else {
      printf("[SENSOR_ERROR]%s()/%d Malloc failed\n","sensor_db_add",0x273);
      uVar5 = (uint)*param_1;
    }
  }
  memset((void *)(g_sensor_entry_array + uVar5 * 0x18 + -1200000),0,0x18);
LAB_004d03b8:
  FUN_00407f30(g_sensor_mutex);
  return 0xffffffff;
}

