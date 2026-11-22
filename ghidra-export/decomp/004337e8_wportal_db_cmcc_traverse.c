// func wportal_db_cmcc_traverse @ 004337e8 size=1

undefined4 wportal_db_cmcc_traverse(void)

{
  undefined4 auStack_10 [2];
  
  auStack_10[0] = 0;
  puts("###PRINT CMCC WQ ENTRY###");
  FUN_004082d0(wportal_cmcc_waitque_mutex,0xffffffff);
  FUN_004083c0(cmcc_wq_tree,_wportal_common_wq_item_traverse_func,auStack_10);
  FUN_00407f30(wportal_cmcc_waitque_mutex);
  return 0;
}

