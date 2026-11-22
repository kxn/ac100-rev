// func apmngr_debug_conformity_check @ 00547ee4 size=1

void apmngr_debug_conformity_check(void)

{
  int iVar1;
  int iVar2;
  char *__s;
  size_t __n;
  undefined **ppuVar3;
  undefined4 uStack_430;
  char acStack_42c [1028];
  
  memset(acStack_42c,0,0x400);
  uStack_430 = 1;
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  __n = (iVar1 + iVar2) * 2;
  g_debug_entry_bit = (void *)FUN_00408450(__n,0x785);
  memset(g_debug_entry_bit,0,__n);
  puts("Now carry out a config conformity validation.");
  ppuVar3 = (undefined **)0x74c0b8;
  puts("Step 1, check if ap_entry in database differ with memory.");
  puts("Id\tAttribute\tMem\tDatabase");
  do {
    snprintf(acStack_42c,0x400,"SELECT * FROM %s;",*ppuVar3);
    iVar1 = FUN_00407fb0((&g_apmngr_db)[(int)ppuVar3[1]],acStack_42c,
                         _apmngr_db_entry_conformity_check,&uStack_430);
    if (iVar1 != 0) goto code_r0x00548130;
    ppuVar3 = ppuVar3 + 3;
  } while (ppuVar3 != &PTR_s_ApEntryRun_table_0074c0d0);
  snprintf(acStack_42c,0x400,"SELECT * FROM %s;",PTR_s_ApEntryRun_table_0074c0d0);
  iVar1 = FUN_00407fb0((&g_apmngr_db)[DAT_0074c0d4],acStack_42c,_apmngr_db_run_conformity_check,0);
  if (iVar1 == 0) {
    puts("--------------------------------------------");
    puts("Step 2, check if template in database differ with memory.");
    puts("Id\tAttribute\tMem\tDatabase");
    uStack_430 = 0;
    snprintf(acStack_42c,0x400," SELECT * FROM %s;",uRam0074c0ac);
    iVar1 = FUN_00407fb0((&g_apmngr_db)[iRam0074c0b0],acStack_42c,_apmngr_db_entry_conformity_check,
                         &uStack_430);
    if (iVar1 != 0) {
      printf("Failed to carry out sql command.");
      goto code_r0x005480e8;
    }
    puts("--------------------------------------------");
    puts("3.Step Three, check if some entry do NOT exist in database but in memory.");
    puts("--------------------------------------------");
    apmngr_db_foreach_proc(0xffffffff,_apmngr_debug_dup_entry_in_mem_print,0);
    __s = "--------------------------------------------";
  }
  else {
code_r0x00548130:
    __s = "Failed to carry out sql command.";
  }
  puts(__s);
code_r0x005480e8:
  FUN_00407df0(g_debug_entry_bit);
  return;
}

