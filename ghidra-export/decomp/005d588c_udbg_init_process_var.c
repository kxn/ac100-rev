// func udbg_init_process_var @ 005d588c size=720

undefined4 udbg_init_process_var(void)

{
  __pid_t _Var1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  _Var1 = getpid();
  iVar2 = FUN_00407e40(_Var1,&pname);
  if (iVar2 < 0) {
    if (udbg_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[UDBG_ERR]%s()/%d Get process name failed.\n","udbg_init_process_var",0x8d5);
    return 0xffffffff;
  }
  sprintf(UDBG_BIN_FILE,"/usr/sbin/%s",&pname);
  iVar2 = access(UDBG_BIN_FILE,0);
  if (iVar2 == 0) {
    sprintf(UDBG_FUN_FILE,"/usr/sbin/%s_symbol_fun",&pname);
    pcVar3 = "/usr/sbin/%s_symbol_obj";
  }
  else {
    sprintf(UDBG_BIN_FILE,"/usr/bin/%s",&pname);
    iVar2 = access(UDBG_BIN_FILE,0);
    if (iVar2 != 0) {
      uVar6 = 0xffffffff;
      if (udbg_err_switch == 0) {
        return 0xffffffff;
      }
      pcVar3 = "[UDBG_ERR]%s()/%d Can not find bin file [%s] from /usr/sbin or /usr/bin\n";
      uVar4 = 0x8e5;
      pcVar5 = &pname;
      goto LAB_005d5a7c;
    }
    sprintf(UDBG_FUN_FILE,"/usr/bin/%s_symbol_fun",&pname);
    pcVar3 = "/usr/bin/%s_symbol_obj";
  }
  sprintf(UDBG_OBJ_FILE,pcVar3,&pname);
  sprintf(UDBG_TMP_SYM_FILE,"%s.%s",UDBG_TMP_SYM_FILE,&pname);
  sprintf(UDBG_SO_FILE,"%s.%s",UDBG_SO_FILE,&pname);
  sprintf(UDGB_TRACE_FILE,"%s.%s",UDGB_TRACE_FILE,&pname);
  if (udbg_debug_switch != 0) {
    printf("[UDBG_DBG]%s()/%d UDBG_BIN_FILE=%s\n","udbg_init_process_var",0x8ff,UDBG_BIN_FILE);
  }
  if (udbg_debug_switch != 0) {
    printf("[UDBG_DBG]%s()/%d UDBG_FUN_FILE=%s\n","udbg_init_process_var",0x900,UDBG_FUN_FILE);
  }
  if (udbg_debug_switch != 0) {
    printf("[UDBG_DBG]%s()/%d UDBG_OBJ_FILE=%s\n","udbg_init_process_var",0x901,UDBG_OBJ_FILE);
  }
  if (udbg_debug_switch != 0) {
    printf("[UDBG_DBG]%s()/%d UDBG_TMP_SYM_FILE=%s\n","udbg_init_process_var",0x902,
           UDBG_TMP_SYM_FILE);
  }
  if (udbg_debug_switch != 0) {
    printf("[UDBG_DBG]%s()/%d UDBG_SO_FILE=%s\n","udbg_init_process_var",0x903,UDBG_SO_FILE);
  }
  uVar6 = 0;
  if (udbg_debug_switch == 0) {
    return 0;
  }
  pcVar3 = "[UDBG_DBG]%s()/%d UDGB_TRACE_FILE=%s\n";
  uVar4 = 0x904;
  pcVar5 = UDGB_TRACE_FILE;
LAB_005d5a7c:
  printf(pcVar3,"udbg_init_process_var",uVar4,pcVar5);
  return uVar6;
}

