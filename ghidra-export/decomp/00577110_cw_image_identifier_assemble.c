// func cw_image_identifier_assemble @ 00577110 size=216

undefined4 cw_image_identifier_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,*puVar4);
  if (((puVar4[2] == 0) || (*(ushort *)(puVar4 + 1) == 0)) ||
     ((uint)*(ushort *)(puVar4 + 1) != *(ushort *)(param_2 + 0xe) - 4)) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to write data\n","cw_image_identifier_assemble",0x95);
    }
  }
  else {
    cw_protocol_restore_raw_bytes(param_1);
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

