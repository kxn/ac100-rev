// func cw_protocol_retrieve16 @ 00571750 size=172

undefined2 cw_protocol_retrieve16(int *param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar1 = *(ushort *)((int)param_1 + 6);
    if (1 < (uint)*(ushort *)(param_1 + 1) - (uint)uVar1) {
      uVar2 = *(undefined2 *)(*param_1 + (uint)uVar1);
      *(ushort *)((int)param_1 + 6) = uVar1 + 2;
      return uVar2;
    }
  }
  if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_retrieve16",0x5a);
  }
  return 0;
}

