// func cw_protocol_retrieve32 @ 005717fc size=180

undefined4 cw_protocol_retrieve32(int *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 local_18 [3];
  
  local_18[0] = 0;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar1 = *(ushort *)((int)param_1 + 6);
    if (3 < (uint)*(ushort *)(param_1 + 1) - (uint)uVar1) {
      memcpy(local_18,(void *)(*param_1 + (uint)uVar1),4);
      *(ushort *)((int)param_1 + 6) = uVar1 + 4;
      return local_18[0];
    }
  }
  if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_retrieve32",0x71);
  }
  return 0;
}

