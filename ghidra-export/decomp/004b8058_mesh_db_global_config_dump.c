// func mesh_db_global_config_dump @ 004b8058 size=1

void mesh_db_global_config_dump(void)

{
  char *pcVar1;
  undefined *puVar2;
  
  if (DAT_00767eb8 == 0) {
    puVar2 = &DAT_00691368;
  }
  else {
    puVar2 = &DAT_006a2b04;
  }
  printf("Mesh enable:\t%s\n\n",puVar2);
  printf("Wan status: \t%d\n",(int)DAT_00767ebc);
  printf("policy mask: \t%d\n",DAT_00767fb4);
  printf("policy: \t%d\n",DAT_00767fb0);
  printf("SSID:\t%s\n",&DAT_00767ebd);
  printf("Key:\t%s\n",&DAT_00767ede);
  printf("Token:\t%s\n\n",&DAT_00767f1e);
  printf("Web Password:\t%s\n\n",&DAT_00767f44);
  printf("BH_work_mode:\t%d\n\n",DAT_00767fac);
  if (DAT_00767f40 == 0) {
    pcVar1 = "Led off";
  }
  else {
    pcVar1 = "Led on";
  }
  printf("Re auto switch:\t%s\n\n",pcVar1 + 4);
  return;
}

