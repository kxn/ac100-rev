// func udbg_trace_to_file @ 005d50dc size=100

void udbg_trace_to_file(void)

{
  int iVar1;
  char acStack_68 [96];
  
  memset(acStack_68,0,0x60);
  iVar1 = access(UDGB_TRACE_FILE,0);
  if (iVar1 != 0) {
    sprintf(acStack_68,"touch %s",UDGB_TRACE_FILE);
    system(acStack_68);
  }
  udbg_dup_stdout(UDGB_TRACE_FILE);
  return;
}

