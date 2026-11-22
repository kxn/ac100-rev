// func FUN_0063240c @ 0063240c size=92

char * FUN_0063240c(undefined2 param_1,char *param_2)

{
  int iVar1;
  undefined1 auStack_2e0 [78];
  undefined1 auStack_292 [650];
  
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e0);
  if (iVar1 == 0) {
    snprintf(param_2,0x100,"%s",auStack_292);
  }
  else {
    param_2 = "---";
  }
  return param_2;
}

