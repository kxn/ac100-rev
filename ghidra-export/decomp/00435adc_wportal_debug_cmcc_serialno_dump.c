// func wportal_debug_cmcc_serialno_dump @ 00435adc size=1

void wportal_debug_cmcc_serialno_dump(void)

{
  puts("CMCC portal serial no entry rbtree table:");
  FUN_004083c0(cmcc_serialno_tree,_wportal_db_cmcc_serialno_rbtree_print,0);
  putchar(10);
  return;
}

