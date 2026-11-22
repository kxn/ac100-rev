// func cw_priv_ch_state_parse @ 005ad3f0 size=260

undefined4 cw_priv_ch_state_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 uVar6;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  puVar2 = (undefined1 *)FUN_00408450(2,0x6e);
  if (puVar2 == (undefined1 *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ch_state_parse",0x71);
    }
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    uVar3 = cw_protocol_retrieve8(param_1);
    *puVar2 = (char)uVar3;
    if (uVar3 < 0x20) {
      uVar6 = cw_protocol_retrieve8(param_1);
      puVar2[1] = uVar6;
      *(undefined1 **)(param_2 + 0x10) = puVar2;
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 0xffffffff;
      printf("radio id(%d) is wrong",uVar3);
      FUN_00407df0(puVar2);
    }
  }
  return uVar4;
}

