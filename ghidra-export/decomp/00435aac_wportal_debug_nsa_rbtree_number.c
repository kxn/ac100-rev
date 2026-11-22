// func wportal_debug_nsa_rbtree_number @ 00435aac size=1

void wportal_debug_nsa_rbtree_number(void)

{
  undefined4 auStack_10 [2];
  
  auStack_10[0] = 0;
  FUN_004082d0(wportal_nsa_mutex,0xffffffff);
  FUN_004083c0(nsa_tree,_rbtree_print,auStack_10);
  FUN_00407f30(wportal_nsa_mutex);
  printf("Nsa number in rbtree: %d\n",auStack_10[0]);
  return;
}

