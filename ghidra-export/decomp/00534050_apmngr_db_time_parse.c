// func apmngr_db_time_parse @ 00534050 size=176

undefined4 apmngr_db_time_parse(char *param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 != (char *)0x0) && (param_2 != 0)) &&
     (iVar1 = sscanf(param_1,"%hhu:%hhu:%hhu",param_2,param_2 + 1,param_2 + 2), iVar1 == 3)) {
    return 0;
  }
  if (apmngr_err_switch != '\0') {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    if (param_1 == (char *)0x0) {
      param_1 = "null";
    }
    printf("[APMNGR_ERROR]%s()/%d Illegal time:%s\n","apmngr_db_time_parse",0xc3,param_1);
  }
  return 0xffffffff;
}

