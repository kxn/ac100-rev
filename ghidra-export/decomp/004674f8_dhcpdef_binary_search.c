// func dhcpdef_binary_search @ 004674f8 size=256

int dhcpdef_binary_search(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  param_2 = param_2 + -1;
  iVar3 = 0;
  do {
    if (param_2 < iVar3) {
      return -1;
    }
    iVar2 = iVar3 + (param_2 - iVar3 >> 1);
    iVar4 = *(int *)(param_1 + iVar2 * 4);
    uVar5 = __floatsidf(param_3 - iVar4);
    iVar1 = __ltdf2((int)((ulonglong)uVar5 >> 0x20),(int)uVar5,0x3eb0c6f7,0xa0b5ed8d);
    if (iVar1 < 0) {
      uVar5 = __floatsidf(iVar4 - param_3);
      iVar1 = __ltdf2((int)((ulonglong)uVar5 >> 0x20),(int)uVar5,0x3eb0c6f7,0xa0b5ed8d);
      if (iVar1 < 0) {
        return iVar2;
      }
    }
    if (param_3 < iVar4) {
      param_2 = iVar2 + -1;
    }
    else {
      iVar3 = iVar2 + 1;
    }
  } while( true );
}

