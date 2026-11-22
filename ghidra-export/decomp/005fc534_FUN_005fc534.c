// func FUN_005fc534 @ 005fc534 size=140

int FUN_005fc534(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  iVar1 = _apdb_read_file(&local_c,&local_10,"/etc/nouci_config/dbs/apdb_nego.db");
  iVar2 = local_c;
  if (iVar1 != 0) {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : read file %s error.\n","_apdb_get_json_data_without_des",
             0x1fb,"/etc/nouci_config/dbs/apdb_nego.db");
    }
    iVar2 = 0;
    if (local_c != 0) {
      FUN_00407df0();
    }
  }
  return iVar2;
}

