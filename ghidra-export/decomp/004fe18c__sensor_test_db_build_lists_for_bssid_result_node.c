// func _sensor_test_db_build_lists_for_bssid_result_node @ 004fe18c size=1068

undefined4 _sensor_test_db_build_lists_for_bssid_result_node(int param_1,ushort *param_2)

{
  byte bVar1;
  ushort uVar3;
  void *pvVar2;
  undefined4 uVar4;
  int iVar5;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_db_build_lists_for_bssid_result_node ENTER\n",
           "_sensor_test_db_build_lists_for_bssid_result_node",0x95c);
  }
  if ((param_1 == 0) || (param_2 == (ushort *)0x0)) {
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_TEST_ERROR]%s()/%d input invalid\n",
           "_sensor_test_db_build_lists_for_bssid_result_node",0x961);
    return 0xffffffff;
  }
  FUN_0051ad88(param_1 + 0x48);
  FUN_0051ad88(param_1 + 0x54);
  FUN_0051ad88(param_1 + 0x60);
  FUN_0051ad88(param_1 + 0x6c);
  FUN_0051ad88(param_1 + 0x78);
  if ((*param_2 & 4) == 0) {
    uVar3 = *param_2;
LAB_004fe21c:
    if ((uVar3 & 0x10) == 0) {
      uVar3 = *param_2;
    }
    else {
      bVar1 = *(byte *)(*(int *)(param_2 + 8) + 3);
      *(undefined4 *)(param_1 + 0x88) = 0;
      *(byte *)(param_1 + 0x96) = bVar1;
      if (bVar1 == 0) {
        uVar3 = *param_2;
      }
      else {
        pvVar2 = (void *)FUN_00408450((uint)bVar1 * 0xc,0x98b);
        *(void **)(param_1 + 0x88) = pvVar2;
        if (pvVar2 == (void *)0x0) {
          if (sensor_test_err_switch == '\0') goto LAB_004fe498;
          uVar4 = 0x98e;
          goto LAB_004fe544;
        }
        memset(pvVar2,0,(uint)*(byte *)(param_1 + 0x96) * 0xc);
        bVar1 = *(byte *)(param_1 + 0x96);
        for (iVar5 = 0; iVar5 < (int)(uint)bVar1; iVar5 = iVar5 + 1) {
          FUN_0051ad88(*(int *)(param_1 + 0x88) + iVar5 * 0xc);
          bVar1 = *(byte *)(param_1 + 0x96);
        }
        uVar3 = *param_2;
      }
    }
    if ((uVar3 & 0x20) == 0) {
      uVar3 = *param_2;
    }
    else {
      bVar1 = *(byte *)(*(int *)(param_2 + 10) + 3);
      *(undefined4 *)(param_1 + 0x8c) = 0;
      *(byte *)(param_1 + 0x97) = bVar1;
      if (bVar1 == 0) {
        uVar3 = *param_2;
      }
      else {
        pvVar2 = (void *)FUN_00408450((uint)bVar1 * 0xc,0x9a1);
        *(void **)(param_1 + 0x8c) = pvVar2;
        if (pvVar2 == (void *)0x0) {
          if (sensor_test_err_switch == '\0') goto LAB_004fe498;
          uVar4 = 0x9a4;
          goto LAB_004fe544;
        }
        memset(pvVar2,0,(uint)*(byte *)(param_1 + 0x97) * 0xc);
        bVar1 = *(byte *)(param_1 + 0x97);
        for (iVar5 = 0; iVar5 < (int)(uint)bVar1; iVar5 = iVar5 + 1) {
          FUN_0051ad88(*(int *)(param_1 + 0x8c) + iVar5 * 0xc);
          bVar1 = *(byte *)(param_1 + 0x97);
        }
        uVar3 = *param_2;
      }
    }
    if ((uVar3 & 0x40) == 0) {
      return 0;
    }
    bVar1 = *(byte *)(*(int *)(param_2 + 0xc) + 3);
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(byte *)(param_1 + 0x98) = bVar1;
    if (bVar1 == 0) {
      return 0;
    }
    pvVar2 = (void *)FUN_00408450((uint)bVar1 * 0xc,0x9b7);
    *(void **)(param_1 + 0x90) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      memset(pvVar2,0,(uint)*(byte *)(param_1 + 0x98) * 0xc);
      bVar1 = *(byte *)(param_1 + 0x98);
      for (iVar5 = 0; iVar5 < (int)(uint)bVar1; iVar5 = iVar5 + 1) {
        FUN_0051ad88(*(int *)(param_1 + 0x90) + iVar5 * 0xc);
        bVar1 = *(byte *)(param_1 + 0x98);
      }
      return 0;
    }
    if (sensor_test_err_switch == '\0') goto LAB_004fe498;
    uVar4 = 0x9ba;
  }
  else {
    bVar1 = *(byte *)(*(int *)(param_2 + 4) + 3);
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(byte *)(param_1 + 0x95) = bVar1;
    if (bVar1 == 0) {
      uVar3 = *param_2;
      goto LAB_004fe21c;
    }
    pvVar2 = (void *)FUN_00408450((uint)bVar1 * 0xc,0x974);
    *(void **)(param_1 + 0x84) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      memset(pvVar2,0,(uint)*(byte *)(param_1 + 0x95) * 0xc);
      bVar1 = *(byte *)(param_1 + 0x95);
      for (iVar5 = 0; iVar5 < (int)(uint)bVar1; iVar5 = iVar5 + 1) {
        FUN_0051ad88(*(int *)(param_1 + 0x84) + iVar5 * 0xc);
        bVar1 = *(byte *)(param_1 + 0x95);
      }
      uVar3 = *param_2;
      goto LAB_004fe21c;
    }
    if (sensor_test_err_switch == '\0') goto LAB_004fe498;
    uVar4 = 0x977;
  }
LAB_004fe544:
  printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n",
         "_sensor_test_db_build_lists_for_bssid_result_node",uVar4);
LAB_004fe498:
  if (sensor_test_debug_switch == '\0') {
    iVar5 = *(int *)(param_1 + 0x84);
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d build_config_list_for_bssid_bssid_result_node fail EXIT\n",
           "_sensor_test_db_build_lists_for_bssid_result_node",0x9c9);
    iVar5 = *(int *)(param_1 + 0x84);
  }
  if (iVar5 == 0) {
    iVar5 = *(int *)(param_1 + 0x88);
  }
  else {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x84) = 0;
    iVar5 = *(int *)(param_1 + 0x88);
  }
  if (iVar5 == 0) {
    iVar5 = *(int *)(param_1 + 0x8c);
  }
  else {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x88) = 0;
    iVar5 = *(int *)(param_1 + 0x8c);
  }
  if (iVar5 == 0) {
    iVar5 = *(int *)(param_1 + 0x90);
  }
  else {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x8c) = 0;
    iVar5 = *(int *)(param_1 + 0x90);
  }
  if (iVar5 != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  return 0xffffffff;
}

