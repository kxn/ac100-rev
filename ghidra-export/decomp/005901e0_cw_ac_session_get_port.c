// func cw_ac_session_get_port @ 005901e0 size=116

undefined4 cw_ac_session_get_port(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (param_1 == 0) {
    uVar1 = 0x1a7;
    pcVar2 = "this";
  }
  else {
    if (param_2 != (undefined2 *)0x0) {
      *param_2 = *(undefined2 *)(param_1 + 0x40);
      return 0;
    }
    uVar1 = 0x1a8;
    pcVar2 = "port";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_session_get_port",uVar1,pcVar2);
  return 0xffffffff;
}

