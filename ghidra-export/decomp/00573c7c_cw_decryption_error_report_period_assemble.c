// func cw_decryption_error_report_period_assemble @ 00573c7c size=200

undefined4 cw_decryption_error_report_period_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar4 < 0x20) {
    cw_protocol_restore8();
    cw_protocol_restore16(param_1,*(undefined2 *)(pbVar4 + 2));
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n",
             "cw_decryption_error_report_period_assemble",0x8f,(uint)*pbVar4);
    }
  }
  return uVar3;
}

