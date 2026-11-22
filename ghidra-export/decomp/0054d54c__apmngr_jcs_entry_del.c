// func _apmngr_jcs_entry_del @ 0054d54c size=1364

void _apmngr_jcs_entry_del(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  undefined8 uVar7;
  undefined2 local_810 [1012];
  
  memset(local_810,0,0x7e4);
  FUN_00407e80("_apmngr_jcs_entry_del");
  iVar1 = json_object_object_get(param_1,"template");
  if (((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 5)) &&
     (iVar2 = json_object_array_length(iVar1), 0 < iVar2)) {
    iVar2 = json_object_get_type(iVar1);
    puVar6 = local_810;
    if (iVar2 == 5) {
      iVar2 = 0;
      while (iVar3 = json_object_array_length(iVar1), iVar2 < iVar3) {
        if (iVar2 == 0x3f2) {
          iVar2 = 0x3f2;
          break;
        }
        iVar3 = json_object_array_get_idx(iVar1,iVar2);
        if (iVar3 == 0) {
LAB_0054d8b8:
          if (jcs_err_switch == 0) {
            *puVar6 = 0xffff;
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_apmngr_jcs_entry_del",0x50b);
            *puVar6 = 0xffff;
          }
          iVar2 = iVar2 + 1;
          puVar6 = puVar6 + 1;
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            uVar5 = json_object_get_int(iVar3);
            *puVar6 = uVar5;
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) goto LAB_0054d8b8;
            uVar7 = json_object_get_double(iVar3);
            uVar5 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
            *puVar6 = uVar5;
          }
          iVar2 = iVar2 + 1;
          puVar6 = puVar6 + 1;
        }
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 4) {
        iVar1 = json_object_object_length(iVar1);
        iVar2 = 0;
        if (iVar1 == 0) goto LAB_0054d70c;
      }
      iVar2 = 0;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "_apmngr_jcs_entry_del",0x50b);
      }
    }
LAB_0054d70c:
    apmngr_template_delete(local_810,iVar2,1);
  }
  iVar1 = json_object_object_get(param_1,"ap");
  if (((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 5)) &&
     (iVar2 = json_object_array_length(iVar1), 0 < iVar2)) {
    iVar2 = json_object_get_type(iVar1);
    puVar6 = local_810;
    if (iVar2 == 5) {
      iVar2 = 0;
      while (iVar3 = json_object_array_length(iVar1), iVar2 < iVar3) {
        if (iVar2 == 0x3f2) {
          iVar2 = 0x3f2;
          break;
        }
        iVar3 = json_object_array_get_idx(iVar1,iVar2);
        if (iVar3 == 0) {
LAB_0054d820:
          if (jcs_err_switch == 0) {
            *puVar6 = 0xffff;
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_apmngr_jcs_entry_del",0x512);
            *puVar6 = 0xffff;
          }
          iVar2 = iVar2 + 1;
          puVar6 = puVar6 + 1;
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            uVar5 = json_object_get_int(iVar3);
            *puVar6 = uVar5;
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) goto LAB_0054d820;
            uVar7 = json_object_get_double(iVar3);
            uVar5 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
            *puVar6 = uVar5;
          }
          iVar2 = iVar2 + 1;
          puVar6 = puVar6 + 1;
        }
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 4) {
        iVar1 = json_object_object_length(iVar1);
        iVar2 = 0;
        if (iVar1 == 0) goto LAB_0054d764;
      }
      iVar2 = 0;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "_apmngr_jcs_entry_del",0x512);
      }
    }
LAB_0054d764:
    apmngr_ap_delete(local_810,iVar2,1,0x3cf2,1);
  }
  iVar1 = json_object_object_get(param_1,"ap_tmp");
  if (((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 5)) ||
     (iVar2 = json_object_array_length(iVar1), iVar2 < 1)) goto LAB_0054d62c;
  iVar2 = json_object_get_type(iVar1,"_apmngr_jcs_entry_del");
  if (iVar2 == 5) {
    puVar6 = local_810;
    iVar2 = 0;
    while (iVar3 = json_object_array_length(iVar1), iVar2 < iVar3) {
      if (iVar2 == 0x3f2) {
        iVar2 = 0x3f2;
        break;
      }
      iVar3 = json_object_array_get_idx(iVar1,iVar2);
      if (iVar3 == 0) {
LAB_0054d9a4:
        if (jcs_err_switch == 0) {
          *puVar6 = 0xffff;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_apmngr_jcs_entry_del",0x519);
          *puVar6 = 0xffff;
        }
        iVar2 = iVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      else {
        iVar4 = json_object_get_type(iVar3);
        if (iVar4 == 3) {
          uVar5 = json_object_get_int(iVar3);
          *puVar6 = uVar5;
        }
        else {
          iVar4 = json_object_get_type();
          if (iVar4 != 2) goto LAB_0054d9a4;
          uVar7 = json_object_get_double(iVar3);
          uVar5 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
          *puVar6 = uVar5;
        }
        iVar2 = iVar2 + 1;
        puVar6 = puVar6 + 1;
      }
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 4) {
      iVar1 = json_object_object_length(iVar1);
      iVar2 = 0;
      if (iVar1 == 0) goto LAB_0054d6a8;
    }
    iVar2 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
             "_apmngr_jcs_entry_del",0x519);
    }
  }
LAB_0054d6a8:
  apmngr_ap_delete(local_810,iVar2,1,0x3cf2,1);
LAB_0054d62c:
  FUN_004082b0(1,"_apmngr_jcs_entry_del");
  return;
}

