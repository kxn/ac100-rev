// func _apmngr_debug_dup_entry_in_mem_print @ 00543dd8 size=1

undefined4 _apmngr_debug_dup_entry_in_mem_print(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char acStack_118 [260];
  
  memset(acStack_118,0,0x100);
  iVar2 = g_debug_entry_bit;
  iVar5 = (uint)*(ushort *)(param_1 + 0x10) * 2;
  pcVar4 = (char *)(g_debug_entry_bit + iVar5);
  if ((*pcVar4 == '\0') || (pcVar4[1] == '\0')) {
    strcpy(acStack_118,"[");
    bVar1 = *pcVar4 == '\0';
    if (bVar1) {
      strcat(acStack_118,"cfg");
      iVar3 = *(int *)(param_1 + 0xc);
    }
    else {
      iVar3 = *(int *)(param_1 + 0xc);
    }
    if ((iVar3 != 0) && (*(char *)(iVar2 + iVar5 + 1) == '\0')) {
      if (bVar1) {
        strcat(acStack_118,",");
      }
      bVar1 = true;
      strcat(acStack_118,"run");
    }
    strcat(acStack_118,"]");
    if (bVar1) {
      printf("%s \t",acStack_118);
      if (*(int *)(param_1 + 0xc) == 0) {
        apmngr_debug_template_print(param_1);
      }
      else {
        apmngr_debug_ap_print(param_1,0);
      }
    }
  }
  return 0;
}

