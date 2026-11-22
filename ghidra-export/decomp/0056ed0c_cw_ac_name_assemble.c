// func cw_ac_name_assemble @ 0056ed0c size=188

undefined4 cw_ac_name_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*(int *)(*(short **)(param_2 + 0x10) + 2) == 0) ||
     (*(short *)(param_2 + 0xe) != **(short **)(param_2 + 0x10))) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to write ac name\n","cw_ac_name_assemble",0x8d);
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

