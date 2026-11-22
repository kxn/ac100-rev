// func cloud_multilink_switch_to_master @ 00499a34 size=284

undefined4 cloud_multilink_switch_to_master(undefined2 param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_2e8 [600];
  uint local_90;
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == 0) {
    if (ap_report_switch == 0) {
      return 0;
    }
    if ((local_90 & 0x1000) == 0) {
      return 0;
    }
    iVar1 = FUN_00498f20(ap_report_switch & 0xff,param_1,0);
    if ((iVar1 != 0) && (cloud_mngt_err_switch != '\0')) {
      printf("[CLOUD_MNGT_ERROR]%s()/%d notify online failed!\n","cloud_multilink_switch_to_master",
             0x1f8d);
    }
    iVar1 = cloud_mngt_notify_ca_certs(param_1,0);
    uVar3 = 0;
    if (iVar1 == 0) {
      return 0;
    }
    if (cloud_mngt_err_switch == '\0') {
      return 0;
    }
    __format = "[CLOUD_MNGT_ERROR]%s()/%d notify certs failed!\n";
    uVar2 = 0x1f92;
  }
  else {
    uVar3 = 0xffffffff;
    if (cloud_mngt_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[CLOUD_MNGT_ERROR]%s()/%d switch to master failed\n";
    uVar2 = 0x1f85;
  }
  printf(__format,"cloud_multilink_switch_to_master",uVar2);
  return uVar3;
}

