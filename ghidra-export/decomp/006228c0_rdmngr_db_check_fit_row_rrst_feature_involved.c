// func rdmngr_db_check_fit_row_rrst_feature_involved @ 006228c0 size=48

bool rdmngr_db_check_fit_row_rrst_feature_involved(char param_1,uint param_2)

{
  bool bVar1;
  
  if ((((param_2 & 1) == 0) || (bVar1 = true, param_1 != '\0')) &&
     (bVar1 = false, (param_2 & 2) != 0)) {
    bVar1 = param_1 == '\x01';
  }
  return bVar1;
}

