// func cw_priv_trans_data_request_assemble @ 005c9e0c size=216

undefined4 cw_priv_trans_data_request_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 *puVar5;
  
  puVar5 = *(undefined2 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore16(param_1,*puVar5);
  cw_protocol_restore16(param_1,puVar5[1]);
  if (*(uint *)(puVar5 + 2) == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    if (*(int *)(puVar5 + 4) == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d data is null\n","cw_priv_trans_data_request_assemble",0xa0);
      return 0xffffffff;
    }
    cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar5 + 4),*(uint *)(puVar5 + 2) & 0xffff);
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar3 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

