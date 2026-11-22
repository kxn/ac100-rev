// func apdb_print_json @ 0060c3cc size=320

void apdb_print_json(void)

{
  int iVar1;
  char *__s;
  
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  iVar1 = FUN_005fc42c();
  if (iVar1 == 0) {
    FUN_00407f30(l_apdb_mutex);
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : Failed to load json data\n","apdb_print_json",0x2c80);
      return;
    }
    return;
  }
  FUN_00407f30(l_apdb_mutex);
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  __s = (char *)FUN_005fc534();
  if (__s != (char *)0x0) {
    FUN_00407f30(l_apdb_mutex);
    puts("**********************This is json ap_db data for negotiation****************************"
        );
    puts(__s);
    puts("*************************************************************************");
    FUN_00407df0(__s);
    return;
  }
  if (apdb_err_switch != 0) {
    printf("[APDB_ERROR]%s()/line %d : Failed to load json data\n","apdb_print_json",0x2c8b);
  }
  FUN_00407f30(l_apdb_mutex);
  return;
}

