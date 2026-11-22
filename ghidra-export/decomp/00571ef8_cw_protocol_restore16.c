// func cw_protocol_restore16 @ 00571ef8 size=176

undefined4 cw_protocol_restore16(int *param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_10;
  undefined1 uStack_f;
  
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) ||
     (param_1[2] - (uint)*(ushort *)(param_1 + 1) < 2)) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_restore16",0x134);
    }
  }
  else {
    puVar1 = (undefined1 *)(*param_1 + (uint)*(ushort *)(param_1 + 1));
    local_10 = (undefined1)((ushort)param_2 >> 8);
    uVar3 = 2;
    *puVar1 = local_10;
    uStack_f = (undefined1)param_2;
    puVar1[1] = uStack_f;
    *(short *)(param_1 + 1) = *(short *)(param_1 + 1) + 2;
  }
  return uVar3;
}

