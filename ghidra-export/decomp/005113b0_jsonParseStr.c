// func jsonParseStr @ 005113b0 size=256

undefined4 jsonParseStr(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *__format;
  
  if (param_1 == 0) {
    if (tdcp_err_switch == 0) {
      return 0;
    }
    __format = "[TDCP_ERROR]%s()/%d Buf is NULL!\n\n";
    uVar2 = 0x11d;
  }
  else {
    iVar1 = json_tokener_new();
    if (iVar1 != 0) {
      uVar2 = json_tokener_parse_ex(iVar1,param_1,0xffffffff);
      if (*(int *)(iVar1 + 0x1c) == 0) {
        json_tokener_free(iVar1);
        return uVar2;
      }
      if (tdcp_err_switch != 0) {
        printf("[TDCP_ERROR]%s()/%d Parse buf failed,%s.\n\n","jsonParseStr",299,param_1);
      }
      json_tokener_free(iVar1);
      return 0;
    }
    if (tdcp_err_switch == 0) {
      return 0;
    }
    __format = "[TDCP_ERROR]%s()/%d Create tokener failed.\n\n";
    uVar2 = 0x124;
  }
  printf(__format,"jsonParseStr",uVar2);
  return 0;
}

