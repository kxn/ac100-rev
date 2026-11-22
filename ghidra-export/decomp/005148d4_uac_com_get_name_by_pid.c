// func uac_com_get_name_by_pid @ 005148d4 size=332

undefined4 uac_com_get_name_by_pid(undefined4 param_1,int param_2)

{
  FILE *__stream;
  char *pcVar1;
  undefined4 uVar2;
  char acStack_150 [64];
  char acStack_110 [256];
  
  uVar2 = 0xffffffff;
  memset(acStack_150,0,0x40);
  memset(acStack_110,0,0x100);
  if (param_2 != 0) {
    sprintf(acStack_150,"/proc/%d/status",param_1);
    __stream = fopen(acStack_150,"r");
    if (__stream != (FILE *)0x0) {
      pcVar1 = fgets(acStack_110,0xff,__stream);
      if (pcVar1 == (char *)0x0) {
        fclose(__stream);
      }
      else {
        uVar2 = 0;
        fclose(__stream);
        sscanf(acStack_110,"%*s %s",param_2);
        if (uac_comm_dbg_switch != 0) {
          printf("[UAC_COMM_DBG]%s()/line %d : task name: %s\n","uac_com_get_name_by_pid",0x4ee,
                 param_2);
        }
      }
    }
  }
  return uVar2;
}

