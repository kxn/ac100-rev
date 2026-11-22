// func cw_protocol_restore8 @ 00571e64 size=148

undefined4 cw_protocol_restore8(int *param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (int *)0x0) || (param_1[2] == (uint)*(ushort *)(param_1 + 1))) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_restore8",0x11b);
    }
  }
  else {
    uVar2 = 1;
    *(undefined1 *)(*param_1 + (uint)*(ushort *)(param_1 + 1)) = param_2;
    *(short *)(param_1 + 1) = *(short *)(param_1 + 1) + 1;
  }
  return uVar2;
}

