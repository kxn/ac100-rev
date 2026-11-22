// func cw_priv_nd_defend_parse @ 005b73dc size=472

undefined4 cw_priv_nd_defend_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 *__s;
  undefined1 uVar5;
  int iVar3;
  undefined4 uVar4;
  void *__s_00;
  int iVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(0xc,0x81);
  if (__s == (undefined1 *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_nd_defend_parse",0x84);
    }
  }
  else {
    memset(__s,0,0xc);
    uVar5 = cw_protocol_retrieve8(param_1);
    *__s = uVar5;
    uVar5 = cw_protocol_retrieve8(param_1);
    __s[1] = uVar5;
    iVar3 = cw_protocol_retrieve32(param_1);
    *(int *)(__s + 4) = iVar3;
    if (iVar3 == 0) {
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    else {
      __s_00 = (void *)FUN_00408450(iVar3 * 0x16,0x96);
      *(void **)(__s + 8) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc nd info list failed\n","cw_priv_nd_defend_parse",0x99)
          ;
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,*(int *)(__s + 4) * 0x16);
      iVar3 = *(int *)(__s + 4);
      for (iVar6 = 0; iVar6 < iVar3; iVar6 = iVar6 + 1) {
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 8) + iVar6 * 0x16,0x10);
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 8) + iVar6 * 0x16 + 0x10,6);
        iVar3 = *(int *)(__s + 4);
      }
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

