// func cloud_mngt_apmngr_callback_wtp_disconnect @ 00491438 size=216

undefined4 cloud_mngt_apmngr_callback_wtp_disconnect(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if ((((param_1 != 0) && (uVar3 = 0, *(int *)(param_1 + 0xc) != 0)) &&
      (iVar1 = _cloud_mngt_role_match(*(undefined4 *)(param_1 + 0x14)), iVar1 != 0)) &&
     (ap_report_switch != 0)) {
    if (cloud_mngt_debug_switch == '\0') {
      cVar2 = *(char *)(param_1 + 0x1c5);
    }
    else {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_apmngr_callback_wtp_disconnect start\n",
             "cloud_mngt_apmngr_callback_wtp_disconnect",0xdd9);
      cVar2 = *(char *)(param_1 + 0x1c5);
    }
    if ((cVar2 != '\0') && (*(int *)(param_1 + 0x3c) != 0)) {
      ap_offline_or_online = 1;
    }
    uVar3 = 0;
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_apmngr_callback_wtp_disconnect end\n",
             "cloud_mngt_apmngr_callback_wtp_disconnect",0xdde);
    }
  }
  return uVar3;
}

