// func cw_protocol_restore64 @ 00572054 size=260

undefined4 cw_protocol_restore64(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint local_10;
  uint local_c;
  
  local_c = param_3 << 0x18 | param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8;
  local_10 = param_4 << 0x18 | param_4 >> 0x18 | (param_4 & 0xff0000) >> 8 | (param_4 & 0xff00) << 8
  ;
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) ||
     (param_1[2] - (uint)*(ushort *)(param_1 + 1) < 8)) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_restore64",0x166);
    }
  }
  else {
    memcpy((void *)(*param_1 + (uint)*(ushort *)(param_1 + 1)),&local_10,8);
    *(short *)(param_1 + 1) = *(short *)(param_1 + 1) + 8;
    uVar2 = 8;
  }
  return uVar2;
}

