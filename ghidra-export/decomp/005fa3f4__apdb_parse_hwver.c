// func _apdb_parse_hwver @ 005fa3f4 size=252

undefined4 _apdb_parse_hwver(char *param_1,undefined2 *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char *local_18 [3];
  
  local_18[0] = (char *)0x0;
  if (param_1 == (char *)0x0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar1 = "[APDB_ERROR]%s()/line %d : input tmp_hwver null.\n";
    uVar3 = 0x52d;
  }
  else {
    pcVar1 = strtok_r(param_1,".",local_18);
    if (pcVar1 == (char *)0x0) {
      if (apdb_err_switch == 0) {
        return 0xffffffff;
      }
      pcVar1 = "[APDB_ERROR]%s()/line %d : parse hardware version failed.\n";
      uVar3 = 0x534;
    }
    else {
      iVar2 = atoi(pcVar1);
      *param_2 = (short)iVar2;
      pcVar1 = strtok_r((char *)0x0,".",local_18);
      if (pcVar1 != (char *)0x0) {
        iVar2 = atoi(pcVar1);
        param_2[1] = (short)iVar2;
        return 0;
      }
      if (apdb_err_switch == 0) {
        return 0xffffffff;
      }
      pcVar1 = "[APDB_ERROR]%s()/line %d : parse hardware version failed.\n";
      uVar3 = 0x53c;
    }
  }
  printf(pcVar1,"_apdb_parse_hwver",uVar3);
  return 0xffffffff;
}

