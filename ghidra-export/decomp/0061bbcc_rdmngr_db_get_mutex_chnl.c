// func rdmngr_db_get_mutex_chnl @ 0061bbcc size=352

int rdmngr_db_get_mutex_chnl
              (undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined2 param_4,
              int param_5,int param_6,undefined4 param_7)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *local_88;
  char acStack_84 [104];
  
  memset(acStack_84,0,100);
  pcVar2 = (char *)apdb_get_radio_mutex_channel(param_1,param_2,param_3,param_4,param_7);
  if (pcVar2 == (char *)0x0) {
    iVar5 = 0;
    puts("mutex_chnl is NULL.");
  }
  else {
    strncpy(acStack_84,pcVar2,99);
    local_88 = (char *)0x0;
    pcVar2 = strtok_r(acStack_84,",",&local_88);
    iVar5 = 0;
    if (pcVar2 != (char *)0x0) {
      bVar1 = true;
      do {
        if (!bVar1) break;
        iVar3 = atoi(pcVar2);
        iVar4 = iVar5 * 4;
        if (param_5 != iVar3) {
          iVar5 = iVar5 + 1;
          *(int *)(param_6 + iVar4) = iVar3;
        }
        pcVar2 = strtok_r((char *)0x0,",",&local_88);
        bVar1 = iVar5 < 0x10;
      } while (pcVar2 != (char *)0x0);
    }
    if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d mutex_chnl cnt is %d.\n\n","rdmngr_db_get_mutex_chnl",0x9e3,
             iVar5);
    }
  }
  return iVar5;
}

