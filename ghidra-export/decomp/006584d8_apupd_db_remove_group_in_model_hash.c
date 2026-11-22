// func apupd_db_remove_group_in_model_hash @ 006584d8 size=100

void apupd_db_remove_group_in_model_hash(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 local_14;
  
  if (apupd_model_hash != 0) {
    local_18 = param_1;
    local_14 = param_2;
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    FUN_00408570(apupd_model_hash,_apupd_remove_group_in_model_entry,&local_18);
    FUN_00407f30(apupd_db_mutex);
  }
  return;
}

