// func uac_done @ 0040b2c0 size=80

void uac_done(void)

{
  __pid_t _Var1;
  char acStack_88 [132];
  
  memset(acStack_88,0,0x80);
  _Var1 = getpid();
  sprintf(acStack_88,"echo %d > %s",_Var1,"/tmp/uac_init_done");
  system(acStack_88);
  return;
}

