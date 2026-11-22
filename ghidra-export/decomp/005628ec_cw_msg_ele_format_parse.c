// func cw_msg_ele_format_parse @ 005628ec size=136

undefined4 cw_msg_ele_format_parse(int *param_1,undefined2 *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  undefined2 uVar2;
  
  uVar1 = 0xffffffff;
  if ((((param_1 != (int *)0x0) && (*param_1 != 0)) &&
      ((uint)*(ushort *)((int)param_1 + 6) <= (uint)*(ushort *)(param_1 + 1))) &&
     (3 < (int)((uint)*(ushort *)(param_1 + 1) - (uint)*(ushort *)((int)param_1 + 6)))) {
    uVar2 = cw_protocol_retrieve16();
    *param_2 = uVar2;
    uVar2 = cw_protocol_retrieve16(param_1);
    *param_3 = uVar2;
    uVar1 = 0;
  }
  return uVar1;
}

