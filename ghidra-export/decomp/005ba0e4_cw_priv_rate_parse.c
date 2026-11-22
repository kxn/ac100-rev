// func cw_priv_rate_parse @ 005ba0e4 size=468

undefined4 cw_priv_rate_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  byte bVar5;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x37,0x84);
  if (__s == (byte *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_rate_parse",0x87);
    }
  }
  else {
    memset(__s,0,0x37);
    uVar2 = cw_protocol_retrieve8(param_1);
    *__s = (byte)uVar2;
    if (uVar2 < 0x20) {
      cw_protocol_retrieve_bytes(param_1,__s + 1,8);
      cw_protocol_retrieve_bytes(param_1,__s + 9,8);
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[0x11] = bVar5;
      cw_protocol_retrieve_bytes(param_1,__s + 0x12,4);
      cw_protocol_retrieve_bytes(param_1,__s + 0x16,4);
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[0x1a] = bVar5;
      cw_protocol_retrieve_bytes(param_1,__s + 0x1b,0xc);
      cw_protocol_retrieve_bytes(param_1,__s + 0x27,0xc);
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[0x33] = bVar5;
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[0x34] = bVar5;
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[0x35] = bVar5;
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[0x36] = bVar5;
      *(byte **)(param_2 + 0x10) = __s;
      uVar3 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar3 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_rate_parse",0x90,(uint)*__s);
      }
      FUN_00407df0(__s);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

