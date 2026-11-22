// func apupd_db_profile_dump @ 00658458 size=128

void apupd_db_profile_dump(void)

{
  puts("apupd block profile dump:");
  printf("max wtps: %d\n",APUPD_WTP_MAX);
  printf("max update models: %d\n",APUPD_UPDATING_MODLE_NUM_MAX);
  printf("max update wtps: %d\n",APUPD_UPDATING_WTP_NUM_MAX);
  printf("max import softwares: %d\n",APUPD_IMPORT_SOFTWARE_NUM_MAX);
  printf("max import softwares total size: %d\n",APUPD_ALL_SOFTWARE_SIZE_MAX);
  return;
}

