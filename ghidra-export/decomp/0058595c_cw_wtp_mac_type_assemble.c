// func cw_wtp_mac_type_assemble @ 0058595c size=188

undefined4 cw_wtp_mac_type_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar4 < 3) {
    cw_protocol_restore8();
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d wtp mac type(%d) is wrong\n","cw_wtp_mac_type_assemble",0xa5,
             (uint)*pbVar4);
    }
  }
  return uVar3;
}

