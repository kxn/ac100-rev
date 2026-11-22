// func apmngr_db_debug_template_show @ 00543190 size=1

void apmngr_db_debug_template_show(void)

{
  printf("================Template(Total : %-3d)================\n",(uint)g_apmngr_template_num);
  puts(" id  |GID|    entry-name    |      Hardware      |Options..|");
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  FUN_00408570(g_apmngr_template_hash,_apmngr_template_hash_callback,0);
  FUN_00407f30(apmngr_db_mutex);
  (*(code *)PTR_puts_00758f90)("=======================================");
  return;
}

