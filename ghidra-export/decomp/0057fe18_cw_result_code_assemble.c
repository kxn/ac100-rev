// func cw_result_code_assemble @ 0057fe18 size=188

undefined4 cw_result_code_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  
  puVar4 = *(uint **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*puVar4 < 0x19) {
    cw_protocol_restore32();
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d result code(%d) is wrong\n","cw_result_code_assemble",0xb3,
             *puVar4);
    }
  }
  return uVar3;
}

