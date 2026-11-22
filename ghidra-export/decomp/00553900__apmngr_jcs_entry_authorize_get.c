// func _apmngr_jcs_entry_authorize_get @ 00553900 size=968

void _apmngr_jcs_entry_authorize_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  FILE *__s;
  undefined4 uVar6;
  undefined8 uVar7;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  iVar1 = json_object_object_get(param_1,"start");
  if (iVar1 == 0) {
LAB_0055395c:
    iVar1 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_apmngr_jcs_entry_authorize_get",0x770);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0055395c;
      uVar7 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar2 = json_object_object_get(param_1,"size");
  if (iVar2 == 0) {
LAB_005539ac:
    iVar2 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_apmngr_jcs_entry_authorize_get",0x773);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      iVar2 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_005539ac;
      uVar7 = json_object_get_double(iVar2);
      iVar2 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_30 = iVar1;
  local_2c = iVar2;
  local_1c = json_object_new_array();
  local_28 = 0;
  if ((apmngr_debug_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d Get wait ap list from %d to %d.\n",
           "_apmngr_authorize_entry_list_get",0x742,iVar1,iVar1 + iVar2);
  }
  if (local_1c == 0) {
    if (apmngr_err_switch == '\0') {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APMNGR_ERROR]%s()/%d Failed to create json array.\n","_apmngr_authorize_entry_list_get"
           ,0x745);
    return;
  }
  apmngr_db_foreach_proc(0xe0000,_apmngr_authorize_entry_get,&local_30);
  pcVar4 = (char *)json_object_to_json_string_ext(local_1c,0);
  if (pcVar4 == (char *)0x0) {
    if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
      __s = (FILE *)0x0;
      iVar1 = 0;
    }
    else {
      __s = (FILE *)0x0;
      printf("[APMNGR_ERROR]%s()/%d translate json to string failed.\n",
             "_apmngr_authorize_entry_list_get",0x74e);
      iVar1 = 0;
    }
    goto LAB_00553a78;
  }
  sVar5 = strlen(pcVar4);
  __s = fopen("/tmp/apmngr_wait_list","w+");
  if (__s == (FILE *)0x0) {
    iVar1 = 0;
    if (apmngr_err_switch == '\0') goto LAB_00553a78;
    iVar2 = is_target_debug_ap();
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_00553a78;
    pcVar4 = "[APMNGR_ERROR]%s()/%d open file failed.\n";
    uVar6 = 0x757;
  }
  else {
    sVar5 = fwrite(pcVar4,sVar5,1,__s);
    iVar1 = local_28;
    if (((sVar5 == 1) || (iVar1 = 0, apmngr_err_switch == '\0')) ||
       (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00553a78;
    pcVar4 = "[APMNGR_ERROR]%s()/%d write to file failed.\n";
    uVar6 = 0x75e;
  }
  printf(pcVar4,"_apmngr_authorize_entry_list_get",uVar6);
  iVar1 = 0;
LAB_00553a78:
  if (local_1c != 0) {
    json_object_put();
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  if (0 < iVar1) {
    uVar6 = json_object_new_string("/tmp/apmngr_wait_list");
    json_object_object_add(param_2,"file_name",uVar6);
    uVar6 = json_object_new_int(iVar1);
    json_object_object_add(param_2,"total_num",uVar6);
  }
  return;
}

