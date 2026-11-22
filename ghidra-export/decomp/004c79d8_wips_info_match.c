// func wips_info_match @ 004c79d8 size=228

bool wips_info_match(int param_1,int param_2,void *param_3,void *param_4,int param_5)

{
  bool bVar2;
  int iVar1;
  uint uVar3;
  void *__s1;
  
  uVar3 = 0;
  if (param_2 + 0xfecea807U < 0xd) {
    uVar3 = (uint)*(byte *)(param_2 + -0xc6d429);
  }
  bVar2 = false;
  if (*(uint *)(param_1 + 0x98) != uVar3) {
    return false;
  }
  switch(param_2) {
  case 0x13157f9:
    iVar1 = memcmp((void *)(param_1 + 0x10),param_4,0x32);
    bVar2 = false;
    if (iVar1 == 0) {
      bVar2 = *(int *)(param_1 + 0x44) == param_5;
    }
    break;
  case 0x13157fa:
  case 0x13157fb:
  case 0x13157fc:
  case 0x13157fd:
  case 0x13157fe:
    __s1 = (void *)(param_1 + 0x4e);
    goto LAB_004c7a74;
  case 0x13157ff:
  case 0x1315800:
  case 0x1315801:
    bVar2 = true;
    break;
  case 0x1315802:
  case 0x1315803:
  case 0x1315804:
  case 0x1315805:
    __s1 = (void *)(param_1 + 0x48);
LAB_004c7a74:
    iVar1 = memcmp(__s1,param_3,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

