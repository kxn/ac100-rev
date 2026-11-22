// func cw_priv_mac_filter_assemble @ 005b58c0 size=252

undefined4 cw_priv_mac_filter_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,*piVar5);
  cw_protocol_restore8(param_1,*(undefined1 *)(piVar5 + 1));
  cw_protocol_restore8(param_1,*(undefined1 *)((int)piVar5 + 5));
  cw_protocol_restore16(param_1,*(undefined2 *)((int)piVar5 + 6));
  if (*piVar5 == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    if (piVar5[2] == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d data is null\n","cw_priv_mac_filter_assemble",0xad);
      return 0xffffffff;
    }
    cw_protocol_restore_raw_bytes
              (param_1,piVar5[2],(uint)(*(byte *)(piVar5 + 1) >> 3) * *piVar5 & 0xffff);
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar3 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

