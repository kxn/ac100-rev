// func _apmngr_jcs_entry_copy @ 0054d100 size=1100

void _apmngr_jcs_entry_copy(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  undefined2 *puVar9;
  undefined8 uVar10;
  undefined1 auStack_ae8 [20];
  uint local_ad4;
  undefined2 local_810 [1012];
  
  memset(local_810,0,0x7e4);
  memset(auStack_ae8,0,0x2d8);
  iVar1 = json_object_object_get(param_1,"ap_ids");
  if (((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 5)) &&
     (iVar2 = json_object_array_length(iVar1), 0 < iVar2)) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 5) {
      puVar9 = local_810;
      for (iVar2 = 0; iVar4 = json_object_array_length(iVar1), iVar2 < iVar4; iVar2 = iVar2 + 1) {
        if (iVar2 == 0x3f2) {
          iVar2 = 0x3f2;
          break;
        }
        iVar4 = json_object_array_get_idx(iVar1,iVar2);
        if (iVar4 == 0) {
LAB_0054d494:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_apmngr_jcs_entry_copy",0x5f9);
          }
          *puVar9 = 0xffff;
        }
        else {
          iVar6 = json_object_get_type(iVar4);
          if (iVar6 == 3) {
            uVar7 = json_object_get_int(iVar4);
            *puVar9 = uVar7;
          }
          else {
            iVar6 = json_object_get_type();
            if (iVar6 != 2) goto LAB_0054d494;
            uVar10 = json_object_get_double(iVar4);
            uVar7 = __fixunsdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
            *puVar9 = uVar7;
          }
        }
        puVar9 = puVar9 + 1;
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 4) {
        iVar1 = json_object_object_length(iVar1);
        iVar2 = 0;
        if (iVar1 == 0) goto LAB_0054d234;
      }
      iVar2 = 0;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "_apmngr_jcs_entry_copy",0x5f9);
      }
    }
LAB_0054d234:
    iVar1 = json_object_object_get(param_1,"copy_ap_id");
    if (iVar1 == 0) {
LAB_0054d368:
      uVar5 = 0xffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_apmngr_jcs_entry_copy",0x600);
      }
    }
    else {
      iVar4 = json_object_get_type(iVar1);
      if (iVar4 == 3) {
        uVar5 = json_object_get_int(iVar1);
        uVar5 = uVar5 & 0xffff;
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 2) goto LAB_0054d368;
        uVar10 = json_object_get_double(iVar1);
        uVar5 = __fixunsdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        uVar5 = uVar5 & 0xffff;
      }
    }
    iVar1 = json_object_object_get(param_1,"replace");
    if (iVar1 == 0) {
LAB_0054d398:
      uVar8 = 0;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n",
               "_apmngr_jcs_entry_copy",0x603);
      }
    }
    else {
      iVar4 = json_object_get_type(iVar1);
      if (iVar4 == 1) {
        uVar8 = json_object_get_boolean(iVar1);
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 3) goto LAB_0054d398;
        iVar1 = json_object_get_int(iVar1);
        uVar8 = (uint)(iVar1 != 0);
      }
    }
    iVar1 = apmngr_db_entry_get_by_id(uVar5,auStack_ae8);
    if ((iVar1 == 0) && (((local_ad4 < 2 || (local_ad4 == 3)) || (local_ad4 == 2)))) {
      puVar9 = local_810;
      iVar1 = 0;
      for (iVar4 = 0; uVar3 = 0, iVar4 < iVar2; iVar4 = iVar4 + 1) {
        uVar7 = *puVar9;
        iVar6 = apmngr_ap_copy(uVar7,auStack_ae8,uVar8);
        if (iVar6 == 0) {
          if ((iVar1 == 0) && (iVar1 = json_object_new_array(), iVar1 == 0)) {
            uVar3 = 0xffffffff;
            break;
          }
          uVar3 = json_object_new_int(uVar7);
          json_object_array_add(iVar1,uVar3);
        }
        puVar9 = puVar9 + 1;
      }
      goto LAB_0054d18c;
    }
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(0xffffffff), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Can not find ap entry of id %d\n","_apmngr_jcs_entry_copy",0x607
             ,uVar5);
    }
  }
  uVar3 = 0xffffffff;
  iVar1 = 0;
LAB_0054d18c:
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  if (iVar1 != 0) {
    json_object_object_add(param_2,"success_id_list",iVar1);
  }
  return;
}

