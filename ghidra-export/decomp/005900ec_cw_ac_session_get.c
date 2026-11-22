// func cw_ac_session_get @ 005900ec size=116

undefined4 cw_ac_session_get(int param_1,int param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (param_1 == 0) {
    uVar1 = 0x182;
    pcVar2 = "this";
  }
  else {
    if (param_2 != 0) {
      uVar1 = FUN_00407fa0(*(undefined4 *)(param_1 + 0x58));
      return uVar1;
    }
    uVar1 = 0x183;
    pcVar2 = "ip_port";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_session_get",uVar1,pcVar2);
  return 0;
}

