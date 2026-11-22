// func apmngr_sql_show @ 00547de8 size=1

void apmngr_sql_show(void)

{
  int iVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  char acStack_420 [1024];
  
  ppuVar3 = &g_apmngr_sql_entry;
  memset(acStack_420,0,0x400);
  puts("Show data in DATABASE.");
  puVar2 = g_apmngr_sql_entry;
  while( true ) {
    snprintf(acStack_420,0x400," SELECT * FROM %s;",puVar2);
    printf("=====================%s=======================\n",*ppuVar3);
    iVar1 = FUN_00407fb0((&g_apmngr_db)[(int)ppuVar3[1]],acStack_420,apmngr_sql_show_callback,0);
    if (iVar1 != 0) {
      puts("Failed to carry out sql command.\r");
      return;
    }
    ppuVar3 = ppuVar3 + 3;
    if (ppuVar3 == (undefined **)0x74c0dc) break;
    puVar2 = *ppuVar3;
  }
  return;
}

