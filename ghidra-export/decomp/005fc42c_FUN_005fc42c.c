// func FUN_005fc42c @ 005fc42c size=264

void * FUN_005fc42c(void)

{
  int iVar1;
  undefined4 local_18;
  void *local_14;
  int local_10 [2];
  
  local_10[0] = 0;
  local_14 = (void *)0x0;
  local_18 = 0;
  iVar1 = _apdb_read_file(local_10,&local_18,"/etc/apdb.bin");
  if (iVar1 == 0) {
    iVar1 = accrypt_des_decrypt(local_10[0],local_18,&local_14);
    if (iVar1 != -1) {
      if (local_10[0] == 0) {
        return local_14;
      }
      FUN_00407df0();
      return local_14;
    }
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : des decode failed.\n","_apdb_get_json_data",0x1c6);
    }
  }
  else if (apdb_err_switch != 0) {
    printf("[APDB_ERROR]%s()/line %d : read file %s error.\n","_apdb_get_json_data",0x1bc,
           "/etc/apdb.bin");
  }
  if (local_10[0] != 0) {
    FUN_00407df0();
    local_10[0] = 0;
    local_18 = 0;
  }
  if (local_14 != (void *)0x0) {
    free(local_14);
  }
  return (void *)0x0;
}

