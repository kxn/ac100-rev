// func _wportal_auth_para_sso_config_set @ 0040f924 size=1016

undefined4 _wportal_auth_para_sso_config_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  char local_140 [8];
  char acStack_138 [31];
  undefined1 local_119;
  char acStack_118 [255];
  undefined1 local_19;
  
  local_140[0] = '\0';
  local_140[1] = '\0';
  local_140[2] = '\0';
  local_140[3] = '\0';
  local_140[4] = 0;
  memset(acStack_138,0,0x20);
  memset(acStack_118,0,0x100);
  iVar1 = json_object_object_get(param_1,"sso_config");
  if (iVar1 == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[WPORTAL_ERR]%s()/%d parse json obj error\n","_wportal_auth_para_sso_config_set",0x1295)
    ;
    return 0xffffffff;
  }
  iVar2 = json_object_object_get(iVar1,"sso_enable");
  if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_auth_para_sso_config_set",0x129a);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar2);
  }
  strncpy(local_140,pcVar6,4);
  iVar2 = strcmp(local_140,"on");
  iVar3 = json_object_object_get(iVar1,"sso_type");
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_auth_para_sso_config_set",0x129e);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar3);
  }
  uVar7 = 0;
  strncpy(acStack_138,pcVar6,0x1f);
  local_119 = 0;
  iVar3 = strcmp(acStack_138,"sangfor");
  sso_enable_set((uint)(iVar2 == 0),(uint)(iVar3 == 0));
  iVar4 = sso_type_is_sangfor();
  if (iVar4 == 0) goto LAB_0040fa70;
  iVar4 = json_object_object_get(iVar1,"sso_sangfor_server");
  if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_auth_para_sso_config_set",0x12a6);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar4);
  }
  strncpy(acStack_118,pcVar6,0xff);
  local_19 = 0;
  iVar1 = json_object_object_get(iVar1,"sso_sangfor_port");
  if (iVar1 == 0) {
LAB_0040fbdc:
    uVar7 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_auth_para_sso_config_set",0x12a9);
    }
  }
  else {
    iVar4 = json_object_get_type(iVar1);
    if (iVar4 == 3) {
      uVar7 = json_object_get_int(iVar1);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0040fbdc;
      uVar8 = json_object_get_double(iVar1);
      uVar7 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  sso_sangfor_config_set(acStack_118,uVar7);
LAB_0040fa70:
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d _wportal_auth_para_sso_config_set\n",
           "_wportal_auth_para_sso_config_set",0x12ae);
  }
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d sso_enable: %d\tsso_type:%d\n","_wportal_auth_para_sso_config_set"
           ,0x12af,(uint)(iVar2 == 0),(uint)(iVar3 == 0));
  }
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d sso_sangfor_server: %s\tsso_sangfor_port:%d\n",
           "_wportal_auth_para_sso_config_set",0x12b0,acStack_118,uVar7);
  }
  return 0;
}

