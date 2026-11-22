// func cloud_mngt_ap_add_report @ 00495768 size=576

void cloud_mngt_ap_add_report(int param_1)

{
  int iVar1;
  int *__s;
  int iVar2;
  char *__s_00;
  size_t sVar3;
  undefined4 extraout_v1;
  code *pcVar4;
  
  if (ap_report_switch != 0) {
    iVar1 = json_object_new_object();
    __s = (int *)FUN_00408450(0x34,0x135c);
    if (__s != (int *)0x0) {
      memset(__s,0,0x34);
      *__s = iVar1;
      __s[4] = ap_report_count;
      __s[6] = 3;
      __s[5] = (int)"aps";
      __s[0xc] = 0x3f800;
      FUN_0051ad88(__s + 8);
      iVar2 = FUN_004080a0(_cloud_mngt_model_data_obj,_cloud_mngt_model_data_key,
                           _cloud_mngt_model_data_cmp,600);
      __s[7] = iVar2;
      if (iVar2 != 0) {
        FUN_0049164c(iVar1);
        iVar2 = __s[0xc];
        __s_00 = (char *)json_object_to_json_string_ext(iVar1,0);
        sVar3 = strlen(__s_00);
        __s[0xc] = iVar2 - sVar3;
        if (param_1 == 0) {
          pcVar4 = cloud_mngt_recycle_report_ap_add_to_json;
        }
        else {
          pcVar4 = cloud_mngt_first_report_ap_add_to_json;
        }
        apmngr_db_foreach_proc(0x15f0000,pcVar4,__s);
        if ((0 < __s[3]) && (__s[1] != 0)) {
          json_object_object_add(*__s,__s[5]);
          __s[1] = 0;
          if ((cloud_mngt_apdb_report_switch != '\0') && (__s[2] != 0)) {
            json_object_object_add(*__s,&DAT_00699510);
            __s[2] = 0;
          }
          if (ap_report_switch != 0) {
            cloud_mngt_obj_send_to_cloud(__s[6],*__s);
          }
        }
      }
    }
    if (iVar1 != 0) {
      json_object_put(iVar1);
    }
    if (__s != (int *)0x0) {
      if (__s[1] == 0) {
        iVar1 = __s[2];
      }
      else {
        json_object_put();
        iVar1 = __s[2];
      }
      if (iVar1 == 0) {
        iVar1 = __s[7];
      }
      else {
        json_object_put();
        iVar1 = __s[7];
      }
      if (iVar1 != 0) {
        while( true ) {
          iVar1 = FUN_004081b0(__s + 8);
          if (iVar1 == 0) break;
          FUN_00407f40(__s[7],iVar1);
          FUN_00408500(iVar1);
          FUN_00407df0(iVar1);
        }
        FUN_00408310();
      }
      FUN_00407df0(__s);
    }
    FUN_00407e70();
    last_ap_add_time = extraout_v1;
  }
  return;
}

