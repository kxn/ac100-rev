// func _wserv_sqlite_db_str_tran @ 005f65c0 size=92

void _wserv_sqlite_db_str_tran(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  
  for (pcVar1 = param_2; (*param_1 != '\0' && ((int)pcVar1 - (int)param_2 < param_3 + -1));
      pcVar1 = pcVar1 + 1) {
    if (*param_1 == '\'') {
      *pcVar1 = '\'';
      pcVar1 = pcVar1 + 1;
      cVar2 = *param_1;
    }
    else {
      cVar2 = *param_1;
    }
    param_1 = param_1 + 1;
    *pcVar1 = cVar2;
  }
  *pcVar1 = '\0';
  return;
}

