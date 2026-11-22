// func cw_capwap_control_ipv6_address_parse @ 00570c68 size=228

undefined4 cw_capwap_control_ipv6_address_parse(int param_1,int param_2)

{
  ushort uVar1;
  void *__s;
  undefined2 uVar4;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0x12,0x6d);
  if (__s == (void *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_capwap_control_ipv6_address_parse",0x70);
    }
  }
  else {
    memset(__s,0,0x12);
    cw_protocol_retrieve_bytes(param_1,__s,0x10);
    uVar4 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)((int)__s + 0x10) = uVar4;
    *(void **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

