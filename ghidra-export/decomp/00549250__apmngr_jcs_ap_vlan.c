// func _apmngr_jcs_ap_vlan @ 00549250 size=900

void _apmngr_jcs_ap_vlan(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  FILE *__s;
  char *pcVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 local_b8;
  int local_b4;
  int local_b0;
  int local_a4;
  char acStack_98 [127];
  undefined1 local_19;
  
  memset(acStack_98,0,0x80);
  iVar1 = json_object_object_get(param_1,"start");
  if (iVar1 == 0) {
LAB_005492c0:
    uVar5 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_apmngr_jcs_ap_vlan",0xb31);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_005492c0;
      uVar6 = json_object_get_double(iVar1);
      uVar5 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
    }
  }
  iVar1 = json_object_object_get(param_1,"size");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_ap_vlan",0xb34);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_98,pcVar4,0x7f);
  local_19 = 0;
  iVar1 = atoi(acStack_98);
  memset(&local_b8,0,0x20);
  local_b8 = uVar5;
  local_b4 = iVar1;
  local_a4 = json_object_new_array();
  local_b0 = 0;
  if (local_a4 == 0) {
    if (apmngr_err_switch == '\0') {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APMNGR_ERROR]%s()/%d Failed to create json array.\n","_apmngr_jcs_ap_vlan_info_get",
           0xb04);
    return;
  }
  apmngr_db_foreach_proc(0xf0000,_apmngr_db_vlan_get,&local_b8);
  pcVar4 = (char *)json_object_to_json_string_ext(local_a4,0);
  if (pcVar4 == (char *)0x0) {
    if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
      __s = (FILE *)0x0;
      iVar1 = 0;
    }
    else {
      __s = (FILE *)0x0;
      printf("[APMNGR_ERROR]%s()/%d translate ap vlan info json to string failed.\n",
             "_apmngr_jcs_ap_vlan_info_get",0xb0d);
      iVar1 = 0;
    }
    goto LAB_005493d8;
  }
  sVar3 = strlen(pcVar4);
  __s = fopen("/tmp/ap_vlan_info","w+");
  if (__s == (FILE *)0x0) {
    iVar1 = 0;
    if (apmngr_err_switch == '\0') goto LAB_005493d8;
    iVar2 = is_target_debug_ap();
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_005493d8;
    pcVar4 = "[APMNGR_ERROR]%s()/%d open ap vlan info file failed.\n";
    uVar5 = 0xb16;
  }
  else {
    sVar3 = fwrite(pcVar4,sVar3,1,__s);
    iVar1 = local_b0;
    if (((sVar3 == 1) || (iVar1 = 0, apmngr_err_switch == '\0')) ||
       (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005493d8;
    pcVar4 = "[APMNGR_ERROR]%s()/%d write ap vlan info to file failed.\n";
    uVar5 = 0xb1d;
  }
  printf(pcVar4,"_apmngr_jcs_ap_vlan_info_get",uVar5);
  iVar1 = 0;
LAB_005493d8:
  if (local_a4 != 0) {
    json_object_put();
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  if (0 < iVar1) {
    uVar5 = json_object_new_string("/tmp/ap_vlan_info");
    json_object_object_add(param_2,"file_name",uVar5);
    uVar5 = json_object_new_int(iVar1);
    json_object_object_add(param_2,"total_num",uVar5);
  }
  return;
}

