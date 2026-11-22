// func apmngr_db_group_id_parse @ 005344c0 size=1148

undefined4 apmngr_db_group_id_parse(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar5;
  int iVar3;
  int iVar4;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APMNGR_ERROR]%s()/%d Input error\n";
    uVar7 = 0x140;
LAB_005345ac:
    printf(pcVar6,"apmngr_db_group_id_parse",uVar7);
    return 0xffffffff;
  }
  iVar1 = json_object_object_get(param_1,"group_id");
  if (iVar1 == 0) goto LAB_00534710;
  iVar2 = json_object_get_type(iVar1);
  if ((iVar2 == 5) ||
     ((iVar2 = json_object_get_type(iVar1), iVar2 == 4 &&
      (iVar2 = json_object_object_length(iVar1), iVar2 == 0)))) {
    iVar2 = json_object_array_length(iVar1);
    if (0x3f2 < iVar2) {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[APMNGR_ERROR]%s()/%d Group array len exceeds max group size %d\n",
             "apmngr_db_group_id_parse",0x14e,0x3f2);
      return 0xffffffff;
    }
    param_2[0x1fa] = 0;
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 5) {
      puVar8 = param_2;
      for (iVar2 = 0; iVar3 = json_object_array_length(iVar1), iVar2 < iVar3; iVar2 = iVar2 + 1) {
        if (iVar2 == 0x3f2) {
          param_2[0x1fa] = 0x3f2;
          goto LAB_005346d0;
        }
        iVar3 = json_object_array_get_idx(iVar1,iVar2);
        if (iVar3 == 0) {
LAB_005348a8:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "apmngr_db_group_id_parse",0x152);
          }
          *(undefined2 *)(puVar8 + 1) = 0xffff;
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 != 6) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "apmngr_db_group_id_parse",0x152);
            }
            goto LAB_005348a8;
          }
          pcVar6 = (char *)json_object_get_string(iVar3);
          iVar3 = atoi(pcVar6);
          *(short *)(puVar8 + 1) = (short)iVar3;
        }
        puVar8 = (undefined4 *)((int)puVar8 + 2);
      }
      param_2[0x1fa] = iVar2;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if ((iVar2 == 4) && (iVar1 = json_object_object_length(iVar1), iVar1 == 0)) {
        param_2[0x1fa] = 0;
      }
      else if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n"
               ,"apmngr_db_group_id_parse",0x152);
        iVar1 = param_2[0x1fa];
        goto LAB_005346d4;
      }
    }
LAB_005346d0:
    iVar1 = param_2[0x1fa];
LAB_005346d4:
    iVar2 = 0;
    puVar8 = param_2;
    while( true ) {
      if (iVar1 <= iVar2) {
        *param_2 = 0;
        return 0;
      }
      if (*(short *)(puVar8 + 1) == -1) break;
      iVar2 = iVar2 + 1;
      puVar8 = (undefined4 *)((int)puVar8 + 2);
    }
    param_2[0x1fa] = 0;
    *param_2 = 1;
    return 0;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 6) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
      iVar1 = atoi(pcVar6);
      *(short *)(param_2 + 1) = (short)iVar1;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "apmngr_db_group_id_parse",0x161);
      }
      if (jcs_err_switch != 0) {
        pcVar6 = "[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n";
        uVar7 = 0x161;
LAB_00534780:
        printf(pcVar6,"apmngr_db_group_id_parse",uVar7);
      }
LAB_0053464c:
      *(undefined2 *)(param_2 + 1) = 0xffff;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if ((iVar2 != 3) && (iVar2 = json_object_get_type(iVar1), iVar2 != 2)) {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[APMNGR_ERROR]%s()/%d Invalid format of group id\n";
      uVar7 = 0x179;
      goto LAB_005345ac;
    }
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
      *(undefined2 *)(param_2 + 1) = uVar5;
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) {
        if (jcs_err_switch != 0) {
          pcVar6 = "[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n";
          uVar7 = 0x16d;
          goto LAB_00534780;
        }
        goto LAB_0053464c;
      }
      uVar9 = json_object_get_double(iVar1);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      *(undefined2 *)(param_2 + 1) = uVar5;
    }
  }
  if (*(short *)(param_2 + 1) != -1) {
    *param_2 = 0;
    param_2[0x1fa] = 1;
    return 0;
  }
LAB_00534710:
  *param_2 = 1;
  return 0;
}

