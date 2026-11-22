// func udbg_execute @ 005d5478 size=404

void udbg_execute(int param_1)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  int local_458;
  char acStack_454 [96];
  int local_3f4;
  undefined4 local_3f0;
  char local_3ec [996];
  
  memset(&local_458,0,0x450);
  if ((param_1 == 0) || (iVar2 = udbg_para_parse(param_1,&local_458), iVar2 == -1)) {
    puts("\n Syntax Error");
  }
  else if (local_458 == 0) {
    udbg_set_var(&local_458);
  }
  else {
    iVar2 = strcmp(acStack_454,"self");
    if ((((iVar2 == 0) && (local_3f4 == 1)) && (local_3f0 != 0)) &&
       ((pcVar4 = strstr(local_3ec,"/dev/"), pcVar4 != (char *)0x0 ||
        (pcVar4 = strstr(local_3ec,"/tmp/udb.dup.stdouterr"), pcVar4 != (char *)0x0)))) {
      sVar3 = strlen(local_3ec);
      if ((0 < (int)sVar3) && (local_3ec[sVar3 - 1] == '\n')) {
        local_3ec[sVar3 - 1] = '\0';
      }
      iVar2 = 0;
      while (cVar1 = local_3ec[iVar2], cVar1 != '\0') {
        if (cVar1 == ' ') {
          iVar2 = iVar2 + 1;
        }
        else {
          if (cVar1 != '\t') break;
          iVar2 = iVar2 + 1;
        }
      }
      pcVar4 = local_3ec + iVar2;
      sVar3 = strlen(pcVar4);
      if ((int)sVar3 < 1) {
        return;
      }
    }
    else {
      iVar2 = strcmp(acStack_454,"reset");
      if ((iVar2 != 0) || (local_3f4 != 0)) {
        udbg_call_fun(&local_458);
        return;
      }
      pcVar4 = "/dev/console";
    }
    udbg_dup_stdout(pcVar4);
  }
  return;
}

