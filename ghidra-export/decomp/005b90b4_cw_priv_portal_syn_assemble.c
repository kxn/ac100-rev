// func cw_priv_portal_syn_assemble @ 005b90b4 size=200

undefined4 cw_priv_portal_syn_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  short *psVar5;
  
  psVar5 = *(short **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore16(param_1,*psVar5);
  if (*psVar5 == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    if (*(int *)(psVar5 + 2) == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d data is null\n","cw_priv_portal_syn_assemble",0x9d);
      return 0xffffffff;
    }
    cw_protocol_restore_raw_bytes(param_1);
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar3 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

