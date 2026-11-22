// func apdb_hwver_exist_by_id_array @ 0060b038 size=1

undefined4 apdb_hwver_exist_by_id_array(int param_1,int param_2,int param_3,short *param_4)

{
  int iVar1;
  short *psVar2;
  char *__format;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if ((param_1 == 0) || (param_2 < 1)) {
    if (apdb_err_switch == 0) {
      return 0;
    }
    __format = "[APDB_ERROR]%s()/line %d : Input error.\n";
    uVar4 = 0x2a48;
  }
  else {
    if (param_4 != (short *)0x0) {
      param_2 = param_2 + -1;
      iVar5 = 0;
      do {
        iVar1 = (iVar5 + param_2) / 2;
        iVar3 = param_1 + iVar1 * 0x168;
        if (param_3 == *(int *)(iVar3 + 0x10)) {
          if (iVar1 != -1) {
            iVar5 = 0;
            do {
              while( true ) {
                if (*(int *)(iVar3 + 0x160) <= iVar5) {
                  return 0;
                }
                psVar2 = (short *)(*(int *)(iVar3 + 0x164) + iVar5 * 0x38);
                if (*param_4 == *psVar2) break;
                iVar5 = iVar5 + 1;
              }
              iVar5 = iVar5 + 1;
            } while (param_4[1] != psVar2[1]);
            return 1;
          }
          break;
        }
        if (param_3 < *(int *)(iVar3 + 0x10)) {
          param_2 = iVar1 + -1;
        }
        else {
          iVar5 = iVar1 + 1;
        }
      } while (iVar5 <= param_2);
      if (apdb_warning_switch == 0) {
        return 0;
      }
      printf("[APDB_WARNING]%s()/line %d :  Failed to search ap[0x%x].\n",
             "apdb_hwver_exist_by_id_array",0x2a55,param_3);
      return 0;
    }
    if (apdb_warning_switch == 0) {
      return 0;
    }
    __format = "[APDB_WARNING]%s()/line %d : Input error.\n";
    uVar4 = 0x2a4e;
  }
  printf(__format,"apdb_hwver_exist_by_id_array",uVar4);
  return 0;
}

