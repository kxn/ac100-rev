// func cw_priv_arp_defend_parse @ 005ab914 size=444

undefined4 cw_priv_arp_defend_parse(undefined4 param_1,int param_2)

{
  undefined1 *__s;
  undefined1 uVar3;
  int iVar1;
  void *__s_00;
  undefined4 uVar2;
  int iVar4;
  
  __s = (undefined1 *)FUN_00408450(0xc,0x7b);
  if (__s == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_arp_defend_parse",0x7e);
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
    if (iVar1 != 0) {
      __s_00 = (void *)FUN_00408450(iVar1 * 0xc,0x90);
      *(void **)(__s + 8) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc arp info list failed\n","cw_priv_arp_defend_parse",
                 0x93);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,*(int *)(__s + 4) * 0xc);
      iVar1 = *(int *)(__s + 4);
      for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
        iVar1 = *(int *)(__s + 8);
        uVar2 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(iVar1 + iVar4 * 0xc) = uVar2;
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 8) + iVar4 * 0xc + 4,6);
        iVar1 = *(int *)(__s + 4);
      }
    }
    uVar2 = 0;
    *(undefined1 **)(param_2 + 0x10) = __s;
  }
  return uVar2;
}

