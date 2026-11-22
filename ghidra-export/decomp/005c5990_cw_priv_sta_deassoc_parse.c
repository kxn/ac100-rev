// func cw_priv_sta_deassoc_parse @ 005c5990 size=396

undefined4 cw_priv_sta_deassoc_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x71);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_deassoc_parse",0x74);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 0x20) {
    uVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar3;
    if (uVar3 < 0x11) {
      cw_protocol_retrieve_bytes(param_1,__s + 2,6);
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005c5aa4;
    bVar1 = __s[1];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar5 = 0x86;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005c5aa4;
    bVar1 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar5 = 0x7d;
  }
  printf(__format,"cw_priv_sta_deassoc_parse",uVar5,(uint)bVar1);
LAB_005c5aa4:
  FUN_00407df0(__s);
  return 0xffffffff;
}

