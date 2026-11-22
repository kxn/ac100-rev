// func _apdb_port_info_prase_from_json @ 005fbf28 size=796

undefined4 _apdb_port_info_prase_from_json(int param_1,int param_2)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar5;
  void *__s;
  int iVar3;
  int iVar4;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : _apdb_port_info_parse_from_json ENTER\n",
           "_apdb_port_info_prase_from_json",0x726);
  }
  if (((param_1 == 0) || (*(int *)(param_1 + 0xc) != 5)) || (param_2 == 0)) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APDB_ERROR]%s()/line %d : input invalid\n";
    uVar7 = 0x729;
  }
  else {
    uVar5 = cJSON_GetArraySize(param_1);
    bVar1 = apdb_debug_switch == 0;
    *(undefined1 *)(param_2 + 0x14) = uVar5;
    if (bVar1) {
      bVar2 = *(byte *)(param_2 + 0x14);
    }
    else {
      printf("[APDB_DEBUG]%s()/line %d : dest_model->phy_num=%d\n","_apdb_port_info_prase_from_json"
             ,0x72e);
      bVar2 = *(byte *)(param_2 + 0x14);
    }
    if (bVar2 == 0) {
      if (apdb_warning_switch == 0) {
        *(undefined1 *)(param_2 + 0x14) = 0;
      }
      else {
        printf("[APDB_WARNING]%s()/line %d : the phy_num is %d,ignore it\n",
               "_apdb_port_info_prase_from_json",0x731,0);
        *(undefined1 *)(param_2 + 0x14) = 0;
      }
      return 0;
    }
    __s = (void *)FUN_00408450((uint)bVar2 << 3,0x735);
    *(void **)(param_2 + 0x2c) = __s;
    if (__s != (void *)0x0) {
      memset(__s,0,(uint)*(byte *)(param_2 + 0x14) << 3);
      iVar8 = 0;
      while( true ) {
        if ((int)(uint)*(byte *)(param_2 + 0x14) <= iVar8) {
          return 0;
        }
        iVar3 = cJSON_GetArrayItem(param_1,iVar8);
        if (iVar3 == 0) break;
        uVar7 = cJSON_GetObjectItem(iVar3,"phy_index");
        iVar9 = iVar8 * 8;
        iVar4 = FUN_00407f50(uVar7,*(int *)(param_2 + 0x2c) + iVar9);
        if (iVar4 != 0) {
          if (apdb_err_switch == 0) {
            iVar8 = *(int *)(param_2 + 0x2c);
            goto LAB_005fc1a0;
          }
          pcVar6 = "[APDB_ERROR]%s()/line %d : Fail to parse phy_index_obj from json\n";
          uVar7 = 0x74b;
          goto LAB_005fc1d8;
        }
        uVar7 = cJSON_GetObjectItem(iVar3,"phy_type");
        iVar4 = FUN_00407f50(uVar7,*(int *)(param_2 + 0x2c) + iVar9 + 1);
        if (iVar4 != 0) {
          if (apdb_err_switch == 0) {
            iVar8 = *(int *)(param_2 + 0x2c);
            goto LAB_005fc1a0;
          }
          pcVar6 = "[APDB_ERROR]%s()/line %d : Fail to parse phy_type_obj from json\n";
          uVar7 = 0x753;
          goto LAB_005fc1d8;
        }
        uVar7 = cJSON_GetObjectItem(iVar3,"phy_speed");
        iVar3 = FUN_00408470(uVar7,*(int *)(param_2 + 0x2c) + iVar9 + 4);
        if (iVar3 != 0) {
          if (apdb_err_switch == 0) {
            iVar8 = *(int *)(param_2 + 0x2c);
            goto LAB_005fc1a0;
          }
          pcVar6 = "[APDB_ERROR]%s()/line %d : Fail to parse phy_speed_obj from json\n";
          uVar7 = 0x75b;
          goto LAB_005fc1d8;
        }
        iVar8 = iVar8 + 1;
      }
      if (apdb_err_switch == 0) {
        iVar8 = *(int *)(param_2 + 0x2c);
        goto LAB_005fc1a0;
      }
      pcVar6 = "[APDB_ERROR]%s()/line %d : Fail to parse phy_array_item from json\n";
      uVar7 = 0x743;
LAB_005fc1d8:
      printf(pcVar6,"_apdb_port_info_prase_from_json",uVar7);
      iVar8 = *(int *)(param_2 + 0x2c);
LAB_005fc1a0:
      if (iVar8 == 0) {
        return 0xffffffff;
      }
      FUN_00407df0();
      *(undefined4 *)(param_2 + 0x2c) = 0;
      return 0xffffffff;
    }
    if (apdb_debug_switch == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APDB_DEBUG]%s()/line %d : dest_model->phy_info mem_malloc fail\n";
    uVar7 = 0x738;
  }
  printf(pcVar6,"_apdb_port_info_prase_from_json",uVar7);
  return 0xffffffff;
}

