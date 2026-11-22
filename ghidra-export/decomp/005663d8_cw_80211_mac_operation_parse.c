// func cw_80211_mac_operation_parse @ 005663d8 size=448

undefined4 cw_80211_mac_operation_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  int iVar3;
  undefined2 uVar5;
  byte bVar6;
  undefined4 uVar4;
  char *__format;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x10,0x6b);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memeory\n","cw_80211_mac_operation_parse",0x6e);
    return 0xffffffff;
  }
  memset(__s,0,0x10);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    iVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)iVar3;
    if (iVar3 == 0) {
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 2) = uVar5;
      bVar6 = cw_protocol_retrieve8(param_1);
      __s[4] = bVar6;
      bVar6 = cw_protocol_retrieve8(param_1);
      __s[5] = bVar6;
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 6) = uVar5;
      uVar4 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 8) = uVar4;
      uVar4 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0xc) = uVar4;
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056651c;
    bVar6 = __s[1];
    __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zeroed\n";
    uVar4 = 0x80;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056651c;
    bVar6 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x77;
  }
  printf(__format,"cw_80211_mac_operation_parse",uVar4,(uint)bVar6);
LAB_0056651c:
  FUN_00407df0(__s);
  return 0xffffffff;
}

