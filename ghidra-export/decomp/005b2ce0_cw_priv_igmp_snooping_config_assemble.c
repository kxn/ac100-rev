// func cw_priv_igmp_snooping_config_assemble @ 005b2ce0 size=296

undefined4 cw_priv_igmp_snooping_config_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  
  puVar4 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar4);
  cw_protocol_restore8(param_1,puVar4[1]);
  cw_protocol_restore8(param_1,puVar4[2]);
  if (puVar4[2] == '\0') {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    iVar5 = 0;
    if (*(int *)(puVar4 + 4) == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d radio list should not be NULL\n",
             "cw_priv_igmp_snooping_config_assemble",0xbb);
      return 0xffffffff;
    }
    for (; iVar5 < (int)(uint)(byte)puVar4[2]; iVar5 = iVar5 + 1) {
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar4 + 4) + iVar5 * 4));
      cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(puVar4 + 4) + iVar5 * 4 + 2));
    }
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar3 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

