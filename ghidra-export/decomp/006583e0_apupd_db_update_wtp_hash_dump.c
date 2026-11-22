// func apupd_db_update_wtp_hash_dump @ 006583e0 size=120

void apupd_db_update_wtp_hash_dump(void)

{
  if (apupd_update_wtp_hash != 0) {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    puts("\nwtp model hash dump:");
    FUN_00408570(apupd_update_wtp_hash,apupd_update_wtp_entry_dump,0);
    FUN_00407f30(apupd_db_mutex);
    return;
  }
  return;
}

