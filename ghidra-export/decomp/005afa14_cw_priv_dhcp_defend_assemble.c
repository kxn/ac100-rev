// func cw_priv_dhcp_defend_assemble @ 005afa14 size=328

undefined4 cw_priv_dhcp_defend_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  puVar4 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar4);
  cw_protocol_restore8(param_1,puVar4[1]);
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 4));
  if (puVar4[1] == '\0') {
    uVar5 = (uint)*(ushort *)(param_1 + 4);
  }
  else if (*(int *)(puVar4 + 4) == 0) {
    uVar5 = (uint)*(ushort *)(param_1 + 4);
  }
  else {
    uVar5 = 0;
    if (*(int *)(puVar4 + 8) == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d bind svr list should not be NULL\n",
             "cw_priv_dhcp_defend_assemble",0xc4);
      return 0xffffffff;
    }
    for (; uVar5 < *(uint *)(puVar4 + 4); uVar5 = uVar5 + 1) {
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar4 + 8) + uVar5 * 7));
      cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar4 + 8) + uVar5 * 7 + 1,6);
    }
    uVar5 = (uint)*(ushort *)(param_1 + 4);
  }
  uVar2 = 0xffffffff;
  if (uVar5 - uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

