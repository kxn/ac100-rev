// func _apdb_extend_cap_transfer_to_str @ 005fcca0 size=360

undefined4 _apdb_extend_cap_transfer_to_str(byte *param_1,int param_2,char *param_3,size_t param_4)

{
  bool bVar1;
  size_t sVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  
  if ((((param_3 == (char *)0x0) || ((int)param_4 < 1)) || (param_1 == (byte *)0x0)) ||
     ((param_2 < 1 || ((int)param_4 < param_2 * 2 + 1)))) {
    uVar3 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : Input error.\n","_apdb_extend_cap_transfer_to_str",0x138);
    }
  }
  else {
    iVar4 = 0;
    bVar1 = false;
    memset(param_3,0,param_4);
    do {
      if ((bVar1) || (*param_1 != 0)) {
        sVar2 = strlen(param_3);
        __format = "%02X";
        if (!bVar1) {
          __format = "%X";
        }
        snprintf(param_3 + sVar2,param_4 - sVar2,__format,(uint)*param_1);
        if (*param_1 != 0) {
          bVar1 = true;
        }
      }
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 != param_2);
    uVar3 = 0;
    if (!bVar1) {
      sVar2 = strlen(param_3);
      snprintf(param_3 + sVar2,param_4 - sVar2,"%X",0);
    }
  }
  return uVar3;
}

