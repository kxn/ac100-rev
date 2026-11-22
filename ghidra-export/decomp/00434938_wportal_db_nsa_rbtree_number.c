// func wportal_db_nsa_rbtree_number @ 00434938 size=96

void wportal_db_nsa_rbtree_number(void)

{
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  FUN_004082d0(wportal_nsa_mutex,0xffffffff);
  FUN_004083c0(nsa_tree,_rbtree_print,local_10);
  FUN_00407f30(wportal_nsa_mutex);
  printf("Nsa number in rbtree: %d\n",local_10[0]);
  return;
}

