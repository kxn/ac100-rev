// func FUN_004521a4 @ 004521a4 size=164

undefined4 FUN_004521a4(void)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_410 [1028];
  
  uVar2 = 0;
  memset(acStack_410,0,0x400);
  snprintf(acStack_410,0x400,
           "CREATE TABLE IF NOT EXISTS %s(id              INTEGER,name    VARCHAR(128),vlan            TEXT,serv_id_map\t\tTEXT,mac_id_map      TEXT,note            VARCHAR(128),type            VARCHAR(20),enable          VARCHAR(10),key\t\t\t\tINTEGER PRIMARY KEY AUTOINCREMENT)"
           ,"macAuthGroupTable");
  iVar1 = FUN_00451e5c("macAuthGroupTable",acStack_410,0,0);
  if ((iVar1 != 0) && (uVar2 = 0xffffffff, macauth_err_switch != 0)) {
    printf("[MACAUTH_ERROR]%s()/%d Create table %s failed.\n","mac_auth_sqlite_create_group_table",
           0x357,"macAuthGroupTable");
  }
  return uVar2;
}

