// func apupd_db_model_hash_dump @ 006581d8 size=120

void apupd_db_model_hash_dump(void)

{
  if (apupd_model_hash != 0) {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    puts("\napupd model hash dump:");
    FUN_00408570(apupd_model_hash,apupd_model_entry_dump,0);
    FUN_00407f30(apupd_db_mutex);
    return;
  }
  return;
}

