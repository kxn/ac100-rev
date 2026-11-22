// func cw_priv_region_list_assemble @ 005badb8 size=252

undefined4 cw_priv_region_list_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar4;
  int iVar3;
  char *pcVar5;
  undefined4 uVar6;
  
  uVar6 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != 0)) {
    pcVar5 = *(char **)(param_2 + 0x10);
    uVar1 = *(ushort *)(param_1 + 4);
    uVar4 = _calculate_region_list_length(pcVar5);
    cw_protocol_restore8(param_1,*pcVar5);
    if (*pcVar5 == '\0') {
      uVar2 = *(ushort *)(param_1 + 4);
    }
    else {
      if (*(int *)(pcVar5 + 4) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d data is null\n","cw_priv_region_list_assemble",0xe6);
        return 0xffffffff;
      }
      cw_protocol_restore_raw_bytes(param_1,*(int *)(pcVar5 + 4),uVar4);
      uVar2 = *(ushort *)(param_1 + 4);
    }
    uVar6 = 0xffffffff;
    if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar6 = 0;
    }
  }
  return uVar6;
}

