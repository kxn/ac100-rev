// func get_write_out_snapshot_count @ 00595648 size=336

undefined4 get_write_out_snapshot_count(int *param_1)

{
  FILE *__stream;
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char acStack_418 [512];
  char acStack_218 [516];
  
  uVar3 = 0xffffffff;
  memset(acStack_218,0,0x200);
  memset(acStack_418,0,0x200);
  if (param_1 != (int *)0x0) {
    snprintf(acStack_418,0x200,"wc -l %s","/tmp/pkt_snapshot.csv");
    if (snapshot_store_debug_switch != 0) {
      printf("[SNAPSHOT_STORE_DEBUG]%s()/%d cmd %s\n","get_write_out_snapshot_count",0x271,
             acStack_418);
    }
    uVar3 = 0xffffffff;
    __stream = popen(acStack_418,"r");
    if (__stream != (FILE *)0x0) {
      memset(acStack_218,0,0x200);
      pcVar1 = fgets(acStack_218,0x200,__stream);
      if (pcVar1 != (char *)0x0) {
        pcVar1 = strchr(acStack_218,0x20);
        pcVar1[(int)(acStack_218 + -(int)acStack_218)] = '\0';
      }
      pclose(__stream);
      uVar3 = 0;
      iVar2 = atoi(acStack_218);
      *param_1 = iVar2;
      if (snapshot_store_debug_switch != 0) {
        printf("[SNAPSHOT_STORE_DEBUG]%s()/%d all_count %u\n","get_write_out_snapshot_count",0x27e,
               iVar2);
      }
    }
  }
  return uVar3;
}

