// func cw_priv_wechat_iplist_assemble @ 005cb4b0 size=204

undefined4 cw_priv_wechat_iplist_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  
  puVar5 = *(uint **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,*puVar5);
  if (*puVar5 == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    if (puVar5[1] == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d data is null\n","cw_priv_wechat_iplist_assemble",0xa4);
      return 0xffffffff;
    }
    cw_protocol_restore_raw_bytes(param_1,puVar5[1],*puVar5 & 0xffff);
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar3 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

