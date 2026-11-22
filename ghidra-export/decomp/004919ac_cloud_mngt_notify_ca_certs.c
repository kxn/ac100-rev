// func cloud_mngt_notify_ca_certs @ 004919ac size=792

undefined4 cloud_mngt_notify_ca_certs(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_2f8;
  int local_2f4;
  undefined1 auStack_2f0 [728];
  
  local_2f4 = 0;
  local_2f8 = 0;
  memset(auStack_2f0,0,0x2d8);
  memset(auStack_2f0,0,0x2d8);
  if ((param_2 == 0) &&
     (iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2f0), iVar1 != 0)) {
    if (cloud_mngt_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[CLOUD_MNGT_ERROR]%s()/%d get ap_entry(%d) failed.\n","cloud_mngt_notify_ca_certs",
           0x1be4,param_1);
    return 0xffffffff;
  }
  iVar1 = cloud_mngt_get_cert_or_key(&local_2f4,&g_cert_file_name);
  if (iVar1 == 0) {
    iVar1 = cloud_mngt_get_cert_or_key(&local_2f8,&g_key_file_name);
    if (iVar1 == 0) {
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d get cert files content is:\n %s \n\n",
               "cloud_mngt_notify_ca_certs",0x1bf5,local_2f4);
      }
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d get key files content is:\n %s \n\n",
               "cloud_mngt_notify_ca_certs",0x1bf6,local_2f8);
      }
      uVar4 = json_object_new_object();
      uVar5 = json_object_new_object();
      iVar1 = json_object_new_object();
      uVar2 = json_object_new_string(&DAT_00697f28);
      json_object_object_add(iVar1,"method",uVar2);
      uVar2 = json_object_new_string(local_2f4);
      json_object_object_add(uVar5,"cert_content",uVar2);
      uVar2 = json_object_new_string(local_2f8);
      json_object_object_add(uVar5,"key",uVar2);
      json_object_object_add(uVar4,"ca_cert",uVar5);
      json_object_object_add(iVar1,"security_manage",uVar4);
      uVar4 = json_object_to_json_string_ext(iVar1,0);
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d get send tdcp_msg:%s\n","cloud_mngt_notify_ca_certs",
               0x1c07,uVar4);
      }
      if (param_2 == 0) {
        iVar3 = _cloud_mngt_notify_ca_certs_by_id(auStack_2f0,uVar4);
        uVar5 = 0;
        if ((iVar3 != 0) && (uVar5 = 0xffffffff, cloud_mngt_err_switch != '\0')) {
          printf("[CLOUD_MNGT_ERROR]%s()/%d send ssl certs to ap all failed!\n",
                 "cloud_mngt_notify_ca_certs",0x1c11);
        }
      }
      else {
        apmngr_db_foreach_proc(0xffffffff,_cloud_mngt_notify_ca_certs_by_id,uVar4);
        uVar5 = 0;
      }
      goto LAB_00491a44;
    }
    if (cloud_mngt_err_switch != '\0') {
      __format = "[CLOUD_MNGT_ERROR]%s()/%d get key files failed!\n";
      uVar4 = 0x1bf1;
      goto LAB_00491bf0;
    }
  }
  else if (cloud_mngt_err_switch != '\0') {
    __format = "[CLOUD_MNGT_ERROR]%s()/%d get cert files failed!\n";
    uVar4 = 0x1beb;
LAB_00491bf0:
    uVar5 = 0xffffffff;
    printf(__format,"cloud_mngt_notify_ca_certs",uVar4);
    iVar1 = 0;
    goto LAB_00491a44;
  }
  uVar5 = 0xffffffff;
  iVar1 = 0;
LAB_00491a44:
  if (local_2f4 != 0) {
    FUN_00407df0();
    local_2f4 = 0;
  }
  if (local_2f8 != 0) {
    FUN_00407df0();
    local_2f8 = 0;
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  return uVar5;
}

