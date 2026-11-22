// func cw_protocol_retrieve64 @ 005718b0 size=288

undefined8 cw_protocol_retrieve64(int *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_18;
  uint local_14;
  
  local_14 = 0;
  local_18 = 0;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar1 = *(ushort *)((int)param_1 + 6);
    if (7 < (uint)*(ushort *)(param_1 + 1) - (uint)uVar1) {
      memcpy(&local_18,(void *)(*param_1 + (uint)uVar1),8);
      *(ushort *)((int)param_1 + 6) = uVar1 + 8;
      uVar3 = local_14 << 0x18 | local_14 >> 0x18 | (local_14 & 0xff0000) >> 8 |
              (local_14 & 0xff00) << 8;
      uVar4 = local_18 << 0x18 |
              local_18 >> 0x18 | (local_18 & 0xff0000) >> 8 | (local_18 & 0xff00) << 8;
      goto LAB_00571914;
    }
  }
  uVar4 = 0;
  uVar3 = 0;
  if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_retrieve64",0x88);
  }
LAB_00571914:
  return CONCAT44(uVar3,uVar4);
}

