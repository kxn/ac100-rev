// func cw_radio_administrative_state_parse @ 0057f608 size=376

undefined4 cw_radio_administrative_state_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  
  uVar2 = *(ushort *)(param_1 + 6);
  pbVar3 = (byte *)FUN_00408450(2,0x6f);
  if (pbVar3 == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_radio_administrative_state_parse",0x72);
    return 0xffffffff;
  }
  *pbVar3 = 0;
  pbVar3[1] = 0;
  uVar4 = cw_protocol_retrieve8(param_1);
  *pbVar3 = (byte)uVar4;
  if (uVar4 < 0x20) {
    iVar5 = cw_protocol_retrieve8(param_1);
    pbVar3[1] = (byte)iVar5;
    if (iVar5 - 1U < 2) {
      *(byte **)(param_2 + 0x10) = pbVar3;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_0057f708;
    bVar1 = pbVar3[1];
    __format = "[CW_ERROR]%32s():%4d state(%d) is wrong\n";
    uVar6 = 0x84;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_0057f708;
    bVar1 = *pbVar3;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x7b;
  }
  printf(__format,"cw_radio_administrative_state_parse",uVar6,(uint)bVar1);
LAB_0057f708:
  FUN_00407df0(pbVar3);
  return 0xffffffff;
}

