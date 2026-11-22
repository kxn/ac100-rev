// func cw_wtp_name_assemble @ 0058601c size=188

undefined4 cw_wtp_name_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*(int *)(*(short **)(param_2 + 0x10) + 2) == 0) ||
     (*(short *)(param_2 + 0xe) != **(short **)(param_2 + 0x10))) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to write wtp name\n","cw_wtp_name_assemble",0x97);
    }
  }
  else {
    cw_protocol_restore_raw_bytes();
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

