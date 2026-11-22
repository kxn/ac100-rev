// func apupd_db_update_model_list_dump @ 006582dc size=140

void apupd_db_update_model_list_dump(void)

{
  int iVar1;
  
  if (apupd_model_list_for_ui != 0) {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    puts("\napupd update model list dump:");
    for (iVar1 = FUN_004081b0(apupd_model_list_for_ui); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      apupd_model_entry_dump(iVar1 + -0xc);
    }
    FUN_00407f30(apupd_db_mutex);
    return;
  }
  return;
}

