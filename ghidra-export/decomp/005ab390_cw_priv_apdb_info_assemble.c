// func cw_priv_apdb_info_assemble @ 005ab390 size=180

undefined4 cw_priv_apdb_info_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if (**(short **)(param_2 + 0x10) != 0) {
    if (*(int *)(*(short **)(param_2 + 0x10) + 2) == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d data is null\n","cw_priv_apdb_info_assemble",0xc6);
      return 0xffffffff;
    }
    cw_protocol_restore_raw_bytes();
  }
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

