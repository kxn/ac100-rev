// func wportal_db_aut_rbtree_number @ 004348d8 size=1

void wportal_db_aut_rbtree_number(void)

{
  undefined4 auStack_10 [2];
  
  auStack_10[0] = 0;
  FUN_004082d0(wportal_aut_mutex,0xffffffff);
  FUN_004083c0(aut_tree,_rbtree_print,auStack_10);
  FUN_00407f30(wportal_aut_mutex);
  printf("Auth number in rbtree: %d\n",auStack_10[0]);
  return;
}

