// func cw_priv_dhcp_defend_parse @ 005afb5c size=456

undefined4 cw_priv_dhcp_defend_parse(undefined4 param_1,int param_2)

{
  undefined1 *__s;
  undefined1 uVar3;
  int iVar1;
  void *__s_00;
  uint uVar2;
  undefined4 uVar4;
  uint uVar5;
  
  __s = (undefined1 *)FUN_00408450(0xc,0x7c);
  if (__s == (undefined1 *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_dhcp_defend_parse",0x7f);
    }
  }
  else {
    memset(__s,0,0xc);
    uVar3 = cw_protocol_retrieve8(param_1);
    *__s = uVar3;
    uVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = uVar3;
    iVar1 = cw_protocol_retrieve32(param_1);
    *(int *)(__s + 4) = iVar1;
    if ((__s[1] != '\0') && (iVar1 != 0)) {
      __s_00 = (void *)FUN_00408450(iVar1 * 7,0x8d);
      *(void **)(__s + 8) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc bind svr list failed\n","cw_priv_dhcp_defend_parse",
                 0x90);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,*(int *)(__s + 4) * 7);
      uVar2 = *(uint *)(__s + 4);
      for (uVar5 = 0; uVar5 < uVar2; uVar5 = uVar5 + 1) {
        iVar1 = *(int *)(__s + 8);
        uVar3 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar1 + uVar5 * 7) = uVar3;
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 8) + uVar5 * 7 + 1,6);
        uVar2 = *(uint *)(__s + 4);
      }
    }
    uVar4 = 0;
    *(undefined1 **)(param_2 + 0x10) = __s;
  }
  return uVar4;
}

