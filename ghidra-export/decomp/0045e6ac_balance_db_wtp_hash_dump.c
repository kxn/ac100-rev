// func balance_db_wtp_hash_dump @ 0045e6ac size=132

void balance_db_wtp_hash_dump(void)

{
  if (balance_wtp_hash != 0) {
    FUN_004082d0(balance_db_mutex,0xffffffff);
    printf("Total wtp hash table number: %d (hash-size:%d)\n",
           *(undefined4 *)(balance_wtp_hash + 0x10),*(undefined4 *)(balance_wtp_hash + 0x14));
    FUN_00408570(balance_wtp_hash,balance_wtp_entry_dump,0);
    FUN_00407f30(balance_db_mutex);
    return;
  }
  return;
}

