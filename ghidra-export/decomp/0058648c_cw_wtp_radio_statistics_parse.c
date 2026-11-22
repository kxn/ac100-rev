// func cw_wtp_radio_statistics_parse @ 0058648c size=432

undefined4 cw_wtp_radio_statistics_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  byte bVar5;
  undefined2 uVar4;
  int iVar3;
  char *__format;
  undefined4 uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x14,0x7f);
  if (__s == (byte *)0x0) {
    return 0xffffffff;
  }
  memset(__s,0,0x14);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    bVar5 = cw_protocol_retrieve8(param_1);
    __s[1] = bVar5;
    if (0xfa < (byte)(bVar5 - 4)) {
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 2) = uVar4;
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 4) = uVar4;
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 6) = uVar4;
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 8) = uVar4;
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 10) = uVar4;
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 0xc) = uVar4;
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 0xe) = uVar4;
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 0x10) = uVar4;
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 0x12) = uVar4;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005865c4;
    bVar5 = __s[1];
    __format = "[CW_ERROR]%32s():%4d last fail type(%d) is wrong\n";
    uVar6 = 0x95;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005865c4;
    bVar5 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x8a;
  }
  printf(__format,"cw_wtp_radio_statistics_parse",uVar6,(uint)bVar5);
LAB_005865c4:
  FUN_00407df0(__s);
  return 0xffffffff;
}

