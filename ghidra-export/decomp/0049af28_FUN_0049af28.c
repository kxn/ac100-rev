// func FUN_0049af28 @ 0049af28 size=356

void FUN_0049af28(void)

{
  int iVar1;
  int *__s;
  char *__s_00;
  size_t sVar2;
  undefined4 extraout_v1;
  int iVar3;
  
  iVar1 = json_object_new_object();
  __s = (int *)FUN_00408450(0x34,0x193c);
  if (__s != (int *)0x0) {
    memset(__s,0,0x34);
    *__s = iVar1;
    __s[4] = ap_basic_info_report_rf_count;
    __s[6] = 1;
    __s[5] = (int)"subDevice";
    __s[0xc] = 0x3f800;
    cloud_mngt_update_devstatus_param_add(iVar1);
    iVar3 = __s[0xc];
    __s_00 = (char *)json_object_to_json_string_ext(iVar1,0);
    sVar2 = strlen(__s_00);
    __s[0xc] = ~sVar2 + iVar3;
    apmngr_db_foreach_proc(0x15f0000,cloud_mngt_ap_status_add_to_json,__s);
    FUN_00407e70();
    last_ap_report_time = extraout_v1;
    if ((0 < __s[3]) && (__s[1] != 0)) {
      json_object_object_add(*__s,__s[5]);
      __s[1] = 0;
      if (ap_report_switch != 0) {
        cloud_mngt_obj_send_to_cloud(__s[6],*__s);
      }
    }
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  if (__s == (int *)0x0) {
    return;
  }
  if (__s[1] != 0) {
    json_object_put();
  }
  FUN_00407df0(__s);
  return;
}

