// func cw_msg_ele_add_with_length @ 00562d14 size=1

undefined4 cw_msg_ele_add_with_length(int param_1,ushort param_2,short param_3,int param_4)

{
  undefined4 uVar1;
  void *__s;
  
  uVar1 = 0xffffffff;
  if (((param_1 != 0) && (param_4 != 0)) && ((param_2 - 1 < 0x36 || (param_2 - 0x400 < 0x19)))) {
    __s = (void *)FUN_00408450(0x18,0x1a2);
    uVar1 = 0xffffffff;
    if (__s != (void *)0x0) {
      memset(__s,0,0x18);
      *(short *)((int)__s + 0xe) = param_3;
      *(ushort *)((int)__s + 0xc) = param_2;
      *(int *)((int)__s + 0x10) = param_4;
      FUN_004086b0(param_1 + 0x1c,__s);
      uVar1 = 0;
      *(short *)(param_1 + 0x16) = param_3 + *(short *)(param_1 + 0x16) + 4;
    }
  }
  return uVar1;
}

