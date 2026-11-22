// func cloud_mngt_client_first_report @ 0049ad3c size=492

void cloud_mngt_client_first_report(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *__s;
  char *__s_00;
  size_t sVar4;
  
  if ((ap_report_switch != 0) && (client_report_switch != 0)) {
    iVar1 = json_object_new_object();
    uVar2 = apmngr_db_get_ap_max();
    iVar3 = FUN_004080a0(client_handle_hash_obj,client_handle_hash_key,client_handle_hash_cmp,uVar2)
    ;
    __s = (int *)FUN_00408450(0x34,0x13b4);
    if (__s != (int *)0x0) {
      memset(__s,0,0x34);
      *__s = iVar1;
      __s[0xb] = iVar3;
      __s[4] = client_report_count;
      __s[6] = 2;
      __s[5] = (int)"subDevice";
      __s[0xc] = 0x3f800;
      cloud_mngt_update_devstatus_param_add(iVar1);
      iVar3 = __s[0xc];
      __s_00 = (char *)json_object_to_json_string_ext(iVar1,0);
      sVar4 = strlen(__s_00);
      __s[0xc] = ~sVar4 + iVar3;
      uVar2 = wsta_profile_get_max_wstation();
      wsta_db_sta_for_each_range(0,uVar2,cloud_mngt_client_add_to_json,__s);
      if ((0 < __s[3]) && (__s[1] != 0)) {
        FUN_00408570(__s[0xb],add_client_hash_node);
        json_object_object_add(*__s,__s[5],__s[1]);
        __s[1] = 0;
        free_ac_cloud_mngt_hash(__s + 0xb,0);
        if ((ap_report_switch != 0) && (client_report_switch != 0)) {
          cloud_mngt_obj_send_to_cloud(__s[6],*__s);
        }
      }
    }
    if (iVar1 != 0) {
      json_object_put(iVar1);
    }
    free_ac_cloud_mngt_hash(__s + 0xb,1);
    if (__s != (int *)0x0) {
      if (__s[1] != 0) {
        json_object_put();
      }
      FUN_00407df0(__s);
      return;
    }
  }
  return;
}

