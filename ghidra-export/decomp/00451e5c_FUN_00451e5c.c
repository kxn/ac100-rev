// func FUN_00451e5c @ 00451e5c size=380

int FUN_00451e5c(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int local_a0;
  char acStack_9c [132];
  
  local_a0 = 0;
  memset(acStack_9c,0,0x80);
  iVar1 = FUN_00408130("/etc/nouci_config/dbs/mac_auth.db",&local_a0,0);
  if (iVar1 == 0) {
    iVar1 = FUN_00407d60(local_a0,param_2);
    if (iVar1 == 0) {
      snprintf(acStack_9c,0x80,"CREATE INDEX %s_%s ON %s(%s)",param_1,"id",param_1,"id");
      FUN_00408530(local_a0,acStack_9c);
      if (param_3 != 0) {
        snprintf(acStack_9c,0x80,"CREATE INDEX %s_%s ON %s(%s)",param_1,param_3,param_1,param_3);
        FUN_00408530(local_a0,acStack_9c);
      }
      if (param_4 != 0) {
        snprintf(acStack_9c,0x80,"CREATE INDEX %s_%s ON %s(%s)",param_1,param_4,param_1,param_4);
        FUN_00408530(local_a0,acStack_9c);
      }
    }
    else {
      iVar2 = FUN_00408410();
      if (iVar2 != 0) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"create table %s failed.\"\n",
               "mac_auth_sqlite_create_table",0x1eb,iVar1,param_2,param_1);
      }
    }
  }
  if (local_a0 != 0) {
    FUN_004080b0();
  }
  return iVar1;
}

