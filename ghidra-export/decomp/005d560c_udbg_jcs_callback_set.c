// func udbg_jcs_callback_set @ 005d560c size=248

void udbg_jcs_callback_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__src;
  char local_110 [256];
  undefined1 local_10;
  
  memset(local_110,0,0x101);
  iVar1 = json_object_object_get(param_1,&DAT_0068ee2c);
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "udbg_jcs_callback_set",0x840);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_110,__src,0x100);
  local_10 = 0;
  if (jcs_debug_switch != 0) {
    printf("[JCS_DBG]%s()/%d cmd=%s\n","udbg_jcs_callback_set",0x841,local_110);
  }
  if (local_110[0] != '\0') {
    udbg_execute(local_110);
  }
  return;
}

