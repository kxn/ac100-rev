// func cw_ac_session_remove @ 00590048 size=164

undefined4 cw_ac_session_remove(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    uVar2 = 0x166;
    pcVar3 = "this";
  }
  else {
    if (param_2 != 0) {
      FUN_00408500(param_2);
      iVar1 = FUN_00407f40(*(undefined4 *)(param_1 + 0x58),param_2);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      return 0;
    }
    uVar2 = 0x167;
    pcVar3 = "session";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_session_remove",uVar2,pcVar3);
  return 0xffffffff;
}

