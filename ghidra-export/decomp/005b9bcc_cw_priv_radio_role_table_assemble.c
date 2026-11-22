// func cw_priv_radio_role_table_assemble @ 005b9bcc size=264

undefined4 cw_priv_radio_role_table_assemble(int param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar5;
  int iVar4;
  undefined4 uVar6;
  char *pcVar7;
  
  uVar6 = 0xffffffff;
  if ((param_1 != 0) && (uVar5 = 0, param_2 != 0)) {
    pcVar7 = *(char **)(param_2 + 0x10);
    cVar1 = *pcVar7;
    uVar2 = *(ushort *)(param_1 + 4);
    if (cVar1 != '\0') {
      uVar5 = FUN_005b9884(pcVar7);
    }
    cw_protocol_restore8(param_1,cVar1);
    if (*pcVar7 == '\0') {
      uVar3 = *(ushort *)(param_1 + 4);
    }
    else {
      if (*(int *)(pcVar7 + 4) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d data is null\n","cw_priv_radio_role_table_assemble",0xfb);
        return 0xffffffff;
      }
      cw_protocol_restore_raw_bytes(param_1,*(int *)(pcVar7 + 4),uVar5);
      uVar3 = *(ushort *)(param_1 + 4);
    }
    uVar6 = 0xffffffff;
    if ((uint)uVar3 - (uint)uVar2 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar6 = 0;
    }
  }
  return uVar6;
}

