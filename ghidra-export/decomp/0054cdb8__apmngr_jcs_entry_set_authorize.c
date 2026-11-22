// func _apmngr_jcs_entry_set_authorize @ 0054cdb8 size=840

void _apmngr_jcs_entry_set_authorize(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  char *__src;
  undefined4 uVar6;
  undefined2 *puVar7;
  undefined8 uVar8;
  char acStack_b68 [127];
  undefined1 local_ae9;
  undefined1 auStack_ae8 [40];
  ushort local_ac0;
  int local_aac;
  undefined2 local_810 [1014];
  
  memset(acStack_b68,0,0x80);
  memset(local_810,0,0x7e4);
  memset(auStack_ae8,0,0x2d8);
  iVar1 = json_object_object_get(param_1,"entry_id");
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
    for (iVar2 = 0; iVar3 = json_object_array_length(iVar1), iVar2 < iVar3; iVar2 = iVar2 + 1) {
      if (iVar2 == 0x3f2) {
        iVar2 = 0x3f2;
        break;
      }
      iVar3 = json_object_array_get_idx(iVar1,iVar2);
      if (iVar3 == 0) {
LAB_0054d06c:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_apmngr_jcs_entry_set_authorize",0x632);
        }
        *puVar7 = 0xffff;
      }
      else {
        iVar4 = json_object_get_type(iVar3);
        if (iVar4 == 3) {
          uVar5 = json_object_get_int(iVar3);
          *puVar7 = uVar5;
        }
        else {
          iVar4 = json_object_get_type();
          if (iVar4 != 2) goto LAB_0054d06c;
          uVar8 = json_object_get_double(iVar3);
          uVar5 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
          *puVar7 = uVar5;
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
      if (iVar1 == 0) goto LAB_0054ceb4;
    }
    iVar2 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
             "_apmngr_jcs_entry_set_authorize",0x632);
    }
  }
LAB_0054ceb4:
  iVar1 = json_object_object_get(param_1,"operation");
  if ((iVar1 == 0) || (iVar3 = json_object_get_type(iVar1), iVar3 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_entry_set_authorize",0x634);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  puVar7 = local_810;
  iVar1 = 0;
  strncpy(acStack_b68,__src,0x7f);
  local_ae9 = 0;
  do {
    while( true ) {
      if (iVar2 <= iVar1) {
        return;
      }
      uVar5 = *puVar7;
      iVar3 = apmngr_db_entry_get_by_id(uVar5,auStack_ae8);
      if (((iVar3 == 0) && (local_aac == 0)) && ((local_ac0 & 1) != 0)) break;
LAB_0054cf90:
      iVar1 = iVar1 + 1;
      puVar7 = puVar7 + 1;
    }
    iVar3 = strncmp(acStack_b68,"allow",0x80);
    if (iVar3 == 0) {
      uVar6 = 1;
    }
    else {
      iVar3 = strncmp(acStack_b68,"reject",0x80);
      if (iVar3 != 0) goto LAB_0054cf90;
      uVar6 = 2;
    }
    iVar1 = iVar1 + 1;
    apmngr_db_ap_flag_set(uVar5,uVar6);
    apmngr_db_ap_flag_unset(uVar5,0);
    puVar7 = puVar7 + 1;
  } while( true );
}

