// func cw_80211_tx_power_parse @ 00569b34 size=388

undefined4 cw_80211_tx_power_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  char *__format;
  undefined4 uVar7;
  
  uVar2 = *(ushort *)(param_1 + 6);
  pbVar3 = (byte *)FUN_00408450(4,0x65);
  if (pbVar3 == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_tx_power_parse",0x68);
    return 0xffffffff;
  }
  *pbVar3 = 0;
  pbVar3[1] = 0;
  pbVar3[2] = 0;
  pbVar3[3] = 0;
  uVar4 = cw_protocol_retrieve8(param_1);
  *pbVar3 = (byte)uVar4;
  if (uVar4 < 0x20) {
    iVar5 = cw_protocol_retrieve8(param_1);
    pbVar3[1] = (byte)iVar5;
    if (iVar5 == 0) {
      uVar6 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(pbVar3 + 2) = uVar6;
      *(byte **)(param_2 + 0x10) = pbVar3;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00569c3c;
    bVar1 = pbVar3[1];
    __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zeroed\n";
    uVar7 = 0x7a;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00569c3c;
    bVar1 = *pbVar3;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar7 = 0x71;
  }
  printf(__format,"cw_80211_tx_power_parse",uVar7,(uint)bVar1);
LAB_00569c3c:
  FUN_00407df0(pbVar3);
  return 0xffffffff;
}

