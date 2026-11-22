// func sensor_di_db_get_chnls_util_info @ 004e0204 size=764

undefined1 * sensor_di_db_get_chnls_util_info(int param_1,undefined2 *param_2)

{
  byte *pbVar1;
  ushort *puVar2;
  undefined1 *puVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  undefined1 *__s;
  undefined1 *puVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  byte *pbVar18;
  int iVar19;
  ushort *puVar20;
  int iVar21;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : db_get_chnls_util_info ENTER,sensor_id=%d\n",
           "sensor_di_db_get_chnls_util_info",0xa6a,param_1);
  }
  if (param_1 < 0) {
    if (sensor_di_err_switch != 0) {
      pcVar9 = "[SENSOR_DI_ERROR]%s()/line %d : invalid sensor_id\n";
      uVar14 = 0xa78;
LAB_004e04cc:
      printf(pcVar9,"sensor_di_db_get_chnls_util_info",uVar14);
    }
  }
  else {
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    iVar6 = _sensor_di_db_get_sensor_node_from_cached_list(param_1);
    if (iVar6 == 0) {
      if (sensor_di_debug_switch != 0) {
        pcVar9 = "[SENSOR_DI_DEBUG]%s()/line %d : sensor node no found\n";
        uVar14 = 0xa81;
        goto LAB_004e04cc;
      }
    }
    else {
      *param_2 = *(undefined2 *)(iVar6 + 0x10);
      __s = (undefined1 *)FUN_00408450(0xfa,0xa87);
      if (__s != (undefined1 *)0x0) {
        memset(__s,0,0xfa);
        iVar8 = 0;
        puVar7 = __s;
        iVar10 = iVar6;
        do {
          if (*(short *)(iVar6 + 0x10) <= iVar8) break;
          uVar11 = (uint)*(ushort *)(iVar10 + 0x24);
          uVar12 = 1;
          if ((uVar11 != 0) && (uVar12 = uVar11, 2 < uVar11)) {
            uVar12 = 3;
          }
          iVar13 = 0;
          iVar15 = 0;
          iVar16 = 0;
          iVar17 = 0;
          iVar19 = 0;
          iVar21 = 0;
          pbVar18 = (byte *)(iVar6 + iVar8 * 0x1c + 0x27);
          puVar20 = (ushort *)(iVar6 + iVar8 * 0x1c + 0x34);
          do {
            iVar21 = iVar21 + 1;
            iVar19 = iVar19 + (uint)*pbVar18;
            pbVar1 = pbVar18 + 3;
            pbVar18 = pbVar18 + 1;
            iVar17 = iVar17 + (uint)*pbVar1;
            iVar16 = iVar16 + (uint)puVar20[-3];
            iVar15 = iVar15 + (uint)*puVar20;
            puVar2 = puVar20 + 3;
            puVar20 = puVar20 + 1;
            iVar13 = iVar13 + (uint)*puVar2;
          } while (iVar21 != 3);
          if (uVar12 == 0) {
            trap(7);
          }
          if (uVar12 == 0) {
            trap(7);
          }
          cVar5 = (char)(iVar19 / (int)uVar12);
          puVar7[1] = cVar5;
          if (uVar12 == 0) {
            trap(7);
          }
          cVar4 = (char)(iVar17 / (int)uVar12);
          puVar7[2] = cVar4;
          puVar7[3] = ('d' - cVar5) - cVar4;
          *(short *)(puVar7 + 4) = (short)(iVar16 / (int)uVar12);
          if ((iVar16 / (int)uVar12 & 0xffffU) == 0) {
            *(short *)(puVar7 + 4) = (short)(iVar16 % (int)uVar12);
          }
          if (uVar12 == 0) {
            trap(7);
          }
          *(short *)(puVar7 + 6) = (short)(iVar15 / (int)uVar12);
          if ((iVar15 / (int)uVar12 & 0xffffU) == 0) {
            *(short *)(puVar7 + 6) = (short)(iVar15 % (int)uVar12);
          }
          if (uVar12 == 0) {
            trap(7);
          }
          *(short *)(puVar7 + 8) = (short)(iVar13 / (int)uVar12);
          if ((iVar13 / (int)uVar12 & 0xffffU) == 0) {
            *(short *)(puVar7 + 8) = (short)(iVar13 % (int)uVar12);
          }
          puVar3 = (undefined1 *)(iVar10 + 0x26);
          iVar8 = iVar8 + 1;
          iVar10 = iVar10 + 0x1c;
          *puVar7 = *puVar3;
          puVar7 = puVar7 + 10;
        } while (iVar8 != 0x19);
        FUN_00407f30(l_sensor_di_data_mutex);
        if (sensor_di_debug_switch == 0) {
          return __s;
        }
        pcVar9 = "[SENSOR_DI_DEBUG]%s()/line %d : db_get_chnls_util_info success EXIT\n";
        uVar14 = 0xac8;
        goto LAB_004e0450;
      }
      if (sensor_di_debug_switch != 0) {
        pcVar9 = "[SENSOR_DI_DEBUG]%s()/line %d : mem malloc fail\n";
        uVar14 = 0xa8a;
        goto LAB_004e04cc;
      }
    }
  }
  __s = (undefined1 *)0x0;
  FUN_00407f30(l_sensor_di_data_mutex);
  if (sensor_di_warning_switch == 0) {
    return (undefined1 *)0x0;
  }
  pcVar9 = "[SENSOR_DI_WARNING]%s()/line %d : db_get_chnls_util_info fail EXIT\n";
  uVar14 = 0xacc;
LAB_004e0450:
  printf(pcVar9,"sensor_di_db_get_chnls_util_info",uVar14);
  return __s;
}

