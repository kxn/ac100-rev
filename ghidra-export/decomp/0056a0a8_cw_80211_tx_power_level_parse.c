// func cw_80211_tx_power_level_parse @ 0056a0a8 size=468

undefined4 cw_80211_tx_power_level_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  undefined2 uVar5;
  int iVar4;
  char *__format;
  undefined4 uVar6;
  byte *pbVar7;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x12,0x66);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_tx_power_level_parse",0x69);
    return 0xffffffff;
  }
  memset(__s,0,0x12);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 0x20) {
    uVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar3;
    if (((uVar3 << 1 == *(ushort *)(param_2 + 0xe) - 2) && (uVar3 != 0)) && (uVar3 < 9)) {
      pbVar7 = __s;
      for (iVar4 = 0; iVar4 < (int)(uint)__s[1]; iVar4 = iVar4 + 1) {
        uVar5 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)(pbVar7 + 2) = uVar5;
        pbVar7 = pbVar7 + 2;
      }
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0056a204;
    bVar1 = __s[1];
    __format = "[CW_ERROR]%32s():%4d num levels(%d) is wrong\n";
    uVar6 = 0x7b;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0056a204;
    bVar1 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x72;
  }
  printf(__format,"cw_80211_tx_power_level_parse",uVar6,(uint)bVar1);
LAB_0056a204:
  FUN_00407df0(__s);
  return 0xffffffff;
}

