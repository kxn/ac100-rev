// func FUN_006505b0 @ 006505b0 size=192

char * FUN_006505b0(int param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_2e8 [78];
  char acStack_29a [654];
  
  memset(auStack_2e8,0,0x2d8);
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    param_2 = (char *)0x0;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: Input error\r\n","apupd_ap_name_get",0xe3);
    }
  }
  else {
    iVar1 = apmngr_db_entry_get_by_mac(param_1,auStack_2e8);
    pcVar2 = acStack_29a;
    if (iVar1 != 0) {
      pcVar2 = "---";
    }
    snprintf(param_2,0x9a,"%s",pcVar2);
  }
  return param_2;
}

