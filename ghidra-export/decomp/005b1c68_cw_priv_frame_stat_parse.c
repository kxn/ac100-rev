// func cw_priv_frame_stat_parse @ 005b1c68 size=676

undefined4 cw_priv_frame_stat_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x7c,0xaa);
  if (__s == (byte *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_frame_stat_parse",0xad);
    }
  }
  else {
    memset(__s,0,0x7c);
    uVar2 = cw_protocol_retrieve8(param_1);
    *__s = (byte)uVar2;
    if (uVar2 < 0x20) {
      cw_protocol_retrieve_bytes(param_1,__s + 1,3);
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 4) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 8) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0xc) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x10) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x14) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x18) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x1c) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x20) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x24) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x28) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x2c) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x30) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x34) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x38) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x3c) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x40) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x44) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x48) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x4c) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x50) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x54) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x58) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x5c) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x60) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 100) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x68) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x6c) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x70) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x74) = uVar3;
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x78) = uVar3;
      *(byte **)(param_2 + 0x10) = __s;
      uVar3 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar3 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_frame_stat_parse",0xb6,
               (uint)*__s);
      }
      FUN_00407df0(__s);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

