// func cloud_mngt_jcs_set_token_set @ 0048c43c size=472

void cloud_mngt_jcs_set_token_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__src;
  undefined4 uVar3;
  undefined8 uVar4;
  char acStack_410 [1023];
  undefined1 local_11;
  
  memset(acStack_410,0,0x400);
  iVar1 = json_object_object_get(param_1,"deviceToken");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "cloud_mngt_jcs_set_token_set",0x1e5a);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_410,__src,0x3ff);
  local_11 = 0;
  iVar1 = json_object_object_get(param_1,"expiresIn");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
      goto LAB_0048c508;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar4 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      goto LAB_0048c508;
    }
  }
  uVar3 = 0xffffffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "cloud_mngt_jcs_set_token_set",0x1e60);
  }
LAB_0048c508:
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d token:%s,expiresIn:%d\n","cloud_mngt_jcs_set_token_set",0x1e63
           ,acStack_410,uVar3);
  }
  if (((ap_report_switch != 0) &&
      (iVar1 = cloud_mngt_notify_all_update_token(acStack_410,uVar3), iVar1 != 0)) &&
     (cloud_mngt_err_switch != '\0')) {
    printf("[CLOUD_MNGT_ERROR]%s()/%d send  all update token error\n","cloud_mngt_jcs_set_token_set"
           ,0x1e68);
  }
  return;
}

