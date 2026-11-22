// func cw_msg_ele_priv_add_with_length @ 00582fa4 size=1

undefined4
cw_msg_ele_priv_add_with_length(int param_1,ushort param_2,undefined2 param_3,int param_4)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((((param_1 != 0) && (param_4 != 0)) &&
      (iVar1 = cw_msg_ele_priv_size(), (int)(uint)param_2 <= iVar1 + -1)) &&
     (__s = (void *)FUN_00408450(0x18,0x301), __s != (void *)0x0)) {
    memset(__s,0,0x18);
    *(ushort *)((int)__s + 0xc) = param_2;
    *(undefined2 *)((int)__s + 0xe) = param_3;
    uVar2 = 0;
    *(int *)((int)__s + 0x10) = param_4;
    FUN_004086b0(param_1 + 8,__s);
    *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + *(short *)((int)__s + 0xe) + 4;
  }
  return uVar2;
}

