// func apupd_db_wtp_ip_update @ 006546d0 size=292

undefined4
apupd_db_wtp_ip_update(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if ((param_1 == 0) || (apupd_wtp_hash == 0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_wtp_ip_update",0x20d3);
    }
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    iVar1 = FUN_00407fa0(apupd_wtp_hash,param_1);
    if (iVar1 == 0) {
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: get wtp from hash by mac failed.\r\n",
               "apupd_db_wtp_ip_update",0x20dd);
      }
      uVar2 = 0xffffffff;
      FUN_00407f30(apupd_db_mutex);
    }
    else {
      uVar2 = 0;
      memcpy((void *)(iVar1 + 0x18),&local_res4,0x14);
      FUN_00407f30(apupd_db_mutex);
    }
  }
  return uVar2;
}

