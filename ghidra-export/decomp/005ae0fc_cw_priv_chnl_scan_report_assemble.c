// func cw_priv_chnl_scan_report_assemble @ 005ae0fc size=404

undefined4 cw_priv_chnl_scan_report_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  pbVar3 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*pbVar3 == 0) || (*(int *)(pbVar3 + 4) != 0)) {
    cw_protocol_restore8(param_1);
    for (iVar5 = 0; iVar4 = iVar5 * 9, iVar5 < (int)(uint)*pbVar3; iVar5 = iVar5 + 1) {
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar3 + 4) + iVar4));
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar3 + 4) + iVar4 + 1));
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar3 + 4) + iVar4 + 2));
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar3 + 4) + iVar4 + 3));
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar3 + 4) + iVar4 + 4));
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar3 + 4) + iVar4 + 5));
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar3 + 4) + iVar4 + 6));
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar3 + 4) + iVar4 + 7));
    }
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d chnl list is null\n","cw_priv_chnl_scan_report_assemble",0xb6);
    }
  }
  return uVar2;
}

