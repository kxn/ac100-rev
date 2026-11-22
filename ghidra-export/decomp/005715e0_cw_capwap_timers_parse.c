// func cw_capwap_timers_parse @ 005715e0 size=216

undefined4 cw_capwap_timers_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 uVar5;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  puVar2 = (undefined1 *)FUN_00408450(2,0x65);
  if (puVar2 == (undefined1 *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_capwap_timers_parse",0x68);
    }
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    uVar5 = cw_protocol_retrieve8(param_1);
    *puVar2 = uVar5;
    uVar5 = cw_protocol_retrieve8(param_1);
    puVar2[1] = uVar5;
    *(undefined1 **)(param_2 + 0x10) = puVar2;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

