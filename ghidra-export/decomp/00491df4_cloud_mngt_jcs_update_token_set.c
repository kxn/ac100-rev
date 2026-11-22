// func cloud_mngt_jcs_update_token_set @ 00491df4 size=696

void cloud_mngt_jcs_update_token_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  char acStack_4410 [1023];
  undefined1 local_4011;
  char acStack_4010 [16383];
  undefined1 local_11;
  
  memset(acStack_4010,0,0x4000);
  memset(acStack_4410,0,0x400);
  iVar1 = json_object_object_get(param_1,"token_str");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "cloud_mngt_jcs_update_token_set",0x1e75);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_4010,pcVar4,0x3fff);
  local_11 = 0;
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d get token_str :%s\n","cloud_mngt_jcs_update_token_set",0x1e77,
           acStack_4010);
  }
  iVar1 = jsonParseStr(acStack_4010);
  iVar2 = json_object_object_get(iVar1,"deviceToken");
  if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "cloud_mngt_jcs_update_token_set",0x1e7c);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar2);
  }
  strncpy(acStack_4410,pcVar4,0x3ff);
  local_4011 = 0;
  iVar2 = json_object_object_get(iVar1,"expiresIn");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar5 = json_object_get_int(iVar2);
      goto LAB_00491f40;
    }
    iVar3 = json_object_get_type();
    if (iVar3 == 2) {
      uVar6 = json_object_get_double(iVar2);
      uVar5 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      goto LAB_00491f40;
    }
  }
  uVar5 = 0xffffffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "cloud_mngt_jcs_update_token_set",0x1e82);
  }
LAB_00491f40:
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d token:%s,expiresIn:%d\n","cloud_mngt_jcs_update_token_set",
           0x1e85,acStack_4410,uVar5);
  }
  if (((ap_report_switch != 0) &&
      (iVar2 = cloud_mngt_notify_all_update_token(acStack_4410,uVar5), iVar2 != 0)) &&
     (cloud_mngt_err_switch != '\0')) {
    printf("[CLOUD_MNGT_ERROR]%s()/%d send  all update token error\n",
           "cloud_mngt_jcs_update_token_set",0x1e8d);
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  return;
}

