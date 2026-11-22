// func sensor_di_db_set_single_chnl_util_info @ 004df768 size=372

undefined4
sensor_di_db_set_single_chnl_util_info
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  char local_res4;
  
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  iVar1 = _sensor_di_db_check_sensor_exists_in_cached_list(param_1);
  if (iVar1 == 0) {
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor not exists_in cached list\n",
             "sensor_di_db_set_single_chnl_util_info",0x9b8);
    }
  }
  else {
    local_res4 = (char)((uint)param_2 >> 0x18);
    iVar5 = 0;
    iVar3 = iVar1;
    do {
      if (*(char *)(iVar3 + 0x26) == local_res4) {
        iVar3 = iVar1 + iVar5 * 0x1c;
        uVar7 = (uint)*(ushort *)(iVar3 + 0x24);
        uVar8 = (undefined1)((uint)param_2 >> 0x10);
        uVar9 = (undefined1)((uint)param_2 >> 8);
        uVar10 = (undefined2)((uint)param_3 >> 0x10);
        uVar11 = (undefined2)((uint)param_4 >> 0x10);
        uVar6 = 3;
        if ((uVar7 < 3) && (uVar6 = uVar7, uVar7 == 0)) {
          *(undefined1 *)(iVar3 + 0x27) = uVar8;
          *(undefined1 *)(iVar3 + 0x2a) = uVar9;
          *(undefined2 *)(iVar3 + 0x2e) = uVar10;
          *(short *)(iVar3 + 0x34) = (short)param_3;
          *(undefined2 *)(iVar3 + 0x3a) = uVar11;
        }
        else {
          puVar4 = (undefined1 *)(iVar1 + iVar5 * 0x1c + 0x27);
          puVar2 = (undefined2 *)(iVar1 + iVar5 * 0x1c + 0x34);
          iVar1 = 0;
          do {
            iVar1 = iVar1 + 1;
            *puVar4 = uVar8;
            puVar4[3] = uVar9;
            puVar4 = puVar4 + 1;
            puVar2[-3] = uVar10;
            *puVar2 = (short)param_3;
            puVar2[3] = uVar11;
            puVar2 = puVar2 + 1;
          } while (iVar1 < (int)uVar6);
        }
        break;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x1c;
    } while (iVar5 != 0x19);
  }
  FUN_00407f30(l_sensor_di_data_mutex);
  return 0;
}

