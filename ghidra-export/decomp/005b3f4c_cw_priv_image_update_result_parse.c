// func cw_priv_image_update_result_parse @ 005b3f4c size=212

undefined4 cw_priv_image_update_result_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  puVar2 = (undefined4 *)FUN_00408450(4,0x6f);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_image_update_result_parse",0x72);
    }
  }
  else {
    *(undefined1 *)puVar2 = 0;
    *(undefined1 *)((int)puVar2 + 1) = 0;
    *(undefined1 *)((int)puVar2 + 2) = 0;
    *(undefined1 *)((int)puVar2 + 3) = 0;
    uVar3 = cw_protocol_retrieve32(param_1);
    *puVar2 = uVar3;
    *(undefined4 **)(param_2 + 0x10) = puVar2;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

