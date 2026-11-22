// func cw_priv_lag_config_assemble @ 005b4540 size=248

undefined4 cw_priv_lag_config_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != 0)) {
    puVar4 = *(undefined1 **)(param_2 + 0x10);
    uVar1 = *(ushort *)(param_1 + 4);
    cw_protocol_restore8(param_1,*puVar4);
    cw_protocol_restore8(param_1,puVar4[1]);
    cw_protocol_restore8(param_1,puVar4[2]);
    if (puVar4[2] == '\0') {
      uVar2 = *(ushort *)(param_1 + 4);
    }
    else {
      if (*(int *)(puVar4 + 4) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d data is null\n","cw_priv_lag_config_assemble",0xab);
        return 0xffffffff;
      }
      cw_protocol_restore_raw_bytes(param_1);
      uVar2 = *(ushort *)(param_1 + 4);
    }
    uVar5 = 0xffffffff;
    if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar5 = 0;
    }
  }
  return uVar5;
}

