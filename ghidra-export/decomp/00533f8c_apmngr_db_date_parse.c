// func apmngr_db_date_parse @ 00533f8c size=196

int apmngr_db_date_parse(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 8;
  if (param_1 != (char *)0x0) {
    iVar3 = 8;
    iVar2 = 0;
    do {
      iVar1 = strcmp(param_1,(&g_apmngr_date_str)[iVar2]);
      iVar3 = iVar3 + -1;
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar3 != 0);
    if (((iVar2 == 8) && (apmngr_err_switch != '\0')) && (iVar3 = is_target_debug_ap(), iVar3 != 0))
    {
      printf("[APMNGR_ERROR]%s()/%d Illegal date:%s\n","apmngr_db_date_parse",0xbb,param_1);
    }
  }
  return iVar2;
}

