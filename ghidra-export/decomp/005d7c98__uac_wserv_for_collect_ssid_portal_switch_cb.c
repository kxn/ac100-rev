// func _uac_wserv_for_collect_ssid_portal_switch_cb @ 005d7c98 size=296

undefined4
_uac_wserv_for_collect_ssid_portal_switch_cb(char *param_1,int param_2,undefined4 *param_3)

{
  void *__s;
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  pcVar2 = param_1;
  if (g_wserv_debug != 0) {
    iVar1 = is_target_debug_ap();
    pcVar2 = " ip list \r\n";
    if (iVar1 != 0) {
      printf("<wserv>[debug]%s(): %d  -> wserv_id = %d\r\n",
             "_uac_wserv_for_collect_ssid_portal_switch_cb",0x12b9,*(undefined4 *)(param_1 + 0x80));
      pcVar2 = (char *)0x10;
    }
  }
  if (param_2 == 0) {
    uVar3 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(pcVar2), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> priv is null\r\n",
             "_uac_wserv_for_collect_ssid_portal_switch_cb",0x12bc);
    }
  }
  else {
    uVar3 = 0xffffffff;
    __s = (void *)FUN_00408450(0x10,0x12c0);
    if (__s != (void *)0x0) {
      memset(__s,0,0x10);
      uVar3 = 0;
      *(byte *)((int)__s + 0xc) = (byte)*param_3 & 0xf;
      *(undefined1 *)((int)__s + 0xd) = *(undefined1 *)(param_3 + 1);
      *(char *)((int)__s + 0xe) = param_1[0x127];
      FUN_004086b0(param_2 + 4,__s);
    }
  }
  return uVar3;
}

