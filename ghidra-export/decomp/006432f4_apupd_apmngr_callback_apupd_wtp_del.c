// func apupd_apmngr_callback_apupd_wtp_del @ 006432f4 size=320

undefined4 apupd_apmngr_callback_apupd_wtp_del(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((g_apupd_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
    if (param_1 != 0) {
      iVar1 = *(int *)(param_1 + 0xc);
      goto LAB_00643320;
    }
  }
  else {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_apmngr_callback_apupd_wtp_del, apid = %d\r\n",
           "apupd_apmngr_callback_apupd_wtp_del",0xf22,(uint)*(ushort *)(param_1 + 0x10));
    if (param_1 != 0) {
      iVar1 = *(int *)(param_1 + 0xc);
LAB_00643320:
      if (iVar1 == 0) {
        uVar3 = 0;
        if (g_apupd_debug == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        __format = "[APUPD_DEBUG]%32s() %05d: wtp is template, don\'t delete it.\r\n";
        uVar2 = 0xf2d;
      }
      else {
        iVar1 = apupd_db_wtp_delete_by_mac(param_1 + 0x48);
        if (iVar1 != -1) {
          return 0;
        }
        uVar3 = 0xffffffff;
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_ERROR]%32s() %05d: delete wtp failed.\r\n";
        uVar2 = 0xf3b;
      }
      goto LAB_006433d4;
    }
  }
  uVar3 = 0xffffffff;
  if (g_apupd_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
  uVar2 = 0xf26;
LAB_006433d4:
  printf(__format,"apupd_apmngr_callback_apupd_wtp_del",uVar2);
  return uVar3;
}

