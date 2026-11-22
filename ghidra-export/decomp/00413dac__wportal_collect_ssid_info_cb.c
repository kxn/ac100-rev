// func _wportal_collect_ssid_info_cb @ 00413dac size=232

undefined4 _wportal_collect_ssid_info_cb(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_180 [368];
  
  memset(auStack_180,0,0x16c);
  memset(auStack_180,0,0x16c);
  iVar1 = wportal_db_ssid_rdt_get(param_2,auStack_180);
  uVar2 = 0;
  if (iVar1 == 0) {
    iVar1 = FUN_00408450(0x10,0x63c);
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
      if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d malloc WPORTAL_SSID_INFO_NODE failed\n",
               "_wportal_collect_ssid_info_cb",0x63f);
      }
    }
    else {
      *(undefined1 *)(iVar1 + 0xd) = *(undefined1 *)(param_1 + 1);
      *(byte *)(iVar1 + 0xc) = (byte)*param_1 & 0xf;
      FUN_004086b0(param_3,iVar1);
    }
  }
  return uVar2;
}

