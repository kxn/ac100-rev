// func _apdb_is_chnl_legal @ 005ffa00 size=132

undefined4 _apdb_is_chnl_legal(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_78 [27];
  
  memcpy(local_78,&DAT_00701bb0,100);
  uVar1 = 0;
  if ((param_1 - 1U < 0xa5) && (uVar1 = 1, 0xd < param_1)) {
    iVar2 = 0;
    do {
      piVar3 = (int *)((int)local_78 + iVar2);
      iVar2 = iVar2 + 4;
      if (*piVar3 == param_1) {
        return 1;
      }
    } while (iVar2 != 100);
    uVar1 = 0;
  }
  return uVar1;
}

