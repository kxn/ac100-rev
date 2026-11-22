// func apdb_is_support_rrst @ 0060d7d0 size=232

undefined4 apdb_is_support_rrst(undefined4 param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int local_18 [3];
  
  local_18[0] = 0;
  if (param_2 == 0) {
    if (apdb_err_switch == 0) {
      return 0;
    }
    __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
    uVar2 = 0x2fbe;
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,local_18);
    if (iVar1 == 0) {
      if (*(int *)(local_18[0] + 4) == 0) {
        return 0;
      }
      if (*(int *)(local_18[0] + 0x34) == 0) {
        return 0;
      }
      if (apdb_debug_switch == 0) {
        return 1;
      }
      printf("[APDB_DEBUG]%s()/line %d : model_id=%d has rrst, not return mutex_channel\n",
             "apdb_is_support_rrst",0x2fcb,param_1);
      return 1;
    }
    if (apdb_warning_switch == 0) {
      return 0;
    }
    __format = "[APDB_WARNING]%s()/line %d : get model failed\n";
    uVar2 = 0x2fc4;
  }
  printf(__format,"apdb_is_support_rrst",uVar2);
  return 0;
}

