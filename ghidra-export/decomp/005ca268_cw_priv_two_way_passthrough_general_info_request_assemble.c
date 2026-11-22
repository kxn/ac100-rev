// func cw_priv_two_way_passthrough_general_info_request_assemble @ 005ca268 size=264

undefined4 cw_priv_two_way_passthrough_general_info_request_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  
  puVar5 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar5);
  cw_protocol_restore8(param_1,puVar5[1]);
  cw_protocol_restore8(param_1,puVar5[2]);
  cw_protocol_restore8(param_1,puVar5[3]);
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar5 + 4));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar5 + 8));
  if (*(uint *)(puVar5 + 8) == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    if (*(int *)(puVar5 + 0xc) == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d data is null\n",
             "cw_priv_two_way_passthrough_general_info_request_assemble",0xb0);
      return 0xffffffff;
    }
    cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar5 + 0xc),*(uint *)(puVar5 + 8) & 0xffff);
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar3 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

