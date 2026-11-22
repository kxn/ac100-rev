// func cw_priv_dhcpv6_defend_parse @ 005b036c size=492

undefined4 cw_priv_dhcpv6_defend_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar5;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  void *__s_00;
  uint uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(0xc,0x82);
  if (__s == (undefined1 *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_dhcpv6_defend_parse",0x85);
    }
  }
  else {
    memset(__s,0,0xc);
    uVar5 = cw_protocol_retrieve8(param_1);
    *__s = uVar5;
    uVar5 = cw_protocol_retrieve8(param_1);
    __s[1] = uVar5;
    iVar2 = cw_protocol_retrieve32(param_1);
    *(int *)(__s + 4) = iVar2;
    if (__s[1] == '\0') {
      uVar3 = (uint)*(ushort *)(param_2 + 0xe);
    }
    else if (iVar2 == 0) {
      uVar3 = (uint)*(ushort *)(param_2 + 0xe);
    }
    else {
      __s_00 = (void *)FUN_00408450(iVar2 * 0x11,0x93);
      *(void **)(__s + 8) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc bind svr list failed\n","cw_priv_dhcpv6_defend_parse",
                 0x96);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,*(int *)(__s + 4) * 0x11);
      uVar3 = *(uint *)(__s + 4);
      for (uVar6 = 0; uVar6 < uVar3; uVar6 = uVar6 + 1) {
        iVar2 = *(int *)(__s + 8);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar2 + uVar6 * 0x11) = uVar5;
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 8) + uVar6 * 0x11 + 1,0x10);
        uVar3 = *(uint *)(__s + 4);
      }
      uVar3 = (uint)*(ushort *)(param_2 + 0xe);
    }
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == uVar3) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

