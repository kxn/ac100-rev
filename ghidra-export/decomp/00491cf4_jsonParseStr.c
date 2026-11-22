// func jsonParseStr @ 00491cf4 size=256

undefined4 jsonParseStr(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *__format;
  
  if (param_1 == 0) {
    if (cloud_mngt_err_switch == '\0') {
      return 0;
    }
    __format = "[CLOUD_MNGT_ERROR]%s()/%d Buf is NULL!\n\n";
    uVar2 = 0x1b29;
  }
  else {
    iVar1 = json_tokener_new();
    if (iVar1 != 0) {
      uVar2 = json_tokener_parse_ex(iVar1,param_1,0xffffffff);
      if (*(int *)(iVar1 + 0x1c) == 0) {
        json_tokener_free(iVar1);
        return uVar2;
      }
      if (cloud_mngt_err_switch != '\0') {
        printf("[CLOUD_MNGT_ERROR]%s()/%d Parse buf failed,%s.\n\n","jsonParseStr",0x1b37,param_1);
      }
      json_tokener_free(iVar1);
      return 0;
    }
    if (cloud_mngt_err_switch == '\0') {
      return 0;
    }
    __format = "[CLOUD_MNGT_ERROR]%s()/%d Create tokener failed.\n\n";
    uVar2 = 0x1b30;
  }
  printf(__format,"jsonParseStr",uVar2);
  return 0;
}

