// func wportal_db_cmcc_serialno_rbtree_dump @ 0043508c size=60

void wportal_db_cmcc_serialno_rbtree_dump(void)

{
  puts("CMCC portal serial no entry rbtree table:");
  FUN_004083c0(cmcc_serialno_tree,_wportal_db_cmcc_serialno_rbtree_print,0);
  putchar(10);
  return;
}

