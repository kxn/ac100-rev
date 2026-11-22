// func cw_priv_wlan_list_parse @ 005cba28 size=432

undefined4 cw_priv_wlan_list_parse(undefined4 param_1,int param_2)

{
  undefined4 *__s;
  undefined4 uVar1;
  int iVar2;
  void *__s_00;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  
  __s = (undefined4 *)FUN_00408450(0xc,0x7f);
  if (__s == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wlan_list_parse",0x82);
    }
  }
  else {
    memset(__s,0,0xc);
    uVar1 = cw_protocol_retrieve32(param_1);
    *__s = uVar1;
    iVar2 = cw_protocol_retrieve32(param_1);
    __s[1] = iVar2;
    if (iVar2 != 0) {
      __s_00 = (void *)FUN_00408450(iVar2 * 0x21,0x8e);
      __s[2] = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc wlan info list failed\n","cw_priv_wlan_list_parse",
                 0x91);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,__s[1] * 0x21);
      uVar3 = __s[1];
      for (uVar5 = 0; uVar5 < uVar3; uVar5 = uVar5 + 1) {
        iVar2 = __s[2];
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar2 + uVar5 * 0x21) = uVar4;
        cw_protocol_retrieve_bytes(param_1,__s[2] + uVar5 * 0x21 + 1,0x20);
        uVar3 = __s[1];
      }
    }
    uVar1 = 0;
    *(undefined4 **)(param_2 + 0x10) = __s;
  }
  return uVar1;
}

