// func cw_protocol_retrieve8 @ 005716c0 size=144

undefined1 cw_protocol_retrieve8(int *param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar2 = *(ushort *)((int)param_1 + 6);
    if ((uint)*(ushort *)(param_1 + 1) != (uint)uVar2) {
      uVar1 = *(undefined1 *)(*param_1 + (uint)uVar2);
      *(ushort *)((int)param_1 + 6) = uVar2 + 1;
      return uVar1;
    }
  }
  if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_retrieve8",0x43);
  }
  return 0;
}

