// func uac_msgQ_init @ 0051e580 size=152

undefined4 uac_msgQ_init(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_t9;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 auStack_18 [12];
  
  iVar3 = *(int *)(in_t9 + 0x23aee8);
  uVar2 = 0;
  if (*(int *)(iVar3 + 0x3b50) == 0) {
    uVar2 = 0xffffffff;
    iVar1 = (**(code **)(in_t9 + 0x23b058))(0xc,auStack_18);
    if (iVar1 == 0) {
      local_1c = 0x7fffffff;
      local_20 = 0x7fffffff;
      iVar1 = (**(code **)(in_t9 + 0x23b1dc))(0xc,&local_20);
      if (iVar1 == 0) {
        uVar2 = 0;
        *(undefined4 *)(iVar3 + 0x3b50) = 1;
      }
    }
  }
  return uVar2;
}

