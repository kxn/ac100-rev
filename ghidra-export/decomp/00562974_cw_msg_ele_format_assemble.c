// func cw_msg_ele_format_assemble @ 00562974 size=140

undefined4 cw_msg_ele_format_assemble(int *param_1,uint param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((((param_1 != (int *)0x0) && (*param_1 != 0)) &&
      (3 < (int)(param_1[2] - (uint)*(ushort *)(param_1 + 1)))) &&
     (((param_2 & 0xffff) - 1 < 0x36 || ((param_2 & 0xffff) - 0x400 < 0x19)))) {
    cw_protocol_restore16(param_1);
    cw_protocol_restore16(param_1,param_3);
    uVar1 = 0;
  }
  return uVar1;
}

