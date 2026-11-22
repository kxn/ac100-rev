// func wportal_db_dm_sessid_rbtree_dump @ 00435050 size=60

void wportal_db_dm_sessid_rbtree_dump(void)

{
  puts("Aut entry for dm sessid rbtree table:");
  FUN_004083c0(dm_sessid_rbtree,_wportal_db_dm_sessid_rbtree_print,0);
  putchar(10);
  return;
}

