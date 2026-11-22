// func cw_priv_roaming_control_parse @ 005bcd04 size=468

undefined4 cw_priv_roaming_control_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar4;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(0x24,0x84);
  if (__s == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_roaming_control_parse",0x87);
    }
  }
  else {
    memset(__s,0,0x24);
    uVar4 = cw_protocol_retrieve8(param_1);
    *__s = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[1] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[2] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[3] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[4] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[5] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[6] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[7] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[8] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[9] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[10] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0xb] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0xc] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0xd] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0xe] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0xf] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0x10] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0x11] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0x12] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0x13] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[0x14] = uVar4;
    cw_protocol_retrieve_bytes(param_1,__s + 0x15,0xf);
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

