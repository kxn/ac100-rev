// func balance_db_dis_sta_hash_dump @ 0045e730 size=148

void balance_db_dis_sta_hash_dump(void)

{
  undefined4 extraout_v1;
  undefined4 local_18 [3];
  
  FUN_00407e70();
  if (balance_dis_sta_hash != 0) {
    local_18[0] = extraout_v1;
    FUN_004082d0(balance_db_mutex,0xffffffff);
    printf("\nTotal ip-mac tbl num: %d (hasi-size:%d)\r\n",
           *(undefined4 *)(balance_dis_sta_hash + 0x10),*(undefined4 *)(balance_dis_sta_hash + 0x14)
          );
    puts("------------------------------------------------------------------\r");
    puts("stamac               failnum          last_fail_time        wtp:Index(leasetime) \r");
    FUN_00408570(balance_dis_sta_hash,balance_dis_sta_entry_dump,local_18);
    FUN_00407f30(balance_db_mutex);
  }
  return;
}

