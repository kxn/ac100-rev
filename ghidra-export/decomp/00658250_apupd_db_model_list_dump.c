// func apupd_db_model_list_dump @ 00658250 size=140

void apupd_db_model_list_dump(void)

{
  int iVar1;
  
  if (apupd_model_list != 0) {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    puts("\napupd model list dump:");
    for (iVar1 = FUN_004081b0(apupd_model_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      apupd_model_entry_dump(iVar1);
    }
    FUN_00407f30(apupd_db_mutex);
    return;
  }
  return;
}

