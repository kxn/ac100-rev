// func cw_protocol_restore32 @ 00571fa8 size=172

undefined4 cw_protocol_restore32(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10 [2];
  
  local_10[0] = param_2;
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) ||
     (param_1[2] - (uint)*(ushort *)(param_1 + 1) < 4)) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_restore32",0x14d);
    }
  }
  else {
    memcpy((void *)(*param_1 + (uint)*(ushort *)(param_1 + 1)),local_10,4);
    *(short *)(param_1 + 1) = *(short *)(param_1 + 1) + 4;
    uVar2 = 4;
  }
  return uVar2;
}

