// func _apmngr_jcs_group_join @ 0054c97c size=1084

void _apmngr_jcs_group_join(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  char *__src;
  undefined2 *puVar7;
  undefined8 uVar8;
  char acStack_890 [127];
  undefined1 local_811;
  undefined2 local_810 [1012];
  
  memset(local_810,0,0x7e4);
  memset(acStack_890,0,0x80);
  iVar1 = json_object_object_get(param_1,"group_id");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_group_join",0x654);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_890,__src,0x7f);
  local_811 = 0;
  uVar3 = atoi(acStack_890);
  iVar1 = json_object_object_get(param_1,"ap_ids");
  if (((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 5)) &&
     (iVar2 = json_object_array_length(iVar1), 0 < iVar2)) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 5) {
      puVar7 = local_810;
      for (iVar2 = 0; iVar4 = json_object_array_length(iVar1), iVar2 < iVar4; iVar2 = iVar2 + 1) {
        if (iVar2 == 0x3f2) {
          iVar2 = 0x3f2;
          break;
        }
        iVar4 = json_object_array_get_idx(iVar1,iVar2);
        if (iVar4 == 0) {
LAB_0054cc2c:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_apmngr_jcs_group_join",0x65a);
          }
          *puVar7 = 0xffff;
        }
        else {
          iVar5 = json_object_get_type(iVar4);
          if (iVar5 == 3) {
            uVar6 = json_object_get_int(iVar4);
            *puVar7 = uVar6;
          }
          else {
            iVar5 = json_object_get_type();
            if (iVar5 != 2) goto LAB_0054cc2c;
            uVar8 = json_object_get_double(iVar4);
            uVar6 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
            *puVar7 = uVar6;
          }
        }
        puVar7 = puVar7 + 1;
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 4) {
        iVar1 = json_object_object_length(iVar1);
        iVar2 = 0;
        if (iVar1 == 0) goto LAB_0054cb74;
      }
      iVar2 = 0;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "_apmngr_jcs_group_join",0x65a);
      }
    }
LAB_0054cb74:
    apmngr_db_entry_group_join(local_810,iVar2,uVar3 & 0xffff);
  }
  iVar1 = json_object_object_get(param_1,"template_ids");
  if (iVar1 == 0) {
    return;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 != 5) {
    return;
  }
  iVar2 = json_object_array_length(iVar1);
  if (iVar2 < 1) {
    return;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 5) {
    puVar7 = local_810;
    for (iVar2 = 0; iVar4 = json_object_array_length(iVar1), iVar2 < iVar4; iVar2 = iVar2 + 1) {
      if (iVar2 == 0x3f2) {
        iVar2 = 0x3f2;
        break;
      }
      iVar4 = json_object_array_get_idx(iVar1,iVar2);
      if (iVar4 == 0) {
LAB_0054cd0c:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_apmngr_jcs_group_join",0x660);
        }
        *puVar7 = 0xffff;
      }
      else {
        iVar5 = json_object_get_type(iVar4);
        if (iVar5 == 3) {
          uVar6 = json_object_get_int(iVar4);
          *puVar7 = uVar6;
        }
        else {
          iVar5 = json_object_get_type();
          if (iVar5 != 2) goto LAB_0054cd0c;
          uVar8 = json_object_get_double(iVar4);
          uVar6 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
          *puVar7 = uVar6;
        }
      }
      puVar7 = puVar7 + 1;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 4) {
      iVar1 = json_object_object_length(iVar1);
      iVar2 = 0;
      if (iVar1 == 0) goto LAB_0054cb1c;
    }
    iVar2 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
             "_apmngr_jcs_group_join",0x660);
    }
  }
LAB_0054cb1c:
  apmngr_db_entry_group_join(local_810,iVar2,uVar3 & 0xffff);
  return;
}

