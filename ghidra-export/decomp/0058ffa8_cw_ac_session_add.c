// func cw_ac_session_add @ 0058ffa8 size=160

undefined4 cw_ac_session_add(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    uVar2 = 0x14d;
    pcVar3 = "this";
  }
  else {
    if (param_2 != 0) {
      FUN_004086b0(param_1 + 0x4c);
      iVar1 = FUN_00408380(*(undefined4 *)(param_1 + 0x58),param_2);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      return 0;
    }
    uVar2 = 0x14e;
    pcVar3 = "session";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_session_add",uVar2,pcVar3);
  return 0xffffffff;
}

