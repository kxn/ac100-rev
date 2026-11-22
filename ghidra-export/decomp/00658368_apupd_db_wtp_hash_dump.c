// func apupd_db_wtp_hash_dump @ 00658368 size=120

void apupd_db_wtp_hash_dump(void)

{
  if (apupd_wtp_hash != 0) {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    puts("\nwtp model hash dump:");
    FUN_00408570(apupd_wtp_hash,apupd_wtp_entry_dump,0);
    FUN_00407f30(apupd_db_mutex);
    return;
  }
  return;
}

