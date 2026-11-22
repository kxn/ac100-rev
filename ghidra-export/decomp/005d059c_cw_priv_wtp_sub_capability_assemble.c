// func cw_priv_wtp_sub_capability_assemble @ 005d059c size=316

undefined4 cw_priv_wtp_sub_capability_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  
  puVar4 = *(ushort **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore16(param_1,*puVar4);
  if (*puVar4 == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    iVar5 = 0;
    if (*(int *)(puVar4 + 2) == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d sub_cap_list is NULL\n","cw_priv_wtp_sub_capability_assemble",
             0xc2);
      return 0xffffffff;
    }
    for (; iVar5 < (int)(uint)*puVar4; iVar5 = iVar5 + 1) {
      iVar6 = iVar5 * 8;
      cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(puVar4 + 2) + iVar6));
      cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(puVar4 + 2) + iVar6 + 2));
      cw_protocol_restore_raw_bytes
                (param_1,((*(int *)(puVar4 + 2) + iVar6) -
                         (uint)*(ushort *)(*(int *)(puVar4 + 2) + iVar6 + 2)) + 8);
    }
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar3 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

