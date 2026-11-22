// func uac_nms_report_jcs_switch_set @ 0049fe70 size=260

void uac_nms_report_jcs_switch_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__src;
  char local_10 [8];
  
  local_10[0] = '\0';
  local_10[1] = '\0';
  local_10[2] = '\0';
  local_10[3] = '\0';
  iVar1 = json_object_object_get(param_1,"enable");
  if (iVar1 == 0) {
    return;
  }
  local_10[0] = '\0';
  local_10[1] = '\0';
  local_10[2] = '\0';
  local_10[3] = '\0';
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 6) {
    __src = (char *)json_object_get_string(iVar1);
  }
  else {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "uac_nms_report_jcs_switch_set",0x3e3);
    }
    __src = "";
  }
  strncpy(local_10,__src,3);
  iVar1 = strcmp("on",local_10);
  if (iVar1 == 0) {
    uVar3 = 1;
    g_nms_support_switch = 1;
  }
  else {
    iVar1 = strcmp("off",local_10);
    if (iVar1 != 0) {
      return;
    }
    uVar3 = 0;
    g_nms_support_switch = 0;
  }
  need_to_notify_ap_begin_report_by_flag_mask(uVar3,0,0,4);
  return;
}

