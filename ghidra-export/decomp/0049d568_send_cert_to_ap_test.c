// func send_cert_to_ap_test @ 0049d568 size=1

/* WARNING: Removing unreachable block (ram,0x00491a00) */
/* WARNING: Removing unreachable block (ram,0x00491a14) */
/* WARNING: Removing unreachable block (ram,0x00491aa4) */
/* WARNING: Removing unreachable block (ram,0x00491ab0) */
/* WARNING: Removing unreachable block (ram,0x00491c24) */
/* WARNING: Removing unreachable block (ram,0x00491c34) */
/* WARNING: Removing unreachable block (ram,0x00491c44) */

undefined4 send_cert_to_ap_test(void)

{
  int iVar1;
  undefined4 uVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  int iStack_2f8;
  int iStack_2f4;
  undefined1 auStack_2f0 [728];
  
  iStack_2f4 = 0;
  iStack_2f8 = 0;
  memset(auStack_2f0,0,0x2d8);
  memset(auStack_2f0,0,0x2d8);
  iVar1 = cloud_mngt_get_cert_or_key(&iStack_2f4,&g_cert_file_name);
  if (iVar1 == 0) {
    iVar1 = cloud_mngt_get_cert_or_key(&iStack_2f8,&g_key_file_name);
    if (iVar1 == 0) {
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d get cert files content is:\n %s \n\n",
               "cloud_mngt_notify_ca_certs",0x1bf5,iStack_2f4);
      }
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d get key files content is:\n %s \n\n",
               "cloud_mngt_notify_ca_certs",0x1bf6,iStack_2f8);
      }
      uVar4 = json_object_new_object();
      uVar3 = json_object_new_object();
      iVar1 = json_object_new_object();
      uVar2 = json_object_new_string(&DAT_00697f28);
      json_object_object_add(iVar1,"method",uVar2);
      uVar2 = json_object_new_string(iStack_2f4);
      json_object_object_add(uVar3,"cert_content",uVar2);
      uVar2 = json_object_new_string(iStack_2f8);
      json_object_object_add(uVar3,"key",uVar2);
      json_object_object_add(uVar4,"ca_cert",uVar3);
      json_object_object_add(iVar1,"security_manage",uVar4);
      uVar4 = json_object_to_json_string_ext(iVar1,0);
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d get send tdcp_msg:%s\n","cloud_mngt_notify_ca_certs",
               0x1c07,uVar4);
      }
      apmngr_db_foreach_proc(0xffffffff,_cloud_mngt_notify_ca_certs_by_id,uVar4);
      uVar4 = 0;
      goto LAB_00491a40;
    }
    if (cloud_mngt_err_switch != '\0') {
      __format = "[CLOUD_MNGT_ERROR]%s()/%d get key files failed!\n";
      uVar3 = 0x1bf1;
      goto LAB_00491bf0;
    }
  }
  else if (cloud_mngt_err_switch != '\0') {
    __format = "[CLOUD_MNGT_ERROR]%s()/%d get cert files failed!\n";
    uVar3 = 0x1beb;
LAB_00491bf0:
    uVar4 = 0xffffffff;
    printf(__format,"cloud_mngt_notify_ca_certs",uVar3);
    iVar1 = 0;
    goto LAB_00491a40;
  }
  uVar4 = 0xffffffff;
  iVar1 = 0;
LAB_00491a40:
  if (iStack_2f4 != 0) {
    FUN_00407df0();
    iStack_2f4 = 0;
  }
  if (iStack_2f8 != 0) {
    FUN_00407df0();
    iStack_2f8 = 0;
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  return uVar4;
}

