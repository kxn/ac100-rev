// func _apmngr_jcs_apdb_info_get @ 0055253c size=764

void _apmngr_jcs_apdb_info_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  FILE *__s;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  if (param_1 == 0) {
    return;
  }
  if (param_2 == 0) {
    return;
  }
  iVar1 = json_object_new_array();
  if (iVar1 == 0) {
    return;
  }
  iVar2 = json_object_array_length(param_1);
  iVar9 = 0;
  iVar8 = 0;
  while (iVar8 < iVar2) {
    iVar3 = json_object_array_get_idx(param_1,iVar8);
    if (iVar3 == 0) {
      if (apmngr_debug_switch == '\0') {
        iVar8 = iVar8 + 1;
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          iVar8 = iVar8 + 1;
        }
        else {
          printf("[APMNGR_DEBUG]%s()/%d get _array item fail with idx=%d\n",
                 "_apmngr_jcs_apdb_info_get",0x1b6,iVar8);
          iVar8 = iVar8 + 1;
        }
      }
    }
    else {
      iVar4 = json_object_new_object();
      if (iVar4 == 0) {
        __s = (FILE *)0x0;
        if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_005526b0;
        pcVar6 = "[APMNGR_DEBUG]%s()/%d Create json object failed when tranverse script list.\n";
        uVar7 = 0x1bd;
        goto LAB_00552754;
      }
      iVar3 = _apdb_info_get(iVar3,iVar4);
      if (iVar3 == 0) {
        iVar9 = iVar9 + 1;
        json_object_array_add(iVar1,iVar4);
        iVar8 = iVar8 + 1;
      }
      else {
        json_object_put(iVar4);
        iVar8 = iVar8 + 1;
      }
    }
  }
  pcVar6 = (char *)json_object_to_json_string_ext(iVar1,0);
  if (pcVar6 == (char *)0x0) {
    __s = (FILE *)0x0;
    if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_005526b0;
    pcVar6 = "[APMNGR_DEBUG]%s()/%d translate json to string failed.\n";
    uVar7 = 0x1d0;
  }
  else {
    sVar5 = strlen(pcVar6);
    __s = fopen("/tmp/apdb_info_list","w+");
    if (__s == (FILE *)0x0) {
      if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_005526b0;
      pcVar6 = "[APMNGR_DEBUG]%s()/%d open file failed.\n";
      uVar7 = 0x1d8;
    }
    else {
      sVar5 = fwrite(pcVar6,sVar5,1,__s);
      if (sVar5 == 1) {
        if (iVar9 != 0) {
          uVar7 = json_object_new_string("/tmp/apdb_info_list");
          json_object_object_add(param_2,"file_name",uVar7);
          uVar7 = json_object_new_int(iVar9);
          json_object_object_add(param_2,"total_num",uVar7);
        }
        goto LAB_005526b0;
      }
      if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_005526b0;
      pcVar6 = "[APMNGR_DEBUG]%s()/%d write to file failed.\n";
      uVar7 = 0x1de;
    }
  }
LAB_00552754:
  printf(pcVar6,"_apmngr_jcs_apdb_info_get",uVar7);
LAB_005526b0:
  json_object_put(iVar1);
  if (__s == (FILE *)0x0) {
    return;
  }
  fclose(__s);
  return;
}

