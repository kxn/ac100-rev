// func apupd_db_software_number_max_check @ 00658178 size=88

bool apupd_db_software_number_max_check(void)

{
  bool bVar1;
  
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  bVar1 = APUPD_IMPORT_SOFTWARE_NUM_MAX <= apupd_import_software_num;
  FUN_00407f30(apupd_db_mutex);
  return bVar1;
}

