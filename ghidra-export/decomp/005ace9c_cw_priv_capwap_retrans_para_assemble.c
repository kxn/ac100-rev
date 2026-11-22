// func cw_priv_capwap_retrans_para_assemble @ 005ace9c size=216

undefined4 cw_priv_capwap_retrans_para_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar4 == 0) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d Illegal retransmit times %d\n",
             "cw_priv_capwap_retrans_para_assemble",0x96,(uint)*pbVar4);
    }
    FUN_00407df0(pbVar4);
    uVar3 = 0xffffffff;
  }
  else {
    cw_protocol_restore8();
    cw_protocol_restore16(param_1,*(undefined2 *)(pbVar4 + 2));
    cw_protocol_restore8(param_1,pbVar4[4]);
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

