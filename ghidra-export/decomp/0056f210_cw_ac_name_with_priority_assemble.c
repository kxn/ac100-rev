// func cw_ac_name_with_priority_assemble @ 0056f210 size=216

undefined4 cw_ac_name_with_priority_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  puVar3 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*(int *)(puVar3 + 4) == 0) ||
     (*(ushort *)(puVar3 + 2) + 1 != (uint)*(ushort *)(param_2 + 0xe))) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to write ac name\n","cw_ac_name_with_priority_assemble",
             0x8f);
    }
  }
  else {
    cw_protocol_restore8(param_1,*puVar3);
    cw_protocol_restore_raw_bytes(param_1,*(undefined4 *)(puVar3 + 4),*(undefined2 *)(puVar3 + 2));
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

